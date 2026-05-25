#include <Arduino.h>
#include <Wire.h>

const int MPU_ADDR = 0x68; // Adres I2C MPU-6050
const float ACCEL_SCALE = 16384.0;

void setup() {
  Serial.begin(115200);
  
  Wire.begin(); // Odpalamy I2C na domyślnych pinach (4 i 5)

  // Wybudzanie MPU-6050
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B); // Rejestr PWR_MGMT_1
  Wire.write(0);    // Ustawienie na 0 (wybudzenie)
  Wire.endTransmission(true);

  delay(2000);
  Serial.println("MPU6050 zainicjalizowany (Arduino Framework)!");
}

void loop() {
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B); // Start od rejestru ACCEL_XOUT_H
  Wire.endTransmission(false);
  
  Wire.requestFrom(MPU_ADDR, 6, true); // Żądanie 6 bajtów

  if (Wire.available() == 6) {
    int16_t rawX = Wire.read() << 8 | Wire.read();
    int16_t rawY = Wire.read() << 8 | Wire.read();
    int16_t rawZ = Wire.read() << 8 | Wire.read();

    float gX = rawX / ACCEL_SCALE;
    float gY = rawY / ACCEL_SCALE;
    float gZ = rawZ / ACCEL_SCALE;

    Serial.print("Akceleracja [g]: X: "); Serial.print(gX);
    Serial.print(" | Y: "); Serial.print(gY);
    Serial.print(" | Z: "); Serial.println(gZ);
  }

  delay(200);
}