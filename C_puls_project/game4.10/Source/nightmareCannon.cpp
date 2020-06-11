#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "nightmareCannon.h"
#include <cmath>
namespace game_framework
{
	NightmareCannon::NightmareCannon()
	{
		x1 = 0;
		y1 = 700;
		velocity_cannon_x = 60;
		velocity_cannon_y = 0;
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
	void NightmareCannon::LoadBitmap()
	{
		LoadNightmareCannonHitBitmap();
		nightmareCannon.LoadBitmap("RES\\enemy\\blueCannon.bmp", RGB(255, 255, 255));
	}
	void NightmareCannon::SetLastMovingState(int flag)
	{
		if (catchAction == 0)
			lastMovingState = flag;
	}
	void NightmareCannon::SetX(int x)
	{
		if (catchAction == 0)
			x1 = x;
	}
	void NightmareCannon::SetY(int y)
	{
		if (catchAction == 0)
			y1 = y;
	}
	void NightmareCannon::AddScreenX_fix(int fix)
	{
		if (usingState == true)
			screenX += fix;
		if (usingState == false)
			hitX += fix;
	}
	void NightmareCannon::AddScreenY_fix(int fix)
	{
		if (usingState == true)
			screenY += fix;
		if (usingState == false)
			hitY += fix;
	}
	void NightmareCannon::SetHitXY()
	{
		if (!isCatchHitXY)
		{
			hitX = screenX;
			hitY = screenY;
			isCatchHitXY = true;
		}
	}
	void NightmareCannon::SetCatchAction(bool flag)
	{
		catchAction = flag;
	}
	bool NightmareCannon::GetUsingState()
	{
		return usingState;
	}
	void NightmareCannon::SetUsingState(bool flag)
	{
		usingState = flag;
		distance = 0;
		catchAction = 0;
		x1 = 0;
		y1 = 0;
		screenX = 0;
		screenY = 0;
		if (usingState)
			nightmareCannonHit.Reset();
	}
	void NightmareCannon::SetScreenXY(int x, int y)
	{
		if (showLock == 0)
		{
			screenX = x;
			screenY = y;
			showLock = 1;
		}
	}
	void NightmareCannon::SetVelocity(int RockX, int RockY)
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
	void NightmareCannon::HitAnimationLock()
	{
		if (nightmareCannonHit.IsFinalBitmap())
		{
			isCatchHitXY = false;
			isHitSomething = 0;
			nightmareCannonHit.setToSpecifyBitmap(7);
		}
	}
	int NightmareCannon::collision(int x, int y)
	{
		if (!usingState)
			return 0;
		if (lastMovingState == 0)
		{
			if ((x1 + 58 >= x) && (x1 <= x + 160) && (y1 <= y + 200) && (y1 + 55 >= y))
			{
				isHitSomething = 2;
				TRACE("isHitSomethingMC:%d\n", isHitSomething);
				SetHitXY();
				return 2;
			}
		}
		else if (lastMovingState == 1)
		{
			if ((x1 <= x + 160) && (x1 >= x) && (y1 <= y + 200) && (y1 + 55 >= y))
			{
				isHitSomething = 2;
				TRACE("isHitSomethingMC:%d\n", isHitSomething);
				SetHitXY();
				return 2;
			}
		}
		return 0;
	}
	void NightmareCannon::OnMove()
	{
		CONST int velocity_cannon = 60;
		if (distance >= 1600 || isHitSomething != 0)
		{
			usingState = false;
			catchAction = 0;
			x1 = 0;
			y1 = 0;
		}
		if (distance >= 1600 && nightmareCannonHit.GetCurrentBitmapNumber() == 0)
		{
			hitX = screenX;
			hitY = screenY;
		}

		if (catchAction == 0)
			showLock = 0;

		if (usingState)
		{
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
		else
			nightmareCannonHit.OnMove();
	}
	void NightmareCannon::OnShow()
	{
		int tmp = x1, tmp2 = y1;
		if (x1 >= 900)
			x1 = screenX;

		if (y1 <= 2700)
			y1 = screenY;
		nightmareCannon.SetTopLeft(x1, y1);
		if (usingState == true)
			nightmareCannon.ShowBitmap();
		x1 = tmp;
		y1 = tmp2;
	}
	void NightmareCannon::OnShowHit()
	{
		nightmareCannonHit.SetTopLeft(hitX, hitY);
		HitAnimationLock();
		if (usingState == false && !nightmareCannonHit.IsFinalBitmap())//
		{
			if ((isHitSomething > 0 && isHitSomething < 8) || distance >= 1600)
			{
				nightmareCannonHit.OnShow();
			}
		}
	}
	void NightmareCannon::LoadNightmareCannonHitBitmap()
	{
		nightmareCannonHit.AddBitmap("RES\\enemy\\explosion.bmp", RGB(255, 255, 255));
		nightmareCannonHit.AddBitmap("RES\\enemy\\explosion2.bmp", RGB(255, 255, 255));
		nightmareCannonHit.AddBitmap("RES\\enemy\\explosion3.bmp", RGB(255, 255, 255));
		nightmareCannonHit.AddBitmap("RES\\enemy\\explosion4.bmp", RGB(255, 255, 255));
		nightmareCannonHit.AddBitmap("RES\\enemy\\explosion5.bmp", RGB(255, 255, 255));
		nightmareCannonHit.AddBitmap("RES\\enemy\\explosion6.bmp", RGB(255, 255, 255));
		nightmareCannonHit.AddBitmap("RES\\enemy\\explosion7.bmp", RGB(255, 255, 255));
		nightmareCannonHit.AddBitmap("RES\\enemy\\explosion8.bmp", RGB(255, 255, 255));
		nightmareCannonHit.SetDelayCount(2);
	}
}