/*
 * Gyro.c
 *
 *  Created on: Sep 16, 2024
 *      Author: Raheek_Helal
 */


/*
#include <avr/io.h>
#include <util/delay.h>
#include "../HAL/Gyroscope/Gyroscope.h"

int main()
{
    int16_t gyro_x, gyro_y, gyro_z;

    DDRB |= (1 << PB0) | (1 << PB1);

    gyroscope_init();

    while (1)
    {
        gyro_x = read_gyroscope_data(0x01);
        gyro_y = read_gyroscope_data(0x02);
        gyro_z = read_gyroscope_data(0x03);

        // Adjust LED behavior based on gyroscope readings
        if (gyro_x > 500)
        {  // Adjust threshold as per calibration
            PORTB |= (1 << PB0);
        }
        else
        {
            PORTB &= ~(1 << PB0);
        }

        if (gyro_y < -500)
        { // Adjust threshold as per calibration
            PORTB |= (1 << PB1);
        }
        else
        {
            PORTB &= ~(1 << PB1);
        }

        _delay_ms(100); // Adjust delay based on the desired responsiveness
    }

    return 0;
}
*/

/*
int main() {
    // Initialize gyroscope and LEDs
    DDRB |= (1 << PB0) | (1 << PB1);

    while (1)
    {
        int16_t gyro_x = read_gyroscope_data(0x01); // Read gyro data for X-axis

        // Adjust LED behavior based on gyro_x reading
        if (gyro_x > 500)
        {
            PORTB |= (1 << PB0);  // Turn on LED connected to PB0
        }
        else
        {
            PORTB &= ~(1 << PB0); // Turn off LED connected to PB0
        }

        _delay_ms(100); // Adjust delay based on the desired responsiveness
    }

    return 0;
}
*/

/*

#include <avr/io.h>
#include <util/delay.h>
#include "../HAL/Gyroscope/Gyroscope.h"

int main()
{
    int16_t gyro_x, gyro_y, gyro_z;

    // Set PB0 and PB1 as output pins
    DDRB |= (1 << PB0) | (1 << PB1);

    gyroscope_init();

    while (1)
    {
    	//PORTB = 0X01;
        gyro_x = read_gyroscope_data(0x01); // Example: read X axis
        gyro_y = read_gyroscope_data(0x02); // Example: read Y axis
        gyro_z = read_gyroscope_data(0x03); // Example: read Z axis

        // Check gyroscope data and set/clear PB0 and PB1 based on conditions
        if (gyro_x > 1000) {
            PORTB |= (1 << PB0); // Set PB0
            _delay_ms(10);
        } else {
            PORTB &= ~(1 << PB0); // Clear PB0
            _delay_ms(10);
        }

        if (gyro_y < -1000) {
            PORTB |= (1 << PB1); // Set PB1
            _delay_ms(10);
        } else {
            PORTB &= ~(1 << PB1); // Clear PB1
            _delay_ms(10);
        }

        _delay_ms(1000); // Add a delay before the next read
    }

    return 0;
}

 */
/*
#include <avr/io.h>
#include <util/delay.h>
#include "../HAL/Gyroscope/Gyroscope.h"

int main() {
    int16_t gyro_x, gyro_y, gyro_z;

    // Set PB0 and PB1 as output pins
    DDRB |= (1 << PB0) | (1 << PB1);

    gyroscope_init(); // Initialize the gyroscope

    while (1) {
        // Read gyroscope data for X, Y, and Z axes
        gyro_x = read_gyroscope_data(0x01); // Example: read X axis
        gyro_y = read_gyroscope_data(0x02); // Example: read Y axis
        gyro_z = read_gyroscope_data(0x03); // Example: read Z axis

        // Control LEDs based on gyroscope readings
        if (gyro_x > 1000) {
            PORTB |= (1 << PB0); // Set PB0
        } else {
            PORTB &= ~(1 << PB0); // Clear PB0
        }

        if (gyro_y < -1000) {
            PORTB |= (1 << PB1); // Set PB1
        } else {
            PORTB &= ~(1 << PB1); // Clear PB1
        }

        _delay_ms(100); // Add a delay before the next read
    }

    return 0;
}
 */
