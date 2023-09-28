# 🤖 ESP32 Robot LED Controller 🌟

Welcome to the ESP32 Robot LED Controller component! This segment is crucial for facilitating communication between our Robot LED Control Server and the robot's onboard LED. 

## 📖 What does this component do? 🤷‍♂️

This ESP32-based code is designed to:
1. Connect the ESP32 device to your Wi-Fi network.
2. Continuously poll the Robot LED Control Server to fetch the desired LED state.
3. Control the robot's onboard LED based on the fetched state (either ON or OFF).

## 📚 Libraries and Hardware 🛠️

### Hardware:
- **ESP32**: This is the microcontroller platform we are using. It is equipped with Wi-Fi, which makes it perfect for IoT projects like this one.

### Libraries:
- **WiFi.h**: Facilitates Wi-Fi communication functionalities for the ESP32.
- **HTTPClient.h**: Provides the ability to make HTTP requests to remote servers.
- **ArduinoJson.h**: Assists in parsing JSON data from the server's response.

## 🌐 Interaction with the Server 🛣️

- The ESP32 sends an HTTP `GET` request to `https://robot-project.onrender.com/getLedState` to obtain the current LED state.
- Upon receiving the response, the ESP32 parses the JSON data to determine whether the LED should be turned ON or OFF.
- Depending on the parsed state, the LED is controlled accordingly.

## 🛠️ Setup & Upload 🏃‍♀️

1. **Environment Setup**:
   - Ensure you have the Arduino IDE installed.
   - Add the ESP32 board support through the Arduino IDE board manager.
   - Install the following libraries through Arduino IDE's Library Manager:
     - `WiFi`
     - `HTTPClient`
     - `ArduinoJson`
   
2. **Network Credentials**: Update the `ssid` and `password` variables in the code with your Wi-Fi network's SSID and password.
   
3. **Uploading the Code**: Connect the ESP32 to your machine and select the appropriate board and port from the Arduino IDE. Then, click the upload button to flash the code onto the ESP32.

## 📌 Note 📝

- Ensure the ESP32 is connected to the same network as the server for seamless communication.
- If the server's URL or endpoints are modified, ensure they are updated accordingly in the ESP32 code.
- The LED is connected to GPIO2 of the ESP32. Make sure the physical connections are in place.

## 😊 Feedback & Troubleshooting 📢

If you face any issues or have feedback, please document them or make notes. Regularly revisiting and updating documentation ensures smoother development and maintenance! 
