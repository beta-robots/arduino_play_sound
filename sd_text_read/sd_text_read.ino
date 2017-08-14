//test for SD reading

//standard library
#include <SPI.h>
#include <SD.h>


//pin assignement & constants
int PIN_LED = 13; //fixed led at pin 13
int PIN_SD_CS = 8; // Pin 8 for SD chip select on sparkfun SD shield
int SERIAL_BAUD_RATE = 9600; //debugging

//setup
void setup()
{
	//To blink the fixed led at pin 13
 	pinMode(PIN_LED, OUTPUT);

	//opens serial port, sets data rate to 9600 bps, Useful for debugging
	Serial.begin(SERIAL_BAUD_RATE);

	//set chip select pin as output
 	pinMode(PIN_SD_CS, OUTPUT);

	//SD init
  	Serial.println("Initializing SD card...");
  	if (!SD.begin(PIN_SD_CS))
	{
		Serial.println("SD card initialization failed. EXIT PROGRAM.");
	    return;
  	}
  	Serial.println("SD initialization done.");
}

//main loop
void loop()
{
	File text_file;
	unsigned char file_byte;

	//blink the led 13
	digitalWrite(PIN_LED, HIGH);

	//read a text file and send bytes throughh serial comm
	text_file = SD.open("test.txt", FILE_READ);
	if (text_file)
	{
		while ( text_file.available() )
		{
			file_byte = text_file.read();
	  		Serial.write(file_byte);
			//Serial.print(" - ");
			//Serial.println(file_byte);
		}
		Serial.println("");
	}
	text_file.close();

	//unblink the led 13
	digitalWrite(PIN_LED, LOW);
	delay(500);

}
