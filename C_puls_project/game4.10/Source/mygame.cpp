#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mygame.h"
namespace game_framework {
/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲開頭畫面物件
/////////////////////////////////////////////////////////////////////////////
	bool isWin;
CGameStateInit::CGameStateInit(CGame* g)
    : CGameState(g)
{
}
void CGameStateInit::OnInit()
{
    gameStartBackground.LoadBitmap("RES\\gamestart\\gamestartUI background.bmp");
    gameStartBackground.SetTopLeft(0, 0);
    option1.LoadBitmap("RES\\gamestart\\option1.bmp", RGB(255, 255, 255));
    option2.LoadBitmap("RES\\gamestart\\option2.bmp", RGB(255, 255, 255));
    option3.LoadBitmap("RES\\gamestart\\option3.bmp", RGB(255, 255, 255));
    option4.LoadBitmap("RES\\gamestart\\option4.bmp", RGB(255, 255, 255));
    option1Select.LoadBitmap("RES\\gamestart\\option1select.bmp", RGB(255, 255, 255));
    option2Select.LoadBitmap("RES\\gamestart\\option2select.bmp", RGB(255, 255, 255));
    option3Select.LoadBitmap("RES\\gamestart\\option3select.bmp", RGB(255, 255, 255));
    option4Select.LoadBitmap("RES\\gamestart\\option4select.bmp", RGB(255, 255, 255));
    option1.SetTopLeft(771, 450);
    option2.SetTopLeft(771, 570);
    option3.SetTopLeft(771, 690);
    option4.SetTopLeft(771, 810);
    option1Select.SetTopLeft(771, 450);
    option2Select.SetTopLeft(771, 570);
    option3Select.SetTopLeft(771, 690);
    option4Select.SetTopLeft(771, 810);
    about.LoadBitmap("RES\\gamestart\\about.bmp");
    about.SetTopLeft(0, 0);
    controlGuide.LoadBitmap("RES\\gamestart\\background.bmp");
    controlGuide.SetTopLeft(0, 0);
    option = 1;
    CAudio::Instance()->Load(AUDIO_OPTIONMOVE, "sounds\\optionmove.wav");	// 載入編號0的聲音ding.wav
    CAudio::Instance()->Load(AUDIO_ENTER, "sounds\\enter.wav");	// 載入編號0的聲音ding.wav
    CAudio::Instance()->Load(AUDIO_START, "sounds\\gamestart.mp3");
    startGuide = false;
    isplaysound = true;
    // 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
    //     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
    ShowInitProgress(0);	// 一開始的loading進度為0%
    // 開始載入資料
    // 此OnInit動作會接到CGameStaterRun::OnInit()，所以進度還沒到100%
}
void CGameStateInit::OnBeginState()
{
}
void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    const char KEY_ESC = 27;
    const char KEY_SPACE = ' ';
    const char KEY_UP = 0x26;	// keyboard上箭頭
    const char KEY_DOWN = 0x28; // keyboard下箭頭
    const char KEY_ENTER = 0x0D;
    if (nChar == KEY_UP)
    {
        option--;
        if (option <= 0)
            option = 4;
        CAudio::Instance()->Play(AUDIO_OPTIONMOVE, false);
    }
    if (nChar == KEY_DOWN)
    {
        option++;
        if (option > 4)
            option = 1;
        CAudio::Instance()->Play(AUDIO_OPTIONMOVE, false);
    }
    if (startGuide == true)
        option = 2;
    if (startabout == true)
        option = 3;
    if (nChar == KEY_ENTER)
        CAudio::Instance()->Play(AUDIO_ENTER, false);
    if (nChar == KEY_ENTER && startGuide == true)
        startGuide = false;
    else if (nChar == KEY_ENTER && startabout == true)
        startabout = false;
    else if (nChar == KEY_ENTER && option == 1)
    {
        isplaysound = true;
        GotoGameState(GAME_STATE_RUN);					// 切換至GAME_STATE_RUN
    }
    else if (nChar == KEY_ENTER && option == 2)
        startGuide = true;
    else if (nChar == KEY_ENTER && option == 3)			// Demo 關閉遊戲的方法
        startabout = true;	// 關閉遊戲
    else if (nChar == KEY_ENTER && option == 4)			// Demo 關閉遊戲的方法
        PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// 關閉遊戲
}
void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
    //GotoGameState(GAME_STATE_RUN);		// 切換至GAME_STATE_RUN
}
void CGameStateInit::OnShow()
{
	if (isplaysound)
	{
		CAudio::Instance()->Play(AUDIO_START, true);
		isplaysound = false;
	}
    gameStartBackground.ShowBitmap();

    if (startGuide == true)
        controlGuide.ShowBitmap();
    else if (startabout == true)
        about.ShowBitmap();
    else if (option == 1)
    {
        option1Select.ShowBitmap();
        option2.ShowBitmap();
        option3.ShowBitmap();
        option4.ShowBitmap();
    }
    else if (option == 2)
    {
        option1.ShowBitmap();
        option2Select.ShowBitmap();
        option3.ShowBitmap();
        option4.ShowBitmap();
    }
    else if (option == 3)
    {
        option1.ShowBitmap();
        option2.ShowBitmap();
        option3Select.ShowBitmap();
        option4.ShowBitmap();
    }
    else if (option == 4)
    {
        option1.ShowBitmap();
        option2.ShowBitmap();
        option3.ShowBitmap();
        option4Select.ShowBitmap();
    }
}
/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的結束狀態(Game Over)
/////////////////////////////////////////////////////////////////////////////
CGameStateOver::CGameStateOver(CGame* g)
    : CGameState(g)
{
}
void CGameStateOver::OnMove()
{
    counter--;
    CAudio::Instance()->Stop(AUDIO_NTUT);
	CAudio::Instance()->Stop(AUDIO_BOSS_STAGE);
    CAudio::Instance()->Stop(AUDIO_CHARGE_LOOP);
    CAudio::Instance()->Stop(AUDIO_CHARGE);
    if (counter < 0)
        GotoGameState(GAME_STATE_INIT);
}
void CGameStateOver::OnBeginState()
{
    counter = 30 * 2; // 2 seconds
}
void CGameStateOver::OnInit()
{
    // 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
    //     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
	youdead.LoadBitmap("RES\\gamestart\\youdead.bmp", RGB(255, 255, 255));
	youdead.SetTopLeft(0, 0);
	youwin.LoadBitmap("RES\\gamestart\\win.bmp", RGB(255, 255, 255));
	youwin.SetTopLeft(0, 0);
    ShowInitProgress(66);	// 接個前一個狀態的進度，此處進度視為66%
    // 開始載入資料
    // 最終進度為100%
    ShowInitProgress(100);
}
void CGameStateOver::OnShow()
{
	if (isWin)
		youwin.ShowBitmap();
	else
		youdead.ShowBitmap();
}
/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////
CGameStateRun::CGameStateRun(CGame* g)
    : CGameState(g)
{
}
CGameStateRun::~CGameStateRun()
{
}
void CGameStateRun::OnBeginState()
{
    x87_1.Initialize();
    fireDragonMap.Initialize();
    life.SetInteger(x87_1.Getlife());
    life.SetTopLeft(149, 468);
    CAudio::Instance()->Play(AUDIO_NTUT, true);			// 撥放 MIDI
    CAudio::Instance()->Stop(AUDIO_START);
    isplayboom = false;
	isWin = false;
	isplayBossStage = false;
}
void CGameStateRun::OnMove()							// 移動遊戲元素
{
    int tmp;//洛克人座標修正值
    int fixCannonY = x87_1.GetY();
    int fixCannonX = x87_1.GetX();
    int left, right, top, down;
    _cannon = x87_1.getCannon();
    for (int i = 0; i < 20; i++)
    {
        int monster_x, monster_y, damage;
        for (int j = 0; j < 8; j++)
        {
            monster[j] = fireDragonMap.getMonster(j);
            monster_x = monster[j].getX();
            monster_y = monster[j].getY();
            if (_cannon[i].GetUsingState())
            {
                damage = _cannon[i].collision(monster_x, monster_y, monster[j].getAlive(), 1);
                if (monster[j].getAlive() == false)
                    damage = 0;
                if (fireDragonMap.getMonsterLife(j, 1) - damage <= 0 && fireDragonMap.getMonsterLife(j, 1) > 0)
                    isplayboom = true;
                fireDragonMap.setMonsterLife(j, damage, 1);
                if (damage > 0)
                {
                    _cannon[i].SetUsingState(0);
                    break;
                }
            }
        }
        for (int j = 0; j < 6; j++)
        {
            nightmare[j] = fireDragonMap.getNightmare(j);
            monster_x = nightmare[j].getX();
            monster_y = nightmare[j].getY();
            if (_cannon[i].GetUsingState())
            {
                damage = _cannon[i].collision(monster_x, monster_y, nightmare[j].getAlive(), 2);
                if (nightmare[j].getAlive() == false)
                    damage = 0;
                if (fireDragonMap.getMonsterLife(j, 2) - damage <= 0 && fireDragonMap.getMonsterLife(j, 2) > 0)
                    isplayboom = true;
                fireDragonMap.setMonsterLife(j, damage, 2);
                if (damage > 0)
                {
                    _cannon[i].SetUsingState(0);
                    break;
                }
            }
        }
        for (int j = 0; j < 6; j++)
        {
            bat[j] = fireDragonMap.getBat(j);
            monster_x = bat[j].getX();
            monster_y = bat[j].getY();
            if (_cannon[i].GetUsingState())
            {
                damage = _cannon[i].collision(monster_x, monster_y, bat[j].getAlive(), 3);
                if (bat[j].getAlive() == false)
                    damage = 0;
                if (fireDragonMap.getMonsterLife(j, 3) - damage <= 0 && fireDragonMap.getMonsterLife(j, 3) > 0)
                    isplayboom = true;
                fireDragonMap.setMonsterLife(j, damage, 3);
                if (damage > 0)
                {
                    _cannon[i].SetUsingState(0);
                    break;
                }
            }
        }
		zero_fake = fireDragonMap.getBoss();
		monster_x = zero_fake.getX();
		monster_y = zero_fake.getY();
		if (_cannon[i].GetUsingState())
		{
			damage = _cannon[i].collision(monster_x, monster_y, zero_fake.getAlive(), 4);
			if (zero_fake.getAlive() == false)
				damage = 0;
			fireDragonMap.setMonsterLife(0, damage, 4);
			if (damage > 0)
				_cannon[i].SetUsingState(0);
			if (fireDragonMap.IsBossDead())
				isplayboom = true;
		}
        _cannon[i].OnMove();
    }
    fireDragonMap.GetLastRockmanXY(x87_1.GetX(), x87_1.GetY());//取得移動之前座標
    int injureMC = fireDragonMap.MosterCannonCollision();
    if (fireDragonMap.MonsterCollision())
	{
		if(fireDragonMap.IsBossStage())
			x87_1.SetInjuredState(true, 4);
		else
			x87_1.SetInjuredState(true, 2);
	}
    else if (injureMC != 0)
    {
		if(!fireDragonMap.GetIsBossCannon())
			isplayboom = true;
        x87_1.SetInjuredState(true, injureMC);
    }
    x87_1.OnMove();
    fireDragonMap.GetNowRockmanXY(x87_1.GetX(), x87_1.GetY());//取得移動之後座標
    left = fireDragonMap.crashleft();
    right = fireDragonMap.crashright();
    top = fireDragonMap.crashtop();
    down = fireDragonMap.crashdown();
    if (left == -1 || right == -1 || top == -1 || down == -1) //碰到死亡地形，GAME OVER
    {
        life.Add(-64);
    }
    if (down != 0)//判斷是否站立於障礙物上
        x87_1.SetCrashState(1);
    else
        x87_1.SetCrashState(0);
    if (left != 0 && top == 0 && down == 0)
        x87_1.SetCrashStateWall(1);
    else if (right != 0 && top == 0 && down == 0)
        x87_1.SetCrashStateWall(2);
    else
        x87_1.SetCrashStateWall(0);
    if (top != 0 && down == 0)//上方碰撞到障礙物，Y座標還原
        x87_1.SetY(fireDragonMap.GetLastY());
    if (down != 0 && top == 0)//下方碰撞到障礙物，Y座標修正至障礙物上方
    {
        tmp = down - fireDragonMap.GetLastY();
        x87_1.SetY(fireDragonMap.GetLastY() + tmp - 200);
        fireDragonMap.GetNowRockmanXY(x87_1.GetX(), x87_1.GetY());//刷新洛克人座標
    }
    //卡牆BUG修正
    else if (right != 0 && left != 0 && top != 0 && down != 0)
    {
        tmp = down - fireDragonMap.GetLastY();
        x87_1.SetY(fireDragonMap.GetLastY() + tmp - 200);
        fireDragonMap.GetNowRockmanXY(x87_1.GetX(), x87_1.GetY());
    }
    if (fireDragonMap.crashright() != 0)//右方碰撞到障礙物，X座標還原
    {
        x87_1.SetX(fireDragonMap.GetLastX());
    }

    if (fireDragonMap.crashleft() != 0)//左方碰撞到障礙物，X座標還原
    {
        x87_1.SetX(fireDragonMap.GetLastX());
    }
    fireDragonMap.GetNowRockmanXY(x87_1.GetX(), x87_1.GetY());
    fireDragonMap.MoveScreen();
    fixCannonY -= x87_1.GetY();
    fixCannonX -= x87_1.GetX();
    x87_1.SetFixCannonScreen(fixCannonY, fixCannonX);
    if (life.GetInteger() <= 0)//血量歸0，GAME OVER
        GotoGameState(GAME_STATE_OVER);
	else if(fireDragonMap.IsBossDead())
	{
		isWin = true;
		GotoGameState(GAME_STATE_OVER);
	}
    life.SetInteger(x87_1.Getlife());
    PlayRockmanSound();
}
void CGameStateRun::PlayRockmanSound()
{
	if (fireDragonMap.IsBossDead() && isplayboom)
		CAudio::Instance()->Play(25, false);
    if (isplayboom)
    {
        CAudio::Instance()->Play(AUDIO_BOOM, false);
        isplayboom = false;
    }
    if (x87_1.GetJumpDegree() == 1 && x87_1.GetJumping())
    {
        CAudio::Instance()->Play(AUDIO_JUMP, false);
        CAudio::Instance()->Play(AUDIO_JUMP2, false);
    }
    if (x87_1.GetSprintDegree() == 1)
        CAudio::Instance()->Play(AUDIO_SPRINT, false);
    if (x87_1.getInjuredDelay() == 1)
        CAudio::Instance()->Play(AUDIO_INJURE, false);
    if (x87_1.GetChargeAttack() > 0)
    {
        CAudio::Instance()->Stop(AUDIO_CHARGE_LOOP);
        CAudio::Instance()->Stop(AUDIO_CHARGE);
    }
    if (x87_1.GetCharge() == 6)
        CAudio::Instance()->Play(AUDIO_CHARGE, false);
    if (x87_1.GetCharge() == 50)
        CAudio::Instance()->Play(AUDIO_CHARGE_LOOP, true);
    if (x87_1.GetChargeAttack() == 0)
    {
        for (int i = 0; i < 2; i++)
            isplay[i] = false;
    }
    if (x87_1.GetIsAttacking() && x87_1.GetDetermineCharge() == 1)
        CAudio::Instance()->Play(AUDIO_CANNON1, false);
    if (x87_1.GetChargeAttack() > 5 && x87_1.GetChargeAttack() <= 50 && !isplay[0])
    {
        CAudio::Instance()->Play(AUDIO_CANNON2, false);
        isplay[0] = true;
    }
    if (x87_1.GetChargeAttack() > 50 && !isplay[1])
    {
        CAudio::Instance()->Play(AUDIO_CANNON3, false);
        CAudio::Instance()->Play(AUDIO_CANNON3_2, false);
        isplay[1] = true;
    }
	if(fireDragonMap.IsBossStage()&& !isplayBossStage)
	{
		CAudio::Instance()->Stop(AUDIO_NTUT);
		CAudio::Instance()->Play(AUDIO_BOSS_STAGE, true);
		isplayBossStage = true;
	}
}
void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
    // 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
    //     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
    ShowInitProgress(33);	// 接個前一個狀態的進度，此處進度視為33%
    // 開始載入資料
    // 完成部分Loading動作，提高進度
    ShowInitProgress(50);
    // 繼續載入其他資料
    x87_1.LoadBitmap();
    x87_1.LoadAttackBitmap();
    fireDragonMap.LoadBitMap();
    life.LoadBitmap();
    CAudio::Instance()->Load(AUDIO_NTUT,  "sounds\\Jakob.wav");
    CAudio::Instance()->Load(AUDIO_JUMP, "sounds\\jump.wav");
    CAudio::Instance()->Load(AUDIO_JUMP2, "sounds\\jump2.wav");
    CAudio::Instance()->Load(AUDIO_SPRINT, "sounds\\sprint.wav");
    CAudio::Instance()->Load(AUDIO_INJURE, "sounds\\injure.wav");
    CAudio::Instance()->Load(AUDIO_CANNON1, "sounds\\cannon1.wav");
    CAudio::Instance()->Load(AUDIO_CANNON2, "sounds\\cannon2.wav");
    CAudio::Instance()->Load(AUDIO_CANNON3, "sounds\\cannon3.wav");
    CAudio::Instance()->Load(AUDIO_CANNON3_2, "sounds\\cannon3-2.wav");
    CAudio::Instance()->Load(AUDIO_CHARGE, "sounds\\charge.wav");
    CAudio::Instance()->Load(AUDIO_CHARGE_LOOP, "sounds\\charge-loop.wav");
    CAudio::Instance()->Load(AUDIO_BOOM, "sounds\\boom.wav");
    CAudio::Instance()->Load(AUDIO_ENEMY_FIRE, "sounds\\enemyfire.wav");
	CAudio::Instance()->Load(AUDIO_BOSS_STAGE, "sounds\\boss_stage.mp3");
	CAudio::Instance()->Load(AUDIO_BOSS_SPRINT, "sounds\\boss\\bossSprint.wav");
	CAudio::Instance()->Load(AUDIO_BOSS_SPRINT_2, "sounds\\boss\\sprint_zero.wav");
	CAudio::Instance()->Load(AUDIO_BOSS_FIRE, "sounds\\boss\\fire.wav");
	CAudio::Instance()->Load(AUDIO_BOSS_CHOP, "sounds\\boss\\chop.wav");
	CAudio::Instance()->Load(AUDIO_BOSS_DES, "sounds\\boss\\destroylight.wav");
	CAudio::Instance()->Load(AUDIO_BOSS_DES_2, "sounds\\boss\\destroylight_zero.wav");
	CAudio::Instance()->Load(AUDIO_BOSS_KILL, "sounds\\boss\\kill.wav");
	CAudio::Instance()->Load(AUDIO_BOSS_KILL_2, "sounds\\boss\\kill_zero.wav");
	CAudio::Instance()->Load(AUDIO_BOSS_DEAD, "sounds\\boss\\dead_zero.wav");
    //
    // 此OnInit動作會接到CGameStaterOver::OnInit()，所以進度還沒到100%
    //
}
//----------------------------------------------------------------------
void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    const char KEY_LEFT  = 0x25;  // keyboard左箭頭
    const char KEY_UP    = 0x26;  // keyboard上箭頭
    const char KEY_RIGHT = 0x27;  // keyboard右箭頭
    const char KEY_DOWN  = 0x28;  // keyboard下箭頭
    const char KEY_JUMP  = 0x5A;  // keyboard按鍵Z
    const char KEY_SPRINT = 0x20; // keyboard空白鍵
    const char KEY_ATTACK = 0x58; // keyboard按鍵X
    const char KEY_CHEAT = 0x43;  // keyboard按鍵C
    if (nChar == KEY_LEFT)
        x87_1.SetMovingLeft(true);
    if (nChar == KEY_RIGHT)
        x87_1.SetMovingRight(true);
    if ((nChar == KEY_JUMP) && (x87_1.GetJumpDegree() == 0))
        x87_1.SetJumping(true);
    if ((nChar == KEY_SPRINT) && (x87_1.GetSprintDegree() == 0))
        x87_1.SetSprinting(true);
    if (nChar == KEY_SPRINT)
        x87_1.SetKeySprintState(true);
    if ((nChar == KEY_ATTACK) && (x87_1.GetCharge() == 0))
        x87_1.SetAttacking(true);
    else
        x87_1.SetAttacking(false);
    if (nChar == KEY_ATTACK)
        x87_1.SetKeyAttackingState(true);
    if (nChar == KEY_CHEAT)
    {
        x87_1.SetLife(64);
        fireDragonMap.setLifeToZero();
    }
}
void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    const char KEY_LEFT  = 0x25; // keyboard左箭頭
    const char KEY_UP    = 0x26; // keyboard上箭頭
    const char KEY_RIGHT = 0x27; // keyboard右箭頭
    const char KEY_DOWN  = 0x28; // keyboard下箭頭
    const char KEY_JUMP  = 0x5A; // keyboard按鍵Z
    const char KEY_SPRINT = 0x20; // keyboard空白鍵
    const char KEY_ATTACK = 0x58; // keyboard按鍵X
    if (nChar == KEY_LEFT)
        x87_1.SetMovingLeft(false);
    if (nChar == KEY_RIGHT)
        x87_1.SetMovingRight(false);
    if ((nChar == KEY_JUMP) && (x87_1.GetJumpDegree() > 0))
        x87_1.SetJumping(false);
    if ((nChar == KEY_SPRINT) && (x87_1.GetSprintDegree() > 0))
        x87_1.SetSprinting(false);
    if (nChar == KEY_SPRINT)
        x87_1.SetKeySprintState(false);
    if (nChar == KEY_ATTACK)
        x87_1.SetAttacking(false);
    if (nChar == KEY_ATTACK)
        x87_1.SetKeyAttackingState(false);
}
//-------------------------------------------------------------------
void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}
void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}
void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
    // 沒事。如果需要處理滑鼠移動的話，寫code在這裡
}
void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}
void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}
void CGameStateRun::OnShow()
{
    //
    //  注意：Show裡面千萬不要移動任何物件的座標，移動座標的工作應由Move做才對，
    //        否則當視窗重新繪圖時(OnDraw)，物件就會移動，看起來會很怪。換個術語
    //        說，Move負責MVC中的Model，Show負責View，而View不應更動Model。
    //
    //  貼上背景圖、撞擊數、球、擦子、彈跳的球
    //
    fireDragonMap.OnShow();
    x87_1.OnShow();
    life.ShowBitmap();
}
}