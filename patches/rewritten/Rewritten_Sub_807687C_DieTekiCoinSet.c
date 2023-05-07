// @Description Rewritten_Sub_807687C_DieTekiCoinSet
// @HookAddress 0x7687E
// @HookString 024d ae46024d 28470000 af680708 P
// Mode: Thumb
// Made by beco

/* Patch & Hook details
.thumb
    .dcb 1
    ldr r0, .DATA
    mov lr, r0
    ldr r0, .DATA + 4
    bx r0
    .dcb 1
.DATA:
    .word 0x080768AF
    .word 0xAAAAAAAA
 */

#define Sub_80767DC_ScoreBunCoinDasu ((void (*)(unsigned short, unsigned short, int)) 0x80767DD)
#define Sub_801E328_EnemyChildSet ((void (*)(unsigned char, unsigned char, unsigned char, unsigned short, unsigned short)) 0x801E329)

#define ucTekiKillCnt (*(volatile unsigned char*) 0x3000C06)

__attribute__((no_caller_saved_registers))
void Rewritten_Sub_807687C_DieTekiCoinSet(unsigned char k, unsigned short y, unsigned short x, int num) {
    // Vanilla code
    ++ ucTekiKillCnt;
    if(!num) return;
    Sub_80767DC_ScoreBunCoinDasu(y, x, num);    // generate coin
    Sub_801E328_EnemyChildSet(13, 0, 0, y, x);  // generate heart piece
}
