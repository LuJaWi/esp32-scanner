#include <HardwareSerial.h>
#include "../include/scanner.h"
#include "../include/scanner_utils.h"



class WaveshareScanner {
public:
  // Create a class to interface with a Waveshare scanner module via a HardwareSerial connection.
  WaveshareScanner(HardwareSerial &scannerSerial) : serial(scannerSerial) {
  };
  HardwareSerial& serial;
  void setToCommandMode();
  void startScan();
  void stopScan();
  String readAsHex();
};

// Set the scanner to Command Mode to receive UART commands
void WaveshareScanner::setToCommandMode() {
  serial.write(UART_enterCommandMode, sizeof(UART_enterCommandMode));
};

// Start scanning
void WaveshareScanner::startScan() {
  serial.write(UART_startScanCommand, sizeof(UART_startScanCommand));
};

// Stop the current scanning step
void WaveshareScanner::stopScan() {
  serial.write(UART_stopScanCommand, sizeof(UART_stopScanCommand));
};

String WaveshareScanner::readAsHex(){
  String hexOut = "";
  String a;
  while (serial.available()) {
    a = "0x";
    int b = serial.read();
    a += String(b);
    a += " ";
    hexOut += a;
    Serial.print("0x");
    Serial.print(b, HEX);
    Serial.print(" ");
  }
  return hexOut;
};
