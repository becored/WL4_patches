// @Description Sub_806EC50_WarSidePanel_Attack_Rewritten
// @HookAddress 0x6EC54
// @HookString  024a 9646024a 10470000 0000 6bed0608 P
// Rewritten by blanchon
// Edited by beco

enum WAR_STAT_NORMAL {
	WALK,					//歩き
	TURN,					//振り返り
	STOP,					//止まり
	JUMPB,					//ジャンプ前
	JUMP,					//ジャンプ
	SQUAT,					//しゃがみ
	SSLIP,					//しゃがみすべり
	SWALK,					//しゃがみ歩き
	SJUMP,					//しゃがみジャンプ
	STURN,					//しゃがみ振り返り
	WKBRK,					//歩き止まり
	DSBRK,					//最速走り止まり
	SLIP,					//すべり始め（坂）
	ROLLB,					//転がり前
	ROLL,					//転がり
	RJUMP,					//転がりジャンプ
	RFLIP,					//転がり後の跳ね返り
	DOKANU,					//土管上
	DOKAND,					//土管下
	MISS,					//ダメージ
	MISS2,
	HAJIK,					//敵はじく
	ATTACK,					//アタック
	DATTACK,				//最速アタック
	AJUMP,					//アタックジャンプ
	DAJUMP,					//最速アタックジャンプ
	AFLIP,					//アタック後の跳ね返り
	HIP,					//ヒップアタック（空中）
	PHIP,					//パワーヒップアタック
	HIP2,					//ヒップアタック（地面）
	PHIP2,					//パワーヒップアタック（地面）
	FUMI,					//踏んづけ跳ね
	LIFT1,					//敵持ち上げ（軽い）
	LIFT2,					//敵持ち上げ（重い）
	THROW0,					//投げ準備
	TAME,					//投げ溜め
	THROW1,					//投げ（弱）
	THROW2,					//投げ（強）
	JTHROW,					//飛び投げ
	TAMCURN,				//溜め反転
	LDMOVE,					//はしご移動
	LDSTOP,					//はしご止まり
	LDDOWN,					//はしご飛び落り
	NETMOVEY,				//金網移動Ｙ
	NETMOVEX,				//金網移動Ｘ
	NETSTOP,				//金網止まり
	NETDOWN,				//金網飛び落り
	HANERU,					//敵地震
	AWATE,					//はしご・金網落ちる
	GATEIN,					//扉入る
	GATEOUT,				//扉出る
	UPFACE,					//上向く
	TSQUAT,					//積み木用しゃがみ
	ASERI,					//あせり
	WAIT0,					//待機ポーズ
	WAIT1,					//待機ポーズ
	BARBELL0,				//バーベル０
	BARBELL1,				//バーベル１
	ATWALK,					//オート歩き
	WAIT2,					//縄跳び
	CATCH,					//捕らえる
	JCLEAR,					//空中でボス戦クリア
	CLRWAIT,				//ボス戦クリア後
	CLRTURN,				//クリア後ターン
	CLRWALK,				//クリア後歩き
	CLRKIME,				//決めポーズ
	LSTWAIT,				//宝待ち（ラスボス）
	LSTKIME,				//決めポーズ（ラスボス）
	LSTAWATE,				//慌てる（ラスボス）

	SLEEP,					//眠り
	WAKEUP,					//目覚め
	JUMPA,					//着地
	DASH,					//最速走り
	DJUMP,					//最速ジャンプ
	JFLIP,					//跳ね返り
	CLASH,					//激突
	TAKARA,					//宝箱
	RPOUSE,					//構え
	GOWALK,					//ゴー
};

#define CurrentTileset_EventIdTablePointer (*(volatile unsigned int*) 0x30031FC)

#define Layer0_DecompressedDataPointer (*(volatile unsigned int*) 0x3000054)
#define Layer0_Width (*(volatile unsigned short*) 0x3000058)
#define Layer0_Height (*(volatile unsigned short*) 0x300005a)

#define Layer1_DecompressedDataPointer (*(volatile unsigned int*) 0x300005c)
#define Layer1_Width (*(volatile unsigned short*) 0x3000060)
#define Layer1_Height (*(volatile unsigned short*) 0x3000062)

#define Layer2_DecompressedDataPointer (*(volatile unsigned int*) 0x3000064)
#define Layer2_Width (*(volatile unsigned short*) 0x3000068)
#define Layer2_Height (*(volatile unsigned short*) 0x300006a)

#define PanelPartWork_Broken_Main ((int (*)(int)) 0x806EE99)
#define PanelPartWork_Switch_Main ((int (*)(int,int)) 0x806F425)
#define PanelPartWork_Broken_Destroy ((int (*)(int,int,int)) 0x806F059)
#define PanelPartWork_Broken_Snow ((int (*)(int)) 0x806EFED)



#define Wario_ucReact (*(volatile unsigned char*) 0x3001898)
#define Wario_ucStat (*(volatile unsigned char*) 0x3001899)
#define Wario_usPosX (*(volatile unsigned short*) 0x30018AA)



struct WHitdef {
short usMukiX;
short usMukiY;
char ucFront;
char ucBack;
short sDX;
char ucSide;
char ucHead;
char ucYuka;
char ucSPow;
char ucHPow;
char ucYPow;
char ucWSide;
char ucWHead;
char ucWYuka;
char ucPlace;
char ucSStop;
char ucHStop;
char ucYStop;
char unused_0;
char unused_1;
char unused_2;
};

#define WHit ((volatile struct WHitdef*) 0x3001918)

struct BgBDdef { // found in /src/gmap/Wario_bg_atari.o (gigaleak)
short xp;
short yp;
short part;
char dir;
char coin;
char hit;
char obop;
char SE;
//char undefined;
};


int Sub_806EC50_WarSidePanel_Attack_Rewritten(unsigned short Ypos,unsigned short Xpos)
{
	unsigned int v2;
	unsigned int v3;
  char v4;
  unsigned int v5;
  signed int v6;
  struct BgBDdef v8;

  v2 = Xpos << 16;
	v3 = v2 >> 16;
  v8.xp = (Xpos << 16) >> 22;
  v8.yp = (Ypos << 16) >> 22;
  v8.part = *(unsigned short*)(2 * *(unsigned short*)(2 * (v8.yp * Layer1_Width + v8.xp) + Layer1_DecompressedDataPointer) \
		+ CurrentTileset_EventIdTablePointer);
  v8.coin = 0;
  v8.obop = 0;
  v8.SE = 0;
  v8.hit = WHit[0].ucSPow;
  v8.dir = 1;
  v4 = 0;
  if (!Wario_ucReact)
  {
	  if (Wario_usPosX > v3)
		v8.dir = 2;

	  switch (Wario_ucStat)
    {
      case ROLL:
      case RJUMP:
        goto LABEL_12;
      case ATTACK:
      case AJUMP:
        v8.dir ^= 3u;
        v4 = 1;
        goto def_806ECF4;
      case DATTACK:
      case DAJUMP:
        v8.dir += 4;
        goto LABEL_12;
      default:
def_806ECF4:
        if ( !v4 )
          return v4;
LABEL_12:
        v6 = PanelPartWork_Broken_Main(&v8);
        v4 = v6;
        if ( v6 == 1 )
          return v4;
        if ( v6 == 2 )
          return 0;
        v5 = PanelPartWork_Switch_Main(&v8, 0);
        break;
    }
    goto LABEL_16;
  }
  if ( Wario_ucReact == 6 )
  {
    v8.dir = 5;
    if ( Wario_usPosX > v3 )
      v8.dir = 6;
    v5 = PanelPartWork_Broken_Snow(&v8);
LABEL_16:
    v4 = v5;
  }
  return v4;
}
