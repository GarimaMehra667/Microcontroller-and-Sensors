// C++ code
//INTERFACING DC MOTOR AND TEMPERATURE SENSOR
const int tmp = A0;
const int en1 = 11;
const int motorpin1 = 5;
const int motorpin2 = 6;

void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(tmp, INPUT);
}

void loop()
{
  float t = analogRead(tmp);
  double temp = (double)t / 1024;   //find percentage of input reading
  temp = temp * 5;                     //multiply by 5V to get voltage
  temp = temp - 0.5;                   //Subtract the offset 
  temp = temp * 100; 
  
  if(temp<=10.0){
  	digitalWrite(motorpin1,LOW);
    digitalWrite(motorpin2,LOW);
  }
  else if(temp>10.0 && temp<=30.0){
    analogWrite(en1,127);
  	digitalWrite(motorpin1,HIGH);
    digitalWrite(motorpin2,LOW);
  }
  else{
    analogWrite(en1,255);
  	digitalWrite(motorpin1,HIGH);
    digitalWrite(motorpin2,LOW);
  }
}