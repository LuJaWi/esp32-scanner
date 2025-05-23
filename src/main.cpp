#include <HardwareSerial.h>

#define RXD2 16 // TX from Scanner into RX on MCU
#define TXD2 17 // RX from Scanner into TX on MCU
// Waveshare scanner uses 5v (VCC)

HardwareSerial ScannerSerial(2); // UART2

uint8_t setToCommandMode[] = {
  0x7E, 0x00,
  0x08,
  0x01,
  0x00, 0x00,
  0x95,
  0xAB, 0xCD
};

uint8_t startScanCommand[] = {
  0x7E, 0x00,
  0x08,
  0x01,
  0x00, 0x02,
  0x01,
  0xAB, 0xCD
};

uint8_t stopScanCommand[] = {
  0x7E, 0x00,
  0x08,
  0x01,
  0x00, 0x02,
  0x00,
  0xAB, 0xCD
};

void readManualScan(HardwareSerial& scanner){
  String barcode = scanner.readStringUntil('\n');
  Serial.print("Scanned: ");
  Serial.println(barcode);
};

void setup() {
  Serial.begin(115200);
  ScannerSerial.begin(9600, SERIAL_8N1, RXD2, TXD2);

  delay(500); // Allow time for scanner to initialize
  ScannerSerial.write(setToCommandMode, sizeof(setToCommandMode));
  delay(500);
  ScannerSerial.flush();
}

void loop() { 
  ScannerSerial.write(startScanCommand, sizeof(startScanCommand));
  while (ScannerSerial.available()) {
    int b = ScannerSerial.read();
    Serial.print("0x");
    Serial.print(b, HEX);
    Serial.print(" ");
  }

  String data = ScannerSerial.readStringUntil('\n');
  if (data.length()>7){
    Serial.println(data.substring(7));
  }
  // ScannerSerial.write(stopScanCommand, sizeof(stopScanCommand));
    
}
