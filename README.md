# VE.Direct2MQTT
Victron Energy VE.Direct UART data output to MQTT using Espressif ESP32

The idea of untying the Smart Solar MPPT 75/15 by Victron Energy from the BLE APP of the smartphone and being able to bring the send to an MQTT broker, led me to create this project.

The VE.Direct interface, on most Victron Energy products, is in fact a UART which transmits at a rate of one record per second at 19200 baud.

It is necessary to make a simple adapter cable with the help of a JST 2.0 PH 4 connector easily available both on Amazon and on Aliexpress.

The pins of the UART port in question, I only used PINs 1 (GND) and 3 (TX), then connected to Serial2 of a "DEVIT V1 ESP32-WROOM-32 Development Board" (Ports GND and GPIO16).

<img width="1369" alt="Screenshot 2023-07-20 at 09 47 55" src="https://github.com/mk4001/VE.Direct2InfluxDB/assets/50479511/780e0403-754e-42f9-90fa-479fb00701fc">

Data, flows from the UART port at the rate of 1 record/sec.

Detailed documentation of the fields, their format and content is gathered here:

https://www.victronenergy.com/upload/documents/VE.Direct-Protocol-3.33.pdf

Once the record has been captured on the ESP32, needs to parse the fields and collect the data, of what we need, before sending to MQTT broker

When your broker is finally receiving data you can decide to collect them (maybe using InfluxDB TELEGRAF):

https://www.influxdata.com/time-series-platform/telegraf/

and create a wonderful Dashboard on Grafana (always in the cloud, always free)

https://grafana.com/auth/sign-up/create-user?pg=hp&plcmt=hero-btn1&cta=create-free-account

With a little imagination and above all practice, you can even create dashboards like these:

![image1](https://github.com/mk4001/VE.Direct2InfluxDB/assets/50479511/0b3f3881-2aa3-4213-99fa-47e8b954535b)

![image2](https://github.com/mk4001/VE.Direct2InfluxDB/assets/50479511/179841d6-7990-4e45-8d7f-5db96ba6c5a7)

the obviously "cool" thing about this is that you can consult the data of your Victron Energy devices quickly and easily from anywhere and customize them as you like.
