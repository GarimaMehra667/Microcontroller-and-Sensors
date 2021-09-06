// C++ code
//INTERFACING 4 LED'S
const int LED1=13;
const int LED2=11;
const int LED3=9;
const int LED4=7;
void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}
void loop()
{
  digitalWrite(LED1, HIGH);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  delay(10); 
  digitalWrite(LED2, LOW);
  delay(10);
  digitalWrite(LED3, HIGH);
  delay(100); 
  digitalWrite(LED3, LOW);
  delay(100); 
  digitalWrite(LED4, HIGH);
  delay(1000); 
  digitalWrite(LED4, LOW);
  delay(1000);
}



