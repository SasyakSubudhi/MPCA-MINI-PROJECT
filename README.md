# 🌱 Automatic Plant Irrigation System using Arduino

## 📌 Overview

This project is an automated irrigation system that uses an Arduino to monitor soil moisture and rainfall conditions to control a water pump. The system ensures that plants receive water only when required, reducing manual effort and conserving water.

---

## ⚙️ Features

* Automatic watering based on soil moisture
* Rain detection to prevent overwatering
* Real-time monitoring using Serial Monitor
* Simple and low-cost implementation

---

## 🧰 Components Used

* Arduino Uno
* Soil Moisture Sensor
* Rain Sensor
* Water Pump
* Jumper Wires
* Breadboard

---

## 🔌 Circuit Connections

* Moisture Sensor → A0
* Rain Sensor (DO) → D8
* Pump → D7 (controlled output)
* VCC → 5V
* GND → Common Ground

---

## 🧠 Working Principle

The system continuously reads data from the moisture and rain sensors. If rain is detected, the pump remains OFF. If there is no rain and the soil is dry (moisture value above threshold), the Arduino turns ON the pump. If the soil is wet, the pump stays OFF. This ensures efficient irrigation and prevents water wastage.

---

## 💻 Code

The Arduino code reads sensor values, compares them with predefined thresholds, and controls the pump accordingly. Serial Monitor is used to display real-time sensor values and system status.

---

## 📊 Sample Output

![Uploading OUTPPUT.png…]()



## 🚀 How to Run

1. Connect all components as per circuit diagram
2. Upload the code using Arduino IDE
3. Open Serial Monitor (9600 baud)
4. Observe sensor values and pump behavior

---

## 🎯 Applications

* Smart agriculture
* Home gardening
* Greenhouse automation

---

## ⚠️ Limitations

* Sensor accuracy may vary
* Pump requires proper power handling (relay recommended for real use)

---

## 📌 Future Improvements

* Add IoT (mobile app monitoring)
* Use relay/transistor for safe pump control
* Add temperature-based control

---

## 👨‍💻 Author

Sasyak Subudhi(PES1UG24AM256)
SUJAN S M (PES1UG24AM292)
Swasthik Pamadi (PES1UG24AM298)

---
