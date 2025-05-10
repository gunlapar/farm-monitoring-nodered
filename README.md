# 📡 **Farm Monitoring dengan Node-RED dan ESP8266** 🚀

Proyek ini adalah sistem pemantauan lingkungan berbasis **ESP8266** yang mengumpulkan data suhu, kelembaban, intensitas cahaya, dan gas menggunakan sensor **DHT11**, **LDR**, dan **MQ-135**, lalu mengirimnya ke **Node-RED** melalui **MQTT**.

## ⚙ **Fitur**
- 🌡 **Pemantauan Suhu & Kelembaban** menggunakan **DHT11**
- 🔆 **Deteksi Intensitas Cahaya** menggunakan **LDR**  
- 💨 **Deteksi Gas** menggunakan **MQ-135**
- 📡 **Pengiriman Data ke Node-RED** melalui **MQTT**
- 💡 **Kontrol LED berdasarkan kondisi pencahayaan**
- 🌐 **Koneksi Wi-Fi untuk komunikasi data**

## 🛠 **Hardware yang Diperlukan**
- **ESP8266 (misalnya NodeMCU)**
- **Sensor DHT11** untuk suhu & kelembaban
- **Sensor LDR** untuk intensitas cahaya
- **Sensor MQ-135** untuk deteksi gas
- **LED indikator**
- **Broker MQTT** (misalnya Mosquitto)
- **Node-RED** sebagai server pemrosesan data

## 🔧 **Instalasi & Konfigurasi**
1. **Clone Repository** *(jika menggunakan GitHub)*
   ```sh
   git clone https://github.com/gunlapar/farm-monitoring-nodered.git
   cd farm-monitoring-nodered


- Instal Library yang Dibutuhkan
- ESP8266WiFi
- PubSubClient
- DHT Sensor Library
- Gunakan Arduino IDE atau PlatformIO untuk menginstalnya.
- Ubah Konfigurasi Wi-Fi & MQTT Edit bagian berikut dalam kode:
const char* ssid       = "";
const char* password   = "";
const char* mqtt_server = "";
const int mqtt_port = 1883;
- Gantilah dengan SSID & Password Wi-Fi serta Alamat MQTT Broker yang sesuai.
🔄 Cara Kerja- ESP8266 menghubungkan ke Wi-Fi.
- Data sensor dikumpulkan setiap 1 detik.
- LED menyala saat lingkungan gelap.
- Data dikirim ke Node-RED melalui MQTT dalam format JSON:
{
  "temp": 26.5,
  "hum": 60.3,
  "ldr": 380,
  "gas": "detected"
}
- Node-RED memproses dan menyimpan data atau melakukan aksi tertentu.
🚀 Cara Menjalankan- Upload kode ke ESP8266 menggunakan Arduino IDE atau PlatformIO.
- Pastikan broker MQTT aktif (gunakan Mosquitto atau broker lain).
- Jalankan Node-RED untuk menerima data sensor.
- Monitor output melalui Serial Monitor atau dashboard Node-RED.

Here's the English version of README.md:
# 📡 **Farm Monitoring with Node-RED and ESP8266** 🚀

This project is an **ESP8266-based** environmental monitoring system that collects temperature, humidity, light intensity, and gas data using **DHT11**, **LDR**, and **MQ-135** sensors, then sends the data to **Node-RED** via **MQTT**.

## ⚙ **Features**
- 🌡 **Temperature & Humidity Monitoring** using **DHT11**
- 🔆 **Light Intensity Detection** using **LDR**
- 💨 **Gas Detection** using **MQ-135**
- 📡 **Data Transmission to Node-RED** via **MQTT**
- 💡 **LED control based on lighting conditions**
- 🌐 **Wi-Fi connection for data communication**

## 🛠 **Required Hardware**
- **ESP8266 (e.g., NodeMCU)**
- **DHT11 Sensor** for temperature & humidity
- **LDR Sensor** for light intensity detection
- **MQ-135 Sensor** for gas detection
- **Indicator LED**
- **MQTT Broker** (e.g., Mosquitto)
- **Node-RED** for data processing

## 🔧 **Installation & Configuration**
1. **Clone the Repository** *(if using GitHub)*
   ```sh
   git clone https://github.com/gunlapar/farm-monitoring-nodered.git
   cd farm-monitoring-nodered

- Install the Required Libraries
- ESP8266WiFi
- PubSubClient
- DHT Sensor Library
- Use Arduino IDE or PlatformIO to install them.
- Update Wi-Fi & MQTT Configuration Edit the following section in the code:
const char* ssid       = "";
const char* password   = "";
const char* mqtt_server = "";
const int mqtt_port = 1883;
- Replace these with your Wi-Fi SSID & Password and MQTT Broker Address.
🔄 How It Works- ESP8266 connects to Wi-Fi.
- Sensor data is collected every 1 second.
- LED turns on when the environment is dark.
- Data is sent to Node-RED via MQTT in JSON format:
{
  "temp": 26.5,
  "hum": 60.3,
  "ldr": 380,
  "gas": "detected"
}
- Node-RED processes and stores the data or triggers actions.
🚀 How to Run- Upload the code to ESP8266 using Arduino IDE or PlatformIO.
- Ensure MQTT Broker is running (use Mosquitto or another broker).
- Start Node-RED to receive sensor data.
- Monitor the output via Serial Monitor or Node-RED dashboard.

