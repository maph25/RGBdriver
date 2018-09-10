#include "MK64F12.h"
#include "GPIO.h"
#include "RGB.h"
#include "NVIC.h"
#include "Delay.h"
#include "Bits.h"

#define GPIOB_OFF_CONST (0xFFFFFFFFU)
#define GPIOB_ON_CONST (0U)
#define DELAY_CONST 65000

gpio_pin_control_register_t pinControlRegisterGPIOBpin21 = GPIO_MUX1;
gpio_pin_control_register_t pinControlRegisterGPIOBpin22 = GPIO_MUX1;
gpio_pin_control_register_t pinControlRegisterGPIOCpin6 = GPIO_MUX1|GPIO_PE|GPIO_PS|INTR_FALLING_EDGE;

uint8 FlagPortC = FALSE;
uint8 FlagPortA = FALSE;

uint8_t INTERRUPT_sw2();
uint8_t INTERRUPT_sw3();

int main(void)
{
	uint8_t statePortC = 0;
	uint8_t statePortA = 0;

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

	for (;;)
	{
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

	Colors_t color = NO_COLOR;

		RGB_init();

		RGB_red_led_on_off(LED_ON);
		delay(DELAY);
		RGB_red_led_on_off(LED_OFF);
		delay(DELAY);
		RGB_blue_led_on_off(LED_ON);
		delay(DELAY);
		RGB_blue_led_on_off(LED_OFF);
		delay(DELAY);
		RGB_green_led_on_off(LED_ON);
		delay(DELAY);
		RGB_green_led_on_off(LED_OFF);
		delay(DELAY);
		RGB_yellow_led_on_off(LED_ON);
		delay(DELAY);
		RGB_yellow_led_on_off(LED_OFF);
		delay(DELAY);
		RGB_white_led_on_off(LED_ON);
		delay(DELAY);
		RGB_white_led_on_off(LED_OFF);
		delay(DELAY);
		RGB_purple_led_on_off(LED_ON);
		delay(DELAY);
		RGB_purple_led_on_off(LED_OFF);
		delay(DELAY);
		/**Sets the threshold for interrupts, if the interrupt has higher priority constant that the BASEPRI, the interrupt will not be attended*/
		NVIC_setBASEPRI_threshold(PRIORITY_11);
		/**Enables and sets a particular interrupt and its priority*/
		NVIC_enableInterruptAndPriotity(PORTC_IRQ,PRIORITY_10);
		/**Enables and sets a particular interrupt and its priority*/
		NVIC_enableInterruptAndPriotity(PORTA_IRQ,PRIORITY_4);

		EnableInterrupts;


	    while(1) {
	    	switch(color)
	    			{
	    			case GREEN:
	    				/**Turn leds off*/
	    				RGB_no_color();
	    				/**Green*/
	    				RGB_green();
	    				break;
	    			case BLUE:
	    				/**Turn leds off*/
	    				RGB_no_color();
	    				/**Blue*/
	    				RGB_blue();
	    				break;
	    			case PURPLE:
	    				/**Turn leds off*/
	    				RGB_no_color();
	    				/**Purple*/
	    				RGB_purple();
	    				break;
	    			case RED:
	    				/**Turn leds off*/
	    				RGB_no_color();
	    				/**Red*/
	    				RGB_red();
	    				break;
	    			case YELLOW:
	    				/**Turn leds off*/
	    				RGB_no_color();
	    				/**Yellow*/
	    				RGB_yellow();
	    				break;
	    			case NO_COLOR:
	    				RGB_no_color();
	    			}

	    return 0 ;
	}

uint8_t INTERRUPT_sw2(color){
	if(statePortC)
		{
		do
			{
			color++; /**Variable color increases its value*/
			}while(color <= NO_COLOR);
		}
	else{
		color = color;/**Varialble color keeps its previous value*/
	}

		statePortC = !statePortC;
		FlagPortC = FALSE;
		return color;
}

uint8_t INTERRUPT_sw3(color){
	if(statePortA)
		{
		do
		{
			color--; /**Variable color decreases its value*/
			}while(color <= NO_COLOR);
		}
	else
		color = color;/**Variable color keeps its value*/

		return color;
		statePortA = !statePortA;
		FlagPortA = FALSE;
	}
}

