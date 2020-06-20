#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "BossCannon.h"
#include "Boss.h"

namespace game_framework
{
Boss::Boss()
{
}

void Boss::Initialize()
{
    x = y = 0;
    screen_x = screen_y = 0;
    life = 48;
    isAlive = true;
    skill = 0;
	commandProcess = 0;
	attackDelay = 0;
	AttackCommand[0] = 0;
	AttackCommand[1] = 2;
	AttackCommand[2] = 2;
	AttackCommand[3] = 3;
	AttackCommand[4] = 0;
	AttackCommand[5] = 2;
	AttackCommand[6] = 2;
	AttackCommand[7] = 3;
	AttackCommand[8] = 1;
	AttackCommand[9] = 0;
	AttackCommand[10] = 4;
	AttackCommand[11] = 0;
	AttackCommand[12] = 5;
	AttackCommand[13] = 0;
	AttackCommand[14] = 1;
	reverse = 0;
	KillDirection = 0;
	isfire = false;
	startAttack = false;
	isInjured = false;
	isPlaySound = false;
	destroyLightCount = 0;
	injureDelay = 30;
	injureShine = 3;
	for (int i = 0; i < 6; i++)
		cannon[i].SetUsingState(false);
}
void Boss::LoadHugeknifeBitMap()
{
	hugeknife.AddBitmap("RES\\boss\\Kill.bmp", RGB(255, 255, 255));
	hugeknife.AddBitmap("RES\\boss\\Kill2.bmp", RGB(255, 255, 255));
	hugeknife.AddBitmap("RES\\boss\\Kill3.bmp", RGB(255, 255, 255));
	hugeknife.AddBitmap("RES\\boss\\Kill4.bmp", RGB(255, 255, 255));
	hugeknife.AddBitmap("RES\\boss\\Kill5.bmp", RGB(255, 255, 255));
	hugeknife.SetDelayCount(2);
}
void Boss::LoadBossDestoryLightBitMap()
{
	bossDestoryLight.AddBitmap("RES\\boss\\bossdestroylight.bmp", RGB(255, 255, 255));
	bossDestoryLight.AddBitmap("RES\\boss\\bossdestroylight2.bmp", RGB(255, 255, 255));
	bossDestoryLight.AddBitmap("RES\\boss\\bossdestroylight3.bmp", RGB(255, 255, 255));
	bossDestoryLight.AddBitmap("RES\\boss\\bossdestroylight4.bmp", RGB(255, 255, 255));
	bossDestoryLight.AddBitmap("RES\\boss\\bossdestroylight5.bmp", RGB(255, 255, 255));
	bossDestoryLight.AddBitmap("RES\\boss\\bossdestroylight6.bmp", RGB(255, 255, 255));
	bossDestoryLight.AddBitmap("RES\\boss\\bossdestroylight7.bmp", RGB(255, 255, 255));
	bossDestoryLight.AddBitmap("RES\\boss\\bossdestroylight8.bmp", RGB(255, 255, 255));
	bossDestoryLight.AddBitmap("RES\\boss\\bossdestroylight9.bmp", RGB(255, 255, 255));
	bossDestoryLight.AddBitmap("RES\\boss\\bossdestroylight10.bmp", RGB(255, 255, 255));
	bossDestoryLight.AddBitmap("RES\\boss\\bossdestroylight11.bmp", RGB(255, 255, 255));
	bossDestoryLight.SetDelayCount(4);
}
void Boss::LoadBossSprintBitMap()
{
	bossSprint.AddBitmap("RES\\boss\\bosssprint.bmp", RGB(255, 255, 255));
	bossSprint.AddBitmap("RES\\boss\\bosssprint2.bmp", RGB(255, 255, 255));
	bossSprint.AddBitmap("RES\\boss\\bosssprint3.bmp", RGB(255, 255, 255));
	bossSprint.AddBitmap("RES\\boss\\bosssprint4.bmp", RGB(255, 255, 255));
	bossSprint.AddBitmap("RES\\boss\\bosssprint5.bmp", RGB(255, 255, 255));
	bossSprint.AddBitmap("RES\\boss\\bosssprint6.bmp", RGB(255, 255, 255));
	bossSprint.AddBitmap("RES\\boss\\bosssprint7.bmp", RGB(255, 255, 255));
	bossSprint.SetDelayCount(4);
}
void Boss::LoadBossSprintLeftBitMap()
{
	bossSprintLeft.AddBitmap("RES\\boss\\bossSprintleft.bmp", RGB(255, 255, 255));
	bossSprintLeft.AddBitmap("RES\\boss\\bossSprint2left.bmp", RGB(255, 255, 255));
	bossSprintLeft.AddBitmap("RES\\boss\\bossSprint3left.bmp", RGB(255, 255, 255));
	bossSprintLeft.AddBitmap("RES\\boss\\bossSprint4left.bmp", RGB(255, 255, 255));
	bossSprintLeft.AddBitmap("RES\\boss\\bossSprint5left.bmp", RGB(255, 255, 255));
	bossSprintLeft.AddBitmap("RES\\boss\\bossSprint6left.bmp", RGB(255, 255, 255));
	bossSprintLeft.AddBitmap("RES\\boss\\bossSprint7left.bmp", RGB(255, 255, 255));
	bossSprintLeft.SetDelayCount(4);
}
void Boss::LoadBossFireBitMap()
{
	bossFire.AddBitmap("RES\\boss\\bossfire.bmp", RGB(255, 255, 255));
	bossFire.AddBitmap("RES\\boss\\bossfire2.bmp", RGB(255, 255, 255));
	bossFire.AddBitmap("RES\\boss\\bossfire3.bmp", RGB(255, 255, 255));
	bossFire.AddBitmap("RES\\boss\\bossfire4.bmp", RGB(255, 255, 255));
	bossFire.AddBitmap("RES\\boss\\bossfire5.bmp", RGB(255, 255, 255));
	bossFire.SetDelayCount(4);
}
void Boss::LoadBossFireLeftBitMap()
{
	bossFireLeft.AddBitmap("RES\\boss\\bossfireleft.bmp", RGB(255, 255, 255));
	bossFireLeft.AddBitmap("RES\\boss\\bossfire2left.bmp", RGB(255, 255, 255));
	bossFireLeft.AddBitmap("RES\\boss\\bossfire3left.bmp", RGB(255, 255, 255));
	bossFireLeft.AddBitmap("RES\\boss\\bossfire4left.bmp", RGB(255, 255, 255));
	bossFireLeft.AddBitmap("RES\\boss\\bossfire5left.bmp", RGB(255, 255, 255));
	bossFireLeft.SetDelayCount(4);
}
void Boss::LoadBossChopBitMap()
{
	bossChop.AddBitmap("RES\\boss\\bossflysword.bmp", RGB(255, 255, 255));
	bossChop.AddBitmap("RES\\boss\\bossflysword2.bmp", RGB(255, 255, 255));
	bossChop.AddBitmap("RES\\boss\\bossflysword3.bmp", RGB(255, 255, 255));
	bossChop.AddBitmap("RES\\boss\\bossflysword4.bmp", RGB(255, 255, 255));
	bossChop.AddBitmap("RES\\boss\\bossflysword5.bmp", RGB(255, 255, 255));
	bossChop.AddBitmap("RES\\boss\\bossflysword6.bmp", RGB(255, 255, 255));
	bossChop.AddBitmap("RES\\boss\\bossflysword7.bmp", RGB(255, 255, 255));
	bossChop.AddBitmap("RES\\boss\\bossflysword8.bmp", RGB(255, 255, 255));
	bossChop.SetDelayCount(2);
}
void Boss::LoadBossChopLeftBitMap()
{
	bossChopLeft.AddBitmap("RES\\boss\\bossflyswordleft.bmp", RGB(255, 255, 255));
	bossChopLeft.AddBitmap("RES\\boss\\bossflysword2left.bmp", RGB(255, 255, 255));
	bossChopLeft.AddBitmap("RES\\boss\\bossflysword3left.bmp", RGB(255, 255, 255));
	bossChopLeft.AddBitmap("RES\\boss\\bossflysword4left.bmp", RGB(255, 255, 255));
	bossChopLeft.AddBitmap("RES\\boss\\bossflysword5left.bmp", RGB(255, 255, 255));
	bossChopLeft.AddBitmap("RES\\boss\\bossflysword6left.bmp", RGB(255, 255, 255));
	bossChopLeft.AddBitmap("RES\\boss\\bossflysword7left.bmp", RGB(255, 255, 255));
	bossChopLeft.AddBitmap("RES\\boss\\bossflysword8left.bmp", RGB(255, 255, 255));
	bossChopLeft.SetDelayCount(2);
}
void Boss::LoadBossKillBitMap()
{
	bossKill.AddBitmap("RES\\boss\\bossKill.bmp", RGB(255, 255, 255));
	bossKill.AddBitmap("RES\\boss\\bossKill.bmp", RGB(255, 255, 255));
	bossKill.AddBitmap("RES\\boss\\bossKill.bmp", RGB(255, 255, 255));
	bossKill.AddBitmap("RES\\boss\\bossKill.bmp", RGB(255, 255, 255));
	bossKill.AddBitmap("RES\\boss\\bossKill.bmp", RGB(255, 255, 255));
	bossKill.AddBitmap("RES\\boss\\bossflysword.bmp", RGB(255, 255, 255));
	bossKill.AddBitmap("RES\\boss\\bossflysword2.bmp", RGB(255, 255, 255));
	bossKill.AddBitmap("RES\\boss\\bossflysword3.bmp", RGB(255, 255, 255));
	bossKill.AddBitmap("RES\\boss\\bossflysword4.bmp", RGB(255, 255, 255));
	bossKill.AddBitmap("RES\\boss\\bossflysword5.bmp", RGB(255, 255, 255));
	bossKill.AddBitmap("RES\\boss\\bossflysword6.bmp", RGB(255, 255, 255));
	bossKill.AddBitmap("RES\\boss\\bossflysword7.bmp", RGB(255, 255, 255));
	bossKill.AddBitmap("RES\\boss\\bossflysword8.bmp", RGB(255, 255, 255));
	bossKill.SetDelayCount(2);
}
void Boss::LoadBossKillLeftBitMap()
{
	bossKillLeft.AddBitmap("RES\\boss\\bossKillleft.bmp", RGB(255, 255, 255));
	bossKillLeft.AddBitmap("RES\\boss\\bossKillleft.bmp", RGB(255, 255, 255));
	bossKillLeft.AddBitmap("RES\\boss\\bossKillleft.bmp", RGB(255, 255, 255));
	bossKillLeft.AddBitmap("RES\\boss\\bossKillleft.bmp", RGB(255, 255, 255));
	bossKillLeft.AddBitmap("RES\\boss\\bossKillleft.bmp", RGB(255, 255, 255));
	bossKillLeft.AddBitmap("RES\\boss\\bossflyswordleft.bmp", RGB(255, 255, 255));
	bossKillLeft.AddBitmap("RES\\boss\\bossflysword2left.bmp", RGB(255, 255, 255));
	bossKillLeft.AddBitmap("RES\\boss\\bossflysword3left.bmp", RGB(255, 255, 255));
	bossKillLeft.AddBitmap("RES\\boss\\bossflysword4left.bmp", RGB(255, 255, 255));
	bossKillLeft.AddBitmap("RES\\boss\\bossflysword5left.bmp", RGB(255, 255, 255));
	bossKillLeft.AddBitmap("RES\\boss\\bossflysword6left.bmp", RGB(255, 255, 255));
	bossKillLeft.AddBitmap("RES\\boss\\bossflysword7left.bmp", RGB(255, 255, 255));
	bossKillLeft.AddBitmap("RES\\boss\\bossflysword8left.bmp", RGB(255, 255, 255));
	bossKillLeft.SetDelayCount(2);
}
void Boss::LoadKnifeBitMap()
{
	knife.AddBitmap("RES\\boss\\flysword_sword.bmp", RGB(255, 255, 255));
	knife.AddBitmap("RES\\boss\\flysword_sword2.bmp", RGB(255, 255, 255));
	knife.AddBitmap("RES\\boss\\flysword_sword3.bmp", RGB(255, 255, 255));
	knife.AddBitmap("RES\\boss\\flysword_sword4.bmp", RGB(255, 255, 255));
	knife.AddBitmap("RES\\boss\\flysword_sword5.bmp", RGB(255, 255, 255));
	knife.SetDelayCount(2);
}
void Boss::LoadKnifeLeftBitMap()
{
	knifeLeft.AddBitmap("RES\\boss\\flysword_sword1left.bmp", RGB(255, 255, 255));
	knifeLeft.AddBitmap("RES\\boss\\flysword_sword2left.bmp", RGB(255, 255, 255));
	knifeLeft.AddBitmap("RES\\boss\\flysword_sword3left.bmp", RGB(255, 255, 255));
	knifeLeft.AddBitmap("RES\\boss\\flysword_sword4left.bmp", RGB(255, 255, 255));
	knifeLeft.AddBitmap("RES\\boss\\flysword_sword5left.bmp", RGB(255, 255, 255));
	knifeLeft.SetDelayCount(2);
}
void Boss::LoadLifeObjectBitmap()
{
	lifeItem.LoadBitmap("RES\\life\\life_item_boss.bmp", RGB(255, 255, 255));
	lifeValue.LoadBitmap("RES\\life\\life_value.bmp", RGB(255, 255, 255));
}
void Boss::LoadBitMap()
{
    boss.LoadBitmap("RES\\boss\\boss.bmp", RGB(255, 255, 255));
	bossLeft.LoadBitmap("RES\\boss\\bossleft.bmp", RGB(255, 255, 255));
	LoadLifeObjectBitmap();
	LoadHugeknifeBitMap();
	LoadBossDestoryLightBitMap();
	LoadBossSprintBitMap();
	LoadBossSprintLeftBitMap();
	LoadBossFireBitMap();
	LoadBossFireLeftBitMap();
	LoadBossChopBitMap();
	LoadBossChopLeftBitMap();
	LoadBossKillBitMap();
	LoadBossKillLeftBitMap();
	LoadKnifeBitMap();
	LoadKnifeLeftBitMap();
	for (int i = 0; i < 6; i++)
		cannon[i].LoadBitMap();
}
void Boss::ResetAnimation()
{
	if (skill == 5)
	{
		bossKill.Reset();
		bossKillLeft.Reset();
		hugeknife.Reset();
		knife.Reset();
		knifeLeft.Reset();
	}
	else if (skill == 4)
		bossDestoryLight.Reset();
	else if (skill == 3)
	{
		bossChop.Reset();
		bossChopLeft.Reset();
		knife.Reset();
		knifeLeft.Reset();
	}
	else if (skill == 2)
	{
		bossFire.Reset();
		bossFireLeft.Reset();
	}
	else if (skill == 1)
	{
		bossSprint.Reset();
		bossSprintLeft.Reset();
	}
}
void Boss::OnShow()
{
	if (AttackDirection == 0)
		hugeknife.SetTopLeft(x + screen_x - 48, y + screen_y - 1492 - 523);
	else if (AttackDirection == 1)
		hugeknife.SetTopLeft(x + screen_x + 6, y + screen_y - 1492 - 523);
	if (bossChop.GetCurrentBitmapNumber() == 2 || bossChopLeft.GetCurrentBitmapNumber() == 2)
	{
		knife.SetTopLeft(x + screen_x - 149, y + screen_y - 1492 - 66 - 45);
		knifeLeft.SetTopLeft(x + screen_x + 43, y + screen_y - 1492 - 66 - 45);
	}
	else if(bossChop.GetCurrentBitmapNumber() == 3 || bossChopLeft.GetCurrentBitmapNumber() == 3)
	{
		knife.SetTopLeft(x + screen_x - 192, y + screen_y - 1492 - 19 - 45);
		knifeLeft.SetTopLeft(x + screen_x + 123, y + screen_y - 1492 - 19 - 45);
	}
	else if (bossChop.GetCurrentBitmapNumber() == 4 || bossChopLeft.GetCurrentBitmapNumber() == 4)
	{
		knife.SetTopLeft(x + screen_x - 188, y + screen_y - 1492 + 14 - 45);
		knifeLeft.SetTopLeft(x + screen_x + 122, y + screen_y - 1492 + 10 - 45);
	}
	else if (bossChop.GetCurrentBitmapNumber() == 5 || bossChopLeft.GetCurrentBitmapNumber() == 5)
	{
		knife.SetTopLeft(x + screen_x - 188, y + screen_y - 1492 + 46 - 45);
		knifeLeft.SetTopLeft(x + screen_x + 122, y + screen_y - 1492 + 46 - 45);
	}
	else if (bossChop.GetCurrentBitmapNumber() == 6 || bossChopLeft.GetCurrentBitmapNumber() == 6)
	{
		knife.SetTopLeft(x + screen_x - 80, y + screen_y - 1492 + 68 - 45);
		knifeLeft.SetTopLeft(x + screen_x + 122, y + screen_y - 1492 + 68 - 45);
	}

	if (bossKill.GetCurrentBitmapNumber() == 7 || bossKillLeft.GetCurrentBitmapNumber() == 7)
	{
		knife.SetTopLeft(x + screen_x - 149, y + screen_y - 1492 - 66 - 45);
		knifeLeft.SetTopLeft(x + screen_x + 43, y + screen_y - 1492 - 66 - 45);
	}
	else if (bossKill.GetCurrentBitmapNumber() == 8 || bossKillLeft.GetCurrentBitmapNumber() == 8)
	{
		knife.SetTopLeft(x + screen_x - 192, y + screen_y - 1492 - 19 - 45);
		knifeLeft.SetTopLeft(x + screen_x + 123, y + screen_y - 1492 - 19 - 45);
	}
	else if (bossKill.GetCurrentBitmapNumber() == 9 || bossKillLeft.GetCurrentBitmapNumber() == 9)
	{
		knife.SetTopLeft(x + screen_x - 188, y + screen_y - 1492 + 14 - 45);
		knifeLeft.SetTopLeft(x + screen_x + 122, y + screen_y - 1492 + 10 - 45);
	}
	else if (bossKill.GetCurrentBitmapNumber() == 10 || bossKillLeft.GetCurrentBitmapNumber() == 10)
	{
		knife.SetTopLeft(x + screen_x - 188, y + screen_y - 1492 + 46 - 45);
		knifeLeft.SetTopLeft(x + screen_x + 122, y + screen_y - 1492 + 46 - 45);
	}
	else if (bossKill.GetCurrentBitmapNumber() == 11 || bossKillLeft.GetCurrentBitmapNumber() == 11)
	{
		knife.SetTopLeft(x + screen_x - 80, y + screen_y - 1492 + 68 - 45);
		knifeLeft.SetTopLeft(x + screen_x + 122, y + screen_y - 1492 + 68 - 45);
	}
	bossKill.SetTopLeft(x + screen_x, y + screen_y - 1492-30);
	bossKillLeft.SetTopLeft(x + screen_x, y + screen_y - 1492-30);
	bossDestoryLight.SetTopLeft(x + screen_x, y + screen_y - 1492 - 85);
	bossChop.SetTopLeft(x + screen_x, y + screen_y - 1492 - 45);
	bossChopLeft.SetTopLeft(x + screen_x, y + screen_y - 1492 - 45);
	bossFire.SetTopLeft(x + screen_x, y + screen_y - 1492);
	bossFireLeft.SetTopLeft(x + screen_x, y + screen_y - 1492);
	bossSprint.SetTopLeft(x + screen_x, y + screen_y - 1492);
	bossSprintLeft.SetTopLeft(x + screen_x, y + screen_y - 1492);
	boss.SetTopLeft(x + screen_x, y + screen_y - 1492);
	bossLeft.SetTopLeft(x + screen_x, y + screen_y - 1492);
	if (injureDelay == 30)
		injureShine = 3;
	if (injureDelay < 30)
		injureShine++;
	if (injureShine % 2 == 0)
		injureShine += 0;
	else if (skill == 5 && KillDirection == 0 && life <= 24)
	{
		bossKill.OnShow();
		if (bossKill.GetCurrentBitmapNumber() < 5)
			hugeknife.OnShow();
		if (!knife.IsFinalBitmap() && bossKill.GetCurrentBitmapNumber() > 6)
			knife.OnShow();
	}
	else if (skill == 5 && KillDirection == 1 && life <= 24)
	{
		bossKillLeft.OnShow();
		if (bossKillLeft.GetCurrentBitmapNumber() < 5)
			hugeknife.OnShow();
		if (!knifeLeft.IsFinalBitmap() && bossKillLeft.GetCurrentBitmapNumber() > 6)
			knifeLeft.OnShow();
	}
	else if (skill == 4)
		bossDestoryLight.OnShow();
	else if (skill == 3 && AttackDirection == 0)
	{
		bossChop.OnShow();
		if (!knife.IsFinalBitmap() && bossChop.GetCurrentBitmapNumber() > 1)
			knife.OnShow();
	}
	else if (skill == 3 && AttackDirection == 1)
	{
		bossChopLeft.OnShow();
		if (!knifeLeft.IsFinalBitmap() && bossChopLeft.GetCurrentBitmapNumber() > 1)
			knifeLeft.OnShow();
	}
	else if (skill == 2 && AttackDirection == 0)
		bossFire.OnShow();
	else if (skill == 2 && AttackDirection == 1)
		bossFireLeft.OnShow();
	else if (skill == 1 && AttackDirection == 0)
		bossSprint.OnShow();
	else if (skill == 1 && AttackDirection == 1)
		bossSprintLeft.OnShow();
	else if (AttackDirection == 0)
		boss.ShowBitmap();
	else if (AttackDirection == 1)
		bossLeft.ShowBitmap();
	for (int i = 0; i < 6; i++)
		if (cannon[i].GetUsingState())
			cannon[i].OnShow();
	//--------顯示生命值-------------
	lifeItem.SetTopLeft(1700, 143);
	if(startAttack)
	{
		lifeItem.ShowBitmap();
		for (int i = 0; i < life; i++)
		{
			lifeValue.SetTopLeft(1736, 339 - i * 4);
			lifeValue.ShowBitmap();
		}
	}
	//--------顯示生命值-------------
	if (injureShine > 4)
		injureShine = 0;
}

int Boss::getX()
{
    return x;
}

int Boss::getY()
{
    return y;
}

int Boss::getScreenX()
{
    return screen_x;
}

int Boss::getScreenY()
{
    return screen_y;
}
int Boss::getLife()
{
	return life;
}
bool Boss::getAlive()
{
    return isAlive;
}

void Boss::setXY(int nx, int ny)
{
    x = nx;
    y = ny;
}

void Boss::setScreen_XY(int nx, int ny)
{
    screen_x = nx;
    screen_y = ny;
}

void Boss::deductLife(int damage)
{
	if (damage > 0)
		isInjured = true;
	if (damage > 4)
		damage = 4;
	if (injureDelay == 30 && isInjured == true)
		life -= damage;
    if (life <= 0)
        isAlive = false;
}

void Boss::OnMove(int RockX, int RockY)
{
	if (life > 24 && skill == 5)
	{
		isfire = false;
		commandProcess++;
		skill = AttackCommand[commandProcess];
		ResetAnimation();
	}
	if (skill == 0)
		Stay();
	else if (skill == 1)
		Sprint();
	else if (skill == 2)
		Fire();
	else if (skill == 3)
		FireFlySword(RockX, RockY);
	else if (skill == 4)
	{
		if (bossDestoryLight.GetCurrentBitmapNumber() < 4)
			destroyLightCount = 3;
		if(bossDestoryLight.GetCurrentBitmapNumber() >= 4)
			destroyLightCount++;
		if (destroyLightCount % 4 == 0 && destroyLightCount <= 16)
			CAudio::Instance()->Play(21, false);
		DestroyLight();
	}
	else if (skill == 5)
		Kill();
	for (int i = 0; i < 6; i++)
		cannon[i].OnMove();
	if (isInjured&&injureDelay == 30)
	{
		injureDelay = 0;
		isInjured = false;
	}
	if (injureDelay < 30)
	{
		injureDelay++;
		isInjured = false;
	}
	if (isPlaySound && !isAlive)
	{
		CAudio::Instance()->Play(25, false);
		isPlaySound = false;
	}
}

void Boss::FixCannonScreenXY(int fixX, int fixY)
{
	for (int i = 0; i < 6; i++)
	{
		cannon[i].AddScreenX_fix(-fixX);
		cannon[i].AddScreenY_fix(-fixY);
	}
}
void Boss::Stay()
{
	if (attackDelay < 10 && startAttack)
		attackDelay++;
	if (attackDelay >= 10)
	{
		isPlaySound = true;
		attackDelay = 0;
		commandProcess++;
		skill = AttackCommand[commandProcess];
		ResetAnimation();
	}
}
void Boss::Sprint()
{
	if (isPlaySound)
	{
		CAudio::Instance()->Play(17, false);
		CAudio::Instance()->Play(18, false);
		isPlaySound = false;
	}
	if (AttackDirection == 0)
	{
		x -= 24;
		screen_x -= 24;
		bossSprint.OnMove();
	}
	else if (AttackDirection == 1)
	{
		x += 24;
		screen_x += 24;
		bossSprintLeft.OnMove();
	}
	if (bossSprint.IsFinalBitmap() || bossSprintLeft.IsFinalBitmap())
	{
		isPlaySound = true;
		commandProcess++;
		skill = AttackCommand[commandProcess];
		ResetAnimation();
	}
}
void Boss::Fire()
{
	if (bossFire.GetCurrentBitmapNumber() == 0 || bossFireLeft.GetCurrentBitmapNumber() == 0)
	{
		if(isPlaySound)
		{
			CAudio::Instance()->Play(19, false);
			isPlaySound = false;
		}
		for (int i = 0; i < 6; i++)
		{
			if (isfire)
				break;
			if(!cannon[i].GetUsingState())
			{
				cannon[i].setCannon(2);
				cannon[i].SetUsingState(true);
				if (AttackDirection == 1)
				{
					cannon[i].SetX(x + 159);
					cannon[i].SetY(y - 8);
					cannon[i].SetScreenXY(x + screen_x + 159, y + screen_y - 8 - 1492);
				}
				else if (AttackDirection == 0)
				{
					cannon[i].SetX(x - 170);
					cannon[i].SetY(y - 8);
					cannon[i].SetScreenXY(x + screen_x - 170, y + screen_y - 8 - 1492);
				}
				cannon[i].SetLastMovingState(AttackDirection);
				cannon[i].SetCatchAction(1);
				isfire = true;
				break;
			}
		}
	}
	bossFire.OnMove();
	bossFireLeft.OnMove();
	if (bossFire.IsFinalBitmap() || bossFireLeft.IsFinalBitmap())
	{
		isPlaySound = true;
		isfire = false;
		commandProcess++;
		skill = AttackCommand[commandProcess];
		ResetAnimation();
	}
}
void Boss::FireFlySword(int RockX, int RockY)
{
	if (bossChop.GetCurrentBitmapNumber() == 2 || bossChopLeft.GetCurrentBitmapNumber() == 2)
	{
		if (isPlaySound)
		{
			CAudio::Instance()->Play(20, false);
			isPlaySound = false;
		}
		for (int i = 0; i < 6; i++)
		{
			if (isfire)
				break;
			if (!cannon[i].GetUsingState())
			{
				cannon[i].setCannon(4);
				cannon[i].SetUsingState(true);
				if (AttackDirection == 1)
				{
					cannon[i].SetX(x + 159);
					cannon[i].SetY(y - 8);
					cannon[i].SetScreenXY(x + screen_x + 159, y + screen_y - 8 - 1492);
				}
				else if (AttackDirection == 0)
				{
					cannon[i].SetX(x - 170);
					cannon[i].SetY(y - 8);
					cannon[i].SetScreenXY(x + screen_x - 170, y + screen_y - 8 - 1492);
				}
				cannon[i].SetVelocity(RockX , RockY);
				cannon[i].SetLastMovingState(AttackDirection);
				cannon[i].SetCatchAction(1);
				isfire = true;
				break;
			}
		}
	}
	bossChop.OnMove();
	bossChopLeft.OnMove();
	if (bossChop.GetCurrentBitmapNumber() > 1 && bossChopLeft.GetCurrentBitmapNumber() > 1)
	{
		if (!knife.IsFinalBitmap() && !knifeLeft.IsFinalBitmap())
		{
			knife.OnMove();
			knifeLeft.OnMove();
		}
	}
	if (bossChop.IsFinalBitmap() || bossChopLeft.IsFinalBitmap())
	{
		isPlaySound = true;
		isfire = false;
		commandProcess++;
		skill = AttackCommand[commandProcess];
		ResetAnimation();
	}
}
void Boss::DestroyLight()
{
	if (isPlaySound)
	{
		CAudio::Instance()->Play(22, false);
		isPlaySound = false;
	}
	if (bossDestoryLight.GetCurrentBitmapNumber() == 4)
	{
		for (int i = 0; i < 6; i++)
		{
			if (i == 5)
			{
				CAudio::Instance()->Play(21, false);
				isPlaySound = false;
			}
			if (isfire)
				break;
			if (!cannon[i].GetUsingState())
			{
				cannon[i].setCannon(3);
				cannon[i].SetUsingState(true);
				cannon[i].SetX(23310 + 300 * i);
				cannon[i].SetY(1730);
				cannon[i].SetScreenXY(23310 + 300 * i + screen_x, 1730 + screen_y - 1492);
				cannon[i].SetLastMovingState(AttackDirection);
				cannon[i].SetCatchAction(1);
			}
		}
		isfire = true;
	}
	bossDestoryLight.OnMove();
	if (bossDestoryLight.IsFinalBitmap())
	{
		destroyLightCount = 0;
		isPlaySound = true;
		isfire = false;
		commandProcess++;
		skill = AttackCommand[commandProcess];
		ResetAnimation();
	}
}
void Boss::Kill()
{
	if (bossKill.GetCurrentBitmapNumber() == 0 && bossKillLeft.GetCurrentBitmapNumber() == 0)
		KillDirection = AttackDirection;
	if (isPlaySound)
	{
		CAudio::Instance()->Play(24, false);
		isPlaySound = false;
	}
	if (bossKill.GetCurrentBitmapNumber() == 6 && bossKillLeft.GetCurrentBitmapNumber() == 6)
	{
		for (int i = 0; i < 6; i++)
		{
			if (i==0)
				CAudio::Instance()->Play(23, false);
			if (isfire)
				break;
			if (!cannon[i].GetUsingState())
			{
				cannon[i].setCannon(1);
				cannon[i].SetUsingState(true);
				if (KillDirection == 1)
				{
					cannon[i].SetX(x + 159);
					cannon[i].SetY(y - 352);
					cannon[i].SetScreenXY(x + screen_x + 159, y + screen_y - 352 - 1492);
				}
				else if (KillDirection == 0)
				{
					cannon[i].SetX(x - 232);
					cannon[i].SetY(y - 352);
					cannon[i].SetScreenXY(x + screen_x - 232, y + screen_y - 352 - 1492);
				}
				cannon[i].SetLastMovingState(KillDirection);
				cannon[i].SetCatchAction(1);
				isfire = true;
				break;
			}
		}
	}
	if (bossKill.GetCurrentBitmapNumber() < 5 && bossKillLeft.GetCurrentBitmapNumber() < 5)
		hugeknife.OnMove();
	if (bossKill.GetCurrentBitmapNumber() > 6 && bossKillLeft.GetCurrentBitmapNumber() > 6)
	{
		if (!knife.IsFinalBitmap() && !knifeLeft.IsFinalBitmap())
		{
			knife.OnMove();
			knifeLeft.OnMove();
		}
	}
	bossKill.OnMove();
	bossKillLeft.OnMove();
	if (bossKill.IsFinalBitmap()|| bossKillLeft.IsFinalBitmap())
	{
		isPlaySound = true;
		isfire = false;
		commandProcess++;
		skill = AttackCommand[commandProcess];
		ResetAnimation();
	}
}
void Boss::DeterminAttack(int RockX, int RockY)
{
	if (commandProcess >= 15)
	{
		isfire = false;
		if (reverse == 0)
			reverse = 1;
		else if (reverse == 1)
			reverse = 0;
		commandProcess = 0;
		skill = AttackCommand[commandProcess];
		ResetAnimation();
	}
	if (reverse == 0)
		AttackDirection = 0;
	else if (reverse == 1)
		AttackDirection = 1;
    if (x - RockX > 0 && skill != 1)
        AttackDirection = 0;
	else if (RockX - x > 0 && skill != 1)
        AttackDirection = 1;
	if ((RockX < 25120) && (RockX > 22880) && (RockY < 2000) && (RockY > 1480) && skill == 0)
	{
		skill = AttackCommand[commandProcess];
		startAttack = true;
		isPlaySound = true;
	}
    OnMove(RockX, RockY);
}
bool Boss::MonsterCollision(int RockX, int RockY)
{
    //TRACE("\n------%d %d %d %d-------\n", RockX, RockX, x, y);
    if (!isAlive)
        return false;
    else if (x + 156 > RockX && RockX + 160 > x && y + 171 > RockY && RockY + 200 > y)
        return true;
    else
        return false;
}
int Boss::MonsterCannonCollision(int RockX, int RockY)
{
    if (isAlive)
	{
		int tmp = 0;
		for (int i = 0; i < 6; i++)
		{
			tmp = cannon[i].collision(RockX, RockY);
			if (tmp != 0)
				return tmp;
		}
	}
    return false;
}
bool Boss::GetStartAttack()
{
	return startAttack;
}
}