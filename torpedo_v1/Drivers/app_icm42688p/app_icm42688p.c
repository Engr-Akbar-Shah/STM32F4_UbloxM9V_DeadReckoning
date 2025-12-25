/*
 * app_icm42688p.c
 *
 *  Created on: Dec 24, 2025
 *      Author: Akbar Shah
 */


#include "main.h"
#include <stdio.h>
#include "app_icm42688p.h"
#include "app_icm42688p_reg.h"

#define ICM42688P_I2C_ADDR      0x68
#define ICM42688P_ADDR          (ICM42688P_I2C_ADDR << 1)
#define ICM42688P_TIMEOUT       1000

static I2C_HandleTypeDef *icm_hi2c = NULL;

// ---------------- READ ----------------
HAL_StatusTypeDef ICM42688P_Read(uint8_t reg, uint8_t *data, uint16_t len)
{
    if (icm_hi2c == NULL) {
        printf("[ICM42688P][READ] ERROR: I2C handle is NULL\r\n");
        return HAL_ERROR;
    }

    HAL_StatusTypeDef status;

    status = HAL_I2C_Master_Transmit(icm_hi2c, ICM42688P_ADDR, &reg, 1, ICM42688P_TIMEOUT);
    if (status != HAL_OK) {
        printf("[ICM42688P][READ] TX failed (reg 0x%02X), status=%d\r\n", reg, status);
        return status;
    }

    status = HAL_I2C_Master_Receive(icm_hi2c, ICM42688P_ADDR, data, len, ICM42688P_TIMEOUT);
    if (status != HAL_OK) {
        printf("[ICM42688P][READ] RX failed (reg 0x%02X), status=%d\r\n", reg, status);
    }

    return status;
}

// ---------------- WRITE ----------------
HAL_StatusTypeDef ICM42688P_Write(uint8_t reg, uint8_t *data, uint16_t len)
{
    if (icm_hi2c == NULL) {
        printf("[ICM42688P][WRITE] ERROR: I2C handle is NULL\r\n");
        return HAL_ERROR;
    }

    uint8_t buf[len + 1];
    buf[0] = reg;

    for (uint16_t i = 0; i < len; i++)
        buf[i + 1] = data[i];

    HAL_StatusTypeDef status =
        HAL_I2C_Master_Transmit(icm_hi2c, ICM42688P_ADDR, buf, len + 1, ICM42688P_TIMEOUT);

    if (status != HAL_OK) {
        printf("[ICM42688P][WRITE] TX failed (reg 0x%02X), status=%d\r\n", reg, status);
    }

    return status;
}

// ---------------- INIT ----------------
HAL_StatusTypeDef ICM42688P_Init(I2C_HandleTypeDef *hi2c)
{
    uint8_t who = 0;

    printf("\r\n[ICM42688P] Init start...\r\n");

    if (hi2c == NULL) {
        printf("[ICM42688P][INIT] ERROR: I2C handle is NULL\r\n");
        return HAL_ERROR;
    }

    icm_hi2c = hi2c;

    HAL_Delay(30);

    // poll WHO_AM_I
    HAL_StatusTypeDef status = HAL_ERROR;

    for (int i = 0; i < 10; i++)
    {
        status = ICM42688P_Read(ICM42688P_WHO_AM_I, &who, 1);

        if (status == HAL_OK && who == 0x47)
            break;

        HAL_Delay(5);
    }

    if (status != HAL_OK) {
        printf("[ICM42688P][INIT] ERROR: WHO_AM_I read failed, status=%d\r\n", status);
        return HAL_ERROR;
    }

    printf("[ICM42688P][INIT] WHO_AM_I = 0x%02X\r\n", who);

    if (who != 0x47) {
        printf("[ICM42688P][INIT] ERROR: Invalid WHO_AM_I (expected 0x47)\r\n");
        return HAL_ERROR;
    }

    // soft reset
    uint8_t rst = 0x01;
    status = ICM42688P_Write(ICM42688P_DEVICE_CONFIG, &rst, 1);

    if (status != HAL_OK) {
        printf("[ICM42688P][INIT] ERROR: Soft reset write failed, status=%d\r\n", status);
        return HAL_ERROR;
    }

    HAL_Delay(30);

    printf("[ICM42688P] Init done.\r\n");

    return HAL_OK;
}

