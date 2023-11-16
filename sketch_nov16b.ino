//includes master loop & serial prints

#include <DHT.h>

#define DHTPIN 2  // DHT22 data pin connected to pin 2
#define DHTTYPE DHT22  // DHT22 sensor type

#define RELAY_PIN 7  // Relay control pin connected to pin 7

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
  float humidity = dht.readHumidity();

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  if (humidity < 40.0) {
    // Humidity is below 40%, turn on the relay
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("Turning ON power outlet");
  } else if (humidity > 60.0) {
    // Humidity is above 60%, turn off the relay
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("Turning OFF power outlet");
  }

  delay(5000);  // Delay for 5 seconds before reading the sensor again
}
