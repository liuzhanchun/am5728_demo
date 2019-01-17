#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <time.h>


int main(int argv,char *argc[])
{
	int fdKnob =  open("/dev/gpioirq", O_RDWR);

	printf("fdKnob=%d\n",fdKnob);

 	timeval tv;
	int m = 1;
	while(1)
	{

  		fd_set rds;
        FD_ZERO(&rds);
        FD_SET( fdKnob, &rds);
        tv.tv_sec = 1;//CONFIG#5#等待中断的超时时间
        tv.tv_usec = 0;
        m = select(fdKnob + 1, &rds, NULL, NULL, &tv); //阻塞直到可读
        if (m > 0 && FD_ISSET ( fdKnob, &rds))
        {
            int data = 0;
            read(fdKnob, (signed char*)&data, 4);
            if (data != 0)
            {
				printf("data=%d\n",data);
			}
		}


	}
	return 0;
}
