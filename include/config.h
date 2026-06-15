#pragma once

// Konfiguracja sprzętowa I2C
#define MPU_ADDR 0x68
#define ACCEL_SCALE 16384.0f

// Ustawienia czasowe (w milisekundach)
#define IMU_READ_INTERVAL_MS 500  // Odświeżanie 50Hz