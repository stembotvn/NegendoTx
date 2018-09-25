#include "NegendoTx.h"
#include "RF24.h"
#include "EEPROM.h"

void NegendoTx::init()
{
	Serial.begin(9600);
	randomSeed(analogRead(A7));

	pinMode(SET, INPUT);
	pinMode(BF, INPUT);
	pinMode(BB, INPUT);
	pinMode(BR, INPUT);
	pinMode(BL, INPUT);
	pinMode(BLed, INPUT);
	pinMode(BX, INPUT);
	pinMode(BY, INPUT);
	pinMode(BSP, INPUT);

	radio.begin();
	radio.setChannel(108);
	radio.setDataRate(RF24_1MBPS);
	radio.setPALevel(RF24_PA_HIGH);
	convertAdd();
}
void NegendoTx::convertAdd()
{
	_readAdd = EEPROM.read(0);
	_AddRandom = (_AddDefault & ~0xFFLL) | _readAdd;
	Serial.print("Address: ");
	Serial.print((unsigned long)(_AddRandom >> 32), 16);
	Serial.println((unsigned long)_AddRandom, 16);
	radio.openWritingPipe(_AddRandom);
}
void NegendoTx::setAddress()
{
	if(!digitalRead(SET))
	{
		Serial.println("Set Address");
		Serial.println("Wait 5s...");
		_startTime = millis();
		while(!digitalRead(SET))
		{
			if(millis() - _startTime == 5000)
			{
				Serial.println("Ready to send new address");
				_address = random(2,255);
				EEPROM.write(0,_address);
				_Add[0] = _address;
				radio.openWritingPipe(_AddDefault);
				radio.write(_Add, sizeof(_Add));
			}
		}
		Serial.println("Set address done.");
		convertAdd();
	}
}
