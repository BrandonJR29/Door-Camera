# Door-Camera
ESP32-CAM door camera.

## Requirements

* esp-idf version 4.2.
* esp-camera inside of esp-idf/components, you can download it from Espressif Repositories.
* ESP32-CAM module.
* uSD of 8GB.
* Push button and a Resistor(1.3k is Ok).

## Installation

* Download this Repo.
* Connect the resistor between GPIO3 and Vcc.
* Connect the push button between GPIO3 and GND.
* make flash, if you can't flash, remember to disconnect the uSD and push reset button(not holding).
* Disconnect Rx0 Pin(GPIO3) and connect a cable in the resistor and push button node to GPIO3.
* Reset ESP32.
* Start taking pictures.

## Proccess

* Camera and uSd configuration.
* Take a picture if the push button is pressed.
* Save the picture in the uSD.
* Pictures' name begins from "pic1.jpg".

## To Do

- [x] Take a picture.
- [x] Save in uSD.
- [ ] Watch in web server.
- [ ] Video streaming after the picture was taken.

## Warnings

* The ESP32 lost RX pin for UART0.
* Don't use GPIO16.
