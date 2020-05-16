#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Rockcannon.h"
#include "Rockman.h"
namespace game_framework
{
Rockman::Rockman()
{
    x = y = 0;
}
void Rockman::Initialize()
{
    const int X_POS = 320;
    const int Y_POS = 1880;
    x = X_POS;
    y = Y_POS;
    isMovingLeft = isMovingRight = false;
    lastMovingState = 0;
    jumpDegree = 0;
    isJumping = isSprinting = false;
    initial_velocity_jump = 20;
    velocity_jump = initial_velocity_jump;
    sprintDegree = 0;
    keepkeydownSprinting = false;
    initial_velocity_sprint = 14;
    velocity_sprint = initial_velocity_sprint;
    isAttacking = false;
    keepkeydownAttacking = false;
    chargeAttack = 0;
    charge = 0;
    determineCharge = 0;
    attackActionDelay = 0;
    isInjured = false;
    initial_velocity_drop = 30;
    velocity_drop = initial_velocity_drop;
    crashState = 1;
    crashState_wall = 0;
    kickWallDegree = 0;
    isKickWall = false;
    isKickWallSlide = false;
    life = 64;

    for (int i = 0; i < 20; i++)
        rockcannon[i].SetUsingState(false);
}
void Rockman::JumpDropping()
{
    if (jumpDegree < 5)
        velocity_jump -= 10;
    else if (jumpDegree >= 5)
        velocity_jump += 10;

    y += velocity_jump;
    jumpDegree--;
}
void Rockman::KickWall()
{
    if (lastMovingState == 1) //½ðÀð:¥ª
    {
        x += 20;

        if (keepkeydownSprinting)
            x += 40;

        kickWallDegree++;
    }

    if (lastMovingState == 0)//½ðÀð:¥k
    {
        x -= 20;

        if (keepkeydownSprinting)
            x -= 40;

        kickWallDegree++;
    }
}
void Rockman::setkickWall()//½ðÀð
{
    if (kickWallDegree == 4)
    {
        kickWallDegree = 0;
        isKickWall = false;
    }

    if (crashState_wall > 0 && isJumping)
    {
        isKickWall = true;
    }
}
bool Rockman::showDropping()
{
    if (((!isJumping) && (jumpDegree >= 3)) || isDropping)
        return true;

    return false;
}
void Rockman::OnMove()
{
    const int STEP_SIZE = 20;
    isInjured = false;
    animationRight.OnMove();
    animationLeft.OnMove();
    animationMovingRight.OnMove();
    animationMovingLeft.OnMove();
    animation_jumpRight.OnMove();
    animation_jumpLeft.OnMove();
    animation_sprintLeft.OnMove();
    animation_sprintRight.OnMove();
    animation_kickWallLeft.OnMove();
    animation_kickWallRight.OnMove();
    animation_kickWallSlideLeft.OnMove();
    animation_kickWallSlideRight.OnMove();
    animationRightAttack.OnMove();
    animationLeftAttack.OnMove();
    animationMovingRightAttack.OnMove();
    animationMovingLeftAttack.OnMove();
    animation_jumpRightAttack.OnMove();
    animation_jumpLeftAttack.OnMove();
    animation_sprintLeftAttack.OnMove();
    animation_sprintRightAttack.OnMove();
    animation_kickWallLeftAttack.OnMove();
    animation_kickWallRightAttack.OnMove();
    animation_kickWallSlideLeftAttack.OnMove();
    animation_kickWallSlideRightAttack.OnMove();

    if ((isSprinting) && (sprintDegree < 20) && (jumpDegree == 0) && (crashState_wall == 0) && (!isKickWall)) //½Ä¨ë
    {
        if (lastMovingState == 0)
            x += velocity_sprint;
        else if (lastMovingState == 1)
            x -= velocity_sprint;

        if (sprintDegree < 8)
            velocity_sprint += 7;
        else
            velocity_sprint -= 7;

        sprintDegree++;

        if (sprintDegree == 20)
            isSprinting = false;
    }
    else
    {
        isSprinting = false;
    }

    if ((!isSprinting) && (sprintDegree > 0))//½Ä¨ëµ²§ô«á¡A­«¸m½Ä¨ë³t«×¡C
    {
        sprintDegree = 0;
        velocity_sprint = initial_velocity_sprint;
    }

    if ((isMovingLeft) && (x >= 0) && !isKickWall)//©¹¥ª²¾°Ê
    {
        if ((keepkeydownSprinting) && (jumpDegree > 0))//¼u®g¸õÅD
            x -= STEP_SIZE * 3;
        else if (!isSprinting)//©¹¥ª²¾°Ê
            x -= STEP_SIZE;
    }
    else if ((isInjured) && (isMovingLeft))//¸I¼²¨ì©Çª««á¡A¸}¦â©¹«á°h
    {
        x += STEP_SIZE * 5;
    }

    if (isMovingRight && !isKickWall) //©¹¥k²¾°Ê
    {
        if ((keepkeydownSprinting) && (jumpDegree > 0))//¼u®g¸õÅD
            x += STEP_SIZE * 3;
        else if (!isSprinting)//©¹¥k²¾°Ê
            x += STEP_SIZE;
    }
    else if ((isInjured) && (isMovingRight))//¸I¼²¨ì©Çª««á¡A¸}¦â©¹«á°h
    {
        x -= STEP_SIZE * 5;
    }

    if ((isJumping) && (jumpDegree < 10))//¸õÅD
    {
        y -= velocity_jump;

        if (jumpDegree < 4)
            velocity_jump += 10;
        else if (jumpDegree >= 4)
            velocity_jump -= 10;

        jumpDegree++;

        if (jumpDegree == 10)
            isJumping = false;
    }

    if ((!isJumping) && (jumpDegree > 0))//¸õÅD¸¨¤U¡BÂHÀð·Æ¸¨¡C
    {
        if (crashState_wall != 0)
        {
            jumpDegree = 0;
            velocity_jump = initial_velocity_jump;
            isKickWallSlide = true;
        }
        else
        {
            JumpDropping();
            isKickWallSlide = false;
        }
    }

    Dropping();
    isAlreadyOnGround();

    if (isKickWall)
        KickWall();

    setkickWall();

    if (keepkeydownAttacking)
    {
        if (determineCharge <= 60)
            determineCharge++;

        if (determineCharge > 5)
            charge = determineCharge;
    }
}

void Rockman::SetMovingLeft(bool flag)
{
    isMovingLeft = flag;

    if (flag == true)
        lastMovingState = 1;
}
void Rockman::SetMovingRight(bool flag)
{
    isMovingRight = flag;

    if (flag == true)
        lastMovingState = 0;
}
int Rockman::GetJumpDegree()
{
    return jumpDegree;
}
int Rockman::GetSprintDegree()
{
    return sprintDegree;
}
int Rockman::GetCharge()
{
    return charge;
}
void Rockman::SetJumping(bool flag)
{
    animation_jumpRight.Reset();
    animation_jumpLeft.Reset();
    animation_jumpRightAttack.Reset();
    animation_jumpLeftAttack.Reset();
    isJumping = flag;
}
//------------------------------------------
void Rockman::SetCrashState(int state)
{
    //TRACE("crashstate:%d\n", state);
    crashState = state;
}
void Rockman::SetCrashStateWall(int state)
{
    crashState_wall = state;

    if (crashState_wall != 0)
    {
        if (jumpDegree == 1)
        {
            animation_kickWallLeft.Reset();
            animation_kickWallRight.Reset();
            animation_kickWallLeftAttack.Reset();
            animation_kickWallRightAttack.Reset();
        }

        if (!isMovingLeft)
        {
            animation_kickWallSlideLeft.Reset();
            animation_kickWallSlideLeftAttack.Reset();
        }

        if (!isMovingRight)
        {
            animation_kickWallSlideRight.Reset();
            animation_kickWallSlideRightAttack.Reset();
        }
    }
}
void Rockman::Dropping()
{
    if (crashState == 0)
        isDropping = true;
    else if (crashState == 1)
        isDropping = false;
}
bool Rockman::GetDropping()
{
    if (crashState_wall != 0)
        isDropping = false;

    return isDropping;
}
void Rockman::isAlreadyOnGround()
{
    if (isDropping)
    {
        if ((crashState == 1) && (jumpDegree == 0))
        {
            isDropping = false;
            dropDegree = 0;
            velocity_drop = initial_velocity_drop;
        }
        else if ((crashState_wall != 0) && (jumpDegree == 0))//½ðÀð·Æ¸¨
        {
            y += 10;
        }
        else if ((crashState == 0) && (jumpDegree == 0))
        {
            y += velocity_drop;
            dropDegree++;

            if (velocity_drop < 60)
                velocity_drop += 10;
        }
    }
}
//------------------------------------------
void Rockman::SetSprinting(bool flag)
{
    animation_sprintRight.Reset();
    animation_sprintLeft.Reset();
    animation_sprintRightAttack.Reset();
    animation_sprintLeftAttack.Reset();
    isSprinting = flag;
}
void Rockman::SetKeySprintState(bool flag)
{
    keepkeydownSprinting = flag;
}
void Rockman::SetAttacking(bool flag)
{
    isAttacking = flag;
}
void Rockman::SetKeyAttackingState(bool flag)
{
    keepkeydownAttacking = flag;

    if ((charge == 0) && (chargeAttack > 0))
        chargeAttack = 0;

    if (flag == false)
    {
        chargeAttack = charge;
        charge = 0;
        determineCharge = 0;

        if (!((isAttacking) && (charge == 0)) || (chargeAttack > 5))
        {
            if (lastMovingState == 0)
            {
                if (chargeAttack > 60)
                    setCannon(x + 170, y, 0);
                else
                    setCannon(x + 170, y + 84, 0);
            }
            else if (lastMovingState == 1)
            {
                if (chargeAttack > 60)
                    setCannon(x - 222, y, 1);
                else
                    setCannon(x, y + 84, 1);
            }
        }
    }
}
void Rockman::SetFixCannonScreenY(int fixY)
{
    for (int i = 0; i < 20; i++)
    {
        if (rockcannon[i].GetUsingState() == true)
            rockcannon[i].SetFixScreenY(fixY);
    }
}
void Rockman::setCannon(int x, int y, int lastMovingState)
{
    for (int i = 0; i < 20; i++)
    {
        if (rockcannon[i].GetUsingState() == false)
        {
            //TRACE("\n\n%d  %d\n\n", x, y);				//¶Çªº®y¼Ð
            rockcannon[i].SetUsingState(true);

            if (isKickWallSlide)
            {
                if (lastMovingState == 0)
                    rockcannon[i].SetLastMovingState(1);
                else if (lastMovingState == 1)
                    rockcannon[i].SetLastMovingState(0);
            }
            else
                rockcannon[i].SetLastMovingState(lastMovingState);

            rockcannon[i].SetX(x);
            rockcannon[i].SetY(y);
            rockcannon[i].SetCatchAction(1);
            rockcannon[i].SetNowCharge(chargeAttack);
            break;
        }
    }
}
bool Rockman::getInjuredState()
{
    return isInjured;
}
RockCannon* Rockman::getCannon()
{
    return rockcannon;
}
int Rockman::Getlife()
{
    return life;
}
//------------------------------------------
int Rockman::GetX()
{
    return x;
}

int Rockman::GetY()
{
    return y;
}
void Rockman::SetX(int X_BT)
{
    x = X_BT;
}

void Rockman::SetY(int Y_BT)
{
    y = Y_BT;
}
//------------------------------------------
void Rockman::LoadLifeObjectBitmap()
{
    lifeItem.LoadBitmapA("RES\\life\\life_item.bmp", RGB(255, 255, 255));
    lifeValue.LoadBitmapA("RES\\life\\life_value.bmp", RGB(255, 255, 255));
}
void Rockman::LoadRightBitmap()
{
    animationRight.AddBitmap("RES\\super armor.bmp", RGB(255, 255, 255));
    animationRight.AddBitmap("RES\\super armor2.bmp", RGB(255, 255, 255));
    animationRight.AddBitmap("RES\\super armor3.bmp", RGB(255, 255, 255));
    animationRight.AddBitmap("RES\\super armor4.bmp", RGB(255, 255, 255));
    animationRight.AddBitmap("RES\\super armor5.bmp", RGB(255, 255, 255));
    animationRight.SetDelayCount(4);
}
void Rockman::LoadLeftBitmap()
{
    animationLeft.AddBitmap("RES\\super armor left.bmp", RGB(255, 255, 255));
    animationLeft.AddBitmap("RES\\super armor left2.bmp", RGB(255, 255, 255));
    animationLeft.AddBitmap("RES\\super armor left3.bmp", RGB(255, 255, 255));
    animationLeft.AddBitmap("RES\\super armor left4.bmp", RGB(255, 255, 255));
    animationLeft.AddBitmap("RES\\super armor left5.bmp", RGB(255, 255, 255));
    animationLeft.SetDelayCount(4);
}
void Rockman::LoadMovingLeftBitmap()
{
    animationMovingLeft.AddBitmap("RES\\super armor movingleft.bmp", RGB(255, 255, 255));
    animationMovingLeft.AddBitmap("RES\\super armor movingleft2.bmp", RGB(255, 255, 255));
    animationMovingLeft.AddBitmap("RES\\super armor movingleft3.bmp", RGB(255, 255, 255));
    animationMovingLeft.AddBitmap("RES\\super armor movingleft4.bmp", RGB(255, 255, 255));
    animationMovingLeft.AddBitmap("RES\\super armor movingleft5.bmp", RGB(255, 255, 255));
    animationMovingLeft.AddBitmap("RES\\super armor movingleft6.bmp", RGB(255, 255, 255));
    animationMovingLeft.AddBitmap("RES\\super armor movingleft7.bmp", RGB(255, 255, 255));
    animationMovingLeft.AddBitmap("RES\\super armor movingleft8.bmp", RGB(255, 255, 255));
    animationMovingLeft.AddBitmap("RES\\super armor movingleft9.bmp", RGB(255, 255, 255));
    animationMovingLeft.SetDelayCount(2);
}
void Rockman::LoadMovingRightBitmap()
{
    animationMovingRight.AddBitmap("RES\\super armor moving.bmp", RGB(255, 255, 255));
    animationMovingRight.AddBitmap("RES\\super armor moving2.bmp", RGB(255, 255, 255));
    animationMovingRight.AddBitmap("RES\\super armor moving3.bmp", RGB(255, 255, 255));
    animationMovingRight.AddBitmap("RES\\super armor moving4.bmp", RGB(255, 255, 255));
    animationMovingRight.AddBitmap("RES\\super armor moving5.bmp", RGB(255, 255, 255));
    animationMovingRight.AddBitmap("RES\\super armor moving6.bmp", RGB(255, 255, 255));
    animationMovingRight.AddBitmap("RES\\super armor moving7.bmp", RGB(255, 255, 255));
    animationMovingRight.AddBitmap("RES\\super armor moving8.bmp", RGB(255, 255, 255));
    animationMovingRight.AddBitmap("RES\\super armor moving9.bmp", RGB(255, 255, 255));
    animationMovingRight.SetDelayCount(2);
}
void Rockman::LoadJumpingLeftBitmap()
{
    animation_jumpLeft.AddBitmap("RES\\super armor jumpleft.bmp", RGB(255, 255, 255));
    animation_jumpLeft.AddBitmap("RES\\super armor jumpleft2.bmp", RGB(255, 255, 255));
    animation_jumpLeft.AddBitmap("RES\\super armor jumpleft3.bmp", RGB(255, 255, 255));
    animation_jumpLeft.AddBitmap("RES\\super armor jumpleft4.bmp", RGB(255, 255, 255));
    animation_jumpLeft.AddBitmap("RES\\super armor jumpleft5.bmp", RGB(255, 255, 255));
    animation_jumpLeft.AddBitmap("RES\\super armor jumpleft6.bmp", RGB(255, 255, 255));
    animation_jumpLeft.AddBitmap("RES\\super armor jumpleft7.bmp", RGB(255, 255, 255));
    animation_jumpLeft.AddBitmap("RES\\super armor jumpleft8.bmp", RGB(255, 255, 255));
    animation_jumpLeft.AddBitmap("RES\\super armor jumpleft9.bmp", RGB(255, 255, 255));
    animation_jumpLeft.AddBitmap("RES\\super armor jumpleft10.bmp", RGB(255, 255, 255));
    animation_jumpLeft.AddBitmap("RES\\super armor jumpleft11.bmp", RGB(255, 255, 255));
    animation_jumpLeft.SetDelayCount(2);
}
void Rockman::LoadJumpingRightBitmap()
{
    animation_jumpRight.AddBitmap("RES\\super armor jump.bmp", RGB(255, 255, 255));
    animation_jumpRight.AddBitmap("RES\\super armor jump2.bmp", RGB(255, 255, 255));
    animation_jumpRight.AddBitmap("RES\\super armor jump3.bmp", RGB(255, 255, 255));
    animation_jumpRight.AddBitmap("RES\\super armor jump4.bmp", RGB(255, 255, 255));
    animation_jumpRight.AddBitmap("RES\\super armor jump5.bmp", RGB(255, 255, 255));
    animation_jumpRight.AddBitmap("RES\\super armor jump6.bmp", RGB(255, 255, 255));
    animation_jumpRight.AddBitmap("RES\\super armor jump7.bmp", RGB(255, 255, 255));
    animation_jumpRight.AddBitmap("RES\\super armor jump8.bmp", RGB(255, 255, 255));
    animation_jumpRight.AddBitmap("RES\\super armor jump9.bmp", RGB(255, 255, 255));
    animation_jumpRight.AddBitmap("RES\\super armor jump10.bmp", RGB(255, 255, 255));
    animation_jumpRight.AddBitmap("RES\\super armor jump11.bmp", RGB(255, 255, 255));
    animation_jumpRight.SetDelayCount(2);
}
void Rockman::LoadSprintingLeftBitmap()
{
    animation_sprintLeft.AddBitmap("RES\\super armor sprintingleft.bmp", RGB(255, 255, 255));
    animation_sprintLeft.AddBitmap("RES\\super armor sprintingleft2.bmp", RGB(255, 255, 255));
    animation_sprintLeft.AddBitmap("RES\\super armor sprintingleft3.bmp", RGB(255, 255, 255));
    animation_sprintLeft.AddBitmap("RES\\super armor sprintingleft4.bmp", RGB(255, 255, 255));
    animation_sprintLeft.AddBitmap("RES\\super armor sprintingleft4.bmp", RGB(255, 255, 255));
    animation_sprintLeft.AddBitmap("RES\\super armor sprintingleft4.bmp", RGB(255, 255, 255));
    animation_sprintLeft.AddBitmap("RES\\super armor sprintingleft4.bmp", RGB(255, 255, 255));
    animation_sprintLeft.AddBitmap("RES\\super armor sprintingleft5.bmp", RGB(255, 255, 255));
    animation_sprintLeft.AddBitmap("RES\\super armor sprintingleft6.bmp", RGB(255, 255, 255));
    animation_sprintLeft.AddBitmap("RES\\super armor sprintingleft7.bmp", RGB(255, 255, 255));
    animation_sprintLeft.AddBitmap("RES\\super armor sprintingleft8.bmp", RGB(255, 255, 255));
    animation_sprintLeft.SetDelayCount(2);
}
void Rockman::LoadSprintingRightBitmap()
{
    animation_sprintRight.AddBitmap("RES\\super armor sprinting.bmp", RGB(255, 255, 255));
    animation_sprintRight.AddBitmap("RES\\super armor sprinting2.bmp", RGB(255, 255, 255));
    animation_sprintRight.AddBitmap("RES\\super armor sprinting3.bmp", RGB(255, 255, 255));
    animation_sprintRight.AddBitmap("RES\\super armor sprinting4.bmp", RGB(255, 255, 255));
    animation_sprintRight.AddBitmap("RES\\super armor sprinting4.bmp", RGB(255, 255, 255));
    animation_sprintRight.AddBitmap("RES\\super armor sprinting4.bmp", RGB(255, 255, 255));
    animation_sprintRight.AddBitmap("RES\\super armor sprinting4.bmp", RGB(255, 255, 255));
    animation_sprintRight.AddBitmap("RES\\super armor sprinting5.bmp", RGB(255, 255, 255));
    animation_sprintRight.AddBitmap("RES\\super armor sprinting6.bmp", RGB(255, 255, 255));
    animation_sprintRight.AddBitmap("RES\\super armor sprinting7.bmp", RGB(255, 255, 255));
    animation_sprintRight.AddBitmap("RES\\super armor sprinting8.bmp", RGB(255, 255, 255));
    animation_sprintRight.SetDelayCount(2);
}
void Rockman::LoadKickWallLeftBitmap()
{
    animation_kickWallLeft.AddBitmap("RES\\super armor kickwallleft.bmp", RGB(255, 255, 255));
    animation_kickWallLeft.AddBitmap("RES\\super armor kickwall5left.bmp", RGB(255, 255, 255));
    animation_kickWallLeft.AddBitmap("RES\\super armor kickwall6left.bmp", RGB(255, 255, 255));
    animation_kickWallLeft.AddBitmap("RES\\super armor jumpleft4.bmp", RGB(255, 255, 255));
    animation_kickWallLeft.SetDelayCount(2);
}
void Rockman::LoadKickWallRightBitmap()
{
    animation_kickWallRight.AddBitmap("RES\\super armor kickwall.bmp", RGB(255, 255, 255));
    animation_kickWallRight.AddBitmap("RES\\super armor kickwall5.bmp", RGB(255, 255, 255));
    animation_kickWallRight.AddBitmap("RES\\super armor kickwall6.bmp", RGB(255, 255, 255));
    animation_kickWallRight.AddBitmap("RES\\super armor jump4.bmp", RGB(255, 255, 255));
    animation_kickWallRight.SetDelayCount(2);
}
void Rockman::LoadKickWallSlideLeftBitmap()
{
    animation_kickWallSlideLeft.AddBitmap("RES\\super armor kickwallleft.bmp", RGB(255, 255, 255));
    animation_kickWallSlideLeft.AddBitmap("RES\\super armor kickwall2left.bmp", RGB(255, 255, 255));
    animation_kickWallSlideLeft.AddBitmap("RES\\super armor kickwall3left.bmp", RGB(255, 255, 255));
    animation_kickWallSlideLeft.AddBitmap("RES\\super armor kickwall4left.bmp", RGB(255, 255, 255));
    animation_kickWallSlideLeft.SetDelayCount(2);
}
void Rockman::LoadKickWallSlideRightBitmap()
{
    animation_kickWallSlideRight.AddBitmap("RES\\super armor kickwall.bmp", RGB(255, 255, 255));
    animation_kickWallSlideRight.AddBitmap("RES\\super armor kickwall2.bmp", RGB(255, 255, 255));
    animation_kickWallSlideRight.AddBitmap("RES\\super armor kickwall3.bmp", RGB(255, 255, 255));
    animation_kickWallSlideRight.AddBitmap("RES\\super armor kickwall4.bmp", RGB(255, 255, 255));
    animation_kickWallSlideRight.SetDelayCount(2);
}
void Rockman::LoadBitmap()
{
    LoadLifeObjectBitmap();
    LoadRightBitmap();
    LoadLeftBitmap();
    LoadMovingLeftBitmap();
    LoadMovingRightBitmap();
    LoadJumpingLeftBitmap();
    LoadJumpingRightBitmap();
    LoadSprintingLeftBitmap();
    LoadSprintingRightBitmap();
    LoadKickWallLeftBitmap();
    LoadKickWallRightBitmap();
    LoadKickWallSlideLeftBitmap();
    LoadKickWallSlideRightBitmap();
}
void Rockman::LoadRightAttackBitmap()
{
    animationRightAttack.AddBitmap("RES\\attack\\super armor.bmp", RGB(255, 255, 255));
}
void Rockman::LoadLeftAttackBitmap()
{
    animationLeftAttack.AddBitmap("RES\\attack\\super armor left.bmp", RGB(255, 255, 255));
}
void Rockman::LoadMovingLeftAttackBitmap()
{
    animationMovingLeftAttack.AddBitmap("RES\\attack\\super armor movingleft.bmp", RGB(255, 255, 255));
    animationMovingLeftAttack.AddBitmap("RES\\attack\\super armor movingleft2.bmp", RGB(255, 255, 255));
    animationMovingLeftAttack.AddBitmap("RES\\attack\\super armor movingleft3.bmp", RGB(255, 255, 255));
    animationMovingLeftAttack.AddBitmap("RES\\attack\\super armor movingleft4.bmp", RGB(255, 255, 255));
    animationMovingLeftAttack.AddBitmap("RES\\attack\\super armor movingleft5.bmp", RGB(255, 255, 255));
    animationMovingLeftAttack.AddBitmap("RES\\attack\\super armor movingleft6.bmp", RGB(255, 255, 255));
    animationMovingLeftAttack.AddBitmap("RES\\attack\\super armor movingleft7.bmp", RGB(255, 255, 255));
    animationMovingLeftAttack.AddBitmap("RES\\attack\\super armor movingleft8.bmp", RGB(255, 255, 255));
    animationMovingLeftAttack.AddBitmap("RES\\attack\\super armor movingleft9.bmp", RGB(255, 255, 255));
    animationMovingLeftAttack.SetDelayCount(2);
}
void Rockman::LoadMovingRightAttackBitmap()
{
    animationMovingRightAttack.AddBitmap("RES\\attack\\super armor moving.bmp", RGB(255, 255, 255));
    animationMovingRightAttack.AddBitmap("RES\\attack\\super armor moving2.bmp", RGB(255, 255, 255));
    animationMovingRightAttack.AddBitmap("RES\\attack\\super armor moving3.bmp", RGB(255, 255, 255));
    animationMovingRightAttack.AddBitmap("RES\\attack\\super armor moving4.bmp", RGB(255, 255, 255));
    animationMovingRightAttack.AddBitmap("RES\\attack\\super armor moving5.bmp", RGB(255, 255, 255));
    animationMovingRightAttack.AddBitmap("RES\\attack\\super armor moving6.bmp", RGB(255, 255, 255));
    animationMovingRightAttack.AddBitmap("RES\\attack\\super armor moving7.bmp", RGB(255, 255, 255));
    animationMovingRightAttack.AddBitmap("RES\\attack\\super armor moving8.bmp", RGB(255, 255, 255));
    animationMovingRightAttack.AddBitmap("RES\\attack\\super armor moving9.bmp", RGB(255, 255, 255));
    animationMovingRightAttack.SetDelayCount(2);
}
void Rockman::LoadJumpingLeftAttackBitmap()
{
    animation_jumpLeftAttack.AddBitmap("RES\\attack\\super armor jumpleft.bmp", RGB(255, 255, 255));
    animation_jumpLeftAttack.AddBitmap("RES\\attack\\super armor jumpleft2.bmp", RGB(255, 255, 255));
    animation_jumpLeftAttack.AddBitmap("RES\\attack\\super armor jumpleft3.bmp", RGB(255, 255, 255));
    animation_jumpLeftAttack.AddBitmap("RES\\attack\\super armor jumpleft4.bmp", RGB(255, 255, 255));
    animation_jumpLeftAttack.AddBitmap("RES\\attack\\super armor jumpleft5.bmp", RGB(255, 255, 255));
    animation_jumpLeftAttack.AddBitmap("RES\\attack\\super armor jumpleft6.bmp", RGB(255, 255, 255));
    animation_jumpLeftAttack.AddBitmap("RES\\attack\\super armor jumpleft7.bmp", RGB(255, 255, 255));
    animation_jumpLeftAttack.AddBitmap("RES\\attack\\super armor jumpleft8.bmp", RGB(255, 255, 255));
    animation_jumpLeftAttack.AddBitmap("RES\\attack\\super armor jumpleft9.bmp", RGB(255, 255, 255));
    animation_jumpLeftAttack.AddBitmap("RES\\attack\\super armor jumpleft10.bmp", RGB(255, 255, 255));
    animation_jumpLeftAttack.AddBitmap("RES\\attack\\super armor jumpleft11.bmp", RGB(255, 255, 255));
    animation_jumpLeftAttack.SetDelayCount(2);
}
void Rockman::LoadJumpingRightAttackBitmap()
{
    animation_jumpRightAttack.AddBitmap("RES\\attack\\super armor jump.bmp", RGB(255, 255, 255));
    animation_jumpRightAttack.AddBitmap("RES\\attack\\super armor jump2.bmp", RGB(255, 255, 255));
    animation_jumpRightAttack.AddBitmap("RES\\attack\\super armor jump3.bmp", RGB(255, 255, 255));
    animation_jumpRightAttack.AddBitmap("RES\\attack\\super armor jump4.bmp", RGB(255, 255, 255));
    animation_jumpRightAttack.AddBitmap("RES\\attack\\super armor jump5.bmp", RGB(255, 255, 255));
    animation_jumpRightAttack.AddBitmap("RES\\attack\\super armor jump6.bmp", RGB(255, 255, 255));
    animation_jumpRightAttack.AddBitmap("RES\\attack\\super armor jump7.bmp", RGB(255, 255, 255));
    animation_jumpRightAttack.AddBitmap("RES\\attack\\super armor jump8.bmp", RGB(255, 255, 255));
    animation_jumpRightAttack.AddBitmap("RES\\attack\\super armor jump9.bmp", RGB(255, 255, 255));
    animation_jumpRightAttack.AddBitmap("RES\\attack\\super armor jump10.bmp", RGB(255, 255, 255));
    animation_jumpRightAttack.AddBitmap("RES\\attack\\super armor jump11.bmp", RGB(255, 255, 255));
    animation_jumpRightAttack.SetDelayCount(2);
}
void Rockman::LoadSprintingLeftAttackBitmap()
{
    animation_sprintLeftAttack.AddBitmap("RES\\attack\\super armor sprintingleft.bmp", RGB(255, 255, 255));
    animation_sprintLeftAttack.AddBitmap("RES\\attack\\super armor sprintingleft2.bmp", RGB(255, 255, 255));
    animation_sprintLeftAttack.AddBitmap("RES\\attack\\super armor sprintingleft3.bmp", RGB(255, 255, 255));
    animation_sprintLeftAttack.AddBitmap("RES\\attack\\super armor sprintingleft4.bmp", RGB(255, 255, 255));
    animation_sprintLeftAttack.AddBitmap("RES\\attack\\super armor sprintingleft4.bmp", RGB(255, 255, 255));
    animation_sprintLeftAttack.AddBitmap("RES\\attack\\super armor sprintingleft4.bmp", RGB(255, 255, 255));
    animation_sprintLeftAttack.AddBitmap("RES\\attack\\super armor sprintingleft4.bmp", RGB(255, 255, 255));
    animation_sprintLeftAttack.AddBitmap("RES\\attack\\super armor sprintingleft5.bmp", RGB(255, 255, 255));
    animation_sprintLeftAttack.AddBitmap("RES\\attack\\super armor sprintingleft6.bmp", RGB(255, 255, 255));
    animation_sprintLeftAttack.AddBitmap("RES\\attack\\super armor sprintingleft7.bmp", RGB(255, 255, 255));
    animation_sprintLeftAttack.AddBitmap("RES\\attack\\super armor sprintingleft8.bmp", RGB(255, 255, 255));
    animation_sprintLeftAttack.SetDelayCount(2);
}
void Rockman::LoadSprintingRightAttackBitmap()
{
    animation_sprintRightAttack.AddBitmap("RES\\attack\\super armor sprinting.bmp", RGB(255, 255, 255));
    animation_sprintRightAttack.AddBitmap("RES\\attack\\super armor sprinting2.bmp", RGB(255, 255, 255));
    animation_sprintRightAttack.AddBitmap("RES\\attack\\super armor sprinting3.bmp", RGB(255, 255, 255));
    animation_sprintRightAttack.AddBitmap("RES\\attack\\super armor sprinting4.bmp", RGB(255, 255, 255));
    animation_sprintRightAttack.AddBitmap("RES\\attack\\super armor sprinting4.bmp", RGB(255, 255, 255));
    animation_sprintRightAttack.AddBitmap("RES\\attack\\super armor sprinting4.bmp", RGB(255, 255, 255));
    animation_sprintRightAttack.AddBitmap("RES\\attack\\super armor sprinting4.bmp", RGB(255, 255, 255));
    animation_sprintRightAttack.AddBitmap("RES\\attack\\super armor sprinting5.bmp", RGB(255, 255, 255));
    animation_sprintRightAttack.AddBitmap("RES\\attack\\super armor sprinting6.bmp", RGB(255, 255, 255));
    animation_sprintRightAttack.AddBitmap("RES\\attack\\super armor sprinting7.bmp", RGB(255, 255, 255));
    animation_sprintRightAttack.AddBitmap("RES\\attack\\super armor sprinting8.bmp", RGB(255, 255, 255));
    animation_sprintRightAttack.SetDelayCount(2);
}
void Rockman::LoadKickWallLeftAttackBitmap()
{
    animation_kickWallLeftAttack.AddBitmap("RES\\attack\\super armor kickwallleft.bmp", RGB(255, 255, 255));
    animation_kickWallLeftAttack.AddBitmap("RES\\attack\\super armor kickwall5left.bmp", RGB(255, 255, 255));
    animation_kickWallLeftAttack.AddBitmap("RES\\attack\\super armor kickwall6left.bmp", RGB(255, 255, 255));
    animation_kickWallLeftAttack.AddBitmap("RES\\attack\\super armor jumpleft4.bmp", RGB(255, 255, 255));
    animation_kickWallLeftAttack.SetDelayCount(2);
}
void Rockman::LoadKickWallRightAttackBitmap()
{
    animation_kickWallRightAttack.AddBitmap("RES\\attack\\super armor kickwall.bmp", RGB(255, 255, 255));
    animation_kickWallRightAttack.AddBitmap("RES\\attack\\super armor kickwall5.bmp", RGB(255, 255, 255));
    animation_kickWallRightAttack.AddBitmap("RES\\attack\\super armor kickwall6.bmp", RGB(255, 255, 255));
    animation_kickWallRightAttack.AddBitmap("RES\\attack\\super armor jump4.bmp", RGB(255, 255, 255));
    animation_kickWallRightAttack.SetDelayCount(2);
}
void Rockman::LoadKickWallSlideLeftAttackBitmap()
{
    animation_kickWallSlideLeftAttack.AddBitmap("RES\\attack\\super armor kickwallleft.bmp", RGB(255, 255, 255));
    animation_kickWallSlideLeftAttack.AddBitmap("RES\\attack\\super armor kickwall2left.bmp", RGB(255, 255, 255));
    animation_kickWallSlideLeftAttack.AddBitmap("RES\\attack\\super armor kickwall3left.bmp", RGB(255, 255, 255));
    animation_kickWallSlideLeftAttack.AddBitmap("RES\\attack\\super armor kickwall4left.bmp", RGB(255, 255, 255));
    animation_kickWallSlideLeftAttack.SetDelayCount(2);
}
void Rockman::LoadKickWallSlideRightAttackBitmap()
{
    animation_kickWallSlideRightAttack.AddBitmap("RES\\attack\\super armor kickwall.bmp", RGB(255, 255, 255));
    animation_kickWallSlideRightAttack.AddBitmap("RES\\attack\\super armor kickwall2.bmp", RGB(255, 255, 255));
    animation_kickWallSlideRightAttack.AddBitmap("RES\\attack\\super armor kickwall3.bmp", RGB(255, 255, 255));
    animation_kickWallSlideRightAttack.AddBitmap("RES\\attack\\super armor kickwall4.bmp", RGB(255, 255, 255));
    animation_kickWallSlideRightAttack.SetDelayCount(2);
}
void Rockman::LoadAttackBitmap()
{
    LoadRightAttackBitmap();
    LoadLeftAttackBitmap();
    LoadMovingLeftAttackBitmap();
    LoadMovingRightAttackBitmap();
    LoadJumpingLeftAttackBitmap();
    LoadJumpingRightAttackBitmap();
    LoadSprintingLeftAttackBitmap();
    LoadSprintingRightAttackBitmap();
    LoadKickWallLeftAttackBitmap();
    LoadKickWallRightAttackBitmap();
    LoadKickWallSlideLeftAttackBitmap();
    LoadKickWallSlideRightAttackBitmap();

    for (int i  = 0; i < 20; i++)
        rockcannon[i].LoadBitmap();
}
void Rockman::OnShow()
{
    int tmp = x, tmp2 = y;

    if (x >= 900)
        x = 900;

    if (y <= 2700)
        y = 380;

    animationRight.SetTopLeft(x, y);
    animationLeft.SetTopLeft(x, y);
    animationMovingRight.SetTopLeft(x, y);
    animationMovingLeft.SetTopLeft(x, y);
    animation_jumpRight.SetTopLeft(x, y);
    animation_jumpLeft.SetTopLeft(x, y);
    animation_sprintLeft.SetTopLeft(x, y);
    animation_sprintRight.SetTopLeft(x, y);
    animation_kickWallLeft.SetTopLeft(x, y);
    animation_kickWallRight.SetTopLeft(x, y);
    animation_kickWallSlideLeft.SetTopLeft(x, y);
    animation_kickWallSlideRight.SetTopLeft(x, y);
    animationRightAttack.SetTopLeft(x, y);
    animationLeftAttack.SetTopLeft(x, y);
    animationMovingRightAttack.SetTopLeft(x, y);
    animationMovingLeftAttack.SetTopLeft(x, y);
    animation_jumpRightAttack.SetTopLeft(x, y);
    animation_jumpLeftAttack.SetTopLeft(x, y);
    animation_sprintLeftAttack.SetTopLeft(x, y);
    animation_sprintRightAttack.SetTopLeft(x, y);
    animation_kickWallLeftAttack.SetTopLeft(x, y);
    animation_kickWallRightAttack.SetTopLeft(x, y);
    animation_kickWallSlideLeftAttack.SetTopLeft(x, y);
    animation_kickWallSlideRightAttack.SetTopLeft(x, y);

    if (crashState_wall == 1 && jumpDegree > 0)//½ðÀð:¥ª
    {
        if (animation_kickWallLeft.IsFinalBitmap() || animation_kickWallLeftAttack.IsFinalBitmap())
        {
            animation_kickWallLeft.setToSpecifyBitmap(3);
            animation_kickWallLeftAttack.setToSpecifyBitmap(3);
        }

        if (((isAttacking) && (charge == 0)) || (chargeAttack > 5))
        {
            animation_kickWallSlideLeftAttack.OnShow();

            if (keepkeydownAttacking == false)
                attackActionDelay++;

            if (attackActionDelay >= 20)
            {
                attackActionDelay = 0;
                chargeAttack = 0;
            }
        }
        else
            animation_kickWallLeft.OnShow();
    }
    else if (crashState_wall == 2 && jumpDegree > 0)//½ðÀð:¥k
    {
        if (animation_kickWallRight.IsFinalBitmap() || animation_kickWallRightAttack.IsFinalBitmap())
        {
            animation_kickWallRight.setToSpecifyBitmap(3);
            animation_kickWallRightAttack.setToSpecifyBitmap(3);
        }

        if (((isAttacking) && (charge == 0)) || (chargeAttack > 5))
        {
            animation_kickWallRightAttack.OnShow();

            if (keepkeydownAttacking == false)
                attackActionDelay++;

            if (attackActionDelay >= 20)
            {
                attackActionDelay = 0;
                chargeAttack = 0;
            }
        }
        else
            animation_kickWallRight.OnShow();
    }
    else if ((jumpDegree != 0) && (lastMovingState == 0))
    {
        if ((!isJumping) && (jumpDegree > 3))
        {
            animation_jumpRight.setToSpecifyBitmap(7);
            animation_jumpRightAttack.setToSpecifyBitmap(7);
        }

        if (((isAttacking) && (charge == 0)) || (chargeAttack > 5))
        {
            animation_jumpRightAttack.OnShow();

            if (keepkeydownAttacking == false)
                attackActionDelay++;

            if (attackActionDelay >= 20)
            {
                attackActionDelay = 0;
                chargeAttack = 0;
            }
        }
        else
            animation_jumpRight.OnShow();
    }
    else if ((jumpDegree != 0) && (lastMovingState == 1))
    {
        if ((!isJumping) && (jumpDegree > 3))
        {
            animation_jumpLeft.setToSpecifyBitmap(7);
            animation_jumpLeftAttack.setToSpecifyBitmap(7);
        }

        if (((isAttacking) && (charge == 0)) || (chargeAttack > 5))
        {
            animation_jumpLeftAttack.OnShow();

            if (keepkeydownAttacking == false)
                attackActionDelay++;

            if (attackActionDelay >= 20)
            {
                attackActionDelay = 0;
                chargeAttack = 0;
            }
        }
        else
            animation_jumpLeft.OnShow();
    }
    else if (crashState_wall == 1)//½ðÀð·Æ¸¨:¥ª
    {
        if (animation_kickWallSlideLeft.IsFinalBitmap() || animation_kickWallSlideLeftAttack.IsFinalBitmap())
        {
            animation_kickWallSlideLeft.setToSpecifyBitmap(3);
            animation_kickWallSlideLeftAttack.setToSpecifyBitmap(3);
        }

        if (((isAttacking) && (charge == 0)) || (chargeAttack > 5))
        {
            animation_kickWallSlideLeftAttack.OnShow();

            if (keepkeydownAttacking == false)
                attackActionDelay++;

            if (attackActionDelay >= 20)
            {
                attackActionDelay = 0;
                chargeAttack = 0;
            }
        }
        else
            animation_kickWallSlideLeft.OnShow();
    }
    else if (crashState_wall == 2)//½ðÀð·Æ¸¨:¥k
    {
        if (animation_kickWallSlideRight.IsFinalBitmap() || animation_kickWallSlideRightAttack.IsFinalBitmap())
        {
            animation_kickWallSlideRight.setToSpecifyBitmap(3);
            animation_kickWallSlideRightAttack.setToSpecifyBitmap(3);
        }

        if (((isAttacking) && (charge == 0)) || (chargeAttack > 5))
        {
            animation_kickWallSlideRightAttack.OnShow();

            if (keepkeydownAttacking == false)
                attackActionDelay++;

            if (attackActionDelay >= 20)
            {
                attackActionDelay = 0;
                chargeAttack = 0;
            }
        }
        else
            animation_kickWallSlideRight.OnShow();
    }
    else if (showDropping() && lastMovingState == 0)
    {
        animation_jumpRight.setToSpecifyBitmap(7);
        animation_jumpRightAttack.setToSpecifyBitmap(7);

        if (((isAttacking) && (charge == 0)) || (chargeAttack > 5))
        {
            animation_jumpRightAttack.OnShow();

            if (keepkeydownAttacking == false)
                attackActionDelay++;

            if (attackActionDelay >= 20)
            {
                attackActionDelay = 0;
                chargeAttack = 0;
            }
        }
        else
            animation_jumpRight.OnShow();
    }
    else if (showDropping() && lastMovingState == 1)
    {
        animation_jumpLeft.setToSpecifyBitmap(7);
        animation_jumpLeftAttack.setToSpecifyBitmap(7);

        if (((isAttacking) && (charge == 0)) || (chargeAttack > 5))
        {
            animation_jumpLeftAttack.OnShow();

            if (keepkeydownAttacking == false)
                attackActionDelay++;

            if (attackActionDelay >= 20)
            {
                attackActionDelay = 0;
                chargeAttack = 0;
            }
        }
        else
            animation_jumpLeft.OnShow();
    }
    else if ((sprintDegree != 0) && (lastMovingState == 0))
    {
        if (((isAttacking) && (charge == 0)) || (chargeAttack > 5))
        {
            animation_sprintRightAttack.OnShow();

            if (keepkeydownAttacking == false)
                attackActionDelay++;

            if (attackActionDelay >= 20)
            {
                attackActionDelay = 0;
                chargeAttack = 0;
            }
        }
        else
            animation_sprintRight.OnShow();
    }
    else if ((sprintDegree != 0) && (lastMovingState == 1))
    {
        if (((isAttacking) && (charge == 0)) || (chargeAttack > 5))
        {
            animation_sprintLeftAttack.OnShow();

            if (keepkeydownAttacking == false)
                attackActionDelay++;

            if (attackActionDelay >= 20)
            {
                attackActionDelay = 0;
                chargeAttack = 0;
            }
        }
        else
            animation_sprintLeft.OnShow();
    }
    else if ((isMovingRight == true) && (isMovingLeft == false))
    {
        if (((isAttacking) && (charge == 0)) || (chargeAttack > 5))
        {
            animationMovingRightAttack.OnShow();

            if (keepkeydownAttacking == false)
                attackActionDelay++;

            if (attackActionDelay >= 20)
            {
                attackActionDelay = 0;
                chargeAttack = 0;
            }
        }
        else
            animationMovingRight.OnShow();
    }
    else if ((isMovingRight == false) && (isMovingLeft == true))
    {
        if (((isAttacking) && (charge == 0)) || (chargeAttack > 5))
        {
            animationMovingLeftAttack.OnShow();

            if (keepkeydownAttacking == false)
                attackActionDelay++;

            if (attackActionDelay >= 20)
            {
                attackActionDelay = 0;
                chargeAttack = 0;
            }
        }
        else
            animationMovingLeft.OnShow();
    }
    else if (lastMovingState == 0)
    {
        if (((isAttacking) && (charge == 0)) || (chargeAttack > 5))
        {
            animationRightAttack.OnShow();

            if (keepkeydownAttacking == false)
                attackActionDelay++;

            if (attackActionDelay >= 20)
            {
                attackActionDelay = 0;
                chargeAttack = 0;
            }
        }
        else
            animationRight.OnShow();
    }
    else if (lastMovingState == 1)
    {
        if (((isAttacking) && (charge == 0)) || (chargeAttack > 5))
        {
            animationLeftAttack.OnShow();

            if (keepkeydownAttacking == false)
                attackActionDelay++;

            if (attackActionDelay >= 20)
            {
                attackActionDelay = 0;
                chargeAttack = 0;
            }
        }
        else
            animationLeft.OnShow();
    }

    for (int i = 0; i < 20; i++)
    {
        if (rockcannon[i].GetUsingState())
        {
            rockcannon[i].OnShow();
        }
    }

    x = tmp;
    y = tmp2;
    //--------Åã¥Ü¥Í©R­È-------------
    lifeItem.SetTopLeft(100, 143);
    lifeItem.ShowBitmap();

    for (int i = 0; i < life; i++)
    {
        lifeValue.SetTopLeft(140, 403 - i * 4);
        lifeValue.ShowBitmap();
    }

    //--------Åã¥Ü¥Í©R­È-------------
}
}
