// @Description Sub_8029B9C_EntityAI_0x04_Tmain_takarabako_card
// @HookAddress 0x78E810
// @HookString P
// @EntryFunctionSymbol Sub_8029B9C_EntityAI_0x04_Tmain_takarabako_card
// Made by beco
// Verison 1.0

#include "TC.h"

extern void Q_INITIAL_takarabako();
extern void Q_K2_COM_takarabako();

#define zako_takara_box_Anm_00 ((unsigned long *)0x83B4EF4)
#define zako_takara_box_Anm_01 ((unsigned long *)0x83B4F24)
#define zako_takara_box_Anm_02 ((unsigned long *)0x83B4F34)

void Sub_8029B9C_EntityAI_0x04_Tmain_takarabako_card()
{
	int v0; // r0

	switch (CurrentEnemyData.CurEnemy_CurrentAnimationId)
	{
	case Q_INITIAL:
		Q_INITIAL_takarabako();
		CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = zako_takara_box_Anm_01;
		break;
	case Q_INITIAL2:
		Sub_802922C_EntityAI_0x00_0x01_0x02_0x03_0x04_0x05_Q_INITIAL2_takarabako();
		CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = zako_takara_box_Anm_02;
		Sub_801E328_EnemyChildSet(
			TAKARA_CARD,
			CurrentEnemyData.CurEnemy_RoomEntitySlotId,
			0,
			CurrentEnemyData.CurEnemy_YPos - 128,
			CurrentEnemyData.CurEnemy_XPos);
		Sub_801E328_EnemyChildSet(
			HIKARI_CARD,
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
		CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = zako_takara_box_Anm_00;
		if (HasCD)
		{
			EntityLeftOverStateList[64 * CurrentRoomId + CurrentEnemyData.CurEnemy_RoomEntitySlotId] = 33;
		}
		else
		{
			Sub_801E328_EnemyChildSet(
				TAKARA_CARD,
				CurrentEnemyData.CurEnemy_RoomEntitySlotId,
				0,
				CurrentEnemyData.CurEnemy_YPos - 128,
				CurrentEnemyData.CurEnemy_XPos);
			Sub_801E328_EnemyChildSet(
				HIKARI_CARD,
				CurrentEnemyData.CurEnemy_RoomEntitySlotId,
				0,
				CurrentEnemyData.CurEnemy_YPos - 128,
				CurrentEnemyData.CurEnemy_XPos);
		}
	case K0_TURN1:
		if (--CurrentEnemyData.CurEnemy_TWork0 << 24)
			break;
		Sub_80292BC_EntityAI_0x00_0x01_0x02_0x03_0x04_0x05_Q_K5_HIP_COM_takarabako();
		CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = zako_takara_box_Anm_02;
	case K5_HIP:
		if (EntityLeftOverStateList[64 * CurrentRoomId + CurrentEnemyData.CurEnemy_RoomEntitySlotId] == 33)
			Sub_80292F8_EntityAI_0x00_0x01_0x02_0x03_0x04_0x05_K5_HIP_COM_takarabako();
		break;
	default:
		break;
	}
	Sub_8026838_EnemyWanderingCom();
}