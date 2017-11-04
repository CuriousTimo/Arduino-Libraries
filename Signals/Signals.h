/*
  Signals.h - Library for German Signals
  Created by Timo Sariwating, November 1, 2017.
  Released into the public domain.
*/

#ifndef Signals_h
#define Signals_h

#include "Arduino.h"

// Viessmann_4011
class Viessmann_4011
{
  public:
    Viessmann_4011(uint8_t hp_red, uint8_t hp_green);
    void begin(uint16_t address_hp);
    void set(uint8_t HP);
    uint16_t getaddress_hp();
    
  private:
    uint8_t _hp_red;
    uint8_t _hp_green;
    uint16_t _address_hp;
};

// Viessmann_4013
class Viessmann_4013
{
  public:
    Viessmann_4013(uint8_t hp_red1, uint8_t hp_red2, uint8_t hp_green, uint8_t hp_yellow, uint8_t hp_white);
    void begin(uint16_t address_hp);
    void set(uint8_t HP);
    uint16_t getaddress_hp();
    
  private:
    uint8_t _hp_red1;
    uint8_t _hp_red2;
    uint8_t _hp_green;
    uint8_t _hp_yellow;
    uint8_t _hp_white;
    uint16_t _address_hp;
};

// Viessmann_4014
class Viessmann_4014
{
  public:
    Viessmann_4014(uint8_t hp_red, uint8_t hp_green, uint8_t vr_green, uint8_t vr_yellow);
    void begin(uint16_t address_hp, uint16_t address_vr);
    void set(uint8_t HP, uint8_t VR);
    uint16_t getaddress_hp();
    uint16_t getaddress_vr();
    
  private:
    uint8_t _hp_red;
    uint8_t _hp_green;
    uint8_t _vr_green;
    uint8_t _vr_yellow;
    uint16_t _address_hp;
    uint16_t _address_vr;
};

// Viessmann_4015
class Viessmann_4015
{
  public:
    Viessmann_4015(uint8_t hp_red, uint8_t hp_green, uint8_t hp_yellow, uint8_t vr_green, uint8_t vr_yellow);
    void begin(uint16_t address_hp, uint16_t address_vr);
    void set(uint8_t HP, uint8_t VR);
    uint16_t getaddress_hp();
    uint16_t getaddress_vr();
    
  private:
    uint8_t _hp_red;
    uint8_t _hp_green;
    uint8_t _hp_yellow;
    uint8_t _vr_green;
    uint8_t _vr_yellow;
    uint16_t _address_hp;
    uint16_t _address_vr;
};

// Viessmann_4016
class Viessmann_4016
{
  public:
    Viessmann_4016(uint8_t hp_red, uint8_t hp_green, uint8_t hp_yellow, uint8_t hp_white, uint8_t vr_green, uint8_t vr_yellow);
    void begin(uint16_t address_hp, uint16_t address_vr);
    void set(uint8_t HP, uint8_t VR);
    uint16_t getaddress_hp();
    uint16_t getaddress_vr();
    
  private:
    uint8_t _hp_red;
    uint8_t _hp_green;
    uint8_t _hp_yellow;
    uint8_t _hp_white;
    uint8_t _vr_green;
    uint8_t _vr_yellow;
    uint16_t _address_hp;
    uint16_t _address_vr;
};

#endif

