/*!
  * @file  getOxygenConcentration.ino
  * @brief Enable the power, and the information is printed on the serial port.
  * @n When using IIC device, select I2C address, set the dialing switch A0, A1 (Address_0 is [0 0]), (Address_1 is [1 0]), (Address_2 is [0 1]), (Address_3 is [1 1]).
  * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  * @license     The MIT License (MIT)
  * @author      ZhixinLiu(zhixin.liu@dfrobot.com)
  * @version     V1.0
  * @date        2021-12-28
  * @get         from https://www.dfrobot.com
  * @url         https://github.com/DFRobot/DFRobot_EOxygenSensor
  */
#include "DFRobot_EOxygenSensor.h"

/**
 *  iic slave Address, The default is E_OXYGEN_ADDRESS_0
 *     E_OXYGEN_ADDRESS_0               0x70
 *     E_OXYGEN_ADDRESS_1               0x71
 *     E_OXYGEN_ADDRESS_2               0x72
 *     E_OXYGEN_ADDRESS_3               0x73
 */
#define OXYGEN_I2C_ADDRESS E_OXYGEN_ADDRESS_0
DFRobot_EOxygenSensor_I2C oxygen(&Wire, OXYGEN_I2C_ADDRESS);

void setup()
{
  Serial.begin(115200);
  while(!Serial);
  while(!oxygen.begin()){
    Serial.println("NO Deivces !");
    delay(1000);
  } Serial.println("Device connected successfully !");
}

void loop() 
{
  Serial.print("oxygen concetnration is "); 
  Serial.print(oxygen.readOxygenConcentration());
  Serial.println("% VOL");
  delay(1000);
}