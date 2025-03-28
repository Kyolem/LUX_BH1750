#include <BH1750.h>
#include <Arduino.h>

BH1750 ::BH1750()
{
    _adress = 0;
    _mode = 0;
}

bool BH1750 ::begin(uint8_t adress)
{
    _adress = adress; // chaque objet aura sa propre adresse
    bool res = false;
    Wire.begin();
    Wire.beginTransmission(adress);
    uint8_t val = Wire.endTransmission();
    if (val == 0)
    {
        res = true;
    }
    else
    {
        res = false;
    }
    return res;
}

void BH1750 ::setMode(uint8_t mode)
{
    _mode = mode;
    //
    switch (_mode)
    {
    case BH1750_CONTINOUS_H_RES_MOD:
        Wire.begin();
        Wire.beginTransmission(BH1750_CONTINOUS_H_RES_MOD);
        Wire.endTransmission();
        break;

    case BH1750_CONTINOUS_H_RES2_MOD:
        Wire.begin();
        Wire.beginTransmission(BH1750_CONTINOUS_H_RES2_MOD);
        Wire.endTransmission();
        break;

    case BH1750_CONTINOUS_L_RES_MOD:
        Wire.begin();
        Wire.beginTransmission(BH1750_CONTINOUS_L_RES_MOD);
        Wire.endTransmission();
        break;

    case BH1750_ONE_TIME_H_RES_MOD:
        Wire.begin();
        Wire.beginTransmission(BH1750_ONE_TIME_H_RES_MOD);
        Wire.endTransmission();
        break;

    case BH1750_ONE_TIME_H_RES2_MOD:
        Wire.begin();
        Wire.beginTransmission(BH1750_ONE_TIME_H_RES2_MOD);
        Wire.endTransmission();
        break;

    case BH1750_ONE_TIME_L_RES_MOD:
        Wire.begin();
        Wire.beginTransmission(BH1750_ONE_TIME_L_RES_MOD);
        Wire.endTransmission();
        break;

    default:
        Wire.begin();
        Wire.beginTransmission(BH1750_CONTINOUS_H_RES_MOD);
        Wire.endTransmission();
        break;
    }
}

bool BH1750 ::isMeasurementReady()
{
    uint32_t timedelay = 0;
    bool res = false;
    uint32_t now = 0;

    switch (_mode)
    {
    case BH1750_CONTINOUS_H_RES_MOD:
        timedelay = 180;
        break;

    case BH1750_CONTINOUS_H_RES2_MOD:
        timedelay = 180;
        break;

    case BH1750_CONTINOUS_L_RES_MOD:
        timedelay = 24;
        break;

    case BH1750_ONE_TIME_H_RES_MOD:
        timedelay = 180;
        break;

    case BH1750_ONE_TIME_H_RES2_MOD:
        timedelay = 180;
        break;

    case BH1750_ONE_TIME_L_RES_MOD:
        timedelay = 24;
        break;

    default:
        timedelay = 180;
        break;
    }
    now = millis();

    if ((now - _lastTime) > timedelay)
    {
        res = true;
    }

    return res;
}

void BH1750 ::powerOn()
{
    Wire.begin();
    Wire.beginTransmission(BH1750_POWER_ON);
    Wire.endTransmission();
}

void BH1750 ::powerDown()
{
    Wire.begin();
    Wire.beginTransmission(BH1750_POWER_DOWN);
    Wire.endTransmission();
}

float BH1750 ::readValue()
{
    uint16_t data = 0x0000;
    uint8_t lower = 0x00;
    uint8_t upper = 0x00;
    float LUX = 0;

    Wire.beginTransmission(_adress);
    Wire.write(_adress);
    Wire.endTransmission();

    Wire.requestFrom(_adress, byte(2));

    upper = Wire.read();
    lower = Wire.read();

    data = ((upper << 8) | lower);
    LUX = data / 1.20;

    _lastTime = millis();

    return LUX;
}