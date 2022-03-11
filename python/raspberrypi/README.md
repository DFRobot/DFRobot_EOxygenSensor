# DFRobot_EOxygenSensor

- [中文版](./README_CN.md)

The DFRobot full-scale oxygen sensor has a built-in calibration algorithm on the signal board that can quickly perform single-point or double-point calibration so as to accurately measure the oxygen concentration in the environment and it features I2C digital output. Based on the principle of electrochemistry, the sensor probe comes with strong anti-interference ability, high stability and sensitivity, and up to two years of service life. It is compatible with mainstream controllers such as Arduino, ESP32, Raspberry Pi, etc. Besides, the sensor is designed with an easy-to-use Gravity interface, and with our sample codes, you can quickly build an oxygen detector.<br>

![Product Image](../../resources/images/SEN0496.jpg)

## Product Link (Link to DFRobot store)
    SKU: SEN0496

## Table of Contents

  * [Summary](#summary)
  * [Installation](#installation)
  * [Methods](#methods)
  * [Compatibility](#compatibility)
  * [History](#history)
  * [Credits](#credits)

## Summary

* Measuring range: 0-100% O2<br>
* Accuracy: 0.01% O2<br>
* 100% O2 in the signal: 100±1% <br>
* Linearity: 0-100%O2<br>
* Operating temperature range: -20 - +50 ℃<br>
* Differential pressure range: 0-500mbar Max<br> 
* Absolute pressure range: 500-2000mbar<br>
* Relatively humidity range: 0 - 99% RH (non-condensing)<br>

## Installation

Download the library to Raspberry Pi before use, then open the routine folder. Input python demox.py into the command line to execute a routine demox.py. For example, to execute control_led.py routine, you need to type:

```python
python calibrationSensor.py
python getOxygenConcentration.py
```

## Methods

```python
  '''!
    @brief Get oxygen concentration in the air, unit VOL
    @return concentration
  '''
  def read_oxygen_concentration(self):

  '''!
    @brief Get calibration status
    @return state
  '''
  def read_calibration_state(self):

  '''!
    @brief Calibrate sensor in air with an O2 concentration of 20.9% Vol
    @return Calibration status
  '''
  def calibration_20_9(self):

  '''!
    @brief Calibrate sensor in 99.5% pure oxygen
    @return Calibration status
  '''
  def calibration_99_5(self):

  '''!
    @brief Clear calibration status
    @return Calibration status
  '''
  def clear_calibration(self):
```

## Compatibility

| Board        | Work Well | Work Wrong | Untested | Remarks |
| ------------ | :-------: | :--------: | :------: | ------- |
| RaspberryPi2 |           |            |    √     |         |
| RaspberryPi3 |     √     |            |          |         |
| RaspberryPi4 |           |            |    √     |         |

* Python Version

| Python  | Work Well | Work Wrong | Untested | Remarks |
| ------- | :-------: | :--------: | :------: | ------- |
| Python2 |     √     |            |          |         |
| Python3 |     √     |            |          |         |

## History

- 2021/12/29 - Version 1.0.0 released.

## Credits
Written by ZhiXinLiu(ZhiXin.Liu@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))
