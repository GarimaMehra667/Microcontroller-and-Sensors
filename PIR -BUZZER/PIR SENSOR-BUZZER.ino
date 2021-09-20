// C++ code
//INTERFACE PIR SENSOR AND PIEZO BUZZER
void setup()
{
  pinMode(2, INPUT);
  Serial.begin(9600);

  pinMode(8, OUTPUT);
}

void loop()
{
  if (digitalRead(2) == HIGH) {
    Serial.println("Motion Detected");
    tone(8, 1245, 1000); // play tone 75 (D#6 = 1245 Hz)
    delay(500); // Wait for 500 millisecond(s)
    tone(8, 294, 1000); // play tone 50 (D4 = 294 Hz)
    delay(500); // Wait for 500 millisecond(s)
  } else {
    noTone(8);
  }
}