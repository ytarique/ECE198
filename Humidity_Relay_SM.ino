#include "DHT.h"  // Include the DHT library

#define DHTPIN PA0   // Define the pin where your DHT22 sensor is connected
#define RELAY_PIN PB0 // Define the pin where your relay is connected
#define DHTTYPE DHT22 // Define the type of the DHT sensor

DHT dht(DHTPIN, DHTTYPE); // Initialize the DHT sensor

void setup() {
  Serial.begin(115200); // Start serial communication
  pinMode(RELAY_PIN, OUTPUT); // Set relay pin as OUTPUT
  dht.begin(); // Initialize the DHT sensor
}

void loop() {
  delay(3000); // Wait for 3 seconds
  
  // Read the humidity level from the DHT sensor
  float humidity = dht.readHumidity();

  // Check if the read was successful
  if (!isnan(humidity)) {
    // Output the humidity level to the serial monitor
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println("%");

    // Control the relay based on humidity levels
    if (humidity < 40.0) {
      // Humidity below 40%: Turn on the relay (provide power to the outlet)
      digitalWrite(RELAY_PIN, HIGH);
      Serial.println("Relay ON");
    } else if (humidity > 60.0) {
      // Humidity above 60%: Turn off the relay (stop powering the outlet)
      digitalWrite(RELAY_PIN, LOW);
      Serial.println("Relay OFF");
    }
  } else {
    // If the read failed, print an error message
    Serial.println("Failed to read from DHT sensor!");
  }
}
