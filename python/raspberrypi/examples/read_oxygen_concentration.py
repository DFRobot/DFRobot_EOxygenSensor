# -*- coding:utf-8 -*-
from __future__ import print_function
'''
  # @file read_oxygen_concentration.py
  # @brief Obtain oxygen concentration in air unit VOL
  # @n Experimental phenomenon Oxygen concentration is printed on the terminal
  # @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  # @license     The MIT License (MIT)
  # @author      [ZhixinLiu](zhixin.liu@dfrobot.com)
  # @version     V1.0
  # @date        2021-12-29
  # @url https://github.com/DFRobot/DFRobot_EOxygenSensor
'''
import time
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

def loop():
  time.sleep(0.1)
  oxygen_concentration = oxygen.read_oxygen_concentration()
  print("oxygen concentration is [%.2f] \n"% oxygen_concentration, end = " ")

if __name__ == "__main__":
  while True:
    loop()