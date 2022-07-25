// @Description Sub_801B8BC_GameMain_End_Rewritten
// @HookAddress 0x1BB4C
// @HookString 01 48 86 46 01 48 00 47 99 BB 01 08 P
// Mode: Thumb
// Made by beco

#define Sub_806C75C_GmapBg_AnimatedMain ((void (*)()) 0x806C75D)
#define Sub_801D684_EnemyMain ((void (*)()) 0x801D685)
#define Sub_806E7F8_GmScrSet ((void (*)()) 0x806E7F9)
#define Sub_8010154_WarioDispMain ((void (*)()) 0x8010155)
#define Sub_8074808_WarioHeartMake ((void (*)()) 0x8074809)
#define Sub_8074988_GmScoreCreate ((void (*)()) 0x8074989)
#define Sub_80751FC_TmScMain ((void (*)()) 0x80751FD)
#define Sub_801C5D8_GmWarioCreate ((void (*)()) 0x801C5D9)
#define Sub_801D8C4_EnemyDisplayMain ((void (*)()) 0x801D8C5)
#define Sub_8000A0C_ClearOamBuf ((int (*)()) 0x8000A0D)
#define Sub_806C794_GmapSceneCreate ((void (*)(int)) 0x806C795)
#define Sub_80101D0_WarioSoundMain ((void (*)()) 0x80101D1)
#define Sub_806C130_MapBgmChangeMain ((void (*)()) 0x806C131)

#define REG_DMA3SAD (*(volatile unsigned int*) 0x40000D4)
#define REG_DMA3DAD (*(volatile unsigned int*) 0x40000D8)
#define REG_DMA3CNT (*(volatile unsigned int*) 0x40000DC)

#define sGameSeq (*(volatile unsigned char*) 0x3000C3C)
#define ucWarOffFlg (*(volatile unsigned char*) 0x30019F8)

void Sub_801B8BC_GameMain_End_Rewritten() {
    // Custom code

    // Vanilla code
    int v6;
    if ( sGameSeq )  // run inside all the time except loading new room
    {
      Sub_806C75C_GmapBg_AnimatedMain();
      Sub_801D684_EnemyMain();
      if ( !ucWarOffFlg ) // hide wario (when wario come out from a vortex)
      {
        Sub_806E7F8_GmScrSet();
        Sub_8010154_WarioDispMain();
      }
      Sub_8074808_WarioHeartMake();
      Sub_8074988_GmScoreCreate();
      Sub_80751FC_TmScMain();
      if ( !ucWarOffFlg )
        Sub_801C5D8_GmWarioCreate();
      Sub_801D8C4_EnemyDisplayMain();
      v6 = Sub_8000A0C_ClearOamBuf();
      Sub_806C794_GmapSceneCreate(v6);
    }
    Sub_80101D0_WarioSoundMain();
    Sub_806C130_MapBgmChangeMain();
}
