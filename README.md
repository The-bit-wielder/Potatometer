
*A neurodivergent communication device that quantifies brain function in potato units*

![Potatometer 3000](https://img.shields.io/badge/Potato-Level%20Fried-yellow) 
![License: MIT](https://img.shields.io/badge/License-MIT-potato.svg)
![ESP32](https://img.shields.io/badge/ESP32-Potato%20Ready-green)

## What Even Is This?

The Potatometer is a device that helps ADHD/ASD folks communicate their current cognitive state using the universal language of potatoes. 

Instead of struggling to articulate "my executive function has completely evaporated," you can just hold a button and get an objective potato rating:

| Potato State | Hold Time | What It Means |
|--------------|-----------|---------------|
| 🥔 RAW       | 0-800ms   | Still functional, crisp |
| 🍲 BOILED    | 800-1600ms| A bit soft around the edges |
| 🔥 BAKED     | 1600-2400ms| Getting warm and toasty |
| 🍳 FRIED     | 2400-3200ms| Sizzling, crispy edges |
| 🥣 MASHED    | 3200-4000ms| Completely blended, no chunks |
| 💀 CHARRED   | 4000ms+   | Burnt out, send help |

## Hardware Requirements

- ESP32 Dev Board
- SSD1306 OLED Display (128x32)
- Momentary Push Button
- Breadboard & Wires
- (Optional) Buzzer for emergency alerts

## Wiring Diagram

| Component | ESP32 Pin | Description |
|-----------|-----------|-------------|
| OLED SDA | GPIO 21 | Serial Data Line |
| OLED SCL | GPIO 22 | Serial Clock Line |
| Button | GPIO 33 | Momentary Push Button |
| OLED VCC | 3.3V | Power Supply |
| OLED GND | GND | Ground |
| Button VCC | 3.3V | Power Supply |
| Button GND | GND | Ground |

## How It Works

1. Press and hold the button to start measuring
2. The OLED displays a progress bar showing your current "potato state"
3. Release the button to see your final potato classification
4. The device calculates how long you held the button and converts it to a potato state:
   - 0-800ms: 🥔 RAW (Still functional, crisp)
   - 800-1600ms: 🍲 BOILED (A bit soft around the edges)
   - 1600-2400ms: 🔥 BAKED (Getting warm and toasty)
   - 2400-3200ms: 🍳 FRIED (Sizzling, crispy edges)
   - 3200-4000ms: 🥣 MASHED (Completely blended, no chunks)
   - 4000ms+: 💀 CHARRED (Burnt out, send help)

## Installation

1. Install the required libraries:
   - Adafruit SSD1306
   - Adafruit GFX Library
   - Wire Library (usually included with Arduino IDE)

2. Upload the `Potato_Meter.ino` file to your ESP32

3. Wire up the components according to the diagram above

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

##PS:Yes the readme was made with AI... no i couldnt focus enough to write it myself ... deal with it ... also potato status: MASHED
