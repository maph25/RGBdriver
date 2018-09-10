#include "MK64F12.h"
#include "GPIO.h"
#include "Delay.h"
#include "Bits.h"

#define GPIOB_OFF_CONST (0xFFFFFFFFU)
#define GPIOB_ON_CONST (0U)
#define DELAY_CONST 65000

gpio_pin_control_register_t pinControlRegisterGPIOBpin21 = GPIO_MUX1;
gpio_pin_control_register_t pinControlRegisterGPIOBpin22 = GPIO_MUX1;
gpio_pin_control_register_t pinControlRegisterGPIOCpin6 = GPIO_MUX1|GPIO_PE|GPIO_PS|INTR_FALLING_EDGE;


int main(void) {


	GPIO_clock_gating(GPIO_B);
	GPIO_clock_gating(GPIO_C);

	GPIO_pin_control_register(GPIO_B,BIT21,&pinControlRegisterGPIOBpin21);
	GPIO_pin_control_register(GPIO_B,BIT22,&pinControlRegisterGPIOBpin22);
	GPIO_pin_control_register(GPIO_C,BIT6,&pinControlRegisterGPIOCpin6);


	GPIO_write_port(GPIO_B, GPIOB_OFF_CONST);

	GPIO_data_direction_pin(GPIO_B,GPIO_OUTPUT,BIT21);
	GPIO_data_direction_pin(GPIO_B,GPIO_OUTPUT,BIT22);
	GPIO_data_direction_pin(GPIO_C,GPIO_INPUT,BIT6);

	GPIO_write_port(GPIO_B, GPIOB_ON_CONST);
	delay(DELAY_CONST);
	GPIO_write_port(GPIO_B, GPIOB_OFF_CONST);


	for (;;) {

		if(!GPIO_read_pin(GPIO_C, BIT6))
		{
			GPIO_clear_pin(GPIO_B, BIT21);
			delay(DELAY_CONST);
			GPIO_set_pin(GPIO_B, BIT21);
			delay(DELAY_CONST);
			GPIO_clear_pin(GPIO_B, BIT22);
			delay(DELAY_CONST);
			GPIO_set_pin(GPIO_B, BIT22);
		}

		}

    return 0 ;
}
