#include "buttons.h"

Buttons::Buttons(int shift, int clk, int stcp, int serial)
{
	this->shift=shift;
	this->clk=clk;
	this->stcp=stcp;
	this->serial=serial;
	
	pinMode(shift, OUTPUT);
	pinMode(clk, OUTPUT);
	pinMode(stcp, OUTPUT);
  pinMode(serial, INPUT);

	digitalWrite(stcp, LOW);
	digitalWrite(clk, LOW);
	digitalWrite(shift, HIGH);
	
}

uint8_t Buttons::readButtons(void)
{
	volatile uint8_t input = 0, temp = 0;

    digitalWrite(clk, HIGH);
  delayMicroseconds(wait);
 digitalWrite(clk, LOW);
  delayMicroseconds(wait);
   digitalWrite(clk, HIGH);
 delayMicroseconds(wait);
 digitalWrite(clk, LOW);
  delayMicroseconds(wait);
   digitalWrite(clk, HIGH);
 delayMicroseconds(wait);
 digitalWrite(clk, LOW);
 delayMicroseconds(wait);

 
	digitalWrite(stcp, HIGH);
  delayMicroseconds(wait);
  digitalWrite(clk, HIGH);
	delayMicroseconds(wait);
 digitalWrite(clk, LOW);
  digitalWrite(stcp, LOW); 
 delayMicroseconds(wait);
 digitalWrite(clk, HIGH);
  delayMicroseconds(wait);
   digitalWrite(clk, LOW);
  delayMicroseconds(wait);
   digitalWrite(clk, HIGH);
 delayMicroseconds(wait);
 
	digitalWrite(shift, LOW);
	delayMicroseconds(1);
	digitalWrite(clk, LOW);
  digitalWrite(shift, HIGH);
  delayMicroseconds(wait);
 
	for (int i = 0; i < 8; i++)
	{
    temp = digitalRead(serial);
    input |= temp << i;
		digitalWrite(clk, HIGH);
		delayMicroseconds(wait);
    digitalWrite(clk, LOW);
		delayMicroseconds(wait);
	}



	return input;
}
