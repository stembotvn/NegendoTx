#include <TransmitterRF24.h>
#include <SPI.h>
#include "RF24.h"

TransmitterRF24 Negendo;
RF24 radio(CE_PIN, CSN_PIN);
int Data[8];
int old_Data[8];

void readButton()
{
  if(!digitalRead(BF))
    Data[0] = 1;
  else
    Data[0] = 0;
  if(!digitalRead(BB))
    Data[1] = 1;
  else
    Data[1] = 0;
  if(!digitalRead(BF))
    Data[2] = 1;
  else
    Data[2] = 0;
  if(!digitalRead(BL))
    Data[3] = 1;
  else
    Data[3] = 0;
  if(!digitalRead(BLed))
    Data[4] = 1;
  else
    Data[4] = 0;
  if(!digitalRead(BX))
    Data[5] = 1;
  else
    Data[5] = 0;
  if(!digitalRead(BSP))
    Data[6] = 1;
  else
    Data[6] = 0;

  Data[7] = analogRead(A0);
}
void setup() 
{
  Negendo.init();
}

void loop() 
{
  Negendo.setAddress();
  readButton();
  if(Data[0]!=old_Data[0] || Data[1]!=old_Data[1] || Data[2]!=old_Data[2] || Data[3]!=old_Data[3] || Data[4]!=old_Data[4] || Data[5]!=old_Data[5] || Data[6]!=old_Data[6] || Data[7]!=old_Data[7])
  {
    radio.write(Data, sizeof(Data));
    old_Data[0] = Data[0];
    old_Data[1] = Data[1];
    old_Data[2] = Data[2];
    old_Data[3] = Data[3];
    old_Data[4] = Data[4];
    old_Data[5] = Data[5];
    old_Data[6] = Data[6];
    old_Data[7] = Data[7];
  }
}

