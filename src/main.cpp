#include <Arduino.h>
#include "config.h"
#include "imu_sensor.h"
#include "i2c_benchmark.h"

// Inicjalizacja obiektów
ImuSensor imu;
Benchmark benchmark;

unsigned long lastImuTime = 0;

void setup() {
    Serial.begin(115200);
    imu.init();
    
    Serial.println("System gotowy. Rozpoczynam wyliczanie katow...");
    Serial.println("Wpisz komende 'test' w terminalu, aby sprawdzic maksymalna predkosc odczytu.");
}

void loop() {
    // 1. Przekazujemy sterowanie do modułu testowego
    benchmark.process(imu);

    // 2. Jeśli test jest w toku, przerywamy pętlę, żeby nie śmiecić w terminalu zwykłymi kątami
    if (benchmark.isActive()) {
        return; 
    }

    // 3. --- STANDARDOWA PRACA URZĄDZENIA ---
    unsigned long currentTime = millis();
    if (currentTime - lastImuTime >= IMU_READ_INTERVAL_MS) {
        lastImuTime = currentTime;
        
        imu.update(); 
        
        Serial.print("Pitch (Przod/Tyl): ");
        Serial.print(imu.getPitch());
        Serial.print(" st. | Roll (Boki): ");
        Serial.print(imu.getRoll());
        Serial.println(" st.");
    }
}