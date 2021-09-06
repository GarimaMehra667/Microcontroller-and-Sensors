//// C++ code
// INTERFACING LED'S WITH TEMPERATURE SENSOR
int baselineTemp = 0;
int celsius = 0;
int fahrenheit = 0;
const int LED2=2;
const int LED3=3;
const int LED4=4;
const int buzzer=5;
void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(buzzer, OUTPUT);
}
void loop()
{
  baselineTemp = 40;
  
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  
   fahrenheit = ((celsius * 9) / 5 + 32);
  Serial.print(celsius);
  Serial.print(" C, ");
  Serial.print(fahrenheit);
  Serial.println(" F");
  
   if (celsius < baselineTemp) {
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  }
 if (celsius >= baselineTemp && celsius < baselineTemp + 10) {
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  }
  if (celsius >= baselineTemp + 10 && celsius < baselineTemp + 20) {
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
  }
if (celsius >= baselineTemp + 20 && celsius < baselineTemp + 30) {
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, HIGH);
  }

 if (celsius >= baselineTemp + 30) {
    tone(buzzer,500,2000);
   delay(1000);
   Serial.println("Buzzer");
  }
  delay(1000); 
}
