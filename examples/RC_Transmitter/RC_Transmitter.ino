#include <NegendoTx.h>
#include <SPI.h>
#include "RF24.h"

NegendoTx Negendo;
RF24 RF(CE_PIN, CSN_PIN);
int Data[8];
int old_Data[8];
void readButton()
{
    Data[0] = digitalRead(BF);
    Data[1] = digitalRead(BB);
    Data[2] = digitalRead(BL);
    Data[3] = digitalRead(BR);
    Data[4] = digitalRead(BSP);
}
void setup() 
{
  Negendo.init();
  Data[0] = 1;
}

void loop() 
{
  Negendo.setAddress();
  readButton();
  if(Data[0]!=old_Data[0] || Data[1]!=old_Data[1] || Data[2]!=old_Data[2] || Data[3]!=old_Data[3] || Data[4]!=old_Data[4] || Data[5]!=old_Data[5] || Data[6]!=old_Data[6] || Data[7]!=old_Data[7])
  {
    RF.write(Data, sizeof(Data));
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

