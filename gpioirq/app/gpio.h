#ifndef _GPIO_H_
#define _GPIO_H_

/*
#define pr_emerg(fmt, ...) \
        printk(KERN_EMERG pr_fmt(fmt), ##__VA_ARGS__)
#define pr_alert(fmt, ...) \
        printk(KERN_ALERT pr_fmt(fmt), ##__VA_ARGS__)
#define pr_crit(fmt, ...) \
        printk(KERN_CRIT pr_fmt(fmt), ##__VA_ARGS__)
#define pr_err(fmt, ...) \
        printk(KERN_ERR pr_fmt(fmt), ##__VA_ARGS__)
#define pr_warning(fmt, ...) \
        printk(KERN_WARNING pr_fmt(fmt), ##__VA_ARGS__)
#define pr_notice(fmt, ...) \
        printk(KERN_NOTICE pr_fmt(fmt), ##__VA_ARGS__)
#define pr_info(fmt, ...) \
        printk(KERN_INFO pr_fmt(fmt), ##__VA_ARGS__)
#define pr_cont(fmt, ...) \
	printk(KERN_CONT fmt, ##__VA_ARGS__)

*/


#define TI57XX_GPIO_ACCESS_REGS		_IOWR('G', 1, struct ti57xx_gpio_regs)
#define u32 unsigned int


struct ti57xx_gpio_regs {
  u32 bank;
	u32 offset;
	u32 value;
	u32 mode;
};

#define SET_REGS	1
#define GET_REGS	2


/* ------------------------------------------------------------------------ *
 *  Direction                                                               *
 * ------------------------------------------------------------------------ */
#define BANK0                   0
#define BANK1                   1   
#define BANK2                   2  
#define BANK3                   3 
#define BANK4                   4 
#define BANK5                   5 
#define BANK6                   6 
#define BANK7                   7 
#define BANK8                   8 

#define GPIO_SIZE		(0x198)

#define GP1_BASE            0x4AE10000
#define GP2_BASE            0x48055000
#define GP3_BASE            0x48057000
#define GP4_BASE            0x48059000
#define GP5_BASE            0x4805B000
#define GP6_BASE            0x4805D000
#define GP7_BASE            0x48051000
#define GP8_BASE            0x48053000



#define GPIO_REVISION        (0x0  )
#define GPIO_SYSCONFIG       (0x10 ) 
#define GPIO_EOI             (0x20 )
#define GPIO_IRQSTATUS_RAW_0 (0x24 )
#define GPIO_IRQSTATUS_RAW_1 (0x28 )

#define GPIO_IRQSTATUS_0     (0x2C )
#define GPIO_IRQSTATUS_1     (0x30 )

#define GPIO_IRQSTATUS_SET_0 (0x34 )
#define GPIO_IRQSTATUS_SET_1 (0x38 )
#define GPIO_IRQSTATUS_CLR_0 (0x3C )
#define GPIO_IRQSTATUS_CLR_1 (0x40 )
#define GPIO_SYSSTATUS       (0x114)
#define GPIO_CTRL            (0x130)
#define GPIO_OE              (0x134)
#define GPIO_DATAIN          (0x138)
#define GPIO_DATAOUT         (0x13C)
#define GPIO_LEVELDETECT0    (0x140)
#define GPIO_LEVELDETECT1    (0x144)
#define GPIO_RISINGDETECT    (0x148)
#define GPIO_FALLINGDETECT   (0x14C)
#define GPIO_DEBOUNCENABLE   (0x150)
#define GPIO_DEBOUNCINGTIME  (0x154)
#define GPIO_CLEARDATAOUT    (0x190)
#define GPIO_SETDATAOUT      (0x194)

#endif





