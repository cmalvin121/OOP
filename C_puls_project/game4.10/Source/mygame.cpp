/*
 * mygame.cpp: ���ɮ��x�C��������class��implementation
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
// �o��class���C�����C���}�Y�e������
/////////////////////////////////////////////////////////////////////////////

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
	option1Select.LoadBitmap("RES\\gamestart\\option1select.bmp", RGB(255, 255, 255));
	option2Select.LoadBitmap("RES\\gamestart\\option2select.bmp", RGB(255, 255, 255));
	option3Select.LoadBitmap("RES\\gamestart\\option3select.bmp", RGB(255, 255, 255));
	option1.SetTopLeft(660, 450);
	option2.SetTopLeft(660, 600);
	option3.SetTopLeft(660, 750);
	option1Select.SetTopLeft(660, 450);
	option2Select.SetTopLeft(660, 600);
	option3Select.SetTopLeft(660, 750);
	controlGuide.LoadBitmap("RES\\gamestart\\background.bmp");
	controlGuide.SetTopLeft(0, 0);
	text1.LoadBitmap("RES\\gamestart\\right.bmp", RGB(255, 255, 255));
	text2.LoadBitmap("RES\\gamestart\\left.bmp", RGB(255, 255, 255));
	text3.LoadBitmap("RES\\gamestart\\jump.bmp", RGB(255, 255, 255));
	text4.LoadBitmap("RES\\gamestart\\attack.bmp", RGB(255, 255, 255));
	text5.LoadBitmap("RES\\gamestart\\sprint.bmp", RGB(255, 255, 255));
	text6.LoadBitmap("RES\\gamestart\\wall.bmp", RGB(255, 255, 255));
	text1.SetTopLeft(573, 62);
	text2.SetTopLeft(573, 212);
	text3.SetTopLeft(573, 362);
	text4.SetTopLeft(573, 512);
	text5.SetTopLeft(689, 662);
	text6.SetTopLeft(750, 814);
	option = 1;
	startGuide = false;
    //
    // ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
    //     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
    //
    ShowInitProgress(0);	// �@�}�l��loading�i�׬�0%
    //
    // �}�l���J���
    //
    Sleep(300);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
    //
    // ��OnInit�ʧ@�|����CGameStaterRun::OnInit()�A�ҥH�i���٨S��100%
    //
}

void CGameStateInit::OnBeginState()
{
}

void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    const char KEY_ESC = 27;
    const char KEY_SPACE = ' ';
	const char KEY_UP = 0x26; // keyboard�W�b�Y
	const char KEY_DOWN = 0x28; // keyboard�U�b�Y
	const char KEY_ENTER = 0x0D;
	if (nChar == KEY_UP)
	{
		option--;
		if (option <= 0)
			option = 3;
	}
	if (nChar == KEY_DOWN)
	{
		option++;
		if (option > 3)
			option = 1;
	}
	if (startGuide == true)
		option = 2;
	if (nChar == KEY_ENTER && startGuide == true)
		startGuide = false;
	else if (nChar == KEY_ENTER && option == 1)
		GotoGameState(GAME_STATE_RUN);						// ������GAME_STATE_RUN
	else if (nChar == KEY_ENTER && option == 2)
		startGuide = true;
	else if (nChar == KEY_ENTER && option == 3)			// Demo �����C������k
        PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// �����C��

}
void CGameStateInit::GotoGuide()
{
	controlGuide.ShowBitmap();
	text1.ShowBitmap();
	text2.ShowBitmap();
	text3.ShowBitmap();
	text4.ShowBitmap();
	text5.ShowBitmap();
	text6.ShowBitmap();
}

void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
{
    //GotoGameState(GAME_STATE_RUN);		// ������GAME_STATE_RUN
}

void CGameStateInit::OnShow()
{
    //
    //
    // Demo�ù��r�����ϥΡA���L�}�o�ɽкɶq�קK�����ϥΦr���A���CMovingBitmap����n
    //
	gameStartBackground.ShowBitmap();
	if (startGuide == true)
		GotoGuide();
	else if (option == 1)
	{
		option1Select.ShowBitmap();
		option2.ShowBitmap();
		option3.ShowBitmap();
	}
	else if (option == 2)
	{
		option1.ShowBitmap();
		option2Select.ShowBitmap();
		option3.ShowBitmap();
	}
	else if (option == 3)
	{
		option1.ShowBitmap();
		option2.ShowBitmap();
		option3Select.ShowBitmap();
	}
}

/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����������A(Game Over)
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
    // ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
    //     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
    //
    ShowInitProgress(66);	// ���ӫe�@�Ӫ��A���i�סA���B�i�׵���66%
    //
    // �}�l���J���
    //
    Sleep(300);				// ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
    //
    // �̲׶i�׬�100%
    //
    ShowInitProgress(100);
}

void CGameStateOver::OnShow()
{
    CDC* pDC = CDDraw::GetBackCDC();			// ���o Back Plain �� CDC
    CFont f, *fp;
    f.CreatePointFont(160, "Times New Roman");	// ���� font f; 160���16 point���r
    fp = pDC->SelectObject(&f);					// ��� font f
    pDC->SetBkColor(RGB(0, 0, 0));
    pDC->SetTextColor(RGB(255, 255, 0));
    char str[80];								// Demo �Ʀr��r�ꪺ�ഫ
    sprintf(str, "Game Over ! (%d)", counter / 30);
    pDC->TextOut(240, 210, str);
    pDC->SelectObject(fp);						// �� font f (�d�U���n�|�F��)
    CDDraw::ReleaseBackCDC();					// �� Back Plain �� CDC
}

/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
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
    const int HITS_LEFT = 10;				//�ͩR��
    x87_1.Initialize();
    fireDragonMap.Initialize();
    life.SetInteger(x87_1.Getlife());
    life.SetTopLeft(149, 468);
    CAudio::Instance()->Play(AUDIO_LAKE, true);			// ���� WAVE
    CAudio::Instance()->Play(AUDIO_DING, false);		// ���� WAVE
    CAudio::Instance()->Play(AUDIO_NTUT, true);			// ���� MIDI
}

void CGameStateRun::OnMove()							// ���ʹC������
{
    int tmp;//���J�H�y�Эץ���
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
                damage = _cannon[i].collision(monster_x, monster_y, monster[j].getAlive(),1);
                if (monster[j].getAlive() == false)
                    damage = 0;
                fireDragonMap.setMonsterLife(j, damage,1);
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
				fireDragonMap.setMonsterLife(j, damage,2);
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
				fireDragonMap.setMonsterLife(j, damage, 3);
				if (damage > 0)
				{
					_cannon[i].SetUsingState(0);
					break;
				}
			}
		}
        _cannon[i].OnMove();
    }

    fireDragonMap.GetLastRockmanXY(x87_1.GetX(), x87_1.GetY());//���o���ʤ��e�y��
	int injureMC = fireDragonMap.MosterCannonCollision();
	if(fireDragonMap.MonsterCollision())
		x87_1.SetInjuredState(true, 2);
	else if(injureMC != 0)
		x87_1.SetInjuredState(true, injureMC);
    x87_1.OnMove();
    fireDragonMap.GetNowRockmanXY(x87_1.GetX(), x87_1.GetY());//���o���ʤ���y��
    left = fireDragonMap.crashleft();
    right = fireDragonMap.crashright();
    top = fireDragonMap.crashtop();
    down = fireDragonMap.crashdown();

    if (left == -1 || right == -1 || top == -1 || down == -1) //�I�즺�`�a�ΡAGAME OVER
    {
        life.Add(-64);
    }

    if (down != 0)//�P�_�O�_���ߩ��ê���W
        x87_1.SetCrashState(1);
    else
        x87_1.SetCrashState(0);

    if (left != 0 && top == 0 && down == 0)
        x87_1.SetCrashStateWall(1);
    else if (right != 0 && top == 0 && down == 0)
        x87_1.SetCrashStateWall(2);
    else
        x87_1.SetCrashStateWall(0);

    if (top != 0 && down == 0)//�W��I�����ê���AY�y���٭�
        x87_1.SetY(fireDragonMap.GetLastY());

    if (down != 0 && top == 0)//�U��I�����ê���AY�y�Эץ��ܻ�ê���W��
    {
        tmp = down - fireDragonMap.GetLastY();
        //TRACE("tmp:%d\n", tmp);
        x87_1.SetY(fireDragonMap.GetLastY() + tmp - 200);
        fireDragonMap.GetNowRockmanXY(x87_1.GetX(), x87_1.GetY());//��s���J�H�y��
    }
    //�d��BUG�ץ�
    else if (right != 0 && left != 0 && top != 0 && down != 0)
    {
        tmp = down - fireDragonMap.GetLastY();
        //TRACE("tmp:%d\n", tmp);
        x87_1.SetY(fireDragonMap.GetLastY() + tmp - 200);
        fireDragonMap.GetNowRockmanXY(x87_1.GetX(), x87_1.GetY());
    }

    if (fireDragonMap.crashright() != 0)//�k��I�����ê���AX�y���٭�
    {
        x87_1.SetX(fireDragonMap.GetLastX());
    }

    if (fireDragonMap.crashleft() != 0)//����I�����ê���AX�y���٭�
    {
        x87_1.SetX(fireDragonMap.GetLastX());
    }

    //TRACE("%d %d %d %d\n", (x87_1.GetY()) / 80, x87_1.GetX() / 80, x87_1.GetY(), x87_1.GetX());
    fireDragonMap.GetNowRockmanXY(x87_1.GetX(), x87_1.GetY());
    fireDragonMap.MoveScreen();
    fixCannonY -= x87_1.GetY();
    fixCannonX -= x87_1.GetX();
    x87_1.SetFixCannonScreen(fixCannonY, fixCannonX);

    if (life.GetInteger() <= 0)//��q�k0�AGAME OVER
        GotoGameState(GAME_STATE_OVER);

    life.SetInteger(x87_1.Getlife());
}

void CGameStateRun::OnInit()  								// �C������Ȥιϧγ]�w
{
    //
    // ��ϫܦh�ɡAOnInit���J�Ҧ����ϭn��ܦh�ɶ��C���קK���C�����H
    //     �������@�СA�C���|�X�{�uLoading ...�v�A���Loading���i�סC
    //
    ShowInitProgress(33);	// ���ӫe�@�Ӫ��A���i�סA���B�i�׵���33%
    //
    // �}�l���J���
    //
    //
    // ��������Loading�ʧ@�A�����i��
    //
    ShowInitProgress(50);
    Sleep(300); // ��C�A�H�K�ݲM���i�סA��ڹC���ЧR����Sleep
    //
    // �~����J��L���
    //
    x87_1.LoadBitmap();
    x87_1.LoadAttackBitmap();
    fireDragonMap.LoadBitMap();
    life.LoadBitmap();
    CAudio::Instance()->Load(AUDIO_DING,  "sounds\\ding.wav");	// ���J�s��0���n��ding.wav
    CAudio::Instance()->Load(AUDIO_LAKE,  "sounds\\lake.mp3");	// ���J�s��1���n��lake.mp3
    CAudio::Instance()->Load(AUDIO_NTUT,  "sounds\\Jakob.wav");	// ���J�s��2���n��ntut.mid
    //
    // ��OnInit�ʧ@�|����CGameStaterOver::OnInit()�A�ҥH�i���٨S��100%
    //
}
//----------------------------------------------------------------------
void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    const char KEY_LEFT  = 0x25; // keyboard���b�Y
    const char KEY_UP    = 0x26; // keyboard�W�b�Y
    const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
    const char KEY_DOWN  = 0x28; // keyboard�U�b�Y
    const char KEY_JUMP  = 0x5A; // keyboard����Z
    const char KEY_SPRINT = 0x20; // keyboard�ť���
    const char KEY_ATTACK = 0x58; // keyboard����X

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
    const char KEY_LEFT  = 0x25; // keyboard���b�Y
    const char KEY_UP    = 0x26; // keyboard�W�b�Y
    const char KEY_RIGHT = 0x27; // keyboard�k�b�Y
    const char KEY_DOWN  = 0x28; // keyboard�U�b�Y
    const char KEY_JUMP  = 0x5A; // keyboard����Z
    const char KEY_SPRINT = 0x20; // keyboard�ť���
    const char KEY_ATTACK = 0x58; // keyboard����X

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
void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
{
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
    // �S�ơC�p�G�ݭn�B�z�ƹ����ʪ��ܡA�gcode�b�o��
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // �B�z�ƹ����ʧ@
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// �B�z�ƹ����ʧ@
{
}

void CGameStateRun::OnShow()
{
    //
    //  �`�N�GShow�̭��d�U���n���ʥ��󪫥󪺮y�СA���ʮy�Ъ��u�@����Move���~��A
    //        �_�h��������sø�Ϯ�(OnDraw)�A����N�|���ʡA�ݰ_�ӷ|�ܩǡC���ӳN�y
    //        ���AMove�t�dMVC����Model�AShow�t�dView�A��View�������Model�C
    //
    //  �K�W�I���ϡB�����ơB�y�B���l�B�u�����y
    //
    fireDragonMap.OnShow();
    //
    //  �K�W���W�Υk�U��������
    //
    x87_1.OnShow();
    life.ShowBitmap();
}
}