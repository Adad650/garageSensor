# Arduino Parking Assistant

An Arduino-based parking assistant that uses an ultrasonic sensor to measure your car's distance from a wall or obstacle. Based on the measured distance, it lights up one of three LEDs (green, yellow, red) to help you park safely and accurately.

---

## Features

- **Ultrasonic distance measurement** using HC-SR04 sensor
- **Three-level LED indication**:
    - **Green LED:** Safe distance
    - **Yellow LED:** Getting close
    - **Red LED:** Stop!
- **Automatic timeout:** LEDs turn off after 30 seconds of inactivity

---

## Installation Instructions

### 1. Install Arduino IDE

- Download the [Arduino IDE](https://www.arduino.cc/en/software) for your operating system.
- Follow the installation instructions for Windows, macOS, or Linux.
- Connect your Arduino board to your computer via USB.

### 2. Set Up the Project

- Clone or download this repository.
- Open `main.cpp` in the Arduino IDE.
- Select your Arduino board and port from the **Tools** menu.
- Click **Upload** to flash the code to your Arduino.

---

## Hardware Required

- 1 × Arduino Uno (or compatible)
- 1 × HC-SR04 Ultrasonic Sensor
- 3 × LEDs (Red, Yellow, Green)
- 3 × 220Ω resistors
- Jumper wires
- Breadboard

---

## Schematic Diagram

Below is a schematic diagram showing how to wire the components:

```
[HC-SR04]      [Arduino UNO]
VCC    ------> 5V
GND    ------> GND
TRIG   ------> Pin 9
ECHO   ------> Pin 10

[LEDs]
Green  ------> Pin 2 (with 220Ω resistor to GND)
Yellow ------> Pin 3 (with 220Ω resistor to GND)
Red    ------> Pin 4 (with 220Ω resistor to GND)
```

---

## Distance Calculation

The HC-SR04 ultrasonic sensor measures distance by sending out an ultrasonic pulse and timing how long it takes to receive the echo. The distance is calculated using the formula:

```
distance in cm = duration * 0.034(The speed of sound) / 2 
```

- duration is the time of pulse
- 0.034 isnt the speed of sound, The speed of sound is 343 m/s but we want the distance in cm to I lowered the decimal places
- Divide by 2 Because we only want one way time.
- The sensor emits a pulse via the TRIG pin.
- The ECHO pin goes HIGH for the duration it takes the pulse to travel to the object and back.


---

## Example Images

Parking Assistant in Action:

> **Note:** If the images below do not display on GitHub, Download the images to your computer then view.

| Parking Assistant in Action |
|:---------------------------:|

![Whatever you want](Images/IMG_1051.jpg)
![Whatever you want](Images/IMG_1052.jpg)
![Whatever you want](Images/IMG_1053.jpg)
![Whatever you want](Images/IMG_1054.jpg)
![Whatever you want](Images/IMG_1055.jpg)

---

## Usage

- As you approach the sensor, the LEDs indicate your distance:
    - **Green:** Far (safe)
    - **Yellow:** Getting close
    - **Red:** Very close (stop)
- If the distance category changes, the corresponding LED lights up.
- If no change is detected for 30 seconds, all LEDs turn off automatically.

---

## License

This project is open source and available under the MIT License.

For questions or contributions, please open an issue or pull request!
