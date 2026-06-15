#include <Arduino.h>
#include "config.h"
#include "imu_sensor.h"

// Stworzenie obiektu czujnika
ImuSensor imu;

// Zmienna do śledzenia upływu czasu (zamiast delay)
unsigned long lastImuTime = 0;

void setup() {
    Serial.begin(115200);
    imu.init();
    
    Serial.println("System gotowy. Rozpoczynam wyliczanie katow...");
}

void loop() {
    unsigned long currentTime = millis();

    // Odczyt co określony czas (20ms)
    if (currentTime - lastImuTime >= IMU_READ_INTERVAL_MS) {
        lastImuTime = currentTime;
        
        // Funkcja update robi wszystko pod maską (I2C + Matematyka)
        imu.update(); 
        
        // Wyświetlanie wyników w terminalu
        Serial.print("Pitch (Przod/Tyl): ");
        Serial.print(imu.getPitch());
        Serial.print(" st. | Roll (Boki): ");
        Serial.print(imu.getRoll());
        Serial.println(" st.");
    }
}