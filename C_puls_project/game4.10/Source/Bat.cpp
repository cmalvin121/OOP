#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Bat.h"

namespace game_framework
{
Bat::Bat()
{}
void Bat::Initialize()
{
    x = y = 0;
    s_x = s_y = 0;
    life = 4;
    isAlive = true;
    AttackDirection = 0;
    monsBoom.Reset();
    AttackMode = 0;
}
void Bat::LoadBitMap()
{
    LoadMovingRightBitMap();
    LoadMovingLeftBitMap();
    LoadBoomBitmap();
}
void Bat::LoadMovingRightBitMap()
{
    monsMovingRight.AddBitmap("RES\\enemy\\batmoving.bmp", RGB(255, 255, 255));
    monsMovingRight.AddBitmap("RES\\enemy\\batmoving2.bmp", RGB(255, 255, 255));
    monsMovingRight.AddBitmap("RES\\enemy\\batmoving3.bmp", RGB(255, 255, 255));
    monsMovingRight.AddBitmap("RES\\enemy\\batmoving4.bmp", RGB(255, 255, 255));
    monsMovingRight.AddBitmap("RES\\enemy\\batmoving5.bmp", RGB(255, 255, 255));
    monsMovingRight.AddBitmap("RES\\enemy\\batmoving6.bmp", RGB(255, 255, 255));
    monsMovingRight.SetDelayCount(2);
}
void Bat::LoadMovingLeftBitMap()
{
    monsMovingLeft.AddBitmap("RES\\enemy\\batmovingleft.bmp", RGB(255, 255, 255));
    monsMovingLeft.AddBitmap("RES\\enemy\\batmoving2left.bmp", RGB(255, 255, 255));
    monsMovingLeft.AddBitmap("RES\\enemy\\batmoving3left.bmp", RGB(255, 255, 255));
    monsMovingLeft.AddBitmap("RES\\enemy\\batmoving4left.bmp", RGB(255, 255, 255));
    monsMovingLeft.AddBitmap("RES\\enemy\\batmoving5left.bmp", RGB(255, 255, 255));
    monsMovingLeft.AddBitmap("RES\\enemy\\batmoving6left.bmp", RGB(255, 255, 255));
    monsMovingLeft.SetDelayCount(2);
}
void Bat::LoadBoomBitmap()
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
void Bat::setXY(int nx, int ny)
{
    x = nx;
    y = ny;
}
void Bat::setScreenXY(int nx, int ny)
{
    s_x = nx;
    s_y = ny;
}
void Bat::setAlive(bool state)
{
    isAlive = state;
}
int Bat::getX()
{
    return x;
}
int Bat::getY()
{
    return y;
}
int Bat::getScreenX()
{
    return s_x;
}

int Bat::getScreenY()
{
    return s_y;
}
bool Bat::getAlive()
{
    return isAlive;
}
int Bat::getLife()
{
    return life;
}
void Bat::deductLife(int damage)
{
    life -= damage;

    if (life <= 0)
        isAlive = false;
}
void Bat::moveAttack(int RockX, int RockY)
{
    if (RockX <= x)
        x -= 30;
    else if (RockX > x)
        x += 30;

    if (RockY <= y)
        y -= 20;
    else if (RockY > y)
        y += 20;
}
void Bat::DeterminAttack(int RockX, int RockY)
{
    monsMovingRight.OnMove();
    monsMovingLeft.OnMove();

    if (((RockX - x) < 1000 && (RockX - x) > 0) || ((x - RockX) < 1000 && (x - RockX) > 0) || AttackMode == 1)
    {
        AttackMode = 1;

        if (isAlive)
            moveAttack(RockX, RockY);
    }

    if (x - RockX > 0)
        AttackDirection = 0;
    else if (RockX - x > 0)
        AttackDirection = 1;
}
bool Bat::MonsterCollision(int RockX, int RockY)
{
    if (!isAlive)
        return false;
    else if (x + 120 > RockX && RockX + 160 > x && y + 160 > RockY && RockY > y)
        return true;
    else
        return false;
}
void Bat::OnShow()
{
    if (AttackDirection == 0)
    {
        monsMovingRight.SetTopLeft(x + s_x, y + s_y - 1492);
        monsMovingRight.OnShow();
    }
    else if (AttackDirection == 1)
    {
        monsMovingLeft.SetTopLeft(x + s_x, y + s_y - 1492);
        monsMovingLeft.OnShow();
    }
}
void Bat::OnShowBoom()
{
    if (monsBoom.IsFinalBitmap())
        monsBoom.setToSpecifyBitmap(7);

    monsBoom.OnMove();
    monsBoom.SetTopLeft(x + s_x, y + s_y - 1492);

    if (isAlive == false && !monsBoom.IsFinalBitmap())
        monsBoom.OnShow();
}
}