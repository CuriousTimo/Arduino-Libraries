/* 
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

#ifndef Viessmann_N_h
#define Viessmann_N_h

// Viessmann_4410
class Viessmann_4410
{
  public:
    Viessmann_4410(uint8_t vr_green1, uint8_t vr_yellow1, uint8_t vr_green2, uint8_t vr_yellow2);
    void init(uint16_t address_vr);
    void set(uint8_t VR);
    uint16_t getaddress_vr();
    
  private:
    uint8_t _vr_green1;
    uint8_t _vr_green2;
    uint8_t _vr_yellow1;
    uint8_t _vr_yellow2;
    uint16_t _address_vr;
}; // end of Viessmann_4410

#endif

