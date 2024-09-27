/*
 * Ultra.c
 *
 *  Created on: Sep 16, 2024
 *      Author: Raheek_Helal
 */



/*
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
            PORTB &= ~(1 << PB0); // Clear PB0
        	PORTB &= ~(1 << PB1); // Clear PB1
        }

        _delay_ms(100); // Add a delay before the next read
    }

    return 0;
}
*/
