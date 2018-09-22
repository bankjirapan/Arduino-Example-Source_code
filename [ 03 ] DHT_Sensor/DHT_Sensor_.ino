//Mornitor LCD
#include <Wire.h>
#include <LiquidCrystal_I2C.h>



//DHT Sensor
#include "DHT.h"
#define DHTPIN D6     // what digital pin we're connected to
#define DHTTYPE DHT11   // DHT 11

int led = D7;

LiquidCrystal_I2C Mornitor(0x3f, 16, 2);
DHT dht(DHTPIN, DHTTYPE);



void setup() {
  pinMode(led,OUTPUT);
  analogWrite(led,100);
  Serial.begin(115200);
  Serial.println("DHTxx test!");
  dht.begin();

}

void loop() {
  // หน่วงเวลา 2 วินาทีให้เซนเซอร์ทำงาน
  delay(6000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  // เช็คถ้าอ่านค่าไม่สำเร็จให้เริ่มอ่านใหม่
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    Mornitor.begin();
    Mornitor.backlight();
    Mornitor.setCursor(0, 0);
    Mornitor.print("Error Sensor !");
    return;
  } else {

    Mornitor.begin();
    Mornitor.backlight();
    Mornitor.setCursor(0, 0);
    Mornitor.print("Humidity :");
    Mornitor.print(h);
    Mornitor.print("");
    Mornitor.print("%");
    Mornitor.setCursor(1, 1);
    Mornitor.print(t);
    Mornitor.print("");
    Mornitor.print("*C");
    Mornitor.print(" ");
    Mornitor.print(f);
    Mornitor.print("*F");

   
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t\n");

   

}
