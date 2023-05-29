/**
 * changelog:
 * put all the shared functions into C_dependency type patch file,
 * put all the declarations into TC.h
 *            ---- by beco, 2023/5/29
 */

// ワリオボイス用
enum
{
    WV_HAPPY_1,            WV_HAPPY_2,            WV_HAPPY_3,
    WV_FIGHT,            WV_ANXIETY,            WV_HURRY,
    WV_CIRCLE,            WV_GOAL,            WV_PYRAMID_CAT,
    WV_COME_BACK,        WV_ANXIETY_2,        WV_GAMEOVER,
    BV_MOUSE_DAMAGE,    BV_KONDOKE_DAMAGE,    BV_DORAMORI_DAMAGE,
    BV_FLOWERNA_DAMAGE,    BV_PINKY_DAMAGE,    BV_YOKI_DAMAGE,
    SV_SMILE,            TS_BOX_UP1,            TS_BOX_UP2,
    TS_BOX_POP,            TS_BOX_BUMP
};

enum WAR_STAT_NORMAL {
    WALK,                    //歩き
    TURN,                    //振り返り
    STOP,                    //止まり
    JUMPB,                    //ジャンプ前
    JUMP,                    //ジャンプ
    SQUAT,                    //しゃがみ
    SSLIP,                    //しゃがみすべり
    SWALK,                    //しゃがみ歩き
    SJUMP,                    //しゃがみジャンプ
    STURN,                    //しゃがみ振り返り
    WKBRK,                    //歩き止まり
    DSBRK,                    //最速走り止まり
    SLIP,                    //すべり始め（坂）
    ROLLB,                    //転がり前
    ROLL,                    //転がり
    RJUMP,                    //転がりジャンプ
    RFLIP,                    //転がり後の跳ね返り
    DOKANU,                    //土管上
    DOKAND,                    //土管下
    MISS,                    //ダメージ
    MISS2,
    HAJIK,                    //敵はじく
    ATTACK,                    //アタック
    DATTACK,                //最速アタック
    AJUMP,                    //アタックジャンプ
    DAJUMP,                    //最速アタックジャンプ
    AFLIP,                    //アタック後の跳ね返り
    HIP,                    //ヒップアタック（空中）
    PHIP,                    //パワーヒップアタック
    HIP2,                    //ヒップアタック（地面）
    PHIP2,                    //パワーヒップアタック（地面）
    FUMI,                    //踏んづけ跳ね
    LIFT1,                    //敵持ち上げ（軽い）
    LIFT2,                    //敵持ち上げ（重い）
    THROW0,                    //投げ準備
    TAME,                    //投げ溜め
    THROW1,                    //投げ（弱）
    THROW2,                    //投げ（強）
    JTHROW,                    //飛び投げ
    TAMCURN,                //溜め反転
    LDMOVE,                    //はしご移動
    LDSTOP,                    //はしご止まり
    LDDOWN,                    //はしご飛び落り
    NETMOVEY,                //金網移動Ｙ
    NETMOVEX,                //金網移動Ｘ
    NETSTOP,                //金網止まり
    NETDOWN,                //金網飛び落り
    HANERU,                    //敵地震
    AWATE,                    //はしご・金網落ちる
    GATEIN,                    //扉入る
    GATEOUT,                //扉出る
    UPFACE,                    //上向く
    TSQUAT,                    //積み木用しゃがみ
    ASERI,                    //あせり
    WAIT0,                    //待機ポーズ
    WAIT1,                    //待機ポーズ
    BARBELL0,                //バーベル０
    BARBELL1,                //バーベル１
    ATWALK,                    //オート歩き
    WAIT2,                    //縄跳び
    CATCH,                    //捕らえる
    JCLEAR,                    //空中でボス戦クリア
    CLRWAIT,                //ボス戦クリア後
    CLRTURN,                //クリア後ターン
    CLRWALK,                //クリア後歩き
    CLRKIME,                //決めポーズ
    LSTWAIT,                //宝待ち（ラスボス）
    LSTKIME,                //決めポーズ（ラスボス）
    LSTAWATE,                //慌てる（ラスボス）

    SLEEP,                    //眠り
    WAKEUP,                    //目覚め
    JUMPA,                    //着地
    DASH,                    //最速走り
    DJUMP,                    //最速ジャンプ
    JFLIP,                    //跳ね返り
    CLASH,                    //激突
    TAKARA,                    //宝箱
    RPOUSE,                    //構え
    GOWALK,                    //ゴー
};
enum MAP_YAKUWARI {
    YNASHI,                //00:なし
    YDAMAGE,            //01:ダメージ
    YNTOBIRA,            //02:扉
    YNWARP,                //03:触れたらワープ
    YTUBE_UL,            //04:土管↑（左）
    YTUBE_UR,            //05:土管↑（右）
    YTUBE_DL,            //06:土管↓（左）
    YTUBE_DR,            //07:土管↓（右）
    YTOMAP,                //08:触れたらTo Map(BOSS STAGE)
    YGWARP,                //09:ワープ(隠しゲーム内用)
    YYOKIYUKA,            //0A:大ボス床壊れ
    YBLOCK_NA_1,        //0B:壊B（岩）（11）→00                //--- NOMAL BLOCK ---
    YBLOCK_NA_1C,        //0C:壊B（岩）（11）→00（C）
    YBLOCK_NA_2LU,        //0D:壊B（岩）（22左上）→00
    YBLOCK_NA_2LUC,        //0E:壊B（岩）（22左上）→00（C）
    YBLOCK_NA_2,        //0F:壊B（岩）（22他）→00
    YBLOCK_NB_1,        //10:壊B（草）（11）→00
    YBLOCK_NB_1C,        //11:壊B（草）（11）→00（C）
    YBLOCK_NB_2LU,        //12:壊B（草）（22左上）→00
    YBLOCK_NB_2LUC,        //13:壊B（草）（22左上）→00（C）
    YBLOCK_NB_2,        //14:壊B（草）（22他）→00
    YBLOCK_NC_1,        //15:壊B3（11）→00
    YBLOCK_NC_1C,        //16:壊B3（11）→00（C）
    YBLOCK_NC_2LU,        //17:壊B3（22左上）→00
    YBLOCK_NC_2LUC,        //18:壊B3（22左上）→00（C）
    YBLOCK_NC_2,        //19:壊B3（22他）→00
    YBLOCK_ND_1,        //1A:壊B4（11）→00
    YBLOCK_ND_1C,        //1B:壊B4（11）→00（C）
    YBLOCK_ND_2LU,        //1C:壊B4（22左上）→00
    YBLOCK_ND_2LUC,        //1D:壊B4（22左上）→00（C）
    YBLOCK_ND_2,        //1E:壊B4（22他）→00
    YBLOCK_HA_2LU,        //1F:堅い壊B(岩)(22左上)→00
    YBLOCK_HA_2LUC,        //20:堅い壊B(岩)(22左上)→00(C)            //--- HARD BLOCK ---
    YBLOCK_HA_2,        //21:堅い壊B(岩)(22他)→00
    YBLOCK_HB_2LU,        //22:堅い壊B(草)(22左上)→00
    YBLOCK_HB_2LUC,        //23:堅い壊B(草)(22左上)→00(C)
    YBLOCK_HB_2,        //24:堅い壊B(草)(22他)→00
    YBLOCK_HC_2LU,        //25:堅い壊B(鉄)(22左上)→00
    YBLOCK_HC_2LUC,        //26:堅い壊B(鉄)(22左上)→00(C)
    YBLOCK_HC_2,        //27:堅い壊B(鉄)(22他)→00
    YBLOCK_HD_2LU,        //28:堅い壊B(木)(22左上)→00
    YBLOCK_HD_2LUC,        //29:堅い壊B(木)(22左上)→00(C)
    YBLOCK_HD_2,        //2A:堅い壊B(木)(22他)→00
    YBLOCK_FA_1,        //2B:火壊B(11)                            //--- FIRE BLOCK ---
    YBLOCK_FA_1C,        //2C:火壊B(11)(C)
    YBLOCK_FA_2LU,        //2D:火壊B(22左上)
    YBLOCK_FA_2LUC,        //2E:火壊B(11左上)(C)
    YBLOCK_FA_2,        //2F:火壊B(22他)
    YBLOCK_SA_2LU,        //30:雪だるま壊れ･弱(22左上)            //--- SNOW BLOCK ---
    YBLOCK_SA_2,        //31:雪だるま壊れ･弱(22左上)
    YBLOCK_SB_2LU,      //32:雪だるま壊れ･強(22左上)
    YBLOCK_SB_2,        //33:雪だるま壊れ･強(22左上)
    YBLOCK_RA_2LU,        //34:ゲート復活壊れブロック(22左上)        //--- RE BLOCK ---
    YBLOCK_RA_2,        //35:ゲート復活壊れブロック(22他)
    YBLOCK_TA_1,        //36:敵指定壊れブロック(パターンなし)    //--- TEKI BLOCK ---
        Yrese37,        //37:
    YSW1_TOBIRA_N,        //38:S1 OFF扉 ON なし
    YSW2_TOBIRA_N,        //39:S2 OFF扉 ON なし
    YSW3_TOBIRA_N,        //3A:S3 OFF扉 ON なし
    YSW4_TOBIRA_N,        //3B:S4 OFF扉 ON なし
    YSW1_N_TOBIRA,        //3C:S1 OFFなし ON 扉
    YSW2_N_TOBIRA,        //3D:S2 OFFなし ON 扉
    YSW3_N_TOBIRA,        //3E:S3 OFFなし ON 扉
    YSW4_N_TOBIRA,        //3F:S4 OFFなし ON 扉
    YSW1N,                //40:スイッチ1本体(初期OFF)
    YSW2N,                //41:スイッチ2本体(初期OFF)
    YSW3N,                //42:スイッチ3本体(初期OFF)
    YSW4N,                //43:スイッチ4本体(初期OFF)
        Yrese44,        //44
        Yrese45,        //45
        Yrese46,        //46
        Yrese47,        //47
    YSW1_N_COIN,        //48:S1 OFF透明コイン ONコイン
    YSW1_N_RCOIN,        //49:S1 OFF透明コイン ON赤コイン
    YSW4_N_COIN,        //4A:S4 OFF     ONコイン
    YSW4_N_RCOIN,        //4B:S4 OFF     ON赤コイン
    YSW4_MIZU_FR_NOR,    //4C:S4 OFF水流れ→(速) ON水
    YSW4_MIZU_FL_NOR,    //4D:S4 OFF水流れ←(速) ON水
    YSW4_MIZU_FU_NOR,    //4E:S4 OFF水流れ↑(速) ON水
    YSW4_MIZU_FD_NOR,    //4F:S4 OFF水流れ↓(速) ON水
    YMIZU_NOR,            //50:水
    YMIZU_SR,            //51:水流れ→
    YMIZU_SL,            //52:水流れ←
    YMIZU_SU,            //53:水流れ↑
    YMIZU_SD,            //54:水流れ↓
    YMIZU_FR,            //55:水流れ→（速い）
    YMIZU_FL,            //56:水流れ←（速い）
    YMIZU_FU,            //57:水流れ↑（速い）
    YMIZU_FD,            //58:水流れ↓（速い）
    YBLOCK_IA_1,        //59:滑る壊れ1×1                        //--- ICE BLOCK ---
    YBLOCK_IA_1C,        //5A:滑る壊れ1×1(C)
    YBLOCK_IA_2LU,        //5B:滑る壊れ2×2(左上)
    YBLOCK_IA_2LUC,        //5C:滑る壊れ2×2(左上C)
    YBLOCK_IA_2,        //5D:滑る壊れ2×2(その他)
            //5E:
            //5F:
    YWASHIBA_RST =0x60,    //60:大滑車･右へ停止
    YWASHIBA_LST,        //61:大滑車･左へ停止
    YWASHIBA_RUP,        //62:大滑車･左水平/右斜め上
    YWASHIBA_RDW,        //63:大滑車･左水平/右斜め下
    YWASHIBA_LUP,        //64:大滑車･左斜め上/右水平
    YWASHIBA_LDW,        //65:大滑車･左斜め下/右水平
    YWASHIBA_RST2,        //66:大滑車･高得点/右へ停止
    YWASHIBA_LST2,        //67:大滑車･高得点/左へ停止
    YSLIP,                //68:滑る
    YFIRE,                //69:炎パネル
    YBELT_L,            //6A:ベルトコンベア←左
    YBELT_R,            //6B:ベルトコンベア→右
            //6C:
            //6D:
            //6E:
            //6F:
    YCOIN_NOR =0x70,    //70:コイン→00
            //71:
    YCOIN_RED =0x72,    //72:赤コイン→00
            //73:
    YKAIFUKU_A =0x74,    //74:ハート1
    YKAIFUKU_B,            //75:ハート3
    YKAIFUKU_C,            //76:ハート5
            //77:
            //78:
    YHASHIGO_M =0x79,    //79:はしご
    YHASHIGO_U,            //7A:はしご上
    YAMI,                //7B:アミ
    YHIKARI,            //7C:光り(ゾンビ用)
    YTUBUEND,            //7D:つぶれもどし
    YDAMAGE_L,            //7E:パネルの右から指定ﾄﾞｯﾄにダメージ
    YDAMAGE_R,            //7F:パネルの左から指定ﾄﾞｯﾄにダメージ
    YDAMAGE_U,            //80:パネルの下から指定ﾄﾞｯﾄにダメージ
    YDAMAGE_D,            //81:パネルの上から指定ﾄﾞｯﾄにダメージ
            //82:
            //83:
    YDOMINO_R4 =0x84,    //84:ドミノ右へ4パネル(40F        84:ドミノ右へ4パネル
    YDOMINO_L4,            //85:ドミノ左へ4パネル(40F        85:ドミノ左へ4パネル
    YDOMINO_R5D1,        //86:ドミノ右へ5,下へ1(50F        86:ドミノ右へ5,下へ1
    YDOMINO_L5D1,        //87:ドミノ左へ5,下へ1(50F        87:ドミノ左へ5,下へ1
    YDOMINO_R5U1,        //88:ドミノ右へ5,上へ1(50F        88:ドミノ右へ5,上へ1
    YDOMINO_L5U1,        //89:ドミノ左へ5,上へ1(50F        89:ドミノ左へ5,上へ1
    YDOMINO_R3D3,        //8A:ドミノ右へ3,下へ3(60F        8A:ドミノ左へ1,下へ3
    YDOMINO_L3D3,        //8B:ドミノ左へ3,下へ3(60F        8B:ドミノ右へ1,下へ3
    YDOMINO_R3U3,        //8C:ドミノ右へ3,上へ3(60F        8C:ドミノ左へ1,上へ3
    YDOMINO_L3U3,        //8D:ドミノ左へ3,上へ3(60F        8D:ドミノ右へ1,上へ3
    YDOMINO_STP ,        //8E:ドミノストップ                8E:ドミノストップ
            //8F:
    YSW1_DAMAGE_N=0x90,    //90:S1 OFFダメージONなし
    YSW2_DAMAGE_N,        //91:S2 OFFダメージONなし
    YSW3_DAMAGE_N,        //92:S3 OFFダメージONなし
    YSW4_DAMAGE_N,        //93:S4 OFFダメージONなし
    YSW1_N_DAMAGE,        //94:S1 OFFなしONダメージ
    YSW2_N_DAMAGE,        //95:S2 OFFなしONダメージ
    YSW3_N_DAMAGE,        //96:S3 OFFなしONダメージ
    YSW4_N_DAMAGE,        //97:S4 OFFなしONダメージ
    YSW1_HASHIGOM_N,    //98:S1 OFFはしご ON なし
    YSW1_HASHIGOU_N,    //99:S1 OFFはしご ON なし
    YSW1_N_HASHIGOM,    //9A:S1 OFFなし ON はしご
    YSW1_N_HASHIGOU,    //9B:S1 OFFなし ON はしご
    YSW2_DAMAGE_U_N,    //9C:S2 OFF下4ドットダメージONなし
            //9D:
            //9E:
            //9F:
    YSETUP_KEY_PRI0 = 0xA0,    //A0:SETUP役割    カギOBJ優先=0
};

enum {
    KN_TSCORE10A,
    KN_TSCORE50A,
    KN_TSCORE100A,
    KN_TSCORE500A,

    KN_TSCORE1000A,
    KN_HIPSTAR,                // ヒップの星のKind Number     (TOptObjSet用)
    KN_ATKSTAR,                // アタックのバシッ！        (TOptObjSet用)
    KN_MIZUBASHIRA,            // 水柱のKind Number         (TOptObjSet用)

    KN_KWR_IWA_1A,            // 岩壊れ1A    左                 (TOptObjSet用)
    KN_KWR_IWA_2A,            // 岩壊れ2A    右                 (TOptObjSet用)
    KN_KWR_IWA_3A,            // 岩壊れ3A    上                 (TOptObjSet用)
    KN_KWR_IWA_4A,            // 岩壊れ4A    下                 (TOptObjSet用)

    KN_KWR_IWA_5A,            // 岩壊れ5A    左遠くへ         (TOptObjSet用)
    KN_KWR_IWA_6A,            // 岩壊れ6A    右遠くへ         (TOptObjSet用)
    KN_KWR_IWA_1B,            // 岩壊れ1B    左                 (TOptObjSet用)
    KN_KWR_IWA_2B,            // 岩壊れ2B    右                 (TOptObjSet用)

    KN_KWR_IWA_3B,            // 岩壊れ3B    上                 (TOptObjSet用)
    KN_KWR_IWA_4B,            // 岩壊れ4B    下                 (TOptObjSet用)
    KN_KWR_IWA_5B,            // 岩壊れ5B    左遠くへ         (TOptObjSet用)
    KN_KWR_IWA_6B,            // 岩壊れ6B    右遠くへ         (TOptObjSet用)

    KN_KWR_METAL_1A,        // 金属壊れ1A    左             (TOptObjSet用)
    KN_KWR_METAL_2A,        // 金属壊れ2A    右             (TOptObjSet用)
    KN_KWR_METAL_3A,        // 金属壊れ3A    上             (TOptObjSet用)
    KN_KWR_METAL_4A,        // 金属壊れ4A    下             (TOptObjSet用)

    KN_KWR_METAL_5A,        // 金属壊れ5A    左遠くへ    (TOptObjSet用)
    KN_KWR_METAL_6A,        // 金属壊れ6A    右遠くへ    (TOptObjSet用)
    KN_KWR_METAL_1B,        // 金属壊れ1B    左            (TOptObjSet用)
    KN_KWR_METAL_2B,        // 金属壊れ2B    右            (TOptObjSet用)

    KN_KWR_METAL_3B,        // 金属壊れ3B    上            (TOptObjSet用)
    KN_KWR_METAL_4B,        // 金属壊れ4B    下            (TOptObjSet用)
    KN_KWR_METAL_5B,        // 金属壊れ5B    左遠くへ    (TOptObjSet用)
    KN_KWR_METAL_6B,        // 金属壊れ6B    右遠くへ    (TOptObjSet用)

    KN_KWR_TREE_1A,            // 木材壊れ1A    左             (TOptObjSet用)
    KN_KWR_TREE_2A,            // 木材壊れ2A    右             (TOptObjSet用)
    KN_KWR_TREE_3A,            // 木材壊れ3A    上             (TOptObjSet用)
    KN_KWR_TREE_4A,            // 木材壊れ4A    下             (TOptObjSet用)

    KN_KWR_TREE_5A,            // 木材壊れ5A    左遠くへ    (TOptObjSet用)
    KN_KWR_TREE_6A,            // 木材壊れ6A    右遠くへ    (TOptObjSet用)
    KN_KWR_TREE_1B,            // 木材壊れ1B    左            (TOptObjSet用)
    KN_KWR_TREE_2B,            // 木材壊れ2B    右            (TOptObjSet用)

    KN_KWR_TREE_3B,            // 木材壊れ3B    上            (TOptObjSet用)
    KN_KWR_TREE_4B,            // 木材壊れ4B    下            (TOptObjSet用)
    KN_KWR_TREE_5B,            // 木材壊れ5B    左遠くへ    (TOptObjSet用)
    KN_KWR_TREE_6B,            // 木材壊れ6B    右遠くへ    (TOptObjSet用)

    KN_KWR_LEAF_A,            // 葉っぱ壊れ 共通             (TOptObjSet用)
    KN_KWR_LEAF_B,            // 葉っぱ壊れ 共通             (TOptObjSet用)
    KN_LOSTCOIN,            // 持ち時間０以降、ワリオから出るコイン(TOptObjSet用)
    KN_HIPSTAR2A,            // ヒップの星SE無しTimeUpスクロールOBJ消滅用(TOptObjSet用)

    KN_LOST_HEART,            // ワリオロストハート        (TOptObjSet用)
    KN_TUCHIKEMURI_L,        // 土煙Ｌ                    (TOptObjSet用)
    KN_TUCHIKEMURI_R,        // 土煙Ｒ                    (TOptObjSet用)
    KN_ITEM_BAKUHATU,        // 元店長専用アイテム爆発(KN_ATKSTARと同じ)    (TOptObjSet用)

    KN_ITEM_NOTE_0,            // 店長専用音符0            (TOptObjSet用)
    KN_ITEM_NOTE_1,            // 店長専用音符1            (TOptObjSet用)
    KN_ITEM_NOTE_2,            // 店長専用音符2            (TOptObjSet用)
    KN_ITEM_NOTE_3,            // 店長専用音符3            (TOptObjSet用)

    KN_ITEM_NOTE_4,            // 店長専用音符4            (TOptObjSet用)
    KN_ITEM_NOTE_5,            // 店長専用音符5            (TOptObjSet用)
    KN_ITEM_NOTE_6,            // 店長専用音符6            (TOptObjSet用)
    KN_ITEM_NOTE_7,            // 店長専用音符7            (TOptObjSet用)

    KN_ITEM_NOTE_8,            // 店長専用音符8            (TOptObjSet用)
    KN_ITEM_NOTE_9,            // 店長専用音符9            (TOptObjSet用)
    KN_GET_HEART,            // ハートゲットエフェクト    (TOptObjSet用)
    KN_GET_QHEART,            // 1/4ハートゲットエフェクト(TOptObjSet用)

    KN_ATKSTAR2,            // アタックのバシッ！の長い版(TOptObjSet用)
    KN_KAKERA_ICON_DSP,        // かけらアイコン表示        (TOptObjSet用)
    KN_CARD_ICON_DSP,        // カードアイコン表示        (TOptObjSet用)
    KN_MOUJA_HIKARI,        // モージャ専用、光            (TOptObjSet用)

    KN_KEMURI_M,            // ボス戦専用オプションけむりM(TOptObjSet用)
    KN_KEMURI_L,            // ボス戦専用オプションけむりM(TOptObjSet用)
    KN_OLDSTAR,                // 昔のアタックの星            (TOptObjSet用)
    KN_JEWELSTAR,            // 宝が上昇する時のきらきら星(TOptObjSet用)

    KN_HAKASE_AWA_L,        // 水中博士用泡Ｌ            (TOptObjSet用)
    KN_HAKASE_AWA_R,        // 水中博士用泡Ｒ            (TOptObjSet用)

// - - - - - - - - - - - - - ゲートでクリアしない＆後出し優先よりも優先↓(ここから下)

    KN_BAINOMIX2,            // 倍の実期間×２表示         (TOptObjSet用)
    KN_KAGI,                // ワリオに引っ付く鍵        (TOptObjSet用)
    KN_TIMEUP_WARIO,        // タイムアップワリオ        (TOptObjSet用)
    KN_LIFEZERO_WARIO,        // ライフゼロワリオ            (TOptObjSet用)

// - - - - - - - - - - - - - 画面の固定位置に表示↓(ここから下)

    KN_TIME_DSP,            // カウントダウンデジタル表示(TOptObjSet用)
    KN_TOKEI_ICON_DSP,        // 時計アイコン表示            (TOptObjSet用)
    KN_HIPSTAR2B,            // ヒップの星SE無しTimeUp固定画面OBJ消滅用(TOptObjSet用)
    KN_SUGOROKU_ICON_DSP,    // すごろくアイコン表示(TOptObjSet用)

    KN_END_IWA_0,            // エンディング岩０            (TOptObjSet用)
    KN_END_IWA_1,            // エンディング岩１            (TOptObjSet用)
    KN_END_IWA_2,            // エンディング岩２            (TOptObjSet用)
    KN_END_IWA_3,            // エンディング岩３            (TOptObjSet用)
    KN_END_IWA_4,            // エンディング岩４            (TOptObjSet用)
    KN_END_IWA_00,            // エンディング岩０            (TOptObjSet用)
    KN_END_IWA_000,            // エンディング岩０            (TOptObjSet用)
    KN_END_IWA_0000,        // エンディング岩０            (TOptObjSet用)
};

enum
{
    TAKARABAKO1, // 00:
    TAKARABAKO2, // 01:
    TAKARABAKO3, // 02:
    TAKARABAKO4, // 03:

    TAKARABAKO_CARD,    // 04:
    TAKARABAKO_BAINOMI, // 05:
    DAICOIN,            // 06:
    J_SWITCH,            // 07:

    TITEM_KAGI,       // 08:
    TENCHO_SAN,       // 09:
    ITEM_KEMURI_L, // 10:
    ITEM_KEMURI_M, // 11:

    ITEM_KEMURI_S,     // 12:
    W_HEART_QUARTER, // 13:
    BOSS_TAKARABAKO, // 14:
    KUTIBIRU_NEKO,     // 15:
                     //------------------------------------配置対象の敵

    ZAKO_TAKARA_BOX_DUMMY, // 16: zako_takara_box（ENDコード用、未設定敵用）
    ZAKO_MEN_YARI,           // 17: zako_men_yari
    ZAKO_MEN_YARI_BLUE,       // 18: zako_men_yari_blue
    ZAKO_MEN_YARI_RED,       // 19: zako_men_yari_red

    ASIBA_MOKUME, // 20: asiba_mokume
    ZAKO_IWA,      // 21: zako_iwa
    ZAKO_S_BIRD,  // 22: zako_s_bird
    ZAKO_HITUBO,  // 23: zako_hitubo

    KONTOGE,        // 24: kontoge
    ZAKO_TOTUMEN,    // 25: zako_totumen
    ZAKO_TAKI_FIRE, // 26: zako_taki_fire
    ZAKO_MOGURAMEN, // 27: zako_moguramen

    ZAKO_HARIMEN,    // 28: zako_harimen
    ZAKO_HARIMEN_Z, // 29: zako_harimen_z
    AWAT,            // 30: awat                （発生器）
    ZAKO_TOGEROBO,    // 31: zako_togerobo

    YUKI,             // 32: yuki
    ZAKO_TOGEMASUKU, // 33: zako_togemasuku
    ZAKO_SPK,         // 34: zako_spk            （発生器）
    ZAKO_YUKA_KIKAI, // 35: zako_yukakikai

    ZAKO_YUKA_KIKAIPRO_Y, // 36: zako_yukakikaipro
    ZAKO_YUKA_KIKAIPRO_X, // 37: zako_yukakikaipro
    ZAKO_JYUUTAN,          // 38: zako_jyuutan
    ZAKO_BOUBA,              // 39: zako_bouba

    ZAKO_ROULETTE,    // 40: zako_roulette
    DOCODOOR,        // 41: docodoor
    ZAKO_MARUMEN,    // 42: zako_marumen
    ZAKO_MARUMEN_Z, // 43: zako_marumen

    ZAKO_BIG_MARUMEN,  // 44: zako_big_marumen
    ZAKO_DOMINO_DUMMY, // 45: zako_domino
    ZAKO_DOMINO_RST,   // 46: zako_domino
    ZAKO_DOMINO_LST,   // 47: zako_domino

    ZAKO_DOMINO_R4,      // 48: zako_domino
    ZAKO_DOMINO_L4,      // 49: zako_domino
    ZAKO_DOMINO_R5D1, // 50: zako_domino
    ZAKO_DOMINO_L5D1, // 51: zako_domino

    ZAKO_DOMINO_R5U1, // 52: zako_domino
    ZAKO_DOMINO_L5U1, // 53: zako_domino
    ZAKO_DOMINO_R3D3, // 54: zako_domino
    ZAKO_DOMINO_L3D3, // 55: zako_domino

    ZAKO_DOMINO_R3U3,  // 56: zako_domino
    ZAKO_DOMINO_L3U3,  // 57: zako_domino
    ZAKO_DOMINO_RGL,   // 58: zako_domino
    ZAKO_DOMINO_BLOCK, // 59: zako_domino_block

    ZAKO_MAYUBIRD, // 60: zako_mayubird
    ZAKO_KOUMORI,  // 61: zako_koumori
    ZAKO_TOGETOGE, // 62: zako_togetoge
    ZAKO_GHOST,       // 63: zako_ghost

    ZAKO_HATI,       // 64: zako_hati
    ZAKO_FLOWER,   // 65: zako_flower
    ZAKO_IMOMUSI,  // 66: zako_imomusi
    ZAKO_TUMIKI_3, // 67: zako_tumiki（三角）

    ZAKO_TUMIKI_3K, // 68: zako_tumiki（三角のくぼみ）
    ZAKO_TUMIKI_4,    // 69: zako_tumiki（四角）
    ZAKO_TUMIKI_0,    // 70: zako_tumiki（丸）
    ZAKO_TUMIKI_3A, // 71: zako_tumiki（出現する足場）

    ZAKO_MENHAMMER, // 72: zako_menhammer
    ZAKO_MENONO,    // 73: zako_menono
    ZAKO_GUGYO,        // 74: zako_gugyo（横回遊）
    ZAKO_GUGYO_T,    // 75: zako_gugyo（縦回遊）

    ZAKO_TOBAWANI,     // 76: zako_tobawani
    ZAKO_SHELL,         // 77: zako_shell
    ZAKO_RINGOSUKEY, // 78: zako_ringosukey
    ZAKO_PISTON_S,     // 79: zako_piston(slow)

    ZAKO_PISTON_F,    // 80: zako_piston(fast)
    DORAMORI,        // 81: doramori
    DOCODOOR_31,    // 82: docodoor_31(すごろく面専用すごろくアイコン表示発生)
    ZAKO_BURANKO_L, // 83: zako_buranko(long)

    ZAKO_BURANKO_S,       // 84: zako_buranko(short)
    ASIBA_MOKUME2R,       // 85: asiba_mokume2R（右回り）
    ASIBA_MOKUME2L,       // 86: asiba_mokume2L（左回り）
    ZAKO_PINBALL_BALL, // 87: zako_pinball（敵玉）

    ZAKO_PINBALL_ENT,  // 88: zako_pinball（入り口）上向き
    ZAKO_PINBALL_ENTD, // 89: zako_pinball（入り口）下向き
    ZAKO_PINBALL_ENTL, // 90: zako_pinball（入り口）左向き
    ZAKO_PINBALL_ENTR, // 91: zako_pinball（入り口）右向き

    ZAKO_PINBALL_BLOCK, // 92: zako_pinball ブロック
    ZAKO_ROULETTE_X,    // 93: zako_roulette（何度も叩ける奴）
    ZAKO_PINBALL_TOGE,    // 94: zako_pinball_toge    （発生器）
    ZAKO_HIMAWARI,        // 95: zako_himawari

    ZAKO_SNOWMAN, // 96: zako_snowman
    ZAKO_ROCKMAN, // 97: zako_rockman
    ZAKO_MAGMA,      // 98: zako_magma
    BOSSTOBIRA0,  // 99: bosstobira

    BOSSTOBIRA1, // 100: bosstobira
    BOSSTOBIRA2, // 101: bosstobira
    BOSSTOBIRA3, // 102: bosstobira
    BOSSTOBIRA4, // 103: bosstobira

    BOSSTOBIRA5,          // 104: bosstobira
    BOSS_SHITTUKI_PUUTIN, // 105: シッキー
    ZAKO_KIYOBU,          // 106: zako_kiyobu
    ZAKO_DENDEN,          // 107: zako_denden

    ZAKO_BUTATABI, // 108: zako_butatabi
    ZAKO_DEBURINA, // 109: zako_deburina
    ZAKO_JYABARA,  // 110: zako_jyabara
    ZAKO_PENCIL_P, // 111: zako_pencil

    ZAKO_PENCIL_B, // 112: zako_pencil
    ZAKO_PENCIL_R, // 113: zako_pencil
    ZAKO_ROBOBIRD, // 114: zako_robobird
    ZAKO_UTUBO,       // 115: zako_utubo

    ZAKO_TOGENOBI,        // 116: zako_togenobi
    ZAKO_TURARA,        // 117: zako_togenobi
    FURAWANA_UEKIBACHI, // 118: furawana
    ZAKO_DICE,            // 119: zako_dice

    ZAKO_TOY_CAR,    // 120: zako_toy_car
    ZAKO_ONOMY,        // 121: zako_onomy
    ZAKO_NEKO,        // 122: zako_neko
    ZAKO_PETBOTTOM, // 123: zako_petbottom

    ZAKO_GLASS_BI,     // 124: zako_glass_bi
    MOUJA,             // 125: mouja(スタート時、パーツ用優先配置用ダミー)
    ZAKO_CHANDELIER, // 126: zako_chandelier
    ZAKO_YUKA_IWA,     // 127: zako_yuka_iwa

    ZAKO_SHITAIN, // 128: zako_shitain

    //-----------------------------grpによるキャラ＆カラーデータ転送を伴わない敵

    OBJCOIN10,    // 00: smallcoin        （チャイルド）
    OBJCOIN50,    // --: smallcoin        （チャイルド）
    OBJCOIN100, // --: smallcoin        （チャイルド）
    OBJCOIN500, // --: smallcoin        （チャイルド）

    OBJCOIN1000,    // 04: j_diamond 元dcoin（チャイルド）
    TAKARA_KAKERA1, // --:
    TAKARA_KAKERA2, // --:
    TAKARA_KAKERA3, // --:

    TAKARA_KAKERA4, // 08:
    TAKARA_CARD,    // --:
    TAKARA_BAINOMI, // --:
    HIKARI_KAKERA1, // --:

    HIKARI_KAKERA2, // 12:
    HIKARI_KAKERA3, // --:
    HIKARI_KAKERA4, // --:
    HIKARI_CARD,    // --:

    HIKARI_BAINOMI,         // 16:
    ZAKO_HITUBO_FIRE,     // --: zako_hitubo_fire1（チャイルド）
    ZAKO_HITUBO_FIRE2,     // --: zako_hitubo_fire2（チャイルド）
    ASIBA_MOKUME_YUKA3J, // --: asiba_mokume        （チャイルド）

    ASIBA_MOKUME_YUKA6J,  // 20: asiba_mokume        （チャイルド）
    ASIBA_MOKUME_YUKA9J,  // --: asiba_mokume        （チャイルド）
    ASIBA_MOKUME_YUKA12J, // --: asiba_mokume        （チャイルド）
    ZAKO_S_BIRD_TAMA,      // --: zako_s_bird        （チャイルド）

    ZAKO_S_BIRD_HONE,    // 24: zako_s_bird        （チャイルド）
    ZAKO_MOGURAMEN_IWA, // --: zako_moguramen    （チャイルド）
    AWAT_CHILD,            // --: awat                （チャイルド）
    ZAKO_TOGEROBO_HEAD, // --: zako_togerobo    （チャイルド）

    YUKI_CHILD_KAKERA, // 28: yuki                （チャイルド）
    YUKI_CHILD_HARF,   // --: yuki                （チャイルド）
    ZAKO_SPK_CHILD,       // --: zako_spk            （チャイルド）
    ZAKO_SPK_CHILD2,   // --: zako_spk            （チャイルド）

    ZAKO_BOUBA_ARROW,    // 32: zako_bouba        （チャイルド）
    ZAKO_ROULETTE_STAR, // --: zako_roulette    （チャイルド）
    DOCODOOR_UZU_BIG_A, // --: docodoor            （チャイルド）
    DOCODOOR_UZU_BIG_B, // --: docodoor            （チャイルド）

    DOCODOOR_UZU_MID_A, // 36: docodoor            （チャイルド）
    DOCODOOR_UZU_MID_B, // --: docodoor            （チャイルド）
    ZAKO_GHOST_UDE,        // --: zako_ghost        （チャイルド）
    ZAKO_GHOST_KAGI,    // --: zako_ghost        （チャイルド）

    ZAKO_TOTUMEN_PINKIE,   // 40: zako_totumen_pinkieピンキー用（チャイルド）
    J_SWITCH_STAR,           // --: j_switch            （チャイルド）
    MOUJA_RING,               // --: mouja            （チャイルド）
    ZAKO_BURANKO_L_ASHIBA, // --: zako_buranko        （チャイルド）

    ZAKO_BURANKO_S_ASHIBA, // 44: zako_buranko        （チャイルド）
    ASIBA_MOKUME2R_YUKA3J, // --: asiba_mokume2    （チャイルド）
    ASIBA_MOKUME2R_YUKA9J, // --: asiba_mokume2    （チャイルド）
    ASIBA_MOKUME2L_YUKA3J, // --: asiba_mokume2    （チャイルド）

    ASIBA_MOKUME2L_YUKA9J, // 48: asiba_mokume2    （チャイルド）
    ZAKO_RINGOSUKEY_APPLE, // --: zako_ringosukey    （チャイルド）
    DOCODOOR_WARIO_IN,       // --: docodoor            （チャイルド）
    DOCODOOR_WARIO_OUT,       // --: docodoor            （チャイルド）

    ZAKO_PINBALL_STAR,         // 52: zako_pinball        （チャイルド）
    ZAKO_TAKI_FIRE_CHILD,     // --: zako_taki_fire    （チャイルド）
    OBJCOIN1000RT,             // --: dcoin            （チャイルド）ルーレット用
    ZAKO_PINBALL_TOGE_CHILD, // --: zako_pinball_toge（チャイルド）

    ZAKO_PISTON_CHILD,    // 56: zako_piston        （チャイルド）
    ZAKO_ROCKMAN_IWA,    // --: zako_rockman        （チャイルド）
    ZAKO_SNOWMAN_REIKI, // --: zako_snowman        （チャイルド）
    ITEM_BOMB,            // --: item_bomb        （チャイルド）

    KONTOGE_DENKI, // 60: kontoge            （チャイルド）
    ITEM_CANON,       // --: item_canon        （チャイルド）
    ITEM_WHITEMAN, // --: item_whiteman    （チャイルド）
    ITEM_MUSIC,       // --: item_music        （チャイルド）

    ITEM_DOG,      // 64: item_dog            （チャイルド）
    ITEM_KISS,      // --: item_kiss        （チャイルド）
    ITEM_GENKOTU, // --: item_genkotu        （チャイルド）
    ITEM_DRAGON,  // --: item_dragon        （チャイルド）

    ITEM_CANON_TAMA,      // 68: item_canon        （チャイルド）
    ITEM_WHITEMAN_BEAM_A, // --: item_whiteman    （チャイルド）
    ITEM_WHITEMAN_BEAM_B, // --: item_whiteman    （チャイルド）
    KONTOGE_NOKOGIRI,      // ---: kontoge            （チャイルド）

    ITEM_KISS_HEART,   // 72: item_kiss        （チャイルド）
    ITEM_DRAGON_FIRE,  // --: item_dragon        （チャイルド）
    BOSS_SHITTUKI,       // --: シッキー            （チャイルド）
    BOSS_PUUTIN_ATARI, // --: シッキー            （チャイルド）

    SHITTUKI_TOGEDON,    // 76: シッキー            （チャイルド）
    SHITTUKI_FIRE,        // --: シッキー            （チャイルド）
    BOSS_JEWEL,            // --: シッキー(全ボス共通)（チャイルド）
    ZAKO_KIYOBU_KEMURI, // --: zako_kiyobu        （チャイルド）

    ZAKO_DENDEN_TAMA,    // 80: zako_denden        （チャイルド）
    ZAKO_DEBURINA_TOGE, // --: zako_deburina    （チャイルド）
    DOCODOOR_KAGI_OUT,    // --: docodoor            （チャイルド）
    ZAKO_TOGENOBI_ARM,    // --: zako_togenobi    （チャイルド）

    ZAKO_TOGENOBI_TOGE, // 84: zako_togenobi    （チャイルド）
    ZAKO_TOGENOBI_TAKO, // --: zako_togenobi    （チャイルド）
    ZAKO_TURARA_KAKERA, // --: zako_turara        （チャイルド）
    FURAWANA_HEAD,        // --: furawana_head    （チャイルド）

    FURAWANA_BODY,    // 88: furawana            （チャイルド）
    FURAWANA_OUKAN, // --: furawana            （チャイルド）
    FURAWANA_UDE_R, // --: furawana            （チャイルド）
    FURAWANA_UDE_L, // --: furawana            （チャイルド）

    FURAWANA_BUBUBAE,         // 92: furawana            （チャイルド）
    FURAWANA_BUBUBAE_HIKARI, // --: furawana            （チャイルド）
    FURAWANA_YODARE,         // --: furawana            （チャイルド）
    DORAMORI_DORIZAME,         // --: doramori            （チャイルド）

    DORAMORI_TUNAMI,         // 96: doramori            （チャイルド）
    DORAMORI_TUNAMI_SHIBUKI, // --: doramori            （チャイルド）
    DORAMORI_ICE_KEMURI,     // --: doramori            （チャイルド）
    DORAMORI_ICE,             // --: doramori            （チャイルド）

    KONTOGE_KAZAMIDORI, // 100: kontoge            （チャイルド）
    KONTOGE_ENTOTU,        // ---: kontoge            （チャイルド）
    KONTOGE_ARM,        // ---: kontoge            （チャイルド）
    KONTOGE_FURIKO,        // ---: kontoge            （チャイルド）

    KONTOGE_EGG,        // 104: kontoge            （チャイルド）
    KONTOGE_PIYO,        // ---: kontoge            （チャイルド）
    ZAKO_GLASS_BI_TAMA, // ---: zako_glass_bi    （チャイルド）
    MOUJA_FACE,            // ---: mouja

    MOUJA_BODY,         // 108: mouja            （チャイルド）
    MOUJA_ARM,         // ---: mouja            （チャイルド）
    MOUJA_OMEN,         // ---: mouja            （チャイルド）
    MOUJA_OMEN_TAMA, // ---: mouja            （チャイルド）

    MOUJA_SENSU,       // 112: mouja            （チャイルド）
    MOUJA_ZAKO_HAMMER, // ---: mouja            （チャイルド）
    MOUJA_ZAKO_KURAGE, // ---: mouja            （チャイルド）
    MOUJA_ZAKO_EGG,       // ---: mouja            （チャイルド）

    MOUJA_ZAKO_PIYO, // 116: mouja            （チャイルド）
    MOUJA_ZAKO_BALL, // ---: mouja            （チャイルド）
    MOUJA_KUTIBIRU,     // ---: mouja            （チャイルド）
    MOUJA_STAR,         // ---: mouja            （チャイルド）

    FURAWANA_KUSAIIKI,     // 120: mouja            （チャイルド）
    ZAKO_SHITAIN_AWA,     // ---: zako_shitain    （チャイルド）
    DORAMORI_HEAD_ATARI, // ---: doramori        （チャイルド）
};


enum {
    Q_INITIAL,
    Q_INITIAL2,
    Q_INITIAL3,
    Q_INITIAL4,
    Q_INITIAL5,
    Q_INITIAL6,
    Q_INITIAL7,
    Q_INITIAL8,
    Q_INITIAL9,
    Q_INITIAL10,
    Q_INITIAL11,
    Q_INITIAL12,
    Q_INITIAL13,
    Q_INITIAL14,
    Q_INITIAL15,
    Q_K0_WALK,
    K0_WALK,
    Q_K0_TURN1,
    K0_TURN1,
    Q_K0_TURN2,
    K0_TURN2,
    Q_K0_TURN3,
    K0_TURN3,
    Q_JITTO,
    JITTO,
    Q_TOBIOKI,
    TOBIOKI,
    Q_N_RAKKA_V,
    N_RAKKA_V,
    Q_H_RAKKA_V,
    H_RAKKA_V,
    Q_K2_LEFT,

    K2_LEFT,
    Q_K2_RIGHT,
    K2_RIGHT,
    Q_K1_LEFT,
    K1_LEFT,
    Q_K1_RIGHT,
    K1_RIGHT,
    Q_K6_LEFT,
    K6_LEFT,
    Q_K6_RIGHT,
    K6_RIGHT,
    Q_HIKKURI_L,
    HIKKURI_L,
    Q_HIKKURI_R,
    HIKKURI_R,
    Q_H_JITABAT,

    H_JITABAT,
    Q_K5_HIP,
    K5_HIP,
    Q_K4_LEFT,
    K4_LEFT,
    Q_K4_RIGHT,
    K4_RIGHT,
    Q_BOUND1_L,
    BOUND1_L,
    Q_BOUND2_L,
    BOUND2_L,
    Q_BOUND3_L,
    BOUND3_L,
    Q_BOUND1_R,
    BOUND1_R,
    Q_BOUND2_R,

    BOUND2_R,
    Q_BOUND3_R,
    BOUND3_R,
    Q_NH_RAKKA_L,
    NH_RAKKA_L,
    Q_NH_RAKKA_R,
    NH_RAKKA_R,
    Q_H_RAKKA_L,
    H_RAKKA_L,
    Q_H_RAKKA_R,
    H_RAKKA_R,
    Q_JISHINTOBI1,
    JISHINTOBI1,
    JISHINTOBI2,
    JISHINTOBI3,
    Q_K2D_LEFT,

    Q_K2D_RIGHT,
    Q_K3_LEFT,
    K3_LEFT,
    Q_K3_RIGHT,
    K3_RIGHT,
    Q_LF_MOVE_R,
    LF_MOVE_R,
    Q_LF_MOVE_L,
    LF_MOVE_L,
    Q_NAGE_L,
    NAGE_L,
    Q_NAGE_R,
    NAGE_R,
    Q_TNAGE_L,
    TNAGE_L,
    Q_TNAGE_R,

    TNAGE_R,
    Q_UNAGE_L,
    UNAGE_L,
    Q_UNAGE_R,
    UNAGE_R,
    Q_UTNAGE_L,
    UTNAGE_L,
    Q_UTNAGE_R,
    UTNAGE_R,
    Q_TD_ATA_R,
    Q_TD_ATA_L,
    Q_SOKUSI,
    Q_K5_HIP2,
    K5_HIP2,
    Q_T_AUX_0,
    T_AUX_0,
    Q_T_AUX_1,
    T_AUX_1,
    Q_T_AUX_2,
    T_AUX_2,
    Q_T_AUX_3,
    T_AUX_3,
    Q_T_AUX_4,
    T_AUX_4,
    Q_T_AUX_5,
    T_AUX_5,
    Q_T_AUX_6,
    T_AUX_6,
};

enum {
    NO_ATA_H,
    NO_TOGE,
    NO_TOGE2_H,
    MAE_TOGE,
    MAE_TOGE2_H,
    MOTSU,
    L_COIN,
    FLOWER_H,
    ALL_TOGE,
    ALL_TOGE2,
    ALL_TOGE3,
    ALL_TOGE4,
    ALL_TOGE5,
    ALL_TOGE_BOSS_H,
    ALL_MOERU,
    ALL_DEBU,
    ALL_ZONBI,
    ALL_ZONBI2,
    ALL_YUKI,
    ALL_BAT_H,
    ALL_ICE_H,
    OTAFUKU_H,
    TUMIKI_4_H,
    NORU_HAKO,
    NORU_HAKO2,
    NORU_HAKO_NH,
    NORU_HAKO2_NH,
    NORU_YUKA_1,
    NORU_YUKA_1ND,
    NORU_YUKA_1A,
    D_MOAI_H1,
    D_MOAI_H2,
    S_BIRD_H1,
    UE_TOGE,
    PROPERA_H,
    HARIMEN_H1,
    HARIMEN_H2,
    MAE_UE_TOGE,
    USHIRO_UE_TOGE,
    ALL_BALLOON,
    ALL_BALLOON_BOSS_H,
    BIG_MARUMEN_H,
    BIG_MARUMEN_H2,
    BIG_MARUMEN_H3,
    PUUTIN_H,
    PUUTIN2_H,
    SHITA_TOGE,
    SHITA_MAE_TOGE_H,
    J_SWITCH_H,
    HATI_H,
    HATI2_H,
    SHITA_BANE_H,
    SHITA_MAE_BANE_H,
    MENISI_H,
    ROULETTE_H,
    TOBAWANI_UE_TOGE_H,
    ALL_TOGE_MAGMA_H,
    MAE_ALL_TOGE_H,
    MAE_ALL_TOGE_N_H,
    UE_TOGE_MOTSU_TOGEDON_H,
    FURAWANA_HEAD_H,
    ALL_ZONBI_MODORI_H,
    TUNAMI_H,
    DORAMORI_H,
    DORAMORI2_H,
    DORAMORI_HEAD_H,
    KONTOGE_SHABERU_H,
    KONTOGE_SHABERU_H2,
    KONTOGE_SHABERU_H3,
    ALL_TOGE_ZERO_H,
    PIYO_BOMB_H,
    KONTOGE_OYA_H,
    MOUJA_OMEN_H,
    MOUJA_FACE_H,
    ALL_AWA,
    MAE_UE_TOGE_WH,
    SHITA_MIGI_TOGE_WH,
    UE_MIGI_TOGE_WH,
    SHELL_WH,
    TOBAWANI_WH,
    TOBAWANI_NOTOGE_WH,
    ALL_TOGE_WH,
    ALL_HAJIKU_WH,
    DORIZAME_WH,
    DORIZAME2_WH,
};


struct EnemyDataStructure
{
    unsigned short CurEnemy_usStatus;
    unsigned char pAnmData1;
    unsigned char pAnmData2;
    unsigned long OAMDataPackPointerForCurrentAnimation;
    unsigned short CurEnemy_YPos;
    unsigned short CurEnemy_XPos;
    unsigned short CurEnemy_AffinePA;
    unsigned short CurEnemy_AffinePB;
    unsigned short CurEnemy_AffinePC;
    unsigned short CurEnemy_AffinePD;
    unsigned short CurEnemy_CurrentAnimationFrameId;
    unsigned char CurEnemy_RealFrameCountForCurrentAnimationFrame;
    unsigned char CurEnemy_GlobalId;
    unsigned char CurEnemy_RoomEntitySlotId;
    unsigned char CurEnemy_ucChrOfs;
    unsigned char CurEnemy_Prio;
    unsigned char CurEnemy_paletteId;
    unsigned char CurEnemy_CurrentAnimationId;
    unsigned char CurEnemy_Life;
    unsigned char CurEnemy_GuardAndDamageParam;
    unsigned char CurEnemy_DisableInteractionWithWarioCountdown;
    unsigned char CurEnemy_SizeY0_Bottom;
    unsigned char CurEnemy_SizeY1_Top;
    unsigned char CurEnemy_SizeX_LeftRight;
    unsigned char CurEnemy_HitboxY0;
    unsigned char CurEnemy_HitboxY1;
    unsigned char CurEnemy_HitboxX0;
    unsigned char CurEnemy_HitboxX1;
    unsigned char CurEnemy_TWork0;
    unsigned char CurEnemy_TWork1;
    unsigned char CurEnemy_TWork2;
    unsigned char CurEnemy_TWork3;
    unsigned char CurEnemy_padding;
};

struct TAnmDef
{
    unsigned long uiObjAddr;
    unsigned char ucTimer;
    unsigned char unused_1;
    unsigned char unused_2;
    unsigned char unused_3;
};

#define CurrentTileset_EventIdTablePointer (*(volatile unsigned short**) 0x30031FC)

#define CurrentPassage (*(volatile unsigned char *)0x3000002)      // 00(Entry) 01(Emerald) 02(Ruby) 03(Topaz) 04(Sapphire) 05(Golden) 06(Sound Room)
#define CurrentLevel (*(volatile unsigned char *)0x3000003)          // 00(first lvl) 01(second lvl) 02(third lvl) 03(fourth lvl) 04(Boss) 05(Mini-Game Shop)
#define CurrentDifficulty (*(volatile unsigned char *)0x03000017) // 00 for normal, =01 for hard, =02 for S-hard
#define CurrentRoomId (*(volatile unsigned char *)0x3000024)
#define ENTITIES ((volatile struct EnemyDataStructure *)0x3000104)
#define EntitySet ((volatile unsigned char *)0x3000524)
#define OAMPaletteOffset ((volatile unsigned char *)0x3000544)
#define EntityLeftOverStateList ((volatile unsigned char *)0x3000564)
#define Has1stGemPiece (*(volatile unsigned char *)0x3000C07)
#define Has2ndGemPiece (*(volatile unsigned char *)0x3000C08)
#define Has3rdGemPiece (*(volatile unsigned char *)0x3000C09)
#define Has4thGemPiece (*(volatile unsigned char *)0x3000C0A)
#define HasCD (*(volatile unsigned char *)0x3000C0B)
#define ucHasKeyzer (*(volatile signed char*) 0x3000C0C)
#define WarioYPos (*(volatile unsigned short *)0x30018AC)
#define CurrentEnemyData (*(volatile struct EnemyDataStructure *)0x3000A24)

#define Layer0_DecompressedDataPointer (*(volatile unsigned int*) 0x3000054)
#define Layer0_Width (*(volatile unsigned short*) 0x3000058)
#define Layer0_Height (*(volatile unsigned short*) 0x300005A)

#define Layer1_DecompressedDataPointer (*(volatile unsigned short**) 0x300005C)
#define Layer1_Width (*(volatile unsigned short*) 0x3000060)
#define Layer1_Height (*(volatile unsigned short*) 0x3000062)

#define Layer2_DecompressedDataPointer (*(volatile unsigned int*) 0x3000064)
#define Layer2_Width (*(volatile unsigned short*) 0x3000068)
#define Layer2_Height (*(volatile unsigned short*) 0x300006A)

#define CurrentRoomHeader_LayerPriorityALphaParam (*(volatile unsigned char*) 0x300008E)

#define PanelPartWork_Broken_Main ((int (*)(int)) 0x806EE99)
#define PanelPartWork_Switch_Main ((int (*)(struct BgBDdef*,int)) 0x806F425)
#define PanelPartWork_Broken_Destroy ((int (*)(int,int,int)) 0x806F059)
#define PanelPartWork_Broken_Snow ((int (*)(int)) 0x806EFED)

#define Sub_8001DA4_m4aSongNumStart ((void (*)(int)) 0x8001DA5)
#define Sub_801E328_EnemyChildSet ((void (*)(char, char, char, int, int)) 0x801E329)
#define Sub_806ACA0_BgShakingInit ((void (*)(unsigned char, char)) 0x806ACA1)
#define Sub_806EE98_PanelPartWork_Broken_Main ((int (*)(struct BgBDdef*)) 0x806EE99)
#define Sub_806F2AC_BgBrokenBlock_ObjSet ((void (*)(struct BgBDdef*)) 0x806F2AD)
#define Sub_806F424_PanelPartWork_Switch_Main ((int (*)(struct BgBDdef*,int)) 0x806F425)
#define Sub_806F4BC_PanelPartWork_YokiDiva_Main ((int (*)(struct BgBDdef*)) 0x806F4BD)
#define Sub_806FFB0_Panel_PutBG_Save ((int (*)(int,int,int)) 0x806FFB1)
#define Sub_8070098_Panel_PutBG_Only ((int (*)(int,int,int)) 0x8070099)
#define Sub_80766E8_TOptObjSet ((void (*)(int,int,unsigned char)) 0x80766E9)
#define Sub_8088620_WarioVoiceSet ((void (*)(int)) 0x8088621)

#define Sub_8000A3C_FixMul ((signed short (*)(signed short, signed short))0x8000A3D)
#define Sub_8000A6C_FixInverse ((signed short (*)(signed short))0x8000A6D)
#define Sub_8001DA4_m4aSongNumStart ((void (*)(int))0x8001DA5)
#define Sub_8088620_WarioVoiceSet ((void (*)(int))0x8088621)
#define Sub_801E328_EnemyChildSet ((void (*)(char, char, char, int, int))0x801E329)
#define Sub_801E3A8_EnemyChildSet_LR ((void (*)(char, char, char, int, int))0x801E3A9)
#define Sub_801E430_EnemyChildSet_WS ((void (*)(char, char, char, int, int))0x801E431)
#define Sub_8026838_EnemyWanderingCom ((void (*)())0x8026839)
#define Sub_80766E8_TOptObjSet ((int (*)(int, int, char))0x80766E9) // to emit various objects ; a1 = Y, a2 = X, a3 = ID of object
#define Sub_802920C_EntityAI_0x00_0x01_0x02_0x03_0x04_0x05_Q_INITIAL_takarabako ((void (*)())0x802920D)
#define Sub_802922C_EntityAI_0x00_0x01_0x02_0x03_0x04_0x05_Q_INITIAL2_takarabako ((void (*)())0x802922D)
#define Sub_8029258_EntityAI_0x00_0x01_0x02_0x03_0x04_0x05_Q_INITIAL3_takarabako ((void (*)())0x8029259)
#define Sub_8029264_Q_K2_COM_takarabako ((void (*)())0x8029265)
#define Sub_80292BC_EntityAI_0x00_0x01_0x02_0x03_0x04_0x05_Q_K5_HIP_COM_takarabako ((void (*)())0x80292BD)
#define Sub_80292F8_EntityAI_0x00_0x01_0x02_0x03_0x04_0x05_K5_HIP_COM_takarabako ((void (*)())0x80292F9)
#define Sub_8053738_EntityAI_0x09_Tmain_tencho_san ((void (*)())0x8053739)
#define Sub_80291B8_EntityAI_SetItemBoxProperties_Q_INITIAL_COM_takarabako ((void (*)())0x80291B9)
#define Sub_8089B80_MiniRandomCreate ((int (*)(void))0x8089B81)
#define Sub_8094ED0__modsi3 ((int (*)(int, int))0x8094ED1)

#define ReBlockSw (*(volatile unsigned char*) 0x300342C)
#define ucGmScore_Tflg (*(volatile unsigned char*) 0x3000C02)
#define Wario_ucReact (*(volatile unsigned char*) 0x3001898)
#define Wario_ucStat (*(volatile unsigned char*) 0x3001899)
#define Wario_usPosX (*(volatile unsigned short*) 0x30018AA)

#define ucEnemyBrokenFlag (*(volatile unsigned char*) 0x3000028)
#define ucThit1 (*(volatile unsigned char*) 0x3000A50)
#define ucThit2 (*(volatile unsigned char*) 0x3000A51)

#define WHit (*(volatile struct WHitDef*) 0x3001918)

struct WHitDef {
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

#define MAX_Tile16_deal_at_the_same_time 20

struct AnyShapeBlockBreakdef
{
    signed char x_pos;
    signed char y_pos;
};

#define event_id_TopLeft 0x100
#define event_id_Top_border 0x101
#define event_id_TopRight 0x102
#define event_id_Left_border 0x103
#define event_id_internal 0x104
#define event_id_Right_border 0x105
#define event_id_BottomLeft 0x106
#define event_id_Bottom_border 0x107
#define event_id_BottomRight 0x108

#define event_id_one_row_left_end 0x109
#define event_id_one_row_middle 0x10A
#define event_id_one_row_right_end 0x10B
#define event_id_one_col_top_end 0x10C
#define event_id_one_col_middle 0x10D
#define event_id_one_col_bottom_end 0x10E

#define sin_cos_table ((signed short *)0x8095138)
