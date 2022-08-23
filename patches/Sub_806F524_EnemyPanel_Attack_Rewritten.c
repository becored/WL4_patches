// @Description Sub_806F524_EnemyPanel_Attack_Rewritten
// @HookAddress 0x6F526
// @HookString  024d ae46024d 28470000 49f60608 P
// Rewritten by beco

#define MEMORY_2039F00 (*(volatile unsigned int*) 0x2039F00)

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

#define Sub_806EE98_PanelPartWork_Broken_Main ((int (*)(int)) 0x806EE99)
#define Sub_806F424_PanelPartWork_Switch_Main ((int (*)(int,int)) 0x806F425)
#define Sub_806F4BC_PanelPartWork_YokiDiva_Main ((int (*)(int)) 0x806F4BD)

#define Sub_8001DA4_m4aSongNumStart ((void (*)(int)) 0x8001DA5)
#define Sub_801E328_EnemyChildSet ((void (*)(char, char, char, int, int)) 0x801E329)
#define Sub_806ACA0_BgShakingInit ((void (*)(unsigned char, char)) 0x806ACA1)
#define Sub_806F2AC_BgBrokenBlock_ObjSet ((void (*)(unsigned int*)) 0x806F2AD)
#define Sub_806FFB0_Panel_PutBG_Save ((int (*)(int,int,int)) 0x806FFB1)
#define Sub_8070098_Panel_PutBG_Only ((int (*)(int,int,int)) 0x8070099)
#define Sub_80766E8_TOptObjSet ((void (*)(int,int,unsigned char)) 0x80766E9)

#define ucEnemyBrokenFlag (*(volatile unsigned char*) 0x3000028)

struct BgBDdef { // found in /src/gmap/Wario_bg_atari.o (gigaleak)
	short xp;
	short yp;
	short part;
	char dir;
	char coin;
	char hit;
	char obop;
	char SE;
	//char undefined;
};

int Sub_806F524_EnemyPanel_Attack_Rewritten(unsigned short y_grid_pos, unsigned short x_grid_pos, unsigned char L1_tile_terrain_type)
{
	signed int v3;
	signed int v6;
	signed int v7;
	unsigned int* v8;
	int v9;
	unsigned int* v10;
	int v11;
	int v12;
	unsigned int* v13;
	int i;
  struct BgBDdef pDestroy;

	pDestroy.xp = x_grid_pos;
	pDestroy.yp = y_grid_pos;
	pDestroy.part = *(unsigned short*)((2 * L1_tile_terrain_type & 0x1FFFF) + CurrentTileset_EventIdTablePointer);
	pDestroy.dir = 4;
	pDestroy.coin = 0;
	pDestroy.obop = 0;
	pDestroy.hit = 1;
	v3 = 0;
	if ( ucEnemyBrokenFlag == 2 )
	{
		v8 = 0x2039F00;
		v9 = 0;
		if ( MEMORY_2039F00 == ((x_grid_pos << 8) | y_grid_pos) )
		{
			MEMORY_2039F00 = 0;
		}
		else
		{
			while ( 1 )
			{
				++v8;
				if ( ++v9 > 63 )
					break;
				if ( v8 == ((x_grid_pos << 8) | y_grid_pos) )
				{
					v8 = 0;
					v6 = 1;
					break;
				}
			}
			if ( !v6 )
			return 1;
		}
		Sub_8070098_Panel_PutBG_Only(0, pDestroy.yp, pDestroy.xp);
		return 1;
	}
	if ( ucEnemyBrokenFlag <= 2 )
	{
		if ( ucEnemyBrokenFlag == 1 )
		{
			v7 = Sub_806EE98_PanelPartWork_Broken_Main(&pDestroy);
			v6 = v7;
			if ( v7 != 1 )
			{
				if ( v7 == 2 )
					v6 = 0;
				else
					Sub_806F424_PanelPartWork_Switch_Main(&pDestroy, 0);
			}
		}
		return v6;
	}
	if ( ucEnemyBrokenFlag != 3 )
	{
		if ( ucEnemyBrokenFlag == 4 )
			Sub_806F4BC_PanelPartWork_YokiDiva_Main(&pDestroy);
		return v6;
	}
	v10 = 0x2039F00;
	v11 = 0;
	v12 = x_grid_pos << 8;
	if ( MEMORY_2039F00 == ((x_grid_pos << 8) | y_grid_pos) )
	return 1;
	while ( 1 )
	{
		++v10;
		if ( ++v11 > 63 )
		break;
		if ( v10 == (v12 | y_grid_pos) )
		{
			v6 = 1;
			break;
		}
	}
	if ( !v6 )
	{
		v13 = 0x2039F00;
		for ( i = 0; i <= 63; ++i )
		{
			if ( !v13 )
			{
				v13 = v12 | y_grid_pos;
				Sub_8070098_Panel_PutBG_Only(1, pDestroy.yp, pDestroy.xp);
				return 1;
			}
			++v13;
		}
	}
	return v6;
}
