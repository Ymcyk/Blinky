#include <stdint.h>
#include <stdbool.h>
#include <stm32f446xx.h>

#include "stm32f4xx.h"

const uint32_t systick_value = 16000000 / 1000; // one milisecond
volatile uint32_t systick_counter = 0;

void configurate();
void delay(uint32_t time);
void set_led(bool status);

/*
input:
	PA8
	PB10
	PB4
	PB5
output:
	PB3
	PA10
	PA2
	PA3
*/

int main() {
	// Configuration
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	SysTick_Config(systick_value);

	// Out PC0
	GPIOC->MODER |= GPIO_MODER_MODE0_0;
	GPIOC->MODER &= ~(GPIO_MODER_MODE0_1);
	GPIOC->OTYPER &= ~(GPIO_OTYPER_OT0);
	GPIOC->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR0);
	GPIOC->PUPDR &= ~(GPIO_PUPDR_PUPD0_0);
	GPIOC->PUPDR |= GPIO_PUPDR_PUPD0_1;

	GPIOC->MODER |= GPIO_MODER_MODE1_0;
	GPIOC->MODER &= ~(GPIO_MODER_MODE1_1);
	GPIOC->OTYPER &= ~(GPIO_OTYPER_OT1);
	GPIOC->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR1);
	GPIOC->PUPDR &= ~(GPIO_PUPDR_PUPD1_0);
	GPIOC->PUPDR |= GPIO_PUPDR_PUPD1_1;

	GPIOC->MODER |= GPIO_MODER_MODE2_0;
	GPIOC->MODER &= ~(GPIO_MODER_MODE2_1);
	GPIOC->OTYPER &= ~(GPIO_OTYPER_OT2);
	GPIOC->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR2);
	GPIOC->PUPDR &= ~(GPIO_PUPDR_PUPD2_0);
	GPIOC->PUPDR |= GPIO_PUPDR_PUPD2_1;

	GPIOC->MODER |= GPIO_MODER_MODE3_0;
	GPIOC->MODER &= ~(GPIO_MODER_MODE3_1);
	GPIOC->OTYPER &= ~(GPIO_OTYPER_OT3);
	GPIOC->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR3);
	GPIOC->PUPDR &= ~(GPIO_PUPDR_PUPD3_0);
	GPIOC->PUPDR |= GPIO_PUPDR_PUPD3_1;

	// LED - PA5
	GPIOA->MODER |= GPIO_MODER_MODE5_0;
	GPIOA->MODER &= ~(GPIO_MODER_MODE5_1);
	GPIOA->OTYPER &= ~(GPIO_OTYPER_OT5);
	GPIOA->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR5);
	GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPD5_0);

	GPIOC->BSRR |= GPIO_BSRR_BS0;
	GPIOC->BSRR |= GPIO_BSRR_BS1;
	GPIOC->BSRR |= GPIO_BSRR_BS2;
	GPIOC->BSRR |= GPIO_BSRR_BS3;

	for (;;) {
		delay(1000);
		GPIOA->BSRR |= GPIO_BSRR_BS5;
		
		delay(1000);
		GPIOA->BSRR |= GPIO_BSRR_BR5;
	}
}

void ahb1_conf();
void systick_conf();
void led_conf();
void keyboard_conf();

void configurate() {
	ahb1_conf();
	systick_conf();
	led_conf();
	keyboard_conf();
}

void delay(uint32_t time) {
	const uint32_t start_time = systick_counter;

	while (systick_counter < (start_time + time)) {

	}
}

void set_led(bool status) {
	if (status) {
		GPIOA->BSRR |= GPIO_BSRR_BS5;
	} else {
		GPIOA->BSRR |= GPIO_BSRR_BR5;
	}
}

void ahb1_conf() {
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
}

void systick_conf() {
	SysTick_Config(systick_value);
}

void led_conf() {
	GPIOA->MODER |= GPIO_MODER_MODE5_0;
	GPIOA->MODER &= ~(GPIO_MODER_MODE5_1);
	GPIOA->OTYPER &= ~(GPIO_OTYPER_OT5);
	GPIOA->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR5);
	GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPD5);
}

void keyboard_conf() {
	GPIOA->MODER |= GPIO_MODER_MODE8_0;
	GPIOA->MODER &= ~(GPIO_MODER_MODE8_1);
	GPIOA->OTYPER &= ~(GPIO_OTYPER_OT8);
	GPIOA->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR8);
	GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPD8);
	// GPIOA->PUPDR |= GPIO_PUPDR_PUPD3_1;
}

void SysTick_Handler(void) {
	++systick_counter;
}
