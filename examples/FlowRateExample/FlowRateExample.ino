/*
  FlowRateExample.ino - Example using FlowMeter library
  Created by Peter Linder, February 11, 2020.
  Released into the public domain.
*/

#include "FlowMeter.h"

FlowMeter fm;

void setup() {
  Serial.begin(9600);
  fm.attach(2); // Flow meter is connected to digital pin 2
}

void loop() {
  double rate = fm.measure(1000); // Take 1000 ms (1 sec) to measure flow rate
  Serial.print("Flow rate (L/min): ");
  Serial.println(rate);
}
