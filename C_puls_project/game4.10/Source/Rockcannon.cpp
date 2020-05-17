#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "RockCannon.h"
namespace game_framework
{
RockCannon::RockCannon()
{
    x1 = 0;
    y1 = 700;
    velocity_cannon = 35;
    nowCharge = 0;
    lastMovingState = 0;
    catchAction = 0;
    screenX = 0;
    screenY = 0;
    showLock = 0;
    usingState = false;
    distance = 0;
}
void RockCannon::SetNowCharge(int charge)
{
    nowCharge = charge;
}
void RockCannon::SetLastMovingState(int flag)
{
    if (catchAction == 0)
        lastMovingState = flag;
}
void RockCannon::SetX(int x)
{
    if (catchAction == 0)
        x1 = x;
}
void RockCannon::SetY(int y)
{
    if (catchAction == 0)
        y1 = y;
}
void RockCannon::SetFixScreenY(int fix)
{
    screenY += fix;
}
void RockCannon::SetCatchAction(bool flag)
{
    catchAction = flag;
}
bool RockCannon::GetUsingState()
{
    return usingState;
}
void RockCannon::SetUsingState(bool flag)
{
    usingState = flag;
    distance = 0;
    catchAction = 0;
    x1 = 0;
    y1 = 0;
}
void RockCannon::SetScreen()
{
    if (lastMovingState == 0)
    {
        if (x1 >= 900)
            screenX = 900 + 170;

        if (y1 <= 2700)
        {
            if (nowCharge > 60)
                screenY = 380;
            else
                screenY = 380 + 84;
        }
    }
    else if (lastMovingState == 1)
    {
        if (nowCharge >= 60)
        {
            if (x1 >= 900)
                screenX = 900 - 222;

            if (y1 <= 2700)
                screenY = 380;
        }
        else
        {
            if (x1 >= 900)
                screenX = 900;

            if (y1 <= 2700)
                screenY = 380 + 84;
        }
    }
}
void RockCannon::LoadBitmap()
{
    LoadNormalCannonBitmap();
    LoadChargeCannonBitmap();
    LoadSuperChargeCannonBitmap();
    LoadNormalCannonLeftBitmap();
    LoadChargeCannonLeftBitmap();
    LoadSuperChargeCannonLeftBitmap();
}
int RockCannon::collision(int x, int y)
{
    //TRACE("\n\n-------------%d   %d   %d   %d------------\n\n", x1, y1, x, y);
    //TRACE("\n\n----------- NowCharge = %d  Moving = %d------------\n\n", nowCharge, lastMovingState);
    if (nowCharge >= 60)
    {
        if (lastMovingState == 0)
        {
            if ((x1 + 222 >= x) && (x1 <= x + 254) && (y1 <= y + 255) && (y1 + 180 >= y))
                return 8;
        }
        else if (lastMovingState == 1)
        {
            if ((x1 <= x + 254) && (x1 >= x) && (y1 <= y + 255) && (y1 + 180 >= y))
                return 8;
        }
    }
    else if (nowCharge >= 5 && nowCharge < 60)
    {
        if (lastMovingState == 0)
        {
            if ((x1 + 40 >= x) && (x1 <= x + 254) && (y1 <= y + 255) && (y1 + 27 >= y))
                return 2;
        }
        else if (lastMovingState == 1)
        {
            if ((x1 <= x + 254) && (x1 >= x) && (y1 <= y + 255) && (y1 + 27 >= y))
                return 2;
        }
    }
    else
    {
        if (lastMovingState == 0)
        {
            if ((x1 + 19 >= x) && (x1 <= x + 254) && (y1 <= y + 255) && (y1 + 12 >= y))
                return 1;
        }
        else if (lastMovingState == 1)
        {
            if ((x1 <= x + 254) && (x1 >= x) && (y1 <= y + 255) && (y1 + 12 >= y))
                return 1;
        }
    }
    return 0;
}
void RockCannon::OnMove()
{
    if (distance >= 1920)
    {
        usingState = false;
        distance = 0;
        catchAction = 0;
        x1 = 0;
        y1 = 0;
    }

    if (catchAction == 0)
        showLock = 0;

    if (usingState)
    {
        normalCannon.OnMove();
        chargeCannon.OnMove();
        superChargeCannon.OnMove();
        normalCannonLeft.OnMove();
        chargeCannonLeft.OnMove();
        superChargeCannonLeft.OnMove();

        if (nowCharge >= 60)
        {
            if (lastMovingState == 0)
            {
                x1 += velocity_cannon * 2;
                screenX += velocity_cannon * 2;
                distance += velocity_cannon * 2;
            }
            else if (lastMovingState == 1)
            {
                x1 -= velocity_cannon * 2;
                screenX -= velocity_cannon * 2;
                distance += velocity_cannon * 2;
            }
        }
        else if (nowCharge < 60)
        {
            if (lastMovingState == 0)
            {
                x1 += velocity_cannon;
                screenX += velocity_cannon;
                distance += velocity_cannon;
            }
            else if (lastMovingState == 1)
            {
                x1 -= velocity_cannon;
                screenX -= velocity_cannon;
                distance += velocity_cannon;
            }
        }
    }
}
void RockCannon::OnShow()
{
    if (showLock == 0)
        SetScreen();

    //TRACE("nowCharge:%d\n", nowCharge);
    showLock = 1;
    int tmp = x1, tmp2 = y1;

    if (x1 >= 900)
        x1 = screenX;

    if (y1 <= 2700)
        y1 = screenY;

    normalCannon.SetTopLeft(x1, y1);
    chargeCannon.SetTopLeft(x1, y1);
    superChargeCannon.SetTopLeft(x1, y1);
    normalCannonLeft.SetTopLeft(x1, y1);
    chargeCannonLeft.SetTopLeft(x1, y1);
    superChargeCannonLeft.SetTopLeft(x1, y1);

    if (lastMovingState == 0 && usingState == true)
    {
        if (nowCharge >= 60)
            superChargeCannon.OnShow();
        else if ((nowCharge < 60) && (nowCharge > 5))
            chargeCannon.OnShow();
        else
            normalCannon.OnShow();
    }
    else if (lastMovingState == 1 && usingState == true)
    {
        if (nowCharge > 60)
            superChargeCannonLeft.OnShow();
        else if ((nowCharge < 60) && (nowCharge > 5))
            chargeCannonLeft.OnShow();
        else
            normalCannonLeft.OnShow();
    }

    x1 = tmp;
    y1 = tmp2;
}
void RockCannon::LoadNormalCannonBitmap()
{
    normalCannon.AddBitmap("RES\\attack\\attack.bmp", RGB(255, 255, 255));
}
void RockCannon::LoadChargeCannonBitmap()
{
    chargeCannon.AddBitmap("RES\\attack\\charge1 attack.bmp", RGB(255, 255, 255));
}
void RockCannon::LoadSuperChargeCannonBitmap()
{
    superChargeCannon.AddBitmap("RES\\attack\\charge attack.bmp", RGB(255, 255, 255));
    superChargeCannon.AddBitmap("RES\\attack\\charge attack2.bmp", RGB(255, 255, 255));
    superChargeCannon.AddBitmap("RES\\attack\\charge attack3.bmp", RGB(255, 255, 255));
    superChargeCannon.AddBitmap("RES\\attack\\charge attack4.bmp", RGB(255, 255, 255));
}
void RockCannon::LoadNormalCannonLeftBitmap()
{
    normalCannonLeft.AddBitmap("RES\\attack\\attack left.bmp", RGB(255, 255, 255));
}
void RockCannon::LoadChargeCannonLeftBitmap()
{
    chargeCannonLeft.AddBitmap("RES\\attack\\charge1 attack left.bmp", RGB(255, 255, 255));
}
void RockCannon::LoadSuperChargeCannonLeftBitmap()
{
    superChargeCannonLeft.AddBitmap("RES\\attack\\charge attack left.bmp", RGB(255, 255, 255));
    superChargeCannonLeft.AddBitmap("RES\\attack\\charge attack left2.bmp", RGB(255, 255, 255));
    superChargeCannonLeft.AddBitmap("RES\\attack\\charge attack left3.bmp", RGB(255, 255, 255));
    superChargeCannonLeft.AddBitmap("RES\\attack\\charge attack left4.bmp", RGB(255, 255, 255));
}
}