
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>


int main(int argc, char *argv[])
{
	int fd;
	unsigned char mode = SPI_MODE_0;
	struct spi_ioc_transfer xfer[2];
	unsigned char tx_buf[32];
	unsigned char rx_buf[32];
	int status;

	fd = open("/dev/spidev2.0", O_RDWR);
	if (fd < 0)
	{
		goto fail;
	}
	if (ioctl(fd, SPI_IOC_WR_MODE, &mode) < 0)
	{
		goto fail;
	}
	memset(xfer, 0, sizeof(xfer));
	memset(tx_buf, 0, sizeof(tx_buf));
	memset(rx_buf, 0, sizeof(rx_buf));

	tx_buf[0] = 0xAA;
	xfer[0].tx_buf = (unsigned long)tx_buf;
	xfer[0].len = 1;

	if (ioctl(fd,SPI_IOC_MESSAGE(1),xfer)<0)
	{
		goto fail;
	}
	close(fd);
	return 0;

fail:
	perror("spi test");
	exit(EXIT_FAILURE);

}
