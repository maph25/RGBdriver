#include "MK64F12.h"
#include "GPIO.h"
#include "RGB.h"
#include "Delay.h"
#include "Bits.h"

#define GPIOB_OFF_CONST (0xFFFFFFFFU)
#define GPIOB_ON_CONST (0U)
#define DELAY_CONST 65000

gpio_pin_control_register_t pinControlRegisterGPIOBpin21 = GPIO_MUX1;
gpio_pin_control_register_t pinControlRegisterGPIOBpin22 = GPIO_MUX1;
gpio_pin_control_register_t pinControlRegisterGPIOCpin6 = GPIO_MUX1|GPIO_PE|GPIO_PS|INTR_FALLING_EDGE;


int main(void)
{
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

	while(1)
	{
		color = RGB_color_selector();
	    switch (color)
	    {
    		case GREEN:
    			RGB_no_color();
		    	RGB_green();
		    	break;
		    case BLUE:
		    	RGB_no_color();
		   		RGB_blue();
		   		break;
			case PURPLE:
				RGB_no_color();
    			RGB_purple();
	    		break;
			case RED:
				RGB_no_color();
				RGB_red();
				break;
			case YELLOW:
				RGB_no_color();
				RGB_red();
			default:
				RGB_no_color();
			break;
	    }
	}

    return 0 ;
}
