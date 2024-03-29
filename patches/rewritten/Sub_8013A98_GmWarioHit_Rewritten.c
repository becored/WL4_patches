// @Description Sub_8013A98_GmWarioHit_Rewritten
// @HookAddress 0x2DED00
// @HookString  P
// Rewritten by beco

enum WAR_STAT_NORMAL {
	WALK,					//歩き
	TURN,					//振り返り
	STOP,					//止まり
	JUMPB,					//ジャンプ前
	JUMP,					//ジャンプ
	SQUAT,					//しゃがみ
	SSLIP,					//しゃがみすべり
	SWALK,					//しゃがみ歩き
	SJUMP,					//しゃがみジャンプ
	STURN,					//しゃがみ振り返り
	WKBRK,					//歩き止まり
	DSBRK,					//最速走り止まり
	SLIP,					//すべり始め（坂）
	ROLLB,					//転がり前
	ROLL,					//転がり
	RJUMP,					//転がりジャンプ
	RFLIP,					//転がり後の跳ね返り
	DOKANU,					//土管上
	DOKAND,					//土管下
	MISS,					//ダメージ
	MISS2,
	HAJIK,					//敵はじく
	ATTACK,					//アタック
	DATTACK,				//最速アタック
	AJUMP,					//アタックジャンプ
	DAJUMP,					//最速アタックジャンプ
	AFLIP,					//アタック後の跳ね返り
	HIP,					//ヒップアタック（空中）
	PHIP,					//パワーヒップアタック
	HIP2,					//ヒップアタック（地面）
	PHIP2,					//パワーヒップアタック（地面）
	FUMI,					//踏んづけ跳ね
	LIFT1,					//敵持ち上げ（軽い）
	LIFT2,					//敵持ち上げ（重い）
	THROW0,					//投げ準備
	TAME,					//投げ溜め
	THROW1,					//投げ（弱）
	THROW2,					//投げ（強）
	JTHROW,					//飛び投げ
	TAMCURN,				//溜め反転
	LDMOVE,					//はしご移動
	LDSTOP,					//はしご止まり
	LDDOWN,					//はしご飛び落り
	NETMOVEY,				//金網移動Ｙ
	NETMOVEX,				//金網移動Ｘ
	NETSTOP,				//金網止まり
	NETDOWN,				//金網飛び落り
	HANERU,					//敵地震
	AWATE,					//はしご・金網落ちる
	GATEIN,					//扉入る
	GATEOUT,				//扉出る
	UPFACE,					//上向く
	TSQUAT,					//積み木用しゃがみ
	ASERI,					//あせり
	WAIT0,					//待機ポーズ
	WAIT1,					//待機ポーズ
	BARBELL0,				//バーベル０
	BARBELL1,				//バーベル１
	ATWALK,					//オート歩き
	WAIT2,					//縄跳び
	CATCH,					//捕らえる
	JCLEAR,					//空中でボス戦クリア
	CLRWAIT,				//ボス戦クリア後
	CLRTURN,				//クリア後ターン
	CLRWALK,				//クリア後歩き
	CLRKIME,				//決めポーズ
	LSTWAIT,				//宝待ち（ラスボス）
	LSTKIME,				//決めポーズ（ラスボス）
	LSTAWATE,				//慌てる（ラスボス）

	SLEEP,					//眠り
	WAKEUP,					//目覚め
	JUMPA,					//着地
	DASH,					//最速走り
	DJUMP,					//最速ジャンプ
	JFLIP,					//跳ね返り
	CLASH,					//激突
	TAKARA,					//宝箱
	RPOUSE,					//構え
	GOWALK,					//ゴー
};

enum WAR_STAT_SWIM {
	SWCHNG,					//泳ぎに変化
	SWIMX,					//泳ぎ左右
	SWIMY,					//泳ぎ上下
	SWIM2,					//泳ぎ（キーだけ）
	SWIM3,					//水面
	SWSTOP,					//浮き
	SWMISS,					//水中ミス
	SWHIP,					//ヒップアタック
	SWHIP2,					//ヒップ着地
	SWFLIPX,				//横はじかれ
	SWFLIPY,				//縦はじかれ
	SWGATEIN,				//扉入る
	SWDEBU,					//デブ
	SWDBHIP,				//デブヒップ
	SWAWA,					//泡
	SWBIT,					//噛まれる
};

#define Sub_8014FAC_WarHitLdMove ((signed int (*)()) 0x8014FAD)
#define Sub_80150D0_WarHitNetMoveY ((signed int (*)()) 0x80150D1)
#define Sub_8015194_WarHitNetMoveX ((signed int (*)()) 0x8015195)
#define Sub_8014C4C_WarHitUp ((signed int (*)()) 0x8014C4D)
#define Sub_8014930_WarHitDown ((signed int (*)()) 0x8014931)
#define Sub_80143D8_WarHitWalk ((signed int (*)()) 0x80143D9)
#define Sub_8014F00_WarHitSWalk ((signed int (*)()) 0x8014F01)
#define Sub_8014758_WarHitStop ((signed int (*)()) 0x8014759)
#define Sub_8014268_WarYukaCheck ((signed int (*)(unsigned char,unsigned short,int*)) 0x8014269)
#define Sub_806DAC0_PanelYakuAllNum_TileEventId ((int (*)(unsigned short, unsigned short))0x806DAC1)
#define Sub_8016614_GmWarioChng_Swim ((void (*)(unsigned char)) 0x8016615)
#define Sub_8012BAC_GmWarioChng ((void (*)(unsigned char)) 0x8012BAD)

#define Wario_ucReact (*(volatile unsigned char*) 0x3001898)
#define Wario_ucStat (*(volatile unsigned char*) 0x3001899)
#define Wario_ucMiss (*(volatile unsigned char*) 0x300189C)
#define Wario_ucJpNext (*(volatile unsigned char*) 0x300189F)
#define Wario_ucJpFlg (*(volatile unsigned char*) 0x30018A0)
#define Wario_usMukiX (*(volatile unsigned short*) 0x30018A6)
#define Wario_usMukiY (*(volatile unsigned short*) 0x30018A8)
#define Wario_usPosX (*(volatile unsigned short*) 0x30018AA)
#define Wario_usPosY (*(volatile unsigned short*) 0x30018AC)
#define Wario_sMvSpeedX (*(volatile signed short*) 0x30018AE)
#define Wario_sMvSpeedY (*(volatile signed short*) 0x30018B0)
#define WHit (*(volatile struct WHitDef*) 0x3001918)

struct WHitDef{
	unsigned short usMukiX;   //Ｘ移動方向
	unsigned short usMukiY;   //Ｙ移動方向
	unsigned char ucFront;   //前方当りポジション
	unsigned char ucBack;    //後方当りポジション
	unsigned short sDX;    //当りによる補正Ｘ

	unsigned char ucSide;    //横壊れ有り
	unsigned char ucHead;    //頭壊れ有り
	unsigned char ucYuka;    //床壊れ有り
	unsigned char ucSPow;    //横壊しのパワー
	unsigned char ucHPow;    //頭
	unsigned char ucYPow;    //床
	unsigned char ucWSide;   //横当りで壊れたとき立てる
	unsigned char ucWHead;   //頭
	unsigned char ucWYuka;   //床
	unsigned char ucPlace;

	unsigned char ucSStop;   //横かべのとき立てる
	unsigned char ucHStop;   //上
	unsigned char ucYStop;   //床
};

#define byte_82DD431 ((volatile unsigned char*) 0x82DD431)

void Sub_8013A98_GmWarioHit_Rewritten()
{
	signed int v0; // r4
  unsigned char v1; // r0
  signed int v2; // r0
  int v3; // [sp+0h] [bp-14h]

  WHit.ucSPow = byte_82DD431[8 * Wario_ucStat + 3];
  WHit.ucHPow = byte_82DD431[8 * Wario_ucStat + 4];
  WHit.ucYPow = byte_82DD431[8 * Wario_ucStat + 5];
  WHit.ucPlace = byte_82DD431[8 * Wario_ucStat + 6];
  if ( Wario_sMvSpeedY <= 47 )
    WHit.ucHPow = 0;
  v0 = 0xFF;
  switch ( Wario_ucStat )
  {
    case DOKANU:
    case DOKAND:
    case LDSTOP:
    case NETSTOP:
    case GATEIN:
    case GATEOUT:
      goto LABEL_26;
    case LDMOVE:
      v1 = Sub_8014FAC_WarHitLdMove();
      goto LABEL_25;
    case NETMOVEY:
      v1 = Sub_80150D0_WarHitNetMoveY();
      goto LABEL_25;
    case NETMOVEX:
      v1 = Sub_8015194_WarHitNetMoveX();
      goto LABEL_25;
    default:
      if ( WHit.usMukiY & 0x40 )                // Wario moving up
      {
        v1 = Sub_8014C4C_WarHitUp();
      }
      else if ( WHit.usMukiY & 0x80 )           // Wario moving down
      {
        v1 = Sub_8014930_WarHitDown();
      }
      else if ( WHit.usMukiX )                  // Wario has horizontal speed
      {
        if ( WHit.ucPlace == 2 )
        {
          v1 = Sub_8014930_WarHitDown();
        }
        else
        {
          v0 = Sub_80143D8_WarHitWalk();
          if ( v0 != 255 )
            goto LABEL_26;
          if ( ((Wario_ucStat - 6) & 0xFF) > 1 )
          {
            if ( Wario_ucStat << 24 != 0 )
              goto LABEL_26;
            if ( Wario_usMukiX & 0x10 )         // wario direction right
            {
              if ( Wario_sMvSpeedX > 40 )       // B dash or R dash, if walking, wario max speed is 0x40
                goto LABEL_26;
              v1 = Sub_8014F00_WarHitSWalk();
            }
            else                                // wario direction left
            {
              if ( Wario_sMvSpeedX < -40 )
                goto LABEL_26;
              v1 = Sub_8014F00_WarHitSWalk();
            }
          }
          else
          {
            v1 = Sub_8014F00_WarHitSWalk();
          }
        }
      }
      else
      {
        if ( WHit.ucPlace )
          goto LABEL_26;
        v1 = Sub_8014758_WarHitStop();
      }
LABEL_25:
      v0 = v1;
LABEL_26:
      switch ( Wario_ucStat )
      {
        case SLIP:
          if ( WHit.ucSStop )
            v0 = STOP;
          break;
        case ROLLB:
        case ROLL:
        case RJUMP:
          if ( v0 == 0xFC )
            v0 = RFLIP;
          break;
        case ATTACK:
        case DATTACK:
        case AJUMP:
        case DAJUMP:
          if ( v0 == 0xFC )
          {
            v0 = AFLIP;
            if ( !WHit.ucWSide )
              Wario_ucJpFlg = 1;
          }
          break;
        case HIP:
        case PHIP:
          if ( v0 == 0xFD )
          {
            v2 = Sub_8014268_WarYukaCheck(WHit.ucSide, Wario_usPosY + 1, &v3);
            if ( v2 )
            {
              if ( v2 <= WHit.ucWYuka && Wario_ucStat == PHIP )
                v0 = 0xFF;
            }
          }
          break;
        default:
          break;
      }
      if ( WHit.usMukiY & 0x80 && (Sub_806DAC0_PanelYakuAllNum_TileEventId(Wario_usPosY, Wario_usPosX) & 0xFF) == 1 )
      {
        Wario_ucReact = 1;                      // set swimming wario
        if ( Wario_ucStat == PHIP )
        {
          Sub_8016614_GmWarioChng_Swim(SWHIP);
        }
        else
        {
          if ( ((Wario_ucStat - 19) & 0xFF) <= 1 )
            Wario_ucMiss = 96;
          Sub_8016614_GmWarioChng_Swim(SWCHNG);
        }
      }
      else if ( WHit.ucPlace != 0xFF )          // not cannot-move wario, i.e. wario can move
      {
        if ( v0 != 0xFF )
          Sub_8012BAC_GmWarioChng(v0);
        if ( v0 == 0xFE )
          ++Wario_usPosY;
      }
      return;
  }
}
