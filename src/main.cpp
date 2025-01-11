#include <Arduino.h>
#include <WiFi.h>
#include <base.h>
#include <iot_configs.h>

#define TELEMETRY_FREQUENCY_MILLISECS 2000

static unsigned long next_telemetry_send_time_ms = 0;
static String telemetry_payload;
static uint32_t message_count = 0;

void setup()
{
  Serial.begin(115200);

  // Establish the connection
  establishConnection();
}

void loop()
{
  // Check if the device is connected to the WiFi network
  if (WiFi.status() != WL_CONNECTED)
  {
    connectToWiFi();
  }
  else if (millis() > next_telemetry_send_time_ms)
  {
    // Prepare the telemetry payload
    telemetry_payload = "{ \"message_count\": " + String(message_count++) +
                        ", \"Millis\": " + String(millis()) + " }";

    // Send the telemetry payload
    sendTelemetry(telemetry_payload);

    // Schedule the next telemetry send
    next_telemetry_send_time_ms = millis() + TELEMETRY_FREQUENCY_MILLISECS;
  }
}
