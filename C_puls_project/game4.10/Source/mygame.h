#include "BossCannon.h"
#include "Boss.h"
#include "Trashcannon.h"
#include "Monster.h"
#include "nightmareCannon.h"
#include "nightmare.h"
#include "Bat.h"
#include "Terrain.h"
#include "RockCannon.h"
#include "Rockman.h"
namespace game_framework {
enum AUDIO_ID {				// 定義各種音效的編號
    AUDIO_OPTIONMOVE,		// 0
    AUDIO_ENTER,			// 1
	AUDIO_START,			// 2
    AUDIO_NTUT,				// 3
	AUDIO_JUMP,				// 4
	AUDIO_JUMP2,			// 5
	AUDIO_SPRINT,			// 6
	AUDIO_INJURE,			// 7
	AUDIO_CANNON1,			// 8
	AUDIO_CANNON2,			// 9
	AUDIO_CANNON3,			// 10
	AUDIO_CANNON3_2,		// 11
	AUDIO_CHARGE,			// 12
	AUDIO_CHARGE_LOOP,		// 13
	AUDIO_BOOM,				// 14
	AUDIO_ENEMY_FIRE,		// 15
	AUDIO_BOSS_STAGE,		// 16
	AUDIO_BOSS_SPRINT,		// 17
	AUDIO_BOSS_SPRINT_2,	// 18
	AUDIO_BOSS_FIRE,		// 19
	AUDIO_BOSS_CHOP,		// 20
	AUDIO_BOSS_DES,			// 21
	AUDIO_BOSS_DES_2,		// 22
	AUDIO_BOSS_KILL,		// 23
	AUDIO_BOSS_KILL_2,		// 24
	AUDIO_BOSS_DEAD,		// 25
};

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲開頭畫面物件
// 每個Member function的Implementation都要弄懂
/////////////////////////////////////////////////////////////////////////////
class CGameStateInit : public CGameState {
    public:
        CGameStateInit(CGame* g);
        void OnInit();  								// 遊戲的初值及圖形設定
        void OnBeginState();							// 設定每次重玩所需的變數
        void OnKeyUp(UINT, UINT, UINT); 				// 處理鍵盤Up的動作
        void OnLButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
    protected:
        void OnShow();									// 顯示這個狀態的遊戲畫面
    private:
        CMovingBitmap gameStartBackground;				//圖片:遊戲選項主畫面
        CMovingBitmap option1;							//圖片:遊戲選項1(開始遊戲)
        CMovingBitmap option2;							//圖片:遊戲選項2(操作指南)
        CMovingBitmap option3;							//圖片:遊戲選項3(關於)
		CMovingBitmap option4;							//圖片:遊戲選項4(結束遊戲)
        CMovingBitmap option1Select;					//圖片:遊戲選項1選擇(開始遊戲)
        CMovingBitmap option2Select;					//圖片:遊戲選項2選擇(操作指南)
        CMovingBitmap option3Select;					//圖片:遊戲選項3選擇(關於)
		CMovingBitmap option4Select;					//圖片:遊戲選項4選擇(結束遊戲)
        CMovingBitmap controlGuide; 					//圖片:操作指南畫面
		CMovingBitmap about;							//圖片:關於畫面
        int option;										//當前選項
        bool startGuide;								//是否開始操作指南
		bool startabout;								//是否開始關於畫面
		bool isplaysound;								//是否播放音效
};
/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
// 每個Member function的Implementation都要弄懂
/////////////////////////////////////////////////////////////////////////////
class CGameStateRun : public CGameState {
    public:
        CGameStateRun(CGame* g);
        ~CGameStateRun();
        void OnBeginState();							// 設定每次重玩所需的變數
        void OnInit();  								// 遊戲的初值及圖形設定
        void OnKeyDown(UINT, UINT, UINT);
        void OnKeyUp(UINT, UINT, UINT);
        void OnLButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
        void OnLButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作
        void OnMouseMove(UINT nFlags, CPoint point);	// 處理滑鼠的動作
        void OnRButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
        void OnRButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作
    protected:
        void OnMove();									// 移動遊戲元素
        void OnShow();									// 顯示這個狀態的遊戲畫面
		void PlayRockmanSound();
    private:
        Rockman x87_1;									//洛克人
        Terrain fireDragonMap;							//地圖:火龍
        CInteger  life;									//生命值
        RockCannon* _cannon;							//洛克人子彈的陣列
        Monster monster[8];								//垃圾怪
		Nightmare nightmare[6];							//夢魘
		Bat bat[6];										//蝙蝠
		Boss zero_fake;									//夢魘傑洛
		bool isplay[2] = { false };						//是否播放音效
		bool isplayboom;								//是否播放爆炸音效
		bool isplayBossStage = false;					//是否進入BOSS戰鬥
};
/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的結束狀態(Game Over)
// 每個Member function的Implementation都要弄懂
/////////////////////////////////////////////////////////////////////////////

class CGameStateOver : public CGameState {
    public:
        CGameStateOver(CGame* g);
        void OnBeginState();							// 設定每次重玩所需的變數
        void OnInit();
    protected:
        void OnMove();									// 移動遊戲元素
        void OnShow();									// 顯示這個狀態的遊戲畫面
    private:
        int counter;									// 倒數之計數器
		CMovingBitmap youdead;							// 圖片:你死了
		CMovingBitmap youwin;							// 圖片:你贏了
};																	 
}