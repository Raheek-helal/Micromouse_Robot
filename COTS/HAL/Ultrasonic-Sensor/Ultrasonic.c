/*
 * Ultrasonic.c
 *
 *  Created on: Sep 16, 2024
 *      Author: Raheek_Helal
 */


#include <avr/io.h>
#include <util/delay.h>
#include "Ultrasonic_int.h"

#define ULTRASONIC_TRIGGER_PIN 2
#define ULTRASONIC_ECHO_PIN 3

void ultrasonic_init()
{
    // Configure trigger pin as output and echo pin as input
    DDRD |= (1 << ULTRASONIC_TRIGGER_PIN);
    DDRD &= ~(1 << ULTRASONIC_ECHO_PIN);
}

uint16_t ultrasonic_get_distance()
{
    uint16_t distance;
    uint32_t duration;

    // Send a 10us pulse on the trigger pin
    PORTD |= (1 << ULTRASONIC_TRIGGER_PIN);
    _delay_us(10);
    PORTD &= ~(1 << ULTRASONIC_TRIGGER_PIN);

    // Measure the duration of the pulse on the echo pin
    while (!(PIND & (1 << ULTRASONIC_ECHO_PIN))); // Wait for the rising edge
    TCNT1 = 0; // Reset Timer1
    TCCR1B |= (1 << CS11); // Start Timer1 with prescaler 8

    while (PIND & (1 << ULTRASONIC_ECHO_PIN)); // Wait for the falling edge
    duration = TCNT1; // Read Timer1 value

    // Calculate distance in cm based on the duration
    distance = duration / 58; // Conversion factor for ultrasonic sensor HC-SR04

    return distance;
}
