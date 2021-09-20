#include <IRremote.h>
int RECV_PIN = 10;
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup()
{
Serial.begin(9600);
// In case the interrupt driver crashes on setup, give a clue
// to the user what's going on.
Serial.println("Enabling IRin");
irrecv.enableIRIn(); // Start the receiver
Serial.println("Enabled IRin");
pinMode(13,OUTPUT);
}
void loop() {
if (irrecv.decode(&results)) {
Serial.println(results.value, DEC);
if (results.value == 16582903){
digitalWrite(13,HIGH);
}
else
{
digitalWrite(13,LOW);
}
irrecv.resume();
delay(100);
}
}