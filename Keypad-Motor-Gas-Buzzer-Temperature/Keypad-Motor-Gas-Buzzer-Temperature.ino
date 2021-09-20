#include <Keypad.h>
const byte numRows= 4; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad
const int buzzer=12;
const int tmp = A1;
const int gas = A0;
const int motorpin1 = 10;
const int motorpin2 = 11;
//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols]=
{
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};
//Code that shows the the keypad connections to the arduino terminals
byte rowPins[numRows] = {9,8,7,6}; //Rows 0 to 3
byte colPins[numCols]= {5,4,3,2}; //Columns 0 to 3
//initializes an instance of the Keypad class
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
void setup()
{
Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
   pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(tmp, INPUT);
   pinMode(gas,INPUT);
}
//If key is pressed, this key is stored in 'keypressed' variable
//If key is not equal to 'NO_KEY', then this key is printed out
//if count=17, then count is reset back to 0 (this means no key is pressed during the whole keypad scan process
void loop()
{
  
char keypressed = myKeypad.getKey();
if (keypressed != NO_KEY)
{
Serial.println(keypressed);
}
if (keypressed=='1')
{
digitalWrite(13,HIGH);
  Serial.println("LED");
}
  if (keypressed=='2')
{
tone(buzzer,500,2000);
    delay(1000);
}
    if (keypressed=='3')
{
  	digitalWrite(motorpin1,HIGH);
    digitalWrite(motorpin2,LOW);
}
    if (keypressed=='4')
{
float t = analogRead(tmp);
  double temp = (double)t / 1024;   //find percentage of input reading
  temp = temp * 5;                     //multiply by 5V to get voltage
  temp = temp - 0.5;                   //Subtract the offset 
  temp = temp * 100; 
      Serial.println(temp);
}
    if (keypressed=='5')
{
      Serial.println(analogRead(gas));
}
}