// @Description GameSelectMmapPatch
// @HookAddress 0x7A0B8
// @HookString 01 48 86 46 014 8 00 47 6B A3 07 08 P C0 46 C0 46 C0 46 C0 46 C0 46 C0 46
// Mode: Thumb
// Made by beco

#define sGameSeq (*(volatile unsigned char*) 0x3000C3C)
#define sub_80845F0 ((int (*)()) 0x80845F1)
#define sub_807A700 ((int (*)()) 0x807A701)

__attribute__((no_caller_saved_registers))
void GameSelectMmapPatch() {
    // Vanilla code
    if ( sub_80845F0() && sub_807A700() ) {
        sGameSeq = 0x24;
    }

    // Custom code
    // TODO

}
