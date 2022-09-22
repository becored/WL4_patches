// @Description Sub_8077D5C_TKagiMark_main_Rewritten
// @HookAddress 0x78F840
// @HookString P
// Mode: Thumb
// Made by beco

// ucStatus
#define TS_EXEC_ON  0x01 // d0　処理ON/OFFフラグ
#define TS_AFFINE_ON 0x02 // d1　回転拡縮フラグ （off:0　on:1）
#define TS_AFFINE_OFF 0xFD //
#define TS_YUUSEN_ON 0x04 // d2　優先フラグ  （off:0　on:1）
#define TS_YUUSEN_OFF 0xFB //
#define TS_TENMETU_ON 0x08 // d3　点滅ON/OFFフラグ（表示:0　非表示:1）
#define TS_TENMETU_OFF 0xF7 //

struct OamData {
  unsigned VPos : 8;
	unsigned AffineMode : 1;
	unsigned AffineParam : 1;
	unsigned ObjMode : 2;
	unsigned Mosaic : 1;
	unsigned ColorMode : 1;
	unsigned Shape : 2;
	unsigned HPos : 9;
	unsigned AffineParamNo_L : 3;
	unsigned HFlip : 1;
	unsigned VFlip : 1;
	unsigned Size : 2;
	unsigned CharNo : 10;
	unsigned Priority : 2;
	unsigned Pltt : 4;
} ;

struct Tk2Def {
	unsigned char ucStatus;
	unsigned char ucAnmTimer;
	unsigned char ucKind;
	unsigned char ucSeq;
	unsigned char ucWork0;
	unsigned char ucWork1;
	unsigned short usAnmPat;
	unsigned short usPosY;
	unsigned short usPosX;
} ;

// ucTimeUp シーケンス
enum ucTimeUp_stat{
  TUP_INIT,  // ステージ開始時
  TUP_COUNT,  // 残り時間カウント時(j_switchを踏んだ時)
  TUP_MOTI_T_END, // 持ち時間0:00になった時(0:00表示が上昇するきっかけ)
  TUP_DSP_CHANGE, // 持ち時間0:00表示が消えて右隅のコイン表示と入れ替わるきっかけ
  TUP_COIN_T_END, // 持ちコイン０（OBJデモの始まるきっかけ）
  TUP_WARIO_CHANGE,// 通常ワリオ止めて、消して、正面ワリオを出すきっかけ
  TUP_WARIO_CENTER,// タイムアップワリオ、真ん中に補正完了
  TUP_WARIO_KAKUDAI_START,// タイムアップワリオ、真ん中から前に押し出されるきっかけ
  TUP_ITEM_LOST, // かけら没収デモ始まりのきっかけ
  TUP_ITEM_LOST2, // カード没収デモ始まりのきっかけ
  TUP_END,
  TUP_KILL_BOSS, // ボス戦にてボスを倒した時
};

enum {
	KN_TSCORE10A,
	KN_TSCORE50A,
	KN_TSCORE100A,
	KN_TSCORE500A,

	KN_TSCORE1000A,
	KN_HIPSTAR,				// ヒップの星のKind Number 	(TOptObjSet用)
	KN_ATKSTAR,				// アタックのバシッ！		(TOptObjSet用)
	KN_MIZUBASHIRA,			// 水柱のKind Number 		(TOptObjSet用)

	KN_KWR_IWA_1A,			// 岩壊れ1A	左			 	(TOptObjSet用)
	KN_KWR_IWA_2A,			// 岩壊れ2A	右			 	(TOptObjSet用)
	KN_KWR_IWA_3A,			// 岩壊れ3A	上			 	(TOptObjSet用)
	KN_KWR_IWA_4A,			// 岩壊れ4A	下			 	(TOptObjSet用)

	KN_KWR_IWA_5A,			// 岩壊れ5A	左遠くへ	 	(TOptObjSet用)
	KN_KWR_IWA_6A,			// 岩壊れ6A	右遠くへ	 	(TOptObjSet用)
	KN_KWR_IWA_1B,			// 岩壊れ1B	左			 	(TOptObjSet用)
	KN_KWR_IWA_2B,			// 岩壊れ2B	右			 	(TOptObjSet用)

	KN_KWR_IWA_3B,			// 岩壊れ3B	上			 	(TOptObjSet用)
	KN_KWR_IWA_4B,			// 岩壊れ4B	下			 	(TOptObjSet用)
	KN_KWR_IWA_5B,			// 岩壊れ5B	左遠くへ	 	(TOptObjSet用)
	KN_KWR_IWA_6B,			// 岩壊れ6B	右遠くへ	 	(TOptObjSet用)

	KN_KWR_METAL_1A,		// 金属壊れ1A	左		 	(TOptObjSet用)
	KN_KWR_METAL_2A,		// 金属壊れ2A	右		 	(TOptObjSet用)
	KN_KWR_METAL_3A,		// 金属壊れ3A	上		 	(TOptObjSet用)
	KN_KWR_METAL_4A,		// 金属壊れ4A	下		 	(TOptObjSet用)

	KN_KWR_METAL_5A,		// 金属壊れ5A	左遠くへ	(TOptObjSet用)
	KN_KWR_METAL_6A,		// 金属壊れ6A	右遠くへ	(TOptObjSet用)
	KN_KWR_METAL_1B,		// 金属壊れ1B	左			(TOptObjSet用)
	KN_KWR_METAL_2B,		// 金属壊れ2B	右			(TOptObjSet用)

	KN_KWR_METAL_3B,		// 金属壊れ3B	上			(TOptObjSet用)
	KN_KWR_METAL_4B,		// 金属壊れ4B	下			(TOptObjSet用)
	KN_KWR_METAL_5B,		// 金属壊れ5B	左遠くへ	(TOptObjSet用)
	KN_KWR_METAL_6B,		// 金属壊れ6B	右遠くへ	(TOptObjSet用)

	KN_KWR_TREE_1A,			// 木材壊れ1A	左		 	(TOptObjSet用)
	KN_KWR_TREE_2A,			// 木材壊れ2A	右		 	(TOptObjSet用)
	KN_KWR_TREE_3A,			// 木材壊れ3A	上		 	(TOptObjSet用)
	KN_KWR_TREE_4A,			// 木材壊れ4A	下		 	(TOptObjSet用)

	KN_KWR_TREE_5A,			// 木材壊れ5A	左遠くへ	(TOptObjSet用)
	KN_KWR_TREE_6A,			// 木材壊れ6A	右遠くへ	(TOptObjSet用)
	KN_KWR_TREE_1B,			// 木材壊れ1B	左			(TOptObjSet用)
	KN_KWR_TREE_2B,			// 木材壊れ2B	右			(TOptObjSet用)

	KN_KWR_TREE_3B,			// 木材壊れ3B	上			(TOptObjSet用)
	KN_KWR_TREE_4B,			// 木材壊れ4B	下			(TOptObjSet用)
	KN_KWR_TREE_5B,			// 木材壊れ5B	左遠くへ	(TOptObjSet用)
	KN_KWR_TREE_6B,			// 木材壊れ6B	右遠くへ	(TOptObjSet用)

	KN_KWR_LEAF_A,			// 葉っぱ壊れ 共通		 	(TOptObjSet用)
	KN_KWR_LEAF_B,			// 葉っぱ壊れ 共通		 	(TOptObjSet用)
	KN_LOSTCOIN,			// 持ち時間０以降、ワリオから出るコイン(TOptObjSet用)
	KN_HIPSTAR2A,			// ヒップの星SE無しTimeUpスクロールOBJ消滅用(TOptObjSet用)

	KN_LOST_HEART,			// ワリオロストハート		(TOptObjSet用)
	KN_TUCHIKEMURI_L,		// 土煙Ｌ					(TOptObjSet用)
	KN_TUCHIKEMURI_R,		// 土煙Ｒ					(TOptObjSet用)
	KN_ITEM_BAKUHATU,		// 元店長専用アイテム爆発(KN_ATKSTARと同じ)	(TOptObjSet用)

	KN_ITEM_NOTE_0,			// 店長専用音符0			(TOptObjSet用)
	KN_ITEM_NOTE_1,			// 店長専用音符1			(TOptObjSet用)
	KN_ITEM_NOTE_2,			// 店長専用音符2			(TOptObjSet用)
	KN_ITEM_NOTE_3,			// 店長専用音符3			(TOptObjSet用)

	KN_ITEM_NOTE_4,			// 店長専用音符4			(TOptObjSet用)
	KN_ITEM_NOTE_5,			// 店長専用音符5			(TOptObjSet用)
	KN_ITEM_NOTE_6,			// 店長専用音符6			(TOptObjSet用)
	KN_ITEM_NOTE_7,			// 店長専用音符7			(TOptObjSet用)

	KN_ITEM_NOTE_8,			// 店長専用音符8			(TOptObjSet用)
	KN_ITEM_NOTE_9,			// 店長専用音符9			(TOptObjSet用)
	KN_GET_HEART,			// ハートゲットエフェクト	(TOptObjSet用)
	KN_GET_QHEART,			// 1/4ハートゲットエフェクト(TOptObjSet用)

	KN_ATKSTAR2,			// アタックのバシッ！の長い版(TOptObjSet用)
	KN_KAKERA_ICON_DSP,		// かけらアイコン表示		(TOptObjSet用)
	KN_CARD_ICON_DSP,		// カードアイコン表示		(TOptObjSet用)
	KN_MOUJA_HIKARI,		// モージャ専用、光			(TOptObjSet用)

	KN_KEMURI_M,			// ボス戦専用オプションけむりM(TOptObjSet用)
	KN_KEMURI_L,			// ボス戦専用オプションけむりM(TOptObjSet用)
	KN_OLDSTAR,				// 昔のアタックの星			(TOptObjSet用)
	KN_JEWELSTAR,			// 宝が上昇する時のきらきら星(TOptObjSet用)

	KN_HAKASE_AWA_L,		// 水中博士用泡Ｌ			(TOptObjSet用)
	KN_HAKASE_AWA_R,		// 水中博士用泡Ｒ			(TOptObjSet用)

// - - - - - - - - - - - - - ゲートでクリアしない＆後出し優先よりも優先↓(ここから下)

	KN_BAINOMIX2,			// 倍の実期間×２表示 		(TOptObjSet用)
	KN_KAGI,				// ワリオに引っ付く鍵		(TOptObjSet用)
	KN_TIMEUP_WARIO,		// タイムアップワリオ		(TOptObjSet用)
	KN_LIFEZERO_WARIO,		// ライフゼロワリオ			(TOptObjSet用)

// - - - - - - - - - - - - - 画面の固定位置に表示↓(ここから下)

	KN_TIME_DSP,			// カウントダウンデジタル表示(TOptObjSet用)
	KN_TOKEI_ICON_DSP,		// 時計アイコン表示			(TOptObjSet用)
	KN_HIPSTAR2B,			// ヒップの星SE無しTimeUp固定画面OBJ消滅用(TOptObjSet用)
	KN_SUGOROKU_ICON_DSP,	// すごろくアイコン表示(TOptObjSet用)

	KN_END_IWA_0,			// エンディング岩０			(TOptObjSet用)
	KN_END_IWA_1,			// エンディング岩１			(TOptObjSet用)
	KN_END_IWA_2,			// エンディング岩２			(TOptObjSet用)
	KN_END_IWA_3,			// エンディング岩３			(TOptObjSet用)
	KN_END_IWA_4,			// エンディング岩４			(TOptObjSet用)
	KN_END_IWA_00,			// エンディング岩０			(TOptObjSet用)
	KN_END_IWA_000,			// エンディング岩０			(TOptObjSet用)
	KN_END_IWA_0000,		// エンディング岩０			(TOptObjSet用)

  // Custom Code
  KN_TSCORE10A_JUMP,
  KN_TSCORE100A_DASH,
};

enum {
	TAKARABAKO1,				// 00:
	TAKARABAKO2,				// 01:
	TAKARABAKO3,				// 02:
	TAKARABAKO4,				// 03:

	TAKARABAKO_CARD,			// 04:
	TAKARABAKO_BAINOMI,			// 05:
	DAICOIN,					// 06:
	J_SWITCH,					// 07:

	TITEM_KAGI,					// 08:
	TENCHO_SAN,					// 09:
	ITEM_KEMURI_L,				// 10:
	ITEM_KEMURI_M,				// 11:

	ITEM_KEMURI_S,				// 12:
	W_HEART_QUARTER,			// 13:
	BOSS_TAKARABAKO,			// 14:
	KUTIBIRU_NEKO,				// 15:
//------------------------------------配置対象の敵

	ZAKO_TAKARA_BOX_DUMMY,		// 16: zako_takara_box（ENDコード用、未設定敵用）
	ZAKO_MEN_YARI,				// 17: zako_men_yari
	ZAKO_MEN_YARI_BLUE,			// 18: zako_men_yari_blue
	ZAKO_MEN_YARI_RED,			// 19: zako_men_yari_red

	ASIBA_MOKUME,				// 20: asiba_mokume
	ZAKO_IWA,					// 21: zako_iwa
	ZAKO_S_BIRD,				// 22: zako_s_bird
	ZAKO_HITUBO,				// 23: zako_hitubo

	KONTOGE,					// 24: kontoge
	ZAKO_TOTUMEN,				// 25: zako_totumen
	ZAKO_TAKI_FIRE,				// 26: zako_taki_fire
	ZAKO_MOGURAMEN,				// 27: zako_moguramen

	ZAKO_HARIMEN,				// 28: zako_harimen
	ZAKO_HARIMEN_Z,				// 29: zako_harimen_z
	AWAT,						// 30: awat				（発生器）
	ZAKO_TOGEROBO,				// 31: zako_togerobo

	YUKI,						// 32: yuki
	ZAKO_TOGEMASUKU,			// 33: zako_togemasuku
	ZAKO_SPK,					// 34: zako_spk			（発生器）
	ZAKO_YUKA_KIKAI,			// 35: zako_yukakikai

	ZAKO_YUKA_KIKAIPRO_Y,		// 36: zako_yukakikaipro
	ZAKO_YUKA_KIKAIPRO_X,		// 37: zako_yukakikaipro
	ZAKO_JYUUTAN,				// 38: zako_jyuutan
	ZAKO_BOUBA,					// 39: zako_bouba

	ZAKO_ROULETTE,				// 40: zako_roulette
	DOCODOOR,					// 41: docodoor
	ZAKO_MARUMEN,				// 42: zako_marumen
	ZAKO_MARUMEN_Z,				// 43: zako_marumen

	ZAKO_BIG_MARUMEN,			// 44: zako_big_marumen
	ZAKO_DOMINO_DUMMY,			// 45: zako_domino
	ZAKO_DOMINO_RST,			// 46: zako_domino
	ZAKO_DOMINO_LST,			// 47: zako_domino

	ZAKO_DOMINO_R4,				// 48: zako_domino
	ZAKO_DOMINO_L4,				// 49: zako_domino
	ZAKO_DOMINO_R5D1,			// 50: zako_domino
	ZAKO_DOMINO_L5D1,			// 51: zako_domino

	ZAKO_DOMINO_R5U1,			// 52: zako_domino
	ZAKO_DOMINO_L5U1,			// 53: zako_domino
	ZAKO_DOMINO_R3D3,			// 54: zako_domino
	ZAKO_DOMINO_L3D3,			// 55: zako_domino

	ZAKO_DOMINO_R3U3,			// 56: zako_domino
	ZAKO_DOMINO_L3U3,			// 57: zako_domino
	ZAKO_DOMINO_RGL,			// 58: zako_domino
	ZAKO_DOMINO_BLOCK,			// 59: zako_domino_block

	ZAKO_MAYUBIRD,				// 60: zako_mayubird
	ZAKO_KOUMORI,				// 61: zako_koumori
	ZAKO_TOGETOGE,				// 62: zako_togetoge
	ZAKO_GHOST,					// 63: zako_ghost

	ZAKO_HATI,					// 64: zako_hati
	ZAKO_FLOWER,				// 65: zako_flower
	ZAKO_IMOMUSI,				// 66: zako_imomusi
	ZAKO_TUMIKI_3,				// 67: zako_tumiki（三角）

	ZAKO_TUMIKI_3K,				// 68: zako_tumiki（三角のくぼみ）
	ZAKO_TUMIKI_4,				// 69: zako_tumiki（四角）
	ZAKO_TUMIKI_0,				// 70: zako_tumiki（丸）
	ZAKO_TUMIKI_3A,				// 71: zako_tumiki（出現する足場）

	ZAKO_MENHAMMER,				// 72: zako_menhammer
	ZAKO_MENONO,				// 73: zako_menono
	ZAKO_GUGYO,					// 74: zako_gugyo（横回遊）
	ZAKO_GUGYO_T,				// 75: zako_gugyo（縦回遊）

	ZAKO_TOBAWANI,				// 76: zako_tobawani
	ZAKO_SHELL,					// 77: zako_shell
	ZAKO_RINGOSUKEY,			// 78: zako_ringosukey
	ZAKO_PISTON_S,				// 79: zako_piston(slow)

	ZAKO_PISTON_F,				// 80: zako_piston(fast)
	DORAMORI,					// 81: doramori
	DOCODOOR_31,				// 82: docodoor_31(すごろく面専用すごろくアイコン表示発生)
	ZAKO_BURANKO_L,				// 83: zako_buranko(long)

	ZAKO_BURANKO_S,				// 84: zako_buranko(short)
	ASIBA_MOKUME2R,				// 85: asiba_mokume2R（右回り）
	ASIBA_MOKUME2L,				// 86: asiba_mokume2L（左回り）
	ZAKO_PINBALL_BALL,			// 87: zako_pinball（敵玉）

	ZAKO_PINBALL_ENT,			// 88: zako_pinball（入り口）上向き
	ZAKO_PINBALL_ENTD,			// 89: zako_pinball（入り口）下向き
	ZAKO_PINBALL_ENTL,			// 90: zako_pinball（入り口）左向き
	ZAKO_PINBALL_ENTR,			// 91: zako_pinball（入り口）右向き

	ZAKO_PINBALL_BLOCK,			// 92: zako_pinball ブロック
	ZAKO_ROULETTE_X,			// 93: zako_roulette（何度も叩ける奴）
	ZAKO_PINBALL_TOGE,			// 94: zako_pinball_toge	（発生器）
	ZAKO_HIMAWARI,				// 95: zako_himawari

	ZAKO_SNOWMAN,				// 96: zako_snowman
	ZAKO_ROCKMAN,				// 97: zako_rockman
	ZAKO_MAGMA,					// 98: zako_magma
	BOSSTOBIRA0,				// 99: bosstobira

	BOSSTOBIRA1,				// 100: bosstobira
	BOSSTOBIRA2,				// 101: bosstobira
	BOSSTOBIRA3,				// 102: bosstobira
	BOSSTOBIRA4,				// 103: bosstobira

	BOSSTOBIRA5,				// 104: bosstobira
	BOSS_SHITTUKI_PUUTIN,		// 105: シッキー
	ZAKO_KIYOBU,				// 106: zako_kiyobu
	ZAKO_DENDEN,				// 107: zako_denden

	ZAKO_BUTATABI,				// 108: zako_butatabi
	ZAKO_DEBURINA,				// 109: zako_deburina
	ZAKO_JYABARA,				// 110: zako_jyabara
	ZAKO_PENCIL_P,				// 111: zako_pencil

	ZAKO_PENCIL_B,				// 112: zako_pencil
	ZAKO_PENCIL_R,				// 113: zako_pencil
	ZAKO_ROBOBIRD,				// 114: zako_robobird
	ZAKO_UTUBO,					// 115: zako_utubo

	ZAKO_TOGENOBI,				// 116: zako_togenobi
	ZAKO_TURARA,				// 117: zako_togenobi
	FURAWANA_UEKIBACHI,			// 118: furawana
	ZAKO_DICE,					// 119: zako_dice

	ZAKO_TOY_CAR,				// 120: zako_toy_car
	ZAKO_ONOMY,					// 121: zako_onomy
	ZAKO_NEKO,					// 122: zako_neko
	ZAKO_PETBOTTOM,				// 123: zako_petbottom

	ZAKO_GLASS_BI,				// 124: zako_glass_bi
	MOUJA,						// 125: mouja(スタート時、パーツ用優先配置用ダミー)
	ZAKO_CHANDELIER,			// 126: zako_chandelier
	ZAKO_YUKA_IWA,				// 127: zako_yuka_iwa

	ZAKO_SHITAIN,				// 128: zako_shitain

//-----------------------------grpによるキャラ＆カラーデータ転送を伴わない敵

	OBJCOIN10,					// 00: smallcoin		（チャイルド）
	OBJCOIN50,					// --: smallcoin		（チャイルド）
	OBJCOIN100,					// --: smallcoin		（チャイルド）
	OBJCOIN500,					// --: smallcoin		（チャイルド）

	OBJCOIN1000,				// 04: j_diamond 元dcoin（チャイルド）
	TAKARA_KAKERA1,				// --:
	TAKARA_KAKERA2,				// --:
	TAKARA_KAKERA3,				// --:

	TAKARA_KAKERA4,				// 08:
	TAKARA_CARD,				// --:
	TAKARA_BAINOMI,				// --:
	HIKARI_KAKERA1,				// --:

	HIKARI_KAKERA2,				// 12:
	HIKARI_KAKERA3,				// --:
	HIKARI_KAKERA4,				// --:
	HIKARI_CARD,				// --:

	HIKARI_BAINOMI,				// 16:
	ZAKO_HITUBO_FIRE,			// --: zako_hitubo_fire1（チャイルド）
	ZAKO_HITUBO_FIRE2,			// --: zako_hitubo_fire2（チャイルド）
	ASIBA_MOKUME_YUKA3J,		// --: asiba_mokume		（チャイルド）

	ASIBA_MOKUME_YUKA6J,		// 20: asiba_mokume		（チャイルド）
	ASIBA_MOKUME_YUKA9J,		// --: asiba_mokume		（チャイルド）
	ASIBA_MOKUME_YUKA12J,		// --: asiba_mokume		（チャイルド）
	ZAKO_S_BIRD_TAMA,			// --: zako_s_bird		（チャイルド）

	ZAKO_S_BIRD_HONE,			// 24: zako_s_bird		（チャイルド）
	ZAKO_MOGURAMEN_IWA,			// --: zako_moguramen	（チャイルド）
	AWAT_CHILD,					// --: awat				（チャイルド）
	ZAKO_TOGEROBO_HEAD,			// --: zako_togerobo	（チャイルド）

	YUKI_CHILD_KAKERA,			// 28: yuki				（チャイルド）
	YUKI_CHILD_HARF,			// --: yuki				（チャイルド）
	ZAKO_SPK_CHILD,				// --: zako_spk			（チャイルド）
	ZAKO_SPK_CHILD2,			// --: zako_spk			（チャイルド）

	ZAKO_BOUBA_ARROW,			// 32: zako_bouba		（チャイルド）
	ZAKO_ROULETTE_STAR,			// --: zako_roulette	（チャイルド）
	DOCODOOR_UZU_BIG_A,			// --: docodoor			（チャイルド）
	DOCODOOR_UZU_BIG_B,			// --: docodoor			（チャイルド）

	DOCODOOR_UZU_MID_A,			// 36: docodoor			（チャイルド）
	DOCODOOR_UZU_MID_B,			// --: docodoor			（チャイルド）
	ZAKO_GHOST_UDE,				// --: zako_ghost		（チャイルド）
	ZAKO_GHOST_KAGI,			// --: zako_ghost		（チャイルド）

	ZAKO_TOTUMEN_PINKIE,		// 40: zako_totumen_pinkieピンキー用（チャイルド）
	J_SWITCH_STAR,				// --: j_switch			（チャイルド）
	MOUJA_RING,					// --: mouja			（チャイルド）
	ZAKO_BURANKO_L_ASHIBA,		// --: zako_buranko		（チャイルド）

	ZAKO_BURANKO_S_ASHIBA,		// 44: zako_buranko		（チャイルド）
	ASIBA_MOKUME2R_YUKA3J,		// --: asiba_mokume2	（チャイルド）
	ASIBA_MOKUME2R_YUKA9J,		// --: asiba_mokume2	（チャイルド）
	ASIBA_MOKUME2L_YUKA3J,		// --: asiba_mokume2	（チャイルド）

	ASIBA_MOKUME2L_YUKA9J,		// 48: asiba_mokume2	（チャイルド）
	ZAKO_RINGOSUKEY_APPLE,		// --: zako_ringosukey	（チャイルド）
	DOCODOOR_WARIO_IN,			// --: docodoor			（チャイルド）
	DOCODOOR_WARIO_OUT,			// --: docodoor			（チャイルド）

	ZAKO_PINBALL_STAR,			// 52: zako_pinball		（チャイルド）
	ZAKO_TAKI_FIRE_CHILD,		// --: zako_taki_fire	（チャイルド）
	OBJCOIN1000RT,				// --: dcoin			（チャイルド）ルーレット用
	ZAKO_PINBALL_TOGE_CHILD,	// --: zako_pinball_toge（チャイルド）

	ZAKO_PISTON_CHILD,			// 56: zako_piston		（チャイルド）
	ZAKO_ROCKMAN_IWA,			// --: zako_rockman		（チャイルド）
	ZAKO_SNOWMAN_REIKI,			// --: zako_snowman		（チャイルド）
	ITEM_BOMB,					// --: item_bomb		（チャイルド）

	KONTOGE_DENKI,				// 60: kontoge			（チャイルド）
	ITEM_CANON,					// --: item_canon		（チャイルド）
	ITEM_WHITEMAN,				// --: item_whiteman	（チャイルド）
	ITEM_MUSIC,					// --: item_music		（チャイルド）

	ITEM_DOG,					// 64: item_dog			（チャイルド）
	ITEM_KISS,					// --: item_kiss		（チャイルド）
	ITEM_GENKOTU,				// --: item_genkotu		（チャイルド）
	ITEM_DRAGON,				// --: item_dragon		（チャイルド）

	ITEM_CANON_TAMA,			// 68: item_canon		（チャイルド）
	ITEM_WHITEMAN_BEAM_A,		// --: item_whiteman	（チャイルド）
	ITEM_WHITEMAN_BEAM_B,		// --: item_whiteman	（チャイルド）
	KONTOGE_NOKOGIRI,			// ---: kontoge			（チャイルド）

	ITEM_KISS_HEART,			// 72: item_kiss		（チャイルド）
	ITEM_DRAGON_FIRE,			// --: item_dragon		（チャイルド）
	BOSS_SHITTUKI,				// --: シッキー			（チャイルド）
	BOSS_PUUTIN_ATARI,			// --: シッキー			（チャイルド）

	SHITTUKI_TOGEDON,			// 76: シッキー			（チャイルド）
	SHITTUKI_FIRE,				// --: シッキー			（チャイルド）
	BOSS_JEWEL,					// --: シッキー(全ボス共通)（チャイルド）
	ZAKO_KIYOBU_KEMURI,			// --: zako_kiyobu		（チャイルド）

	ZAKO_DENDEN_TAMA,			// 80: zako_denden		（チャイルド）
	ZAKO_DEBURINA_TOGE,			// --: zako_deburina	（チャイルド）
	DOCODOOR_KAGI_OUT,			// --: docodoor			（チャイルド）
	ZAKO_TOGENOBI_ARM,			// --: zako_togenobi	（チャイルド）

	ZAKO_TOGENOBI_TOGE,			// 84: zako_togenobi	（チャイルド）
	ZAKO_TOGENOBI_TAKO,			// --: zako_togenobi	（チャイルド）
	ZAKO_TURARA_KAKERA,			// --: zako_turara		（チャイルド）
	FURAWANA_HEAD,				// --: furawana_head	（チャイルド）

	FURAWANA_BODY,				// 88: furawana			（チャイルド）
	FURAWANA_OUKAN,				// --: furawana			（チャイルド）
	FURAWANA_UDE_R,				// --: furawana			（チャイルド）
	FURAWANA_UDE_L,				// --: furawana			（チャイルド）

	FURAWANA_BUBUBAE,			// 92: furawana			（チャイルド）
	FURAWANA_BUBUBAE_HIKARI,	// --: furawana			（チャイルド）
	FURAWANA_YODARE,			// --: furawana			（チャイルド）
	DORAMORI_DORIZAME,			// --: doramori			（チャイルド）

	DORAMORI_TUNAMI,			// 96: doramori			（チャイルド）
	DORAMORI_TUNAMI_SHIBUKI,	// --: doramori			（チャイルド）
	DORAMORI_ICE_KEMURI,		// --: doramori			（チャイルド）
	DORAMORI_ICE,				// --: doramori			（チャイルド）

	KONTOGE_KAZAMIDORI,			// 100: kontoge			（チャイルド）
	KONTOGE_ENTOTU,				// ---: kontoge			（チャイルド）
	KONTOGE_ARM,				// ---: kontoge			（チャイルド）
	KONTOGE_FURIKO,				// ---: kontoge			（チャイルド）

	KONTOGE_EGG,				// 104: kontoge			（チャイルド）
	KONTOGE_PIYO,				// ---: kontoge			（チャイルド）
	ZAKO_GLASS_BI_TAMA,			// ---: zako_glass_bi	（チャイルド）
	MOUJA_FACE,					// ---: mouja

	MOUJA_BODY,					// 108: mouja			（チャイルド）
	MOUJA_ARM,					// ---: mouja			（チャイルド）
	MOUJA_OMEN,					// ---: mouja			（チャイルド）
	MOUJA_OMEN_TAMA,			// ---: mouja			（チャイルド）

	MOUJA_SENSU,				// 112: mouja			（チャイルド）
	MOUJA_ZAKO_HAMMER,			// ---: mouja			（チャイルド）
	MOUJA_ZAKO_KURAGE,			// ---: mouja			（チャイルド）
	MOUJA_ZAKO_EGG,				// ---: mouja			（チャイルド）

	MOUJA_ZAKO_PIYO,			// 116: mouja			（チャイルド）
	MOUJA_ZAKO_BALL,			// ---: mouja			（チャイルド）
	MOUJA_KUTIBIRU,				// ---: mouja			（チャイルド）
	MOUJA_STAR,					// ---: mouja			（チャイルド）

	FURAWANA_KUSAIIKI,			// 120: mouja			（チャイルド）
	ZAKO_SHITAIN_AWA,			// ---: zako_shitain	（チャイルド）
	DORAMORI_HEAD_ATARI,		// ---: doramori		（チャイルド）
};

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

enum {
	KNH_WAKEUP,
	Q_KNH_WALK_L,
	KNH_WALK_L,
	Q_KNH_WALK_R,
	KNH_WALK_R,
	Q_KNH_TURN_L2R,
	KNH_TURN_L2R,
	Q_KNH_TURN_R2L,
	KNH_TURN_R2L,

	Q_KNH_TURN_L2USIRO,
	KNH_TURN_L2USIRO,
	Q_KNH_TURN_R2USIRO,
	KNH_TURN_R2USIRO,
	Q_KNH_USIRO,
	KNH_USIRO,
	Q_KNH_TURN_USIRO2L,
	KNH_TURN_USIRO2L,
	Q_KNH_TURN_USIRO2R,
	KNH_TURN_USIRO2R,
};

#define REG_DMA3SAD (*(volatile unsigned int*) 0x40000D4)
#define REG_DMA3DAD (*(volatile unsigned int*) 0x40000D8)
#define REG_DMA3CNT (*(volatile unsigned int*) 0x40000DC)

#define Sub_806C75C_GmapBg_AnimatedMain ((void (*)()) 0x806C75D)
#define Sub_801D684_EnemyMain ((void (*)()) 0x801D685)
#define Sub_806E7F8_GmScrSet ((void (*)()) 0x806E7F9)
#define Sub_8010154_WarioDispMain ((void (*)()) 0x8010155)
#define Sub_8074808_WarioHeartMake ((void (*)()) 0x8074809)
#define Sub_8074988_GmScoreCreate ((void (*)()) 0x8074989)
#define Sub_80751FC_TmScMain ((void (*)()) 0x80751FD)
#define Sub_801C5D8_GmWarioCreate ((void (*)()) 0x801C5D9)
#define Sub_801D8C4_EnemyDisplayMain ((void (*)()) 0x801D8C5)
#define Sub_8000A0C_ClearOamBuf ((int (*)()) 0x8000A0D)
#define Sub_806C794_GmapSceneCreate ((void (*)(int)) 0x806C795)
#define Sub_80101D0_WarioSoundMain ((void (*)()) 0x80101D1)
#define Sub_806C130_MapBgmChangeMain ((void (*)()) 0x806C131)
#define Sub_80762E4_TScoreOamCreate ((void (*)(int)) 0x80762E5)
#define Sub_8075988_GmTimerSub_loseCoinSoundsPalette ((void (*)()) 0x8075989)
#define Sub_80752F0_CoinChrScore ((void (*)()) 0x80752F1)
#define Sub_8075388_TimeChrScore ((void (*)()) 0x8075389)
#define Sub_807569C_TimeChrScore2 ((void (*)()) 0x807569D)
#define Sub_8094DFC_call_via_r0 ((void (*)(int)) 0x8094DFD)
#define Sub_8076A0C_TimeScore_Animation ((void (*)(int)) 0x8076A0D)
#define Sub_8000A3C_FixMul ((int (*)(int,int)) 0x8000A3D)
#define Sub_8000A6C_FixInverse ((int (*)(int)) 0x8000A6D)
#define Sub_801E430_EnemyChildSet_WS ((void (*)(char,char,char,short,short)) 0x801E431)
#define Sub_8076784_Change_KN_HIPSTAR2A ((void (*)()) 0x8076785)

#define ucStageNum (*(volatile unsigned char*) 0x3000003)
#define ucHeyaNum (*(volatile unsigned char*) 0x3000024)
#define ucTimeUp (*(volatile unsigned char*) 0x3000047)
#define ScEbuf ((volatile struct Tk2Def*) 0x3000B80) // 12 bytes
#define Scbuf (*(volatile struct Tk2Def*) 0x3000BE0) // 12 bytes
#define iGmTimeFrame (*(volatile unsigned short*) 0x3000BEC)

#define ucGmTime_Tflg (*(volatile unsigned char*) 0x3000C01)
#define ucGmScore_Tflg (*(volatile unsigned char*) 0x3000C02)
#define ucGmTimeCc_Tflg (*(volatile unsigned char*) 0x3000C03)
#define ucWarioOutStartFlg (*(volatile unsigned char*) 0x3000C0E)
#define usAffnPA (*(volatile unsigned short*) 0x3000C14)
#define usAffnPB (*(volatile unsigned short*) 0x3000C16)
#define usAffnPC (*(volatile unsigned short*) 0x3000C18)
#define usAffnPD (*(volatile unsigned short*) 0x3000C1A)
#define ucDocodoorChrOfs (*(volatile unsigned short*) 0x3000C24)
#define usDocodoorPosY (*(volatile unsigned short*) 0x3000C26)
#define usDocodoorPosX (*(volatile unsigned short*) 0x3000C28)
#define sGameSeq (*(volatile unsigned char*) 0x3000C3C)

#define OamBuf ((volatile struct OamData*) 0x3001444)
#define coinNumOAMPal1 (*(volatile unsigned char*) 0x3001449)
#define coinNumOAMPal2 (*(volatile unsigned char*) 0x3001459)
#define ucCntObj (*(volatile unsigned char*) 0x300184A)
#define Wario_ucReact (*(volatile unsigned char*) 0x3001898)
#define Wario_ucStat (*(volatile unsigned char*) 0x3001899)
#define Wario_usMukiX (*(volatile unsigned short*) 0x30018A6)
#define Wario_usMukiY (*(volatile unsigned short*) 0x30018A8)
#define Wario_usPosX (*(volatile unsigned short*) 0x30018AA)
#define Wario_usPosY (*(volatile unsigned short*) 0x30018AC)
#define Wario_sHitDX1 (*(volatile short*) 0x30018CA)
#define Wario_sHitDY1 (*(volatile short*) 0x30018CC)
#define ucWarOffFlg (*(volatile unsigned char*) 0x30019F8)

#define sin_cos_table ((volatile unsigned short*) 0x8095138)

#define	KAGI_WAKEUP_TIME 48-1
#define	KAGI_TURN_TIME 25-1
#define	KAGI_TURN_2USIRO_TIME 10-1
#define	KAGI_TURN_USIRO2_TIME 16-1

#define KAGI_WAKEUP_L 0x83B49BC
#define KAGI_WALK_L 0x83B47C4
#define KAGI_WALK_R 0x83B47EC
#define KAGI_TURN_L2R 0x83B48DC
#define KAGI_TURN_R2L 0x83B4904
#define KAGI_TURN_L2USIRO 0x83B4814
#define KAGI_TURN_R2USIRO 0x83B483C
#define KAGI_USIRO 0x83B4864
#define KAGI_TURN_USIRO2L 0x83B488C
#define KAGI_TURN_USIRO2R 0x83B48B4

struct TAnmDef {
  unsigned long uiObjAddr;
  unsigned char ucTimer;
  unsigned char unused_1;
  unsigned char unused_2;
  unsigned char unused_3;
};

void Sub_8077D5C_TKagiMark_main_Rewritten() {
    // Vanilla code
    unsigned short a,b;
    unsigned short wy,wx,ky,kx,dx,dy;
    char ws;

  	ws = 0;	// 普通状態

  	if(!Wario_ucReact)
  	{
  		if(Wario_ucStat >= LDMOVE && Wario_ucStat <= NETDOWN)	ws = 1;	// 梯子状態
  		else if(Wario_ucStat == DOKANU || Wario_ucStat == DOKAND)	ws = 1;	// 土管状態
  	}

  	if(ucTimeUp >= TUP_WARIO_CHANGE)
  	{
  		Sub_8076784_Change_KN_HIPSTAR2A();
  		return;
  	}


  	switch(Scbuf.ucSeq)
  	{
  		case KNH_WAKEUP:
  			Sub_8076A0C_TimeScore_Animation(KAGI_WAKEUP_L);
  			if(++Scbuf.ucWork0 < KAGI_WAKEUP_TIME);
  			else	Scbuf.ucSeq = Q_KNH_WALK_L;
  			break;

  		case Q_KNH_WALK_L:
  			Scbuf.ucSeq = KNH_WALK_L;
  			Scbuf.usAnmPat = 0;
  			Scbuf.ucAnmTimer = 0;
  		case KNH_WALK_L:
  			Sub_8076A0C_TimeScore_Animation(KAGI_WALK_L);
  			if(ws)	Scbuf.ucSeq = Q_KNH_TURN_L2USIRO;
  			else if(Wario_usMukiX & 0x10)	Scbuf.ucSeq = Q_KNH_TURN_L2R; // R_KEY
  			break;

  		case Q_KNH_WALK_R:
  			Scbuf.ucSeq = KNH_WALK_R;
  			Scbuf.usAnmPat = 0;
  			Scbuf.ucAnmTimer = 0;
  		case KNH_WALK_R:
  			Sub_8076A0C_TimeScore_Animation(KAGI_WALK_R);
  			if(ws)	Scbuf.ucSeq = Q_KNH_TURN_R2USIRO;
  			else if(Wario_usMukiX & 0x20)	Scbuf.ucSeq = Q_KNH_TURN_R2L; // L_KEY
  			break;

  		case Q_KNH_TURN_L2R:
  			Scbuf.ucSeq = KNH_TURN_L2R;
  			Scbuf.ucWork0 = KAGI_TURN_TIME;
  			Scbuf.usAnmPat = 0;
  			Scbuf.ucAnmTimer = 0;
  		case KNH_TURN_L2R:
  			Sub_8076A0C_TimeScore_Animation(KAGI_TURN_L2R);
  			if(--Scbuf.ucWork0);
  			else	Scbuf.ucSeq = Q_KNH_WALK_R;
  			break;

  		case Q_KNH_TURN_R2L:
  			Scbuf.ucSeq = KNH_TURN_R2L;
  			Scbuf.ucWork0 = KAGI_TURN_TIME;
  			Scbuf.usAnmPat = 0;
  			Scbuf.ucAnmTimer = 0;
  		case KNH_TURN_R2L:
  			Sub_8076A0C_TimeScore_Animation(KAGI_TURN_R2L);
  			if(--Scbuf.ucWork0);
  			else	Scbuf.ucSeq = Q_KNH_WALK_L;
  			break;

  		case Q_KNH_TURN_L2USIRO:
  			Scbuf.ucSeq = KNH_TURN_L2USIRO;
  			Scbuf.ucWork0 = KAGI_TURN_2USIRO_TIME;
  			Scbuf.usAnmPat = 0;
  			Scbuf.ucAnmTimer = 0;
  		case KNH_TURN_L2USIRO:
  			Sub_8076A0C_TimeScore_Animation(KAGI_TURN_L2USIRO);
  			if(--Scbuf.ucWork0);
  			else	Scbuf.ucSeq = Q_KNH_USIRO;
  			break;

  		case Q_KNH_TURN_R2USIRO:
  			Scbuf.ucSeq = KNH_TURN_R2USIRO;
  			Scbuf.ucWork0 = KAGI_TURN_2USIRO_TIME;
  			Scbuf.usAnmPat = 0;
  			Scbuf.ucAnmTimer = 0;
  		case KNH_TURN_R2USIRO:
  			Sub_8076A0C_TimeScore_Animation(KAGI_TURN_R2USIRO);
  			if(--Scbuf.ucWork0);
  			else	Scbuf.ucSeq = Q_KNH_USIRO;
  			break;

  		case Q_KNH_USIRO:
  			Scbuf.ucSeq = KNH_USIRO;
  			Scbuf.usAnmPat = 0;
  			Scbuf.ucAnmTimer = 0;
  		case KNH_USIRO:
  			Sub_8076A0C_TimeScore_Animation(KAGI_USIRO);
  			if(!ws)
  			{
  				if(Wario_usMukiX & 0x20)	Scbuf.ucSeq = Q_KNH_TURN_USIRO2L; // L_KEY
  				else	Scbuf.ucSeq = Q_KNH_TURN_USIRO2R;
  			}
  			break;

  		case Q_KNH_TURN_USIRO2L:
  			Scbuf.ucSeq = KNH_TURN_USIRO2L;
  			Scbuf.ucWork0 = KAGI_TURN_USIRO2_TIME;
  			Scbuf.usAnmPat = 0;
  			Scbuf.ucAnmTimer = 0;
  		case KNH_TURN_USIRO2L:
  			Sub_8076A0C_TimeScore_Animation(KAGI_TURN_USIRO2L);
  			if(--Scbuf.ucWork0);
  			else	Scbuf.ucSeq = Q_KNH_WALK_L;
  			break;

  		case Q_KNH_TURN_USIRO2R:
  			Scbuf.ucSeq = KNH_TURN_USIRO2R;
  			Scbuf.ucWork0 = KAGI_TURN_USIRO2_TIME;
  			Scbuf.usAnmPat = 0;
  			Scbuf.ucAnmTimer = 0;
  		case KNH_TURN_USIRO2R:
  			Sub_8076A0C_TimeScore_Animation(KAGI_TURN_USIRO2R);
  			if(--Scbuf.ucWork0);
  			else	Scbuf.ucSeq = Q_KNH_WALK_R;
  			break;

  		default:
  			Sub_8076A0C_TimeScore_Animation(KAGI_USIRO);
  			break;
  	}


  // ワリオ、どこでもドアーに入って脱出状態になった時

  	if(ucWarioOutStartFlg)
  	{
  		//------------------------ X pos 作る
  		dx = 0;
  		kx = Scbuf.usPosX+512;
  		wx = usDocodoorPosX+512;
  		if(kx > wx)	dx = kx - wx;
  		else	dx = wx - kx;

  		if(dx <= 8)	a = 0;
  		else	a = (dx-8) >> 3;

  		if(kx > wx)	Scbuf.usPosX -= a;
  		else if(kx < wx)	Scbuf.usPosX += a;

  		//------------------------ Y pos 作る
  		dy = 0;
  		ky = Scbuf.usPosY+512;
  		wy = usDocodoorPosY+512;

  		if(ky > wy)	dy = ky - wy;
  		else	dy = wy - ky;

  		if(dy <= 8)	b = 0;
  		else	b = (dy-8) >> 3;

  		if(ky > wy)	Scbuf.usPosY -= b;
  		else if(ky < wy)	Scbuf.usPosY += b;

  		if(!a && !b)
  		{
  			Sub_801E430_EnemyChildSet_WS(DOCODOOR_KAGI_OUT, 0, ucDocodoorChrOfs, usDocodoorPosY, usDocodoorPosX);
  			Scbuf.ucStatus = 0;
  		}
  		return;
  	}

  // 通常時
  //--------------------------------------------- X pos 作る
  	dx = 0;
  	kx = Scbuf.usPosX+512;
  	wx = Wario_usPosX+512;

  	if(ws)	b = 4;
  	else	b = 64;

  	if(Wario_usMukiX & 0x20) // L_KEY
  	{
  		wx += b;

  		if(kx > wx)	dx = kx - wx;
  		else	dx = wx - kx;

  		if(dx <= 8)	a = 0;
  		else	a = (dx-8) >> 3;

  		if(kx > wx)	Scbuf.usPosX -= a;
  		else if(kx < wx)	Scbuf.usPosX += a;
  	}
  	else
  	{
  		wx -= b;

  		if(kx > wx)	dx = kx - wx;
  		else	dx = wx - kx;

  		if(dx <= 8)	a = 0;
  		else	a = (dx-8) >> 3;

  		if(kx < wx)	Scbuf.usPosX += a;
  		else if(kx > wx)	Scbuf.usPosX -= a;
  	}
  //--------------------------------------------- Y pos 作る
  	dy = 0;
  	ky = Scbuf.usPosY+512;
  	if(ws)	wy = Wario_usPosY+512;
  	else	wy = Wario_usPosY+Wario_sHitDY1+512;

  	if(ky > wy)	dy = ky - wy;
  	else	dy = wy - ky;

  	if(dy <= 8)	a = 0;
  	else	a = (dy-8) >> 3;

  	if(ky > wy)	Scbuf.usPosY -= a;
  	else if(ky < wy)	Scbuf.usPosY += a;
}
