#ifndef BASE_H
#define BASE_H

#include <Arduino.h>

// Function declarations
void establishConnection();
void connectToWiFi();
void sendTelemetry(String telemetry_payload);

#endif // IOTFLORABOT_H
