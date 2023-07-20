/*
  © MK4001 16 Jul 2023
  Write Victron Energy MPPT fields to MQTT
  based on ESP32 Wroom
*/

void publishFloatValue(const char* topic, float value) {
  char message[20];
  snprintf(message, sizeof(message), "%.2f", value);
  client.publish(topic, message);
}