#define GPIO_BASE 0x20200000UL

#define GPFSEL4 (GPIO_BASE + 0x10)

#define GPSET1 (GPIO_BASE + 0x20)

#define GPCLR1 (GPIO_BASE + 0x2C)

void  main(void) {
	volatile unsigned long int* func_select_4 = (unsigned long int*) GPFSEL4;
	volatile unsigned long int* gpio_set_1 = (unsigned long int*) GPSET1;
	volatile unsigned long int* gpio_clear_1 = (unsigned long int*) GPCLR1;

	*func_select_4 |= (1<<21);
	
	volatile unsigned int timer;

	while (1) {
		for (timer = 0; timer < 30000; timer++) 
			;
		
		*gpio_set_1 |= (1<<16);

		for (timer = 0; timer < 30000; timer++) 
			;

		*gpio_clear_1 |= (1<<16);
	}
}
