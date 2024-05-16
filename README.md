# Circuit-Breaker
Sure, here's the modified README for using Blynk Web Dashboard:

---

# Circuit Breaker with Blynk Web Dashboard

This project implements a circuit breaker using an ESP8266 (NodeMCU) microcontroller and Blynk IoT platform. The circuit breaker automatically trips when the current exceeds a certain threshold and can be controlled remotely using the Blynk Web Dashboard.

## Features

- Automatically trips the circuit when the current exceeds a threshold
- Remote control via the Blynk Web Dashboard
- Buzzer for audible alerts
- Serial monitoring for debugging

## Components Used

- ESP8266 (NodeMCU)
- Current sensor
- Relay
- Buzzer
- Resistors and connecting wires

## Dependencies

- [Blynk](https://github.com/blynkkk/blynk-library) - Blynk IoT platform library for ESP8266
- [ESP8266WiFi](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi) - ESP8266 WiFi library

## Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/your_username/circuit-breaker.git
    ```

2. Install the necessary libraries using the Arduino Library Manager.

3. Open the `circuit_breaker.ino` file in the Arduino IDE.

4. Configure your Blynk authentication token and Wi-Fi credentials in the code.

5. Upload the code to your ESP8266 board.

## Usage

1. Open the [Blynk Web Dashboard](https://blynk.io/dashboard/web) in your web browser.

2. Create a new project and obtain the project token.

3. Add two switch widgets to control the circuit breaker and reset button.

4. Monitor the circuit breaker status and sensor values in the Blynk Web Dashboard.

5. Use the switch widgets to control the circuit breaker remotely.

## Circuit Diagram

![Circuit Diagram](circuit_diagram.png)

## Acknowledgements

- [Blynk IoT Platform](https://blynk.io/)
- [ESP8266WiFi Library](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi)
