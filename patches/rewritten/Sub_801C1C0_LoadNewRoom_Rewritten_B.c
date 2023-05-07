// @Description Sub_801C1C0_LoadNewRoom_Rewritten_B
// @HookAddress 0x1C2AE
// @HookString 02 48 86 46 02 48 00 47 00 00 19 C3 01 08 P
// Mode: Thumb
// Made by beco

#define cGmStartFlg (*(volatile unsigned char*) 0x3000C3F)
#define usWarStopFlg (*(volatile unsigned char*) 0x30019F6)
#define ucWarOffFlg (*(volatile unsigned char*) 0x30019F8)
#define ucDisConFlg (*(volatile unsigned char*) 0x3000012)
#define ucGateNum (*(volatile unsigned char*) 0x3000025)
#define ucTimeUp (*(volatile unsigned char*) 0x3000047)
#define PassageID (*(volatile unsigned char*) 0x3000002)
#define InPassageLevelID (*(volatile unsigned char*) 0x3000003)
#define usBgEvy (*(volatile unsigned char*) 0x3001870)

#define Sub_8075F44_TmScInit ((void (*)()) 0x8075F45)
#define Sub_801DE7C_EnemyInit ((void (*)()) 0x801DE7D)
#define Sub_80711E8_GameInit_ColorSetWork_All ((void (*)()) 0x80711E9)
#define Sub_806BF88_BgmChangeInit ((void (*)()) 0x806BF89)
#define Sub_801D684_EnemyMain ((void (*)()) 0x801D685)
#define Sub_8074808_WarioHeartMake ((void (*)()) 0x8074809)

void Sub_801C1C0_LoadNewRoom_Rewritten_B() {
    // Vanilla code
    Sub_8075F44_TmScInit();
    Sub_801DE7C_EnemyInit();
    Sub_80711E8_GameInit_ColorSetWork_All();
    Sub_806BF88_BgmChangeInit();
    int v0 = cGmStartFlg;
    if ( !cGmStartFlg ) {
      Sub_801D684_EnemyMain();
      Sub_8074808_WarioHeartMake();
      cGmStartFlg = 1; // set ingame state
      usWarStopFlg = v0;
      ucWarOffFlg = 0;
      if ( !ucDisConFlg && !ucGateNum ) {
        ucTimeUp = 0;
        if ( (PassageID || InPassageLevelID != 2) && InPassageLevelID != 4 ) {
          usWarStopFlg = 1000;
          ucWarOffFlg= 1;
        }
      }
    }
    usBgEvy = 15;
}
