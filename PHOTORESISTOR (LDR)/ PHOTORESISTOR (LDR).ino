// C++ code
// INTERFACE PHOTORESISTOR WITH LED
const int led=6,LDR=A0;
void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int value = analogRead(A0);
  Serial.println(value);
  if(value>750)
  {
    digitalWrite(led,HIGH);
  }
  else
    {
    digitalWrite(led,LOW);
  }
}