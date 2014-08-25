#include "stm32f4xx.h"

void init_GPIO(void){

    GPIO_InitTypeDef GPIO_InitStruct;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);

    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13;// | GPIO_Pin_13; // we want to configure all LED GPIO pins
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;      // we want the pins to be an output
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;  // this sets the GPIO modules clock speed
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;     // this sets the pin type to push / pull (as opposed to open drain)
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;   // this sets the pullup / pulldown resistors to be inactive
    GPIO_Init(GPIOG, &GPIO_InitStruct);             // this finally passes all the values to the GPIO_Init function which takes care of setting the corresponding bits.

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;        // we want to configure PA0
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;     // we want it to be an input
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;//this sets the GPIO modules clock speed
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;   // this sets the pin type to push / pull (as opposed to open drain)
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_DOWN;   // this enables the pulldown resistor --> we want to detect a high level
    GPIO_Init(GPIOA, &GPIO_InitStruct);           // this passes the configuration to the Init function which takes care of the low level stuff
}

int main(void)
{
    init_GPIO();


    }
}

void assert_failed(uint8_t* file, uint32_t line)
{
    //printf("Wrong parameters value: file");// %d on line %d\r\n", (int)file, (int)line);
    while(1)
    {}
}
