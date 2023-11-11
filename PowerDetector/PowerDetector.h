#ifndef PowerDetector_h
#define PowerDetector_h

#include <Arduino.h>
#include <EEPROM.h>

class PowerDetector {
public:
  PowerDetector(int indicadorAddress, byte indicadorValue);

  void begin();
  bool isPowerOn();

private:
  int address;
  byte value;
};

#endif
