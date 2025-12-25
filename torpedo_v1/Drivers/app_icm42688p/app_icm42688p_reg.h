/*
 * app_icm42688p_reg.h
 *
 *  Created on: Dec 24, 2025
 *      Author: flash
 */

#ifndef APP_ICM42688P_APP_ICM42688P_REG_H_
#define APP_ICM42688P_APP_ICM42688P_REG_H_

/*BANK 0 REGISTERS*/
#define ICM42688P_DEVICE_CONFIG          0x11  // Configures SPI mode and software reset.
#define ICM42688P_DRIVE_CONFIG           0x13  // Controls slew rate settings for I2C and SPI/I3C interfaces.
#define ICM42688P_INT_CONFIG             0x14  // Configures INT1 and INT2 interrupt modes, drive circuits, and polarity.
#define ICM42688P_FIFO_CONFIG            0x16  // Sets FIFO mode (bypass, stream-to-FIFO, stop-on-full).
#define ICM42688P_TEMP_DATA1             0x1D  // Upper byte of temperature sensor data (15:8).
#define ICM42688P_TEMP_DATA0             0x1E  // Lower byte of temperature sensor data (7:0).
#define ICM42688P_ACCEL_DATA_X1          0x1F  // Upper byte of X-axis accelerometer data (15:8).
#define ICM42688P_ACCEL_DATA_X0          0x20  // Lower byte of X-axis accelerometer data (7:0).
#define ICM42688P_ACCEL_DATA_Y1          0x21  // Upper byte of Y-axis accelerometer data (15:8).
#define ICM42688P_ACCEL_DATA_Y0          0x22  // Lower byte of Y-axis accelerometer data (7:0).
#define ICM42688P_ACCEL_DATA_Z1          0x23  // Upper byte of Z-axis accelerometer data (15:8).
#define ICM42688P_ACCEL_DATA_Z0          0x24  // Lower byte of Z-axis accelerometer data (7:0).
#define ICM42688P_GYRO_DATA_X1           0x25  // Upper byte of X-axis gyroscope data (15:8).
#define ICM42688P_GYRO_DATA_X0           0x26  // Lower byte of X-axis gyroscope data (7:0).
#define ICM42688P_GYRO_DATA_Y1           0x27  // Upper byte of Y-axis gyroscope data (15:8).
#define ICM42688P_GYRO_DATA_Y0           0x28  // Lower byte of Y-axis gyroscope data (7:0).
#define ICM42688P_GYRO_DATA_Z1           0x29  // Upper byte of Z-axis gyroscope data (15:8).
#define ICM42688P_GYRO_DATA_Z0           0x2A  // Lower byte of Z-axis gyroscope data (7:0).
#define ICM42688P_TMST_FSYNCH            0x2B  // Upper byte of FSYNC timestamp data (15:8).
#define ICM42688P_TMST_FSYNCL            0x2C  // Lower byte of FSYNC timestamp data (7:0).
#define ICM42688P_INT_STATUS             0x2D  // Status register for interrupts (FSYNC, PLL ready, reset done, data ready, FIFO, AGC). Read to clear.
#define ICM42688P_FIFO_COUNTH            0x2E  // High byte of FIFO count (15:8).
#define ICM42688P_FIFO_COUNTL            0x2F  // Low byte of FIFO count (7:0).
#define ICM42688P_FIFO_DATA              0x30  // FIFO data output port.
#define ICM42688P_APEX_DATA0             0x31  // Step count lower byte (pedometer output).
#define ICM42688P_APEX_DATA1             0x32  // Step count upper byte (pedometer output).
#define ICM42688P_APEX_DATA2             0x33  // Step cadence (pedometer output).
#define ICM42688P_APEX_DATA3             0x34  // Activity class and DMP idle status.
#define ICM42688P_APEX_DATA4             0x35  // Tap detection outputs (tap count, axis, direction).
#define ICM42688P_APEX_DATA5             0x36  // Double tap timing measurement.
#define ICM42688P_INT_STATUS2            0x37  // Status for SMD, WOM interrupts (X, Y, Z). Read to clear.
#define ICM42688P_INT_STATUS3            0x38  // Status for step detect, step count overflow, tilt, wake, sleep, tap interrupts. Read to clear.
#define ICM42688P_SIGNAL_PATH_RESET      0x4B  // Resets DMP memory, signal path, FIFO, and latches timestamp. Write to clear.
#define ICM42688P_INTF_CONFIG0           0x4C  // Configures FIFO and sensor data handling (hold last data, endianness, invalid data treatment).
#define ICM42688P_INTF_CONFIG1           0x4D  // Configures accelerometer LP clock, RTC mode, and clock source selection.
#define ICM42688P_PWR_MGMT0              0x4E  // Power management for temperature sensor, idle state, gyro, and accel modes.
#define ICM42688P_GYRO_CONFIG0           0x4F  // Sets gyroscope full-scale range and ODR.
#define ICM42688P_ACCEL_CONFIG0          0x50  // Sets accelerometer full-scale range and ODR.
#define ICM42688P_GYRO_CONFIG1           0x51  // Configures gyro temperature filter bandwidth and UI/DEC2 filter order.
#define ICM42688P_GYRO_ACCEL_CONFIG0     0x52  // Configures accel and gyro UI filter bandwidths and low-latency options.
#define ICM42688P_ACCEL_CONFIG1          0x53  // Configures accelerometer UI and DEC2 filter order.
#define ICM42688P_TMST_CONFIG            0x54  // Enables timestamp to registers, sets resolution, delta, FSYNC, and enables timestamp.
#define ICM42688P_APEX_CONFIG0           0x56  // Enables/disables DMP features (power save, tap, pedometer, tilt, raise-to-wake) and sets DMP ODR.
#define ICM42688P_SMD_CONFIG             0x57  // Configures significant motion detection (WOM mode, interrupt mode, SMD mode).
#define ICM42688P_FIFO_CONFIG1           0x5F  // Enables FIFO features (resume partial read, watermark, hires, timestamp, sensors).
#define ICM42688P_FIFO_CONFIG2           0x60  // Lower bits of FIFO watermark threshold.
#define ICM42688P_FIFO_CONFIG3           0x61  // Upper bits of FIFO watermark threshold.
#define ICM42688P_FSYNC_CONFIG           0x62  // Configures FSYNC tagging, clearing, and polarity.
#define ICM42688P_INT_CONFIG0            0x63  // Configures interrupt clearing options for data ready, FIFO threshold, and full.
#define ICM42688P_INT_CONFIG1            0x64  // Configures interrupt pulse duration, de-assertion, and async reset.
#define ICM42688P_INT_SOURCE0            0x65  // Routes UI FSYNC, PLL ready, reset done, data ready, FIFO, AGC interrupts to INT1.
#define ICM42688P_INT_SOURCE1            0x66  // Routes I3C protocol error, SMD, WOM (X, Y, Z) interrupts to INT1.
#define ICM42688P_INT_SOURCE3            0x68  // Routes UI FSYNC, PLL ready, reset done, data ready, FIFO, AGC interrupts to INT2.
#define ICM42688P_INT_SOURCE4            0x69  // Routes I3C protocol error, SMD, WOM (X, Y, Z) interrupts to INT2.
#define ICM42688P_FIFO_LOST_PKT0         0x6C  // Low byte of lost FIFO packet count.
#define ICM42688P_FIFO_LOST_PKT1         0x6D  // High byte of lost FIFO packet count.
#define ICM42688P_SELF_TEST_CONFIG       0x70  // Enables self-test for accelerometer and gyroscope axes.
#define ICM42688P_WHO_AM_I               0x75  // Device ID register (0x47). Read-only.
#define ICM42688P_REG_BANK_SEL           0x76  // Selects user bank (0–4).

/*BANK 1 REGISTERS*/
#define ICM42688P_SENSOR_CONFIG0         0x03  // Disables individual gyroscope and accelerometer axes.
#define ICM42688P_GYRO_CONFIG_STATIC2    0x0B  // Enables/disables gyroscope anti-aliasing filter and notch filter.
#define ICM42688P_GYRO_CONFIG_STATIC3    0x0C  // Sets bandwidth for gyroscope anti-aliasing filter.
#define ICM42688P_GYRO_CONFIG_STATIC4    0x0D  // Sets squared bandwidth for gyroscope anti-aliasing filter (7:0).
#define ICM42688P_GYRO_CONFIG_STATIC5    0x0E  // Sets bitshift and upper bits for gyroscope anti-aliasing filter.
#define ICM42688P_GYRO_CONFIG_STATIC6    0x0F  // Gyroscope X-axis notch filter coefficient (factory trimmed).
#define ICM42688P_GYRO_CONFIG_STATIC7    0x10  // Gyroscope Y-axis notch filter coefficient (factory trimmed).
#define ICM42688P_GYRO_CONFIG_STATIC8    0x11  // Gyroscope Z-axis notch filter coefficient (factory trimmed).
#define ICM42688P_GYRO_CONFIG_STATIC9    0x12  // Configures gyroscope notch filter coefficients and selections (factory trimmed).
#define ICM42688P_GYRO_CONFIG_STATIC10   0x13  // Selects bandwidth for gyroscope notch filter.
#define ICM42688P_XG_ST_DATA             0x5F  // X-axis gyroscope self-test data (factory output).
#define ICM42688P_YG_ST_DATA             0x60  // Y-axis gyroscope self-test data (factory output).
#define ICM42688P_ZG_ST_DATA             0x61  // Z-axis gyroscope self-test data (factory output).
#define ICM42688P_TMSTVAL0               0x62  // Lower byte of timestamp value (7:0).
#define ICM42688P_TMSTVAL1               0x63  // Timestamp value (15:8).
#define ICM42688P_TMSTVAL2               0x64  // Upper bits of timestamp value (19:16).
#define ICM42688P_INTF_CONFIG4           0x7A  // Configures I3C bus mode and SPI 4-wire mode.
#define ICM42688P_INTF_CONFIG5           0x7B  // Sets function of pin 9 (INT2, FSYNC, CLKIN).
#define ICM42688P_INTF_CONFIG6           0x7C  // Enables I3C SM, IBI, SDR/DDR modes, and async timing.

/*BANK 2 REGISTERS */
#define ICM42688P_ACCEL_CONFIG_STATIC2   0x03  // Enables/disables accelerometer anti-aliasing filter and sets bandwidth.
#define ICM42688P_ACCEL_CONFIG_STATIC3   0x04  // Sets squared bandwidth for accelerometer anti-aliasing filter (7:0).
#define ICM42688P_ACCEL_CONFIG_STATIC4   0x05  // Sets bitshift and upper bits for accelerometer anti-aliasing filter.
#define ICM42688P_XA_ST_DATA             0x3B  // X-axis accelerometer self-test data (factory output).
#define ICM42688P_YA_ST_DATA             0x3C  // Y-axis accelerometer self-test data (factory output).
#define ICM42688P_ZA_ST_DATA             0x3D  // Z-axis accelerometer self-test data (factory output).

/*BANK 4 REGISTERS */
#define ICM42688P_APEX_CONFIG1           0x40  // Sets pedometer low-energy amplitude threshold and DMP power-save time.
#define ICM42688P_APEX_CONFIG2           0x41  // Sets pedometer amplitude threshold and step count detection window.
#define ICM42688P_APEX_CONFIG3           0x42  // Sets pedometer step detection threshold, step buffer timer, and high-energy threshold.
#define ICM42688P_APEX_CONFIG4           0x43  // Configures tilt wait time and sleep timeout for raise-to-wake/sleep.
#define ICM42688P_APEX_CONFIG5           0x44  // Defines mounting matrix for sensor orientation.
#define ICM42688P_APEX_CONFIG6           0x45  // Sets sleep gesture detection window delay.
#define ICM42688P_APEX_CONFIG7           0x46  // Sets tap detection jerk threshold and peak tolerance.
#define ICM42688P_APEX_CONFIG8           0x47  // Sets tap detection timing windows (TMAX, TAVG, TMIN).
#define ICM42688P_APEX_CONFIG9           0x48  // Sets sensitivity mode for accelerometer ODR (low power vs. high performance).
#define ICM42688P_ACCEL_WOM_X_THR        0x4A  // Sets X-axis Wake-on-Motion threshold (in mg).
#define ICM42688P_ACCEL_WOM_Y_THR        0x4B  // Sets Y-axis Wake-on-Motion threshold (in mg).
#define ICM42688P_ACCEL_WOM_Z_THR        0x4C  // Sets Z-axis Wake-on-Motion threshold (in mg).
#define ICM42688P_INT_SOURCE6            0x4D  // Routes step, tilt, wake, sleep, tap interrupts to INT1.
#define ICM42688P_INT_SOURCE7            0x4E  // Routes step, tilt, wake, sleep, tap interrupts to INT2.
#define ICM42688P_INT_SOURCE8            0x4F  // Routes FSYNC, PLL ready, data ready, FIFO, AGC interrupts to IBI.
#define ICM42688P_INT_SOURCE9            0x50  // Routes I3C protocol error, SMD, WOM interrupts to IBI.
#define ICM42688P_INT_SOURCE10           0x51  // Routes step, tilt, wake, sleep, tap interrupts to IBI.
#define ICM42688P_OFFSET_USER0           0x77  // Lower bits of X-axis gyro user offset.
#define ICM42688P_OFFSET_USER1           0x78  // Upper bits of Y/X gyro user offset.
#define ICM42688P_OFFSET_USER2           0x79  // Lower bits of Y-axis gyro user offset.
#define ICM42688P_OFFSET_USER3           0x7A  // Lower bits of Z-axis gyro user offset.
#define ICM42688P_OFFSET_USER4           0x7B  // Upper bits of X accel and Z gyro user offset.
#define ICM42688P_OFFSET_USER5           0x7C  // Lower bits of X-axis accel user offset.
#define ICM42688P_OFFSET_USER6           0x7D  // Lower bits of Y-axis accel user offset.
#define ICM42688P_OFFSET_USER7           0x7E  // Upper bits of Z/Y accel user offset.
#define ICM42688P_OFFSET_USER8           0x7F  // Lower bits of Z-axis accel user offset.

#endif /* APP_ICM42688P_APP_ICM42688P_REG_H_ */
