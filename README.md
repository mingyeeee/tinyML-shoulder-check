# TinyML Shoulder Check
Frequent shoulder checks for other cyclists or people while cycling can be dangerous as your attention is diverted away from oncoming traffic or obstacles. TinyML Should Check is a low power rear view camera system that performs people detection using Tensorflow Lite for Microcontrollers. This device alerts the cyclist if there is another cyclist or person behind them by flashing an LED on the handlebars.

**Still a work in progress**

## Software Setup
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
Potentiometer (lighting mode selector) | A0
