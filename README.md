# EasyCozyHome – IoT Home Monitoring & Control System

EasyCozyHome is an IoT project developed in the  
**Microcontroller and Basic Internet of Things Laboratory**.

The system uses Arduino to monitor temperature and soil moisture sensors,
control actuators via serial commands, and visualize real-time data using
Node-RED with remote access through ngrok.

## System Overview
- Reads temperature data using DS18B20 sensor
- Reads soil moisture level via analog sensor
- Controls LEDs and motors using serial commands
- Sends sensor data to Node-RED for real-time visualization
- Enables external access to the dashboard using ngrok
- Hardware behavior is simulated using Proteus

## Features
- Temperature monitoring (DS18B20)
- Soil moisture monitoring
- LED and motor control via serial communication
- Real-time IoT dashboard (Node-RED)
- Remote dashboard access using ngrok

## Project Structure

## Serial Commands
| Command | Function |
|------|---------|
| a / b | LED 1 ON / OFF |
| g / h | LED 2 ON / OFF |
| c / d | Motor 1 Forward / Reverse |
| e / f | Motor 2 Forward / Reverse |

## Data Output Format
- Temperature: `tp<value>` (°C)
- Soil Moisture: `sm<value>` (%)

## Tech Stack
- Microcontroller: Arduino  
- Language: C/C++ (Arduino)  
- Sensors: DS18B20, Soil Moisture Sensor  
- Simulation: Proteus  
- IoT Platform: Node-RED  
- Networking: ngrok  

## Notes
This project demonstrates basic embedded systems programming,
serial communication, and IoT integration with real-time data visualization.
