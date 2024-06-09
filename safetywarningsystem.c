#include <avr/io.h>

#define A0 PIN_A0  // Car On Sensor
#define A1 PIN_A1  // Driver Seated Sensor
#define A2 PIN_A2  // Seatbelt Fastened Sensor
#define B0 PIN_B0  // Warning Light

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(B0, OUTPUT);
}

void loop() {
  int carOn = digitalRead(A0);
  int driverSeated = digitalRead(A1);
  int seatbeltFastened = digitalRead(A2);

  // Turn on warning light if car is on, driver seated, and seatbelt not fastened
  if (carOn && driverSeated && !seatbeltFastened) {
    digitalWrite(B0, HIGH);
  } else {
    digitalWrite(B0, LOW);
  }
}
