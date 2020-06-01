#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "TrashCannon.h"
namespace game_framework
{
	TrashCannon::TrashCannon()
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
	void TrashCannon::LoadBitmap()
	{
		LoadTrashCannonHitBitmap();
		trashCannon.LoadBitmap("RES\\enemy\\trashcannon.bmp", RGB(255, 255, 255));
	}
	void TrashCannon::SetLastMovingState(int flag)
	{
		if (catchAction == 0)
			lastMovingState = flag;
	}
	void TrashCannon::SetX(int x)
	{
		if (catchAction == 0)
			x1 = x;
	}
	void TrashCannon::SetY(int y)
	{
		if (catchAction == 0)
			y1 = y;
	}
	void TrashCannon::AddScreenX_fix(int fix)
	{
		if (usingState == true)
			screenX += fix;
		if (usingState == false)
			hitX += fix;
	}
	void TrashCannon::AddScreenY_fix(int fix)
	{
		if (usingState == true)
			screenY += fix;
		if (usingState == false)
			hitY += fix;
	}
	void TrashCannon::SetHitXY()
	{
		if (!isCatchHitXY)
		{
			hitX = screenX;
			hitY = screenY;
			isCatchHitXY = true;
		}
	}
	void TrashCannon::SetCatchAction(bool flag)
	{
		catchAction = flag;
	}
	bool TrashCannon::GetUsingState()
	{
		return usingState;
	}
	void TrashCannon::SetUsingState(bool flag)
	{
		usingState = flag;
		distance = 0;
		catchAction = 0;
		x1 = 0;
		y1 = 0;
		if(usingState)
			trashCannonHit.Reset();
	}
	void TrashCannon::SetScreenXY(int x,int y)
	{
		if (showLock == 0) 
		{
			screenX = x;
			screenY = y;
			showLock = 1;
		}
	}
	void TrashCannon::HitAnimationLock()
	{
		if (trashCannonHit.IsFinalBitmap())
		{
			isCatchHitXY = false;
			isHitSomething = 0;
			trashCannonHit.setToSpecifyBitmap(7);
		}
	}
	int TrashCannon::collision(int x, int y)
	{
		if (!usingState)
			return 0;
		if (lastMovingState == 0)
		{
			if ((x1 + 32 >= x) && (x1 <= x + 160) && (y1 <= y + 200) && (y1 + 32 >= y))
			{
				isHitSomething = 2;
				TRACE("isHitSomethingMC:%d\n", isHitSomething);
				SetHitXY();
				return 2;
			}
		}
		else if (lastMovingState == 1)
		{
			if ((x1 <= x + 160) && (x1 >= x) && (y1 <= y + 200) && (y1 + 32 >= y))
			{
				isHitSomething = 2;
				TRACE("isHitSomethingMC:%d\n", isHitSomething);
				SetHitXY();
				return 2;
			}
		}
		return 0;
	}
	void TrashCannon::OnMove()
	{
		if (distance >= 800 || isHitSomething != 0)
		{
			usingState = false;
			catchAction = 0;
			x1 = 0;
			y1 = 0;
		}
		if (distance >= 800 && trashCannonHit.GetCurrentBitmapNumber() == 0)
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
				x1 -= velocity_cannon;
				screenX -= velocity_cannon;
				distance += velocity_cannon;
			}
			else if (lastMovingState == 1)
			{
				x1 += velocity_cannon;
				screenX += velocity_cannon;
				distance += velocity_cannon;
			}
		}
		else
			trashCannonHit.OnMove();
	}
	void TrashCannon::OnShow()
	{
		int tmp = x1, tmp2 = y1;
		if (x1 >= 900)
			x1 = screenX;

		if (y1 <= 2700)
			y1 = screenY;
		trashCannon.SetTopLeft(x1, y1);
		if (usingState == true)
			trashCannon.ShowBitmap();
		x1 = tmp;
		y1 = tmp2;
	}
	void TrashCannon::OnShowHit()
	{
		trashCannonHit.SetTopLeft(hitX, hitY);
		HitAnimationLock();
		if (usingState == false && !trashCannonHit.IsFinalBitmap())
		{
			if ((isHitSomething > 0 && isHitSomething < 8) || distance >= 800)
			{
				trashCannonHit.OnShow();
				TRACE("in\n");
			}
		}
	}
	void TrashCannon::LoadTrashCannonHitBitmap()
	{
		trashCannonHit.AddBitmap("RES\\enemy\\explosion.bmp", RGB(255, 255, 255));
		trashCannonHit.AddBitmap("RES\\enemy\\explosion2.bmp", RGB(255, 255, 255));
		trashCannonHit.AddBitmap("RES\\enemy\\explosion3.bmp", RGB(255, 255, 255));
		trashCannonHit.AddBitmap("RES\\enemy\\explosion4.bmp", RGB(255, 255, 255));
		trashCannonHit.AddBitmap("RES\\enemy\\explosion5.bmp", RGB(255, 255, 255));
		trashCannonHit.AddBitmap("RES\\enemy\\explosion6.bmp", RGB(255, 255, 255));
		trashCannonHit.AddBitmap("RES\\enemy\\explosion7.bmp", RGB(255, 255, 255));
		trashCannonHit.AddBitmap("RES\\enemy\\explosion8.bmp", RGB(255, 255, 255));
		trashCannonHit.SetDelayCount(2);
	}
}