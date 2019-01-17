#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "gpio.h"

#include "gpio_api.h"

int	  fd_gpio;

int open_gpio()
{
    fd_gpio = open("/dev/ti57xx_gpio", O_RDWR);
    if(fd_gpio!= -1 )
       printf("open fd_gpio = %d success\n",fd_gpio);
    return fd_gpio;
}

void close_gpio()
{
    close(fd_gpio);
}

int setDirection_gpio(int bank_id,int gpio_id, int gpio_direction )
{
     struct ti57xx_gpio_regs gpio_regs;

     gpio_regs.mode = GET_REGS;
     gpio_regs.bank = bank_id;
     gpio_regs.offset = GPIO_OE;

     if(ioctl(fd_gpio, TI57XX_GPIO_ACCESS_REGS, &gpio_regs) < 0) 
     {
				printf("GET_REGS mode ioctl failed\n");
				return -1;
     }       

     if ( gpio_direction == GPIO_OUT )
        gpio_regs.value  &= (~(1<<gpio_id ));
     if ( gpio_direction == GPIO_IN )
				gpio_regs.value  |= ( 1<<gpio_id );

     gpio_regs.mode = SET_REGS;
     if(ioctl(fd_gpio, TI57XX_GPIO_ACCESS_REGS, &gpio_regs) < 0) 
     {
				printf("SET_REGS mode ioctl failed\n");
				return -1;
     }
     return 0;
}
int write_gpio(int bank_id, int gpio_id, int output_value )
{

     struct ti57xx_gpio_regs gpio_regs;

     gpio_regs.mode = GET_REGS;
     gpio_regs.bank = bank_id;
     gpio_regs.offset = GPIO_DATAOUT;

     if(ioctl(fd_gpio, TI57XX_GPIO_ACCESS_REGS, &gpio_regs) < 0) 
     {
				printf("GET_REGS mode ioctl failed\n");
				return -1;
     }       

     if ( output_value == 0 )
        gpio_regs.value  &= (~(1<<gpio_id ));
     if ( output_value == 1 )
				gpio_regs.value  |= ( 1<<gpio_id );

     gpio_regs.mode = SET_REGS;
     if(ioctl(fd_gpio, TI57XX_GPIO_ACCESS_REGS, &gpio_regs) < 0) 
     {
				printf("SET_REGS mode ioctl failed\n");
				return -1;
     }
     return 0;
}
int read_gpio(int bank_id, int gpio_id )
{
     struct ti57xx_gpio_regs gpio_regs;
     int gpio_input;
     gpio_regs.mode = GET_REGS;
     gpio_regs.bank = bank_id;
     gpio_regs.offset = GPIO_DATAIN;

     if(ioctl(fd_gpio, TI57XX_GPIO_ACCESS_REGS, &gpio_regs) < 0) 
     {
				printf("GET_REGS mode ioctl failed\n");
				return -1;
     }       
     gpio_input = ( gpio_regs.value >> gpio_id ) & 1;

    // printf(" bank %d pin %d  input value is %d\n",bank_id,gpio_id,gpio_input);
     return gpio_input;
}


int read_gpio_reg(int bank_id,int offset)
{
     struct ti57xx_gpio_regs gpio_regs;

     gpio_regs.mode = GET_REGS;
     gpio_regs.bank = bank_id;//BANK0;
     gpio_regs.offset = offset;//GPIO_DATAOUT;

     if(ioctl(fd_gpio, TI57XX_GPIO_ACCESS_REGS, &gpio_regs) < 0) 
     {
				printf("GET_REGS mode ioctl failed\n");
				return -1;
     } 
     printf("the bank_id %d offset %x reg is %x\n",bank_id,offset,gpio_regs.value);
     return 1;
}


int write_gpio_reg(int bank_id,int offset,int value)
{
     struct ti57xx_gpio_regs gpio_regs;

     gpio_regs.mode = SET_REGS;
     gpio_regs.bank = bank_id;//BANK0;
     gpio_regs.offset = offset;//GPIO_DATAOUT;
     gpio_regs.value =  value;//0xF;

     if(ioctl(fd_gpio, TI57XX_GPIO_ACCESS_REGS, &gpio_regs) < 0) 
     {
				printf("SET_REGS mode ioctl failed\n");
				return -1;
     } 
     return 1;
}
