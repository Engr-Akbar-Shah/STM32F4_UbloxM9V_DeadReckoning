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

static icm_accel_range_t current_accel_range = ICM_ACCEL_RANGE_4G;
static icm_gyro_range_t  current_gyro_range  = ICM_GYRO_RANGE_500DPS;


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
//        printf("[ICM42688P][READ] TX failed (reg 0x%02X), status=%d\r\n", reg, status);
        return status;
    }

    status = HAL_I2C_Master_Receive(icm_hi2c, ICM42688P_ADDR, data, len, ICM42688P_TIMEOUT);
    if (status != HAL_OK) {
//        printf("[ICM42688P][READ] RX failed (reg 0x%02X), status=%d\r\n", reg, status);
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
//        printf("[ICM42688P][WRITE] TX failed (reg 0x%02X), status=%d\r\n", reg, status);
    }

    return status;
}

HAL_StatusTypeDef ICM42688P_EnableSensors(void)
{
    uint8_t val = 0;

    // 0x0F = accel + gyro ON, temp ON, normal mode
    val = 0x0F;

    HAL_StatusTypeDef status = ICM42688P_Write(ICM42688P_PWR_MGMT0, &val, 1);

    if (status != HAL_OK) {
        printf("[ICM42688P][CFG] ERROR: Failed to enable sensors\r\n");
        return status;
    }

    HAL_Delay(10);
    return HAL_OK;
}

static float icm_get_accel_sensitivity(void)
{
    switch (current_accel_range)
    {
        case ICM_ACCEL_RANGE_2G:  return 2.0f  / 32768.0f;
        case ICM_ACCEL_RANGE_4G:  return 4.0f  / 32768.0f;
        case ICM_ACCEL_RANGE_8G:  return 8.0f  / 32768.0f;
        case ICM_ACCEL_RANGE_16G: return 16.0f / 32768.0f;
    }
    return 1.0f;
}

static float icm_get_gyro_sensitivity(void)
{
    switch (current_gyro_range)
    {
        case ICM_GYRO_RANGE_250DPS:  return 250.0f  / 32768.0f;
        case ICM_GYRO_RANGE_500DPS:  return 500.0f  / 32768.0f;
        case ICM_GYRO_RANGE_1000DPS: return 1000.0f / 32768.0f;
        case ICM_GYRO_RANGE_2000DPS: return 2000.0f / 32768.0f;
    }
    return 1.0f;
}


HAL_StatusTypeDef ICM42688P_ConfigAccel(icm_accel_range_t range, icm_odr_t odr)
{
    uint8_t reg = 0;

    // Build config byte
    reg |= (odr << 5);
    reg |= (range << 1);

    HAL_StatusTypeDef status = ICM42688P_Write(ICM42688P_ACCEL_CONFIG0, &reg, 1);

    if (status != HAL_OK) {
        printf("[ICM42688P][CFG] ERROR: ACCEL config failed\r\n");
    }
    else if (status == HAL_OK)
            current_accel_range = range;

    return status;
}

HAL_StatusTypeDef ICM42688P_ConfigGyro(icm_gyro_range_t range, icm_odr_t odr)
{
    uint8_t reg = 0;

    reg |= (odr << 5);
    reg |= (range << 1);

    HAL_StatusTypeDef status = ICM42688P_Write(ICM42688P_GYRO_CONFIG0, &reg, 1);

    if (status != HAL_OK) {
        printf("[ICM42688P][CFG] ERROR: GYRO config failed\r\n");
    }
    else if (status == HAL_OK)
        current_gyro_range = range;

    return status;
}

static HAL_StatusTypeDef ICM42688P_WaitForDataReady(void)
{
    uint8_t st;
    for (int i = 0; i < 20; i++)  // up to ~20 * 5ms = 100ms
    {
        if (ICM42688P_Read(ICM42688P_INT_STATUS, &st, 1) == HAL_OK)
        {
            if (st & 0x08) // bit3: UI data ready
                return HAL_OK;
        }
        HAL_Delay(5);
    }

    printf("[ICM42688P][DATA] DRDY timeout\r\n");
    return HAL_TIMEOUT;
}


HAL_StatusTypeDef ICM42688P_ReadData(icm_data_t *out)
{
    if (!out) return HAL_ERROR;

    uint8_t buf[12];   // accel(6) + gyro(6)

    if (ICM42688P_WaitForDataReady() != HAL_OK)
        {
            printf("[ICM42688P][DATA] No data ready\r\n");
            return HAL_ERROR;
        }

    // start at ACCEL_DATA_X1
    HAL_StatusTypeDef status =
        ICM42688P_Read(ICM42688P_ACCEL_DATA_X1, buf, sizeof(buf));

    if (status != HAL_OK) {
        printf("[ICM42688P][DATA] Read failed\r\n");
        return status;
    }

    int16_t ax = (int16_t)((buf[0] << 8) | buf[1]);
    int16_t ay = (int16_t)((buf[2] << 8) | buf[3]);
    int16_t az = (int16_t)((buf[4] << 8) | buf[5]);

    int16_t gx = (int16_t)((buf[6] << 8) | buf[7]);
    int16_t gy = (int16_t)((buf[8] << 8) | buf[9]);
    int16_t gz = (int16_t)((buf[10] << 8) | buf[11]);

    float a_sens = icm_get_accel_sensitivity();
    float g_sens = icm_get_gyro_sensitivity();

    out->ax = ax * a_sens;
    out->ay = ay * a_sens;
    out->az = az * a_sens;

    out->gx = gx * g_sens;
    out->gy = gy * g_sens;
    out->gz = gz * g_sens;

    return HAL_OK;
}



// ---------------- INIT ----------------
HAL_StatusTypeDef ICM42688P_Init(I2C_HandleTypeDef *hi2c)
{
    uint8_t who = 0;
    uint8_t rst = 0;
    HAL_StatusTypeDef st;

    printf("\r\n[ICM42688P] Init start...\r\n");
    HAL_Delay(1000);
    icm_hi2c = hi2c;

    HAL_Delay(20);

    // -------- VERIFY DEVICE ----------
    st = ICM42688P_Read(ICM42688P_WHO_AM_I, &who, 1);
    if (st != HAL_OK || who != 0x47) {
        printf("[INIT] WHO_AM_I failed (0x%02X)\r\n", who);
        return HAL_ERROR;
    }

    printf("[INIT] WHO_AM_I OK\r\n");

    // -------- SOFT RESET ----------
    rst = 0x01;
    st = ICM42688P_Write(ICM42688P_DEVICE_CONFIG, &rst, 1);
    HAL_Delay(200);

    // poll RESET DONE bit
    uint8_t int_status = 0;
    for (int i = 0; i < 50; i++) {
        if (ICM42688P_Read(ICM42688P_INT_STATUS, &int_status, 1) == HAL_OK) {
            if (int_status & (1 << 4)) break;
        }
        HAL_Delay(5);
    }

    HAL_Delay(200);

    // -------- ENABLE SENSORS ----------
    uint8_t pwr = 0x0F;
    st = ICM42688P_Write(ICM42688P_PWR_MGMT0, &pwr, 1);
    HAL_Delay(100);

    // -------- CONFIG ACCEL ----------
    uint8_t aconf = (ICM_ODR_200HZ << 5) | (ICM_ACCEL_RANGE_4G << 1);
    st = ICM42688P_Write(ICM42688P_ACCEL_CONFIG0, &aconf, 1);
    HAL_Delay(200);
    current_accel_range = ICM_ACCEL_RANGE_4G;

    // -------- CONFIG GYRO ----------
    uint8_t gconf = (ICM_ODR_200HZ << 5) | (ICM_GYRO_RANGE_500DPS << 1);
    st = ICM42688P_Write(ICM42688P_GYRO_CONFIG0, &gconf, 1);
    HAL_Delay(200);
    current_gyro_range = ICM_GYRO_RANGE_500DPS;

    printf("[ICM42688P] Init done.\r\n");

    HAL_Delay(200);
    uint8_t bank0 = 0x00;
    ICM42688P_Write(ICM42688P_REG_BANK_SEL, &bank0, 1);

    HAL_Delay(1000);

    uint8_t r;

    ICM42688P_Read(ICM42688P_PWR_MGMT0, &r, 1);
    printf("PWR_MGMT0 = 0x%02X\r\n", r);

    ICM42688P_Read(ICM42688P_ACCEL_CONFIG0, &r, 1);
    printf("ACCEL_CONFIG0 = 0x%02X\r\n", r);

    ICM42688P_Read(ICM42688P_GYRO_CONFIG0, &r, 1);
    printf("GYRO_CONFIG0  = 0x%02X\r\n", r);


    return HAL_OK;
}


