/**************************************************************** 
  This is the Spark Core example of using the library of the
  AM2321 Humidity and Temperature sensor
  This sensor uses custom I2C communication and supports 2 wires
  and one wire configuration.
  
  This example assumed a 2 wires configuration.  
  
  Written by Ed Wios.
  Oct 2014
 ***************************************************************/
 
#include "AM2321.h"

#include "application.h"

extern char* itoa(int a, char* buffer, unsigned char radix);

AM2321 am2321;

char str[8];

void setup()
{
    am2321.begin();
    Serial.begin(BAUD);
}

void loop()
{
	unsigned long result = 0;
	unsigned int temp, humi = 0;
	unsigned int amID = 0;

	amID = am2321.readID();
	delay(2000);
	result = am2321.readAll();
	humi = result>>16;
	temp = result&0xFFFF;

	Serial.print("ID: ");
	Serial.print(amID);
	Serial.print(", Temp: ");
	Serial.print(temp/10.0);
	Serial.print(", Humi: ");
	Serial.println(humi/10.0);
	delay(2000);
}

