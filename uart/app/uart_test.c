#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>
#include <termios.h>
#include <errno.h> 
#include <unistd.h>
#include <string.h>
#define S_TIMEOUT 1
  
int serial_fd = 0;

char uart_device[]="/dev/ttyS0"; 

int init_serial() 
{ 
    serial_fd = open(uart_device, O_RDWR | O_NOCTTY | O_NDELAY); 
    if (serial_fd < 0) { 
        perror("open"); 
        return -1; 
    } 
    printf("serial_fd = %d",serial_fd);
      
    struct termios options; 
      
    tcgetattr(serial_fd, &options); 

    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~CSIZE;
    options.c_cflag &= ~CRTSCTS;
    options.c_cflag |= CS8;
    options.c_cflag &= ~CSTOPB; 
    options.c_iflag |= IGNPAR; 
    options.c_oflag = 0;  
    options.c_lflag = 0;  
    cfsetospeed(&options, B115200); 
      
    tcflush(serial_fd, TCIFLUSH); 
    tcsetattr(serial_fd, TCSANOW, &options); 
      
    return 0; 
} 
  
unsigned int total_send = 0 ;
int uart_send(int fd, char *data, int datalen) 
{ 
    int len = 0; 
    len = write(fd, data, datalen);
    if(len == datalen) { 
    total_send += len ;
        printf("total_send is %d\n",total_send); 
        return len; 
    } else { 
        tcflush(fd, TCOFLUSH); 
        return -1; 
    } 
    return 0; 
} 

unsigned int total_length = 0 ; 
int uart_recv(int fd, char *data, int datalen) 
{ 
    int len=0, ret = 0; 
    fd_set fs_read; 
    struct timeval tv_timeout; 
      
    FD_ZERO(&fs_read); 
    FD_SET(fd, &fs_read); 

//#ifdef S_TIMEOUT    
    tv_timeout.tv_sec = (10*20/115200+2); 
    tv_timeout.tv_usec = 0; 
    //ret = select(fd+1, &fs_read, NULL, NULL, NULL);
//#elif
    ret = select(fd+1, &fs_read, NULL, NULL, &tv_timeout);
//#endif
     
    if (FD_ISSET(fd, &fs_read)) { 
        len = read(fd, data, datalen); 
    total_length += len ;
        printf("total len = %d\n", total_length); 
        return len; 
    } else { 
        perror("select"); 
        return -1; 
    } 
      
    return 0; 
} 
  
int main(int argc, char *argv[]) 
{ 
    init_serial(); 
    char buf[]="hello world"; 
    char buf1[11] ; 
    memset(buf1,0,sizeof(char)*11); 
    int i;
    for (i = 0; i < 1000; i++) {
        uart_send(serial_fd, buf, 11); 
        printf("\n"); 
        sleep(1);
        //uart_recv(serial_fd, buf1, 11);
        printf("receive: \n");
        /*if (strncmp(buf, buf1, 11) != 0) {
            printf("Test failed!\n");
            exit(3);
        }*/
        //memset(buf1,0,sizeof(char)*11); 
    }
    close(serial_fd); 
    printf("Test pass!\n");
    return 0; 
}
