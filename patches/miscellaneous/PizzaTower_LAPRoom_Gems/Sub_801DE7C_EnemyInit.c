// @Description a function wrapper patch for Sub_801DE7C_EnemyInit generated by Ghidra script: WL4FuncExporter.py
// function starts at: 0x1DE7C

// @HookAddress 0x1DE7E
// Changelog:
// v1.0 on 2024/04/28 by ssp
// create patch and add the respawn logic

/** starts from 1DE7E, no alignment byte needed
 *  ends at 1DEB2 with a branch instruction to jump out
 * .thumb
      .dcb 1
      ldr r0, .DATA
      mov lr, r0
      ldr r0, .DATA + 4
      bx r0
      .dcb 1
 * .DATA:
      .word 0x0801DEB3
      .word 0xAAAAAAAA
 */
// @HookString 0248 86460248 00470000 b3de0108 P

#define cPauseFlag (*(volatile unsigned char*) 0x3000c35)
#define ucDisConFlg (*(volatile unsigned char*) 0x3000012)

#define Sub_801DEC0_LoadEntitySet ((void (*)(void)) 0x801dec1)
#define Sub_801E060_EnemyPlacementRoomExpansionDataBuffInit ((void (*)()) 0x801e061)
#define Sub_801DFF8_EnemyPlacementRoomsFlagBufferInit ((void (*)()) 0x801dff9)
#define Sub_801E0D4_ClearAllTheEntitySlotInit ((void (*)()) 0x801e0d5)
#define Sub_801E1C0_EnemyMapOutStartScreen ((void (*)()) 0x801e1c1)
#define Sub_801E258_EnemyMapOutOutOfScreen ((void (*)(int)) 0x801e259)

// 00(Entry) 01(Emerald) 02(Ruby) 03(Topaz) 04(Sapphire) 05(Golden) 06(Sound Room)
#define CurrentPassage (*(volatile unsigned char*) 0x3000002)
// 00(first lvl) 01(second lvl) 02(third lvl) 03(fourth lvl) 04(Boss) 05(Mini-Game Shop)
#define CurrentLevel (*(volatile unsigned char*) 0x3000003)
#define CurrentRoom (*(volatile unsigned char*) 0x03000024)

#define ucJSwitchOnFlg (*(volatile unsigned char*) 0x03000C0D)

// from 0x3000564 to 0x3000964
#define EntityStateSlotInRoom ((volatile unsigned char*) 0x3000564)
struct SpriteSetLoadInfo {
    unsigned char global_id;
    unsigned char palette_offset;
};
#define EntitySetPointerTable ((volatile struct SpriteSetLoadInfo**) 0x878EF78)
struct EntityLoadInfo {
    unsigned char YPos;
    unsigned char XPos;
    unsigned char EntityIdInEntityset;
};
#define CurrentEntityLoadInfoList ((volatile unsigned char*) 0x3000964)

// change these before applying patch
#define LAPROOMID 3 // we only revive diamonds in this Room
// unsigned char EnemiesHaveBeenRevivedRoomList[0x10], custom variables
#define EnemiesHaveBeenRevivedRoomList ((volatile unsigned char*) 0x3006280)

void Sub_801DE7C_EnemyInit()
{
    // Custom Code: initialize my variables before pressing frog switch
    if (!ucJSwitchOnFlg)
    {
        for (int i = 0; i < 0x10; ++i)
        {
            EnemiesHaveBeenRevivedRoomList[i] = 1;
        }
    }

    // vanilla logic
    Sub_801DEC0_LoadEntitySet();
    if ( !cPauseFlag )
    {
        Sub_801E060_EnemyPlacementRoomExpansionDataBuffInit();
        if ( !ucDisConFlg )
        {
            // vanilla logic
            Sub_801DFF8_EnemyPlacementRoomsFlagBufferInit();

            // Custom Code: this has to be done after the initialization of CurrentEntityLoadInfoList[]
            if (ucJSwitchOnFlg == 1)
            {
                if (!CurrentPassage && !CurrentLevel && !cPauseFlag && EnemiesHaveBeenRevivedRoomList[CurrentRoom] == 0)
                {
                    unsigned char *p_EntityStateSlotInRoom = &EntityStateSlotInRoom[64 * CurrentRoom];
                    // We revive every enemy including the diamonds in Room 0
                    if (CurrentRoom == LAPROOMID)
                    {
                        for (int i = 0; i < 64; ++i)
                        {
                            // if the current enemy is dead
                            if (*p_EntityStateSlotInRoom == 2) {
                                // revive it
                                *p_EntityStateSlotInRoom = 0;
                            }
                            p_EntityStateSlotInRoom++;
                        }
                        EnemiesHaveBeenRevivedRoomList[CurrentRoom] = 1;
                    }
                    else
                    { // in other Room, We revive every emeny except the diamonds
                        for (int i = 0; i < 64; ++i)
                        {
                            // don't change the stats of diamonds in this Room
                            unsigned char cur_local_enemy_id = CurrentEntityLoadInfoList[3 * i + 2];
                            if (cur_local_enemy_id < 0x10)
                            {
                                p_EntityStateSlotInRoom++;
                                continue;
                            }

                            // if the current enemy is dead
                            if (*p_EntityStateSlotInRoom == 2) {
                                // revive it
                                *p_EntityStateSlotInRoom = 0;
                            }
                            p_EntityStateSlotInRoom++;
                        }
                        EnemiesHaveBeenRevivedRoomList[CurrentRoom] = 1;
                    }
                }
            }
            
            // vanilla logic
            Sub_801E0D4_ClearAllTheEntitySlotInit();
            Sub_801E1C0_EnemyMapOutStartScreen();
            Sub_801E258_EnemyMapOutOutOfScreen(1);
            Sub_801E258_EnemyMapOutOutOfScreen(2);
        }
    }
}
