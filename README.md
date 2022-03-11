# DFRobot_EOxygenSensor
- [中文版](./README_CN.md)

The DFRobot full-scale oxygen sensor has a built-in calibration algorithm on the signal board that can quickly perform single-point or double-point calibration so as to accurately measure the oxygen concentration in the environment and it features I2C digital output. Based on the principle of electrochemistry, the sensor probe comes with strong anti-interference ability, high stability and sensitivity, and up to two years of service life. It is compatible with mainstream controllers such as Arduino, ESP32, Raspberry Pi, etc. Besides, the sensor is designed with an easy-to-use Gravity interface, and with our sample codes, you can quickly build an oxygen detector.<br>

![Product Image](./resources/images/SEN0496.jpg)

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
* 100% O2 in the signal: 100±1%<br>
* Linearity: 0-100%O2<br>
* Operating temperature range: -20 - +50 ℃<br>
* Differential pressure range: 0-500mbar Max<br> 
* Absolute pressure range: 500-2000mbar<br>
* Relatively humidity range: 0 - 99% RH (non-condensing)<br>

## Installation

There are two methods for using this library:<br>
1. Open Arduino IDE, search for "DFRobot_EOxygenSensor" on the status bar in Tools ->Manager Libraries and install the library.<br>
2. Download the library file before use, paste it into \Arduino\libraries directory, then open the examples folder and run the demo in the folder.<br>

## Methods

```C++
  /**
   * @fn readOxygenConcentration
   * @brief Get oxygen concentration unit vol
   * @return concentration
   */
  float readOxygenConcentration(void);

  /**
   * @fn readCalibrationState
   * @brief Check calibration status
   * @return state
   */
  uint8_t readCalibrationState(void);

  /**
   * @fn calibration_20_9
   * @brief Calibration in air with an O2 concentration of 20.9% Vol
   * @return Calibration state
   */
  bool calibration_20_9(void);

  /**
   * @fn calibration_99_5
   * @brief Calibration in air with an O2 concentration of 99.5% Vol
   * @return Calibration state
   */
  bool calibration_99_5(void);

  /**
   * @fn clearCalibration
   * @brief Clear calibration data
   * @return clear state
   */
  bool clearCalibration(void);
```

## Compatibility

MCU                | Work Well    | Work Wrong   | Untested    | Remarks
------------------ | :----------: | :----------: | :---------: | :----:
Arduino Uno        |      √       |              |             |
Arduino MEGA2560   |      √       |              |             |
Arduino Leonardo   |      √       |              |             |
FireBeetle-ESP32   |      √       |              |             |
Micro:bit          |              |              |      √      |


## History

- 2021/12/28 - V1.0.0 Version

## Credits

Written by ZhiXinLiu(ZhiXin.Liu@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))
