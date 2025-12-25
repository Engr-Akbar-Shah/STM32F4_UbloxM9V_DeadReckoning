/*
 * app_icm42688p.h
 *
 *  Created on: Dec 24, 2025
 *      Author: flash
 */

#ifndef APP_ICM42688P_APP_ICM42688P_H_
#define APP_ICM42688P_APP_ICM42688P_H_

#include "stm32f4xx_hal.h"
#include <stdint.h>


typedef enum {
    ICM_ACCEL_RANGE_2G = 0,
    ICM_ACCEL_RANGE_4G,
    ICM_ACCEL_RANGE_8G,
    ICM_ACCEL_RANGE_16G
} icm_accel_range_t;

typedef enum {
    ICM_GYRO_RANGE_250DPS = 0,
    ICM_GYRO_RANGE_500DPS,
    ICM_GYRO_RANGE_1000DPS,
    ICM_GYRO_RANGE_2000DPS
} icm_gyro_range_t;

typedef enum {
    ICM_ODR_12_5HZ = 0x01,
    ICM_ODR_25HZ   = 0x02,
    ICM_ODR_50HZ   = 0x03,
    ICM_ODR_100HZ  = 0x04,
    ICM_ODR_200HZ  = 0x05,
    ICM_ODR_400HZ  = 0x06,
    ICM_ODR_800HZ  = 0x07,
    ICM_ODR_1600HZ = 0x08
} icm_odr_t;

typedef struct {
    float ax, ay, az;
    float gx, gy, gz;
} icm_data_t;


// Initialize device
HAL_StatusTypeDef ICM42688P_Init(I2C_HandleTypeDef *hi2c);

// Low-level read (TX reg → RX data)
HAL_StatusTypeDef ICM42688P_Read(uint8_t reg, uint8_t *data, uint16_t len);

// Low-level write (TX reg + data)
HAL_StatusTypeDef ICM42688P_Write(uint8_t reg, uint8_t *data, uint16_t len);

HAL_StatusTypeDef ICM42688P_ReadData(icm_data_t *out);

#endif /* APP_ICM42688P_APP_ICM42688P_H_ */
