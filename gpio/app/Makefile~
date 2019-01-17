
CROSS_COMPILE = arm-linux-gnueabihf-

ARCH:=arm
CC:=$(CROSS_COMPILE)gcc

gpio_app:test_gpio.o gpio_api.o
	$(CC) $^ -o $@

%.o:%.c
	$(CC) -c $< -o $@

clean:
	rm -fr *.o gpio_app
	

