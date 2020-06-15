namespace game_framework
{
	class NightmareCannon
	{
	public:
		NightmareCannon();
		void LoadBitmap();					//載入角色動畫
		void OnMove();						//移動圖形
		void OnShow();						//顯示圖形
		void OnShowHit();
		void SetLastMovingState(int);		//設定上次移動狀態
		void SetX(int);
		void SetY(int);
		void AddScreenX_fix(int);
		void AddScreenY_fix(int);
		void SetScreenXY(int, int);			//設定砲擊螢幕座標
		void SetVelocity(int, int);
		void SetCatchAction(bool);
		bool GetUsingState();
		void SetUsingState(bool flag);
		int collision(int x, int y);
	private:
		int x1, y1;								//腳色當前座標
		int screenX, screenY;					//畫面的座標
		int hitX, hitY;							//子彈擊中座標
		bool boomsound;
		CMovingBitmap nightmareCannon;			//圖片:夢魘炮
		CAnimation nightmareCannonHit;			//圖片:夢魘炮擊中
		void LoadNightmareCannonHitBitmap();	//載入動畫:夢魘炮擊中
		void HitAnimationLock();				//擊中動畫鎖定
		void SetHitXY();						//設定擊中座標
		int velocity_cannon_x,velocity_cannon_y;//夢魘炮速度
		int lastMovingState;					//上次的移動方向
		int isHitSomething;						//是否擊中到東西
		bool catchAction;						//0:抓取動作，1:不抓取動作
		bool showLock;							//顯示鎖定
		bool usingState;						//是否被使用中
		bool isCatchHitXY;						//是否擷取擊中座標
		int distance;
	};
}

