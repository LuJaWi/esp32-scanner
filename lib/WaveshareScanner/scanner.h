// Scanner Library
#pragma once

#include <HardwareSerial.h>

class WaveshareScanner {
public:
  WaveshareScanner(HardwareSerial &scannerSerial);
  HardwareSerial& serial;
  void setToCommandMode();
  void startScan();
  void stopScan();
  String readAsHexString();
  String readBuffer();
  String lastBarcode; // Previously read barcode

};