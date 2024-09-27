/*
 * Gyroscope.c
 *
 *  Created on: Sep 12, 2024
 *      Author: Raheek_Helal
 */

/*
#include "Gyroscope.h"
#include "../../MCAL/TWI/TWI_int.h"


#define GYRO_ADDRESS 0x68

void gyroscope_init() {
    // Initialize gyroscope settings if needed
}


int16_t read_gyroscope_data(uint8_t axis) {
    int16_t gyro_data;

    MTWI_u8SendStartCondition();
    MTWI_u8SendSlaveAddressRw(GYRO_ADDRESS, TWI_WRITE);
    MTWI_u8SendByte(axis);
    MTWI_u8SendRepeatedStartCondition();
    MTWI_u8SendSlaveAddressRw(GYRO_ADDRESS, TWI_READ);



    gyro_data = (int16_t)(MTWI_u8ReceiveByte(axis, TWI_ACK)) << 8;
    gyro_data |= MTWI_u8ReceiveByte(axis, TWI_NOT_ACK);

    MTWI_u8SendStopCondition();

    return gyro_data;
}
*/
/*
int16_t read_gyroscope_data(uint8_t address) {
    uint8_t gyro_data[2];

    // Start I2C communication
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));

    // Send device address with write bit
    TWDR = (GYRO_ADDRESS << 1) | 0;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));

    // Send register address to read from
    TWDR = address;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));

    // Repeat start condition for read
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));

    // Send device address with read bit
    TWDR = (GYRO_ADDRESS << 1) | 1;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));

    // Read gyroscope data
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    while (!(TWCR & (1 << TWINT)));
    gyro_data[0] = TWDR;

    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    gyro_data[1] = TWDR;

    // Stop I2C communication
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);

    // Combine the received data into a signed 16-bit value
    int16_t gyro_value = (gyro_data[0] << 8) | gyro_data[1];

    return gyro_value;
}
*/
/*
#include "Gyroscope.h"
#include "../../MCAL/TWI/TWI_int.h"

#define GYRO_ADDRESS 0x69

void gyroscope_init() {
    // Initialize gyroscope settings if needed
}

int16_t read_gyroscope_data(uint8_t axis) {
    int16_t gyro_data;

    MTWI_u8SendStartCondition();
    MTWI_u8SendSlaveAddressRw(GYRO_ADDRESS, TWI_WRITE);
    MTWI_u8SendByte(axis);
    MTWI_u8SendRepeatedStartCondition();
    MTWI_u8SendSlaveAddressRw(GYRO_ADDRESS, TWI_READ);

    gyro_data = (int16_t)(MTWI_u8ReceiveByte(&axis, TWI_ACK)) << 8;
    gyro_data |= MTWI_u8ReceiveByte(&axis, TWI_NOT_ACK);

    MTWI_u8SendStopCondition();

    return gyro_data;
}
*/
#include "Gyroscope.h"
#include "../../MCAL/TWI/TWI_int.h"

#define GYRO_ADDRESS 0x68

void gyroscope_init()
{
    // Initialize gyroscope settings if needed
}

int16_t read_gyroscope_data(uint8_t axis) {
    int16_t gyro_data;

    MTWI_u8SendStartCondition();
    MTWI_u8SendSlaveAddressRw(GYRO_ADDRESS, TWI_WRITE);
    MTWI_u8SendByte(axis);
    MTWI_u8SendRepeatedStartCondition();
    MTWI_u8SendSlaveAddressRw(GYRO_ADDRESS, TWI_READ);

    gyro_data = (int16_t)(MTWI_u8ReceiveByte(&axis, TWI_ACK)) << 8;
    gyro_data |= MTWI_u8ReceiveByte(&axis, TWI_NOT_ACK);

    MTWI_u8SendStopCondition();

    return gyro_data;
}
