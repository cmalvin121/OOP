#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "BossCannon.h"

namespace game_framework
{
BossCannon::BossCannon()
{
    x1 = 0;
    y1 = 700;
    velocity_cannon = 30;
    lastMovingState = 0;
    catchAction = 0;
    screenX = 0;
    screenY = 0;
    showLock = 0;
    usingState = false;
    distance = 0;
    isHitSomething = 0;
    hitX = hitY = 0;
    isCatchHitXY = false;
}
void BossCannon::LoadBitMap()
{
    bossCannonleft.LoadBitmap("RES\\boss\\cannonleft.bmp", RGB(255, 255, 255));
}

void BossCannon::setCannon(int t)
{
    type = t;
}

void BossCannon::OnMove()
{
    if (distance >= 1600 || isHitSomething != 0)
    {
        usingState = false;
        catchAction = 0;
        x1 = 0;
        y1 = 0;
        distance = 0;
        isHitSomething = 0;
    }

    if (type == 1 || type == 2)			//1 = 劍氣  2 = 直線炮彈
    {
        if (catchAction == 0)
            showLock = 0;

        if (usingState)
        {
            if (lastMovingState == 0)
            {
                x1 -= velocity_cannon;
                screenX -= velocity_cannon;
                distance += velocity_cannon;
            }
            else if (lastMovingState == 1)
            {
                x1 += velocity_cannon;
                screenX += velocity_cannon;
                distance += velocity_cannon;
                //TRACE("\n------Hiiiii-----\n");
            }
        }
    }
    else if (type == 3)				//3 = 捶地板
    {
        if (catchAction == 0)
            showLock = 0;

        if (usingState)
        {
            y1 -= velocity_cannon;
            screenY -= velocity_cannon;
            distance += velocity_cannon;
        }
    }
}
void BossCannon::OnShow()
{
    int tmp = x1, tmp2 = y1;

    if (x1 >= 900)
        x1 = screenX;

    if (y1 <= 2700)
        y1 = screenY;

    bossCannonleft.SetTopLeft(x1 + 160, y1 - 85);

    if (usingState == true)
        bossCannonleft.ShowBitmap();

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
}
bool BossCannon::GetUsingState()
{
    return usingState;
}
int BossCannon::collision(int x, int y)
{
    TRACE("\n---Test2: %d %d ; %d %d---\n", x, y, x1, y1);

    if (!usingState)
        return 0;

    if (type == 1)
    {
        if (lastMovingState == 0)
        {
            if ((x1 + 35 >= x) && (x1 <= x + 160) && (y1 <= y + 200) && (y1 + 60 >= y))
            {
                isHitSomething = 1;
                usingState = false;
                return 5;
            }
        }
        else if (lastMovingState == 1)
        {
            if ((x1 <= x + 160) && (x1 >= x) && (y1 <= y + 200) && (y1 + 60 >= y))
            {
                isHitSomething = 1;
                return 5;
            }
        }
    }
    else if (type == 2)
    {
        if (lastMovingState == 0)
        {
            if ((x1 + 32 >= x) && (x1 <= x + 160) && (y1 <= y + 200) && (y1 + 32 >= y))
            {
                isHitSomething = 2;
                //TRACE("isHitSomethingMC:%d\n", isHitSomething);
                return 3;
            }
        }
        else if (lastMovingState == 1)
        {
            if ((x1 <= x + 160) && (x1 >= x) && (y1 <= y + 200) && (y1 + 32 >= y))
            {
                isHitSomething = 2;
                //TRACE("isHitSomethingMC:%d\n", isHitSomething);
                return 3;
            }
        }
    }
    else if (type == 3)
    {
        int temp;
        temp = x1;

        if ((x1 + 35 >= x) && (x1 <= x + 160) && (y1 <= y + 200) && (y1 + 60 >= y))
        {
            isHitSomething = 3;
            //TRACE("isHitSomethingMC:%d\n", isHitSomething);
            return 3;
        }

        x1 += 100;

        if ((x1 + 35 >= x) && (x1 <= x + 160) && (y1 <= y + 200) && (y1 + 60 >= y))
        {
            isHitSomething = 3;
            //TRACE("isHitSomethingMC:%d\n", isHitSomething);
            return 3;
        }

        x1 += 100;

        if ((x1 + 35 >= x) && (x1 <= x + 160) && (y1 <= y + 200) && (y1 + 60 >= y))
        {
            isHitSomething = 3;
            //TRACE("isHitSomethingMC:%d\n", isHitSomething);
            return 3;
        }

        x1 = temp - 210;

        if ((x1 + 35 >= x) && (x1 <= x + 160) && (y1 <= y + 200) && (y1 + 60 >= y))
        {
            isHitSomething = 3;
            //TRACE("isHitSomethingMC:%d\n", isHitSomething);
            return 3;
        }

        x1 -= 100;

        if ((x1 + 35 >= x) && (x1 <= x + 160) && (y1 <= y + 200) && (y1 + 60 >= y))
        {
            isHitSomething = 3;
            //TRACE("isHitSomethingMC:%d\n", isHitSomething);
            return 3;
        }

        x1 -= 100;

        if ((x1 + 35 >= x) && (x1 <= x + 160) && (y1 <= y + 200) && (y1 + 60 >= y))
        {
            isHitSomething = 3;
            //TRACE("isHitSomethingMC:%d\n", isHitSomething);
            return 3;
        }

        x1 = temp;
    }

    return 0;
}
}