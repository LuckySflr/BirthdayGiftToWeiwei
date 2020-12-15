#include "test_board.h"
#include "music.h"
#include "led.h"
extern uchar songname_flag;
extern int rand(void);
extern void srand(int);
void main()
{
	uint rnum;
	WDTCN = 0xDE; // Disable watchdog timer
	WDTCN = 0xAD;
	Device_Init();
	song(START_SONGNAME);
	Timer_Init();
	EA = 1;	 //总中断打开
	TR0 = 1; //开定时器
	TR1 = 1;
	srand((uint)(TL0));
	startled();
	while (1)
	{
		rnum = rand() % 45;
		changeLED(rnum);
		if (!songname_flag) //如果确认是最后一个片段结束了
		{
			breathLED(ALLLED,2); //先做一组呼吸灯然后继续
			huangeready();
		}
	}
}

void Oscillator_Init(void)
{
	int i; // Software timer

	OSCICN |= 0x87; // Enable the missing clock detector
		// Internal Oscillator Enabled
		// Internal Oscillator typical frequency is 16MHz.

	// Initialize external crystal oscillator to use 11.0592 MHz crystal

	OSCXCN = 0x67; // Enable external crystal osc.
				   // Crystal Oscillator Mode
				   // f > 6.74MHz

	for (i = 0; i < 256; i++)
		; // Wait at least 1 ms，
	while (!(OSCXCN & 0x80))
		; // Wait for crystal osc to settle	（判断OSCXCN最高位是否为1）

	OSCICN |= 0x08;	 // Select external clock source
	OSCICN &= ~0x04; // Disable the internal osc.
}
void Port_IO_Init(void)
{

	XBR0 = 0x00; // Enable UART0,采用P00,P01
	XBR1 = 0x00; // no other interface at present.
	XBR2 = 0x40; // Weak Pull-ups Enabled，这里禁止弱上拉比较重要

	PRT0CF = 0xff;
	PRT1CF = 0xff; //	全部推挽输出
	PRT2CF = 0xff;
	PRT3CF = 0xff;

	P0 = 0xff;
	P1 = 0xff;
	P2 = 0xff;
	P3 = 0xff;
}

void Timer_Init(void)
{
	CKCON = 0x00; //Timer0&1&2 uses the 1/12system clock
	Timer0and1_Init();
	Timer2_Init();
	//定时器都还没有打开
}
void Device_Init(void)
{
	Oscillator_Init(); //振荡器初始化
	Port_IO_Init();	   //优先权交叉译码器初始化
}

void delayms(uint delaytime) //1ms误差2.09us
{
	uint a, b;
	for (b = delaytime; b > 0; b--)
		for (a = 3000; a > 0; a--)
			;
}
