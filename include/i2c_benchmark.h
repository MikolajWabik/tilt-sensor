#pragma once
#include <Arduino.h>
#include "imu_sensor.h"

class Benchmark {
public:
    void process(ImuSensor& imu); // Funkcja obsługująca komendy i sam test
    bool isActive();              // Funkcja zwracająca informację, czy test właśnie trwa

private:
    bool isTesting = false;
    unsigned long startTime = 0;
    unsigned long readCount = 0;
};