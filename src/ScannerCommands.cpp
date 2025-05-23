#include "../include/ScannerCommands.h"

/**
 * @brief Calculates the checksum for a given data buffer.
 *
 * This function computes the checksum by performing a bitwise XOR operation
 * over the data bytes, excluding the start byte (index 0) and the stop byte
 * (last index). The checksum is initialized to 0x00 and updated for each
 * relevant byte in the buffer.
 *
 * @param data   Pointer to the data buffer.
 * @param length Length of the data buffer.
 * @return The calculated checksum as a uint8_t value.
 */
uint8_t calculateChecksum(const uint8_t* data, size_t length) {
  uint8_t checksum = 0x00;
  for (size_t i = 1; i < length - 2; i++) {  // Skip start byte [0] and stop byte [length - 1]
    checksum ^= data[i];
  }
  return checksum;
}

/**
 * @brief Calculates the CRC-CCITT (XModem) checksum for a given data buffer.
 *
 * This function computes the 16-bit CRC-CCITT checksum using the polynomial 0x1021,
 * starting with an initial value of 0x0000. It processes each byte of the input data
 * and updates the CRC accordingly.
 *
 * @param data Pointer to the input data buffer.
 * @param len  Number of bytes in the data buffer.
 * @return The computed 16-bit CRC-CCITT checksum.
 */
uint16_t crc_ccitt(const uint8_t* data, size_t len) {
  uint16_t crc = 0x0000;
  for (size_t i = 0; i < len; ++i) {
    crc ^= (uint16_t)data[i] << 8;
    for (int j = 0; j < 8; ++j) {
      if (crc & 0x8000) crc = (crc << 1) ^ 0x1021;
      else crc <<= 1;
    }
  }
  return crc;
}


void sendWriteCommand(HardwareSerial& scannerSerial, uint16_t address, const uint8_t* data, uint8_t length) {
  uint8_t packet[260];  // Enough for header + max data + CRC
  size_t i = 0;

  // Header
  packet[i++] = 0x7E;
  packet[i++] = 0x00;

  // Type and Length
  packet[i++] = 0x08;
  packet[i++] = (length == 256) ? 0x00 : length;

  // Address (big-endian)
  packet[i++] = (address >> 8) & 0xFF;
  packet[i++] = address & 0xFF;

  // Data
  for (int j = 0; j < length; ++j) {
    packet[i++] = data[j];
  }

  // Calculate CRC over Type through last Data byte
  uint16_t crc = crc_ccitt(&packet[2], 1 + 1 + 2 + length);  // Type+Len+Addr+Data
  packet[i++] = (crc >> 8) & 0xFF;
  packet[i++] = crc & 0xFF;

  // Send packet
  scannerSerial.write(packet, i);
}
