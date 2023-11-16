//only serial printing of humidity levels

#include <DHT.h>

#define DHTPIN 2  // DHT22 data pin connected to pin 2
#define DHTTYPE DHT22  // DHT22 sensor type

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
}

void loop() {
  float humidity = dht.readHumidity();

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  delay(5000);  // Delay for 5 seconds before reading the sensor again
}
