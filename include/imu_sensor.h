#pragma once
#include <Arduino.h>

class ImuSensor {
public:
    void init();
    void update();
    
    float getPitch();
    float getRoll();

private:
    float pitch = 0.0f;
    float roll = 0.0f;
    
    void readRawData(int16_t &rawX, int16_t &rawY, int16_t &rawZ);
    void calculateAngles(float gX, float gY, float gZ);
};