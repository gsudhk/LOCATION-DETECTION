-> Live GPS Tracker using ESP8266, FastAPI & Leaflet.js

This is a full-stack IoT project that tracks real-time GPS data using an ESP8266 (NodeMCU) microcontroller connected to a NEO-6M GPS module. The ESP8266 sends the live coordinates over Wi-Fi to a FastAPI backend via HTTP POST. The backend stores the latest GPS data and serves it to a frontend webpage built with Leaflet.js, which displays the live location on an interactive OpenStreetMap. The map updates every 2 seconds, giving a seamless live tracking experience.




-> Features

1) Real-time GPS location tracking
2)ESP8266 sends live latitude & longitude via HTTP
3) FastAPI backend handles GPS data and serves it to the frontend
4)Leaflet.js frontend map auto-refreshes every 2 seconds
5) CORS-enabled API for cross-device integration
6) Lightweight and ideal for IoT & student projects


-> Technologies Used

| Component       | Technology             |
|----------------|------------------------|
| Microcontroller| ESP8266 (NodeMCU)       |
| GPS Module     | NEO-6M GPS              |
| Communication  | HTTP over Wi-Fi         |
| Backend        | FastAPI (Python)        |
| Data Format    | JSON                    |
| Frontend       | HTML + JavaScript + Leaflet.js |
| Libraries Used | ArduinoJson, TinyGPS++  |




-> Project Structure

<img width="438" height="182" alt="image" src="https://github.com/user-attachments/assets/185bb8a0-06a0-4079-b461-59d042808d2d" />


->Block Diagram

<img width="798" height="799" alt="image" src="https://github.com/user-attachments/assets/a17c5a17-3562-4225-87a0-3816a413609c" />



-> Connections

<img width="1303" height="713" alt="image" src="https://github.com/user-attachments/assets/885a8e6f-c69d-4271-aecc-6d4228bb2f86" />

-> WEBSITE IMAGE

<img width="912" height="525" alt="image" src="https://github.com/user-attachments/assets/cbdc1601-26ce-4700-a890-cdc745efed2c" />


-> WORKING VIDEO


