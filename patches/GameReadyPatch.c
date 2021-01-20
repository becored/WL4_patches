// @Description GameReadyPatch
// @HookAddress 0x2D0
// @HookString 01 48 86 46 01 48 00 47 31 06 00 08 P
// Mode: Thumb
// Made by beco

// Data
#define VRAM 0x6000000

// IRAM
#define PassageID (*(volatile unsigned char*) 0x3000002)
#define InPassageLevelID (*(volatile unsigned char*) 0x3000003)
#define ucDisConFlg ((volatile unsigned char*) 0x3000012)
#define ucSaveFlg (*(volatile unsigned char*) 0x3000013)
#define ucPerfect (*(volatile unsigned char*) 0x3000015)
#define GlobalGameMode (*(volatile unsigned char*) 0x3000C3A)
#define sGameSeq (*(volatile unsigned short*) 0x3000C3C)
#define cNextFlg (*(volatile unsigned short*) 0x3000C3E)
#define cGmStartFlg ((volatile unsigned short*) 0x3000C3F)
#define usFadeTimer (*(volatile unsigned short*) 0x300188E)
#define sLocalSeq (*(volatile unsigned short*) 0x3002C60)
#define unk_3004A6C (*(volatile unsigned short*) 0x3004A6C)

// I/O
#define REG_BG0VOFS (*(volatile unsigned short*) 0x4000012)
#define REG_BG0HOFS (*(volatile unsigned short*) 0x4000010)
#define REG_BG1VOFS (*(volatile unsigned short*) 0x4000016)
#define REG_BG1HOFS (*(volatile unsigned short*) 0x4000014)
#define REG_BG2VOFS (*(volatile unsigned short*) 0x400001A)
#define REG_BG2HOFS (*(volatile unsigned short*) 0x4000018)
#define REG_DMA3SAD (*(volatile unsigned int*) 0x40000D4)
#define REG_DMA3DAD (*(volatile unsigned int*) 0x40000D8)
#define REG_DMA3CNT (*(volatile unsigned int*) 0x40000DC)

// Subroutine
#define Sub_80917A8_GameReady ((int (*)()) 0x80917A9)

__attribute__((no_caller_saved_registers))
void GameReadyPatch() {
    // Vanilla code
    if (Sub_80917A8_GameReady()) {
      if (cNextFlg == 1) {
        if (ucDisConFlg[0]) {
          sGameSeq = 0;
          GlobalGameMode = 2;
        } else {
          GlobalGameMode = 1;
          if (ucSaveFlg) {
            if ( InPassageLevelID == 6 ){
                 sGameSeq = ucDisConFlg[0];
            } else {
              sGameSeq = 38;
            }
          } else {
            sGameSeq = -2;
            GlobalGameMode = ucDisConFlg[0];
          }
        }
      } else {
        sGameSeq = 0;
        GlobalGameMode = 0;
      }
      cNextFlg = 0;
    }
    cGmStartFlg[0] = 0;

    // Custom code
}
