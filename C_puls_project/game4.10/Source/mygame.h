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
        CMovingBitmap gameStartBackground;				//�Ϥ�:�C���ﶵ�D�e��
        CMovingBitmap option1;							//�Ϥ�:�C���ﶵ1(�}�l�C��)
        CMovingBitmap option2;							//�Ϥ�:�C���ﶵ2(�ާ@���n)
        CMovingBitmap option3;							//�Ϥ�:�C���ﶵ3(����)
		CMovingBitmap option4;							//�Ϥ�:�C���ﶵ4(�����C��)
        CMovingBitmap option1Select;					//�Ϥ�:�C���ﶵ1���(�}�l�C��)
        CMovingBitmap option2Select;					//�Ϥ�:�C���ﶵ2���(�ާ@���n)
        CMovingBitmap option3Select;					//�Ϥ�:�C���ﶵ3���(����)
		CMovingBitmap option4Select;					//�Ϥ�:�C���ﶵ4���(�����C��)
        CMovingBitmap controlGuide; 					//�Ϥ�:�ާ@���n�e��
		CMovingBitmap about;							//�Ϥ�:����e��
        int option;										//��e�ﶵ
        bool startGuide;								//�O�_�}�l�ާ@���n
		bool startabout;								//�O�_�}�l����e��
		bool isplaysound;								//�O�_���񭵮�
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
        Rockman x87_1;									//���J�H
        Terrain fireDragonMap;							//�a��:���s
        CInteger  life;									//�ͩR��
        RockCannon* _cannon;							//���J�H�l�u���}�C
        Monster monster[8];								//�U����
		Nightmare nightmare[6];							//���L
		Bat bat[6];										//����
		Boss zero_fake;									//���L�Ǭ�
		bool isplay[2] = { false };						//�O�_���񭵮�
		bool isplayboom;								//�O�_�����z������
		bool isplayBossStage = false;					//�O�_�i�JBOSS�԰�
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
        int counter;									// �˼Ƥ��p�ƾ�
		CMovingBitmap youdead;							// �Ϥ�:�A���F
		CMovingBitmap youwin;							// �Ϥ�:�AĹ�F
};																	 
}