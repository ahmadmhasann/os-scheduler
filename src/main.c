/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V01                                                               */
/* Date      : Jan 04,   2021                                                    */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "OS_interface.h"

#define OS_TEST_PIN_1 GPIOA,PIN0
#define OS_TEST_PIN_2 GPIOA,PIN1
#define OS_TEST_PIN_3 GPIOA,PIN2

void task1 (void);
void task2 (void);
void task3 (void);


void main(void)
{
	/*Initialize system clock*/
    RCC_vidInitSysClock();

    /*Enable PORTA clock*/
    GPIO_vidEnablePortClock(GPIOA);

    /*Set Pins direction*/
    GPIO_vidSetPinDirection(OS_TEST_PIN_1, OUTPUT_SPEED_2MHZ_PP);
    GPIO_vidSetPinDirection(OS_TEST_PIN_2, OUTPUT_SPEED_2MHZ_PP);
    GPIO_vidSetPinDirection(OS_TEST_PIN_3, OUTPUT_SPEED_2MHZ_PP);

    /*Initialize OS Scheduler*/
    OS_vidInit();

    /*Create task 1 with 0 	  ms first delay and 1000 ms period*/
    OS_u8CreateTask(1000, 0   , task1);
    /*Create task 2 with 1000 ms first delay and 2000 ms period*/
    OS_u8CreateTask(2000, 1000, task2);
    /*Create task 3 with 1000 ms first delay and 3000 ms period*/
    OS_u8CreateTask(3000, 1000, task3);

    /*Starting OS Scheduler*/
    OS_vidStart();

    /*Dispatch Tasks*/
    while (1)
    {
        OS_vidDispatchTasks();
    }
}

void task1 (void) {
    GPIO_u8TogglePinValue(OS_TEST_PIN_1);
}
void task2 (void) {
    GPIO_u8TogglePinValue(OS_TEST_PIN_2);
}
void task3 (void) {
    GPIO_u8TogglePinValue(OS_TEST_PIN_3);
}



