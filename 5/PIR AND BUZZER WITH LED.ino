// C++ code
//INTERFACING PIR AND BUZZER WITH LED
const int PIR = 6, LED=3, Buzzer=5;
void setup()
{
pinMode(PIR, INPUT);
pinMode(Buzzer, OUTPUT);
pinMode(LED, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  int value=digitalRead(PIR);
  if(value==1)
{
  
  tone(Buzzer,500,2000);
  digitalWrite(LED,HIGH);
  delay(2000);
  
  Serial.println("Motion Detected");
}
else
{
  
  noTone(Buzzer);
  digitalWrite(LED,LOW);
  Serial.println("Motion not Detected");
}
}


