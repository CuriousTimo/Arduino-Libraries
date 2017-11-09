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

#ifndef Viessmann_H0_h
#define Viessmann_H0_h

// VR Signals all have 2 Yellow and 2 Green LEDs so we can reuse this code
    void switch_VR(uint16_t _pin_yellow1, uint16_t _pin_yellow2, uint16_t _pin_green1,  uint16_t _pin_green2, uint8_t mode);


// Viessmann_4010
class Viessmann_4010
{
  public:
    Viessmann_4010(uint8_t vr_green1, uint8_t vr_yellow1, uint8_t vr_green2, uint8_t vr_yellow2);
    void init(uint16_t address_vr);
    void set(uint8_t VR);
    uint16_t getaddress_vr();
    
  private:
    uint8_t _vr_green1;
    uint8_t _vr_green2;
    uint8_t _vr_yellow1;
    uint8_t _vr_yellow2;
    uint16_t _address_vr;
}; // end of Viessmann_4010

// Viessmann_4011
class Viessmann_4011
{
  public:
    Viessmann_4011(uint8_t hp_red, uint8_t hp_green);
    void init(uint16_t address_hp);
    void set(uint8_t HP);
    uint16_t getaddress_hp();
    
  private:
    uint8_t _hp_red;
    uint8_t _hp_green;
    uint16_t _address_hp;
}; // end of Viessmann_4011

// Viessmann_4012
class Viessmann_4012
{
  public:
    Viessmann_4012(uint8_t hp_red, uint8_t hp_green, uint8_t hp_yellow);
    void init(uint16_t address_hp);
    void set(uint8_t HP);
    uint16_t getaddress_hp();
    
  private:
    uint8_t _hp_red;
    uint8_t _hp_green;
    uint8_t _hp_yellow;
    uint16_t _address_hp;
}; // end of Viessmann_4012

// Viessmann_4013
class Viessmann_4013
{
  public:
    Viessmann_4013(uint8_t hp_red1, uint8_t hp_red2, uint8_t hp_green, uint8_t hp_yellow, uint8_t hp_white);
    void init(uint16_t address_hp);
    void set(uint8_t HP);
    uint16_t getaddress_hp();
    
  private:
    uint8_t _hp_red1;
    uint8_t _hp_red2;
    uint8_t _hp_green;
    uint8_t _hp_yellow;
    uint8_t _hp_white;
    uint16_t _address_hp;
}; // end of Viessmann_4013

// Viessmann_4014
class Viessmann_4014
{
  public:
    Viessmann_4014(uint8_t hp_red, uint8_t hp_green, uint8_t vr_green1, uint8_t vr_yellow1, uint8_t vr_green2, uint8_t vr_yellow2);
    void init(uint16_t address_hp, uint16_t address_vr);
    void set(uint8_t HP, uint8_t VR);
    uint16_t getaddress_hp();
    uint16_t getaddress_vr();
    
  private:
    uint8_t _hp_red;
    uint8_t _hp_green;
    uint8_t _vr_green1;
    uint8_t _vr_green2;
    uint8_t _vr_yellow1;
    uint8_t _vr_yellow2;
    uint16_t _address_hp;
    uint16_t _address_vr;
}; // end of Viessmann_4014

// Viessmann_4015
class Viessmann_4015
{
  public:
    Viessmann_4015(uint8_t hp_red, uint8_t hp_green, uint8_t hp_yellow, uint8_t vr_green1, uint8_t vr_yellow1, uint8_t vr_green2, uint8_t vr_yellow2);
    void init(uint16_t address_hp, uint16_t address_vr);
    void set(uint8_t HP, uint8_t VR);
    uint16_t getaddress_hp();
    uint16_t getaddress_vr();
    
  private:
    uint8_t _hp_red;
    uint8_t _hp_green;
    uint8_t _hp_yellow;
    uint8_t _vr_green1;
    uint8_t _vr_green2;
    uint8_t _vr_yellow1;
    uint8_t _vr_yellow2;
    uint16_t _address_hp;
    uint16_t _address_vr;
}; // end of Viessmann_4015

// Viessmann_4016
class Viessmann_4016
{
  public:
    Viessmann_4016(uint8_t hp_red1, uint8_t hp_red2, uint8_t hp_green, uint8_t hp_yellow, uint8_t hp_white, uint8_t vr_green1, uint8_t vr_yellow1, uint8_t vr_green2, uint8_t vr_yellow2);
    void init(uint16_t address_hp, uint16_t address_vr);
    void set(uint8_t HP, uint8_t VR);
    uint16_t getaddress_hp();
    uint16_t getaddress_vr();
    
  private:
    uint8_t _hp_red1;
    uint8_t _hp_red2;
    uint8_t _hp_green;
    uint8_t _hp_yellow;
    uint8_t _hp_white;
    uint8_t _vr_green1;
    uint8_t _vr_green2;
    uint8_t _vr_yellow1;
    uint8_t _vr_yellow2;
    uint16_t _address_hp;
    uint16_t _address_vr;
}; // end of Viessmann_4016

// Viessmann_4017
class Viessmann_4017
{
  public:
    Viessmann_4017(uint8_t sh_red, uint8_t sh_white);
    void init(uint16_t address_sh);
    void set(uint8_t SH);
    uint16_t getaddress_sh();
    
  private:
    uint8_t _sh_red;
    uint8_t _sh_white;
    uint16_t _address_sh;
}; // end of Viessmann_4017

// Viessmann_4018
class Viessmann_4018
{
  public:
    Viessmann_4018(uint8_t sh_red, uint8_t sh_white);
    void init(uint16_t address_sh);
    void set(uint8_t SH);
    uint16_t getaddress_sh();
    
  private:
    uint8_t _sh_red;
    uint8_t _sh_white;
    uint16_t _address_sh;
}; // end of Viessmann_4018

// Viessmann_4030
class Viessmann_4030
{
  public:
    Viessmann_4030(uint8_t vr_green1, uint8_t vr_yellow1, uint8_t vr_green2, uint8_t vr_yellow2, uint8_t kl_white);
    void init(uint16_t address_vr, uint16_t address_kl);
    void set(uint8_t VR, uint8_t KL);
    uint16_t getaddress_vr();
    uint16_t getaddress_kl();
    
  private:
    uint8_t _vr_green1;
    uint8_t _vr_green2;
    uint8_t _vr_yellow1;
    uint8_t _vr_yellow2;
    uint8_t _kl_white;
    uint16_t _address_vr;
    uint16_t _address_kl;
}; // end of Viessmann_4030

#endif

