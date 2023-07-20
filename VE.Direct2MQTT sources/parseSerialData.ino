/*
  © MK4001 16 Jul 2023
  Write Victron Energy MPPT fields to MQTT
  based on ESP32 Wroom
*/

void parseSerialData(String data) {

  // Search for "TAB" and split field & value
  int tabPos = data.indexOf('\t');
  String field = data.substring(0, tabPos);
  String value = data.substring(tabPos + 1);

  //Main or channel 1 (battery) voltage (mV)
  if (field.equals("V")) {
    float voltage = value.toFloat() / 1000;
    publishFloatValue("VE/Battery Voltage", voltage);

    //Main or channel 1 battery current (mA)
  } else if (field.equals("I")) {
    float current = value.toFloat() / 1000;
    publishFloatValue("VE/Battery Current", current);
  }

  //Panel voltage (mV)
  else if (field.equals("VPV")) {
    float vpv = value.toFloat() / 1000;
    publishFloatValue("VE/PV voltage", vpv);
  }

  //Panel Power (W)
  else if (field.equals("PPV")) {
    float ppv = value.toFloat() / 1000;
    publishFloatValue("VE/PV Power", ppv);
  }

  //State of Operation
  else if (field.equals("CS")) {
    client.publish("VE/State of operation", value.c_str());
  }

  //Tracker operation mode
  else if (field.equals("MPPT")) {
    client.publish("VE/Operation mode", value.c_str());
  }

  //Off reason
  else if (field.equals("OR")) {
    client.publish("VE/Off reason", value.c_str());
  }

  //Error code
  else if (field.equals("ERR")) {
    client.publish("VE/Error code", value.c_str());
  }

  //Load output state (ON/OFF)
  else if (field.equals("LOAD")) {
    client.publish("VE/Load State", value.c_str());
  }

  //Load current (mA)
  else if (field.equals("IL")) {
    float il = value.toFloat() / 1000;
    publishFloatValue("VE/Load current", il);
  }

  //Yield total (0.01 kWh)
  else if (field.equals("H19")) {
    float yeld = value.toFloat() / 1000;
    publishFloatValue("VE/Yield total", yeld);
  }

  //Yield today (0.01 kWh)
  else if (field.equals("H20")) {
    float yeld = value.toFloat() / 1000;
    publishFloatValue("VE/Yield today", yeld);
  }

  //Maximum power today (W)
  else if (field.equals("H21")) {
    client.publish("VE/Max power today", value.c_str());
  }

  //Yield yesterday (0.01 kWh)
  else if (field.equals("H22")) {
    float yeld = value.toFloat() / 1000;
    publishFloatValue("VE/Yield yesterday", yeld);
  }

  //Maximum power yesterday (W)
  else if (field.equals("H23")) {
    client.publish("VE/Max power yesterday", value.c_str());
  }
}
