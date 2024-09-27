/*
 * main.c
 *
 *  Created on: Sep 6, 2024
 *      Author: Raheek_Helal
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include <avr/io.h>
#include "../MCAL/PWM/PWM.h"
#include "../HAL/Motor-Driver/Motor_Driver.h"
#include "../HAL/Encoder/Encoder.h"
#include <util/delay.h>


int main(void)
{
	pwm_init();
	motors_init();
	DDRB = 0x01;

	while(1)
	{

		move_both_motors(100, BACKWARD, BACKWARD);
		//move_both_motors(0xFFFF, 0xFFFF, FORWARD, FORWARD);
		_delay_ms(2000);


		stop_both_motors();
		_delay_ms(2000);
		//move_both_motors(0xBFFF, 0xBFFF, FORWARD, FORWARD);
		//_delay_ms(2000);
		//stop_both_motors();
		//_delay_ms(2000);
		//move_both_motors(0x7FFF, 0x7FFF, FORWARD, FORWARD);
		//_delay_ms(2000);
		////stop_both_motors();
		//_delay_ms(2000);


		move_both_motors(50, BACKWARD, BACKWARD);
		//move_both_motors(0x7FFF, 0x7FFF, BACKWARD, BACKWARD);
		_delay_ms(2000);


		//stop_both_motors();
		//_delay_ms(2000);

	}


	return 0;
}

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



