/*********************************************************************************/
/* Author    : Ahmed Hassan                                                      */
/* Version   : V01                                                               */
/* Date      : Jan 19,   2021                                                    */
/*********************************************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define HIGH_PIN     1
#define LOW_PIN      0
#define HIGH_PORT    0xFFFF
#define LOW_PORT     0

#define TRUE     1
#define FALSE    0

#define GPIOA    0
#define GPIOB    1
#define GPIOC    2

#define PIN0     0
#define PIN1     1
#define PIN2     2
#define PIN3     3
#define PIN4     4
#define PIN5     5
#define PIN6     6
#define PIN7     7
#define PIN8     8
#define PIN9     9
#define PIN10    10
#define PIN11    11
#define PIN12    12
#define PIN13    13
#define PIN14    14
#define PIN15    15

#define INPUT_ANLOG               0b0000
#define INPUT_FLOATING            0b0100
#define INPUT_PULLUP_PULLDOWN     0b1000

//For Speed 10MHZ
#define OUTPUT_SPEED_10MHZ_PP     0b0001
#define OUTPUT_SPEED_10MHZ_OD     0b0101
#define OUTPUT_SPEED_10MHZ_AFPP   0b1001
#define OUTPUT_SPEED_10MHZ_AFOD   0b1101

//For Speed 2MHZ
#define OUTPUT_SPEED_2MHZ_PP      0b0010
#define OUTPUT_SPEED_2MHZ_OD      0b0110
#define OUTPUT_SPEED_2MHZ_AFPP    0b1010
#define OUTPUT_SPEED_2MHZ_AFOD    0b1110

//For Speed 50MHZ
#define OUTPUT_SPEED_50MHZ_PP     0b0011
#define OUTPUT_SPEED_50MHZ_OD     0b0111
#define OUTPUT_SPEED_50MHZ_AFPP   0b1011
#define OUTPUT_SPEED_50MHZ_AFOD   0b1111


void GPIO_vidSetPinDirection          ( u8 Copy_u8Port, u8 Copy_u8Pin, u8 u8Copy_u8Mode  );
void GPIO_vidSetPinValue              ( u8 Copy_u8Port, u8 Copy_u8Pin, u8 u8Copy_u8Value );

u8   GPIO_u8GetPinDirection           ( u8 Copy_u8Port, u8 Copy_u8Pin      );
u8   GPIO_u8GetPinValue               ( u8 Copy_u8Port, u8 Copy_u8Pin      );
u16  GPIO_u16GetPortValue             ( u8 Copy_u8Port                     );

void GPIO_vidSetPortDirection         ( u8 Copy_u8Port, u8  Copy_u8Mode    );
void GPIO_vidSetPortValue             ( u8 Copy_u8Port, u16 Copy_u16Value  );

void GPIO_vidSetPortLowPinsDirection  ( u8 Copy_u8Port, u8  Copy_u8Mode    );
void GPIO_vidSetPortHighPinsDirection ( u8 Copy_u8Port, u8  Copy_u8Mode    );

void GPIO_vidSetPortLowPinsValue      ( u8 Copy_u8Port, u8  Copy_u8Value   );
void GPIO_vidSetPortHighPinsValue     ( u8 Copy_u8Port, u8  Copy_u8Value   );

u8   GPIO_u8TogglePinValue            ( u8 Copy_u8Port, u8 Copy_u8Pin      );

void GPIO_vidLockPin                  ( u8 Copy_u8Port, u8 Copy_u8Pin      );

void GPIO_vidEnablePortClock          ( u8 Copy_u8Port );

#endif