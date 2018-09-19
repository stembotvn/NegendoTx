#include <NegendoTx.h>

NegendoTx Negendo;
int Data[9];
int old_Data[9];
void readButton()
{
    Data[0] = digitalRead(BF);
    Data[1] = digitalRead(BB);
    Data[2] = digitalRead(BL);
    Data[3] = digitalRead(BR);
    Data[4] = digitalRead(BSP);
    Data[5] = digitalRead(BLed);
    Data[6] = digitalRead(BX);
    Data[7] = digitalRead(BY);
    Data[8] = analogRead(Speed);
    for(int i=0; i<=7; i++)
    {
      if(Data[i] == 0)
      {
        Data[i] = 1;
      }
      else if(Data[i] == 1)
      {
        Data[i] = 0;
      }
    }
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
    Negendo.radio.write(Data, sizeof(Data));
    old_Data[0] = Data[0];
    old_Data[1] = Data[1];
    old_Data[2] = Data[2];
    old_Data[3] = Data[3];
    old_Data[4] = Data[4];
    old_Data[5] = Data[5];
    old_Data[6] = Data[6];
    old_Data[7] = Data[7];
    old_Data[8] = Data[8];
    Serial.println("Send data");
  }
}

