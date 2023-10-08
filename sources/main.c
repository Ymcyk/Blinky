#include <stdint.h>
#include "stm32f446xx.h"

#define LD2_ON GPIOA->BSRR = GPIO_BSRR_BS5
#define LD2_OFF GPIOA->BSRR = GPIO_BSRR_BR5

// PA5 - LD4

void ConfigureLD2();
void Delay();

int main()
{

	ConfigureLD2();

    /* Loop forever */
	while(1)
	{
		// Set LED on PA5
		LD2_ON;
		Delay();

		// Reset LED on PA5
		LD2_OFF;
		Delay();
	}
}

void ConfigureLD2()
{
	// Enable Clock for PORTD
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	// Configure GPIO Mode - Output
	GPIOA->MODER |= GPIO_MODER_MODE5_0; // It's default reset state. Not necessary.
	GPIOA->MODER &= ~(GPIO_MODER_MODE5_1);

	// Configure Output Mode - Push-pull
	GPIOA->OTYPER &= ~(GPIO_OTYPER_OT5); // It's default reset state. Not necessary.

	// Configure GPIO Speed - Low
	GPIOA->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED5); // Two bits together. It's default reset state. Not necessary.

	// Configure Pull-up/Pull-down - no PU/PD
	GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPD5); // It's default reset state. Not necessary.
}

void Delay()
{
	uint32_t i;

	for(i = 0; i < 999999; i++)
	{

	}
}