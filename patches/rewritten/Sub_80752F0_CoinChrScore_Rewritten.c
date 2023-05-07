// @Description Sub_80752F0_CoinChrScore_Rewritten
// @HookAddress 0x752F2
// @HookString 02 48 86 46 02 48 00 47 00 00 5B 53 07 08 P
// Mode: Thumb
// Made by beco

#define REG_DMA3SAD (*(volatile unsigned int*) 0x40000D4)
#define REG_DMA3DAD (*(volatile unsigned int*) 0x40000D8)
#define REG_DMA3CNT (*(volatile unsigned int*) 0x40000DC)

#define cGmStScore0 (*(volatile unsigned char*) 0x3000BFC)
#define cGmStScore1 (*(volatile unsigned char*) 0x3000BFD)
#define cGmStScore2 (*(volatile unsigned char*) 0x3000BFE)
#define cGmStScore3 (*(volatile unsigned char*) 0x3000BFF)
#define cGmStScore4 (*(volatile unsigned char*) 0x3000C00)
#define ucGmScore_Tflg (*(volatile unsigned char*) 0x3000C02)

void Sub_80752F0_CoinChrScore_Rewritten() {
    // Custom code

    // Vanilla code
    REG_DMA3SAD = 0x8403AE8 + 32 * cGmStScore4;
    REG_DMA3DAD = 0x6011080;
    REG_DMA3CNT = 0x80000010;

    REG_DMA3SAD = 0x8403AE8 + 32 * cGmStScore3;
    REG_DMA3DAD = 0x60110A0;
    REG_DMA3CNT = 0x80000010;

    REG_DMA3SAD = 0x8403AE8 + 32 * cGmStScore2;
    REG_DMA3DAD = 0x60110C0;
    REG_DMA3CNT = 0x80000010;

    REG_DMA3SAD = 0x8403AE8 + 32 * cGmStScore1;
    REG_DMA3DAD = 0x60110E0;
    REG_DMA3CNT = 0x80000010;

    REG_DMA3SAD = 0x8403AE8 + 32 * cGmStScore0;
    REG_DMA3DAD = 0x6011100;
    REG_DMA3CNT = 0x80000010;

    ucGmScore_Tflg = 0;
}
