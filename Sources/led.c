#include "led.h"

uint Count_cycle;
uint Count_duty;
extern uint rand(void);
void Timer2_Init(void)
{
	//Timer2����
	PT2 = 1;	  //����TIMER2���ж����ȼ�
	T2CON = 0x00; //��ʱ��2����Ϊ�Զ���װ��16λ
	RCAP2H = BREATH_H;
	RCAP2L = BREATH_L; //��ʱʱ�����
	TH2 = RCAP2H;
	TL2 = RCAP2L;
	ET2 = 1;
}
//�����̵Ƶ�״̬
void allGLED(uchar stateb)
{
	up1 = stateb;
	up3 = stateb;
	up5 = stateb;
	up7 = stateb;
	up0 = stateb;
	left2 = stateb;
	left4 = stateb;
	left6 = stateb;
	left8 = stateb;
	left10 = stateb;

	right2 = stateb;
	right4 = stateb;
	right6 = stateb;
	right8 = stateb;
	right10 = stateb;
}
//���к�Ƶ�״̬
void allRLED(uchar stateb)
{
	up2 = stateb;
	up4 = stateb;
	up6 = stateb;
	up8 = stateb;
	left1 = stateb;
	left3 = stateb;
	left5 = stateb;
	left7 = stateb;
	left9 = stateb;

	down0 = stateb;
	right1 = stateb;
	right3 = stateb;
	right5 = stateb;
	right7 = stateb;
	right9 = stateb;
}
//�����ϱߵĵƵ�״̬
void allupLED(uchar state)
{
	up1 = state;
	up2 = state;
	up3 = state;
	up4 = state;

	up5 = state;
	up6 = state;
	up7 = state;
	up8 = state;
}
//�����±ߵĵƵ�״̬
void alldownLED(uchar state)
{
	up0 = state;
	left1 = state;
	left2 = state;
	left3 = state;
	left4 = state;
	left5 = state;
	left6 = state;
	left7 = state;
	left8 = state;
	left9 = state;
	left10 = state;

	down0 = state;
	right10 = state;
	right9 = state;
	right8 = state;
	right7 = state;
	right6 = state;
	right5 = state;
	right4 = state;
	right3 = state;
	right2 = state;
	right1 = state;
}
//���еĵƵ�״̬
void allLED(uchar state)
{
	allupLED(state);
	alldownLED(state);
}

//��ʽ1+2�����µ������ε�����Ϩ��
void cxdsycdlxmLED(uint xms, uchar state3) //���µ������ε�������Ϩ��
{
	allLED((~state3) & 1);
	down0 = state3;
	delayms(xms);
	right10 = state3;
	left10 = state3;
	delayms(xms);

	right9 = state3;
	left9 = state3;
	delayms(xms);

	right8 = state3;
	left8 = state3;
	delayms(xms);

	right7 = state3;
	left7 = state3;
	delayms(xms);

	right6 = state3;
	left6 = state3;
	delayms(xms);

	right5 = state3;
	left5 = state3;
	delayms(xms);

	right4 = state3;
	left4 = state3;
	delayms(xms);

	right3 = state3;
	left3 = state3;
	delayms(xms);

	right2 = state3;
	left2 = state3;
	delayms(xms);

	right1 = state3;
	left1 = state3;
	delayms(xms);

	up0 = state3;
	delayms(xms);

	up8 = state3;
	up4 = state3;
	delayms(xms);

	up7 = state3;
	up3 = state3;
	delayms(xms);

	up6 = state3;
	up2 = state3;
	delayms(xms);

	up5 = state3;
	up1 = state3;
	delayms(xms);
}
//��ʽ3+4�����ϵ������ε�����Ϩ��
void csdxycdlxmLED(uint xms, uchar state2) //���ϵ������ε�����Ϩ��
{
	allLED((~state2) & 1);
	up1 = state2;
	up5 = state2;
	delayms(xms);

	up2 = state2;
	up6 = state2;
	delayms(xms);

	up3 = state2;
	up7 = state2;
	delayms(xms);

	up4 = state2;
	up8 = state2;
	delayms(xms);

	up0 = state2;
	delayms(xms);

	left1 = state2;
	right1 = state2;
	delayms(xms);

	left2 = state2;
	right2 = state2;
	delayms(xms);

	left3 = state2;
	right3 = state2;
	delayms(xms);

	left4 = state2;
	right4 = state2;
	delayms(xms);

	left5 = state2;
	right5 = state2;
	delayms(xms);

	left6 = state2;
	right6 = state2;
	delayms(xms);

	left7 = state2;
	right7 = state2;
	delayms(xms);

	left8 = state2;
	right8 = state2;
	delayms(xms);

	left9 = state2;
	right9 = state2;
	delayms(xms);

	left10 = state2;
	right10 = state2;
	delayms(xms);

	down0 = state2;
	delayms(xms);
}
//��ʽ5+6�����д��ϵ��£�����Ϩ��
void dhcsdxLED(uint xms, uchar statea) //���д��ϵ���
{
	allLED((~statea) & 1);

	up1 = statea;
	up5 = statea;
	delayms(xms);
	up1 = ((~statea) & 1);
	up5 = ((~statea) & 1);

	up2 = statea;
	up6 = statea;
	delayms(xms);
	up2 = ((~statea) & 1);
	up6 = ((~statea) & 1);

	up3 = statea;
	up7 = statea;
	delayms(xms);
	up3 = ((~statea) & 1);
	up7 = ((~statea) & 1);

	up4 = statea;
	up8 = statea;
	delayms(xms);
	up4 = ((~statea) & 1);
	up8 = ((~statea) & 1);

	up0 = statea;
	delayms(xms);
	up0 = (~statea) & 1;

	left1 = statea;
	right1 = statea;
	delayms(xms);
	left1 = ((~statea) & 1);
	right1 = ((~statea) & 1);

	left2 = statea;
	right2 = statea;
	delayms(xms);
	left2 = ((~statea) & 1);
	right2 = ((~statea) & 1);

	left3 = statea;
	right3 = statea;
	delayms(xms);
	left3 = ((~statea) & 1);
	right3 = ((~statea) & 1);

	left4 = statea;
	right4 = statea;
	delayms(xms);
	left4 = ((~statea) & 1);
	right4 = ((~statea) & 1);

	left5 = statea;
	right5 = statea;
	delayms(xms);
	left5 = (~statea) & 1;
	right5 = (~statea) & 1;

	left6 = statea;
	right6 = statea;
	delayms(xms);
	left6 = (~statea) & 1;
	right6 = (~statea) & 1;

	left7 = statea;
	right7 = statea;
	delayms(xms);
	left7 = (~statea) & 1;
	right7 = (~statea) & 1;

	left8 = statea;
	right8 = statea;
	delayms(xms);
	left8 = (~statea) & 1;
	right8 = (~statea) & 1;

	left9 = statea;
	right9 = statea;
	delayms(xms);
	left9 = (~statea) & 1;
	right9 = (~statea) & 1;

	left10 = statea;
	right10 = statea;
	delayms(xms);
	left10 = (~statea) & 1;
	right10 = (~statea) & 1;

	down0 = statea;
	delayms(xms);
	down0 = (~statea) & 1;
}
//��ʽ7+8�����д��µ��ϣ�����Ϩ��
void dhcxdsLED(uint xms, uchar statea) //���д��µ���
{
	allLED((~statea) & 1);
	down0 = statea;
	delayms(xms);
	down0 = (~statea) & 1;
	left10 = statea;
	right10 = statea;
	delayms(xms);
	left10 = (~statea) & 1;
	right10 = (~statea) & 1;
	left9 = statea;
	right9 = statea;
	delayms(xms);
	left9 = (~statea) & 1;
	right9 = (~statea) & 1;
	left8 = statea;
	right8 = statea;
	delayms(xms);
	left8 = (~statea) & 1;
	right8 = (~statea) & 1;
	left7 = statea;
	right7 = statea;
	delayms(xms);
	left7 = (~statea) & 1;
	right7 = (~statea) & 1;
	left6 = statea;
	right6 = statea;
	delayms(xms);
	left6 = (~statea) & 1;
	right6 = (~statea) & 1;

	left5 = statea;
	right5 = statea;
	delayms(xms);
	left5 = (~statea) & 1;
	right5 = (~statea) & 1;
	left4 = statea;
	right4 = statea;
	delayms(xms);
	left4 = ((~statea) & 1);
	right4 = ((~statea) & 1);
	left3 = statea;
	right3 = statea;
	delayms(xms);
	left3 = ((~statea) & 1);
	right3 = ((~statea) & 1);
	left2 = statea;
	right2 = statea;
	delayms(xms);
	left2 = ((~statea) & 1);
	right2 = ((~statea) & 1);
	left1 = statea;
	right1 = statea;
	delayms(xms);
	left1 = ((~statea) & 1);
	right1 = ((~statea) & 1);
	up0 = statea;
	delayms(xms);
	up0 = (~statea) & 1;
	up4 = statea;
	up8 = statea;
	delayms(xms);
	up4 = ((~statea) & 1);
	up8 = ((~statea) & 1);
	up3 = statea;
	up7 = statea;
	delayms(xms);
	up3 = ((~statea) & 1);
	up7 = ((~statea) & 1);
	up2 = statea;
	up6 = statea;
	delayms(xms);
	up2 = ((~statea) & 1);
	up6 = ((~statea) & 1);
	up1 = statea;
	up5 = statea;
	delayms(xms);
	up1 = ((~statea) & 1);
	up5 = ((~statea) & 1);
}
//��ʽ9+10+11+12���Խ���ʱ�뻥����˸
void djhxssLEDnsz(uint xms, uint yms, uchar statea) //��ʽ9+10+11+12���Խ���ʱ�뻥����˸
{
	uchar i;
	allLED((~statea) & 1);
	for (i = 0; i < 2; i++)
	{

		up0 = statea;
		down0 = statea;
		if (i == 0)
			up1 = statea;
		else if (i == 1)
			up8 = statea;
		delayms(xms);
		up0 = (~statea) & 1;
		down0 = (~statea) & 1;
		if (i == 0)
			up1 = (~statea) & 1;
		else if (i == 1)
			up8 = (~statea) & 1;
		delayms(yms);

		left1 = statea;
		right10 = statea;
		if (i == 0)
			up2 = statea;
		else if (i == 1)
			up7 = statea;
		delayms(xms);
		left1 = (~statea) & 1;
		right10 = (~statea) & 1;
		if (i == 0)
			up2 = (~statea) & 1;
		else if (i == 1)
			up7 = (~statea) & 1;
		delayms(yms);

		left2 = statea;
		right9 = statea;
		if (i == 0)
			up3 = statea;
		else if (i == 1)
			up6 = statea;
		delayms(xms);
		left2 = (~statea) & 1;
		right9 = (~statea) & 1;
		if (i == 0)
			up3 = (~statea) & 1;
		else if (i == 1)
			up6 = (~statea) & 1;
		delayms(yms);

		left3 = statea;
		right8 = statea;
		if (i == 0)
			up4 = statea;
		else if (i == 1)
			up5 = statea;
		delayms(xms);
		left3 = (~statea) & 1;
		right8 = (~statea) & 1;
		if (i == 0)
			up4 = (~statea) & 1;
		else if (i == 1)
			up5 = (~statea) & 1;
		delayms(yms);

		left4 = statea;
		right7 = statea;
		if (i == 0)
			up8 = statea;
		else if (i == 1)
			up1 = statea;
		delayms(xms);
		left4 = (~statea) & 1;
		right7 = (~statea) & 1;
		if (i == 0)
			up8 = (~statea) & 1;
		else if (i == 1)
			up1 = (~statea) & 1;
		delayms(yms);

		left5 = statea;
		right6 = statea;
		if (i == 0)
			up7 = statea;
		else if (i == 1)
			up2 = statea;
		delayms(xms);
		left5 = (~statea) & 1;
		right6 = (~statea) & 1;
		if (i == 0)
			up7 = (~statea) & 1;
		else if (i == 1)
			up2 = (~statea) & 1;
		delayms(yms);

		left6 = statea;
		right5 = statea;
		if (i == 0)
			up6 = statea;
		else if (i == 1)
			up3 = statea;
		delayms(xms);
		left6 = (~statea) & 1;
		right5 = (~statea) & 1;
		if (i == 0)
			up6 = (~statea) & 1;
		else if (i == 1)
			up3 = (~statea) & 1;
		delayms(yms);

		left7 = statea;
		right4 = statea;
		if (i == 0)
			up5 = statea;
		else if (i == 1)
			up4 = statea;
		delayms(xms);
		left7 = (~statea) & 1;
		right4 = (~statea) & 1;
		if (i == 0)
			up5 = (~statea) & 1;
		else if (i == 1)
			up4 = (~statea) & 1;
		delayms(yms);

		left8 = statea;
		right3 = statea;
		if (i == 0)
			up1 = statea;
		else if (i == 1)
			up8 = statea;
		delayms(xms);
		left8 = (~statea) & 1;
		right3 = (~statea) & 1;
		if (i == 0)
			up1 = (~statea) & 1;
		else if (i == 1)
			up8 = (~statea) & 1;
		delayms(yms);

		left9 = statea;
		right2 = statea;
		if (i == 0)
			up2 = statea;
		else if (i == 1)
			up7 = statea;
		delayms(xms);
		left9 = (~statea) & 1;
		right2 = (~statea) & 1;
		if (i == 0)
			up2 = (~statea) & 1;
		else if (i == 1)
			up7 = (~statea) & 1;
		delayms(yms);

		left10 = statea;
		right1 = statea;
		if (i == 0)
			up3 = statea;
		else if (i == 1)
			up6 = statea;
		delayms(xms);
		left10 = (~statea) & 1;
		right1 = (~statea) & 1;
		if (i == 0)
			up3 = (~statea) & 1;
		else if (i == 1)
			up6 = (~statea) & 1;
		delayms(yms);

		down0 = statea;
		up0 = statea;
		if (i == 0)
			up4 = statea;
		else if (i == 1)
			up5 = statea;
		delayms(xms);
		down0 = (~statea) & 1;
		up0 = (~statea) & 1;
		if (i == 0)
			up4 = (~statea) & 1;
		else if (i == 1)
			up5 = (~statea) & 1;
		delayms(yms);
	}
}
//��ʽ13+14+15+16���Խ�˳ʱ��ʱ�뻥����˸
void djhxssLEDssz(uint xms, uint yms, uchar statea) //��ʽ13+14+15+16���Խ�˳ʱ�뻥����˸
{
	uchar i;
	allLED((~statea) & 1);
	for (i = 0; i < 2; i++)
	{
		up0 = statea;
		down0 = statea;
		if (i == 0)
			up5 = statea;
		else if (i == 1)
			up4 = statea;
		delayms(xms);
		up0 = (~statea) & 1;
		down0 = (~statea) & 1;
		if (i == 0)
			up5 = (~statea) & 1;
		else if (i == 1)
			up4 = (~statea) & 1;
		delayms(yms);

		right1 = statea;
		left10 = statea;
		if (i == 0)
			up6 = statea;
		else if (i == 1)
			up3 = statea;
		delayms(xms);
		right1 = (~statea) & 1;
		left10 = (~statea) & 1;
		if (i == 0)
			up6 = (~statea) & 1;
		else if (i == 1)
			up3 = (~statea) & 1;
		delayms(yms);

		right2 = statea;
		left9 = statea;
		if (i == 0)
			up7 = statea;
		else if (i == 1)
			up2 = statea;
		delayms(xms);
		right2 = (~statea) & 1;
		left9 = (~statea) & 1;
		if (i == 0)
			up7 = (~statea) & 1;
		else if (i == 1)
			up2 = (~statea) & 1;
		delayms(yms);

		right3 = statea;
		left8 = statea;
		if (i == 0)
			up8 = statea;
		else if (i == 8)
			up1 = statea;
		delayms(xms);
		right3 = (~statea) & 1;
		left8 = (~statea) & 1;
		if (i == 0)
			up8 = (~statea) & 1;
		else if (i == 1)
			up1 = (~statea) & 1;
		delayms(yms);

		right4 = statea;
		left7 = statea;
		if (i == 0)
			up4 = statea;
		else if (i == 1)
			up5 = statea;
		delayms(xms);
		right4 = (~statea) & 1;
		left7 = (~statea) & 1;
		if (i == 0)
			up4 = (~statea) & 1;
		else if (i == 1)
			up5 = (~statea) & 1;
		delayms(yms);

		right5 = statea;
		left6 = statea;
		if (i == 0)
			up3 = statea;
		else if (i == 1)
			up6 = statea;
		delayms(xms);
		right5 = (~statea) & 1;
		left6 = (~statea) & 1;
		if (i == 0)
			up3 = (~statea) & 1;
		else if (i == 1)
			up6 = (~statea) & 1;
		delayms(yms);

		right6 = statea;
		left5 = statea;
		if (i == 0)
			up2 = statea;
		else if (i == 1)
			up7 = statea;
		delayms(xms);
		right6 = (~statea) & 1;
		left5 = (~statea) & 1;
		if (i == 0)
			up2 = (~statea) & 1;
		else if (i == 1)
			up7 = (~statea) & 1;
		delayms(yms);

		right7 = statea;
		left4 = statea;
		if (i == 0)
			up1 = statea;
		else if (i == 1)
			up8 = statea;
		delayms(xms);
		right7 = (~statea) & 1;
		left4 = (~statea) & 1;
		if (i == 0)
			up1 = (~statea) & 1;
		else if (i == 1)
			up8 = (~statea) & 1;
		delayms(yms);

		right8 = statea;
		left3 = statea;
		if (i == 0)
			up5 = statea;
		else if (i == 1)
			up4 = statea;
		delayms(xms);
		right8 = (~statea) & 1;
		left3 = (~statea) & 1;
		if (i == 0)
			up5 = (~statea) & 1;
		else if (i == 1)
			up4 = (~statea) & 1;
		delayms(yms);

		right9 = statea;
		left2 = statea;
		if (i == 0)
			up6 = statea;
		else if (i == 1)
			up3 = statea;
		delayms(xms);
		right9 = (~statea) & 1;
		left2 = (~statea) & 1;
		if (i == 0)
			up6 = (~statea) & 1;
		else if (i == 1)
			up3 = (~statea) & 1;
		delayms(yms);

		right10 = statea;
		left1 = statea;
		if (i == 0)
			up7 = statea;
		else if (i == 1)
			up2 = statea;
		delayms(xms);
		right10 = (~statea) & 1;
		left1 = (~statea) & 1;
		if (i == 0)
			up7 = (~statea) & 1;
		else if (i == 1)
			up2 = (~statea) & 1;
		delayms(yms);

		down0 = statea;
		up0 = statea;
		if (i == 0)
			up8 = statea;
		else if (i == 1)
			up1 = statea;
		delayms(xms);
		down0 = (~statea) & 1;
		up0 = (~statea) & 1;
		if (i == 0)
			up8 = (~statea) & 1;
		else if (i == 1)
			up1 = (~statea) & 1;
		delayms(yms);
	}
}
//��ʽ17�����µ��ϵ���Ȼ��Ϩ������
void cxds1(uint xms)
{
	uchar i;
	allLED(OFF);
	for (i = 0; i < 2; i++)
	{
		cxdsycdlxmLED(xms, ON);
		delayms(xms);
		delayms(xms);
		cxdsycdlxmLED(xms, OFF);
	}
}
//��ʽ18�����ϵ��µ���Ȼ��Ϩ������
void csdx1(uint xms)
{
	uchar i;
	allLED(ON);
	for (i = 0; i < 2; i++)
	{
		csdxycdlxmLED(xms, ON);
		delayms(xms);
		delayms(xms);
		csdxycdlxmLED(xms, OFF);
	}
}
//��ʽ19�����µ������ε���Ȼ����ϵ���Ϩ��Ȼ����ϵ��µ���Ȼ����µ���Ϩ��
void cxds2(uint xms) //���µ������ε���LEDȻ��Ϩ��Ȼ����ϵ��µ���Ȼ��Ϩ��
{
	allLED(OFF);
	cxdsycdlxmLED(xms, ON);
	delayms(xms);
	delayms(xms);
	csdxycdlxmLED(xms, OFF);
	csdxycdlxmLED(xms, ON);
	delayms(xms);
	delayms(xms);
	cxdsycdlxmLED(xms, OFF);
}
//��ʽ20�����µ������ε���Ȼ����µ���Ϩ��Ȼ����ϵ��µ���Ȼ����ϵ���Ϩ��
void csdx2(uint xms) //���µ������ε���LEDȻ��Ϩ��Ȼ����ϵ��µ���Ȼ��Ϩ��
{
	allLED(OFF);
	cxdsycdlxmLED(xms, ON);
	delayms(xms);
	delayms(xms);
	cxdsycdlxmLED(xms, OFF);
	csdxycdlxmLED(xms, ON);
	delayms(xms);
	delayms(xms);
	csdxycdlxmLED(xms, OFF);
}
//��ʽ21+22����ʱ��������أ��ֱ��������Ϩ��
void zgkgLEDnsz(uint xms, uchar statec) //��ʱ���������//�ȿ�������Ȼ���ǰһ��������һ��
{
	allLED((~statec) & 1);
	up0 = statec;
	delayms(xms);
	left1 = statec;
	delayms(xms);

	up0 = ((~statec) & 1);
	left2 = statec;
	delayms(xms);

	left1 = ((~statec) & 1);
	left3 = statec;
	delayms(xms);

	left1 = ((~statec) & 1);
	left3 = statec;
	delayms(xms);
	left2 = ((~statec) & 1);
	left4 = statec;
	delayms(xms);
	left3 = ((~statec) & 1);
	left5 = statec;
	delayms(xms);
	left4 = ((~statec) & 1);
	left6 = statec;
	delayms(xms);
	left5 = ((~statec) & 1);
	left7 = statec;
	delayms(xms);
	left6 = ((~statec) & 1);
	left8 = statec;
	delayms(xms);
	left7 = ((~statec) & 1);
	left9 = statec;
	delayms(xms);
	left8 = ((~statec) & 1);
	left10 = statec;
	delayms(xms);

	left9 = ((~statec) & 1);
	down0 = statec;
	delayms(xms);
	left10 = ((~statec) & 1);
	right10 = statec;
	delayms(xms);
	down0 = ((~statec) & 1);
	right9 = statec;
	delayms(xms);
	right10 = ((~statec) & 1);
	right8 = statec;
	delayms(xms);

	right9 = ((~statec) & 1);
	right7 = statec;
	delayms(xms);

	right8 = ((~statec) & 1);
	right6 = statec;
	delayms(xms);

	right7 = ((~statec) & 1);
	right5 = statec;
	delayms(xms);

	right6 = ((~statec) & 1);
	right4 = statec;
	delayms(xms);

	right5 = ((~statec) & 1);
	right3 = statec;
	delayms(xms);

	right4 = ((~statec) & 1);
	right2 = statec;
	delayms(xms);

	right3 = ((~statec) & 1);
	right1 = statec;
	delayms(xms);

	right2 = ((~statec) & 1);
	up0 = statec;
	delayms(xms);

	right1 = ((~statec) & 1);
	up8 = statec;
	delayms(xms);

	up0 = ((~statec) & 1);
	up7 = statec;
	delayms(xms);

	up8 = ((~statec) & 1);
	up6 = statec;
	delayms(xms);

	up7 = ((~statec) & 1);
	up5 = statec;
	delayms(xms);

	up6 = ((~statec) & 1);
	up1 = statec;
	delayms(xms);

	up5 = ((~statec) & 1);
	up2 = statec;
	delayms(xms);

	up1 = ((~statec) & 1);
	up3 = statec;
	delayms(xms);

	up2 = ((~statec) & 1);
	up4 = statec;
	delayms(xms);

	up3 = ((~statec) & 1);
	delayms(xms);

	up4 = ((~statec) & 1);
}
//��ʽ23+24��˳ʱ��������أ��ֱ��������Ϩ��
void zgkgLEDssz(uint xms, uchar statec) //˳ʱ���������//�ȿ�������Ȼ���ǰһ��������һ��
{
	allLED((~statec) & 1);
	up4 = statec;
	delayms(xms);
	up3 = statec;
	delayms(xms);

	up4 = ((~statec) & 1);
	up2 = statec;
	delayms(xms);

	up3 = ((~statec) & 1);
	up1 = statec;
	delayms(xms);

	up2 = ((~statec) & 1);
	up5 = statec;
	delayms(xms);

	up1 = ((~statec) & 1);
	up6 = statec;
	delayms(xms);

	up5 = ((~statec) & 1);
	up7 = statec;
	delayms(xms);

	up6 = ((~statec) & 1);
	up8 = statec;
	delayms(xms);

	up7 = ((~statec) & 1);
	up0 = statec;
	delayms(xms);

	up8 = ((~statec) & 1);
	right1 = statec;
	delayms(xms);

	up0 = ((~statec) & 1);
	right2 = statec;
	delayms(xms);

	right1 = ((~statec) & 1);
	right3 = statec;
	delayms(xms);

	right2 = ((~statec) & 1);
	right4 = statec;
	delayms(xms);

	right3 = ((~statec) & 1);
	right5 = statec;
	delayms(xms);

	right4 = ((~statec) & 1);
	right6 = statec;
	delayms(xms);

	right5 = ((~statec) & 1);
	right7 = statec;
	delayms(xms);

	right6 = ((~statec) & 1);
	right8 = statec;
	delayms(xms);

	right7 = ((~statec) & 1);
	right9 = statec;
	delayms(xms);

	right8 = ((~statec) & 1);
	right10 = statec;
	delayms(xms);

	right9 = ((~statec) & 1);
	down0 = statec;
	delayms(xms);

	right10 = ((~statec) & 1);
	left10 = statec;
	delayms(xms);

	down0 = ((~statec) & 1);
	left9 = statec;
	delayms(xms);

	left10 = ((~statec) & 1);
	left8 = statec;
	delayms(xms);

	left9 = ((~statec) & 1);
	left7 = statec;
	delayms(xms);

	left8 = ((~statec) & 1);
	left6 = statec;
	delayms(xms);

	left7 = ((~statec) & 1);
	left5 = statec;
	delayms(xms);

	left6 = ((~statec) & 1);
	left4 = statec;
	delayms(xms);

	left5 = ((~statec) & 1);
	left3 = statec;
	delayms(xms);

	left4 = ((~statec) & 1);
	left2 = statec;
	delayms(xms);

	left3 = ((~statec) & 1);
	left1 = statec;
	delayms(xms);

	left2 = ((~statec) & 1);
	up0 = statec;
	delayms(xms);

	left1 = ((~statec) & 1);
	delayms(xms);

	up0 = ((~statec) & 1);
}
//��ʽ25�����еĵ�ȫ����˸x����
void ssLED(uint xms, uchar sscishu) //���е���xms�Ŀ���Ƶ����˸,����˸sstime��
{
	uchar i;
	for (i = 0; i < sscishu; i++)
	{
		allLED(ON);
		delayms(xms);
		allLED(OFF);
		delayms(xms);
	}
}

void up8LEDycdlxmnsz(uint xmsa, uchar statea) //�ϱ߰˸�LED��ʱ��һ�ε�����Ϩ��
{
	allupLED((~statea) & 1);
	up8 = statea;
	delayms(xmsa);
	up7 = statea;
	delayms(xmsa);
	up6 = statea;
	delayms(xmsa);
	up5 = statea;
	delayms(xmsa);
	up1 = statea;
	delayms(xmsa);
	up2 = statea;
	delayms(xmsa);
	up3 = statea;
	delayms(xmsa);
	up4 = statea;
	delayms(xmsa);
}
void down22LEDycdlxmnsz(uint xmsa, uchar statea) //�±�22��LED��ʱ��һ�ε�����Ϩ��
{
	alldownLED((~statea) & 1);
	up0 = statea;
	delayms(xmsa);
	left1 = statea;
	delayms(xmsa);
	left2 = statea;
	delayms(xmsa);
	left3 = statea;
	delayms(xmsa);
	left4 = statea;
	delayms(xmsa);
	left5 = statea;
	delayms(xmsa);
	left6 = statea;
	delayms(xmsa);
	left7 = statea;
	delayms(xmsa);
	left8 = statea;
	delayms(xmsa);
	left9 = statea;
	delayms(xmsa);
	left10 = statea;
	delayms(xmsa);

	down0 = statea;
	delayms(xmsa);

	right10 = statea;
	delayms(xmsa);
	right9 = statea;
	delayms(xmsa);
	right8 = statea;
	delayms(xmsa);
	right7 = statea;
	delayms(xmsa);
	right6 = statea;
	delayms(xmsa);
	right5 = statea;
	delayms(xmsa);
	right4 = statea;
	delayms(xmsa);
	right3 = statea;
	delayms(xmsa);
	right2 = statea;
	delayms(xmsa);
	right1 = statea;
	delayms(xmsa);
}
//��ʽ26��������ʱ�����
void ycdlLEDnsz(uint xmsa) //������ʱ�����
{
	up8LEDycdlxmnsz(xmsa, ON);
	down22LEDycdlxmnsz(xmsa, ON);
	delayms(xmsa);
	delayms(xmsa);
}
//��ʽ27��������ʱ��Ϩ��
void ycxmLEDnsz(uint xmsa) //������ʱ��Ϩ��
{
	down22LEDycdlxmnsz(xmsa, OFF);
	up8LEDycdlxmnsz(xmsa, OFF);
}

void up8LEDycdlxmssz(uint xmsa, uchar statea) //�ϱ߰˸�LED˳ʱ��һ�ε�����Ϩ��
{
	allupLED((~statea) & 1);
	up4 = statea;
	delayms(xmsa);
	up3 = statea;
	delayms(xmsa);
	up2 = statea;
	delayms(xmsa);
	up1 = statea;
	delayms(xmsa);
	up5 = statea;
	delayms(xmsa);
	up6 = statea;
	delayms(xmsa);
	up7 = statea;
	delayms(xmsa);
	up8 = statea;
	delayms(xmsa);
}
void down22LEDycdlxmssz(uint xmsa, uchar statea) //�±�22��LED˳ʱ��һ�ε�����Ϩ��
{
	alldownLED((~statea) & 1);
	up0 = statea;
	delayms(xmsa);
	right1 = statea;
	delayms(xmsa);
	right2 = statea;
	delayms(xmsa);
	right3 = statea;
	delayms(xmsa);
	right4 = statea;
	delayms(xmsa);
	right5 = statea;
	delayms(xmsa);
	right6 = statea;
	delayms(xmsa);
	right7 = statea;
	delayms(xmsa);
	right8 = statea;
	delayms(xmsa);
	right9 = statea;
	delayms(xmsa);
	right10 = statea;
	delayms(xmsa);

	down0 = statea;
	delayms(xmsa);

	left10 = statea;
	delayms(xmsa);
	left9 = statea;
	delayms(xmsa);
	left8 = statea;
	delayms(xmsa);
	left7 = statea;
	delayms(xmsa);
	left6 = statea;
	delayms(xmsa);
	left5 = statea;
	delayms(xmsa);
	left4 = statea;
	delayms(xmsa);
	left3 = statea;
	delayms(xmsa);
	left2 = statea;
	delayms(xmsa);
	left1 = statea;
	delayms(xmsa);
	delayms(xmsa);
	delayms(xmsa);
}
//��ʽ28������˳ʱ�����
void ycdlLEDssz(uint xmsa) //����˳ʱ�����
{
	up8LEDycdlxmssz(xmsa, ON);
	down22LEDycdlxmssz(xmsa, ON);
	delayms(xmsa);
	delayms(xmsa);
}
//��ʽ29������˳ʱ��Ϩ��
void ycxmLEDssz(uint xmsa) //����˳ʱ��Ϩ��
{
	down22LEDycdlxmssz(xmsa, OFF);
	up8LEDycdlxmssz(xmsa, OFF);
}
//��ʽ30������LED�������˳ʱ��Ȼ����ʱ��
void allLEDzgdl(uint xmsc) //����LED������أ���˳ʱ��Ȼ����ʱ��
{
	uchar i = 0;
	for (i = 0; i < 2; i++)
	{

		zgkgLEDssz(xmsc, ON);
		zgkgLEDnsz(xmsc, ON);
	}
}
//��ʽ31������LED���Ϩ����˳ʱ��Ȼ����ʱ��
void allLEDzgxm(uint xmsc) //����LED������أ���˳ʱ��Ȼ����ʱ��
{
	uchar i = 0;
	for (i = 0; i < 2; i++)
	{

		zgkgLEDssz(xmsc, OFF);
		zgkgLEDnsz(xmsc, OFF);
	}
}
//��ʽ32������LED����˳ʱ�����Ȼ������Ϩ��
void allLEDdlxmssz(uint xmsb)
{
	uchar i;
	for (i = 0; i < 2; i++)
	{
		ycdlLEDssz(xmsb);
		ycxmLEDssz(xmsb);
	}
}
//��ʽ33������LED������ʱ�����Ȼ������Ϩ��
void allLEDdlxmnsz(uint xmsb)
{
	uchar i;
	for (i = 0; i < 2; i++)
	{
		ycdlLEDnsz(xmsb);
		ycxmLEDnsz(xmsb);
	}
}
//��ʽ34������LED���ε���Ȼ������Ϩ����˳ʱ�����ʱ��
void allLEDdlxm(uint xmsb) //���еĵ����ε���Ȼ������Ϩ����˳ʱ��Ȼ����ʱ��
{
	ycdlLEDssz(xmsb);
	ycxmLEDssz(xmsb);
	ycdlLEDnsz(xmsb);
	ycxmLEDnsz(xmsb);
}

//���̷ֿ���˸1234
void rgfkssLED1(stated)
{
	up1 = stated;
	up8 = stated;

	// up0=stated;
	left4 = stated;
	left8 = stated;
	right10 = stated;
	right6 = stated;
	right2 = stated;
}
void rgfkssLED2(stated)
{
	up2 = stated;
	up7 = stated;

	// left1=stated;
	left5 = stated;
	left9 = stated;
	right9 = stated;
	right5 = stated;
	right1 = stated;
}
void rgfkssLED3(stated)
{
	up3 = stated;
	up6 = stated;

	left2 = stated;
	left6 = stated;
	left10 = stated;
	right8 = stated;
	right4 = stated;
}
void rgfkssLED4(stated)
{
	up4 = stated;
	up5 = stated;

	left3 = stated;
	left7 = stated;
	down0 = stated;
	right7 = stated;
	right3 = stated;
}
//���̵Ʒֿ���˸˳ʱ��
void rgfkssLEDssz(uint xmsd) //���̷ֿ���˸
{
	up0 = OFF;
	left1 = OFF;

	rgfkssLED1(ON);
	delayms(xmsd);
	rgfkssLED1(OFF);

	rgfkssLED2(ON);
	delayms(xmsd);
	rgfkssLED2(OFF);

	rgfkssLED3(ON);
	delayms(xmsd);
	rgfkssLED3(OFF);

	rgfkssLED4(ON);
	delayms(xmsd);
	rgfkssLED4(OFF);
}
//���̵Ʒֿ���˸��ʱ��
void rgfkssLEDnsz(uint xmsd) //���̷ֿ���˸
{
	up0 = OFF;
	left1 = OFF;

	rgfkssLED4(ON);
	delayms(xmsd);
	rgfkssLED4(OFF);

	rgfkssLED3(ON);
	delayms(xmsd);
	rgfkssLED3(OFF);

	rgfkssLED2(ON);
	delayms(xmsd);
	rgfkssLED2(OFF);

	rgfkssLED1(ON);
	delayms(xmsd);
	rgfkssLED1(OFF);
}
//��ʽ35�����к��̵Ʒֿ���˸˳ʱ��
void allrgfkssLEDssz(uint xmsd)
{
	uchar i = 0;
	for (i = 0; i < 2; i++)
	{
		rgfkssLEDssz(xmsd);
	}
}
//��ʽ36�����к��̵Ʒֿ���˸��ʱ��
void allrgfkssLEDnsz(uint xmsd)
{
	uchar i = 0;
	for (i = 0; i < 2; i++)
	{
		rgfkssLEDnsz(xmsd);
	}
}
//��ʽ37�����к��̵Ʒֿ���˸,��˳ʱ�����ʱ��
void ALLrgfkssLED(uint xmsd, uchar timed)
{
	uchar i;
	for (i = 0; i < timed; i++)
	{
		rgfkssLEDssz(xmsd);
		rgfkssLEDssz(xmsd);
		rgfkssLEDnsz(xmsd);
		rgfkssLEDnsz(xmsd);
	}
}
//��ʽ38�����̵Ʒֱ���˸
void ssGRLED(uint xms, uchar time3) //���̷ֱ���˸
{
	uchar i;
	allLED(OFF);
	for (i = 0; i < time3; i++)
	{
		allGLED(ON);
		delayms(xms);
		allGLED(OFF);

		allRLED(ON);
		delayms(xms);
		allRLED(OFF);
	}
}
//��ʽ0��������
void breathLED(uchar j, uchar times)
{
	uchar i;
	uint duty_cycle;
	for (i = 0; i < times; i++)
	{
		for (duty_cycle = DUTY_END; duty_cycle >= DUTY_START; duty_cycle -= DUTY_STEP)
		{
			if (duty_cycle == DUTY_START)
			{
				for (; Count_cycle < COUNT_CYCLE + 300; Count_cycle++)
				{
					TR2 = 1;
					if (j == ALLLED)
						allLED(ON);
					else if (j == ALLGLED)
						allGLED(ON);
					else if (j == ALLRLED)
						allRLED(ON);
					while (Count_duty <= duty_cycle)
						;
					if (j == ALLLED)
						allLED(OFF);
					else if (j == ALLGLED)
						allGLED(OFF);
					else if (j == ALLRLED)
						allRLED(OFF);
					while (Count_duty <= TOTLE_DUTY)
						;
					TR2 = 0;
					Count_duty = 0;
				}
			}
			else
			{
				for (; Count_cycle < COUNT_CYCLE; Count_cycle++)
				{
					TR2 = 1;
					if (j == ALLLED)
						allLED(ON);
					else if (j == ALLGLED)
						allGLED(ON);
					else if (j == ALLRLED)
						allRLED(ON);
					while (Count_duty <= duty_cycle)
						;
					if (j == ALLLED)
						allLED(OFF);
					else if (j == ALLGLED)
						allGLED(OFF);
					else if (j == ALLRLED)
						allRLED(OFF);
					while (Count_duty <= TOTLE_DUTY)
						;
					TR2 = 0;
					Count_duty = 0;
				}
			}

			Count_cycle = 0;
		}
		for (duty_cycle = DUTY_START; duty_cycle <= DUTY_END; duty_cycle += DUTY_STEP)
		{
			if (duty_cycle == DUTY_END)
			{
				for (; Count_cycle < COUNT_CYCLE + 100; Count_cycle++)
				{
					TR2 = 1;
					if (j == ALLLED)
						allLED(ON);
					else if (j == ALLGLED)
						allGLED(ON);
					else if (j == ALLRLED)
						allRLED(ON);
					while (Count_duty <= duty_cycle)
						;
					if (j == ALLLED)
						allLED(OFF);
					else if (j == ALLGLED)
						allGLED(OFF);
					else if (j == ALLRLED)
						allRLED(OFF);
					while (Count_duty <= TOTLE_DUTY)
						;
					TR2 = 0;
					Count_duty = 0;
				}
			}
			else
			{
				for (; Count_cycle < COUNT_CYCLE; Count_cycle++)
				{
					TR2 = 1;
					if (j == ALLLED)
						allLED(ON);
					else if (j == ALLGLED)
						allGLED(ON);
					else if (j == ALLRLED)
						allRLED(ON);
					while (Count_duty <= duty_cycle)
						;
					if (j == ALLLED)
						allLED(OFF);
					else if (j == ALLGLED)
						allGLED(OFF);
					else if (j == ALLRLED)
						allRLED(OFF);
					while (Count_duty <= TOTLE_DUTY)
						;
					TR2 = 0;
					Count_duty = 0;
				}
			}
			Count_cycle = 0;
		}
	}
}
//�ϵ����ˮ����ʽ
void startled(void)
{
	breathLED(ALLLED, 2);
	ssGRLED(200, 2);
	breathLED(ALLGLED, 2);
	ssGRLED(200, 2);
	breathLED(ALLRLED, 2);
	zgkgLEDnsz(150, ON);
	zgkgLEDssz(150, ON);
	ycdlLEDnsz(100);
	ycxmLEDnsz(100);
	ycdlLEDssz(100);
	ycxmLEDssz(100);
	ALLrgfkssLED(150, 2);
	ssLED(200, 3);
}
//����ı�LED��ʽ
void changeLED(uchar r)
{
	uchar j;
	uint ledtime;
	ledtime = rand() % 30 + 90;
	j = rand() % 3 + 1;
	switch (r)
	{
	case 0:
	allRLED(OFF);
		breathLED(ALLGLED, j);
		break;
	case 1:
		cxdsycdlxmLED(ledtime, ON);
		break;
	case 2:
		cxdsycdlxmLED(ledtime, OFF);
		break;
	case 3:
		csdxycdlxmLED(ledtime, ON);
		break;
	case 4:
		csdxycdlxmLED(ledtime, OFF);
		break;
	case 5:
		dhcsdxLED(ledtime, ON);
		break;
	case 6:
		dhcsdxLED(ledtime, OFF);
		break;
	case 7:
		dhcxdsLED(ledtime, ON);
		break;
	case 8:
		dhcxdsLED(ledtime, OFF);
		break;
	case 9:
		djhxssLEDnsz(ledtime + 80, ledtime + 80, ON);
		break;
	case 10:
		djhxssLEDnsz(ledtime + 80, ledtime + 80, OFF);
		break;
	case 11:
		djhxssLEDnsz(ledtime, 0, ON);
		break;
	case 12:
		djhxssLEDnsz(ledtime, 0, OFF);
		break;
	case 13:
		djhxssLEDssz(ledtime + 80, ledtime + 80, ON);
		break;
	case 14:
		djhxssLEDssz(ledtime + 80, ledtime + 80, OFF);
		break;
	case 15:
		djhxssLEDssz(ledtime, 0, ON);
		break;
	case 16:
		djhxssLEDssz(ledtime, 0, OFF);
		break;
	case 17:
		cxds1(ledtime);
		break;
	case 18:
		csdx1(ledtime);
		break;
	case 19:
		cxds2(ledtime);
		break;
	case 20:
		csdx2(ledtime);
		break;
	case 21:
		zgkgLEDnsz(ledtime, ON);
		break;
	case 22:
		zgkgLEDnsz(ledtime, OFF);
		break;
	case 23:
		zgkgLEDssz(ledtime, ON);
		break;
	case 24:
		zgkgLEDssz(ledtime, OFF);
		break;
	case 25:
		ssLED(ledtime + 130, j);
		break;
	case 26:
		ycdlLEDnsz(ledtime);
		break;
	case 27:
		ycxmLEDnsz(ledtime);
		break;
	case 28:
		ycdlLEDssz(ledtime);
		break;
	case 29:
		ycxmLEDssz(ledtime);
		break;
	case 30:
		allLEDzgdl(ledtime);
		break;
	case 31:
		allLEDzgxm(ledtime);
		break;
	case 32:
		allLEDdlxmssz(ledtime);
		break;
	case 33:
		allLEDdlxmnsz(ledtime);
		break;
	case 34:
		allLEDdlxm(ledtime);
		break;
	case 35:
		allrgfkssLEDssz(ledtime);
		break;
	case 36:
		allrgfkssLEDnsz(ledtime);
		break;
	case 37:
		ALLrgfkssLED(ledtime, 3);
		break;
	case 38:
		ssGRLED(300, j + 1);
		break;
	case 39:
		allGLED(OFF);
		breathLED(ALLRLED, j);
		break;
	default:
		ALLrgfkssLED(ledtime, j);
		break;
	}
}
void Timer2Interrupt(void) interrupt 5 //������30us��װ
{
	TF2 = 0;
	Count_duty++;
}
