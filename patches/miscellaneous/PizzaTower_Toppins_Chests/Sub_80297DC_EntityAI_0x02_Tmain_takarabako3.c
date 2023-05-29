// @Description Sub_80297DC_EntityAI_0x02_Tmain_takarabako3
// @HookAddress 0x78E808
// @HookString P
// @EntryFunctionSymbol Sub_80297DC_EntityAI_0x02_Tmain_takarabako3
// Made by beco
// Verison 1.0

#include "TC.h"

extern void Q_INITIAL_takarabako();
extern void Q_K2_COM_takarabako();

#define zako_takara_box_Anm_05 ((unsigned long *)0x83B4F84)

void Sub_80297DC_EntityAI_0x02_Tmain_takarabako3()
{
	int v0; // r0

	switch (CurrentEnemyData.CurEnemy_CurrentAnimationId)
	{
	case Q_INITIAL:
		Q_INITIAL_takarabako();
		CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = zako_takara_box_Anm_05;
		break;
	case Q_INITIAL2:
		Sub_802922C_EntityAI_0x00_0x01_0x02_0x03_0x04_0x05_Q_INITIAL2_takarabako();
		Sub_801E328_EnemyChildSet(
			TAKARA_KAKERA2,
			CurrentEnemyData.CurEnemy_RoomEntitySlotId,
			0,
			CurrentEnemyData.CurEnemy_YPos - 128,
			CurrentEnemyData.CurEnemy_XPos);
		Sub_801E328_EnemyChildSet(
			HIKARI_KAKERA2,
			CurrentEnemyData.CurEnemy_RoomEntitySlotId,
			0,
			CurrentEnemyData.CurEnemy_YPos - 128,
			CurrentEnemyData.CurEnemy_XPos);
		break;
	case Q_INITIAL3:
		Sub_8029258_EntityAI_0x00_0x01_0x02_0x03_0x04_0x05_Q_INITIAL3_takarabako();
		break;
	case Q_K5_HIP:
		Q_K2_COM_takarabako();
		if (Has3rdGemPiece)
		{
			EntityLeftOverStateList[64 * CurrentRoomId + CurrentEnemyData.CurEnemy_RoomEntitySlotId] = 33;
		}
		else
		{
			Sub_801E328_EnemyChildSet(
				TAKARA_KAKERA3,
				CurrentEnemyData.CurEnemy_RoomEntitySlotId,
				0,
				CurrentEnemyData.CurEnemy_YPos - 128,
				CurrentEnemyData.CurEnemy_XPos);
			Sub_801E328_EnemyChildSet(
				HIKARI_KAKERA3,
				CurrentEnemyData.CurEnemy_RoomEntitySlotId,
				0,
				CurrentEnemyData.CurEnemy_YPos - 128,
				CurrentEnemyData.CurEnemy_XPos);
		}
	case K0_TURN1:
		if (--CurrentEnemyData.CurEnemy_TWork0 << 24)
			break;
		Sub_80292BC_EntityAI_0x00_0x01_0x02_0x03_0x04_0x05_Q_K5_HIP_COM_takarabako();
	case K5_HIP:
		if (EntityLeftOverStateList[64 * CurrentRoomId + CurrentEnemyData.CurEnemy_RoomEntitySlotId] == 33)
			Sub_80292F8_EntityAI_0x00_0x01_0x02_0x03_0x04_0x05_K5_HIP_COM_takarabako();
		break;
	default:
		break;
	}
	Sub_8026838_EnemyWanderingCom();
}