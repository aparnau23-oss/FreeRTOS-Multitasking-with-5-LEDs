# ESP32-FreeRTOS-Multitasking-with-5-LEDs
This project demonstrates multitasking on the ESP32 using FreeRTOS. Five independent tasks control five LEDs, each blinking at a different interval.

## GPIO Connections

| LED | GPIO |
|------|------|
| Red | GPIO5 |
| Yellow | GPIO4 |
| Green | GPIO2 |
| White | GPIO21 |
| Blue | GPIO22 |

## Blink Intervals

- 🔴 Red – 5 seconds
- 🟡 Yellow – 4 seconds
- 🟢 Green – 3 seconds
- ⚪ White – 2 seconds
- 🔵 Blue – 1 second

## Features

- FreeRTOS multitasking
- Independent LED control
- ESP-IDF based project
- Compatible with Wokwi simulation
