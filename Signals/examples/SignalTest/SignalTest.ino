/*  SignalTest.ino Example Sketch for Signals Library
 * 
 *  Viessmann 4010 - H0 Colour light distant signal                         | Vr0, Vr1 and Vr2
 *  Viessmann 4011 - H0 Colour light block signal                           | Hp0 and Hp1
 *  Viessmann 4013 - H0 Colour light departure signal                       | Hp0, Hp1, Vr0, Vr1 and Vr2
 *  Viessmann 4014 - H0 Colour light block signal with distant signal       | Hp0, Hp1, Hp2 and Hp0/Sh1
 *  Viessmann 4015 - H0 Colour light entry signal with distant signal       | Hp0, Hp1, Vr0, Vr1 and Vr2
 *  Viessmann 4016 - H0 Colour light departure signal with distant signal   | Hp0, Hp1, Hp2, Hp0/Sh1, Vr0, Vr1 and Vr2
 *  Strobe         - H0 Generic Strobe output
 *  
 *  Hp0       Halt                    Red               | mode 0
 *  Hp1       Fahrt                   Green             | mode 1
 *  Hp2       Langsamfahrt            Green/Yellow      | mode 2
 *  Hp0/Sh1   Shunting                Red/White         | mode 3
 *  Off       All Lights Off                            | mode 100
 *  
 *  Vr0       Halt erwarten           Yellow            | mode 0
 *  Vr1       Fahrt erwarten          Green             | mode 1
 *  Vr2       Langsamfahrt erwarten   Green/Yellow      | mode 2
 *  Off       All Lights Off                            | mode 100
 *  
 *  
 *  A signal uses 1 address per 2 Aspects. The Adresses are numbered in ascending order (Base address++).
 *  HP and VR signals have their own base address and operate like independent signals.
 *  
 *  Example:
 *  Viessmann 4015 - H0 Colour light entry signal with distant signal.
 *  This signal has 3 aspects HP and 3 aspects VR
 *  
 *  HP Red    = pin 3
 *  HP Green  = pin 4
 *  HP Yellow = pin 5
 *  VR Green  = Pin 6
 *  VR Yellow = Pin 9
 *  
 *  HP uses address 10 and 11
 *  VR uses address 16 and 17
 *  
 *  Initialize with:      Viessmann_4015 mySignal(3, 4, 5, 6, 9);   | Viessmann_4015(hp_red, hp_green, hp_yellow, vr_green, vr_yellow);
 *  Then in Setup call:   mySignal.begin(10, 16);                   | mySignal.begin(address_hp, address_vr);
 */

#include <Signals.h>

// Inintializers
// Viessmann_4010(vr_green, vr_yellow);                                    // Viessmann 4010 = 3 Aspects HP        = 2 Addresses
// Viessmann_4011(hp_red,   hp_green);                                     // Viessmann 4011 = 2 Aspects HP        = 1 Address
// Viessmann_4013(hp_red1,  hp_red2,  hp_green,  hp_yellow, hp_white);     // Viessmann 4013 = 4 Aspects HP        = 2 Addresses
// Viessmann_4014(hp_red,   hp_green, vr_green,  vr_yellow);               // Viessmann 4014 = 2 Aspects HP & 3 VR = 1 Address   HP and 2 Addresses VR
// Viessmann_4015(hp_red,   hp_green, hp_yellow, vr_green,  vr_yellow);    // Viessmann 4015 = 3 Aspects HP & 3 VR = 2 Addresses HP and 2 Addresses VR

// Strobe(pin, time ON in ms, time OFF in ms);                             // Stobe          = On or Off           = 1 Address

Viessmann_4011 mySignal1(8, 9);
Viessmann_4013 mySignal2(3, 4, 5, 6, 7);

uint8_t mode_4011, mode_4013 = 0;

void setup() {

  Serial.begin(115200);   // Start Arduino Serial
  
  mySignal1.init(21);       // Initialize the start address
  mySignal2.init(23);       // Initialize the start address
}

void loop() {

  // this will walk throught modes 0 to 3 (HP0, HP1, HP2, Hp0/Sh1)

  // Viessmann_4011 only has HP0 and HP1 so turn off leds for modes 2 and 3
  if (mode_4011 > 1) {
    mySignal1.set(100);
  } else {
    mySignal1.set(mode_4011);
  }
  
  mySignal2.set(mode_4013);

  // Wait 2 Seconds
  delay(2000);

  // Goto next Mode
  mode_4011++;
  mode_4013++;

  // Reset Viessmann_4011 to mode 0 when bigger than 3
  if(mode_4011 > 3) {
    mode_4011 = 0;
  }

  // Reset Viessmann_4013 to mode 0 when bigger than 3
  if(mode_4013 > 3) {
    mode_4013 = 0;
  }
  
  // Serial.println(mySignal1.getaddress());
  
}
