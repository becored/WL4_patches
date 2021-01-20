// @Description SeisanSavePatch, will be executed when Wario get into the vortex (escape from a level)
// @HookAddress 0x81262
// @HookString 02 48 86 46 02 48 00 47 00 00 85 12 08 08 P C0 46 C0 46 C0 46 C0 46 C0 46 C0 46 C0 46 C0 46
// Mode: Thumb
// Made by beco

#define PassageID (*(volatile unsigned char*) 0x3000002)
#define InPassageLevelID (*(volatile unsigned char*) 0x3000003)
#define W4ItemStatus ((volatile unsigned char*) 0x3000A68)
#define ucKagiGetFlg (*(volatile unsigned char*) 0x3000C0C)

__attribute__((no_caller_saved_registers))
void SeisanSavePatch() {
    // Vanilla code
    if (ucKagiGetFlg) {
        W4ItemStatus[24 * PassageID + 4 * InPassageLevelID] |= 0x20;
    }

    // Custom code
}
