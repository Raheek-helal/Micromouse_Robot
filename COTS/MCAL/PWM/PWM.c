/*
 * PWM.c
 *
 *  Created on: Sep 5, 2024
 *      Author: Raheek_Helal
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <avr/io.h>
#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/PWM/PWM.h"
/*
void pwm_init()
{
    // Set Fast PWM mode with non-inverting mode for Timer/Counter1
	SET_BIT(TCCR1A, COM1A1);
	SET_BIT(TCCR1A, WGM10);
	SET_BIT(TCCR1A, WGM11);
	// Set prescaler to 1, start PWM generation
	SET_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1B, CS10);

    // Set OC1A (PB1) as output for PWM signal
    DIO_vSetPinDir(DIO_PORTB, DIO_PIN1, DIO_OUTPUT);

/*	// Configure Timer1 for PWM (16-bit)
		TCCR1A |= (1 << COM1A1) | (1 << COM1B1) | (1 << WGM11) | (1 << WGM10);
		TCCR1B |= (1 << WGM13) | (1 << WGM12) | (1 << CS11); // Prescaler 8
		ICR1 = 0xFFFF; // TOP value for 16-bit PWM

		// Set OCR1A and OCR1B as output pins
		    DDRD |= (1 << DDD5) | (1 << DDD4); // Set OC1A (pin D5) and OC1B (pin D4) as outputs
		   // DIO_vSetPinDir  ( DIO_PORTD, DIO_PIN5, DIO_OUTPUT );
		   // DIO_vSetPinDir  ( DIO_PORTD, DIO_PIN4, DIO_OUTPUT);*/
/*}

void set_pwm_duty_cycle(/*uint8_t channel, *//* uint16_t  speed)
{
    // Set the PWM duty cycle to control motor speed
	/*if(channel == pwm_A)
	{
		DIO_vSetPortVal(OCR1A, speed); // Set the duty cycle (0-255)
	}
	else if(channel == pwm_B)
	{
		DIO_vSetPortVal(OCR1B, speed);
	}*/
/*
	uint16_t duty_cycle = ((uint32_t)speed * 255) / 100;
	OCR1A = duty_cycle;

}
*/

void pwm_init()
{
    // Set Fast PWM mode with non-inverting mode for Timer/Counter1
    SET_BIT(TCCR1A, COM1A1);
    SET_BIT(TCCR1A, WGM10);
    SET_BIT(TCCR1A, WGM11);

    // Set prescaler to 1, start PWM generation
    SET_BIT(TCCR1B, WGM12);
    SET_BIT(TCCR1B, CS10);

    // Set OC1A (PB1) as output for PWM signal
    DIO_vSetPinDir(DIO_PORTB, DIO_PIN1, DIO_OUTPUT);

    // Ensure that Timer/Counter1 is set up correctly for PWM
    if ((TCCR1A & ((1 << WGM10) | (1 << WGM11))) == ((1 << WGM10) | (1 << WGM11)) &&
        (TCCR1B & (1 << WGM12)) == (1 << WGM12) &&
        (TCCR1B & ((1 << CS10) | (1 << CS11) | (1 << CS12))) == (1 << CS10)) {
        // PWM initialization successful
    } else {
        // Error in PWM initialization
        // Add error handling code here

    	PORTB = 0x01;
    }
}

void set_pwm_duty_cycle(uint16_t speed)
{
    // Calculate the duty cycle based on the speed (0-100 mapped to 0-255)
    uint16_t duty_cycle = (speed * 255) / 100;

    // Check if duty cycle is within valid range (0-255)
    if (duty_cycle > 255) {
        duty_cycle = 255; // Cap duty cycle at maximum value
    }

    // Set the duty cycle for motor control
    OCR1A = duty_cycle;
}
