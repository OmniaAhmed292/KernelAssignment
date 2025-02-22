#include <stdint.h>
#include "miros.h"
#include "bsp.h"

uint32_t stack_blinky1[40];
OSThread blinky1;
void main_blinky1() {
    while (1) {
        BSP_ledGreenOn();
        BSP_delay(1);
        BSP_ledGreenOff();
        BSP_delay(1);
    }
}

uint32_t stack_blinky2[40];
OSThread blinky2;
void main_blinky2() {
    while (1) {
        BSP_ledBlueOn();
        BSP_delay(1);
        BSP_ledBlueOff();
        BSP_delay(1);
    }
}

int main(void) {
    BSP_init();
    OS_init();

    /* fabricate Cortex-M ISR stack frame for blinky1 */
    OSThread_start(&blinky1,
                   &main_blinky1,
                   stack_blinky1, sizeof(stack_blinky1));

    /* fabricate Cortex-M ISR stack frame for blinky2 */
    OSThread_start(&blinky2,
                   &main_blinky2,
                   stack_blinky2, sizeof(stack_blinky2));

    //BSP_ledRedOn();
    while (1) {
    }

    //return 0;
}
