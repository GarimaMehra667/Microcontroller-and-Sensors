// C++ code
//
#include <Servo.h>;
Servo myservo;
int pinP=A2;
int val;
void setup()
{
  Serial.begin(9600);
  myservo.attach(9);
  pinMode(pinP,INPUT);
}

void loop()
{
  val=analogRead(pinP);
  Serial.print("Analog Value");
  Serial.print(val);
  Serial.print("\n");
  val=map(val,0,1023,0,180);
  Serial.print("Mapped Value");
  Serial.print(val);
  Serial.print("\n\n");
  myservo.write(val);
  delay(1000);
 }