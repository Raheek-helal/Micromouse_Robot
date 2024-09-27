# Micromouse_Robot

Welcome to the **Micromouse Maze Solver**! This repository contains the code and drivers for a Micromouse robot designed to autonomously solve mazes using a flood fill algorithm. The project integrates multiple low-level drivers for hardware control and sensor integration, making it a robust solution for real-time maze-solving.

## Overview

This project was developed as part of my participation in the **IEEE Victories 3.0 Micromouse Competition**, organized by the **IEEE Mansoura Branch** and powered by the **National Telecom Regulatory Authority (NTRA)**. The Micromouse competition challenges small, autonomous robots to navigate through a maze as quickly as possible, using sensors, motor drivers, and efficient algorithms.

### Features
- **Flood Fill Algorithm**: A recursive algorithm that explores and solves mazes by systematically visiting and marking cells.
- **MCAL Drivers**: Includes **DIO (Digital I/O)**, **PWM**, and a custom **TWI (Two-Wire Interface)** driver for communication.
- **HAL Drivers**: Abstracts the hardware layers for sensors (IR, Ultrasonic) and actuators (motors, encoders, gyroscope).
- **Custom Libraries**: Provides utility libraries like `BIT_MATH.h` and `STD_TYPES.h` for bit manipulation and standard types in C.
- **Wall Detection**: Integrated IR and ultrasonic sensors to detect walls and optimize movement.
- **Backtracking**: The robot returns to the last unexplored cell after hitting dead-ends or fully exploring a path.

## Competition Background

This project was designed for the **Micromouse competition** at **IEEE Victories 3.0**, where I applied both software and hardware skills to create a fully autonomous robot capable of solving a maze. It provided a hands-on experience in robotics and embedded systems, specifically in writing drivers and controlling various hardware components.

### My Experience
As a competitor, I developed various **MCAL (Microcontroller Abstraction Layer)** and **HAL (Hardware Abstraction Layer)** drivers, alongside an efficient maze-solving algorithm. I worked on the following:

#### MCAL Drivers
- **DIO Driver**: Configured digital input/output for motor control and sensor inputs.
- **PWM Driver**: Pulse-width modulation for controlling motor speed.
- **TWI Driver**: I2C communication protocol driver to interface with sensors.

#### HAL Drivers
- **IR Sensor Driver**: To detect nearby walls and obstacles.
- **Ultrasonic Sensor Driver**: For distance measurement in the maze.
- **Motor Driver**: To control the motors for precise movement.
- **Encoder Driver**: To track wheel rotation and movement distance.
- **Gyroscope Driver**: For orientation and turning accuracy.

#### Libraries
- **BIT_MATH.h**: Utility functions for bit-level operations (e.g., setting, clearing, and toggling bits).
- **STD_TYPES.h**: Standard data types definitions for consistent coding.

## Algorithm Explanation

The Micromouse uses the **Flood Fill Algorithm** to navigate the maze efficiently. Here's how it works:
1. **Wall Detection**: The robot checks for walls in front, to the right, and to the left using IR and ultrasonic sensors.
2. **Recursive Exploration**: Moves forward if there is no wall, marking the cell as visited and recursively exploring neighboring cells.
3. **Backtracking**: If a dead-end or fully explored path is reached, the robot backtracks to the last unexplored cell.
4. **Path Optimization**: Once the maze is fully explored, the optimal path to the goal is determined and followed.

For more details, refer to the [`floodFill`](./path/to/floodFill) function.

## Drivers

### MCAL Drivers
- **DIO Driver**: Handles all digital input/output operations for controlling motors, sensors, and other peripherals.
- **PWM Driver**: Controls motor speed using pulse-width modulation.
- **TWI (I2C) Driver**: Manages communication between the microcontroller and external devices like sensors using the I2C protocol.

### HAL Drivers
- **IR Sensor Driver**: Reads data from IR sensors to detect nearby walls.
- **Ultrasonic Sensor Driver**: Uses ultrasonic waves to measure distances in front of the robot.
- **Motor Driver**: Controls the movement of the robot's motors (both speed and direction).
- **Encoder Driver**: Tracks the rotation of the wheels to measure distance traveled.
- **Gyroscope Driver**: Keeps track of the robot's orientation for accurate turns.

### Libraries
- **BIT_MATH.h**: Provides macros for bit manipulation, making it easier to manage individual bits.
- **STD_TYPES.h**: Defines common standard types like `u8`, `s16`, and `u32` to ensure consistency across the codebase.


## File Structure

```
├── src
│   ├── main.c           # Entry point for the Micromouse algorithm
│   ├── floodFill.c      # Core flood fill algorithm
│   ├── drivers          # Contains all the MCAL and HAL drivers
│   │   ├── dio.c        # DIO driver
│   │   ├── pwm.c        # PWM driver
│   │   ├── twi.c        # TWI driver
│   │   ├── ir_sensor.c  # IR sensor driver
│   │   ├── ultrasonic.c # Ultrasonic sensor driver
│   │   ├── motor.c      # Motor driver
│   │   ├── encoder.c    # Encoder driver
│   │   ├── gyroscope.c  # Gyroscope driver
├── include
│   ├── api.h            # API function declarations
│   ├── floodFill.h      # Flood fill function declarations
│   ├── drivers          # Header files for drivers
│   │   ├── dio.h
│   │   ├── pwm.h
│   │   ├── twi.h
│   │   ├── ir_sensor.h
│   │   ├── ultrasonic.h
│   │   ├── motor.h
│   │   ├── encoder.h
│   │   ├── gyroscope.h
├── libs
│   ├── BIT_MATH.h       # Bit manipulation utilities
│   ├── STD_TYPES.h      # Standard types for consistency
├── README.md            # Project overview (you are here)
├── Makefile             # Build instructions
└── LICENSE              # License for the project
```

## Future Enhancements

- **Additional Algorithms**: Implementing A* or Dijkstra algorithms for faster maze-solving.
- **Improved Sensor Fusion**: Enhancing accuracy by fusing data from multiple sensors (IR, ultrasonic, and gyroscope).
- **Hardware Optimization**: Further improving motor control and sensor accuracy for real-world performance.

## License

This project is licensed under the MIT License. See the [LICENSE](./LICENSE) file for details.
