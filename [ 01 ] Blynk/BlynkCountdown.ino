// Import library WiFi
#include <WiFiClientSecure.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

//Blynk
#define BLYNK_PRINT Serial

//Setting  Auth Blynk
char auth[] = "";

int PumNum = D5;
int DataFormApp;

//Setting timmer
int TimeCountDown = 1200;

//Read parameter form App blynk

BLYNK_WRITE(V1) // Set Pin
{
  DataFormApp = param.asInt();
}

void setup() {

  Serial.begin(115200);
  Blynk.begin(auth, "BS@_COM", "");
  pinMode(PumNum, OUTPUT);


}

void loop() {


  //Check Event form app blynk
  if (DataFormApp == 1) {

    if (TimeCountDown != 0) {
      digitalWrite(PumNum, HIGH);
      delay(1000);
      Count_time(1);

      Blynk.virtualWrite(V3, TimeCountDown);

      if (TimeCountDown == 0) {
        digitalWrite(PumNum, LOW);
        Blynk.virtualWrite(V1, 0);
        DataFormApp = 0;

        //Setting timmer defulut;
        TimeCountDown = 1200;
        Blynk.virtualWrite(V3, TimeCountDown);
      }
    }


  } else if (DataFormApp == 0) {
    digitalWrite(PumNum, LOW);
    Serial.print(DataFormApp);

    //Setting timmer defulut;
    TimeCountDown = 1200;


    Blynk.virtualWrite(V3, TimeCountDown);
    Count_time(0);

  }
  Blynk.run();
  delay(1000);

}


//Countdown Timmer

void Count_time(int Status) {
  while (Status != 0) {
    TimeCountDown--;
    delay(1000);
    Blynk.virtualWrite(V3, TimeCountDown);

    Status = 0;
    if (TimeCountDown == 0) {
      Status = 0;
    }
    if (DataFormApp == 0) {
      Status = 0;
    }
  }
}

//--------------------




