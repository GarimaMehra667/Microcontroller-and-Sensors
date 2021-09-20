// C++ code
//INTERFACE ULTRASONIC DISTANCE SENSOR WITH DC MOTOR AND BUZZER
int inches = 0;
int cm = 0;
const int en1 = 11;
const int motorpin1 = 5;
const int motorpin2 = 6;
const int buzzer=12;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void MOTOR()
{if (cm>40)
  {
    analogWrite(en1,255);
    digitalWrite(motorpin1,HIGH);
    digitalWrite(motorpin2,LOW);
  }
    else if (cm>20 & cm<30)
     {
    analogWrite(en1,127);
  	digitalWrite(motorpin1,HIGH);
    digitalWrite(motorpin2,LOW);
  }
  
  else
  {
    digitalWrite(motorpin1,LOW);
    digitalWrite(motorpin2,LOW);
    tone(buzzer,500,2000);
    delay(1000);
  }
}

void setup()
{
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(buzzer, OUTPUT);

}

void loop()
{
  // measure the ping time in cm
  cm = 0.01723 * readUltrasonicDistance(7, 7);
  // convert to inches by dividing by 2.54
  inches = (cm / 2.54);
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.println("cm");
  delay(100); // Wait for 100 millisecond(s)
  MOTOR(); 
}