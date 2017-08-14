//Playing single tone. Useful to debug analog circuit

//pin assignement & constants
int PIN_LED = 13; //fixed led at pin 13
int PIN_SPEAKER = 9; // Pin 9 to audio amplifier input

//setup
void setup()
{
	//To blink the fixed led at pin 13
 	pinMode(PIN_LED, OUTPUT);
}

//main loop
void loop()
{
	//blink the led 13
	digitalWrite(PIN_LED, HIGH);

	//play a tone
	tone(PIN_SPEAKER, 440);
	delay(500);
	noTone(PIN_SPEAKER);

	//unblink the led 13
	digitalWrite(PIN_LED, LOW);
	delay(500);
}
