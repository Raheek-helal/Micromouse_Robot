/*
 * PWM.h
 *
 *  Created on: Sep 5, 2024
 *      Author: Raheek_Helal
 */

#ifndef MCAL_PWM_PWM_H_
#define MCAL_PWM_PWM_H_

#define pwm_A  0
#define pwm_B  1

void pwm_init();
void set_pwm_duty_cycle(/*uint8_t channel,*/ uint16_t speed);

#endif /* MCAL_PWM_PWM_H_ */
