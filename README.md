# Send Data from ESP32 to Azure IoT Hub  
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)  

A step-by-step guide to securely transmit sensor data from an ESP32 microcontroller to Microsoft Azure IoT Hub using MQTT.  

---

## Project Overview  
This project demonstrates how to send telemetry data (e.g., mock temperature, humidity) from an ESP32 to **Azure IoT Hub**. It includes:  
- Secure communication with Azure IoT Hub (TLS 1.2).  
- JSON-formatted telemetry data.  
- Integration with PlatformIO (VS Code) for streamlined development.  

---

## Prerequisites  
### Hardware  
- ESP32 board (e.g., Seeed Studio XIAO ESP32-C6).  
- USB cable for programming.  

### Software  
- [Visual Studio Code](https://code.visualstudio.com/) with [PlatformIO](https://platformio.org/) extension.  
- [Azure account](https://azure.microsoft.com/) (free tier available).  

### Credentials  
- Wi-Fi SSID and password.  
- Azure IoT Hub connection details:  
  - **Hostname**  
  - **Device ID**  
  - **Primary Key**  

---

## Setup Instructions  

### 1. Configure Azure IoT Hub  
1. Create an **IoT Hub** in the [Azure Portal](https://portal.azure.com/).  
2. Register a new device in your IoT Hub and note its **Device ID** and **Primary Key**.  

### 2. Clone and Configure the Project  
```bash  
git clone https://github.com/your-repo/esp32-azure-iot.git
```
1. Open the project in VS Code with PlatformIO.
2. Update `lib/iot_configs/iot_configs.h` with your credentials:
```cpp
// Wi-Fi  
#define WIFI_SSID "your-ssid"  
#define WIFI_PASSWORD "your-password"  

// Azure IoT Hub  
#define HOSTNAME "your-iot-hub-hostname"  
#define DEVICE_ID "your-device-id"  
#define PRIMARY_KEY "your-primary-key"  
```
### 3. Upload Code to ESP32
1. Build the Project
2. Upload to ESP32
3. Use monitor output to debug
### 4. Verify Data in Azure IoT Hub
1. Navigate to your IoT Hub in the [Azure Portal](https://portal.azure.com/).
2. Use the Azure CLI to monitor incoming data:
```bash
az iot hub monitor-events --hub-name YourHubName --device-id YourDeviceID  
```
Example output:
```json
{"temperature": 25.5, "humidity": 60}
```

---

## Troubleshooting  

### 🔧 Common Issues & Fixes  
1. **Wi-Fi Connection Failed**  
   - **Cause**: Incorrect SSID or password.  
   - **Fix**: Update `WIFI_SSID` and `WIFI_PASSWORD` in `lib/iot_configs/iot_configs.h`.  

2. **Azure Authentication Error**  
   - **Cause**: Invalid IoT Hub credentials.  
   - **Fix**: Verify `HOSTNAME`, `DEVICE_ID`, and `PRIMARY_KEY` in `iot_configs.h`.  

3. **MQTT Protocol Errors**  
   - **Cause**: TLS version mismatch.  
   - **Fix**: Ensure Azure IoT Hub uses **TLS 1.2** (configured during hub creation).  

4. **Serial Monitor Shows No Output**  
   - **Cause**: Incorrect baud rate or USB port issues.  
   - **Fix**:  
     - Set Serial Monitor baud rate to `115200`.  
     - Reconnect the ESP32 USB cable.  

5. **Data Not Visible in Azure IoT Hub**  
   - **Cause**: Device not registered or firewall restrictions.  
   - **Fix**:  
     - Re-register the device in Azure IoT Hub.  
     - Allow outbound traffic on port `8883` (MQTT over TLS).  
