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
    life = 80;
    delayTime = 0;
}

void Boss::LoadBitMap()
{
    boss.LoadBitmap("RES\\boss\\bossleft.bmp", RGB(255, 255, 255));
}

void Boss::OnShow()
{
	boss.SetTopLeft(x + screen_x, y + screen_y - 1492);

    if (life > 0)
        boss.ShowBitmap();
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

bool Boss::getAlive()
{
    if (life > 0)
        return true;

    return false;
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
    life -= damage;
}

void Boss::OnMove()
{
    if (delayTime == 180)
    {
        cannon.setCannon(1);
        cannon.SetX(x - 20);
        cannon.SetY(y - 20);
        cannon.OnMove();
    }
    else if (delayTime == 120)
    {
        cannon.setCannon(2);
        cannon.SetX(x - 20);
        cannon.SetY(y - 20);
        cannon.OnMove();
    }
    else if (delayTime == 60)
    {
        cannon.setCannon(3);
        cannon.SetX(x - 20);
        cannon.SetY(y - 20);
        cannon.OnMove();
    }

    delayTime++;

    if (delayTime > 180)
    {
        delayTime = 0;
    }
}

void Boss::DeterminAttack(int RockX, int RockY)
{
    if (x - RockX > 0)
        AttackDirection = 0;
    else if (RockX - x > 0)
        AttackDirection = 1;
}
}