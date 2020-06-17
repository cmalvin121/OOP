/*
 * mygame.h: ���ɮ��x�C��������class��interface
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
 *	 2004-03-02 V4.0
 *      1. Add CGameStateInit, CGameStateRun, and CGameStateOver to
 *         demonstrate the use of states.
 *   2005-09-13
 *      Rewrite the codes for CBall and CEraser.
 *   2005-09-20 V4.2Beta1.
 *   2005-09-29 V4.2Beta2.
 *   2006-02-08 V4.2
 *      1. Rename OnInitialUpdate() -> OnInit().
 *      2. Replace AUDIO_CANYON as AUDIO_NTUT.
 *      3. Add help bitmap to CGameStateRun.
 *   2006-09-09 V4.3
 *      1. Rename Move() and Show() as OnMove and OnShow() to emphasize that they are
 *         event driven.
 *   2008-02-15 V4.4
 *      1. Add namespace game_framework.
 *      2. Replace the demonstration of animation as a new bouncing ball.
 *      3. Use ShowInitProgress(percent) to display loading progress.
*/
//
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
#include "CEraser.h"
#include "CBall.h"
#include "CBouncingBall.h"

namespace game_framework {
/////////////////////////////////////////////////////////////////////////////
// Constants
/////////////////////////////////////////////////////////////////////////////

enum AUDIO_ID {				// �w�q�U�ح��Ī��s��
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
	AUDIO_ENEMY_FIRE		// 15
};

/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����C���}�Y�e������
// �C��Member function��Implementation���n����
/////////////////////////////////////////////////////////////////////////////
class CGameStateInit : public CGameState {
    public:
        CGameStateInit(CGame* g);
        void OnInit();  								// �C������Ȥιϧγ]�w
        void OnBeginState();							// �]�w�C�������һݪ��ܼ�
        void OnKeyUp(UINT, UINT, UINT); 				// �B�z��LUp���ʧ@
        void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
    protected:
        void OnShow();									// ��ܳo�Ӫ��A���C���e��
    private:
        CMovingBitmap logo;								// csie��logo
        CMovingBitmap gameStartBackground;
        CMovingBitmap option1;
        CMovingBitmap option2;
        CMovingBitmap option3;
		CMovingBitmap option4;
        CMovingBitmap option1Select;
        CMovingBitmap option2Select;
        CMovingBitmap option3Select;
		CMovingBitmap option4Select;
        CMovingBitmap controlGuide;
		CMovingBitmap about;
        int option;
        bool startGuide;
		bool startabout;
		bool isplaysound;
};

/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
// �C��Member function��Implementation���n����
/////////////////////////////////////////////////////////////////////////////

class CGameStateRun : public CGameState {
    public:
        CGameStateRun(CGame* g);
        ~CGameStateRun();
        void OnBeginState();							// �]�w�C�������һݪ��ܼ�
        void OnInit();  								// �C������Ȥιϧγ]�w
        void OnKeyDown(UINT, UINT, UINT);
        void OnKeyUp(UINT, UINT, UINT);
        void OnLButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
        void OnLButtonUp(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@
        void OnMouseMove(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@
        void OnRButtonDown(UINT nFlags, CPoint point);  // �B�z�ƹ����ʧ@
        void OnRButtonUp(UINT nFlags, CPoint point);	// �B�z�ƹ����ʧ@
    protected:
        void OnMove();									// ���ʹC������
        void OnShow();									// ��ܳo�Ӫ��A���C���e��
		void PlayRockmanSound();
    private:
        Rockman x87_1;				// ���J�H
        Terrain fireDragonMap;		// �a��:���s
        CInteger  life;				// �ͩR��
        RockCannon* _cannon;		//�l�u���}�C
        Monster monster[8];			//�Ǫ�
		Nightmare nightmare[6];		//���L
		Bat bat[6];					//����
		bool isplay[2] = { false };
		bool isplayboom;
        //const int monster_num, terrain_num;
        //int map[6][5];
};

/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����������A(Game Over)
// �C��Member function��Implementation���n����
/////////////////////////////////////////////////////////////////////////////

class CGameStateOver : public CGameState {
    public:
        CGameStateOver(CGame* g);
        void OnBeginState();							// �]�w�C�������һݪ��ܼ�
        void OnInit();
    protected:
        void OnMove();									// ���ʹC������
        void OnShow();									// ��ܳo�Ӫ��A���C���e��
    private:
        int counter;	// �˼Ƥ��p�ƾ�
		CMovingBitmap youdead;
};

}