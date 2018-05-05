#include <buttons.h>

Buttons button(4,0,15,10);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
}

uint8_t but = 0;

void loop() {
  but = button.readButtons();
  delay(50);
  if(but)
  {
	Serial.print(" Buttons: ");
	if (but & Buttons::UP) Serial.print("UP ");
	if (but & Buttons::DOWN) Serial.print("DOWN ");
	if (but & Buttons::LEFT) Serial.print("LEFT ");
	if (but & Buttons::RIGHT) Serial.print("RIGHT ");
	if (but & Buttons::A) Serial.print("A "); 
	if (but & Buttons::B) Serial.print("B ");
	if (but & Buttons::SELECT) Serial.print("SELECT ");
	if (but & Buttons::START) Serial.println("START ");
	Serial.println();
 }
}
