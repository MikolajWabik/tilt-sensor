#include "imu_sensor.h"
#include "config.h"
#include <Wire.h>
#include <math.h>

void ImuSensor::init() {
    Wire.begin(); 
    Wire.setClock(400000); //Wymuszenie trybu FAST dla I2C (~400 kHz)

    Wire.beginTransmission(MPU_ADDR);
    Wire.write(0x6B); // Rejestr zasilania PWR_MGMT_1
    Wire.write(0);    // Wybudzenie czujnika
    Wire.endTransmission(true);
    
    delay(100); // Dajemy układowi ułamek sekundy na stabilizację zasilania
}

void ImuSensor::readRawData(int16_t &rawX, int16_t &rawY, int16_t &rawZ) {
    Wire.beginTransmission(MPU_ADDR);
    Wire.write(0x3B); 
    Wire.endTransmission(false);
    
    Wire.requestFrom(MPU_ADDR, 6, true);
    if (Wire.available() == 6) {
        rawX = Wire.read() << 8 | Wire.read();
        rawY = Wire.read() << 8 | Wire.read();
        rawZ = Wire.read() << 8 | Wire.read();
    }
}

void ImuSensor::calculateAngles(float gX, float gY, float gZ) {
    // atan2 zwraca wynik w radianach, dlatego mnożymy przez (180 / PI), aby otrzymać stopnie
    roll = atan2(gY, gZ) * (180.0f / PI);
    pitch = atan2(-gX, sqrt(gY * gY + gZ * gZ)) * (180.0f / PI);
}

void ImuSensor::update() {
    int16_t rawX = 0, rawY = 0, rawZ = 0;
    
    // 1. Pobierz surowe wartości rejestrów
    readRawData(rawX, rawY, rawZ);
    
    // 2. Przelicz na przyspieszenie ziemskie [g]
    float gX = rawX / ACCEL_SCALE;
    float gY = rawY / ACCEL_SCALE;
    float gZ = rawZ / ACCEL_SCALE;
    
    // 3. Wlicz trygonometrię
    calculateAngles(gX, gY, gZ);
}

float ImuSensor::getPitch() {
    return pitch;
}

float ImuSensor::getRoll() {
    return roll;
}