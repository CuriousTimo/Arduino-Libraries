/*
 * 
 * Viessmann_N.cpp - Library for German Signals
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
#include "Viessmann_N.h"

// Viessmann_4410
Viessmann_4410::Viessmann_4410(uint8_t vr_green1, uint8_t vr_yellow1, uint8_t vr_green2, uint8_t vr_yellow2) {
  pinMode(vr_green1,   OUTPUT);
  pinMode(vr_green2,   OUTPUT);
  pinMode(vr_yellow1,  OUTPUT);
  pinMode(vr_yellow2,  OUTPUT);
  
  _vr_green1   = vr_green1;
  _vr_green2   = vr_green2;
  _vr_yellow1  = vr_yellow1;
  _vr_yellow2  = vr_yellow1;
}

void Viessmann_4410::init(uint16_t address_vr) {
  _address_vr = address_vr;
    
  set(0); //Vr0
}

uint16_t Viessmann_4410::getaddress_vr() {
  return _address_vr;
}

void Viessmann_4410::set(uint8_t VR) {
  switch (VR) {
    case 0: // Vr0
      digitalWrite(_vr_yellow1, LOW);
      digitalWrite(_vr_yellow1, LOW);
      digitalWrite(_vr_green2,  HIGH);
      digitalWrite(_vr_green2,  HIGH);
      break;
    case 1: // Vr1
      digitalWrite(_vr_yellow1, HIGH);
      digitalWrite(_vr_yellow2, HIGH);
      digitalWrite(_vr_green1,  LOW);     
      digitalWrite(_vr_green2,  LOW);
      break;
    case 2: // Vr2
      digitalWrite(_vr_yellow1, LOW);
      digitalWrite(_vr_yellow2, HIGH);
      digitalWrite(_vr_green1,  HIGH);
      digitalWrite(_vr_green2,  LOW);
      break;
    case 99: // LED TEST (All On)
      digitalWrite(_vr_yellow1, LOW);
      digitalWrite(_vr_yellow2, LOW);
      digitalWrite(_vr_green1,  LOW);
      digitalWrite(_vr_green2,  LOW);
      break;
    case 100: // All Off
      digitalWrite(_vr_yellow1, HIGH);
      digitalWrite(_vr_yellow2, HIGH);
      digitalWrite(_vr_green1,  HIGH);
      digitalWrite(_vr_green2,  HIGH);
      break;
  }
} // end of Viessmann_4410