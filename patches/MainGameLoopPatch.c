// @Description MainGameLoopPatch
// @HookAddress 0x1D4
// @HookString 01 48 86 46 01 48 00 47 ED 01 00 08 P
// Mode: Thumb
// Made by beco

#define usRandomCount (*(volatile unsigned short*) 0x3000006)
#define ucMainTimer (*(volatile unsigned short*) 0x3000C41)

#define Sub_8000954_SetKeyPressWRAM ((void (*)()) 0x8000955)
#define Sub_80007BC_SoftResetCheck ((void (*)()) 0x80007BD)

__attribute__((no_caller_saved_registers))
void MainGameLoopPatch() {
    // Vanilla code
    Sub_8000954_SetKeyPressWRAM();
    Sub_80007BC_SoftResetCheck();
    ++ucMainTimer;
    ++usRandomCount;

    // Custom code
}
