/*
 * main.c
 *
 *  Created on: Sep 6, 2024
 *      Author: Raheek_Helal
 */
/*
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include <avr/io.h>
#include "../MCAL/PWM/PWM.h"
#include "../HAL/Motor-Driver/Motor_Driver.h"
#include "../HAL/Encoder/Encoder.h"
#include <util/delay.h>
*/
/*
int main(void)
{
	pwm_init();
	motors_init();

	while(1)
	{
		move_both_motors(0xFFFF, 0xFFFF, FORWARD, FORWARD);
		_delay_ms(2000);
		stop_both_motors();
		_delay_ms(2000);
		//move_both_motors(0xBFFF, 0xBFFF, FORWARD, FORWARD);
		//_delay_ms(2000);
		//stop_both_motors();
		//_delay_ms(2000);
		move_both_motors(0x7FFF, 0x7FFF, FORWARD, FORWARD);
		_delay_ms(2000);
		//stop_both_motors();
		//_delay_ms(2000);
		//move_both_motors(0xFFFF, 0x7FFF, BACKWARD, BACKWARD);
		//_delay_ms(2000);
		//stop_both_motors();
		//_delay_ms(2000);

	}


	return 0;
}
*/
/*
int main()
{
	// Initialize motor
	motors_init();
    // Initialize encoder
    encoder_init();

    int previous_position = 0;

    // Main loop
    while (1)
    {
    	DDRA = 0xFF;
    	//run the motors
    	move_both_motors(0xFFFF, 0xFFFF, FORWARD, FORWARD);
		_delay_ms(2000);

        // Read encoder position
        int position = read_encoder_position();

        // Check if the position has changed
        if (position != previous_position)
        {
            // Update the previous position
            previous_position = position;

            // Perform actions based on encoder position
            //PORTA = 0x01;
            TOG_BIT(PORTA,7);
			//_delay_ms(1000);

        }
        // Add a delay to the control loop
        _delay_ms(10); // Delay for 10 milliseconds
    }

    return 0;
}
*/
/*
#include <stdio.h>
#include <util/delay.h>
#include "../MCAL/PWM/PWM.h"
#include "../HAL/Motor-Driver/Motor_Driver.h"
#include "../HAL/Encoder/Encoder.h"
#include <avr/interrupt.h>

int main()
{
	DDRB = 0xFF;
	// Initialize motor
	motors_init();
	// Initialize encoder
    encoder_init();
    sei();

    float distance_traveled = 0;
    const float counts_per_meter = 1000;

    while (1)
    {

    	//write the motor move here
    	move_both_motors(0xFFFF, 0xFFFF, FORWARD, FORWARD);
    	_delay_ms(2000);

        distance_traveled = calculate_distance(encoder_count, counts_per_meter);
        _delay_ms(100);

        //write your logic code here
        if(distance_traveled >= 1.0)
        {
        	PORTB = 0x01;
        	_delay_ms(2000);
        }
    }

    return 0;
}
*/



#include <avr/io.h>
#include <util/delay.h>
#include "../HAL/Ultrasonic-Sensor/Ultrasonic_int.h"

int main() {
    uint16_t distance_cm;

    // Set PB0 and PB1 as output pins
    DDRB |= (1 << PB0) | (1 << PB1);

    // Initialize ultrasonic sensor
    ultrasonic_init();

    while (1) {
        // Read distance from ultrasonic sensor
        distance_cm = ultrasonic_get_distance();

        // Control PB0 and PB1 based on distance readings
        if (distance_cm < 10) {
            PORTB |= (1 << PB0);  // Set PB0
            PORTB &= ~(1 << PB1); // Clear PB1
        } else if (distance_cm >= 10 && distance_cm < 20) {
            PORTB &= ~(1 << PB0); // Clear PB0
            PORTB |= (1 << PB1);  // Set PB1
        } else {
            PORTB |= (1 << PB0);  // Set PB0
            PORTB |= (1 << PB1);  // Set PB1
        }

        _delay_ms(100); // Add a delay before the next read
    }

    return 0;
}
