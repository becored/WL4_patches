// @Description Sub_8076658_GmStScoreCalc_Rewritten
// @HookAddress 0x7665A
// @HookString 024d ae46024d 28470000 e1660708 P
// Mode: Thumb
// Made by beco

#define Sub_8094E38__divsi3 ((int (*)(int,int)) 0x8094E39)
#define Sub_8094ED0__modsi3 ((int (*)(int,int)) 0x8094ED1)

#define iGmStageScore (*(volatile int*) 0x3000BF8)
#define cGmStScore ((volatile unsigned char*) 0x3000BFC)
#define ucGmScore_Tflg (*(volatile unsigned char*) 0x3000C02)

void Sub_8076658_GmStScoreCalc_Rewritten(int num) {

  	ucGmScore_Tflg = 1;			// ステージスコアキャラ転送フラグ立てる

  	iGmStageScore += num;
  	if(iGmStageScore < 0)	iGmStageScore = 0;

  	cGmStScore[4] = Sub_8094E38__divsi3(iGmStageScore,10000);
  	if(cGmStScore[4] > 9)
  	{
  		cGmStScore[4] = 9;
  		cGmStScore[3] = 9;
  		cGmStScore[2] = 9;
  		cGmStScore[1] = 9;
  		cGmStScore[0] = 9;
  	}
  	else
  	{
  		//　さらに表示上の１の位は、変化しないので扱わない
  		//	点数計算の内部処理は10分の1で行う
  		cGmStScore[3] = Sub_8094ED0__modsi3(Sub_8094E38__divsi3(iGmStageScore,1000),10);
  		cGmStScore[2] = Sub_8094ED0__modsi3(Sub_8094E38__divsi3(iGmStageScore,100),10);
  		cGmStScore[1] = Sub_8094ED0__modsi3(Sub_8094E38__divsi3(iGmStageScore,10),10);
  		cGmStScore[0] = Sub_8094ED0__modsi3(iGmStageScore,10);
  	}

}
