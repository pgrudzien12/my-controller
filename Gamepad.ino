// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output


const int SW_pin_th = 3; // digital pin connected to switch output
const int Y_pin_th = 3; // analog pin connected to X output
const int X_pin_th = 2; // analog pin connected to Y output


const int SW_pin_right_point = 4; // digital pin connected to switch output
const int SW_pin_left_point = 5; // digital pin connected to switch output

#include "HID-Project.h"

void setup() {
  pinMode(SW_pin, INPUT);
  pinMode(SW_pin_th, INPUT);
  pinMode(SW_pin_right_point, INPUT);
  pinMode(SW_pin_left_point, INPUT);
  digitalWrite(SW_pin, HIGH);
  digitalWrite(SW_pin_th, HIGH);
  
  Gamepad.begin();
  Serial.begin(115200);
}

void loop() {

  int rightPointSw = digitalRead(SW_pin_right_point);
  int leftPointSw = digitalRead(SW_pin_left_point);
  
  int rightSdw = digitalRead(SW_pin);
  int rightX = analogRead(X_pin);
  int rightY = analogRead(Y_pin);
  
  int leftSdw = digitalRead(SW_pin_th);
  int leftX = analogRead(X_pin_th);
  int leftY = analogRead(Y_pin_th);

  // Move x/y Axis to a new position (16bit)
  Gamepad.xAxis(rightX * 8);
  Gamepad.yAxis(rightY * 8);
  if (rightSdw == 0)
    Gamepad.press(1);
  else
    Gamepad.release(1);


  Gamepad.rxAxis(leftX * 8);
  Gamepad.ryAxis(leftY * 8);
  if (leftSdw == 0)
    Gamepad.press(2);
  else
    Gamepad.release(2);

    
  if (rightPointSw == 1)
    Gamepad.press(3);
  else
    Gamepad.release(3);
    
  if (leftPointSw == 1)
    Gamepad.press(4);
  else
    Gamepad.release(4);
  

  // Functions above only set the values.
  // This writes the report to the host.
  Gamepad.write();
  delay(10);
}
