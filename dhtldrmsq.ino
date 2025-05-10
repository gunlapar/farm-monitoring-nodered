#include <ESP8266WiFi.h>           // WiFi untuk ESP8266
#include <PubSubClient.h>          // MQTT client :contentReference[oaicite:8]{index=8}
#include <DHT.h>                   // Library DHT dari Adafruit :contentReference[oaicite:9]{index=9}

// —— Wi‑Fi & MQTT Settings ——
const char* ssid       = "Hyuuga";
const char* password   = "mimiperi123";
const char* mqtt_server= "192.168.1.125";
const int   mqtt_port  = 1883;
const char* mqtt_topic = "sensor/env";

// —— Pin Definitions ——
#define DHTPIN   D2
#define DHTTYPE  DHT11
DHT dht(DHTPIN, DHTTYPE);          // Inisialisasi DHT11 :contentReference[oaicite:10]{index=10}

const int LDRPin = A0;             // Analog pin untuk LDR :contentReference[oaicite:11]{index=11}
const int GASPin = D7;             // Digital pin untuk MQ‑135 DO :contentReference[oaicite:12]{index=12}
const int LEDPin = D5;             // Digital pin untuk LED indikator :contentReference[oaicite:13]{index=13}

const int threshold = 400;         // Ambang LDR (0–1023)

WiFiClient   espClient;
PubSubClient client(espClient);

// —— Fungsi Setup ——
void setup() {
  Serial.begin(115200);
  dht.begin();                     // Mulai DHT11 :contentReference[oaicite:14]{index=14}
  pinMode(GASPin, INPUT);          // MQ‑135 DO sebagai input digital
  pinMode(LEDPin, OUTPUT);         // LED sebagai output digital :contentReference[oaicite:15]{index=15}

  // Koneksi Wi‑Fi
  WiFi.begin(ssid, password);      // Memulai koneksi WiFi :contentReference[oaicite:16]{index=16}
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  // Koneksi MQTT
  client.setServer(mqtt_server, mqtt_port);
  while (!client.connected()) {
    client.connect("ESP8266Client");  // Connect ke broker :contentReference[oaicite:17]{index=17}
    delay(500);
  }
}

// —— Fungsi Loop ——
void loop() {
  if (!client.connected()) {
    client.connect("ESP8266Client");
  }
  client.loop();

  // 1) Baca DHT11
  float temperature = dht.readTemperature();
  float humidity    = dht.readHumidity();

  // 2) Baca LDR
  int rawLDR = analogRead(LDRPin);             // 0–1023 :contentReference[oaicite:18]{index=18}
  // Logika LED berdasarkan threshold
  if (rawLDR < threshold) {
    digitalWrite(LEDPin, HIGH);                // Menyalakan LED saat gelap :contentReference[oaicite:19]{index=19}
  } else {
    digitalWrite(LEDPin, LOW);                 // Mematikan LED saat terang :contentReference[oaicite:20]{index=20}
  }

  // 3) Baca MQ‑135 (digital)
  int gasState = digitalRead(GASPin);          // HIGH/LOW :contentReference[oaicite:21]{index=21}

  // 4) Buat JSON payload
  char payload[128];
  snprintf(payload, sizeof(payload),
    "{\"temp\":%.1f,\"hum\":%.1f,\"ldr\":%d,\"gas\":%s}",
    temperature, humidity, rawLDR,
    gasState == LOW ? "\"detected\"" : "\"clear\""
  );

  // 5) Publish via MQTT
  client.publish(mqtt_topic, payload);          // Kirim JSON ke Node‑RED :contentReference[oaicite:22]{index=22}
  Serial.println(payload);

  delay(1000);
}
