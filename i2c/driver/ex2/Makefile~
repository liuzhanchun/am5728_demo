KDIR = /home/develop/develop/linux-4.4.19
CROSS_COMPILE = arm-linux-gnueabihf-

PWD=$(shell pwd)

obj-m = i2c-driver.o

all:
	make -C $(KDIR) M=$(PWD) modules ARCH=arm CROSS_COMPILE=$(CROSS_COMPILE)
clean:
	rm -fr *.o *.mod.c *.ko
	rm Module.symvers
	rm modules.order

