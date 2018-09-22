//เริ่มต้นของคำสั่ง
void setup()
{
    //เลือก Mode ของขา ในที่นี้เลือกขา D2 
    pinMode(D2, OUTPUT);
}

//ฟังก์ชั่นการทำงานซ้ำ
void loop()
{
    digitalWrite(D2, 1);
    delay(1000);
    digitalWrite(D2, 0);
    delay(1000);
}
