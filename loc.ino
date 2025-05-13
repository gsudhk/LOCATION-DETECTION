#include <Ultrasonic.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#define RXPin D7
#define TXPin D6
#define GPSBaud 9600
TinyGPSPlus gps;
SoftwareSerial gpsSerial(RXPin, TXPin);
const char* ssid = "Onexxxxd";
const char* password = "12xxx";
const char* server = "192.168.xxx.21";
WiFiClient client;
void setup() {
 Serial.begin(115200);
 gpsSerial.begin(GPSBaud)
 WiFi.begin(ssid, password);
 Serial.print("Connecting to WiFi...");
 while (WiFi.status() != WL_CONNECTED) {
 delay(500);
 Serial.print(".");
 }
 Serial.println("Connected!");
}
void loop() {
 while (gpsSerial.available() > 0) {
 gps.encode(gpsSerial.read());
 if (gps.location.isUpdated()) {
 float latitude = gps.location.lat();
 float longitude = gps.location.lng();
Serial.print("Lat: "); Serial.print(latitude, 6);
 Serial.print(" Lon: "); Serial.println(longitude, 6);
 sendGPSData(latitude, longitude);
 }
 }
}
void sendGPSData(float lat, float lon) {
 WiFiClient client;
 Serial.println("Connecting to server: 172xxx253.49");
 if (client.connect(server, 8000)) {
 Serial.println(" Connected to server! Sending GPS data...");
 StaticJsonDocument<200> jsonDoc;
 jsonDoc["latitude"] = lat;
 jsonDoc["longitude"] = lon;
 String postData;
 serializeJson(jsonDoc, postData);
 Serial.print(" Sending Data: ");
 Serial.println(postData);
 client.println("POST /gps HTTP/1.1");
 client.println("Host: 192.xxx.228.21");
 client.println("Content-Type: application/json");
 client.println("Content-Length: " + String(postData.length()));
 client.println();
 client.println(postData);
 delay(500);
 Serial.println(" Data sent successfully!");
 } else {
 Serial.println(" Connection to server failed!");
 }
 client.stop();
}