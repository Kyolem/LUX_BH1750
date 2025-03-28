#include <Wire.h>
#include <Arduino.h>
#include <Ticker.h>
#include <BH1750.h>

// constantes
const uint32_t PERIOD = 1000;
const uint8_t BH1750_Addr = 0x23;

// prototypes
void action(void);

// objets
Ticker myTick(action, PERIOD, 0, MILLIS);
BH1750 LUX;
// variables
//**********************************************************************

//**********************************************************************

void action()
{
  if (LUX.isMeasurementReady())
  {
    Serial.println(LUX.readValue());
  }
}

//**********************************************************************
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin();
  myTick.start();
  LUX.begin(BH1750_Addr);
  LUX.powerOn();
  LUX.setMode(BH1750_CONTINOUS_H_RES_MOD);
}

//**********************************************************************
void loop()
{
  myTick.update();
}
