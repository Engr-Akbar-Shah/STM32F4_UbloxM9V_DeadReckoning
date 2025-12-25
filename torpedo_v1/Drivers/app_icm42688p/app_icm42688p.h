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


// Initialize device
HAL_StatusTypeDef ICM42688P_Init(I2C_HandleTypeDef *hi2c);

// Low-level read (TX reg → RX data)
HAL_StatusTypeDef ICM42688P_Read(uint8_t reg, uint8_t *data, uint16_t len);

// Low-level write (TX reg + data)
HAL_StatusTypeDef ICM42688P_Write(uint8_t reg, uint8_t *data, uint16_t len);

#endif /* APP_ICM42688P_APP_ICM42688P_H_ */
