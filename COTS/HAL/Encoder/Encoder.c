/*
 * Encoder.c
 *
 *  Created on: Sep 10, 2024
 *      Author: Raheek_Helal
 */


#include <avr/io.h>
#include <util/delay.h>
#include "../../MCAL/DIO/DIO_int.h"
#include "Encoder.h"
#include <stdio.h>

// Initialize encoder pins
void encoder_init()
{
    // Set encoder pins as inputs
    DIO_vSetPinDir  ( DIO_PORTD, ENCODER_A_PIN, DIO_INPUT );
    DIO_vSetPinDir  ( DIO_PORTD, ENCODER_B_PIN, DIO_INPUT );

    // Enable pull-up resistors for encoder pins
    DIO_vSetPinVal  ( DIO_PORTD, ENCODER_A_PIN, DIO_HIGH );
    DIO_vSetPinVal  ( DIO_PORTD, ENCODER_B_PIN, DIO_HIGH );
}

// Read encoder position
int read_encoder_position()
{
    static uint8_t prev_state = 0;
    static int position = 0;

    uint8_t current_state = (PIND & ((1 << ENCODER_A_PIN) | (1 << ENCODER_B_PIN)));

    if (prev_state == 0b00 && current_state == 0b01) {
        position++;
    } else if (prev_state == 0b01 && current_state == 0b11) {
        position++;
    } else if (prev_state == 0b11 && current_state == 0b10) {
        position--;
    } else if (prev_state == 0b10 && current_state == 0b00) {
        position--;
    }

    prev_state = current_state;
    printf("Position Change: %d\n", position);

    return position;
}

/*
#include <avr/io.h>
#include <avr/interrupt.h>
#include "encoder.h"

volatile int encoder_count = 0;

void encoder_init()
{
    DDRA &= ~(1 << PA0);
    DDRA &= ~(1 << PA1);
    PORTA |= (1 << PA0) | (1 << PA1);
    GICR |= (1 << INT0) | (1 << INT1);
    MCUCR |= (1 << ISC01) | (1 << ISC11);
}

ISR(INT0_vect)
{
    if (ENCODER_PINB)
    {
        encoder_count++;
    }
    else
    {
        encoder_count--;
    }
}

ISR(INT1_vect) {
    if (ENCODER_PINA)
    {
        encoder_count++;
    }
    else
    {
        encoder_count--;
    }
}

float calculate_distance(float encoder_count, float counts_per_meter)
{
    return (float)encoder_count / counts_per_meter;
}
*/
