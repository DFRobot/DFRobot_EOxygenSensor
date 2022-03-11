/*!
 * @file DFRobot_EOxygenSensor.h
 * @brief Define the basic structure of class DFRobot_EOxygenSensor
 * @copyright Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license The MIT License (MIT)
 * @author ZhixinLiu(zhixin.liu@dfrobot.com)
 * @version V1.0
 * @date 2021-12-28
 * @url https://github.com/DFRobot/DFRobot_EOxygenSensor
 */
#ifndef __DFRobot_EOxygenSensor__
#define __DFRobot_EOxygenSensor__
#include <Arduino.h>
#include <Wire.h>

//#define ENABLE_DBG
//#define NORMAL_ENABLE

#ifdef ENABLE_DBG
  #ifdef NORMAL_ENABLE
    #define DBG(...) {Serial.println(__VA_ARGS__);}
  #else
    #define DBG(...) {Serial.print("[");Serial.print(__FUNCTION__); Serial.print("(): "); Serial.print(__LINE__); Serial.print(" ] "); Serial.println(__VA_ARGS__);}
  #endif
#else
  #define DBG(...)
#endif

#define           E_OXYGEN_ADDRESS_0       0x70
#define           E_OXYGEN_ADDRESS_1       0x71
#define           E_OXYGEN_ADDRESS_2       0x72
#define           E_OXYGEN_ADDRESS_3       0x73

#define           OXYGEN_DATA              0x10
#define           CALIBRATION_STATE        0x13
#define           CALIBRATION_SENSOR       0x18

#define           CALIBRATION_20_9         0x01
#define           CALIBRATION_99_5         0x02
#define           CALIBRATION_CLEAR        0x03


class DFRobot_EOxygenSensor{
public:
  DFRobot_EOxygenSensor(){};
  ~DFRobot_EOxygenSensor(){};

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

  
protected:
  virtual uint8_t readData (uint8_t reg, uint8_t *data, uint8_t len)=0;
  virtual void    writeData(uint8_t reg, uint8_t *data, uint8_t len)=0;
  void readKB(void);
};

class DFRobot_EOxygenSensor_I2C:public DFRobot_EOxygenSensor{
public:
  DFRobot_EOxygenSensor_I2C(TwoWire *pWire=&Wire, uint8_t addr=0x30);
  ~DFRobot_EOxygenSensor_I2C(){};
  void writeData(uint8_t reg,uint8_t *data,uint8_t len);
  uint8_t readData(uint8_t reg,uint8_t *data,uint8_t len);
  bool begin(void);
private:
  TwoWire *_pWire;
  uint8_t _I2C_addr;
};
#endif
