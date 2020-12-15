#ifndef __LED_H
#define __LED_H
#include "test_board.h"

#ifndef __C8051F005_H
#define __C8051F005_H
#include "C8051F000.h"
#endif //__C8051F005_H

//LED的开关状态
#define ON 0
#define OFF 1

#define COUNT_CYCLE 10
#define TOTLE_DUTY 250
#define DUTY_START 1
#define DUTY_END 41
#define DUTY_STEP 1
#define BREATH_H 0xFF
#define BREATH_L 0xEC //10us

#define ALLLED 0
#define ALLGLED 1
#define ALLRLED 2
sbit up0 = P0 ^ 3;
sbit left1 = P0 ^ 2;
sbit left2 = P3 ^ 6;
sbit left3 = P3 ^ 7;
sbit left4 = P2 ^ 6;
sbit left5 = P2 ^ 7;
sbit left6 = P0 ^ 1;
sbit left7 = P0 ^ 0;
sbit left8 = P1 ^ 0;
sbit left9 = P1 ^ 1;
sbit left10 = P1 ^ 2;

sbit right1 = P0 ^ 4;
sbit right2 = P0 ^ 5;
sbit right3 = P2 ^ 5;
sbit right4 = P2 ^ 4;
sbit right5 = P1 ^ 5;
sbit right6 = P2 ^ 1;
sbit right7 = P3 ^ 0;
sbit right8 = P3 ^ 1;
sbit right9 = P2 ^ 0;
sbit right10 = P1 ^ 4;
sbit down0 = P1 ^ 3;

sbit up1 = P3 ^ 5;
sbit up2 = P3 ^ 4;
sbit up3 = P1 ^ 7;
sbit up4 = P1 ^ 6;

sbit up5 = P0 ^ 7;
sbit up6 = P0 ^ 6;
sbit up7 = P2 ^ 2;
sbit up8 = P2 ^ 3;
void Timer2_Init(void);
//所有绿灯的状态
void allGLED(uchar stateb);
//所有红灯的状态
void allRLED(uchar stateb);
//所有上边的灯的状态
void allupLED(uchar state);
//所有下边的灯的状态
void alldownLED(uchar state);
//所有的灯的状态
void allLED(uchar state);
//样式0：呼吸灯
void breathLED(uchar j, uchar times);
//样式1+2：从下到上依次点亮，熄灭
void cxdsycdlxmLED(uint xms, uchar state3); //从下到上依次点亮或者熄灭
//样式3+4：从上到下依次点亮，熄灭
void csdxycdlxmLED(uint xms, uchar state2); //从上到下依次点亮或熄灭
//样式5+6：单行从上到下，点亮熄灭
void dhcsdxLED(uint xms, uchar statea); //单行从上到下
//样式7+8：单行从下到上，点亮熄灭
void dhcxdsLED(uint xms, uchar statea); //单行从下到上
//样式9+10+11+12：对角逆时针互相闪烁
void djhxssLEDnsz(uint xms, uint yms, uchar statea); //样式9+10+11+12：对角逆时针互相闪烁
//样式13+14+15+16：对角顺时针时针互相闪烁
void djhxssLEDssz(uint xms, uint yms,uchar statea); //样式13+14+15+16：对角顺时针互相闪烁
//样式17：从下到上点亮然后熄灭，两次
void cxds1(uint xms);
//样式18：从上到下点亮然后熄灭，两次
void csdx1(uint xms);
//样式19：从下到上依次点亮然后从上到下熄灭然后从上到下点亮然后从下到上熄灭
void cxds2(uint xms); //从下到上依次点亮LED然后熄灭然后从上到下点亮然后熄灭         
//样式20：从下到上依次点亮然后从下到上熄灭然后从上到下点亮然后从上到下熄灭
void csdx2(uint xms); //从下到上依次点亮LED然后熄灭然后从上到下点亮然后熄灭         
//样式21+22：逆时针逐个开关，分别点亮或者熄灭
void zgkgLEDnsz(uint xms, uchar statec); //逆时针逐个开关//先开两个，然后关前一个，开下一个
//样式23+24：顺时针逐个开关，分别点亮或者熄灭
void zgkgLEDssz(uint xms, uchar statec); //顺时针逐个开关//先开两个，然后关前一个，开下一个
//样式25：所有的灯全部闪烁x次数
void ssLED(uint xms, uchar sscishu); //所有灯以xms的开关频率闪烁,共闪烁sstime次
void up8LEDycdlxmnsz(uint xmsa, uchar statea); //上边八个LED逆时针一次点亮或熄灭
void down22LEDycdlxmnsz(uint xmsa, uchar statea); //下边22个LED逆时针一次点亮或熄灭
//样式26：依次逆时针点亮
void ycdlLEDnsz(uint xmsa); //依次逆时针点亮
//样式27：依次逆时针熄灭
void ycxmLEDnsz(uint xmsa); //依次逆时针熄灭;
void up8LEDycdlxmssz(uint xmsa, uchar statea); //上边八个LED顺时针一次点亮或熄灭
void down22LEDycdlxmssz(uint xmsa, uchar statea); //下边22个LED顺时针一次点亮或熄灭
//样式28：依次顺时针点亮
void ycdlLEDssz(uint xmsa); //依次顺时针点亮
//样式29：依次顺时针熄灭
void ycxmLEDssz(uint xmsa); //依次顺时针熄灭
//样式30：所有LED逐个打开先顺时针然后逆时针
void allLEDzgdl(uint xmsc); //所有LED逐个开关，先顺时针然后逆时针
//样式31：所有LED逐个熄灭先顺时针然后逆时针
void allLEDzgxm(uint xmsc); //所有LED逐个开关，先顺时针然后逆时针
//样式32：所有LED依次顺时针点亮然后依次熄灭
void allLEDdlxmssz(uint xmsb);
//样式33：所有LED依次逆时针点亮然后依次熄灭
void allLEDdlxmnsz(uint xmsb);
//样式34：所有LED依次电联然后依次熄灭，先顺时针后逆时针
void allLEDdlxm(uint xmsb); //所有的灯依次点亮然后依次熄灭，先顺时针然后逆时针
//红绿分开闪烁1234
void rgfkssLED1(stated);
void rgfkssLED2(stated);
void rgfkssLED3(stated);
void rgfkssLED4(stated);
//红绿灯分开闪烁顺时针
void rgfkssLEDssz(uint xmsd); //红绿分开闪烁
//红绿灯分开闪烁逆时针
void rgfkssLEDnsz(uint xmsd); //红绿分开闪烁
//样式35：所有红绿灯分开闪烁顺时针
void allrgfkssLEDssz(uint xmsd);
//样式36：所有红绿灯分开闪烁逆时针
void allrgfkssLEDnsz(uint xmsd);
//样式37：所有红绿灯分开闪烁,先顺时针后逆时针
void ALLrgfkssLED(uint xmsd, uchar timed);
//样式38：红绿灯分别闪烁
void ssGRLED(uint xms, uchar time3); //红绿分别闪烁
void startled(void);
//随机改变LED样式
void changeLED(uchar r);
#endif // __LED_H