/*
 * Motor_Driver.h
 *
 *  Created on: Sep 5, 2024
 *      Author: Raheek_Helal
 */

#ifndef HAL_MOTOR_DRIVER_MOTOR_DRIVER_H_
#define HAL_MOTOR_DRIVER_MOTOR_DRIVER_H_

#include <avr/io.h>

// Control Port
#define CONTROL_PORT  DIO_PORTC

// Define motors
#define MOTOR_A   0
#define MOTOR_B   1

// Define directions
#define FORWARD  0
#define BACKWARD 1

// Define motor control pins for Motor A
#define MOTOR_A_ENABLE_PIN 0
#define MOTOR_A_IN1_PIN 1
#define MOTOR_A_IN2_PIN 2

// Define motor control pins for Motor B
#define MOTOR_B_ENABLE_PIN 3
#define MOTOR_B_IN1_PIN 4
#define MOTOR_B_IN2_PIN 5

// Motor control functions
void motors_init(void);

void set_motor_speed(uint16_t  speed, uint8_t motor);

void set_motor_direction(uint8_t direction, uint8_t motor);

void move_both_motors(uint16_t  speedA, uint16_t  speedB, uint8_t directionA, uint8_t directionB);

void stop_both_motors(void);



#endif /* HAL_MOTOR_DRIVER_MOTOR_DRIVER_H_ */
