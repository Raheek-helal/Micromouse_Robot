/*
 * IR.c
 *
 *  Created on: Aug 31, 2024
 *      Author: Raheek_Helal
 */
#include "IR.h"

void IR_sensor_init() {
    // Set the IR sensor pin as input
    IR_SENSOR_DDR &= ~(1 << IR_SENSOR_INPUT);
}

int IR_sensor_read() {
    // Read the value from the IR sensor pin
    if (IR_SENSOR_PIN & (1 << IR_SENSOR_INPUT))
    {
        return 1; // IR sensor detected an object
    }
    else
    {
        return 0; // No object detected by IR sensor
    }
}
