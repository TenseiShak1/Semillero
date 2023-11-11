#include <PowerDetector.h>

const int indicadorAddress = 0;
const byte indicadorValue = 42;

PowerDetector powerDetector(indicadorAddress, indicadorValue);

void setup() {
  Serial.begin(9600);
  powerDetector.begin();

  if (powerDetector.isPowerOn()) {
    Serial.println("El Arduino está encendido.");
  } else {
    Serial.println("El Arduino se ha reiniciado o encendido por primera vez.");
  }
}

void loop() {
  // El código principal va aquí
}
