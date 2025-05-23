#include <HardwareSerial.h>
#include "../lib/WaveshareScanner/scanner.h"

#define UART_NUM 2
#define RXD2 16 // TX from Scanner into RX on MCU
#define TXD2 17 // RX from Scanner into TX on MCU
// Waveshare scanner uses 5v (VCC)

HardwareSerial ScannerSerial(UART_NUM); // UART2
WaveshareScanner Scanner(ScannerSerial);

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
}

void loop() { 
  Scanner.startScan();
  Scanner.readAsHex();
  Scanner.readBuffer();  
}
