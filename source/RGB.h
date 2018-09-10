/*
 * RGB.h
 *
 *  Created on: 04/09/2018
 *      Author: jlpe
 */

#ifndef RGB_H_
#define RGB_H_

#include "stdint.h"
#include "Bits.h"
#include "GPIO.h"


#define LED_ON (0x01u)
#define LED_OFF (0x00)

#define BLUE_LED_PORT  GPIO_B
#define RED_LED_PORT   GPIO_B
#define GREEN_LED_PORT GPIO_E

#define SW2_PORT GPIO_C
#define SW3_PORT GPIO_A


#define BLUE_LED_PIN  BIT21
#define RED_LED_PIN   BIT22
#define GREEN_LED_PIN BIT26

#define SW2_PIN BIT6
#define SW3_PIN BIT4

#define SW2 (0x01u)
#define SW3 (0x02u)
#define SW_MASK (0x03)

#define COLOR_LIMIT (0x06u)


typedef enum {GREEN, BLUE, PURPLE, RED, YELLOW, WHITE, NO_COLOR} Colors_t;


void RGB_init(void);

Colors_t RGB_color_selector(void);

void RGB_red_led_on_off(uint8_t on_off);
void RGB_blue_led_on_off(uint8_t on_off);
void RGB_green_led_on_off(uint8_t on_off);

void RGB_yellow_led_on_off(uint8_t on_off);
void RGB_white_led_on_off(uint8_t on_off);
void RGB_purple_led_on_off(uint8_t on_off);


void RGB_red(void);
void RGB_blue(void);
void RGB_green(void);
void RGB_purple(void);
void RGB_yellow(void);
void RGB_no_color(void);


#endif /* RGB_H_ */
