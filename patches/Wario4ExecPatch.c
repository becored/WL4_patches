// @Description Wario4ExecPatch
// @HookAddress 0x3694
// @HookString 01 48 86 46 01 48 00 47 07 39 00 08 P C0 46 C0 46 C0 46 C0 46
// Mode: Thumb
// Made by beco

#define usFadeTimer (*(volatile unsigned short*) 0x300188E)
#define Sub_8005F1C_Wario4_Exec ((void (*)(int)) 0x8005F1D)

__attribute__((no_caller_saved_registers))
void Wario4ExecPatch() {
    // Vanilla code
    Sub_8005F1C_Wario4_Exec( usFadeTimer++ );

    // Custom code
    // TODO


}
