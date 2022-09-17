/*
 * I2C_PROTOCOL.h
 *
 * Created: 15/08/2022 9:48:25 SA
 *  Author: Administrator
 */

#ifndef _I2C_PROTOCOL_H_
#define _I2C_PROTOCOL_H_

#include <avr/io.h>

#define F_SCL 100000
#define _SB(bit) (1 << bit)
#define ACK 1
#define NACK 0

void I2C_Init();
void I2C_Start();
void I2C_Stop();
void I2C_Write(uint8_t dataSend);
uint8_t I2C_Read(int sig);

#endif /*_I2C_PROTOCOL_H_*/
