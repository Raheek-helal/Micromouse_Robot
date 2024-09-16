/*
 * Gyroscope.h
 *
 *  Created on: Sep 12, 2024
 *      Author: Raheek_Helal
 */

#ifndef HAL_GYROSCOPE_GYROSCOPE_H_
#define HAL_GYROSCOPE_GYROSCOPE_H_


#include <avr/io.h>

void gyroscope_init(void);
int16_t read_gyroscope_data(uint8_t axis);


#endif /* HAL_GYROSCOPE_GYROSCOPE_H_ */
