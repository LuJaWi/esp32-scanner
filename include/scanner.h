#pragma once

#include <HardwareSerial.h>

class WaveshareScanner {
public:
  WaveshareScanner(HardwareSerial &scannerSerial);
  HardwareSerial& serial;
  void setToCommandMode();
  void startScan();
  void stopScan();
};