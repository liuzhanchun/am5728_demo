
#define GPIO_IN                 1
#define GPIO_OUT                0


int open_gpio();
void close_gpio();

int setDirection_gpio(int bank_id,int gpio_id, int gpio_direction );
int write_gpio(int bank_id, int gpio_id, int output_value );
int read_gpio(int bank_id, int gpio_id );

int read_gpio_reg(int bank_id,int offset);
int write_gpio_reg(int bank_id,int offset,int value);
