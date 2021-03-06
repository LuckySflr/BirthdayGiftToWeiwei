#ifndef __YLC_H
#define __YLC_H

#define ZDYC_YLC 130      //月亮船E调，最短拍子1/4拍,校准OK

#define YLC_PD0  435 //月亮船片段0   E调
#define YLC_PD1  436 //月亮船片段1   E调
#define YLC_PD2  437 //月亮船片段2   E调
#define YLC_PD3  438 //月亮船片段3   E调
#define YLC_PD4  439 //月亮船片段4   E调
#define YLC_PD5  440 //月亮船片段5   E调
#define YLC_PD6  441 //月亮船片段6   E调
#define YLC_PD7  442 //月亮船片段7   E调
#define YLC_PD8  443 //月亮船片段8   E调
#define YLC_PD9  444 //月亮船片段9   E调
#define YLC_PD10 445 //月亮船片段10  E调
#define YLC_PD11 446 //月亮船片段11  E调
#define YLC_PD12 447 //月亮船片段11  E调

#define YLC_START YLC_PD0
#define YLC_END YLC_PD12

#define yueliangchuan_pd7 yueliangchuan_pd1
#define yueliangchuan_pd4 yueliangchuan_pd2
#define yueliangchuan_pd8 yueliangchuan_pd2
#define yueliangchuan_pd10 yueliangchuan_pd2
#define yueliangchuan_pd9 yueliangchuan_pd3
#define yueliangchuan_pd11 yueliangchuan_pd5

/* //斗地主C调，最短拍子为1/4拍
code uchar doudizhu[]=
{
	// 5,2,2,  5,2,1,  6,2,1,  5,2,2,  3,2,2,  5,2,8,  1,2,2,  1,2,1,  
	// 2,2,1,  1,2,2,  6,1,2,  5,1,8,  6,1,2,  6,1,1,  5,1,1,  6,1,2,  1,2,2,  
	// 2,2,2,  1,2,2,  2,2,2,  3,2,2,  5,2,3,  6,2,1,  5,2,2,  3,2,2,  2,2,8,  
	// 5,2,2,  5,2,1,  6,2,1,  5,2,2,  3,2,2,  5,2,8,  2,2,2,  2,2,1,  3,2,1,  
	// 2,2,2,  1,2,2,  6,1,8,  5,1,2,  6,1,2,  1,2,2,  2,2,2,  3,2,2,  6,2,2,  
	// 3,2,2,  5,2,2,  2,2,3,  3,2,1,  2,2,2,  6,1,2,  1,2,8,  6,2,2,  6,2,1,  
	// 5,2,1,  3,2,2,  5,2,2,  6,2,6,  3,2,2,  5,2,2,  5,2,1,  6,2,1,  5,2,2,  
	// 3,2,2,  5,2,8,  2,2,2,  2,2,1,  3,2,1,  2,2,2,  1,2,2,  2,2,2,  1,2,2,  
	// 6,1,2,  5,1,2,  1,2,8,  1,2,6, 
	0xff,
}; */
/* 南京大学校歌G调，最短音符1/2拍
code unsigned char njdxxg[]=
{
	// 3,2,4, 1,2,4, 5,1,4, 3,2,4, 5,2,4, 4,2,4, 3,2,7,
	// 2,2,4, 2,2,4, 1,2,2, 7,1,2, 1,2,4, 3,2,2, 2,2,2, 2,2,2, 1,2,2, 2,2,4, 5,1,4,
	// 3,2,4, 1,2,4, 5,1,2, 1,2,2, 3,2,4, 5,2,4, 4,2,4, 3,2,4, 2,2,4,
	// 2,2,2, 2,2,2, 3,2,2, 2,2,2, 1,2,2, 7,1,2, 1,2,2, 3,2,2, 3,2,4, 
	// 2,2,2, 1,2,2, 2,2,4, 1,2,4, 5,2,2, 5,2,2, 5,2,2, 5,2,2, 6,2,4, 
	// 5,2,4, 5,2,4, 5,2,4, 5,2,2, 5,2,2, 5,2,4, 6,2,4, 2,2,4, s4,1,4,5,2,4,
	0xff,
}; */
/* 
code uchar yueliangchuan[]=				
{
	6,1,2, 3,2,4, 3,2,2, 3,2,2, 3,2,2, 2,2,2, 3,2,2, 
	0,1,16,		//我能够捉到月亮
	6,1,2, 2,2,4, 2,2,2, 3,2,2, 2,2,2, 1,2,2, 2,2,2,//我将用我数的梦
	0,1,4, 1,2,2, 2,2,2, 3,2,6, 7,1,2, 7,1,4, 1,2,4, 6,1,4, 6,1,4, 6,1,16,	//撑起无数的桨
	6,1,2, 3,2,2, 3,2,2, 3,2,2, 3,2,2, 3,2,2, 3,2,4,
	3,2,2, 3,2,2, 2,2,2, 3,2,2, 0,1,8,//用勇敢和智慧做我的船桨
	6,1,2, 2,2,2, 2,2,2, 2,2,2, 2,2,4, 0,1,4, 
	2,2,6, 6,1,2, 6,1,4, 5,1,4, 6,1,16,//摇着月亮船驶向远方
	5,2,2, 6,2,2, 0,1,6, 3,2,2, 5,2,2, 6,2,2,
	2,2,6, 1,2,2, 1,2,4, 5,1,4, 1,2,2, 2,2,2, 2,2,2, 2,2,2, 3,2,2, 2,2,2, 0,1,6,//如果我能够捉到月亮
	2,2,2, 2,2,2, 3,2,2, 4,2,2, 4,2,6,
	2,2,2, 3,2,2, 4,2,2, 3,2,2, 4,2,2, 3,2,1, 2,2,1, 2,2,4, //我会用蜡笔画出银河的气势
	0,1,2, 2,2,2, 2,2,2, 3,2,2, 4,2,2, 4,2,6, 2,2,2, 1,2,2, 7,1,2, 5,2,2, 5,2,2, 5,2,1, 5,2,1, 5,2,2, 1,2,2, 6,2,2, 6,2,2, 6,2,2, 5,2,1, 6,2,1, 6,2,2, 0,1,2, 4,2,2, 5,2,2, 6,2,6, 5,2,2, 5,2,8, 5,2,16,//我会用算术数清所有的星星把最亮的一颗戴在胸上
	
	6,2,4, 6,2,3, 3,2,1, 5,2,2, 6,2,2, 3,2,2, 5,2,2, 6,2,4, 5,2,2, 3,2,2, 5,2,2, 6,2,2, 0,1,4,//再见了妈妈今晚我就要远航，
	6,2,4, 6,2,3, 3,2,1, 5,2,2, 6,2,2, 3,2,2, 5,2,2, 6,2,2, 5,2,4, 3,2,2, 2,2,2, 5,2,4, 2,2,2, 3,2,16,//别为我担心我有快乐和智慧的桨
	4,2,8,4,2,8, 6,1,8, 4,2,8,//当你醒来
	4,2,2, 4,2,4, 4,2,2, 3,2,2, 4,2,2, 5,2,2, 2,2,2, //千万别告诉别人
	0,1,4, 2,2,2, 2,2,2, 2,2,2, 3,2,2, 4,2,2, 3,2,2, 2,2,2, 2,2,2, 5,2,2, 5,2,4, 5,2,2, 6,2,4, 2,2,4, 3,2,16,	//我正摇着月亮船在银河上远航
	
	
	
	6,2,4, 6,2,3, 3,2,1, 5,2,2, 6,2,2, 3,2,2, 5,2,2, 6,2,4, 5,2,2, 3,2,2, 5,2,2, 6,2,2, 0,1,4,//再见了妈妈今晚我就要远航，
	6,2,4, 6,2,3, 3,2,1, 5,2,2, 6,2,2, 3,2,2, 5,2,2, 6,2,2, 5,2,4, 3,2,2, 2,2,2, 5,2,4, 2,2,2, 3,2,16,//别为我担心我有快乐和智慧的桨
	4,2,8,4,2,8, 6,1,8, 4,2,8,//当你醒来
	4,2,2, 4,2,4, 4,2,2, 3,2,2, 4,2,2, 5,2,2, 2,2,2, //千万别告诉别人
	0,1,4, 2,2,2, 2,2,2, 2,2,2, 3,2,2, 4,2,2, 3,2,2, 2,2,2, 2,2,2, 
	5,2,2, 5,2,4, 5,2,2, 5,2,4, 3,2,2, 6,2,2, 6,2,16,	//我正摇着月亮船在银河上远航
	//间奏	
	1,3,16, 6,2,16, 7,2,6, 3,2,2, 3,2,8, 1,3,16, 6,2,16, 7,2,16, 2,3,16, 7,2,16, 
	
		6,2,4, 6,2,3, 3,2,1, 5,2,2, 6,2,2, 3,2,2, 5,2,2, 6,2,4, 5,2,2, 3,2,2, 5,2,2, 6,2,2, 0,1,4,//再见了妈妈今晚我就要远航，
	6,2,4, 6,2,3, 3,2,1, 5,2,2, 6,2,2, 3,2,2, 5,2,2, 6,2,2, 5,2,4, 3,2,2, 2,2,2, 5,2,4, 2,2,2, 3,2,16,//别为我担心我有快乐和智慧的桨
	4,2,8,4,2,8, 6,1,8, 4,2,8,//当你醒来
	4,2,2, 4,2,4, 4,2,2, 3,2,2, 4,2,2, 5,2,2, 2,2,2, //千万别告诉别人
	0,1,4, 2,2,2, 2,2,2, 2,2,2, 3,2,2, 4,2,2, 3,2,2, 2,2,2, 2,2,2, 
	5,2,2, 5,2,4, 5,2,2, 5,2,4, 3,2,2, 6,2,2, 6,2,16, 
	//我正摇着月亮船在银河上远航

	1,3,4, 6,2,4, 3,2,1, 2,2,1, 0,1,2, 6,1,2, 6,1,1, 7,1,1,  1,2,1, 6,1,1, 7,1,1, 1,2,1, 2,2,1, 7,1,1, 2,2,1, 3,2,1, 4,2,1, 5,2,1, 3,2,1, 4,2,1, 5,2,1, 7,2,1, 6,2,4, 0,1,2, 6,2,2, 	
	0xff,
};
 */
#endif// __YLC_H