#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
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

void Boss::deductLife(int damage)
{
    life -= damage;
}

void Boss::OnMove()
{
    if (life % 20 == 0)
    {
        lacerate.SetTopLeft(x - 20, y - 20);
        lacerate.OnMove();
    }

    cannon.SetTopLeft(x - 20, y - 20);
    cannon.OnMove();
}
}