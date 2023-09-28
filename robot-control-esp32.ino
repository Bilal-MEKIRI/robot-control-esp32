#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>


// Network credentials
const char* ssid     = "SFR_6C60";      // Your network SSID (name of the Wi-Fi network)
const char* password = "iumnitimiteheri3ongi";  // Your network password

void setup() {
  Serial.begin(115200);               // Start the serial communication for debugging
  pinMode(2, OUTPUT);                 // Set GPIO2 as an output for LED control
  
  // Connect to the WiFi network
  WiFi.begin(ssid, password);

  // Wait until the ESP32 is successfully connected to the Wi-Fi network
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  // Once connected, print out the connection details
  Serial.println("Connected to WiFi");
  Serial.print("ESP32 IP address: ");
  Serial.println(WiFi.localIP()); 
}

void loop() {
  Serial.println("We accessed the loop function..."); 
  
  // Check if ESP32 is connected to the WiFi
  if (WiFi.status() == WL_CONNECTED) {
    
    HTTPClient http;  // Create a HTTPClient object to make HTTP requests

    // Begin a connection to the specified URL
    http.begin("https://robot-project.onrender.com/getLedState");
    
    // Send an HTTP GET request
    int httpCode = http.GET();
    
    // Print the HTTP response code (should be 200 for OK)
    Serial.print("HTTP Response code: ");
    Serial.println(httpCode);
    Serial.println(http.errorToString(httpCode));

    // Check if HTTP request was successful
    if (httpCode > 0) {
      Serial.println("Fetching led state...");  
      
      // Get the response payload from the server
      String payload = http.getString();
      Serial.println(payload);

      // Create a JSON document to store the parsed data
      DynamicJsonDocument doc(256);
      
      // Try to parse the JSON data from the response
      DeserializationError error = deserializeJson(doc, payload);

      // If parsing was successful, read the LED state and control the LED
      if (!error) {
        const char* ledState = doc["ledState"];  // Extract LED state from parsed JSON
        
        // Compare ledState value and turn on/off the LED accordingly
        if (strcmp(ledState, "ON") == 0) {
          digitalWrite(2, HIGH);  // Turn ON the LED
        } else if (strcmp(ledState, "OFF") == 0) {
          digitalWrite(2, LOW);   // Turn OFF the LED
        }
      } else {
        // If there was an error in parsing, print an error message
        Serial.println("Failed to parse JSON!");
      }
    }

    http.end();  // Close the HTTP connection
  }

  delay(100);  // Wait for 0.1 seconds before next loop iteration
}
