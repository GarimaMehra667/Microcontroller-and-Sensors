// C++ code 
//IF SMOKE IS DETECTED MOTOR STARTS MOVING AND VALUE IN DIISPLAYED ON LED
#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
const int gas = A0;
const int motorpin1 = 9;
const int motorpin2 = 10;

void setup()
{
  analogWrite(6,50);
  lcd.begin(16,2);
  pinMode(gas,INPUT);
  pinMode(motorpin1,OUTPUT);
  pinMode(motorpin2,OUTPUT);
}

void loop()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(analogRead(gas));
  
  if(analogRead(gas)>800){
  	digitalWrite(motorpin1,LOW);
    digitalWrite(motorpin2,HIGH);
  }
  else{
  	digitalWrite(motorpin1,LOW);
    digitalWrite(motorpin2,LOW);
  }
  delay(1000);
}