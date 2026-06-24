#include "i2c_benchmark.h"

void Benchmark::process(ImuSensor& imu) {
    // 1. Sprawdzanie komend z terminala
    if (Serial.available() > 0) {
        String command = Serial.readStringUntil('\n'); 
        command.trim(); 
        
        if (command == "test" && !isTesting) {
            Serial.println("\n--- START BENCHMARKU (Trwa 10 sekund) ---");
            isTesting = true;             
            readCount = 0;                
            startTime = millis(); 
        }
    }

    // 2. Wykonywanie logiki testu
    if (isTesting) {
        imu.update(); 
        readCount++;  
        
        if (millis() - startTime >= 10000) { 
            Serial.print("Calkowita liczba odczytow (przez 10s): ");
            Serial.println(readCount);
            Serial.print("Srednia czestotliwosc odczytu: ");
            Serial.print(readCount / 10);
            Serial.println(" Hz");
            
            Serial.print("Sredni czas odczytu danych: ");
            Serial.print(10000.0 / readCount, 4); // Wymuszenie precyzji zmiennoprzecinkowej
            Serial.println(" ms\n");

            isTesting = false; 
        }
    }
}

bool Benchmark::isActive() {
    return isTesting;
}