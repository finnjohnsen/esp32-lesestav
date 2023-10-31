# esp32-lesestav

## Hardware 
- ESP32: Heltec WiFi Kit 32
- RFID EM4305 FDX-B Animal Tag Reader Module

## Tilkoblinger / PIN

- EM4305 trenger strøm
    - ESP32 5V -> EM4305 5V
    - ESP32 GRN -> EM4305 GRN
- Data fra EM4305 til ESP32
    - ESP32 GPIO_NUM_19 -> EM4305 TX

