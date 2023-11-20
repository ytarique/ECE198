#define RELAY_PIN D2  // Define the pin where your relay is connected

void setup() {
 Serial.begin(115200); // Start serial communication
 pinMode(RELAY_PIN, OUTPUT); // Set relay pin as OUTPUT
}

void loop() {
 if (Serial.available() > 0) {
   char command = Serial.read();

   // Check the user input and control the relay accordingly
   if (command == '1') {
     digitalWrite(RELAY_PIN, HIGH); // Turn on the relay
     Serial.println("Relay ON");
   } else if (command == '0') {
     digitalWrite(RELAY_PIN, LOW); // Turn off the relay
     Serial.println("Relay OFF");
   }
 }
}