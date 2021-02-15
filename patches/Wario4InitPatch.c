// @Description Wario4InitPatch
// @HookAddress 0x5EE0
// @HookString 01 48 86 46 01 48 00 47 F7 5E 00 08 P C0 46
// Mode: Thumb
// Made by beco

#define ucPerfect (*(volatile unsigned char*) 0x3000015)
#define s5_car_y (*(volatile unsigned short*) 0x3002C9C)
#define s5_super_hard (*(volatile unsigned short*) 0x3002CA2)
#define REG_DISPCNT (*(volatile unsigned short*) 0x4000000)

void Wario4InitPatch() {
    // Custom code
    // TODO


    // Vanilla code
    s5_car_y = 150;
    if ( ucPerfect == 1 ) {
        s5_super_hard = 1;
    } else {
        s5_super_hard = 0;
    }
    REG_DISPCNT = 0;
}
