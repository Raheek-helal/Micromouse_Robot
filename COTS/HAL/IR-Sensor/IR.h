/*
 * IR.h
 *
 *  Created on: Aug 31, 2024
 *      Author: Raheek_Helal
 */

#ifndef IR_H_
#define IR_H_

#include <avr/io.h>
#include <util/delay.h>

#define IR_SENSOR_PIN    PINB
#define IR_SENSOR_DDR    DDRB
#define IR_SENSOR_INPUT  PB0


void IR_sensor_init();
int IR_sensor_read();

#endif /* IR_H_ */
