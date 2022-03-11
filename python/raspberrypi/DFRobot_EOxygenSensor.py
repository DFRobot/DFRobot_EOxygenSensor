# -*- coding:utf-8 -*-
'''!
  @file DFRobot_EOxygenSensor.py
  @note DFRobot_EOxygenSensor Class infrastructure, implementation of underlying methods
  @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  @license     The MIT License (MIT)
  @author      [ZhixinLiu](zhixin.liu@dfrobot.com)
  @version     V1.0
  @date       2021-12-29
  @url https://github.com/DFRobot/DFRobot_EOxygenSensor
'''
import time
import smbus
import os

## Oxygen data register
OXYGEN_DATA               = 0x10
## calbration state
CALIBRATION_STATE         = 0x13
## calbration sensor
CALIBRATION_SENSOR        = 0x18
## I2C address 
E_OXYGEN_ADDRESS_0        = 0x70
E_OXYGEN_ADDRESS_1        = 0x71
E_OXYGEN_ADDRESS_2        = 0x72
E_OXYGEN_ADDRESS_3        = 0x73

CALIBRATION_20_9          = 0x01
CALIBRATION_99_5          = 0x02
CALIBRATION_CLEAR         = 0x03

class DFRobot_EOxygenSensor(object):
  '''!
    @brief Electrochemical oxygen class
    @details Contain some functions of obtaining/calibrating oxygen data
  '''
  ## iic send buffer
  __txbuf      = [0]    
  def __init__(self, bus):
    self.i2cbus = smbus.SMBus(bus)

  def read_oxygen_concentration(self):
    '''!
      @brief Get oxygen concentration in the air unit VOL
      @return concentration
    '''
    rslt = self.read_reg(OXYGEN_DATA, 3)
    vol = float(rslt[0]) + float(rslt[1]) / 10.0 + float(rslt[2]) / 100.0
    return vol


  def read_calibration_state(self):
    '''!
      @brief Get calibration status
      @return state
    '''
    rslt = self.read_reg(CALIBRATION_STATE, 3)
    return rslt[0]

  def calibration_20_9(self):
    '''!
      @brief Calibrate sensor in air with an O2 concentration of 20.9% Vol
      @return Calibration status
    '''
    self.__txbuf[0] = 1
    self.write_reg(CALIBRATION_SENSOR, self.__txbuf)
    time.sleep(2)
    state = self.read_calibration_state()
    if state & CALIBRATION_20_9 == CALIBRATION_20_9:
      return 1
    else:
      return 0

  def calibration_99_5(self):
    '''!
      @brief Calibrate sensor in 99.5% pure oxygen
      @return Calibration status
    '''
    self.__txbuf[0] = 2
    self.write_reg(CALIBRATION_SENSOR, self.__txbuf)
    time.sleep(2)
    state = self.read_calibration_state()
    if state & CALIBRATION_99_5 == CALIBRATION_99_5:
      return 1
    else:
      return 0

  def clear_calibration(self):
    '''!
      @brief Clear calibration status
      @return Calibration status
    '''
    self.__txbuf[0] = 3
    self.write_reg(CALIBRATION_SENSOR, self.__txbuf)
    time.sleep(2)
    state = self.read_calibration_state()
    if state == 0:
      return 1
    else:
      return 0


class DFRobot_EOxygenSensor_I2C(DFRobot_EOxygenSensor): 
  '''!
    @brief An example of an IIC interface module
  '''

  def __init__(self, bus, addr):
    self.__addr = addr
    super(DFRobot_EOxygenSensor_I2C, self).__init__(bus)

  def write_reg(self, reg, data):
    '''!
      @brief writes data to a register
      @param reg register address
      @param data written data
    '''
    self.i2cbus.write_i2c_block_data(self.__addr, reg, data)

  def read_reg(self, reg, len):
    '''!
      @brief read the data from the register
      @param reg register address
      @param len read datalen
    '''
    while 1:
      try:
        rslt = self.i2cbus.read_i2c_block_data(self.__addr, reg, len)
        return rslt
      except:
        os.system('i2cdetect -y 1')
