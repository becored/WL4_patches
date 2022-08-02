// @Description Sub_801C1C0_LoadNewRoom_Rewritten_A
// @HookAddress 0x1C218
// @HookString 01 48 86 46 01 48 00 47 59 C2 01 08 P
// Mode: Thumb
// Made by beco

#define unk_8400A68 0x8400A68
#define c_82DF094_cap_Char 0x82DF094
#define REG_DMA3SAD (*(volatile unsigned int*) 0x40000D4)
#define REG_DMA3DAD (*(volatile unsigned int*) 0x40000D8)
#define REG_DMA3CNT (*(volatile unsigned int*) 0x40000DC)

#define Sub_80746C0_LoadBasicElementAndHeartTiles ((void (*)()) 0x80746C1)
#define Sub_801C43C_GmWarInit ((void (*)()) 0x801C43D)

void Sub_801C1C0_LoadNewRoom_Rewritten_A() {
    // Vanilla code
    REG_DMA3SAD = c_82DF094_cap_Char;
    REG_DMA3DAD = 0x6010B00;
    REG_DMA3CNT = 0x80000080;
    Sub_80746C0_LoadBasicElementAndHeartTiles();
    REG_DMA3SAD = unk_8400A68;
    REG_DMA3DAD = 0x5000280;
    REG_DMA3CNT = 0x80000040;
    Sub_801C43C_GmWarInit();
}
