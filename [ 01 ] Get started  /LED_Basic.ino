//เริ่มต้นของคำสั่ง
void setup()
{
    //เลือก Mode ของขา ในที่นี้เลือกขา D2
    pinMode(D2, OUTPUT);
}

//ฟังก์ชั่นการทำงานซ้ำ
void loop()
{
    //เลือกแบบ Digital คือการส่งขา 1 คือเปิด 0 คือปิด
    digitalWrite(D2, 1);
    //หน่วงเวลา หน่วยเป็น Millisecond มิลลิวินาที
    delay(1000);
    //เลือกแบบ Digital คือการส่งขา 1 คือเปิด 0 คือปิด
    digitalWrite(D2, 0);
    delay(1000);
}
