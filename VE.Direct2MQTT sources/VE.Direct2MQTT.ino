/*
  © MK4001 16 Jul 2023
  Write Victron Energy MPPT fields to MQTT
  based on ESP32 Wroom
*/

#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Your WiFi SSID here";
const char* password = "Your WiFi pwd here";
const char* mqttServer = "Your MQTT broker address here";
const int mqttPort = 1883;
//const char* mqttUser = "MQTT username ";
//const char* mqttPassword = "MQTT pwd";

#define SERIAL_PORT Serial2

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);

  SERIAL_PORT.begin(19200);  // Default speed of Victron UART VE.Direct port

  connectToWiFi();

  client.setServer(mqttServer, mqttPort);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  if (SERIAL_PORT.available()) {
    String message = SERIAL_PORT.readStringUntil('\n');

    /*  DEGUB ONLY
    Serial.print("String: |");
    Serial.print(message);
    Serial.println ("|");
*/
    message.trim();

    parseSerialData(message);
  }
}

