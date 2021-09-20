// C++ code
//DISPLAY TEMPERATURE ON LCD
#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int celsius = 0;
int fahrenheit = 0;

void setup()
{
  pinMode(A0,INPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop()
{
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  fahrenheit = ((celsius * 9) / 5 + 32);
 
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(celsius);
    lcd.print(" C, ");
    lcd.setCursor(0,1);
    lcd.print(fahrenheit);
    lcd.println(" F");
    delay(1000);
 
  }