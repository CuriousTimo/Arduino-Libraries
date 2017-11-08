/*
 * 
 * Strobe.cpp - Library for German Signals
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
#include "Strobe.h"
#include "Timing.h"

// Strobe
Strobe::Strobe(uint8_t pin, unsigned long on, unsigned long off):Blink(on, off) {
  pinMode(pin,  OUTPUT);

  _pin  = pin;
}

void Strobe::init(uint16_t address) {
  _address = address;
    
  //Off
  _state = 0;
  digitalWrite(_pin, LOW);
}

void Strobe::set(bool state) {
  _state  = state;
}

bool Strobe::update() {
  if (_state){                  //If timer is active
    if (millis()-started >= interval){  //and elapsed time is greater than interval
      if (!out){                //and output is off
        interval = interval1;   //change the time to check to interval1 (time on)
      }
      else{                     //If output is on
        interval = interval2;   //change the time to check to interval2 (time off)
      }
      started = millis();       //store when output is changed (elapsed times greater than interval)
      out = !out;               //toggle the output
    }
  }
  else{                         //If timer isn't active
    out = false;                //set output to low level
  }
  digitalWrite(_pin ,out);
}

uint16_t Strobe::getaddress() {
  return _address;
} // end of Strobe
