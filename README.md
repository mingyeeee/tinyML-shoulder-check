# TinyML Shoulder Check
Low power rear view camera system for cycling to perform people detection using Tensorflow Lite for Microcontrollers. Alerts cyclist if some on a bike or not is approaching them.

**Still a work in progress**

## Setup
Currently using model from Tensorflow lite for micros [repo](https://github.com/tensorflow/tensorflow/tree/master/tensorflow/lite/micro/examples/person_detection/arduino).
Planning on training a model to include cars and bikes

## Hardware Setup
* Arducam mini 2MP plus 
* Teensy 4.0
* Potentiometer

Arducam Pins | Teensy Pin
------------ | -------------
CS | 7
MOSI | 11
MISO | 12
SCK | 13
GND | GND
VCC | 3.3V
SDA | 18
SCL | 19

Other Components | Teensy Pin
------------ | -------------
LED (person detected) | 2
potentiometer (lighting mode selector) | 0
