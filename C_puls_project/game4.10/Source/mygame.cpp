/*
 * mygame.cpp: 本檔案儲遊戲本身的class的implementation
 * Copyright (C) 2002-2008 Woei-Kae Chen <wkc@csie.ntut.edu.tw>
 *
 * This file is part of game, a free game development framework for windows.
 *
 * game is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * game is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * History:
 *   2002-03-04 V3.1
 *          Add codes to demostrate the use of CMovingBitmap::ShowBitmap(CMovingBitmap &).
 *	 2004-03-02 V4.0
 *      1. Add CGameStateInit, CGameStateRun, and CGameStateOver to
 *         demonstrate the use of states.
 *      2. Demo the use of CInteger in CGameStateRun.
 *   2005-09-13
 *      Rewrite the codes for CBall and CEraser.
 *   2005-09-20 V4.2Beta1.
 *   2005-09-29 V4.2Beta2.
 *      1. Add codes to display IDC_GAMECURSOR in GameStateRun.
 *   2006-02-08 V4.2
 *      1. Revise sample screens to display in English only.
 *      2. Add code in CGameStateInit to demo the use of PostQuitMessage().
 *      3. Rename OnInitialUpdate() -> OnInit().
 *      4. Fix the bug that OnBeginState() of GameStateInit is not called.
 *      5. Replace AUDIO_CANYON as AUDIO_NTUT.
 *      6. Add help bitmap to CGameStateRun.
 *   2006-09-09 V4.3
 *      1. Rename Move() and Show() as OnMove and OnShow() to emphasize that they are
 *         event driven.
 *   2006-12-30
 *      1. Bug fix: fix a memory leak problem by replacing PostQuitMessage(0) as
 *         PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE,0,0).
 *   2008-02-15 V4.4
 *      1. Add namespace game_framework.
 *      2. Replace the demonstration of animation as a new bouncing ball.
 *      3. Use ShowInitProgress(percent) to display loading progress.
 *   2010-03-23 V4.6
 *      1. Demo MP3 support: use lake.mp3 to replace lake.wav.
*/

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

CGameStateInit::CGameStateInit(CGame* g)
    : CGameState(g)
{
}

void CGameStateInit::OnInit()
{
    //
    // 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
    //     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
    //
    ShowInitProgress(0);	// 一開始的loading進度為0%
    //
    // 開始載入資料
    //
    Sleep(300);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
    //
    // 此OnInit動作會接到CGameStaterRun::OnInit()，所以進度還沒到100%
    //
}

void CGameStateInit::OnBeginState()
{
}

void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    const char KEY_ESC = 27;
    const char KEY_SPACE = ' ';

    if (nChar == KEY_SPACE)
        GotoGameState(GAME_STATE_RUN);						// 切換至GAME_STATE_RUN
    else if (nChar == KEY_ESC)								// Demo 關閉遊戲的方法
        PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// 關閉遊戲
}

void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
    GotoGameState(GAME_STATE_RUN);		// 切換至GAME_STATE_RUN
}

void CGameStateInit::OnShow()
{
    //
    //
    // Demo螢幕字型的使用，不過開發時請盡量避免直接使用字型，改用CMovingBitmap比較好
    //
    CDC* pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC
    CFont f, *fp;
    f.CreatePointFont(160, "Times New Roman");	// 產生 font f; 160表示16 point的字
    fp = pDC->SelectObject(&f);					// 選用 font f
    pDC->SetBkColor(RGB(0, 0, 0));
    pDC->SetTextColor(RGB(255, 255, 0));
    pDC->TextOut(120, 220, "Please click mouse or press SPACE to begin.");
    pDC->TextOut(5, 395, "Press Ctrl-F to switch in between window mode and full screen mode.");

    if (ENABLE_GAME_PAUSE)
        pDC->TextOut(5, 425, "Press Ctrl-Q to pause the Game.");

    pDC->TextOut(5, 455, "Press Alt-F4 or ESC to Quit.");
    pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
    CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
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

    if (counter < 0)
        GotoGameState(GAME_STATE_INIT);
}

void CGameStateOver::OnBeginState()
{
    counter = 30 * 5; // 5 seconds
}

void CGameStateOver::OnInit()
{
    //
    // 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
    //     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
    //
    ShowInitProgress(66);	// 接個前一個狀態的進度，此處進度視為66%
    //
    // 開始載入資料
    //
    Sleep(300);				// 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
    //
    // 最終進度為100%
    //
    ShowInitProgress(100);
}

void CGameStateOver::OnShow()
{
    CDC* pDC = CDDraw::GetBackCDC();			// 取得 Back Plain 的 CDC
    CFont f, *fp;
    f.CreatePointFont(160, "Times New Roman");	// 產生 font f; 160表示16 point的字
    fp = pDC->SelectObject(&f);					// 選用 font f
    pDC->SetBkColor(RGB(0, 0, 0));
    pDC->SetTextColor(RGB(255, 255, 0));
    char str[80];								// Demo 數字對字串的轉換
    sprintf(str, "Game Over ! (%d)", counter / 30);
    pDC->TextOut(240, 210, str);
    pDC->SelectObject(fp);						// 放掉 font f (千萬不要漏了放掉)
    CDDraw::ReleaseBackCDC();					// 放掉 Back Plain 的 CDC
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
    const int ANIMATION_SPEED = 15;
    const int HITS_LEFT = 10;				//生命值
    x87_1.Initialize();
    fireDragonMap.Initialize();
    life.SetInteger(HITS_LEFT);
    life.SetTopLeft(30, 30);
    help.SetTopLeft(0, SIZE_Y - help.Height());			// 設定說明圖的起始座標
    CAudio::Instance()->Play(AUDIO_LAKE, true);			// 撥放 WAVE
    CAudio::Instance()->Play(AUDIO_DING, false);		// 撥放 WAVE
    CAudio::Instance()->Play(AUDIO_NTUT, true);			// 撥放 MIDI
}

void CGameStateRun::OnMove()							// 移動遊戲元素
{
    int tmp;//洛克人座標修正值
    int left, right, top, down;
    _cannon = x87_1.getCannon();

    for (int i = 0; i < 20; i++)
        _cannon[i].OnMove();

    fireDragonMap.GetLastRockmanXY(x87_1.GetX(), x87_1.GetY());//取得移動之前座標
    x87_1.OnMove();
    fireDragonMap.GetNowRockmanXY(x87_1.GetX(), x87_1.GetY());//取得移動之後座標
    left = fireDragonMap.crashleft();
    right = fireDragonMap.crashright();
    top = fireDragonMap.crashtop();
    down = fireDragonMap.crashdown();

    if (left == -1 || right == -1 || top == -1 || down == -1) //碰到死亡地形，GAME OVER
        life.Add(-10);

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
        //TRACE("tmp:%d\n", tmp);
        x87_1.SetY(fireDragonMap.GetLastY() + tmp - 200);
        fireDragonMap.GetNowRockmanXY(x87_1.GetX(), x87_1.GetY());//刷新洛克人座標
    }
    //卡牆BUG修正
    else if (right != 0 && left != 0 && top != 0 && down != 0)
    {
        tmp = down - fireDragonMap.GetLastY();
        //TRACE("tmp:%d\n", tmp);
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

    //TRACE("%d %d %d %d\n", (x87_1.GetY()) / 80, x87_1.GetX() / 80, x87_1.GetY(), x87_1.GetX());
    fireDragonMap.GetNowRockmanXY(x87_1.GetX(), x87_1.GetY());
    fireDragonMap.MoveScreen();

    if (x87_1.getInjuredState())//碰到怪物，生命-1
        life.Add(-1);

    if (life.GetInteger() <= 0)//血量歸0，GAME OVER
        GotoGameState(GAME_STATE_OVER);
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
    //
    // 當圖很多時，OnInit載入所有的圖要花很多時間。為避免玩遊戲的人
    //     等的不耐煩，遊戲會出現「Loading ...」，顯示Loading的進度。
    //
    ShowInitProgress(33);	// 接個前一個狀態的進度，此處進度視為33%
    //
    // 開始載入資料
    //
    //
    // 完成部分Loading動作，提高進度
    //
    ShowInitProgress(50);
    Sleep(300); // 放慢，以便看清楚進度，實際遊戲請刪除此Sleep
    //
    // 繼續載入其他資料
    //
    help.LoadBitmap(IDB_HELP, RGB(255, 255, 255));				// 載入說明的圖形
    corner.LoadBitmap(IDB_CORNER);							// 載入角落圖形
    x87_1.LoadBitmap();
    x87_1.LoadAttackBitmap();
    fireDragonMap.LoadBitMap();
    life.LoadBitmap();
    CAudio::Instance()->Load(AUDIO_DING,  "sounds\\ding.wav");	// 載入編號0的聲音ding.wav
    CAudio::Instance()->Load(AUDIO_LAKE,  "sounds\\lake.mp3");	// 載入編號1的聲音lake.mp3
    CAudio::Instance()->Load(AUDIO_NTUT,  "sounds\\Jakob.wav");	// 載入編號2的聲音ntut.mid
    //
    // 此OnInit動作會接到CGameStaterOver::OnInit()，所以進度還沒到100%
    //
}
//----------------------------------------------------------------------
void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    const char KEY_LEFT  = 0x25; // keyboard左箭頭
    const char KEY_UP    = 0x26; // keyboard上箭頭
    const char KEY_RIGHT = 0x27; // keyboard右箭頭
    const char KEY_DOWN  = 0x28; // keyboard下箭頭
    const char KEY_JUMP  = 0x5A; // keyboard按鍵Z
    const char KEY_SPRINT = 0x20; // keyboard空白鍵
    const char KEY_ATTACK = 0x58; // keyboard按鍵X

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
    //
    //  貼上背景圖、撞擊數、球、擦子、彈跳的球
    //
    help.ShowBitmap();					// 貼上說明圖
    fireDragonMap.OnShow();
    //
    //  貼上左上及右下角落的圖
    //
    corner.SetTopLeft(0, 0);
    corner.ShowBitmap();
    corner.SetTopLeft(SIZE_X - corner.Width(), SIZE_Y - corner.Height());
    corner.ShowBitmap();
    x87_1.OnShow();
    life.ShowBitmap();
}
}