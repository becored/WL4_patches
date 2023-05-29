// @Description TC shared fucntions and stuff

/**
 * changelog:
 * put all the shared functions into C_dependency type patch file,
 * put all the declarations into TC.h
 *            ---- by beco, 2023/5/29
 */

#include "TC.h"

#define zako_takara_box_Anm_03 ((unsigned long *)0x83B4F44)

void Q_INITIAL_takarabako()
{
	CurrentEnemyData.CurEnemy_HitboxY0 = 120;
	CurrentEnemyData.CurEnemy_GuardAndDamageParam = L_COIN;
	CurrentEnemyData.CurEnemy_CurrentAnimationId = K0_WALK;
	Sub_80291B8_EntityAI_SetItemBoxProperties_Q_INITIAL_COM_takarabako();
}

void Q_K2_COM_takarabako()
{
	CurrentEnemyData.CurEnemy_CurrentAnimationId = K0_TURN1;
	CurrentEnemyData.CurEnemy_RealFrameCountForCurrentAnimationFrame = 0;
	CurrentEnemyData.CurEnemy_CurrentAnimationFrameId = 0;
	CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = zako_takara_box_Anm_03;
	CurrentEnemyData.CurEnemy_TWork0 = 13;
	CurrentEnemyData.CurEnemy_HitboxY0 = 64;
	CurrentEnemyData.CurEnemy_GuardAndDamageParam = NO_ATA_H;
	EntityLeftOverStateList[64 * CurrentRoomId + CurrentEnemyData.CurEnemy_RoomEntitySlotId] = 17;
	Sub_8001DA4_m4aSongNumStart(220);
	Sub_8088620_WarioVoiceSet(1);
}