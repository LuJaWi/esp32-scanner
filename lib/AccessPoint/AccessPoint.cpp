#include <WiFi.h>
#include "AccessPoint.h"

void AccessPoint::startServer() {
  // Start TCP server
  server.begin();
  // Start Wi-Fi Access Point
  WiFi.softAP(ssid, password);
  IP = WiFi.softAPIP();
};

void AccessPoint::checkConnection() {
  if (!client || !client.connected()) {
    client = server.available();
    if (client) {
      Serial.println("Client connected");
      client.setTimeout(10);  // Short timeout for responsiveness
    }
  }
};

// Modify receiveCommand to use the map
void AccessPoint::receiveCommand() {
  if (client && client.connected() && client.available()) {
    String cmd = client.readStringUntil('\n');
    cmd.trim();
    if (cmd.length() > 0) {
      Serial.print("Command received: ");  Serial.println(cmd);
      currentCommand = cmd;
    }
  }
}
