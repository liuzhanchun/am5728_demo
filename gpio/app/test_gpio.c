#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <sys/time.h>


#include "gpio.h"
#include "gpio_api.h"


void set_gpio()
{
    //led gpio direction
    setDirection_gpio(3,13,GPIO_OUT);
    setDirection_gpio(3,14,GPIO_OUT);
    setDirection_gpio(3,20,GPIO_OUT);
    setDirection_gpio(3,23,GPIO_OUT);  
    setDirection_gpio(3,24,GPIO_OUT);

   //gpio direction


}

int main()
{  
    int ret=0;

    open_gpio();

    set_gpio();

    int i=0;
    while(i<100)
    {
         i++;
         printf("%dth\n",i);
         write_gpio(3,19,0);
         write_gpio(3,20,0);
         sleep(1);
         write_gpio(3,19,1);
         write_gpio(3,20,1);
         sleep(1);
    }
 
    close_gpio();
    return 0;
}
