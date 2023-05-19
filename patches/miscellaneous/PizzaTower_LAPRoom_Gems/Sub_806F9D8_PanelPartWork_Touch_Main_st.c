// @Description Rewritten Sub_806F9D8_PanelPartWork_Touch_Main_st
// @HookAddress 0x6F9DC
// @HookString  024a 9646024a 10470000 0000 9bfb0608 P
// Rewritten by blanchon
// Edited by beco
// @EntryFunctionSymbol Sub_806F9D8_PanelPartWork_Touch_Main_st

#define CurrentTileset_EventIdTablePointer (*(volatile unsigned int*) 0x30031FC)
#define CurrentRoomHeader_TilesetId (*(volatile unsigned char*) 0x3000074)

#define CurrentRoomHeader_Layer0MappingType (*(volatile unsigned char*) 0x3000075)
#define CurrentRoomHeader_Layer1MappingType (*(volatile unsigned char*) 0x3000076)
#define CurrentRoomHeader_Layer2MappingType (*(volatile unsigned char*) 0x3000077)
#define CurrentRoomHeader_Layer3MappingType (*(volatile unsigned char*) 0x3000078)

#define CurrentRoomHeader_LayerPriorityALphaParam (*(volatile unsigned char*) 0x300008e)

#define Layer0_DecompressedDataPointer (*(volatile unsigned int*) 0x3000054)
#define Layer0_Width (*(volatile unsigned short*) 0x3000058)
#define Layer0_Height (*(volatile unsigned short*) 0x300005a)

#define Layer1_DecompressedDataPointer (*(volatile unsigned int*) 0x300005c)
#define Layer1_Width (*(volatile unsigned short*) 0x3000060)
#define Layer1_Height (*(volatile unsigned short*) 0x3000062)

#define Layer2_DecompressedDataPointer (*(volatile unsigned int*) 0x3000064)
#define Layer2_Width (*(volatile unsigned short*) 0x3000068)
#define Layer2_Height (*(volatile unsigned short*) 0x300006a)

#define MapSwitch1 (*(volatile unsigned char*) 0x300002f)
#define MapSwitch2 (*(volatile unsigned char*) 0x3000030)
#define MapSwitch3 (*(volatile unsigned char*) 0x3000031)
#define MapSwitch4 (*(volatile unsigned char*) 0x3000032) // frog blocks, etc (see WL4 RAM record)

#define ucJSwitchOnFlg (*(volatile unsigned char*) 0x03000C0D)

#define PanelPartWork_Coin_Normal ((int (*)(int,int)) 0x806FD1D)
#define PanelPartWork_Coin_Red ((int (*)(int,int)) 0x806FD49)
#define PanelPartWork_Touch_Damage ((int (*)(int,int)) 0x806FBA5)
#define Panel_PutBG_Save ((int (*)(int,int,int)) 0x806FFB1)

#define m4aSongNumStart ((int (*)(int)) 0x8001DA5) // to produce various sound effects


#define Sub_8094E00_call_via_r1 ((int (*)(int,int,int)) 0x8094E01)


#define byte_300189C (*(volatile unsigned char*) 0x300189C)
#define ucTimeUp (*(volatile unsigned char*) 0x3000047)
#define WarioCurrentState (*(volatile unsigned char*) 0x3001898)
#define usWarStopFlg (*(volatile unsigned short*) 0x30019F6)
#define WarioHeart0 (*(volatile unsigned char*) 0x3001910)
#define WarioHeart1 (*(volatile unsigned char*) 0x3001911)
#define WarioHeart2 (*(volatile unsigned char*) 0x3001912)
#define WarioHeart3 (*(volatile unsigned char*) 0x3001913)
#define ucTitle2f (*(volatile unsigned char*) 0x3000022)
#define unk_83F9DEC (*(volatile unsigned short*) 0x83F9DEC)

// custom structures 
struct EmpBlkdef
{
	unsigned short position;
	unsigned short tileID;
};

// custom variables for restoring crystals
#define EXBACKUP_FIELD_EMPBLK ((volatile struct EmpBlkdef *) 0x203E000)
#define usDisConR_EmpBlk (*(volatile unsigned short *) 0x3006F00)

void StoreRemovedTile (unsigned short Y_value, unsigned short X_value)
{
    int n;
    unsigned short id = *(unsigned short *)(2 * (Y_value * Layer1_Width + X_value) + Layer1_DecompressedDataPointer);
    unsigned short pos = (2 * (X_value + Y_value * Layer1_Width) & 0x1FFFF) + Layer1_DecompressedDataPointer >> 1;
    for (n = 0; n != usDisConR_EmpBlk; n++)
    {
        if ( EXBACKUP_FIELD_EMPBLK[n].tileID == id && EXBACKUP_FIELD_EMPBLK[n].position == pos )
          return;
    }
    // store obtained crystals to EXBACKUP_FIELD_EMPBLK
    EXBACKUP_FIELD_EMPBLK[usDisConR_EmpBlk].tileID = id;
    EXBACKUP_FIELD_EMPBLK[usDisConR_EmpBlk].position = pos;
    ++usDisConR_EmpBlk;
}

int Sub_806F9D8_PanelPartWork_Touch_Main_st (unsigned short Y_value, unsigned short X_value)
{

  int v2; // r5
  int v3; // r4
  char v4; // r4
  int v5; // r0
  int v6; // r0
  int v7; // ST08_4
  int v8; // r2
  int v10; // [sp+4h] [bp-1Ch]
  int v11; // [sp+1Ch] [bp-4h]

  v2 = Y_value;

  v3 = *(unsigned short*)(2 * \
       *(unsigned short*)(2 * (Y_value * Layer1_Width + X_value) + Layer1_DecompressedDataPointer) \
	   + CurrentTileset_EventIdTablePointer);

  v10 = v3;


  if ( v3 == 0x70 )                             // blue ruby
  {
    StoreRemovedTile(Y_value, X_value);
    goto LABEL_8;
  }

  if ( v3 == 0x72 )                             // ruby
  {
    StoreRemovedTile(Y_value, X_value);
    goto LABEL_8;
  }

  if ( MapSwitch1 & 1 )
  {
    if ( v3 == 0x48 )                           // hollow blue ruby, triggered by frog switch
    {
LABEL_8:
      PanelPartWork_Coin_Normal(Y_value, X_value);
      return v11;
    }

    if ( v3 == 0x49 )                           // hollow ruby, triggered by frog switch
      goto LABEL_43;

  }

  if ( MapSwitch4 & 1 )
  {
    if ( v3 == 0x4A )
      goto LABEL_8;

    if ( v3 == 0x4B )
    {
LABEL_43:
      PanelPartWork_Coin_Red(Y_value, X_value);
      return v11;
    }

  }

  if ( v3 != 0x74 && v3 != 0x75 && v3 != 0x76 ) // if not heart, ??? & big heart
  {
    if ( CurrentRoomHeader_Layer0MappingType == 0x10 )
      v6 = *(unsigned short*)(2 * \
       *(unsigned short*)(2 * (Y_value * Layer0_Width + X_value) + Layer0_DecompressedDataPointer) \
	   + CurrentTileset_EventIdTablePointer);

   v7 = *(unsigned short*)(2 * \
       *(unsigned short*)(2 * (Y_value * Layer2_Width + X_value) + Layer2_DecompressedDataPointer) \
	   + CurrentTileset_EventIdTablePointer);

    if ( WarioCurrentState == 1 )               // swimming
    {
      if ( !byte_300189C )
        PanelPartWork_Touch_Damage(v3, 6u);

    } else if ( WarioCurrentState > 1 )
    {
      if ( WarioCurrentState == 8 && !byte_300189C )
        PanelPartWork_Touch_Damage(v3, 0x13u);

    } else if ( !WarioCurrentState && !byte_300189C && !PanelPartWork_Touch_Damage(v3, 0x13u) && v3 == 0x69 )
    {
      WarioCurrentState = 2;
      Sub_8094E00_call_via_r1(0, 0x8017ADD, v8);
    }


  } else if ( ucTimeUp <= 3u && !usWarStopFlg && (WarioHeart0 || ucTitle2f) )
  {
    Panel_PutBG_Save(0, Y_value, X_value);
    v4 = 3;
    if ( v10 != 0x75 )
    {
      v4 = 1;
      if ( v10 == 0x76 )                        // big heart
        v4 = 5;

    }

    v5 = 4 * (v10 - 0x74);

    if ( WarioCurrentState == 1 )
      v5 += 2;

    m4aSongNumStart(unk_83F9DEC + v5);
    WarioHeart1 += v4;

    if ( WarioHeart0 + WarioHeart1 > 8 )
      WarioHeart1 = 8 - WarioHeart0;

    WarioHeart2 = 8 * WarioHeart1;
    WarioHeart3 = 0;
  }

  return v11;


}
