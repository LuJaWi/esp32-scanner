#include "scanner_utils.h"
#include <Arduino.h>

bool responseConfirmed(uint8_t* response, size_t responseSize) {
  if (responseSize != sizeof(WS_ACK)) {
    return false;
  }
  for (int i = 0; i < responseSize ; i++) {
    if (response[i] != WS_ACK[i]) {
      return false;
    }
  }
  return true;
};