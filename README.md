# Door-Camera
ESP32-CAM door camera.

## Requirements

* esp-idf version 4.2.
* esp-camera inside of esp-idf/components
* ESP32-CAM.
* uSD of 8GB.
* Push button and Resistor.

## Installation

* Download this Repo.
* Connect a resistor between GPIO3 and Vcc.
* Connect a push button between GPIO3 and GND.
* make flash.

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
