/*
 * Encoder.h
 *
 *  Created on: Sep 10, 2024
 *      Author: Raheek_Helal
 */

#ifndef HAL_ENCODER_ENCODER_H_
#define HAL_ENCODER_ENCODER_H_


// Define pins for encoder connections
#define ENCODER_A_PIN PD2
#define ENCODER_B_PIN PD3

void encoder_init(void);
int read_encoder_position(void);

/*
#define ENCODER_PINA (PINA & (1 << PA0))
#define ENCODER_PINB (PINA & (1 << PA1))

extern volatile int encoder_count;


void encoder_init();
float calculate_distance(float encoder_count, float counts_per_meter);
*/

#endif /* HAL_ENCODER_ENCODER_H_ */
