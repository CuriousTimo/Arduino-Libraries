/*
 * 
 * Signals.cpp - Library for German Signals
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
 */

#include "Arduino.h"
#include "Signals.h"

// Viessmann_4010
Viessmann_4010::Viessmann_4010(uint8_t vr_green, uint8_t vr_yellow) {
  pinMode(vr_green,   OUTPUT);
  pinMode(vr_yellow,  OUTPUT);
  
  _vr_green   = vr_green;
  _vr_yellow  = vr_yellow;
}

void Viessmann_4010::init(uint16_t address_vr) {
  _address_vr = address_vr;
    
  //Vr0
  digitalWrite(_vr_green,   LOW);
  digitalWrite(_vr_yellow,  HIGH);
}

uint16_t Viessmann_4010::getaddress_vr() {
  return _address_vr;
}

void Viessmann_4010::set(uint8_t VR) {
  switch (VR) {
    case 0: // Vr0
      digitalWrite(_vr_yellow, LOW);
      digitalWrite(_vr_green,  HIGH);
      break;
    case 1: // Vr1
      digitalWrite(_vr_yellow, HIGH);
      digitalWrite(_vr_green,  LOW);
      break;
    case 2: // Vr2
      digitalWrite(_vr_yellow, LOW);
      digitalWrite(_vr_green,  LOW);
      break;
  }
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
Viessmann_4014::Viessmann_4014(uint8_t hp_red, uint8_t hp_green, uint8_t vr_green, uint8_t vr_yellow) {
  pinMode(hp_red,     OUTPUT);
  pinMode(hp_green,   OUTPUT);
  pinMode(vr_green,   OUTPUT);
  pinMode(vr_yellow,  OUTPUT);
  
  _hp_red     = hp_red;
  _hp_green   = hp_green;
  _vr_green   = vr_green;
  _vr_yellow  = vr_yellow;
}

void Viessmann_4014::init(uint16_t address_hp, uint16_t address_vr) {
  _address_hp = address_hp;
  _address_vr = address_vr;
    
  //Hp0
  digitalWrite(_hp_red,     LOW);
  digitalWrite(_hp_green,   HIGH);
  digitalWrite(_vr_green,   HIGH);
  digitalWrite(_vr_yellow,  HIGH);
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
  }

  switch (VR) {
    case 0: // Vr0
      digitalWrite(_vr_yellow, LOW);
      digitalWrite(_vr_green,  HIGH);
      break;
    case 1: // Vr1
      digitalWrite(_vr_yellow, HIGH);
      digitalWrite(_vr_green,  LOW);
      break;
    case 2: // Vr2
      digitalWrite(_vr_yellow, LOW);
      digitalWrite(_vr_green,  LOW);
      break;
  }
} // end of Viessmann_4014

// Viessmann_4015
Viessmann_4015::Viessmann_4015(uint8_t hp_red, uint8_t hp_green, uint8_t hp_yellow, uint8_t vr_green, uint8_t vr_yellow) {
  pinMode(hp_red,     OUTPUT);
  pinMode(hp_green,   OUTPUT);
  pinMode(hp_yellow,  OUTPUT);
  pinMode(vr_green,   OUTPUT);
  pinMode(vr_yellow,  OUTPUT);
  
  _hp_red     = hp_red;
  _hp_green   = hp_green;
  _hp_yellow  = hp_yellow;
  _vr_green   = vr_green;
  _vr_yellow  = vr_yellow;
}

void Viessmann_4015::init(uint16_t address_hp, uint16_t address_vr) {
  _address_hp = address_hp;
  _address_vr = address_vr;
    
  //Hp0
  digitalWrite(_hp_red,     LOW);
  digitalWrite(_hp_green,   HIGH);
  digitalWrite(_hp_yellow,  HIGH);
  digitalWrite(_vr_green,   HIGH);
  digitalWrite(_vr_yellow,  HIGH);
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
      digitalWrite(_hp_red,    LOW);
      digitalWrite(_hp_green,  HIGH);
      digitalWrite(_hp_yellow, HIGH);
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
  }

  switch (VR) {
    case 0: // Vr0
      digitalWrite(_vr_yellow, LOW);
      digitalWrite(_vr_green,  HIGH);
      break;
    case 1: // Vr1
      digitalWrite(_vr_yellow, HIGH);
      digitalWrite(_vr_green,  LOW);
      break;
    case 2: // Vr2
      digitalWrite(_vr_yellow, LOW);
      digitalWrite(_vr_green,  LOW);
      break;
  }
} // end of Viessmann_4015
