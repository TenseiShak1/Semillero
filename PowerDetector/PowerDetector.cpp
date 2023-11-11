#include "PowerDetector.h"

PowerDetector::PowerDetector(int indicadorAddress, byte indicadorValue) {
  address = indicadorAddress;
  value = indicadorValue;
}

void PowerDetector::begin() {
  byte storedValue = EEPROM.read(address);

  if (storedValue != value) {
    EEPROM.write(address, value);
  }
}

bool PowerDetector::isPowerOn() {
  return (EEPROM.read(address) == value);
}
