#ifndef __MUSIC_H
#define __MUSIC_H
#include "test_board.h"

#ifndef __C8051F005_H
#define __C8051F005_H
#include "C8051F000.h"
#endif //__C8051F005_H

#define NT 12        //定时器时钟一个机器周期包括NT个时钟周期
#define FREQUENCY 24 //系统的晶振频率

#include "ceshi.h"
#include "weiwei.h"
#include "bsywjmcxn.h"
#include "nuannuan.h"
#include "pmmry.h"
#include "ghyjn.h"
#include "xiaoxingyun.h"
#include "srklzyl.h"
#include "zdqc.h"
#include "xuemaojiao.h"
#include "chengdu.h"
#include "fcml.h"
#include "znsrkl.h"
#include "ylc.h"

//C调音符和频率对照表
#define CDIAO 1
#define DDIAO 2
#define EDIAO 3
#define FDIAO 4
#define GDIAO 5
#define ADIAO 6
#define BDIAO 7

#define sCDIAO 8     //#C调
#define sDDIAO 9     //#D调
#define sEDIAO FDIAO //#E调
#define sFDIAO 10    //#F调
#define sGDIAO 11    //#G调
#define sADIAO 12    //#A调

#define bDDIAO sCDIAO
#define bEDIAO sDDIAO
#define bFDIAO EDIAO
#define bGDIAO sFDIAO
#define bADIAO sGDIAO
#define bBDIAO sADIAO

#define NUM_FREQUENCY 38

//由于特殊符号：升调符号#不能使用宏，改用s代替
#define ds1 22 //低音1升半音=db2
#define ds2 23 //低音2升半音=db3
#define ds3 4  //低音3升半音=低音4
#define ds4 24 //低音4升半音=db5
#define ds5 25 //低音5升半音=db6
#define ds6 26 //低音6升半音=db7
#define ds7 8  //低音7升半音=中音1

//低音1降半音为重低音7不常用不算在内
#define db2 ds1
#define db3 ds2
#define db4 3
#define db5 ds4
#define db6 ds5
#define db7 ds6

#define s1 27 //1升半音=b2
#define s2 28 //2升半音=b3
#define s3 11 //3升半音=4，为第(7+4)
#define s4 29 //4升半音=b5
#define s5 30 //5升半音=b6
#define s6 31 //6升半音=b7
#define s7 15 //7升半音=高音1，为第(7*2+1)

#define b1 7  //1降半音=低音7，为第7个数
#define b2 s1 //2降半音
#define b3 s2 //3降半音
#define b4 10 //4降半音=3，为(7+3)个数
#define b5 s4 //5降半音
#define b6 s5 //6降半音
#define b7 s6 //7降半音

#define zgy1 37 //重高音1
#define zgy2 38 //重高音2

#define gs1 32   //高音1升半音=gb2
#define gs2 33   //高音2升半音=gb3
#define gs3 18   //高音3升半音=高音4，为第(7*2+4)
#define gs4 34   //高音4升半音=gb5
#define gs5 35   //高音5升半音=gb6
#define gs6 36   //高音6升半音=gb7
#define gs7 zgy1 //高音7升半音=重高音1

#define gb1 14  //高音1降半音=中音7，为第7+7个数
#define gb2 gs1 //高音2降半音=高音1升半音
#define gb3 gs2 //高音3降半音=高音2升半音
#define gb4 17  //高音4降半音=高音3 ，为(7*2+3)个数
#define gb5 gs4 //高音5降半音=高音4升半音
#define gb6 gs5 //高音6降半音=高音5升半音
#define gb7 gs6 //高音7降半音=高音6升半音

#define TOTLE_SONG 21
#define START_SONGNAME ZNSRKL_START //开始第一首歌曲名字

#define REF_YINCHANG 5   //25ms
#define BPYC 300         //半拍音长300
#define ZDYC_NJDXXG 250  //最短音长校歌G调，最短1/2拍
#define ZDYC_HLDDZ 75    //斗地主C调，最短1/4拍
#define ZDYC_ZNSRKL 150  //生日快乐F调，最短1/2拍
#define ZDYC_ZUOBIAN 130 //左边F调，最短1/4拍,校准OK
#define ZDYC_ZCYLN 270  //自从有了你D调，最短1/2拍,校准OK
#define ZDYC_CHUANQI 220 //传奇D调，最短1/4拍,校准OK
#define ZDYC_YUJIAN 160  //遇见D调，最短1/4拍，校准OK
#define ZDYC_PYGHLKN 125 //漂洋过海来看你D调，1分钟60拍，最短音符1/8拍,校准OK
#define ZDYC_HYL 125     //好运来，D调，1分钟132拍,最短音符1/4拍,校准OK
#define ZDYC_HRZ 105      //好日子 F调，最短音符1/4拍,校准OK
#define ZDYC_QZGY 125    //青藏高原李娜 E调，1分钟58拍最短音符1/8拍,校准OK


/* #define YLC 0 //月亮船E调，最短拍子1/4拍
#define YLC_START YLC
#define YLC_END YLC */

#define HLDDZ 1           //斗地主C调，最短1/4拍
#define HLDDZ_START HLDDZ //斗地主C调，最短1/4拍
#define HLDDZ_END HLDDZ   //斗地主C调，最短1/4拍

// #define ZNSRKL 2            //生日快乐F调，最短1/2拍
// #define ZNSRKL_START ZNSRKL //生日快乐F调，最短1/2拍
// #define ZNSRKL_END ZNSRKL   //生日快乐F调，最短1/2拍

#define ZUOBIAN_PD0 3  //左边片段0
#define ZUOBIAN_PD1 4  //左边片段1，最短1/4拍
#define ZUOBIAN_PD2 5  //左边片段2
#define ZUOBIAN_PD3 6  //左边片段3
#define ZUOBIAN_PD4 7  //左边片段4
#define ZUOBIAN_PD5 8  //左边片段5
#define ZUOBIAN_PD6 9  //左边片段6
#define ZUOBIAN_PD7 10 //左边片段7
#define ZUOBIAN_PD8 11 //左边片段8
#define ZUOBIAN_PD9 12 //左边片段8
#define ZUOBIAN_START ZUOBIAN_PD0
#define ZUOBIAN_END ZUOBIAN_PD9

//自从有了你，赵薇，1分钟220拍，D调，最短音符1/2拍
#define ZCYLN_PD0 13 //自从有了你片段0
#define ZCYLN_PD1 14 //自从有了你片段1
#define ZCYLN_PD2 15 //自从有了你片段2
#define ZCYLN_PD3 16 //自从有了你片段3
#define ZCYLN_PD4 17 //自从有了你片段4
#define ZCYLN_PD5 18 //自从有了你片段5
#define ZCYLN_PD6 19 //自从有了你片段6
#define ZCYLN_PD7 20 //自从有了你片段7
#define ZCYLN_PD8 21 //自从有了你片段8
#define ZCYLN_PD9 22 //自从有了你片段9

#define ZCYLN_START ZCYLN_PD0
#define ZCYLN_END ZCYLN_PD9

//传奇-王菲  E调，最短音符1/4拍
#define CHUANQI_PD0 23  //传奇片段0
#define CHUANQI_PD1 24  //传奇片段1
#define CHUANQI_PD2 25  //传奇片段2
#define CHUANQI_PD3 26  //传奇片段3
#define CHUANQI_PD4 27  //传奇片段4
#define CHUANQI_PD5 28  //传奇片段5
#define CHUANQI_PD6 29  //传奇片段6
#define CHUANQI_PD7 30  //传奇片段7
#define CHUANQI_PD8 31  //传奇片段8
#define CHUANQI_PD9 32  //传奇片段9
#define CHUANQI_PD10 33 //传奇片段10
#define CHUANQI_PD11 34 //传奇片段11
#define CHUANQI_PD12 35 //传奇片段12
#define CHUANQI_PD13 36 //传奇片段13
#define CHUANQI_PD14 37 //传奇片段14
#define CHUANQI_START CHUANQI_PD0
#define CHUANQI_END CHUANQI_PD14

//遇见-孙燕姿，1=G转bB，每分钟92拍，最短音符	1/4拍
#define YUJIAN_PD0 38 //遇见片段0
#define YUJIAN_PD1 39 //遇见片段1
#define YUJIAN_PD2 40 //遇见片段2
#define YUJIAN_PD3 41 //遇见片段3
#define YUJIAN_PD4 42 //遇见片段4
#define YUJIAN_PD5 43 //遇见片段5
#define YUJIAN_PD6 44 //遇见片段6

#define YUJIAN_START YUJIAN_PD0
#define YUJIAN_END YUJIAN_PD6

#define PYGHLKN_PD0 45  //漂洋过海来看你片段0
#define PYGHLKN_PD1 46  //漂洋过海来看你片段1
#define PYGHLKN_PD2 47  //漂洋过海来看你片段2
#define PYGHLKN_PD3 48  //漂洋过海来看你片段3
#define PYGHLKN_PD4 49  //漂洋过海来看你片段4
#define PYGHLKN_PD5 50  //漂洋过海来看你片段5
#define PYGHLKN_PD6 51  //漂洋过海来看你片段6
#define PYGHLKN_PD7 52  //漂洋过海来看你片段7
#define PYGHLKN_PD8 53  //漂洋过海来看你片段8
#define PYGHLKN_PD9 54  //漂洋过海来看你片段9
#define PYGHLKN_PD10 55 //漂洋过海来看你片段10
#define PYGHLKN_PD11 56 //漂洋过海来看你片段11
#define PYGHLKN_PD12 57 //漂洋过海来看你片段12
#define PYGHLKN_PD13 58 //漂洋过海来看你片段13
#define PYGHLKN_PD14 59 //漂洋过海来看你片段14

#define PYGHLKN_START PYGHLKN_PD0
#define PYGHLKN_END PYGHLKN_PD14

#define pyghlkn_pd6 pyghlkn_pd1
#define pyghlkn_pd7 pyghlkn_pd2
#define pyghlkn_pd11 pyghlkn_pd2
#define pyghlkn_pd8 pyghlkn_pd3
#define pyghlkn_pd9 pyghlkn_pd4
#define pyghlkn_pd13 pyghlkn_pd4

#define HYL_PD0 60 //好运来片段0
#define HYL_PD1 61 //好运来片段1
#define HYL_PD2 62 //好运来片段2
#define HYL_PD3 63 //好运来片段3
#define HYL_PD4 64 //好运来片段4
#define HYL_PD5 65 //好运来片段5
#define HYL_PD6 66 //好运来片段6
#define HYL_PD7 67 //好运来片段7
#define HYL_PD8 68 //好运来片段8
#define HYL_PD9 69 //好运来片段9
#define HYL_START HYL_PD0
#define HYL_END HYL_PD9

#define hyl_pd2 hyl_pd1
#define hyl_pd5 hyl_pd1
#define hyl_pd6 hyl_pd3
#define hyl_pd8 hyl_pd3

#define HRZ_PD1 70 //好日子片段1
#define HRZ_PD2 71 //好日子片段2
#define HRZ_PD3 72 //好日子片段3
#define HRZ_START HRZ_PD1
#define HRZ_END HRZ_PD3

#define hrz_pd2 hrz_pd1

#define QZGY_PD0 73 //青藏高原片段0
#define QZGY_PD1 74 //青藏高原片段1
#define QZGY_PD2 75 //青藏高原片段2
#define QZGY_PD3 76 //青藏高原片段3
#define QZGY_PD4 77 //青藏高原片段4
#define QZGY_START QZGY_PD0
#define QZGY_END QZGY_PD4

#define qzgy_pd3 qzgy_pd1

#define NJDXXG 500 //校歌G调，最短1/2拍
#define NJDXXG_START NJDXXG
#define NJDXXG_END NJDXXG

//音量占空比控制
#define TOTLE_DUTY_MUSIC 1
#define DUTY_HIGH_MUSIC 0.5
#define DUTY_LOW_MUSIC (TOTLE_DUTY_MUSIC - DUTY_HIGH_MUSIC)
//函数声明
void cal_TH0TL0(uchar refyinchang);
unsigned int length_array(unsigned char *ge_name);
sbit beep = P3 ^ 2;
void Timer0and1_Init(void);
void Diaogao(uchar);
uint cal_Yinfu(uchar *gemingzi);
uchar *cal_Gename(uint);   //1、歌名
void cal_Diaoname(uint);   //2、调名
uchar length_Yin(uint);    //3、音长
uint total_Yinfu(uint);    //4、音符的数量
void song(uint name_song); //确定要唱的歌曲的参数
//判断歌名字是否为歌曲的最后一个片段，若是则返回0，若不是返回1
uchar songname_panduan(uint name);
void huange(uint geming1);
void huangeready(void);

#endif // __MUSIC_H
