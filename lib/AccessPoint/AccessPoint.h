#pragma once

#include <WiFi.h>

#define SERVER_PORT 9316

// Access Point credentials
const char *ssid = "WaveScan32";
const char *password = "ScanJam";

class AccessPoint {
public:
  void startServer();
  void checkConnection();
  void receiveCommand(String cmd);
  int serverPort = SERVER_PORT;
  WiFiServer server = WiFiServer(serverPort);
  WiFiClient client;
  IPAddress IP;
};