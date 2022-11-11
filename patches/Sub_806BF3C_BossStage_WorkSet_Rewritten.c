// @Description Sub_806BF3C_BossStage_WorkSet_Rewritten
// @HookAddress 0x6BF3C
// @HookString 01488646 01480047 65b40608 P
// Mode: Thumb
// Made by beco

enum {
	BOSS_NON,		//ボス部屋でない
	BOSS_PASS,		//ボス廊下			ボスステージ↓
	BOSS_HEYA,		//中ボス部屋		ボス部屋↓
	BOSS_YOKI,		//大ボス部屋
};

enum {
	BGYOKI_STOP,			//停止
	BGYOKI_LIGHT_ON,		//画面暗->スポットライトＯＮ
	BGYOKI_LIGHT_WAIT,		//スポットライトＯＮ状態、ＯＦＦ待ち
	BGYOKI_BGEVENT_OFF,		//イベント終了-> (BGYOKI_STOP)へ
};

#define ucWorldNum (*(volatile unsigned char*) 0x3000002)
#define ucStageNum (*(volatile unsigned char*) 0x3000003)
#define ucBossHeya (*(volatile unsigned char*) 0x300001B)
#define ucGmapSubSeq (*(volatile unsigned char*) 0x3000021)
#define ucHeyaNum (*(volatile unsigned char*) 0x3000024)
#define ucBgYoki (*(volatile unsigned char*) 0x3000045)

void Sub_806BF3C_BossStage_WorkSet_Rewritten() {
    // Vanilla code
  	ucBossHeya = BOSS_NON;
  	if( ucStageNum != 4 ) return;

  	//-----
  	ucBossHeya = BOSS_PASS;				// ボスステージ
  	if( ucHeyaNum ) {
  		ucBossHeya = BOSS_HEYA;			// ボス部屋
  		if( ucWorldNum == 5 ) {
  			ucBossHeya = BOSS_YOKI;		// ヨーキ
  			ucGmapSubSeq = 0;
  			ucBgYoki = BGYOKI_STOP; 	// ヨーキ部屋BG-EVENT
  		}
  	}
}
