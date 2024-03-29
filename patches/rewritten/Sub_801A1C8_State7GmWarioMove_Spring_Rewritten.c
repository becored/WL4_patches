// @Description Sub_801A1C8_State7GmWarioMove_Spring_Rewritten
// @HookAddress 0x2DECEC
// @HookString P
// Mode: Thumb
// Made by beco

enum WAR_STAT_NORMAL
{
	WALK,	// 歩き
	TURN,	// 振り返り
	STOP,	// 止まり
	JUMPB,	// ジャンプ前
	JUMP,	// ジャンプ
	SQUAT,	// しゃがみ
	SSLIP,	// しゃがみすべり
	SWALK,	// しゃがみ歩き
	SJUMP,	// しゃがみジャンプ
	STURN,	// しゃがみ振り返り
	WKBRK,	// 歩き止まり
	DSBRK,	// 最速走り止まり
	SLIP,	// すべり始め（坂）
	ROLLB,	// 転がり前
	ROLL,	// 転がり
	RJUMP,	// 転がりジャンプ
	RFLIP,	// 転がり後の跳ね返り
	DOKANU, // 土管上
	DOKAND, // 土管下
	MISS,	// ダメージ
	MISS2,
	HAJIK,	  // 敵はじく
	ATTACK,	  // アタック
	DATTACK,  // 最速アタック
	AJUMP,	  // アタックジャンプ
	DAJUMP,	  // 最速アタックジャンプ
	AFLIP,	  // アタック後の跳ね返り
	HIP,	  // ヒップアタック（空中）
	PHIP,	  // パワーヒップアタック
	HIP2,	  // ヒップアタック（地面）
	PHIP2,	  // パワーヒップアタック（地面）
	FUMI,	  // 踏んづけ跳ね
	LIFT1,	  // 敵持ち上げ（軽い）
	LIFT2,	  // 敵持ち上げ（重い）
	THROW0,	  // 投げ準備
	TAME,	  // 投げ溜め
	THROW1,	  // 投げ（弱）
	THROW2,	  // 投げ（強）
	JTHROW,	  // 飛び投げ
	TAMETURN, // 溜め反転
	LDMOVE,	  // はしご移動
	LDSTOP,	  // はしご止まり
	LDDOWN,	  // はしご飛び落り
	NETMOVEY, // 金網移動Ｙ
	NETMOVEX, // 金網移動Ｘ
	NETSTOP,  // 金網止まり
	NETDOWN,  // 金網飛び落り
	HANERU,	  // 敵地震
	AWATE,	  // はしご・金網落ちる
	GATEIN,	  // 扉入る
	GATEOUT,  // 扉出る
	UPFACE,	  // 上向く
	TSQUAT,	  // 積み木用しゃがみ
	ASERI,	  // あせり
	WAIT0,	  // 待機ポーズ
	WAIT1,	  // 待機ポーズ
	BARBELL0, // バーベル０
	BARBELL1, // バーベル１
	ATWALK,	  // オート歩き
	WAIT2,	  // 縄跳び
	CATCH,	  // 捕らえる
	JCLEAR,	  // 空中でボス戦クリア
	CLRWAIT,  // ボス戦クリア後
	CLRTURN,  // クリア後ターン
	CLRWALK,  // クリア後歩き
	CLRKIME,  // 決めポーズ
	LSTWAIT,  // 宝待ち（ラスボス）
	LSTKIME,  // 決めポーズ（ラスボス）
	LSTAWATE, // 慌てる（ラスボス）

	SLEEP,	// 眠り
	WAKEUP, // 目覚め
	JUMPA,	// 着地
	DASH,	// 最速走り
	DJUMP,	// 最速ジャンプ
	JFLIP,	// 跳ね返り
	CLASH,	// 激突
	TAKARA, // 宝箱
	RPOUSE, // 構え
	GOWALK, // ゴー
};

struct WJEffDef
{
	unsigned char ucStat;
	unsigned char ucAnmTimer; // アニメタイマー
	unsigned char ucAnmPat;	  // アニメパターン
	unsigned short usPosX;	  // Ｘ
	unsigned short usPosY;	  // Ｙ
	unsigned long iAnmAddr;	  // アドレス
};

struct LiftDef
{
	unsigned char ucStat; // STATにより、持ち上げ時補正値を決める
	unsigned char ucWait; // 敵重量 1:軽い 2:重い 0x80立:上投げ
	signed short sDx;	  // 敵の補正座標Ｘ
	signed short sDy;	  // 敵の補正座標Ｙ
	unsigned char unused_1;
	unsigned char unused_2;
};

struct WHitDef
{
	unsigned short usMukiX; // Ｘ移動方向
	unsigned short usMukiY; // Ｙ移動方向
	unsigned char ucFront;	// 前方当りポジション
	unsigned char ucBack;	// 後方当りポジション
	unsigned short sDX;		// 当りによる補正Ｘ

	unsigned char ucSide;  // 横壊れ有り
	unsigned char ucHead;  // 頭壊れ有り
	unsigned char ucYuka;  // 床壊れ有り
	unsigned char ucSPow;  // 横壊しのパワー
	unsigned char ucHPow;  // 頭
	unsigned char ucYPow;  // 床
	unsigned char ucWSide; // 横当りで壊れたとき立てる
	unsigned char ucWHead; // 頭
	unsigned char ucWYuka; // 床
	unsigned char ucPlace;

	unsigned char ucSStop; // 横かべのとき立てる
	unsigned char ucHStop; // 上
	unsigned char ucYStop; // 床
};

#define Sub_8001DA4_m4aSongNumStart ((int (*)(int))0x8001DA5)
#define Sub_806DAC0_PanelYakuAllNum_TileEventId ((int (*)(unsigned short, unsigned short))0x806DAC1)
#define Sub_8014090_WarHeadCheck ((int (*)(unsigned short, unsigned int, int))0x8014091)

#define CurrentEnemyData ((volatile struct EnemyDataStructure *)0x3000104)
#define EntityLeftOverStateList ((volatile unsigned char *)0x3000564)
#define WarioKey_React ((volatile unsigned int *)0x82DEC70)
#define WarioChng_React ((volatile unsigned int *)0x82DECA0)
#define WarioOthr_React ((volatile unsigned int *)0x82DED90)
#define WarioMove_React ((volatile unsigned int *)0x82DECD0)

#define KeyPressContinuous ((volatile unsigned short *)0x3001844)
#define usTrg_KeyPress1Frame ((volatile unsigned short *)0x3001848)
#define Wario_ucReact (*(volatile unsigned char *)0x3001898)
#define Wario_ucStat (*(volatile unsigned char*) 0x3001899)
#define Wario_ucJpNext (*(volatile unsigned char *)0x300189F)
#define Wario_ucTumiki (*(volatile unsigned char *)0x300189E)
#define Wario_ucJpFlg (*(volatile unsigned char *)0x30018A0)
#define Wario_ucJTimer (*(volatile unsigned char *)0x30018A1)
#define Wario_usTimer (*(volatile unsigned short *)0x30018A4)
#define Wario_usMukiX (*(volatile unsigned short *)0x30018A6)
#define Wario_usMukiY (*(volatile unsigned short *)0x30018A8)
#define Wario_usPosX (*(volatile unsigned short *)0x30018AA)
#define Wario_usPosY (*(volatile unsigned short *)0x30018AC)
#define Wario_ucPlace (*(volatile unsigned char*) 0x30018B2)
#define Wario_ucAnmTimer (*(volatile unsigned char *)0x30018B6)
#define Wario_ucAnmPat (*(volatile unsigned char *)0x30018B7)
#define Wario_ucAnmTimer_LOBYTE (*(volatile unsigned char *)0x30018B6)
#define Wario_ucAnmTimer_HIBYTE (*(volatile unsigned char *)0x30018B7)
#define Wario_sMvSpeedX (*(volatile signed short *)0x30018AE)
#define Wario_sMvSpeedY (*(volatile signed short *)0x30018B0)
#define WHit (*(volatile struct WHitDef *)0x3001918)
#define WarJEff (*(volatile struct WJEffDef *)0x3001950)
#define WarJEff_BYTE1 (*(volatile unsigned char *)0x3001951)
#define WarJEff_LOBYTE (*(volatile unsigned char *)0x3001950)
#define WarioLift (*(volatile struct LiftDef *)0x3001948)
#define cGmStartFlg (*(volatile unsigned char *)0x3000C3F)
#define usWarStopFlg (*(volatile unsigned char *)0x30019F6)
#define ucWarOffFlg (*(volatile unsigned char *)0x30019F8)
#define ucDisConFlg (*(volatile unsigned char *)0x3000012)
#define ucGateNum (*(volatile unsigned char *)0x3000025)
#define ucTimeUp (*(volatile unsigned char *)0x3000047)
#define PassageID (*(volatile unsigned char *)0x3000002)
#define InPassageLevelID (*(volatile unsigned char *)0x3000003)
#define CurrentRoomId (*(volatile unsigned char *)0x3000024)
#define usBgEvy (*(volatile unsigned char *)0x3001870)

#define byte_82DD431 ((volatile unsigned char *)0x82DD431)

#define Sub_8075F44_TmScInit ((void (*)())0x8075F45)
#define Sub_801DE7C_EnemyInit ((void (*)())0x801DE7D)
#define Sub_80711E8_GameInit_ColorSetWork_All ((void (*)())0x80711E9)
#define Sub_806BF88_BgmChangeInit ((void (*)())0x806BF89)
#define Sub_801D684_EnemyMain ((void (*)())0x801D685)
#define Sub_8074808_WarioHeartMake ((void (*)())0x8074809)

int Sub_801A1C8_State7GmWarioMove_Spring_Rewritten()
{
  int v0; // r4
  int v2; // [sp+4h] [bp-4h]

  WHit.ucSide = byte_82DD431[8 * Wario_ucStat + 1840];
  WHit.ucHead = byte_82DD431[8 * Wario_ucStat + 1841];
  WHit.ucYuka = byte_82DD431[8 * Wario_ucStat + 1842];
  v0 = 0;
  if ( Wario_ucPlace == 2 )
  {
    v0 = (Wario_sMvSpeedY << 16 >> 19) & 0xFFFF;
    if ( Wario_ucStat != 2 )
      Wario_sMvSpeedY -= 8;
  }
  if ( Wario_sMvSpeedY < -128 )
    Wario_sMvSpeedY = -128;
  Wario_usPosY -= v0;
  Wario_usPosX += Wario_sMvSpeedX << 16 >> 19;
  return v2;
}
