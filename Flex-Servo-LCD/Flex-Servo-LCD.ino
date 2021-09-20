// C++ code
//
#include <Servo.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
Servo myServo;
const int flexPin = A0;
const int ledPin = 13;
void setup()
{
Serial.begin(9600);
analogWrite(6,50);
lcd.begin(16,2);
myServo.attach(10);
pinMode(ledPin,OUTPUT);
}
void loop()
{
int flexValue;
int servoPosition;
flexValue = analogRead(flexPin);
Serial.print("sensor: ");
Serial.println(flexValue);

servoPosition = map(flexValue, 800, 900, 0, 180);
servoPosition = constrain(servoPosition, 0, 180);

myServo.write(servoPosition);
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Flex = ");
 lcd.setCursor(8,0);
 lcd.print(flexValue);
 lcd.setCursor(0,1);
 lcd.print("Servo = ");
 lcd.setCursor(9,1);
 lcd.print(servoPosition);
  
if(flexValue>890)
digitalWrite(ledPin,HIGH);
else
digitalWrite(ledPin,LOW);

delay(100);
}