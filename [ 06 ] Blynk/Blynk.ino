#include <WiFiClientSecure.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>



const int pingPinTrig = D6;
int inPinEcho = D7;

int lineStatus = 0;

int PumNum = D5;
int DataFormApp;

int TimeCountDown = 1200;

//Blynk
#define BLYNK_PRINT Serial

//Line Token
String TokenLine = "";



char auth[] = "";
BLYNK_WRITE(V1) //Button Widget is writing to pin V1
{
  DataFormApp = param.asInt();
}

void setup() {

  Serial.begin(115200);
  Blynk.begin(auth, "BS@_COM", "");
  pinMode(PumNum, OUTPUT);


}






void loop() {

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
        TimeCountDown = 1200;
        Blynk.virtualWrite(V3, TimeCountDown);
      }
    }


  } else if (DataFormApp == 0) {
    digitalWrite(PumNum, LOW);
    Serial.print(DataFormApp);
    TimeCountDown = 1200;
    Blynk.virtualWrite(V3, TimeCountDown);
    Count_time(0);

  }







  long duration, cm;

  pinMode(pingPinTrig, OUTPUT);
  digitalWrite(pingPinTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPinTrig, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPinTrig, LOW);
  pinMode(inPinEcho, INPUT);

  duration = pulseIn(inPinEcho, HIGH);

  cm = duration / 29 / 2;

  //Serial.println(cm);
  Blynk.virtualWrite(10, cm);


  if (cm >= 250) {
    //Line_Notify(TokenLine, "%E0%B8%99%E0%B9%89%E0%B8%B3%E0%B9%83%E0%B8%99%E0%B9%81%E0%B8%97%E0%B8%87%E0%B8%84%E0%B9%8C%E0%B9%84%E0%B8%A1%E0%B9%88%E0%B8%A1%E0%B8%B5%E0%B9%81%E0%B8%A5%E0%B9%89%E0%B8%A7%E0%B9%80%E0%B8%94%E0%B9%89%E0%B8%AD%E0%B8%99%E0%B9%89%E0%B8%B3%E0%B9%83%E0%B8%99%E0%B9%81%E0%B8%97%E0%B8%87%E0%B8%84%E0%B9%8C%E0%B9%84%E0%B8%A1%E0%B9%88%E0%B8%A1%E0%B8%B5%E0%B9%81%E0%B8%A5%E0%B9%89%E0%B8%A7%E0%B9%80%E0%B8%94%E0%B9%89%E0%B8%AD");
    //lineStatus = 1;
    // SetLineStatus(1);
  } else if (cm >= 200) {
    // Line_Notify(TokenLine, "%E0%B8%99%E0%B9%89%E0%B8%B3%E0%B9%83%E0%B8%99%E0%B9%81%E0%B8%97%E0%B8%87%E0%B8%84%E0%B9%8C%E0%B9%83%E0%B8%81%E0%B8%A5%E0%B9%89%E0%B8%88%E0%B8%B0%E0%B8%AB%E0%B8%A1%E0%B8%94%E0%B9%81%E0%B8%A5%E0%B9%89%E0%B8%A7%20%E0%B8%87%E0%B8%94%E0%B8%81%E0%B8%B2%E0%B8%A3%E0%B9%83%E0%B8%8A%E0%B9%89%E0%B8%99%E0%B9%89%E0%B8%B3%E0%B8%97%E0%B8%B5%E0%B9%88%E0%B9%84%E0%B8%A1%E0%B9%88%E0%B8%88%E0%B8%B3%E0%B9%80%E0%B8%9B%E0%B9%87%E0%B8%99%E0%B8%84%E0%B8%A3%E0%B8%B1%E0%B8%9A%E0%B8%99%E0%B9%89%E0%B8%B3%E0%B9%83%E0%B8%99%E0%B9%81%E0%B8%97%E0%B8%87%E0%B8%84%E0%B9%8C%E0%B9%83%E0%B8%81%E0%B8%A5%E0%B9%89%E0%B8%88%E0%B8%B0%E0%B8%AB%E0%B8%A1%E0%B8%94%E0%B9%81%E0%B8%A5%E0%B9%89%E0%B8%A7%20%E0%B8%87%E0%B8%94%E0%B8%81%E0%B8%B2%E0%B8%A3%E0%B9%83%E0%B8%8A%E0%B9%89%E0%B8%99%E0%B9%89%E0%B8%B3%E0%B8%97%E0%B8%B5%E0%B9%88%E0%B9%84%E0%B8%A1%E0%B9%88%E0%B8%88%E0%B8%B3%E0%B9%80%E0%B8%9B%E0%B9%87%E0%B8%99%E0%B8%84%E0%B8%A3%E0%B8%B1%E0%B8%9A");
    //lineStatus = 1;
    // SetLineStatus(1);
  } else if (cm >= 175) {
    // Line_Notify(TokenLine, "%E0%B8%99%E0%B9%89%E0%B8%B3%E0%B9%80%E0%B8%AB%E0%B8%A5%E0%B8%B7%E0%B8%AD%E0%B8%84%E0%B8%A3%E0%B8%B6%E0%B9%88%E0%B8%87%E0%B9%81%E0%B8%97%E0%B8%87%E0%B8%84%E0%B9%8C%E0%B9%81%E0%B8%A5%E0%B9%89%E0%B8%A7%E0%B8%99%E0%B8%B0%E0%B8%84%E0%B8%A3%E0%B8%B1%E0%B8%9A%E0%B8%99%E0%B9%89%E0%B8%B3%E0%B9%80%E0%B8%AB%E0%B8%A5%E0%B8%B7%E0%B8%AD%E0%B8%84%E0%B8%A3%E0%B8%B6%E0%B9%88%E0%B8%87%E0%B9%81%E0%B8%97%E0%B8%87%E0%B8%84%E0%B9%8C%E0%B9%81%E0%B8%A5%E0%B9%89%E0%B8%A7%E0%B8%99%E0%B8%B0%E0%B8%84%E0%B8%A3%E0%B8%B1%E0%B8%9A");
    // lineStatus = 1;
    // SetLineStatus(1);
  } else {

  }
  Blynk.run();


  delay(1000);






}

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




void Line_Notify(String LINE_Token, String message) {
  String msg = String("message=") + message;

  WiFiClientSecure client;
  if (!client.connect("notify-api.line.me", 443)) {
    Serial.println("connection failed");
    return;
  }

  String req = "";
  req += "POST /api/notify HTTP/1.1\r\n";
  req += "Host: notify-api.line.me\r\n";
  req += "Content-Type: application/x-www-form-urlencoded\r\n";
  req += "Authorization: Bearer " + String(LINE_Token) + "\r\n";
  req += "Content-Length: " + String(msg.length()) + "\r\n";
  req += "\r\n";
  req +=  msg;

  client.print(req);

  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }

  // Read all the lines of the reply from server and print them to Serial
  while (client.available()) {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

  Serial.println();
  Serial.println("closing connection");

}

/*
  void SetLineStatus(int status_input) {
  if (status_input == 1) {
    delay(1800000);
    lineStatus = 0;

  } else {

  }
*/


