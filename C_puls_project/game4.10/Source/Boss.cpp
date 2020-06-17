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
    isLocked = 0;
    isAlive = true;
    skill = 0;
}

void Boss::LoadBitMap()
{
    boss.LoadBitmap("RES\\boss\\bossleft.bmp", RGB(255, 255, 255));
    cannon.LoadBitMap();
}

void Boss::OnShow()
{
    boss.SetTopLeft(x + screen_x, y + screen_y - 1492);

    if (life > 0)
        boss.ShowBitmap();

    if (cannon.GetUsingState())
        cannon.OnShow();
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
    life -= damage;

    if (life < 0)
        isAlive = false;
}

void Boss::OnMove()
{
    TRACE("\n---Test1: %d %d---\n", delayTime, isLocked);

    if (isLocked == 1)
    {
        if (skill == 2 && delayTime >= 150 && cannon.GetUsingState() == false)
        {
            cannon.setCannon(1);
            cannon.SetX(x - 20);
            cannon.SetY(y - 20);
            cannon.SetScreenXY(x + screen_x - 20, y + screen_y - 20 - 1492);
            cannon.SetUsingState(true);
        }
        else if (skill == 1 && delayTime >= 100 && cannon.GetUsingState() == false)
        {
            cannon.setCannon(2);
            cannon.SetX(x - 20);
            cannon.SetY(y - 20);
            cannon.SetScreenXY(x + screen_x - 20, y + screen_y - 20 - 1492);
            cannon.SetUsingState(true);
            cannon.SetLastMovingState(1);
            ++skill;
        }
        else if (skill == 0 && delayTime >= 50 && cannon.GetUsingState() == false)
        {
            cannon.setCannon(3);
            cannon.SetX(x - 20);
            cannon.SetY(y - 20);
            cannon.SetScreenXY(x + screen_x - 20, y + screen_y - 20 - 1492);
            cannon.SetUsingState(true);
            cannon.SetLastMovingState(1);
            ++skill;
        }

        cannon.OnMove();
        delayTime++;

        if (delayTime > 150)
        {
            delayTime = 0;
            skill = 0;
        }
    }
}

void Boss::FixCannonScreenXY(int fixX, int fixY)
{
    cannon.AddScreenX_fix(-fixX);
    cannon.AddScreenY_fix(-fixY);
}

void Boss::DeterminAttack(int RockX, int RockY)
{
    if (x - RockX > 0)
        AttackDirection = 0;
    else if (RockX - x > 0)
        AttackDirection = 1;

    if (((RockX - x) < 600 && (RockX - x) > 0) || ((x - RockX) < 600 && (x - RockX) > 0))
    {
        isLocked = 1;
    }

    OnMove();
}
bool Boss::MonsterCollision(int RockX, int RockY)
{
    //TRACE("\n------%d %d %d %d-------\n", RockX, RockX, x, y);
    if (!isAlive)
        return false;
    else if (x + 130 > RockX && RockX + 140 > x && y + 171 > RockY && RockY + 200 > y)
        return true;
    else
        return false;
}
int Boss::MonsterCannonCollision(int RockX, int RockY)
{
    if (isAlive)
        return cannon.collision(RockX, RockY);

    return false;
}
}