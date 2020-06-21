#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "nightmareCannon.h"
#include "nightmare.h"

namespace game_framework
{
	Nightmare::Nightmare()
	{}
	void Nightmare::Initialize()
	{
		x = y = 0;
		s_x = s_y = 0;
		life = 10;
		isAlive = true;
		AttackDelay = 49;
		determinActionDelay = 0;
		moveDelay = 0;
		AttackDirection = 0;
		AttackMode = 0;
		monsBoom.Reset();
		firesound = false;
		if (rand() % 2)
			moveDelay = 200;
		else
			AttackDelay = 200;
	}
	void Nightmare::LoadBitMap()
	{
		LoadRightBitMap();
		LoadLeftBitMap();
		LoadMovingRightBitMap();
		LoadMovingLeftBitMap();
		LoadattackRightBitMap();
		LoadattackLeftBitMap();
		LoadBoomBitmap();
		cannon.LoadBitmapA();
	}
	void Nightmare::LoadRightBitMap()
	{
		monsRight.AddBitmap("RES\\enemy\\enemy_X6_2.bmp", RGB(255, 255, 255));
		monsRight.AddBitmap("RES\\enemy\\enemy_X6_2 2.bmp", RGB(255, 255, 255));
		monsRight.AddBitmap("RES\\enemy\\enemy_X6_2 3.bmp", RGB(255, 255, 255));
		monsRight.AddBitmap("RES\\enemy\\enemy_X6_2 4.bmp", RGB(255, 255, 255));
		monsRight.SetDelayCount(4);
	}
	void Nightmare::LoadLeftBitMap()
	{
		monsLeft.AddBitmap("RES\\enemy\\enemy_X6_2left.bmp", RGB(255, 255, 255));
		monsLeft.AddBitmap("RES\\enemy\\enemy_X6_2 2left.bmp", RGB(255, 255, 255));
		monsLeft.AddBitmap("RES\\enemy\\enemy_X6_2 3left.bmp", RGB(255, 255, 255));
		monsLeft.AddBitmap("RES\\enemy\\enemy_X6_2 4left.bmp", RGB(255, 255, 255));
		monsLeft.SetDelayCount(4);
	}
	void Nightmare::LoadMovingRightBitMap()
	{
		monsMovingRight.AddBitmap("RES\\enemy\\enemy_X6_2 move.bmp", RGB(255, 255, 255));
		monsMovingRight.AddBitmap("RES\\enemy\\enemy_X6_2 move2.bmp", RGB(255, 255, 255));
		monsMovingRight.AddBitmap("RES\\enemy\\enemy_X6_2 move3.bmp", RGB(255, 255, 255));
		monsMovingRight.SetDelayCount(4);
	}
	void Nightmare::LoadMovingLeftBitMap()
	{
		monsMovingLeft.AddBitmap("RES\\enemy\\enemy_X6_2 moveleft.bmp", RGB(255, 255, 255));
		monsMovingLeft.AddBitmap("RES\\enemy\\enemy_X6_2 move2left.bmp", RGB(255, 255, 255));
		monsMovingLeft.AddBitmap("RES\\enemy\\enemy_X6_2 move3left.bmp", RGB(255, 255, 255));
		monsMovingLeft.SetDelayCount(4);
	}
	void Nightmare::LoadattackRightBitMap()
	{
		monsRightAttack.AddBitmap("RES\\enemy\\enemy_X6_2 attack.bmp", RGB(255, 255, 255));
		monsRightAttack.AddBitmap("RES\\enemy\\enemy_X6_2 attack2.bmp", RGB(255, 255, 255));
		monsRightAttack.AddBitmap("RES\\enemy\\enemy_X6_2 attack3.bmp", RGB(255, 255, 255));
		monsRightAttack.SetDelayCount(4);
	}
	void Nightmare::LoadattackLeftBitMap()
	{
		monsLeftAttack.AddBitmap("RES\\enemy\\enemy_X6_2 attackleft.bmp", RGB(255, 255, 255));
		monsLeftAttack.AddBitmap("RES\\enemy\\enemy_X6_2 attack2left.bmp", RGB(255, 255, 255));
		monsLeftAttack.AddBitmap("RES\\enemy\\enemy_X6_2 attack3left.bmp", RGB(255, 255, 255));
		monsLeftAttack.SetDelayCount(4);
	}
	void Nightmare::LoadBoomBitmap()
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
	void Nightmare::setXY(int nx, int ny)
	{
		x = nx;
		y = ny;
	}
	void Nightmare::setScreenXY(int nx, int ny)
	{
		s_x = nx;
		s_y = ny;
	}
	void Nightmare::setAlive(bool state)
	{
		isAlive = state;
	}
	int Nightmare::getX()
	{
		return x;
	}
	int Nightmare::getY()
	{
		return y;
	}
	int Nightmare::getScreenX()
	{
		return s_x;
	}
	int Nightmare::getScreenY()
	{
		return s_y;
	}
	void Nightmare::FixCannonScreenXY(int fixX, int fixY)
	{
		cannon.AddScreenX_fix(-fixX);
		cannon.AddScreenY_fix(-fixY);
	}
	bool Nightmare::getAlive()
	{
		return isAlive;
	}
	int Nightmare::getLife()
	{
		return life;
	}
	void Nightmare::deductLife(int damage)
	{
		life -= damage;
		if (life <= 0)
			isAlive = false;
	}
	void Nightmare::moveAttack(int RockX, int RockY)
	{
		monsMovingRight.OnMove();
		monsMovingLeft.OnMove();
		moveDelay++;
		if (RockX <= x)
			x -= 20;
		else if (RockX > x)
			x += 20;
		if (RockY <= y)
			y -= 10;
		else if (RockY > y)
			y += 10;
	}
	void Nightmare::fire(int RockX, int RockY)
	{
		monsRightAttack.OnMove();
		monsLeftAttack.OnMove();
		AttackDelay++;
		if (AttackDelay % 35 == 0 && isAlive)
		{
			cannon.SetUsingState(true);
			cannon.SetX(x + 40);
			cannon.SetY(y + 36);
			cannon.SetScreenXY(x + s_x + 40, y + s_y + 36 - 1492);
			cannon.SetVelocity(RockX + 80, RockY + 100);
			cannon.SetLastMovingState(AttackDirection);
			cannon.SetCatchAction(1);
			firesound = true;
		}
	}
	void Nightmare::stay()
	{
		determinActionDelay++;
		if (determinActionDelay >= 50)
		{
			if (AttackDelay == 0 && moveDelay != 0)
			{
				AttackMode = 2;
				moveDelay = 0;
			}
			else if (moveDelay == 0 && AttackDelay != 0)
			{
				AttackMode = 1;
				AttackDelay = 0;
			}
			determinActionDelay = 0;
		}
	}
	void Nightmare::DeterminAttack(int RockX, int RockY)
	{
		if ((AttackDelay == 200 || moveDelay == 200) && AttackMode != 0)
			AttackMode = 0;
		if (AttackMode == 0 && AttackDelay == 200)
			moveDelay = 0;
		else if(AttackMode == 0 && moveDelay == 200)
			AttackDelay = 0;
		if (AttackMode != 2)
		{
			monsRightAttack.Reset();
			monsLeftAttack.Reset();
		}
		if (((RockX - x) < 1000 && (RockX - x) > 0) || ((x - RockX) < 1000 && (x - RockX) > 0)|| AttackMode != 0)
		{
			if(isAlive)
			{
				if (AttackMode == 0)
					stay();
				else if (AttackMode == 1)
					moveAttack(RockX, RockY);
				else if (AttackMode == 2)
					fire(RockX, RockY);
			}
		}
		monsRight.OnMove();
		monsLeft.OnMove();
		if (x - RockX > 0)
			AttackDirection = 0;
		else if (RockX - x > 0)
			AttackDirection = 1;
		cannon.OnMove();
		if (firesound)
		{
			CAudio::Instance()->Play(15, false);
			firesound = false;
		}
	}
	bool Nightmare::MonsterCollision(int RockX, int RockY)
	{
		if (!isAlive)
			return false;
		else if (x + 196 > RockX && RockX + 160 > x && y + 90 > RockY && RockY > y)
			return true;
		else
			return false;
	}
	int Nightmare::MonsterCannonCollision(int RockX, int RockY)
	{
		if (isAlive)
			return cannon.collision(RockX, RockY);
		return false;
	}
	void Nightmare::OnShow()
	{
		if (AttackMode == 2 && AttackDirection == 0)
		{
			monsRightAttack.SetTopLeft(x + s_x, y + s_y - 1492);
			monsRightAttack.OnShow();
		}
		else if (AttackMode == 2 && AttackDirection == 1)
		{
			monsLeftAttack.SetTopLeft(x + s_x, y + s_y - 1492);
			monsLeftAttack.OnShow();
		}
		else if (AttackMode == 1 && AttackDirection == 0)
		{
			monsMovingRight.SetTopLeft(x + s_x, y + s_y - 1492);
			monsMovingRight.OnShow();
		}
		else if (AttackMode == 1 && AttackDirection == 1)
		{
			monsMovingLeft.SetTopLeft(x + s_x, y + s_y - 1492);
			monsMovingLeft.OnShow();
		}
		else if (AttackDirection == 0)
		{
			monsRight.SetTopLeft(x + s_x, y + s_y - 1492);
			monsRight.OnShow();
		}
		else if (AttackDirection == 1)
		{
			monsLeft.SetTopLeft(x + s_x, y + s_y - 1492);
			monsLeft.OnShow();
		}
		if (cannon.GetUsingState())
			cannon.OnShow();
		else
			cannon.OnShowHit();
	}
	void Nightmare::OnShowBoom()
	{
		if (monsBoom.IsFinalBitmap())
			monsBoom.setToSpecifyBitmap(7);
		monsBoom.OnMove();
		monsBoom.SetTopLeft(x + s_x, y + s_y - 1492);
		if (isAlive == false && !monsBoom.IsFinalBitmap())
			monsBoom.OnShow();
	}
}