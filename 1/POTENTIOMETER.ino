// C++ code 
// INTERFACING POTENTIOMETER WITH LED
const int a=A0,led=6;
void setup()
{
  pinMode(led, OUTPUT);
  pinMode(a,INPUT);
}

void loop()
{
  int value = analogRead(a);
  int b= map(value,0,1023,0,255);
  analogWrite(led,b);
}