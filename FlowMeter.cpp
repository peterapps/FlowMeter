/*
  FlowMeter.cpp - Library for reading flow rate from Adafruit brass liquid flow meter
  Created by Peter Linder, February 11, 2020.
  Released into the public domain.
*/

#include "FlowMeter.h"

volatile int FlowMeter::pulses = 0;

FlowMeter::FlowMeter(){
}

void FlowMeter::attach(int pin){
  pinMode(pin, INPUT);
  attachInterrupt(digitalPinToInterrupt(pin), FlowMeter::flow_interrupt, RISING);
}

void FlowMeter::flow_interrupt(){
  ++pulses;
}

double FlowMeter::measure(int timeout){
  pulses = 0;
  interrupts();
  delay(timeout);
  noInterrupts();

  double dt = timeout/1000.0; // dt in seconds
  dt /= 60.0; // dt in minutes
  double liters = pulses / 485.0; // 485 pulses per liter
  return liters / dt;
}

/* References:
 *  https://www.bc-robotics.com/tutorials/using-a-flow-sensor-with-arduino/
 *  https://github.com/adafruit/Adafruit-Flow-Meter/blob/master/Adafruit_FlowMeter.pde
 *  https://www.adafruit.com/product/833
 */
