#include "DHT.h"  // Include the DHT library

#define DHTPIN PA0  // Define the pin where your DHT22 sensor is connected
#define DHTTYPE DHT22  // Define the type of the DHT sensor

DHT dht(DHTPIN, DHTTYPE);  // Initialize the DHT sensor

void setup() {
  Serial.begin(115200);  // Start serial communication
  dht.begin();  // Initialize the DHT sensor
}

void loop() {
  delay(3000);  // Wait for 3 seconds
  
  // Read the humidity level from the DHT sensor
  float humidity = dht.readHumidity();

  // Check if the read was successful
  if (!isnan(humidity)) {
    // Output the humidity level to the serial monitor
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println("%");
  } else {
    // If the read failed, print an error message
    Serial.println("Failed to read from DHT sensor!");
  }
}
