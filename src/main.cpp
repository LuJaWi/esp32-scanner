#include <HardwareSerial.h>
#include "../include/header.h"

#define UART_NUM 2
#define RXD2 16 // TX from Scanner into RX on MCU
#define TXD2 17 // RX from Scanner into TX on MCU
// Waveshare scanner uses 5v (VCC)

HardwareSerial ScannerSerial(UART_NUM); // UART2
WaveshareScanner Scanner(ScannerSerial); // From Waveshare Scanner Library
// AccessPoint accessPoint;

void readManualScan(HardwareSerial& scanner){
  String barcode = scanner.readStringUntil('\n');
  Serial.print("Scanned: ");
  Serial.println(barcode);
};

void setup() {
  Serial.begin(115200);
  Scanner.serial.begin(9600, SERIAL_8N1, RXD2, TXD2);

  delay(500); // Allow time for scanner to initialize
  Scanner.setToCommandMode();
  delay(500);
  ScannerSerial.flush();
  // accessPoint.startServer();
}

void loop() {
  // accessPoint.receiveCommand();
  // if (accessPoint.currentCommand == "SCAN") {
    Scanner.startScan();
    Scanner.readAsHexString();
    Scanner.readBuffer();
    if (Scanner.lastBarcode != ""){
      Serial.print("Barcode: "); Serial.println(Scanner.lastBarcode);
    }
  // }
  delay(20);
}
