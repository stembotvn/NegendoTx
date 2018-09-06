#ifndef NegendoTx_h
#define NegendoTx_h

#include "RF24.h"
#include <SPI.h>
#include <EEPROM.h>

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#define CE_PIN	A2
#define CSN_PIN A3

#define SET 2
#define BF  3
#define BB  4
#define BR  5
#define BL  6
#define BLed  7
#define BX  8
#define BSP 9
#define Speed A0
#define buzzer A1
#define Led 13

class NegendoTx
{
public:
	NegendoTx(){}

	void init();
	void convertAdd();
	void setAddress();
	void blinks(int n, int times);
	void tone(uint16_t frequency, uint32_t duration);
	void tick(int n, uint16_t frequency, int times);
private:
	const uint64_t _AddDefault = 0xF0F0F0F001LL;
	uint64_t _AddRandom;
	byte _readAdd;
	byte _address;
	int _Pot;
	int _Add[1];
	long _duration;
	long _startTime;

	RF24 radio= RF24(CE_PIN, CSN_PIN);
};
#endif 