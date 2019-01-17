#ifndef _I2C_H
#define _I2C_H

struct atg_val {
	short accelx;
	short accely;
	short accelz;
	short temp;
	short gyrox;
	short gyroy;
	short gyroz;
};

#define MPU6050_MAGIC	'm'

#define MPU6050_GET_VAL	_IOR(MPU6050_MAGIC, 0, struct atg_val)




#endif

