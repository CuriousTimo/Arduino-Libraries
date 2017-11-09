/*
 * 
 * Viessmann_H0.cpp - Library for German Signals
 * 
 * Copyright (c) 2017 Timo Sariwating (Curious Timo). All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * This Library includes the Timing Libarary version 1.9 by Wallace Campos
 */

#include "Arduino.h"
#include "Viessmann_H0.h"

// VR Signals all have 2 Yellow and 2 Green LEDs so we can reuse this code
void switch_VR(uint16_t _pin_yellow1, uint16_t _pin_yellow2, uint16_t _pin_green1,  uint16_t _pin_green2, uint8_t mode) {
  
  switch (mode) {
    case 0: // Vr0
      digitalWrite(_pin_yellow1, LOW);
      digitalWrite(_pin_yellow2, LOW);
      digitalWrite(_pin_green1,  HIGH);
      digitalWrite(_pin_green2,  HIGH);
      break;
    case 1: // Vr1
      digitalWrite(_pin_yellow1, HIGH);
      digitalWrite(_pin_yellow2, HIGH);
      digitalWrite(_pin_green1,  LOW);     
      digitalWrite(_pin_green2,  LOW);
      break;
    case 2: // Vr2
      digitalWrite(_pin_yellow1, LOW);
      digitalWrite(_pin_yellow2, HIGH);
      digitalWrite(_pin_green1,  HIGH);
      digitalWrite(_pin_green2,  LOW);
      break;
    case 99: // LED TEST (All On)
      digitalWrite(_pin_yellow1, LOW);
      digitalWrite(_pin_yellow2, LOW);
      digitalWrite(_pin_green1,  LOW);
      digitalWrite(_pin_green2,  LOW);
      break;
    case 100: // All Off
      digitalWrite(_pin_yellow1, HIGH);
      digitalWrite(_pin_yellow2, HIGH);
      digitalWrite(_pin_green1,  HIGH);
      digitalWrite(_pin_green2,  HIGH);
      break;
  }
} // end of switch_VR

// Viessmann_4010
Viessmann_4010::Viessmann_4010(uint8_t vr_green1, uint8_t vr_yellow1, uint8_t vr_green2, uint8_t vr_yellow2) {
  pinMode(vr_green1,   OUTPUT);
  pinMode(vr_green2,   OUTPUT);
  pinMode(vr_yellow1,  OUTPUT);
  pinMode(vr_yellow2,  OUTPUT);
  
  _vr_green1   = vr_green1;
  _vr_green2   = vr_green2;
  _vr_yellow1  = vr_yellow1;
  _vr_yellow2  = vr_yellow1;
}

void Viessmann_4010::init(uint16_t address_vr) {
  _address_vr = address_vr;
    
  set(0); //Vr0
}

uint16_t Viessmann_4010::getaddress_vr() {
  return _address_vr;
}

void Viessmann_4010::set(uint8_t VR) {
  switch_VR(_vr_yellow1, _vr_yellow2, _vr_green1,  _vr_green2, VR);
} // end of Viessmann_4010

// Viessmann_4011
Viessmann_4011::Viessmann_4011(uint8_t hp_red, uint8_t hp_green) {
  pinMode(hp_red,   OUTPUT);
  pinMode(hp_green, OUTPUT);
  
  _hp_red     = hp_red;
  _hp_green   = hp_green;
}

void Viessmann_4011::init(uint16_t address_hp) {
  _address_hp = address_hp;

  set(0); //Hp0
}

uint16_t Viessmann_4011::getaddress_hp() {
  return _address_hp;
}

void Viessmann_4011::set(uint8_t HP) {
  switch (HP) {
    case 0: // Hp0
      digitalWrite(_hp_red,   LOW);
      digitalWrite(_hp_green, HIGH);
      break;
    case 1: // Hp1
      digitalWrite(_hp_red,   HIGH);
      digitalWrite(_hp_green, LOW);
      break;
    case 99: // LED TEST (All On)
      digitalWrite(_hp_red,   LOW);
      digitalWrite(_hp_green, LOW);
      break;
    case 100: // All Off
      digitalWrite(_hp_red,   HIGH);
      digitalWrite(_hp_green, HIGH);
      break;
  }
} // end of Viessmann_4011

// Viessmann_4012
Viessmann_4012::Viessmann_4012(uint8_t hp_red, uint8_t hp_green, uint8_t hp_yellow) {
  pinMode(hp_red,     OUTPUT);
  pinMode(hp_green,   OUTPUT);
  pinMode(hp_yellow,  OUTPUT);
  
  _hp_red     = hp_red;
  _hp_green   = hp_green;
  _hp_yellow  = hp_yellow;
}

void Viessmann_4012::init(uint16_t address_hp) {
  _address_hp = address_hp;
 
  set(0); //Hp0
}

uint16_t Viessmann_4012::getaddress_hp() {
  return _address_hp;
}

void Viessmann_4012::set(uint8_t HP) {
  switch (HP) {
    case 0: // Hp0
      digitalWrite(_hp_red,     LOW);
      digitalWrite(_hp_green,   HIGH);
      digitalWrite(_hp_yellow,  HIGH);
      break;
    case 1: // Hp1
      digitalWrite(_hp_red,     HIGH);
      digitalWrite(_hp_yellow,  HIGH);
      digitalWrite(_hp_green,   LOW);
      break;
    case 2: // Hp2
      digitalWrite(_hp_red,     HIGH);
      digitalWrite(_hp_yellow,  LOW);
      digitalWrite(_hp_green,   LOW);
      break;
    case 99: // LED TEST (All On)
      digitalWrite(_hp_red,     LOW);
      digitalWrite(_hp_yellow,  LOW);
      digitalWrite(_hp_green,   LOW);
      break;
    case 100: // All Off
      digitalWrite(_hp_red,     HIGH);
      digitalWrite(_hp_yellow,  HIGH);
      digitalWrite(_hp_green,   HIGH);
      break;
  }
} // end of Viessmann_4012

// Viessmann_4013
Viessmann_4013::Viessmann_4013(uint8_t hp_red1, uint8_t hp_red2, uint8_t hp_green, uint8_t hp_yellow, uint8_t hp_white) {
  pinMode(hp_red1,    OUTPUT);
  pinMode(hp_red2,    OUTPUT);
  pinMode(hp_green,   OUTPUT);
  pinMode(hp_yellow,  OUTPUT);
  pinMode(hp_white,   OUTPUT);
  
  _hp_red1    = hp_red1;
  _hp_red2    = hp_red2;
  _hp_green   = hp_green;
  _hp_yellow  = hp_yellow;
  _hp_white   = hp_white;
}

void Viessmann_4013::init(uint16_t address_hp) {
  _address_hp = address_hp;
    
  set(0); //Hp0
}

uint16_t Viessmann_4013::getaddress_hp() {
  return _address_hp;
}

void Viessmann_4013::set(uint8_t HP) {
  switch (HP) {
    case 0: // Hp0
      digitalWrite(_hp_red1,    LOW);
      digitalWrite(_hp_red2,    LOW);
      digitalWrite(_hp_green,   HIGH);
      digitalWrite(_hp_yellow,  HIGH);
      digitalWrite(_hp_white,   HIGH);
      break;
    case 1: // Hp1
      digitalWrite(_hp_red1,    HIGH);
      digitalWrite(_hp_red2,    HIGH);
      digitalWrite(_hp_green,   LOW);
      digitalWrite(_hp_yellow,  HIGH);
      digitalWrite(_hp_white,   HIGH);
      break;
    case 2: // Hp2
      digitalWrite(_hp_red1,    HIGH);
      digitalWrite(_hp_red2,    HIGH);
      digitalWrite(_hp_green,   LOW);
      digitalWrite(_hp_yellow,  LOW);
      digitalWrite(_hp_white,   HIGH);
      break;
    case 3: // Hp0/Sh1
      digitalWrite(_hp_red1,    LOW);
      digitalWrite(_hp_red2,    HIGH);
      digitalWrite(_hp_green,   HIGH);
      digitalWrite(_hp_yellow,  HIGH);
      digitalWrite(_hp_white,   LOW);
      break;
    case 99: // LED TEST (All On)
      digitalWrite(_hp_red1,    LOW);
      digitalWrite(_hp_red2,    LOW);
      digitalWrite(_hp_green,   LOW);
      digitalWrite(_hp_yellow,  LOW);
      digitalWrite(_hp_white,   LOW);
      break;
    case 100: // All Off
      digitalWrite(_hp_red1,    HIGH);
      digitalWrite(_hp_red2,    HIGH);
      digitalWrite(_hp_green,   HIGH);
      digitalWrite(_hp_yellow,  HIGH);
      digitalWrite(_hp_white,   HIGH);
      break;
  }
} // end of Viessmann_4013

// Viessmann_4014
Viessmann_4014::Viessmann_4014(uint8_t hp_red, uint8_t hp_green, uint8_t vr_green1, uint8_t vr_yellow1, uint8_t vr_green2, uint8_t vr_yellow2) {
  pinMode(hp_red,     OUTPUT);
  pinMode(hp_green,   OUTPUT);
  pinMode(vr_green1,   OUTPUT);
  pinMode(vr_green2,   OUTPUT);
  pinMode(vr_yellow1,  OUTPUT);
  pinMode(vr_yellow2,  OUTPUT);
  
  _hp_red     = hp_red;
  _hp_green   = hp_green;
  _vr_green1   = vr_green1;
  _vr_green2   = vr_green2;
  _vr_yellow1  = vr_yellow1;
  _vr_yellow2  = vr_yellow1;
}

void Viessmann_4014::init(uint16_t address_hp, uint16_t address_vr) {
  _address_hp = address_hp;
  _address_vr = address_vr;
  
  set(0, 0); //Hp0 & Vr0
}

uint16_t Viessmann_4014::getaddress_hp() {
  return _address_hp;
}

uint16_t Viessmann_4014::getaddress_vr() {
  return _address_vr;
}

void Viessmann_4014::set(uint8_t HP, uint8_t VR) {
  switch (HP) {
    case 0: // Hp0
      digitalWrite(_hp_red,   LOW);
      digitalWrite(_hp_green, HIGH);
      break;
    case 1: // Hp1
      digitalWrite(_hp_red,   HIGH);
      digitalWrite(_hp_green, LOW);
      break;
    case 99: // LED TEST (All On)
      digitalWrite(_hp_red,   LOW);
      digitalWrite(_hp_green, LOW);
      break;
    case 100: // All Off
      digitalWrite(_hp_red,   HIGH);
      digitalWrite(_hp_green, HIGH);
      break;
  }

  switch_VR(_vr_yellow1, _vr_yellow2, _vr_green1,  _vr_green2, VR);
} // end of Viessmann_4014

// Viessmann_4015
Viessmann_4015::Viessmann_4015(uint8_t hp_red, uint8_t hp_green, uint8_t hp_yellow, uint8_t vr_green1, uint8_t vr_yellow1, uint8_t vr_green2, uint8_t vr_yellow2) {
  pinMode(hp_red,     OUTPUT);
  pinMode(hp_green,   OUTPUT);
  pinMode(hp_yellow,  OUTPUT);
  pinMode(vr_green1,   OUTPUT);
  pinMode(vr_green2,   OUTPUT);
  pinMode(vr_yellow1,  OUTPUT);
  pinMode(vr_yellow2,  OUTPUT);
  
  _hp_red     = hp_red;
  _hp_green   = hp_green;
  _hp_yellow  = hp_yellow;
  _vr_green1   = vr_green1;
  _vr_green2   = vr_green2;
  _vr_yellow1  = vr_yellow1;
  _vr_yellow2  = vr_yellow1;
}

void Viessmann_4015::init(uint16_t address_hp, uint16_t address_vr) {
  _address_hp = address_hp;
  _address_vr = address_vr;
 
  set(0, 0); //Hp0 & Vr0    
}

uint16_t Viessmann_4015::getaddress_hp() {
  return _address_hp;
}

uint16_t Viessmann_4015::getaddress_vr() {
  return _address_vr;
}

void Viessmann_4015::set(uint8_t HP, uint8_t VR) {
  switch (HP) {
    case 0: // Hp0
      digitalWrite(_hp_red,     LOW);
      digitalWrite(_hp_green,   HIGH);
      digitalWrite(_hp_yellow,  HIGH);
      break;
    case 1: // Hp1
      digitalWrite(_hp_red,     HIGH);
      digitalWrite(_hp_yellow,  HIGH);
      digitalWrite(_hp_green,   LOW);
      break;
    case 2: // Hp2
      digitalWrite(_hp_red,     HIGH);
      digitalWrite(_hp_yellow,  LOW);
      digitalWrite(_hp_green,   LOW);
      break;
    case 99: // LED TEST (All On)
      digitalWrite(_hp_red,     LOW);
      digitalWrite(_hp_yellow,  LOW);
      digitalWrite(_hp_green,   LOW);
      break;
    case 100: // All Off
      digitalWrite(_hp_red,     HIGH);
      digitalWrite(_hp_yellow,  HIGH);
      digitalWrite(_hp_green,   HIGH);
      break;
  }

  switch_VR(_vr_yellow1, _vr_yellow2, _vr_green1,  _vr_green2, VR);
} // end of Viessmann_4015

// Viessmann_4016
Viessmann_4016::Viessmann_4016(uint8_t hp_red1, uint8_t hp_red2, uint8_t hp_green, uint8_t hp_yellow, uint8_t hp_white, uint8_t vr_green1, uint8_t vr_yellow1, uint8_t vr_green2, uint8_t vr_yellow2) {
  pinMode(hp_red1,    OUTPUT);
  pinMode(hp_red2,    OUTPUT);
  pinMode(hp_green,   OUTPUT);
  pinMode(hp_yellow,  OUTPUT);
  pinMode(hp_white,   OUTPUT);
  pinMode(vr_green1,   OUTPUT);
  pinMode(vr_green2,   OUTPUT);
  pinMode(vr_yellow1,  OUTPUT);
  pinMode(vr_yellow2,  OUTPUT);
  
  _hp_red1    = hp_red1;
  _hp_red2    = hp_red2;
  _hp_green   = hp_green;
  _hp_yellow  = hp_yellow;
  _hp_white   = hp_white;
  _vr_green1   = vr_green1;
  _vr_green2   = vr_green2;
  _vr_yellow1  = vr_yellow1;
  _vr_yellow2  = vr_yellow1;
}

void Viessmann_4016::init(uint16_t address_hp, uint16_t address_vr) {
  _address_hp = address_hp;
  _address_vr = address_vr;
 
  set(0, 0); //Hp0 & Vr0    
}

uint16_t Viessmann_4016::getaddress_hp() {
  return _address_hp;
}

uint16_t Viessmann_4016::getaddress_vr() {
  return _address_vr;
}

void Viessmann_4016::set(uint8_t HP, uint8_t VR) {
  switch (HP) {
    case 0: // Hp0
      digitalWrite(_hp_red1,    LOW);
      digitalWrite(_hp_red2,    LOW);
      digitalWrite(_hp_green,   HIGH);
      digitalWrite(_hp_yellow,  HIGH);
      digitalWrite(_hp_white,   HIGH);
      break;
    case 1: // Hp1
      digitalWrite(_hp_red1,    HIGH);
      digitalWrite(_hp_red2,    HIGH);
      digitalWrite(_hp_green,   LOW);
      digitalWrite(_hp_yellow,  HIGH);
      digitalWrite(_hp_white,   HIGH);
      break;
    case 2: // Hp2
      digitalWrite(_hp_red1,    HIGH);
      digitalWrite(_hp_red2,    HIGH);
      digitalWrite(_hp_green,   LOW);
      digitalWrite(_hp_yellow,  LOW);
      digitalWrite(_hp_white,   HIGH);
      break;
    case 3: // Hp0/Sh1
      digitalWrite(_hp_red1,    LOW);
      digitalWrite(_hp_red2,    HIGH);
      digitalWrite(_hp_green,   HIGH);
      digitalWrite(_hp_yellow,  HIGH);
      digitalWrite(_hp_white,   LOW);
      break;
    case 99: // LED TEST (All On)
      digitalWrite(_hp_red1,    LOW);
      digitalWrite(_hp_red2,    LOW);
      digitalWrite(_hp_green,   LOW);
      digitalWrite(_hp_yellow,  LOW);
      digitalWrite(_hp_white,   LOW);
      break;
    case 100: // All Off
      digitalWrite(_hp_red1,    HIGH);
      digitalWrite(_hp_red2,    HIGH);
      digitalWrite(_hp_green,   HIGH);
      digitalWrite(_hp_yellow,  HIGH);
      digitalWrite(_hp_white,   HIGH);
      break;
  }

  switch_VR(_vr_yellow1, _vr_yellow2, _vr_green1,  _vr_green2, VR);
} // end of Viessmann_4016

// Viessmann_4017
Viessmann_4017::Viessmann_4017(uint8_t sh_red, uint8_t sh_white) {
  pinMode(sh_red,    OUTPUT);
  pinMode(sh_white,  OUTPUT);
  
  _sh_red    = sh_red;
  _sh_white  = sh_white;
}

void Viessmann_4017::init(uint16_t address_sh) {
  _address_sh = address_sh;
    
  set(0); //Sh0
}

uint16_t Viessmann_4017::getaddress_sh() {
  return _address_sh;
}

void Viessmann_4017::set(uint8_t SH) {
  switch (SH) {
    case 0: // Sh0
      digitalWrite(_sh_red,   LOW);
      digitalWrite(_sh_white, HIGH);
      break;
    case 1: // Sh1
      digitalWrite(_sh_red,   HIGH);
      digitalWrite(_sh_white, LOW);
      break;
    case 99: // LED TEST (All On)
      digitalWrite(_sh_red,   LOW);
      digitalWrite(_sh_white, LOW);
      break;
    case 100: // All Off
      digitalWrite(_sh_red,   HIGH);
      digitalWrite(_sh_white, HIGH);
      break;
  }
} // end of Viessmann_4017

// Viessmann_4018
Viessmann_4018::Viessmann_4018(uint8_t sh_red, uint8_t sh_white) {
  pinMode(sh_red,    OUTPUT);
  pinMode(sh_white,  OUTPUT);
  
  _sh_red    = sh_red;
  _sh_white  = sh_white;
}

void Viessmann_4018::init(uint16_t address_sh) {
  _address_sh = address_sh;
    
  set(0); //Sh0
}

uint16_t Viessmann_4018::getaddress_sh() {
  return _address_sh;
}

void Viessmann_4018::set(uint8_t SH) {
  switch (SH) {
    case 0: // Sh0
      digitalWrite(_sh_red,   LOW);
      digitalWrite(_sh_white, HIGH);
      break;
    case 1: // Sh1
      digitalWrite(_sh_red,   HIGH);
      digitalWrite(_sh_white, LOW);
      break;
    case 99: // LED TEST (All On)
      digitalWrite(_sh_red,   LOW);
      digitalWrite(_sh_white, LOW);
      break;
    case 100: // All Off
      digitalWrite(_sh_red,   HIGH);
      digitalWrite(_sh_white, HIGH);
      break;
  }
} // end of Viessmann_4018

// Viessmann_4030
Viessmann_4030::Viessmann_4030(uint8_t vr_green1, uint8_t vr_yellow1, uint8_t vr_green2, uint8_t vr_yellow2, uint8_t kl_white) {
  pinMode(vr_green1,   OUTPUT);
  pinMode(vr_green2,   OUTPUT);
  pinMode(vr_yellow1,  OUTPUT);
  pinMode(vr_yellow2,  OUTPUT);
  pinMode(kl_white,  OUTPUT);
  
  _vr_green1   = vr_green1;
  _vr_green2   = vr_green2;
  _vr_yellow1  = vr_yellow1;
  _vr_yellow2  = vr_yellow1;
  _kl_white  = kl_white;
}

void Viessmann_4030::init(uint16_t address_vr, uint16_t address_kl) {
  _address_vr = address_vr;
  _address_kl = address_kl;
 
  set(0, 0); //Vr0 & KL Off   
}

uint16_t Viessmann_4030::getaddress_vr() {
  return _address_vr;
}

uint16_t Viessmann_4030::getaddress_kl() {
  return _address_kl;
}

void Viessmann_4030::set(uint8_t VR, uint8_t KL) {
  switch_VR(_vr_yellow1, _vr_yellow2, _vr_green1,  _vr_green2, VR);

  switch (KL) {
    case 0: // On
      digitalWrite(_kl_white, LOW);
      break;
    case 1: // Off
      digitalWrite(_kl_white, HIGH);
      break;
    case 99: // LED TEST (All On)
      digitalWrite(_kl_white, LOW);
      break;
    case 100: // All Off
      digitalWrite(_kl_white, HIGH);
      break;
  }
} // end of Viessmann_4030
