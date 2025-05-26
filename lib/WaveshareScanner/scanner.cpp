#include <HardwareSerial.h>
#include "scanner.h"
#include "scanner_utils.h"

WaveshareScanner::WaveshareScanner(HardwareSerial &scannerSerial) : serial(scannerSerial) {};

// Set the scanner to Command Mode to receive UART commands
void WaveshareScanner::setToCommandMode() {
  serial.write(UART_enterCommandMode, sizeof(UART_enterCommandMode));
};

// Start scanning
void WaveshareScanner::startScan() {
  serial.write(UART_startScanCommand, sizeof(UART_startScanCommand));
  int bufferSize = 7;
  uint8_t buffer[bufferSize];
  uint8_t* buffer_p = buffer;
  serial.readBytes(buffer_p, bufferSize);
  if (!responseConfirmed(buffer_p, bufferSize)) {
    Serial.println("Started Scanning");
  } else {
    Serial.print("Unexpected response recieved while trying to start scan: ");
    for (int i = 0 ; i < bufferSize ; i++){
      Serial.print(buffer_p[i]); Serial.print(" ");
    };
    Serial.println();
  }
};

// Stop the current scanning step
void WaveshareScanner::stopScan() {
  serial.write(UART_stopScanCommand, sizeof(UART_stopScanCommand));
};

// Read Available data in buffer as hex with 0x?? formatting
String WaveshareScanner::readAsHexString(){
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

// Read the string in the buffer until a new line is reached
String WaveshareScanner::readBuffer() {
  String data = serial.readStringUntil('\n');
  // Serial.println(data.substring(7)); // Skip acknowledge response
  Serial.println(data);
  lastBarcode = data;
  return data;
};


