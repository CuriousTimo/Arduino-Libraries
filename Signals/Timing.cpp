#include "Timing.h"
//________________________Timing_______________________
Timing::Timing(unsigned long intervl):interval(intervl),active(false),out(false),started(0){}

void Timing::setInterval(unsigned long intervl){
	interval = intervl;							//Set interval to intervl
}

void Timing::debounceToggle(bool checkState){
	//Source: http://arduino.cc/en/Tutorial/Debounce
	if (lastState != checkState){			//If signal is changed
		debounce_started = millis();		//Reset debouncing timer
	}
	if (millis()-debounce_started >= 10){	//If elapsed time is greater than debounce delay
		if (checkState != stateNow){		//and button state is changed
			stateNow = checkState;			//change state
			if (stateNow){					//If button in high level
				active = !active;			//toggle timer
			}
		}
	}
	lastState = checkState;					//Store reading to use in next loop
}

void Timing::writePin(uint8_t pin){
	digitalWrite(pin,check());					//Write pin with out state
}

void Timing::set(bool pin_status){
	active = pin_status;						//Turn on or off timer
}

void Timing::enable(){
	active = true;								//No need comments
}

void Timing::disable(){
    active = false;								//No need comments
}

void Timing::toggle(){
	active = !active;							//No need comments
}

void Timing::reset(){
	out = false;								//Reset internal variables
	active = false;
	started = 0;
	elapsed_time = 0;
}

bool Timing::state(){
	return	out;								//Return output state without check again
}

bool Timing::check(){
	//No pure virtual
}

unsigned long Timing::timing(){
	if (active){								//If timer is active
		if (started == 0){						//and started now
			started = millis()-elapsed_time;	//load millis - elapsed time (in memory) in started
		}
		elapsed_time = millis()-started;		//Load current elapsed time (stay this in memory)
	}
	else{										//If timer isn't active
		started = 0;							//reset started counter
	}
	return elapsed_time;						//Return elapsed time
}


//_______________________PulseIn_______________________
PulseIn::PulseIn():Timing(0){
	elapsed_time = 0;
}

unsigned long PulseIn::pulseWidth(){
	return elapsed_time;						//Return pulse width
}

bool PulseIn::check(){
	out = false;								//Reset output state used to read elapsed time
	if (active){								//If timer is active
		if (started == 0){						//and started now
			started = millis();					//load current millis
		}
	}
	else{										//When timer isn't active
		if (started != 0){						//and was started
			elapsed_time = millis()-started;	//set elapsed time
			out = true;							//set output to high level (new value in this case)
			started = 0;						//reset started counter
		}
	}
	return out;									//Return out (have a new value?)
}


//_____________________SimpleBlink_____________________
SimpleBlink::SimpleBlink(unsigned long intervl):Timing(intervl){
	active = true;							//Start blinking
}

bool SimpleBlink::check(){
	if (active){
		if (millis()-started >= interval){	//If timer is active and elapsed time is greater than interval
			out = !out;						//toggle the output
			started = millis();				//store when output is changed
		}
	}
	else{									//If timer isn't active
			out = false;					//set output to low level
	}
	return out;								//Return output
}


//________________________Blink________________________
Blink::Blink(unsigned long intervl1, unsigned long intervl2):SimpleBlink(intervl1){
	interval1 = intervl1;					
	interval2 = intervl2;
}

void Blink::setInterval2(unsigned long intervl){
	active = true;
	interval2 = intervl;
}

bool Blink::check(){
	if (active){							//If timer is active
		if (millis()-started >= interval){	//and elapsed time is greater than interval
			if (!out){						//and output is off
				interval = interval1;		//change the time to check to interval1 (time on)
			}
			else{							//If output is on
				interval = interval2;		//change the time to check to interval2 (time off)
			}
			started = millis();				//store when output is changed (elapsed times greater than interval)
			out = !out;						//toggle the output
		}
	}
	else{									//If timer isn't active
		out = false;						//set output to low level
	}
	return out;								//Return output
}


//_____________________BlinkNTimes_____________________
BlinkNTimes::BlinkNTimes(unsigned long intervl, uint8_t ntimes):SimpleBlink(intervl){
	how_many_times = (ntimes*2);
	executed_times = 0;
}

void BlinkNTimes::nTimes(uint8_t ntimes){
	how_many_times = (ntimes*2);
}

bool BlinkNTimes::check(){
	if (active){								//If timer is active
		if (executed_times < how_many_times){	//and how many times is less than executed times
			if (millis()-started >= interval){	//and elapsed time is greater than interval
				out = !out;						//toggle output
				started = millis();				//store when do this
				executed_times++;				//increment executed times
			}
		}
	}
	else{										//If timer isn't active
		out = false;							//set output to low level
		executed_times = 0;						//reset counter
	}
	return out;									//Return output
}


//____________________BlinkWithPause___________________
BlinkWithPause::BlinkWithPause(unsigned long intervl):Blink(intervl,intervl){
	retentive_time = 0;
}

BlinkWithPause::BlinkWithPause(unsigned long intervl1, unsigned long intervl2):Blink(intervl1,intervl2){
	retentive_time = 0;
}

void BlinkWithPause::pause(){
    paused = true;
	if (active && retentive_time == 0)			//If timer is active and was not paused
		retentive_time = millis() - started;	//store elapsed time of actual state of output
}

void BlinkWithPause::unpause(){
    paused = false;
	if (active && retentive_time != 0){			//If timer is active and paused
		started = millis() - retentive_time;	//reload elapsed time of actual state of output
		retentive_time = 0;						//Reset counter
	}
}

void BlinkWithPause::reset(){
	active = false;
	started = 0;
	out = false;
	retentive_time = 0;
}

bool BlinkWithPause::check(){
	if (active){									//If timer is active
		if (started == 0){							//and started now
			started = millis();						//load current millis - start timing
		}
		else if (!paused){							//If timer isn't paused
			if (!out){								//and output is off
				if (millis()-started >= interval2){	//and elapsed time is greater than interval2 (time off)
				    started = millis();				//load when output is changed
					out = true;						//change output to high level
				}
			}
			else{									//If timer isn't paused and output is on
				if (millis()-started >= interval){	//and elapsed time is greater than interval (time on)
				    started = millis();				//load when output is changed
					out = false;					//change output to low level
				}
			}
		}											//If timer is active but paused, do nothing
	}										
	else{											//If timer isn't active
		out = false; 								//set output to low level
		started = 0;								//reset counter
	}
	return out;										//Return output
}


//_____________________TimerOnDelay____________________
TimerOnDelay::TimerOnDelay(unsigned long intervl):Timing(intervl){}

bool TimerOnDelay::check(){
	if (active){								//If timer is active
		if (started == 0){						//and started now
			started = millis();					//load current millis - start timing
		}
		else if	(millis()-started >= interval){	//If elapsed time is greater than interval
			out = true;							//set output to high level
		}
	}
	else{										//If timer isn't active
		out = false;							//set output to low level
		started = 0;							//reset counter
	}
	return out;									//Return output
}


//____________________TimerOffDelay____________________
TimerOffDelay::TimerOffDelay(unsigned long intervl):Timing(intervl){}

bool TimerOffDelay::check(){
	if (active){								//If timer is active
		out = true;								//set output to high level
		started = 0;							//reset counter
	}
	else if (out){								//If ins't active and output is in high level
		if (started == 0){						//and started timer now
			started = millis();					//load current millis - start timing
		}
		else if (millis()-started >= interval){	//If elapsed time is greater than interval
			out = false;						//set output to low level
		}
	}
	return out;									//Return output
}	

	
//___________________RetentiveOnDelay__________________
RetentiveOnDelay::RetentiveOnDelay(unsigned long intervl):Timing(intervl){
	elapsed_time = 0;
}

bool RetentiveOnDelay::check(){
	if (active){								//If timer is active
		if (started == 0){						//and started now
			started = millis()-elapsed_time;	//load current millis - stored elapsed time before active was toggled
		}
		if (!out){								//If output is in low level
			elapsed_time = millis()-started;	//load elapsed time - it is necessary only retentive timing
			if	(elapsed_time >= interval){		//If elapsed time is greater than interval
				out = true;						//set output to high level
			}
		}
	}
	else{										//If timer isn't active
		if (out){								//and output still in high level
			elapsed_time = 0;					//reset elapsed time counter
		}	
		started = 0;							//reset started counter
		out = false;							//set output to low level
	}
	return out;									//Return output
}


//___________________RetentiveOffDelay________________
RetentiveOffDelay::RetentiveOffDelay(unsigned long intervl):Timing(intervl){
	elapsed_time = 0;
}

bool RetentiveOffDelay::check(){
	if (active){								//If timer is active
		elapsed_time = 0;						//reset elapsed time counter	
		out = true;								//set output to high level				
		started = 0;							//reset started counter
	}
	else{										//If timer isn't active
		if (out){								//If output is in high level - used to reduce process
			if (started == 0){					//and started now
				started = millis()-elapsed_time;//load current millis - stored elapsed time before active was toggled
			}		
			elapsed_time = millis()-started;	//Load elapsed time - it is necessary only retentive timing
			if	(elapsed_time >= interval){		//If elapsed time is greater than interval
				out = false;					//set output to low level
			}
		}
	}
	return out;									//Return output
}