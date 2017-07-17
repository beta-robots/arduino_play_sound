//playing sound from a SD card

//standard library
#include <SPI.h>
#include <SD.h>
#include "TMRpcm.h"

//play sound TMRpcm object
TMRpcm tmrpcm;

//pin assignement & constants
int PIN_SD_CS = 8; // Pin 8 for SD chip select on sparkfun SD shield
int PIN_SPEAKER = 9; // Pin 9 to audio amplifier input
int SERIAL_BAUD_RATE = 9600; //debugging

//global vars

//setup
void setup()
{
	//opens serial port, sets data rate to 9600 bps, Useful for debugging
	Serial.begin(SERIAL_BAUD_RATE);

	//set chip select pin as output
 	pinMode(PIN_SD_CS, OUTPUT);

	//SD init
  	Serial.println("Initializing SD card...");
  	if (!SD.begin(PIN_SD_CS))
	{
		Serial.println("Initialization failed!!!");
		Serial.println("EXIT program.");
	    return;
  	}
  	Serial.println("SD initialization done.");

	//tmrpcm init
	tmrpcm.speakerPin = PIN_SPEAKER;
	tmrpcm.setVolume(6);
}

//main loop
void loop()
{
	File sound_file = SD.open("sound1.txt", FILE_READ);
	unsigned char file_byte;

	// if the file is available, write to it:
	if (sound_file)
	{
		//play a sound
		tmrpcm.play("sound1.wav");

		// read from the file until there's nothing else in it:
    	while (sound_file.available())
		{
			file_byte = sound_file.read();
      		Serial.write(file_byte);
			//Serial.print(" - ");
			//Serial.println(file_byte);
		}
	}

	//close file
	sound_file.close();

	//relax
	delay(500);
}
