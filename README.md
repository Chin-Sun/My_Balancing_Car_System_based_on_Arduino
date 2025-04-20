
[![my balance car](https://res.cloudinary.com/marcomontalbano/image/upload/v1654679836/video_to_markdown/images/youtube--kOZWG59ebCE-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://youtu.be/kOZWG59ebCE "my balance car")

# 🤖 The Integrated Design of Balancing Car System Based on Arduino

📅 **Project Duration:** November 2020 – December 2020  
🔗 **GitHub Repository:** [My_Balancing_Car_System_based_on_Arduino](https://github.com/Chin-Sun/My_Balancing_Car_System_based_on_Arduino)

## 📌 Overview

This project demonstrates the complete development of a **two-wheeled self-balancing car**, using an Arduino-based control system. The vehicle maintains upright balance using a PID control algorithm, enabling real-time adjustment of speed and orientation through sensor feedback.

---

## 🧩 Key Features

- **Self-balancing capability** using real-time feedback from motion sensors  
- **Speed and direction regulation** based on PID control  
- **Modular system architecture** allowing for easy hardware upgrades  
- **Compact and mobile design** using lightweight materials

---

## 🔧 Hardware Components

- **Core Controller:** Arduino Uno (ATmega328P)
- **Sensors:**
  - MPU6050 (Gyroscope + Accelerometer) for tilt angle detection
- **Actuators:**
  - Two DC motors with encoders for precise speed and direction control
  - L298N Motor Driver for bidirectional motor control
- **Power Supply:** 2-cell Li-ion battery pack with voltage regulator
- **Structure:** Lightweight chassis with two wheels and stabilizer mounts

---

## 💻 Software Implementation

- **Development Environment:** Arduino IDE  
- **Language:** C/C++ (Arduino-flavored)  
- **Key Functionalities:**
  - **Sensor Data Acquisition:** Real-time tilt angle calculated from MPU6050 using complementary filter
  - **PID Control Loop:** Calculates error in tilt angle and adjusts motor PWM output accordingly
  - **Motor Control:** Pulse-width modulation (PWM) used for speed regulation and direction reversal
  - **System Calibration:** Offset adjustment for sensor drift and tuning of PID gains (Kp, Ki, Kd)

---

## 🛠️ Development Process

1. **Component Selection:** Chose compatible sensors, drivers, and microcontroller based on control needs  
2. **Circuit Assembly:** Built the electrical connections on a breadboard and later transferred to soldered protoboard  
3. **Firmware Development:**
   - Wrote modular code for sensor reading, PID calculation, and motor control
   - Tested each module independently before integration
4. **Tuning & Testing:**
   - Performed empirical tuning of PID gains
   - Iteratively tested stability under different load and surface conditions
5. **Final Integration:** Assembled full system and conducted real-time balancing demos

---

## 📚 Core Skills Demonstrated

- **Embedded system development** using Arduino microcontroller  
- **Real-time control algorithms** (PID) for mechanical stabilization  
- **Sensor fusion** using accelerometer and gyroscope data  
- **Motor control** using PWM and H-bridge drivers  
- **System-level debugging** and incremental integration

---
