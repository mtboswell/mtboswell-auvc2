#include "WProgram.h"
void setup();
void loop();
void setup(){
	Serial.begin(9600);
	pinMode(7,OUTPUT);
        pinMode(2,OUTPUT);
	digitalWrite(7,HIGH);
}

void loop(){
        if( Serial.available() > 0 ){
          if( Serial.read() == 'r' ){
             digitalWrite(2,HIGH);
             delay(1);
             digitalWrite(2,LOW);
          }
        }
	Serial.print(" DEPTH");
	Serial.print(analogRead(0));
	Serial.print(" GO");
	Serial.print(digitalRead(6));
	delay(10);
}

int main(void)
{
	init();

	setup();
    
	for (;;)
		loop();
        
	return 0;
}

