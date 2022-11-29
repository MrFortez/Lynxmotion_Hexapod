#include <Wire.h>

#include <PS4BT.h>
#include <usbhub.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

USB Usb;
BTD Btd(&Usb); 

PS4BT PS4(&Btd, PAIR);

static byte LY = 127;
static byte LX = 127;
static byte RY = 127;
static byte RX = 127;

void setup() {
  pinMode(7,OUTPUT);
  digitalWrite(7,HIGH);
  Serial.begin(9600);
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); // Halt
  }
  Serial.print(F("\r\nPS4 Bluetooth Library Started"));

  Wire.begin();
}

void loop() {
  Wire.beginTransmission(8);
  Usb.Task();
  readInput();
  Wire.endTransmission();
  delay(10);
}

void readInput() {
  if (PS4.getButtonClick(PS)) {
    Wire.write("Start");
  }
  else if (PS4.getButtonClick(L1)) {
    Wire.write("L1");
  }
  //this one is intended to not be the same, I dont want to deal with analog values. Also this just makes more sense
  else if (PS4.getButtonClick(R1)) {
    Wire.write("L2");
  }
  else if (PS4.getButtonClick(TRIANGLE)) {
    Wire.write("Triangle");
  }
  else if (PS4.getButtonClick(CIRCLE)) {
    Wire.write("Circle");
  }
  else if (PS4.getButtonClick(SQUARE)) {
    Wire.write("Square");
  }
  else if (PS4.getButtonClick(OPTIONS)) {
    Wire.write("Select");
  }
  else {
    Wire.write("");
  }

  LX = PS4.getAnalogHat(LeftHatX);
  Serial.print(LX);
  LY = PS4.getAnalogHat(LeftHatY);
  Serial.print(LY);
  RX = PS4.getAnalogHat(RightHatX);
  Serial.print(RX);
  RY = PS4.getAnalogHat(RightHatY);
  Serial.print(RY);
  Wire.write(LX);
  Wire.write(LY);
  Wire.write(RX);
  Wire.write(RY);
}
