/*
 * Modified by: Mingye Chen
 * Date: 2021-05-31
 * Copyright 2019 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "detection_responder.h"

#include "Arduino.h"

// Flash the blue LED after each inference
void RespondToDetection(tflite::ErrorReporter* error_reporter,
                        int8_t person_score, int8_t no_person_score) {
  static bool is_initialized = false;
  if (!is_initialized) {
    // Pins for the built-in RGB LEDs on the Arduino Nano 33 BLE Sense
    pinMode(2, OUTPUT);
    postivityCount = 0;
    is_initialized = true;
  }

  // Note: The RGB LEDs on the Arduino Nano 33 BLE
  // Sense are on when the pin is LOW, off when HIGH.

  // Switch the person LED off
  digitalWrite(2, LOW);

  // Switch on the green LED when a person is detected,
  // the red when no person is detected
  if (person_score > no_person_score) {
    TF_LITE_REPORT_ERROR(error_reporter, "Person detected!");
    postivityCount ++;
  } else {
    digitalWrite(2, LOW);
    TF_LITE_REPORT_ERROR(error_reporter, "NO ONE detected!");
    postivityCount = 0;
  }
  // Check how many consecutive times a person was detected
  if (postivityCount > 5){
    digitalWrite(2, HIGH);
  }
  TF_LITE_REPORT_ERROR(error_reporter, "Person score: %d No person score: %d",
                       person_score, no_person_score);
}
