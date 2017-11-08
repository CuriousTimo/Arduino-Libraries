/*
||
|| @file 	Timing.h
|| @version	1.9
|| @author	Wallace Campos
|| @contact	wallace.iub@hotmail.com
|| 
|| @history
|| | I start in the arduino world some months ago and I never saw nothing about
|| | microcontrollers, but I work with PLCs and PC. This library is inspired by
|| | PLCs timers and based on TimedAction by Alexander Brevig.
||
|| @description
|| |______________________________________________________________________________
|| |						Description of each class:
|| |______________________________________________________________________________	
|| | 1. Timing: 
|| | Base class with one constructor. Timing(unsigned long interval). This set the
|| | interval for timer check and do something. This timer isn't the internal
|| | timer of microcontroller, it is a software timer and your accuracy depends
|| | how many time your controller needs to run your sketch.
|| | check() is a virtual method to use in subclasses. It work in different modes.
|| | See bellow. 
|| |______________________________________________________________________________
|| | 2.PulseIn: Provide a easy way to calculate a width of a digital pulse on pin
|| | without stop microcontroller process. Your precision depends how much time
|| | your controller needs to run your application, so it isn't as accurate.
|| | check() method checks if timer is active and when timer have a new value
|| | for elapsed time, it returns a true value and you can read it using 
|| | pulseWidth().
|| |______________________________________________________________________________
|| | 3.SimpleBlink: Provide a easy way to blink a led at a set interval.
|| | check() method checks if timer is active and if elapsed time is greater than 
|| | interval and toggle the output.
|| |______________________________________________________________________________
|| | 4.Blink: Provide a way to blink a led at a set interval, but you can
|| | choose the time on and time off of the led.
|| | check() method checks if timer is active and if elapsed time is greater than
|| | interval and toggle the output. It will check also if output is setted and
|| | change the interval value to next step.
|| |______________________________________________________________________________
|| | 5.BlinkNTimes: Provide a way to blink a led at set interval in N times
|| | defined on constructor.
|| | check() method checks if timer is active and elapsed time is greater than
|| | interval and change the output state until ntimes is reached. When blink is 
|| | finished, you need call disable() or reset() methods to reset timer.
|| |______________________________________________________________________________
|| | 6.BlinkWithPause: Provide a way to blink a led at set interval, you can
|| | choose time on and time off.
|| | check() method checks if timer is active and if elapsed time is greater than
|| | interval and change the output state. When you pause - pause() - the blink, 
|| | timer is paused and output stay with the last state, when you unpause it
|| | - unpause() - timer is resumed and return blinking.
|| |______________________________________________________________________________
|| | 7.TimerOnDelay: Provide a way to do an on delay without using delay(), with
|| | this your microcontroller don't need stop to wait a moment and do something.
|| | check() method checks if timer is active and if elapsed timer is greater than
|| | interval and set the output to high level.
|| |______________________________________________________________________________
|| | 8.TimerOffDelay: Provide a way to do an off delay without using delay(), with
|| | this you can stop something after some time.
|| | check() method checks if timer is active and set output to high level, when
|| | timer is stooped - disable() - start timing and when elapsed time is greater
|| |  than interval set output to low level.
|| |______________________________________________________________________________
|| | 9.RetentiveOnDelay: Provide a way to do a retentive on delay without using
|| | delay(). With this you can store how many time a digital bit stayed in high
|| | level to set output to high level.
|| | check() method checks if timer is active and start timing, after this, if 
|| | elapsed time isn't greater than interval and timer is unsetted, check()
|| | store in elapsed_time total elapsed time and when timer is activated again,
|| | reload this value in started and continue timing until elapsed time is 
|| | greater than interval to set output to high level. If output is in high level
|| | and timer isn't active, timer is reset - set output to low level and reset 
|| | counters. 
|| |______________________________________________________________________________
|| | 10.RetentiveOffDelay: Provide a way to do a retentive off delay without using
|| | delay(). With this you can store how many time a digital bit stayed in low
|| | level to set output of timer to low level.
|| | check() method checks if timer isn't active and start timing, after this, if
|| | elapsed timer isn't greater than interval and timer is activated again,
|| | check() store in elapsed_time total elapsed time and when timer is unsetted
|| | again, reload this value in started and continue timing until elapsed time is
|| | greater than interval to set output to low level.
|| |______________________________________________________________________________									  
|| |							Methods and variables:
|| |______________________________________________________________________________									  																		 	  
|| | Timing Methods:																	  
|| | 1.1 setInterval(intervl) - set the interval for the timer;	
|| | 1.2 debounceToggle(checkState) -  read a pin, debounce it and toggle timer;
|| | Source: http://arduino.cc/en/Tutorial/Debounce
|| | 1.3 writePin(pin) - write in digital pin result of check();
|| | 1.4 set(value) - read a pin and write in active;							  	  													 
|| | 1.5 enable() - enable timer;											  
|| | 1.6 disable() - disable timer;											  
|| | 1.7 toggle() - if timer isn't enable, enable it, else, disable it;	  
|| | 1.8 reset() - reset internal variables, turn off timer and output;		  
|| | 1.9 state() - get the output state of timer without calling check() again.								  
|| | 1.10 check() - checks the timing and return the output state. It is a 
|| | virtual method, so it works in different modes. See bellow.
|| | 1.11 timing() - it is a stopwatch to use in base class but you can't use
|| | check(). This method return total run time of a digital bit activated by 
|| | enable(), stopped by disable() and reseted by reset().
|| |			
|| | Other methods:
|| | 1.12 PulseIn.pulseWidth() - return elapsed time of a digital signal;
|| | 1.13 Blink.setInterval2(intervl) - set interval2 for timer, this interval
|| | is used for time to stay off output when timer is running;
|| | 1.14 BlinkNTimes.nTimes(ntimes) - set how many times led will blink;
|| | 1.15 BlinkWithPause.pause() - pause timer and stay output in actual state;
|| | 1.16 BlinkWithPause.unpause() - unpause timer and return blinking.
|| |															  
|| | Timing Variables:																	  
|| | 2.1 out - indicate the status of timer, according each check methods;	  
|| | 2.2 active - indicate if timer is setted on or off, if off;																  
|| | 2.3 stateNow - used to debounce a digital pin, it indicates actual value
|| | of debounce;
|| | 2.4  lastState - used to debounce a digital pin, it indicates the last
|| | reading value of pin;
|| | 2.5 started - indicates when timer is started;								  														  
|| | 2.6 interval - the interval for timer check something;					  
|| | 2.7 elapsed_time - necessary only retentive timers and timing() method - 
|| | this variable store total elapsed time of timing and in retentive timers
|| | if timer is unsetted - disable() - and setted again - enable() - reload 
|| | this value in started variable.		
|| | 2.8 started_debounce - indicates when debounce is changed
|| | 2.9 delay_debounce - how many time to toggle timer.				  
|| |
|| | Other Variables:
|| | 2.10 Blink.interval1 - time to stay on the led;
|| | 2.11 Blink.interval2 - time to stay off the led;
|| | 2.12 BlinkNTimes.how_may_times - how many times output will blink;
|| | 2.13 BlinkNTimes.executed_times - how many times output was changed;
|| | 2.14 BlinkWithPause.paused - indicates if timer is paused;
|| | 2.15 BlinkWithPause.retentive_time - this variable store elapsed time when 
|| | timer is paused and reload this in started variable again when unpaused;
|| |______________________________________________________________________________
|| #
|| @license
|| | This library is free software; you can redistribute it and/or
|| | modify it under the terms of the GNU Lesser General Public
|| | License as published by the Free Software Foundation; version
|| | 2.1 of the License.
|| |
|| | This library is distributed in the hope that it will be useful,
|| | but WITHOUT ANY WARRANTY; without even the implied warranty of
|| | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
|| | Lesser General Public License for more details.
|| |
|| | You should have received a copy of the GNU Lesser General Public
|| | License along with this library; if not, write to the Free Software
|| | Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
|| #
||
|| @Ps.: Sorry for my bad English
*/

#ifndef Timing_h
#define Timing_h
#include "Arduino.h"

class Timing {

  public:
	Timing(unsigned long intervl);
	void setInterval(unsigned long intervl);
	void debounceToggle(bool checkState);	
	void writePin(uint8_t pin);
	void set(bool pin_status);	
	void enable();
	void disable();
	void toggle();
	void reset();	
	bool state();
	virtual bool check();
	unsigned long timing();

	
	
  protected:
  	bool out;
	bool active;
	bool stateNow;	
	bool lastState;
	unsigned long started;	
	unsigned long interval;
	unsigned long elapsed_time;
	unsigned long debounce_started;

};

class PulseIn : public Timing{

  public:
	PulseIn();
	bool check();
	unsigned long pulseWidth();
	
};

class SimpleBlink : public Timing{

  public:
	SimpleBlink(unsigned long intervl);
	virtual bool check();
	
};

class Blink : public SimpleBlink{

  public:
	Blink(unsigned long intervl1, unsigned long intervl2);
	void setInterval2(unsigned long intervl);	
	virtual bool check();
	
  protected:
	unsigned long interval1;
	unsigned long interval2;
	
};

class BlinkNTimes : public SimpleBlink{

	public:
	BlinkNTimes(unsigned long intervl, uint8_t ntimes);
	void nTimes(uint8_t ntimes);
	virtual bool check();
	
	private:
	uint8_t how_many_times;
	uint8_t executed_times;
	
};

class BlinkWithPause : public Blink{
  
  public:
    BlinkWithPause(unsigned long intervl);
    BlinkWithPause(unsigned long intervl1, unsigned long intevl2);
	virtual bool check();
	void reset();	
	void pause();
	void unpause();

  private: 
    bool paused;
    unsigned long retentive_time;

};

class TimerOnDelay : public Timing{

	public:
	TimerOnDelay(unsigned long intervl);
	virtual bool check();
	
};

class TimerOffDelay : public Timing{

	public:
	TimerOffDelay(unsigned long intervl);
	virtual bool check();
	
};

class RetentiveOnDelay : public Timing{

  public:
	RetentiveOnDelay(unsigned long intervl);
	virtual bool check();

};

class RetentiveOffDelay : public Timing{

  public:
	RetentiveOffDelay(unsigned long intervl);
	virtual bool check();
	
};

#endif

/*
|| @Timing changelog
|| | 1.9 2013-08-30 - Wallace Campos: Add PulseIn Class
|| | 1.8 2013-08-19 - Wallace Campos: Add set()
|| | 1.7 2013-08-27 - Wallace Campos: Improved code
|| | 1.6 2013-08-27 - Wallace Campos: Add timing() method
|| | 1.5 2013-08-10 - Wallace Campos: Improved code
|| | 1.4 2013-07-30 - Wallace Campos: Add Retentive delays
|| | 1.3 2013-07-14 - Wallace Campos: Restart the project and add OnDelay and OffDelay classes
|| | 1.2 2012-12-13 - Wallace Campos: Change lib name and start a new project with Timing classes
|| | 1.1 2012-12-09 - Wallace Campos: Added improves (comments and cut part of code) 	
|| | 1.0 2012-10-21 - Wallace Campos: Initial Release with blink class
|| #
*/