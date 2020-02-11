/*
  FlowMeter.h - Library for reading flow rate from Adafruit brass liquid flow meter
  Created by Peter Linder, February 11, 2020.
  Released into the public domain.
*/

#ifndef _FLOWMETER_H
#define _FLOWMETER_H

#include "Arduino.h"

class FlowMeter {
private:
  static volatile int pulses;
  static void flow_interrupt();
public:
  FlowMeter();
  void attach(int pin);
  double measure(int timeout);
};

#endif // _FLOWMETER_H
