/*  SignalTest.ino Example Sketch for Signals Library
 * 
 *  Viessmann 4010 - H0 Colour light distant signal                         | Vr0, Vr1 and Vr2
 *  Viessmann 4011 - H0 Colour light block signal                           | Hp0 and Hp1
 *  Viessmann 4013 - H0 Colour light departure signal                       | Hp0, Hp1, Vr0, Vr1 and Vr2
 *  Viessmann 4014 - H0 Colour light block signal with distant signal       | Hp0, Hp1, Hp2 and Hp0/Sh1
 *  Viessmann 4015 - H0 Colour light entry signal with distant signal       | Hp0, Hp1, Vr0, Vr1 and Vr2
 *  Viessmann 4016 - H0 Colour light departure signal with distant signal   | Hp0, Hp1, Hp2, Hp0/Sh1, Vr0, Vr1 and Vr2
 *  
 *  Hp0       Halt                    Red               | mode 0
 *  Hp1       Fahrt                   Green             | mode 1
 *  Hp2       Langsamfahrt            Green/Yellow      | mode 2
 *  Hp0/Sh1   Shunting                Red/White         | mode 3
 *  
 *  Vr0       Halt erwarten           Yellow
 *  Vr1       Fahrt erwarten          Green
 *  Vr2       Langsamfahrt erwarten   Green/Yellow
 *  
 *  Hp0/Sh1   Shunting                Red/White
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

// Viessmann_4010(vr_green, vr_yellow);                                    // Viessmann 4010 = 3 Aspects HP        = 2 Addresses
// Viessmann_4011(hp_red,   hp_green);                                     // Viessmann 4011 = 2 Aspects HP        = 1 Address
// Viessmann_4013(hp_red1,  hp_red2,  hp_green,  hp_yellow, hp_white);     // Viessmann 4013 = 2 Aspects HP        = 2 Addresses
// Viessmann_4014(hp_red,   hp_green, vr_green,  vr_yellow);               // Viessmann 4014 = 2 Aspects HP & 3 VR = 3 Addresses
// Viessmann_4015(hp_red,   hp_green, hp_yellow, vr_green,  vr_yellow);    // Viessmann 4015 = 3 Aspects HP & 3 VR = 4 Addresses

Viessmann_4011 signal1(8, 9);
Viessmann_4013 signal2(3, 4, 5, 6, 7);

uint8_t test1, test2 = 0;

void setup() {

  Serial.begin(115200);
  
  signal1.init(21);
  signal2.init(23);
  
}

void loop() {

  if (test1 > 1) {
    signal1.set(100);
  } else {
    signal1.set(test1);
  }
  
  signal2.set(test2);
  
  delay(2000);
  
  test1++;
  test2++;

  if(test1 > 3) {
    test1 = 0;
  }

  if(test2 > 3) {
    test2 = 0;
  }
  
  // Serial.println(signal1.getaddress_hp());
  
}
