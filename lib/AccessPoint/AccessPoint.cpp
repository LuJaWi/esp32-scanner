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

#include <unordered_map>
#include <functional>

// Define a type for command handler functions
using CommandHandler = std::function<void(const String&)>;

// Example command handlers
void handleStart(const String& cmd) {
  Serial.println("Handling START command");
}

void handleStop(const String& cmd) {
  Serial.println("Handling STOP command");
}

// Unordered map for command parsing
std::unordered_map<String, CommandHandler> commandMap = {
  {"START", handleStart},
  {"STOP", handleStop}
};

// Modify receiveCommand to use the map
void AccessPoint::receiveCommand(String cmd) {
  if (client && client.connected() && client.available()) {
    cmd.trim();
    Serial.print("Command received: ");  Serial.println(cmd);

    auto it = commandMap.find(cmd);
    if (it != commandMap.end()) {
      it->second(cmd); // Call the handler
    } else {
      Serial.println("Unknown command");
    }
  }
}
