#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include <cmath>
#include "audio.h"
#include "gamelib.h"
#include "BossCannon.h"

namespace game_framework
{
BossCannon::BossCannon()
{
    x1 = 0;
    y1 = 700;
	screenX = 0;
	screenY = 0;
	hitX = hitY = 0;
    velocity_cannon_x = 30;
	velocity_cannon_y = 30;
	distance = 0;
    lastMovingState = 0;
	usingState = false;
    catchAction = 0;
    showLock = 0;
    isHitSomething = 0;
    isCatchHitXY = false;
}
void BossCannon::LoadFlySwordBitMap() 
{
	flySword.AddBitmap("RES\\boss\\flysword_shot.bmp", RGB(255, 255, 255));
	flySword.AddBitmap("RES\\boss\\flysword_shot2.bmp", RGB(255, 255, 255));
	flySword.AddBitmap("RES\\boss\\flysword_shot3.bmp", RGB(255, 255, 255));
	flySword.AddBitmap("RES\\boss\\flysword_shot4.bmp", RGB(255, 255, 255));
	flySword.AddBitmap("RES\\boss\\flysword_shot3.bmp", RGB(255, 255, 255));
	flySword.AddBitmap("RES\\boss\\flysword_shot2.bmp", RGB(255, 255, 255));
	flySword.SetDelayCount(1);
}
void BossCannon::LoadFlySwordLeftBitMap()
{
	flySwordLeft.AddBitmap("RES\\boss\\flysword_shotleft.bmp", RGB(255, 255, 255));
	flySwordLeft.AddBitmap("RES\\boss\\flysword_shot2left.bmp", RGB(255, 255, 255));
	flySwordLeft.AddBitmap("RES\\boss\\flysword_shot3left.bmp", RGB(255, 255, 255));
	flySwordLeft.AddBitmap("RES\\boss\\flysword_shot4left.bmp", RGB(255, 255, 255));
	flySwordLeft.AddBitmap("RES\\boss\\flysword_shot3left.bmp", RGB(255, 255, 255));
	flySwordLeft.AddBitmap("RES\\boss\\flysword_shot2left.bmp", RGB(255, 255, 255));
	flySwordLeft.SetDelayCount(1);
}
void BossCannon::LoadDestroyLightBitMap()
{
	destroyLight.AddBitmap("RES\\boss\\destroylight.bmp", RGB(255, 255, 255));
	destroyLight.AddBitmap("RES\\boss\\destroylight2.bmp", RGB(255, 255, 255));
	destroyLight.AddBitmap("RES\\boss\\destroylight3.bmp", RGB(255, 255, 255));
	destroyLight.AddBitmap("RES\\boss\\destroylight4.bmp", RGB(255, 255, 255));
	destroyLight.SetDelayCount(1);
}
void BossCannon::LoadCannonBitMap()
{
	cannon.AddBitmap("RES\\boss\\cannon.bmp", RGB(255, 255, 255));
	cannon.AddBitmap("RES\\boss\\cannon2.bmp", RGB(255, 255, 255));
	cannon.AddBitmap("RES\\boss\\cannon3.bmp", RGB(255, 255, 255));
	cannon.SetDelayCount(2);
}
void BossCannon::LoadCannonLeftBitMap()
{
	cannonLeft.AddBitmap("RES\\boss\\cannonleft.bmp", RGB(255, 255, 255));
	cannonLeft.AddBitmap("RES\\boss\\cannon2left.bmp", RGB(255, 255, 255));
	cannonLeft.AddBitmap("RES\\boss\\cannon3left.bmp", RGB(255, 255, 255));
	cannonLeft.SetDelayCount(2);
}
void BossCannon::LoadBitMap()
{
	hugeSword.LoadBitmap("RES\\boss\\Killfire.bmp", RGB(255, 255, 255));
	hugeSwordLeft.LoadBitmap("RES\\boss\\Killfireleft.bmp", RGB(255, 255, 255));
	LoadFlySwordBitMap();
	LoadFlySwordLeftBitMap();
	LoadDestroyLightBitMap();
	LoadCannonBitMap();
	LoadCannonLeftBitMap();
}

void BossCannon::setCannon(int t)
{
    type = t;
	showLock = 0;
}
void BossCannon::SetVelocity(int RockX, int RockY)
{
	int v_x, v_y;
	if (RockX > x1)
		v_x = RockX - x1;
	else
		v_x = x1 - RockX;
	if (RockY > y1)
		v_y = RockY - y1;
	else
		v_y = y1 - RockY;
	velocity_cannon_x = (int)(v_x * 60 / sqrt(pow(v_x, 2) + pow(v_y, 2)));
	velocity_cannon_y = (int)(v_y * 60 / sqrt(pow(v_x, 2) + pow(v_y, 2)));
	if (RockY < y1)
		velocity_cannon_y = velocity_cannon_y * -1;
}
void BossCannon::OnMove()
{
    if (distance >= 1600)
    {
        usingState = false;
        catchAction = 0;
        x1 = 0;
        y1 = 0;
        distance = 0;
        isHitSomething = 0;
    }
    if (type == 1 || type == 2)
    {
		velocity_cannon_x = 30;
		if (type == 1)
		velocity_cannon_x = 50;
        if (catchAction == 0)
            showLock = 0;
        if (usingState)
        {
            if (lastMovingState == 0)
            {
                x1 -= velocity_cannon_x;
                screenX -= velocity_cannon_x;
                distance += velocity_cannon_x;
            }
            else if (lastMovingState == 1)
            {
                x1 += velocity_cannon_x;
                screenX += velocity_cannon_x;
                distance += velocity_cannon_x;
            }
        }
		cannon.OnMove();
		cannonLeft.OnMove();
    }
    else if (type == 3)
    {
		velocity_cannon_y = 50;
		distance += 50;
        if (catchAction == 0)
            showLock = 0;
        if (usingState)
        {
            y1 -= velocity_cannon_y;
            screenY -= velocity_cannon_y;
            distance += velocity_cannon_y;
        }
		destroyLight.OnMove();
    }
	else if (type == 4)
	{
		if (catchAction == 0)
			showLock = 0;
		if (usingState)
		{
			CONST int velocity_cannon = 60;
			if (lastMovingState == 0)
			{
				x1 -= velocity_cannon_x;
				screenX -= velocity_cannon_x;
				distance += velocity_cannon;
			}
			else if (lastMovingState == 1)
			{
				x1 += velocity_cannon_x;
				screenX += velocity_cannon_x;
				distance += velocity_cannon;
			}
			y1 += velocity_cannon_y;
			screenY += velocity_cannon_y;
		}
		flySword.OnMove();
		flySwordLeft.OnMove();
	}
}
void BossCannon::OnShow()
{
    int tmp = x1, tmp2 = y1;
    if (x1 >= 900)
        x1 = screenX;
    if (y1 <= 2700)
        y1 = screenY;
	if (type == 1 && lastMovingState == 0)
	{
		hugeSword.SetTopLeft(x1, y1);
		hugeSword.ShowBitmap();
	}
	else if (type == 1 && lastMovingState == 1)
	{
		hugeSwordLeft.SetTopLeft(x1, y1);
		hugeSwordLeft.ShowBitmap();
	}
	else if (type == 2 && lastMovingState == 0)
	{
		cannon.SetTopLeft(x1, y1);
		cannon.OnShow();
	}
	else if (type == 2 && lastMovingState == 1)
	{
		cannonLeft.SetTopLeft(x1, y1);
		cannonLeft.OnShow();
	}
	else if (type == 3)
	{
		destroyLight.SetTopLeft(x1, y1);
		destroyLight.OnShow();
	}
	else if (type == 4 && lastMovingState == 0)
	{
		flySword.SetTopLeft(x1, y1);
		flySword.OnShow();
	}
	else if (type == 4 && lastMovingState == 1)
	{
		flySwordLeft.SetTopLeft(x1, y1);
		flySwordLeft.OnShow();
	}
    x1 = tmp;
    y1 = tmp2;
}
void BossCannon::SetLastMovingState(int flag)
{
    if (catchAction == 0)
        lastMovingState = flag;
}
void BossCannon::SetX(int x)
{
    if (catchAction == 0)
        x1 = x;
}
void BossCannon::SetY(int y)
{
    if (catchAction == 0)
        y1 = y;
}
void BossCannon::AddScreenX_fix(int fix)
{
    if (usingState == true)
        screenX += fix;
    if (usingState == false)
        hitX += fix;
}
void BossCannon::AddScreenY_fix(int fix)
{
    if (usingState == true)
        screenY += fix;
    if (usingState == false)
        hitY += fix;
}
void BossCannon::SetScreenXY(int x, int y)
{
    if (showLock == 0)
    {
        screenX = x;
        screenY = y;
        showLock = 1;
    }
}
void BossCannon::SetCatchAction(bool flag)
{
    catchAction = flag;
}
void BossCannon::SetUsingState(bool flag)
{
	usingState = flag;
	distance = 0;
	catchAction = 0;
	x1 = 0;
	y1 = 0;
	screenX = 0;
	screenY = 0;
}
bool BossCannon::GetUsingState()
{
    return usingState;
}
int BossCannon::collision(int x, int y)
{
    if (!usingState)
        return 0;
    if (type == 1)
    {
        if (lastMovingState == 0)
        {
            if ((x1 + 232 >= x) && (x1 <= x + 160) && (y1 <= y + 200) && (y1 + 523 >= y))
            {
                isHitSomething = 1;
                return 16;
            }
        }
        else if (lastMovingState == 1)
        {
            if ((x1 <= x + 160) && (x1 >= x) && (y1 <= y + 200) && (y1 + 523 >= y))
            {
                isHitSomething = 1;
                return 16;
            }
        }
    }
    else if (type == 2)
    {
        if (lastMovingState == 0)
        {
            if ((x1 + 32 >= x) && (x1 <= x + 160) && (y1 <= y + 200) && (y1 + 109 >= y))
            {
                isHitSomething = 4;
                return 4;
            }
        }
        else if (lastMovingState == 1)
        {
			if ((x1 + 58 <= x + 160) && (x1 + 58 + 160 >= x) && (y1 <= y + 200) && (y1 + 109 >= y))
            {
                isHitSomething = 4;
                return 4;
            }
        }
    }
    else if (type == 3)
    {
		if ((x1 + 7 + 94 >= x) && (x1 + 7 <= x + 160) && (y1 <= y + 200) && (y1 + 225 >= y))
        {
            isHitSomething = 4;
            return 4;
        }
    }
	else if (type == 4)
	{
		if (lastMovingState == 0)
		{
			if ((x1 + 108 >= x) && (x1 <= x + 160) && (y1 <= y + 200) && (y1 + 167 >= y))
			{
				isHitSomething = 8;
				return 8;
			}
		}
		else if (lastMovingState == 1)
		{
			if ((x1 <= x + 160) && (x1 >= x) && (y1 <= y + 200) && (y1 + 167 >= y))
			{
				isHitSomething = 8;
				return 8;
			}
		}
	}
    return 0;
}
}