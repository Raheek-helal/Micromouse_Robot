/*
 * Motor_Driver.c
 *
 *  Created on: Sep 5, 2024
 *      Author: Raheek_Helal
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <avr/io.h>
#include "Motor_Driver.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/PWM/PWM.h"

// Motor control functions
void motors_init()
{
    // Initialize motor control pins as output on PORTC
    DIO_vSetPinDir(CONTROL_PORT, MOTOR_A_ENABLE_PIN, DIO_OUTPUT);
    DIO_vSetPinDir(CONTROL_PORT, MOTOR_A_IN1_PIN, DIO_OUTPUT);
    DIO_vSetPinDir(CONTROL_PORT, MOTOR_A_IN2_PIN, DIO_OUTPUT);
    DIO_vSetPinDir(CONTROL_PORT, MOTOR_B_ENABLE_PIN, DIO_OUTPUT);
    DIO_vSetPinDir(CONTROL_PORT, MOTOR_B_IN1_PIN, DIO_OUTPUT);
    DIO_vSetPinDir(CONTROL_PORT, MOTOR_B_IN2_PIN, DIO_OUTPUT);

    // Set PORTC pins as output for motor control
        //DDRC |= (1 << PC0) | (1 << PC1) | (1 << PC2) | (1 << PC3);

        // Initialize PWM on OC1A (PC5) and OC1B (PC6)
        //pwm_init();

    pwm_init();
}

void set_motor_speed(uint16_t speed/*, uint8_t motor*/)
{
	/*
    // Set the speed of the specified motor using PWM
	if (motor == MOTOR_A)
	{
		set_pwm_duty_cycle(pwm_A, speed); // Set PWM duty cycle for Motor A
	}
	else if (motor == MOTOR_B)
	{
		set_pwm_duty_cycle(pwm_B, speed); // Set PWM duty cycle for Motor B
	}*/
	set_pwm_duty_cycle(/*pwm_A,*/ speed);

}

void set_motor_direction(uint8_t direction, uint8_t motor)
{
    // Set the direction of the specified motor on PORTC
   /* if (motor == MOTOR_A)
    {
        if (direction == FORWARD)
        {
        	SET_BIT(CONTROL_PORT, MOTOR_A_IN1_PIN);
        	CLR_BIT(CONTROL_PORT, MOTOR_A_IN2_PIN);
        }
        else if (direction == BACKWARD)
        {
        	CLR_BIT(CONTROL_PORT, MOTOR_A_IN1_PIN);
          	SET_BIT(CONTROL_PORT, MOTOR_A_IN2_PIN);
        }
    }
    else if (motor == MOTOR_B)
    {
    	if (direction == FORWARD)
    	{
    		SET_BIT(CONTROL_PORT, MOTOR_B_IN1_PIN);
    		CLR_BIT(CONTROL_PORT, MOTOR_B_IN2_PIN);
    	}
    	else if (direction == BACKWARD)
    	{
    		CLR_BIT(CONTROL_PORT, MOTOR_B_IN1_PIN);
    		SET_BIT(CONTROL_PORT, MOTOR_B_IN2_PIN);
    }*/

	if (motor == MOTOR_A) {
	        if (direction == FORWARD) {
	            PORTC |= (1 << MOTOR_A_IN1_PIN);
	            PORTC &= ~(1 << MOTOR_A_IN2_PIN);
	        } else if (direction == BACKWARD) {
	            PORTC &= ~(1 << MOTOR_A_IN1_PIN);
	            PORTC |= (1 << MOTOR_A_IN2_PIN);
	        }
	    } else if (motor == MOTOR_B) {
	        if (direction == FORWARD) {
	            PORTC |= (1 << MOTOR_B_IN1_PIN);
	            PORTC &= ~(1 << MOTOR_B_IN2_PIN);
	        } else if (direction == BACKWARD) {
	            PORTC &= ~(1 << MOTOR_B_IN1_PIN);
	            PORTC |= (1 << MOTOR_B_IN2_PIN);
	        }
	    }
}

void move_both_motors(/*int16_t  speedA, uint16_t  speedB*/uint16_t  speed, uint8_t directionA, uint8_t directionB)
{
	//Enable the motors
	//DIO_vSetPinVal( PORTD, DDD5, DIO_HIGH);
	//DIO_vSetPinVal(PORTD, DDD4, DIO_HIGH);
	DIO_vSetPinVal( CONTROL_PORT, MOTOR_A_ENABLE_PIN, DIO_HIGH);
	DIO_vSetPinVal(CONTROL_PORT, MOTOR_B_ENABLE_PIN, DIO_HIGH);

    // Set speed and direction for both motors
    //set_motor_speed(speedA, MOTOR_A);
    //set_motor_speed(speedB, MOTOR_B);
	set_motor_speed(speed);
    set_motor_direction(directionA, MOTOR_A);
    set_motor_direction(directionB, MOTOR_B);
}

void stop_both_motors()
{
	    // Stop both motors by setting the enable pins to LOW
	    DIO_vSetPinVal(CONTROL_PORT, MOTOR_A_ENABLE_PIN, DIO_LOW);
	    DIO_vSetPinVal(CONTROL_PORT, MOTOR_B_ENABLE_PIN, DIO_LOW);
}

