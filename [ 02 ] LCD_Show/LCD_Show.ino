#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C Mornitor(0x3f,16,2);

void setup() {

  Mornitor.begin();
  Mornitor.backlight();
  Mornitor.setCursor(0, 0); // ไปที่ตัวอักษรที่ 4 บรรทัดที่ 0
  Mornitor.print("Hello Bank");
  Mornitor.setCursor(0, 1); // ไปที่ตัวอักษรที่ 0 บรรทัดที่ 1
  Mornitor.print("Welcome to Node MCU");

}

void loop() {
  // put your main code here, to run repeatedly:

}
