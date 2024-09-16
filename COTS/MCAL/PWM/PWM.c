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

void pwm_init()
{
   /* // Set Fast PWM mode with non-inverting mode for Timer/Counter1
	SET_BIT(TCCR1A, COM1A1);
	SET_BIT(TCCR1A, WGM10);
	SET_BIT(TCCR1A, WGM11);
	// Set prescaler to 1, start PWM generation
	SET_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1B, CS10);

    // Set OC1A (PB1) as output for PWM signal
    DIO_vSetPinDir(DIO_PORTB, DIO_PIN1, DIO_OUTPUT);*/

	// Configure Timer1 for PWM (16-bit)
		TCCR1A |= (1 << COM1A1) | (1 << COM1B1) | (1 << WGM11) | (1 << WGM10);
		TCCR1B |= (1 << WGM13) | (1 << WGM12) | (1 << CS11); // Prescaler 8
		ICR1 = 0xFFFF; // TOP value for 16-bit PWM

		// Set OCR1A and OCR1B as output pins
		    DDRD |= (1 << DDD5) | (1 << DDD4); // Set OC1A (pin D5) and OC1B (pin D4) as outputs
		   // DIO_vSetPinDir  ( DIO_PORTD, DIO_PIN5, DIO_OUTPUT );
		   // DIO_vSetPinDir  ( DIO_PORTD, DIO_PIN4, DIO_OUTPUT);
}

void set_pwm_duty_cycle(uint8_t channel, uint16_t  speed)
{
    // Set the PWM duty cycle to control motor speed
	if(channel == pwm_A)
	{
		DIO_vSetPortVal(OCR1A, speed); // Set the duty cycle (0-255)
	}
	else if(channel == pwm_B)
	{
		DIO_vSetPortVal(OCR1B, speed);
	}

}
