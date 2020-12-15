#ifndef __TEST_BOARD_H
#define __TEST_BOARD_H

#define uchar unsigned char
#define uint unsigned int

//void delayus(uint xus);   //100usÎó²î 3us
void delayms(uint delaytime);

void Oscillator_Init(void);
void Port_IO_Init(void);
void Device_Init(void);
void Timer_Init(void);

#endif // __TEST_BOARD_H