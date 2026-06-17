# Automotive Tilt Sensor 🚗📐
**Status:** 🚧 Work in Progress (B.Sc. Thesis Project)

## About the Project
A vehicle tilt indicator (inclinometer) project based on Inertial Measurement Unit (IMU) sensors. The system is designed to precisely measure and display the vehicle's tilt angles, which is crucial for off-road driving applications. This project is currently being developed as a B.Sc. Engineering thesis at the Gdańsk University of Technology.

## Technical Scope
The project combines hardware design with embedded software:
* **Hardware:** Custom PCB design integrating a microcontroller and an IMU sensor (e.g., Raspberry Pi Pico 2 & MPU-6050).
* **Firmware:** Software developed in C++ using the PlatformIO environment, responsible for data acquisition and sensor filtering.
* **Mechanics:** 3D printed custom enclosure and mounting hardware designed in CAD.

## Roadmap & Current Status
- [x] Project initialization and environment setup (PlatformIO / C++)
- [x] Initial IMU sensor communication implementation
- [ ] Electronic schematic design (KiCad)
- [ ] PCB layout design
- [ ] Implementation of filtering algorithms (e.g., Kalman / Complementary filter)
- [ ] 3D enclosure design

*Note: This repository is currently in an early development stage. Hardware documentation (schematics and PCB layouts) and 3D models will be added soon.*
