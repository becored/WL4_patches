// @Description Rewrite Sub_806FD74_WarioBgAttackCheck_Center
// @HookAddress 0x6FD7E
// from 0x6FD7E to 0x6FF54, no passed-in param
// @HookString 024a 9646024a 10470000 55ff0608 P
// @EntryFunctionSymbol Sub_806FD74_WarioBgAttackCheck_Center

/* Patch & Hook details
 
 .thumb
    .dcb 1
    ldr r2, .DATA
    mov lr, r2
    ldr r2, .DATA + 4
    bx r2
    .dcb 1
  .DATA:
    .word 0x0806FF55
    .word 0xAAAAAAAA
 */

/**
 * changelog: 
 * directly modified from the IDA pro's generated C code.
 * add logic to asynchronize Layer 0 and Layer 3.
 *            ---- by ssp (shinespeciall), 2022/09/01
 */

#define ucGateNum (*(volatile unsigned char*) 0x3000025)
#define ucSTEndType (*(volatile unsigned char*) 0x3000048)

#define Layer0_DecompressedDataPointer (*(volatile unsigned short**) 0x3000054)
#define Layer0_Width (*(volatile unsigned short*) 0x3000058)
#define Layer0_Height (*(volatile unsigned short*) 0x300005a)
#define Layer1_DecompressedDataPointer (*(volatile unsigned short**) 0x300005c)
#define Layer1_Width (*(volatile unsigned short*) 0x3000060)
#define Layer1_Height (*(volatile unsigned short*) 0x3000062)
#define Layer2_DecompressedDataPointer (*(volatile unsigned short**) 0x3000064)
#define Layer2_Width (*(volatile unsigned short*) 0x3000068)
#define Layer2_Height (*(volatile unsigned short*) 0x300006a)

#define CurrentRoomHeader_Layer0MappingType (*(volatile unsigned char*) 0x3000075)
#define CurrentRoomHeader_Layer1MappingType (*(volatile unsigned char*) 0x3000076)
#define CurrentRoomHeader_Layer2MappingType (*(volatile unsigned char*) 0x3000077)
// #define CurrentRoomHeader_Layer3MappingType (*(volatile unsigned char*) 0x3000078)

#define ucJSwitchOnFlg (*(volatile unsigned char*) 0x03000C0D)

#define sGameSeq (*(volatile short*) 0x3000C3C)
#define cGmStartFlg (*(volatile char*) 0x3000C3F)

#define usBg0Hofs (*(volatile unsigned short*) 0x3001876)
#define usBg0Vofs (*(volatile unsigned short*) 0x3001878)
#define usBg1Hofs_CameraXPos (*(volatile unsigned short*) 0x300187A)
#define usBg1Vofs_CameraYPos (*(volatile unsigned short*) 0x300187C)
#define usBg2Hofs (*(volatile unsigned short*) 0x300187E)
#define usBg2Vofs (*(volatile unsigned short*) 0x3001880)
#define usBg3Hofs (*(volatile unsigned short*) 0x3001882)
#define usBg3Vofs (*(volatile unsigned short*) 0x3001884)
#define Wario_ucReact (*(volatile char*) 0x3001898)
#define Wario_ucStat (*(volatile char*) 0x3001899)

#define Wario_usMukiX  (*(volatile short*) 0x30018A6) // face right: 0x10, face left: 0x20
#define Wario_usPosX  (*(volatile short*) 0x30018AA) // rightwards positive
#define Wario_usPosY  (*(volatile short*) 0x30018AC) // downwards positive
#define Wario_speed_X (*(volatile short*) 0x30018AE)
#define Wario_speed_Y (*(volatile short*) 0x30018B0)
#define Wario_sHitDX1 (*(volatile short*) 0x30018CA) // seems always negative
#define Wario_sHitDY1 (*(volatile short*) 0x30018CC) // seems always negative
#define Wario_sHitDX2 (*(volatile short*) 0x30018CE)

#define CurrentTileset_TerrainTypeTablePointer (*(volatile unsigned char**) 0x30031F8)
#define CurrentTileset_EventIdTablePointer (*(volatile unsigned short**) 0x30031FC)

// functions
#define Sub_806DDE4_PanelPartWork_Warp_DoorType2 ((int (*)(int, int)) 0x806DDE5)
#define Sub_8001DA4_m4aSongNumStart ((void (*)(int)) 0x8001DA5)

#define Sub_806E01C_GateFadeType_CHECK_NextRoom ((void (*)(int)) 0x806E01D)
#define Sub_80025C8_MPlayStop_rev01 ((void (*)(int, int, int)) 0x80025C9)
#define Sub_8001F3C_m4aMPlayFadeOut ((void (*)(int, unsigned short)) 0x8001F3D)
#define Sub_806FF64_PanelPartWork_Touch_Light ((int (*)(int*, int)) 0x806FF65)
#define Sub_8094E00_call_via_r1 ((int (*)(int, int)) 0x8094E01)

#define Sub_806BB4C_GmapBgVramInitSet ((void (*)(unsigned char bgnum)) 0x806BB4D)

// custom structures 
struct EmpBlkdef
{
	unsigned short position;
	unsigned short tileID;
};

// custom variables for restoring crystals
#define EXBACKUP_FIELD_EMPBLK ((volatile struct EmpBlkdef *) 0x203E000)
#define usDisConR_EmpBlk (*(volatile unsigned short *) 0x3006F00)

#define EXMAPFILADR 0x2000000
#define EXBACKUP_FIELD 0x203A000

// change these before applying patch
#define RespawnEnemiesEventID 0xA1
// unsigned char EnemiesHaveBeenRevivedRoomList[0x10], custom variables
#define EnemiesHaveBeenRevivedRoomList ((volatile unsigned char*) 0x3006280)

void RestoreRemovedTiles()
{
	int n, a, c;
    // restore tiles saved in EXBACKUP_FIELD_EMPBLK
    if (usDisConR_EmpBlk)
    {
        for (n = 0; n != usDisConR_EmpBlk; n++)
        {
            a = EXBACKUP_FIELD_EMPBLK[n].position << 1;
            *(short *)(EXMAPFILADR + a) = EXBACKUP_FIELD_EMPBLK[n].tileID;
        }
    }
    Sub_806BB4C_GmapBgVramInitSet(1);
}

void Sub_806FD74_WarioBgAttackCheck_Center()
{
    int v0; // r12
    int v1; // r6
    int v6; // r0
    unsigned int v8; // r7
    int v12; // r1
    int v13; // r2
    unsigned int v15[2]; // [sp+0h] [bp-58h] BYREF
    int v16[2]; // [sp+8h] [bp-50h] BYREF
    int v17[2]; // [sp+10h] [bp-48h] BYREF
    int v18[2]; // [sp+18h] [bp-40h] BYREF

    v18[0] = ((Wario_sHitDX2 << 16 >> 17) + Wario_usPosX) >> 6;// wario x
    v18[1] = ((Wario_sHitDX1 << 16 >> 17) + Wario_usPosX) >> 6;// wario x
    v0 = ((Wario_sHitDY1 << 16 >> 17) + Wario_usPosY) >> 6;// wario y

    int v18_L2[2];
    int delta_L1_to_L2_X = (int)usBg2Hofs - (int)usBg1Hofs_CameraXPos;
    int delta_L1_to_L2_Y = (int)usBg2Vofs - (int)usBg1Vofs_CameraYPos;
    v18_L2[0] = ((Wario_sHitDX2 << 16 >> 17) + Wario_usPosX + delta_L1_to_L2_X) >> 6;
    v18_L2[1] = ((Wario_sHitDX1 << 16 >> 17) + Wario_usPosX + delta_L1_to_L2_X) >> 6;
    int v0_L2 = ((Wario_sHitDY1 << 16 >> 17) + Wario_usPosY + delta_L1_to_L2_Y) >> 6;

    int v18_L0[2];
    int delta_L1_to_L0_X = (int)usBg0Hofs - (int)usBg1Hofs_CameraXPos;
    int delta_L1_to_L0_Y = (int)usBg0Vofs - (int)usBg1Vofs_CameraYPos;
    v18_L0[0] = ((Wario_sHitDX2 << 16 >> 17) + Wario_usPosX + delta_L1_to_L0_X) >> 6;
    v18_L0[1] = ((Wario_sHitDX1 << 16 >> 17) + Wario_usPosX + delta_L1_to_L0_X) >> 6;
    int v0_L0 = ((Wario_sHitDY1 << 16 >> 17) + Wario_usPosY + delta_L1_to_L0_Y) >> 6;

    v1 = 0;
    do
    {
        v16[v1] = CurrentTileset_EventIdTablePointer[Layer1_DecompressedDataPointer[(v0 * Layer1_Width + v18[v1])]];
        v17[v1] = CurrentTileset_EventIdTablePointer[Layer2_DecompressedDataPointer[(v0_L2 * Layer2_Width + v18_L2[v1])]];
        if ( CurrentRoomHeader_Layer0MappingType == 0x10 )
            v6 = CurrentTileset_EventIdTablePointer[Layer0_DecompressedDataPointer[v0_L0 * Layer0_Width + v18_L0[v1]]];
        else
            v6 = 0;
        v15[v1] = v6;
        ++v1;
    }
    while ( v1 <= 1 );
    v1 = 0;
    v8 = v0 & 0xFFFF;
    do // the vanilla C code generated by IDA pro here looks weird, and v17 is not an array, i tewak the logic here to make it looks correct
    {
        if ( v16[v1] == 3 || v17[v1] == 3)                            // current event id == 3, room edge warp door trigger
        {
            if ( Sub_806DDE4_PanelPartWork_Warp_DoorType2(v8, v18[v1]) )
            return;
        }
        else if ( v16[v1] == 9 || v17[v1] == 9)                        // current event id == 9, bonus room glowing area warp
        {
            if ( Sub_806DDE4_PanelPartWork_Warp_DoorType2(v8, v18[v1]) )
            {
                Sub_8001DA4_m4aSongNumStart(25);
                return;
            }
        }
        else if ( v16[v1] == 8 || v17[v1] == 8 )                        // current event id == 8, boss level corrider exit door trigger
        {
            ucSTEndType = 6;
            ucGateNum = 0;
            cGmStartFlg = 0;
            sGameSeq = 3;
            Sub_806E01C_GateFadeType_CHECK_NextRoom(2);
            Sub_80025C8_MPlayStop_rev01(0x3006240, v12, v13);  // the latter 2 params are possibly useless
            Sub_8001F3C_m4aMPlayFadeOut(0x30060F0, 2u);
            Sub_8001F3C_m4aMPlayFadeOut(0x3006170, 2u);
            Sub_8001F3C_m4aMPlayFadeOut(0x30061B0, 2u);
            return;
        }
        // Custom Code: re-initialize my variables
        else if ( v16[v1] == RespawnEnemiesEventID || v17[v1] == RespawnEnemiesEventID )
        {
            if (ucJSwitchOnFlg == 1)
            {
                for (int i = 0; i < 0x10; ++i)
                {
                    EnemiesHaveBeenRevivedRoomList[i] = 0;
                }
                RestoreRemovedTiles();
            }
        }
        ++v1;
    }
    while ( v1 <= 1 );
    if ( Wario_ucReact == 9 )                     // bat wario
    {
        if ( Wario_ucStat )
            Sub_806FF64_PanelPartWork_Touch_Light(v15, 4);// v16 gets water or light event id
    }
    else if ( Wario_ucReact > 9u )
    {
        if ( Wario_ucReact == 10 && Wario_ucStat != 6 && (v16[0] == 125 || v16[1] == 125) )
            Sub_8094E00_call_via_r1(6, 0x801B281);
    }
    else if ( Wario_ucReact == 5 && Wario_ucStat )// zombie wario
    {
        Sub_806FF64_PanelPartWork_Touch_Light(v15, 10);// v16 gets water or light event id
    }
    return;
}
