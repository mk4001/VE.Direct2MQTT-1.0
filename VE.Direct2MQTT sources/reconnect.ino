/*
  © MK4001 16 Jul 2023
  Write Victron Energy MPPT fields to MQTT
  based on ESP32 Wroom
*/

void reconnect() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT...");
    if (client.connect("ESP32-WROOM")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" retrying in 5 seconds");
      delay(5000);
    }
  }
}