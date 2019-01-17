#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>  

int main(int argc, char **argv)
{
    int key_fd = 0;
    int status = 0;
    struct input_event key_event;
   	key_fd = open("/dev/input/event0", O_RDONLY);
    if (key_fd < 0) {
        printf("%d: open error\n", __LINE__);
        return -1;
    }
    while (1) 
    {
        memset(&key_event, 0x00, sizeof( key_event));
        status = read(key_fd, &key_event, sizeof(key_event));
        if (status < 0) {
            printf("%d: read error\n", __LINE__);
            return -1;
        }
       printf("input_event.type =%d,input_event.code = %d ,input_event.value = %d\r\n",key_event.type,key_event.code,key_event.value);
      // sleep(1);
    }

    close (key_fd);

    return status;
}


//²Î¿¼£ºhttps://blog.csdn.net/ppslinux/article/details/77996900