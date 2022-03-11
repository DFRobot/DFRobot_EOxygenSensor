/*!
 * @file DFRobot_EOxygenSensor.cpp
 * @brief Define the basic structure of class DFRobot_EOxygenSensor
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      ZhixinLiu(zhixin.liu@dfrobot.com)
 * @version     V1.0
 * @date        2021-12-28
 * @url https://github.com/DFRobot/DFRobot_EOxygenSensor
 */
#include "DFRobot_EOxygenSensor.h"
/*
DFRobot_EOxygenSensor::DFRobot_EOxygenSensor()
{
}

DFRobot_EOxygenSensor::~DFRobot_EOxygenSensor()
{
}
*/


void DFRobot_EOxygenSensor::readKB(void)
{
  uint8_t buf[10] = {0x00};
  readData(25, buf, 6);
  // Serial.print("k  "); Serial.println((float)buf[0] + (float)buf[1]/100.0);
  // Serial.print("b  "); Serial.println((float)buf[2] + (float)buf[3]/100.0);
  // Serial.print("k0  "); Serial.println((float)buf[4] + (float)buf[5]/100.0);
}

float DFRobot_EOxygenSensor::readOxygenConcentration(void)
{
  static float oldVol = 0.0;
  float vol;
  uint8_t buf[10] = {0x00};
  readData(OXYGEN_DATA, buf, 3);
  vol = (float)buf[0] + ((float)buf[1])/10.0 + ((float)buf[2])/100.0;
  if(vol >= 0.00001 && vol <= -0.00001){
    return oldVol;
  }else{
    oldVol = vol;
    return vol;
  }
}

uint8_t DFRobot_EOxygenSensor::readCalibrationState(void)
{
  uint8_t buf[10] = {0x00};
  readData(CALIBRATION_STATE, buf, 1);
  return buf[0];
}

bool DFRobot_EOxygenSensor::calibration_20_9(void)
{
  uint8_t state = 0, data = CALIBRATION_20_9;
  writeData(CALIBRATION_SENSOR, &data, 1);
  delay(2000);
  state = readCalibrationState();
  if(state & CALIBRATION_20_9)  return true;
  return false;
}

bool DFRobot_EOxygenSensor::calibration_99_5(void)
{
  uint8_t state = 0, data = CALIBRATION_99_5;
  writeData(CALIBRATION_SENSOR, &data, 1);
  delay(2000);
  state = readCalibrationState();
  if(state & CALIBRATION_99_5)  return true;
  return false;
}

bool DFRobot_EOxygenSensor::clearCalibration(void)
{
  uint8_t state = 0, data = CALIBRATION_CLEAR;
  writeData(CALIBRATION_SENSOR, &data, 1);
  delay(2000);
  state = readCalibrationState();
  if(state == 0)  return true;
  return false;
}

DFRobot_EOxygenSensor_I2C::DFRobot_EOxygenSensor_I2C(TwoWire *pWire, uint8_t addr)
{
  _pWire = pWire;
  this->_I2C_addr = addr;
}

bool DFRobot_EOxygenSensor_I2C::begin(void)
{
  _pWire->begin();
  _pWire->setClock(100000);
  _pWire->beginTransmission(_I2C_addr);
  
  if(_pWire->endTransmission() == 0){
    return true;
  }else{
    DBG("I2C connect error");
    return false;
  }
}

void DFRobot_EOxygenSensor_I2C::writeData(uint8_t reg, uint8_t *data, uint8_t len)
{
  _pWire->beginTransmission(this->_I2C_addr);
  _pWire->write(reg);
  for(uint8_t i = 0; i < len; i++)
    _pWire->write(data[i]);
  _pWire->endTransmission();
}

uint8_t DFRobot_EOxygenSensor_I2C::readData(uint8_t reg, uint8_t *data, uint8_t len)
{
  int i=0;
  _pWire->beginTransmission(this->_I2C_addr);
  _pWire->write(reg);
  _pWire->endTransmission();
  _pWire->requestFrom((uint8_t)this->_I2C_addr,(uint8_t)len);
  while (_pWire->available()){
    data[i++]=_pWire->read();
  }
  return 0;
}