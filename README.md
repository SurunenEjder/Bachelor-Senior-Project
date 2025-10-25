# Autonomous Line-Following Robot with Obstacle Avoidance

![Robot Image](media/image1.png)

## 📋 Project Overview

This project involves the design and implementation of an autonomous line-following robot capable of obstacle detection and avoidance. The robot uses infrared sensors for line tracking and ultrasonic sensors for obstacle detection, providing a complete autonomous navigation system.

## 🎯 Key Features

- **Line Following**: Uses IR sensors to follow black lines on white surfaces
- **Obstacle Avoidance**: Ultrasonic sensor detects obstacles within 30cm range
- **Autonomous Navigation**: Capable of making turns and U-turns
- **Real-time Processing**: Arduino-based control system
- **Cost-effective Solution**: Built with affordable components

## 🛠️ Hardware Components

| Component | Quantity | Purpose |
|-----------|----------|---------|
| Arduino Uno | 1 | Main microcontroller |
| L298N Motor Driver | 1 | Motor control |
| IR Sensors | 3 | Line detection |
| Ultrasonic Sensor (HC-SR04) | 1 | Obstacle detection |
| DC Motors with Wheels | 2 | Movement |
| Caster Wheel | 1 | Balance and stability |
| 9V Batteries | 4 | Power supply |
| Robot Chassis | 1 | Body structure |

## 🔌 Circuit Diagram

The robot uses the following pin configuration:

- **IR Sensors**: Pins 10, 11, 12
- **Motor Driver**:
  - Right Motor: Pins 6, 7, 9
  - Left Motor: Pins 3, 4, 5
- **Ultrasonic Sensor**: Pins 2 (ECHO), 8 (TRIGGER)

## 💻 Software Requirements

- Arduino IDE
- NewPing Library
- Python (for initial Raspberry Pi implementation)

## 🚀 Installation & Setup

1. **Hardware Assembly**:
   - Mount all components on the chassis
   - Connect motors to L298N driver
   - Wire sensors to Arduino according to pin configuration
   - Connect power supply (9V batteries)

2. **Software Setup**:
   ```bash
   # Install required library
   # In Arduino IDE: Sketch -> Include Library -> Manage Libraries -> Search "NewPing"
