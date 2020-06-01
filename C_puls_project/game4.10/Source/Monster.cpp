#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Trashcannon.h"
#include "Monster.h"

namespace game_framework
{
Monster::Monster()
{}
void Monster::Initialize()
{
    x = y = 0;
    s_x = s_y = 0;
    life = 10;
    isAlive = true;
    AttackDirection = 0;
    AttackDelay = 0;
    monsBoom.Reset();
}
void Monster::LoadBitMap()
{
    monsRight.LoadBitmap("RES\\enemy\\enemy_X6_1.bmp", RGB(255, 255, 255));
    monsLeft.LoadBitmap("RES\\enemy\\enemy_X6_1left.bmp", RGB(255, 255, 255));
    monsRightAttack.LoadBitmap("RES\\enemy\\enemy_X6_1 attack.bmp", RGB(255, 255, 255));
    monsLeftAttack.LoadBitmap("RES\\enemy\\enemy_X6_1 attackleft.bmp", RGB(255, 255, 255));
    LoadBoomBitmap();
	cannon.LoadBitmapA();
}
void Monster::LoadBoomBitmap()
{
    monsBoom.AddBitmap("RES\\enemy\\explosion.bmp", RGB(255, 255, 255));
    monsBoom.AddBitmap("RES\\enemy\\explosion2.bmp", RGB(255, 255, 255));
    monsBoom.AddBitmap("RES\\enemy\\explosion3.bmp", RGB(255, 255, 255));
    monsBoom.AddBitmap("RES\\enemy\\explosion4.bmp", RGB(255, 255, 255));
    monsBoom.AddBitmap("RES\\enemy\\explosion5.bmp", RGB(255, 255, 255));
    monsBoom.AddBitmap("RES\\enemy\\explosion6.bmp", RGB(255, 255, 255));
    monsBoom.AddBitmap("RES\\enemy\\explosion7.bmp", RGB(255, 255, 255));
    monsBoom.AddBitmap("RES\\enemy\\explosion8.bmp", RGB(255, 255, 255));
    monsBoom.SetDelayCount(2);
}
void Monster::setXY(int nx, int ny)
{
    x = nx;
    y = ny;
}
void Monster::setScreenXY(int nx, int ny)
{
    s_x = nx;
    s_y = ny;
}
void Monster::setAlive(bool state)
{
    isAlive = state;
}
int Monster::getX()
{
    return x;
}
int Monster::getY()
{
    return y;
}
int Monster::getScreenX()
{
    return s_x;
}

int Monster::getScreenY()
{
    return s_y;
}
void Monster::FixCannonScreenXY(int fixX, int fixY)
{
	if(cannon.GetUsingState())
	{
		cannon.AddScreenX_fix(-fixX);
		cannon.AddScreenY_fix(-fixY);
	}
}
bool Monster::getAlive()
{
    return isAlive;
}
void Monster::deductLife(int damage)
{
    life -= damage;

    if (life <= 0)
        isAlive = false;

    //TRACE("\n\n--------------- life = %d --------------\n\n", life);
}
void Monster::DeterminAttack(int RockX, int RockY)
{
    if (x - RockX > 400 || RockX - x > 400)
        AttackDelay = 49;

    if (((x - RockX < 400) && (x - RockX > 0)) || ((RockX - x < 400) && (RockX - x > 0)))//往左對主角攻擊,往右對主角攻擊
        AttackDelay++;

    if (x - RockX > 0)
        AttackDirection = 0;
    else if (RockX - x > 0)
        AttackDirection = 1;

    if (AttackDelay == 50)
	{
		AttackDelay = 0;
		cannon.SetUsingState(true);
		cannon.SetX(x + 121);
		cannon.SetY(y + 48);
		cannon.SetScreenXY(s_x + 121, s_y + 48 - 1492);
		cannon.SetLastMovingState(AttackDirection);
		cannon.SetCatchAction(1);
	}
	cannon.OnMove();

}
bool Monster::MonsterCollision(int RockX, int RockY)
{
    if (!isAlive)
        return false;
    else if (x + 254 > RockX && RockX + 160 > x && y + 225 > RockY && RockY > y)
        return true;
    else
        return false;
}
int Monster::MonsterCannonCollision(int RockX, int RockY)
{
	if(isAlive)
		return cannon.collision(RockX, RockY);
	return false;
}
void Monster::OnShow()
{
    if (AttackDelay < 5 && AttackDirection == 0)
    {
        monsRightAttack.SetTopLeft(s_x, s_y - 1492);
        monsRightAttack.ShowBitmap();
    }
    else if (AttackDelay < 5 && AttackDirection == 1)
    {
        monsLeftAttack.SetTopLeft(s_x, s_y - 1492);
        monsLeftAttack.ShowBitmap();
    }
    else if (AttackDirection == 0)
    {
        monsRight.SetTopLeft(s_x, s_y - 1492);
        monsRight.ShowBitmap();
    }
    else if (AttackDirection == 1)
    {
        monsLeft.SetTopLeft(s_x, s_y - 1492);
        monsLeft.ShowBitmap();
    }
	if (cannon.GetUsingState())
		cannon.OnShow();
	else
		cannon.OnShowHit();
}
void Monster::OnShowBoom()
{
    if (monsBoom.IsFinalBitmap())
        monsBoom.setToSpecifyBitmap(7);

    monsBoom.OnMove();
    monsBoom.SetTopLeft(s_x, s_y - 1492);

    if (isAlive == false && !monsBoom.IsFinalBitmap())
        monsBoom.OnShow();
}
}