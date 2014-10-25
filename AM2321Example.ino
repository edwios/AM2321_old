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
	float temp, humi;
	unsigned int amID;

	amID = am2321.readID();
	delay(2000);
	temp = am2321.readTemperature();
	delay(2000);
	humi = am2321.readHumidity();

	Serial.print("ID: ");
	Serial.print(amID);
	Serial.print(", Temp: ");
	Serial.print(temp);
	Serial.print(", Humi: ");
	Serial.println(humi);
	delay(2000);
}

