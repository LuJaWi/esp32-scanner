#pragma once

#include <Arduino.h>

/*
Waveshare Scanner UART Command Structure:
[Header] [Length] [Command Type] [Command Code] [Data] [Checksum]

*/

uint8_t triggerScanCommand[] = {
  0x7E, 0x00,              // Header
  0x08,                    // Command type
  0x01,                    // Command Length
  0x00, 0x02, 0x01,        // CMD 0x0002 = Trigger Scan, 0x01 = start
  0x0A,                    // Checksum (example)
  0x7E
};


uint8_t disableStartupBeep[] = {
  0x7E, 0x00, 0x08, 0x01,  // Header + Length + Command Type + Code
  0x00, 0x21, 0x00,        // CMD: 0x0021 = Buzzer Control, Data = 0x00 = Off
  0x29,                    // XOR checksum (example, adjust as needed)
  0x7E                     // Footer
};


uint8_t calculateChecksum(const uint8_t* data, size_t length);
