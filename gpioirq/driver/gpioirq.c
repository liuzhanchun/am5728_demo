#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/ioctl.h>
#include <linux/uaccess.h>
#include <linux/of.h>
#include <linux/interrupt.h>
#include <linux/platform_device.h>
#include <linux/poll.h>



#define DEVICE_NAME "gpioirq"  
struct resource *key2_res;
static DECLARE_WAIT_QUEUE_HEAD(buttons_wait); //声明、初始化等待队列buttons_wait
static int knob_ready = 0;  
static int knob_value = 0;  
static struct cdev chrdev_cdev;  
static dev_t chrdev_devno;
#define BUTTON_MAJOR 	246  
static struct class	*ti57xx_gpio_class;


static int knob_open(struct inode *inode, struct file *filp)
{
	knob_ready = 0;  //旋轮键值准备好标志
	knob_value = 0;  //旋轮键值

	return 0;
}
static int knob_read(struct file *file, char *buffer, size_t count, loff_t *ppos)
{
	int data;
	
	if (knob_ready == 0)
	{
		return  - EAGAIN;
	}
	knob_ready = 0;
	copy_to_user(buffer, &knob_value, sizeof(knob_value));  //使用copy_to_user把键值送到用户空间
	data =0;
	return sizeof(data);
}

static unsigned int knob_select(struct file *file, struct poll_table_struct *wait)
{
	if (knob_ready)
	{
		return 1;
	}
	//POLLIN，设备可以无阻塞读
	poll_wait(file, &buttons_wait, wait); //把当前进程放入一个等待对列
	return 0;
	//使进程调用poll或select系统调用时，阻塞直到buttons_wait等待队列唤醒
} 
static irqreturn_t fskey_handler(int irq, void *dev_id)
{
	if (irq == key2_res->start)
		{
			knob_value = 100;
			knob_ready = 1;
			wake_up_interruptible(&buttons_wait); //唤醒buttons_wait等待对列中的进程		
			//printk("K2 pressed\n");
		}
		

	return IRQ_HANDLED;
}
static struct file_operations chrdev_fops = {  
    .owner      =   THIS_MODULE,  
    //.ioctl      =   chrdev_ioctl,  
    //.release    =   chrdev_release,
		.open= knob_open,	
		.poll= knob_select,
		/*poll方法是poll和select这两个系统调用的后端实现,是在用户空间程序执行poll或select系统调用时被调用,
		这两个系统调用可用来查询设备是否可读或可写，或是否处理某种特殊状态。
		这两个系统调用是可阻塞的，直至设备变为可读或可写状态为止*/
		.read= knob_read,  
};
static int fskey_probe(struct platform_device *pdev)
{

	int ret = 0;
	//方式1
	// alloc character device number  
	ret = alloc_chrdev_region(&chrdev_devno, 0, 1, DEVICE_NAME);  
	if (ret < 0) {
		pr_err(DEVICE_NAME ": could'nt allocate the character driver\n");
		return -1;
	} 
	//printk(KERN_ALERT " major:%d minor:%d\n", MAJOR(chrdev_devno), MINOR(chrdev_devno));  
      
	cdev_init(&chrdev_cdev, &chrdev_fops);  
  chrdev_cdev.owner = THIS_MODULE;  
	// add a character device  
  ret = cdev_add(&chrdev_cdev, chrdev_devno, 1);  
	if (ret < 0) {
		pr_err(DEVICE_NAME ": cdev add failed\n");
		unregister_chrdev_region(chrdev_devno, 1);
		return -1;
	}
    
  ti57xx_gpio_class = class_create(THIS_MODULE, DEVICE_NAME);
	if (!ti57xx_gpio_class) {
		pr_err(DEVICE_NAME ":failed to add device to sys fs\n");
		goto ERROR_CLASS;
	}
	device_create(ti57xx_gpio_class, NULL, chrdev_devno,NULL, DEVICE_NAME);
	//方式二	   
  //ret = register_chrdev(BUTTON_MAJOR, DEVICE_NAME, &chrdev_fops); //注册按键设备
	key2_res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
	if (!key2_res ) {
		pr_err(DEVICE_NAME ": platform_get_resource failed");	
		goto ERROR_REG;
	}
	ret = request_irq(key2_res->start, fskey_handler, key2_res->flags & IRQF_TRIGGER_MASK, "key2", NULL);
	if (ret<0){
		pr_err(DEVICE_NAME ": request_irq failed");	
		goto ERROR_REG;
	}
	pr_info(DEVICE_NAME ":*************************\n");   
	return 0;

ERROR_REG:
	device_destroy(ti57xx_gpio_class, chrdev_devno);
	class_destroy(ti57xx_gpio_class);
ERROR_CLASS:
	cdev_del(&chrdev_cdev);
	unregister_chrdev_region(chrdev_devno, 1);
	return -1;
}

static int fskey_remove(struct platform_device *pdev)
{
	free_irq(key2_res->start, NULL);
	device_destroy(ti57xx_gpio_class, chrdev_devno);
	class_destroy(ti57xx_gpio_class);
	cdev_del(&chrdev_cdev);
	unregister_chrdev_region(chrdev_devno, 1);
	
	pr_info(DEVICE_NAME ": Exiting TI81XX_GPIO module\n");
	
	return 0;
}

static const struct of_device_id fskey_of_matches[] = {
	{ .compatible = "my_gpio_irq", },
	{ /* sentinel */ }
};

MODULE_DEVICE_TABLE(of, fskey_of_matches);

struct platform_driver fskey_drv = { 
	.driver = { 
		.name    = "my_gpio_irq",
		.owner   = THIS_MODULE,
		.of_match_table = of_match_ptr(fskey_of_matches),
	},  
	.probe   = fskey_probe,
	.remove  = fskey_remove,
};

module_platform_driver(fskey_drv);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("lzc");
MODULE_DESCRIPTION("A simple device driver for gpioirq on AM5728 board");
