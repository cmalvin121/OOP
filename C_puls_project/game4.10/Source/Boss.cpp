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
}

void Boss::LoadBitMap()
{
    boss.LoadBitmap("RES\\bitmap3.bmp", RGB(255, 255, 255));
}

void Boss::OnShow()
{
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
    if (life % 20 == 0)
    {
        cannon.setCannon(1);
        cannon.SetX(x - 20);
        cannon.SetY(y - 20);
        cannon.OnMove();
        cannon.setCannon(2);
        cannon.SetX(x - 20);
        cannon.SetY(y - 20);
        cannon.OnMove();
        cannon.setCannon(3);
        cannon.SetX(x - 20);
        cannon.SetY(y - 20);
        cannon.OnMove();
    }
}
}