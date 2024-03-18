#include "main.h"
#include "daughterboard.h"
#include "milis.h"
#include "stm8s.h"

#include "delay.h"
#include <stdio.h>
//#include <uart1.h>


void setup(void) {
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); // taktovani MCU na 16MHz


    GPIO_Init(LED1_PORT, LED1_PIN,GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(LED2_PORT, LED2_PIN,GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(LED3_PORT, LED3_PIN,GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(LED4_PORT, LED4_PIN,GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(LED5_PORT, LED5_PIN,GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(LED6_PORT, LED6_PIN,GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(LED7_PORT, LED7_PIN,GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(S1_PORT, S1_PIN, GPIO_MODE_IN_PU_NO_IT);

    init_milis();
    //init_uart1();
}

uint8_t cube[7] = {
        0b00100000,
        0b10000001,
        0b10100001,
        0b11000011,
        0b11100011,
        0b11011011};


int main(void) {
    uint8_t number = 0;
    uint8_t time = 0;
    uint8_t i = 0;
    setup();
    
    
    while (1) {
        if (milis() - time >= 5) {
            if (PUSH(S1)) {
                number++;
                i++;
                if (i > 6) {
                    i = 0;
                }
            } else {
                GPIO_Write(GPIOG, cube[number]);
            }
            time = milis();
        }
    }
}


/*-------------------------------  Assert -----------------------------------*/
#include "__assert__.h"