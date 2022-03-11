# -*- coding:utf-8 -*-
from __future__ import print_function
'''!
  # @file calibration_sensor.py
  # @brief Calibrate the sensor at different concentrations
  # @n Experimental phenomenon The result of sensor calibration is displayed on the serial port
  # @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  # @license     The MIT License (MIT)
  # @author      [ZhixinLiu](zhixin.liu@dfrobot.com)
  # @version     V1.0
  # @date        2021-12-29
  # @url https://github.com/DFRobot/DFRobot_EOxygenSensor
'''
import sys
import os
sys.path.append(os.path.dirname(os.path.dirname(os.path.realpath(__file__))))
from DFRobot_EOxygenSensor import *

I2C_BUS         = 0x01            #default use I2C1
'''
  E_OXYGEN_ADDRESS_0       = 0x70
  E_OXYGEN_ADDRESS_1       = 0x71
  E_OXYGEN_ADDRESS_2       = 0x72
  E_OXYGEN_ADDRESS_3       = 0x73
'''
oxygen = DFRobot_EOxygenSensor_I2C(I2C_BUS, E_OXYGEN_ADDRESS_0)
global state
def setup():
  if oxygen.calibration_20_9() == 1:
    print("20.9 calibration success!\n")
'''
  if oxygen.calibration_99_5() == 1:
    print("99.5 calibration success!\n")
'''
'''
  if oxygen.clear_calibration() == 1:
    print("clear calibration success!\n")
'''
def loop():
  state = oxygen.read_calibration_state()
  if state == 0:
    print("no calbration!\n")
  if state & CALIBRATION_20_9 == CALIBRATION_20_9:
    print("20.9 is calibration!\n", end = " ")
  if state & CALIBRATION_99_5 == CALIBRATION_99_5:
    print("99.5 is calibration!\n", end = " ")
  time.sleep(1)
if __name__ == "__main__":
  setup()
  while True:
    loop()