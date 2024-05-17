#define BLYNK_TEMPLATE_ID "TMPL3TTcwgONG"
#define BLYNK_TEMPLATE_NAME "Circuit Breaker"
#define BLYNK_AUTH_TOKEN "csH9jeir1kps8kyYgSwHwDMhvhSzLjDO"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

const int relayPin = D7;        // Pin connected to the relay
const int buzzerPin = D0;       // Pin connected to the buzzer
const int currentSensorPin = A0;// Analog input pin for current sensor

#define RELAY_VIRTUAL_PIN V1
#define RESET_VIRTUAL_PIN V0

bool isCircuitBreakerOn = false; // Variable to store circuit breaker state

void setup() {
  Serial.begin(115200);               // Initialize serial communication
  Serial.println("Initializing...");

  pinMode(relayPin, OUTPUT);          // Set relayPin as output
  pinMode(buzzerPin, OUTPUT);         // Set buzzerPin as output
  digitalWrite(relayPin, LOW);        // Turn off relay initially

  // Connect to Wi-Fi and Blynk server
  Serial.print("Connecting to Wi-Fi");
  WiFi.begin("OPPO Reno8 5G", "V5gghewx");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  Blynk.begin(BLYNK_AUTH_TOKEN, "OPPO Reno8 5G", "V5gghewx");
  Serial.println("Blynk connected");

  // Register callback for virtual pins
  Blynk.syncVirtual(RELAY_VIRTUAL_PIN); // Request current relay state from server
}

void loop() {
  Blynk.run();

  int sensorValue = analogRead(currentSensorPin); // Read analog value from current sensor pin

  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  // Check if sensor value is greater than 535
  if (sensorValue > 540 && Blynk.connected()) {
    // Activate theircuit breaker
    Serial.println("Circuit breaker activated");
    isCircuitBreakerOn = true;
    digitalWrite(relayPin, HIGH); // Turn off relay
    digitalWrite(buzzerPin, LOW); // Turn on buzzer
    Blynk.virtualWrite(RESET_VIRTUAL_PIN, LOW); // Turn off reset button
  } else {
    // Deactivate the circuit breaker
    Serial.println("Circuit breaker deactivated");
    isCircuitBreakerOn = false;
    digitalWrite(relayPin, LOW);  // Turn on relay
    digitalWrite(buzzerPin, HIGH); // Turn off buzzer
    Blynk.virtualWrite(RESET_VIRTUAL_PIN, HIGH); // Turn on reset button
  }
  
  delay(1000); // Wait for 1 second before reading again
}

// Blynk virtual pin write callback
BLYNK_WRITE(RELAY_VIRTUAL_PIN) {
  int relayState = param.asInt();
  if (!isCircuitBreakerOn) {
    digitalWrite(relayPin, relayState);
  }
}
