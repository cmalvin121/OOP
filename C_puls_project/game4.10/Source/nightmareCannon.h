namespace game_framework
{
	class NightmareCannon
	{
	public:
		NightmareCannon();
		void LoadBitmap();					//載入角色動畫
		void SetX(int);						//設定X
		void SetY(int);						//設定Y
		void SetScreenXY(int, int);			//設定砲擊螢幕座標
		void AddScreenX_fix(int);			//修正砲彈螢幕座標X
		void AddScreenY_fix(int);			//修正砲彈螢幕座標Y
		void OnMove();						//移動圖形
		void OnShow();						//顯示圖形
		void OnShowHit();					//顯示砲彈擊中動畫
		void SetVelocity(int, int);			//設定砲彈速度(追蹤砲彈)
		void SetLastMovingState(int);		//設定上次移動狀態
		void SetUsingState(bool flag);		//設定砲彈使用狀態
		bool GetUsingState();				//取得砲彈使用狀態
		void SetCatchAction(bool);			//設定砲彈抓取使用者座標
		int collision(int x, int y);		//砲彈與洛克人碰撞
	private:
		int x1, y1;								//腳色當前座標
		int screenX, screenY;					//畫面的座標
		int hitX, hitY;							//子彈擊中座標
		void SetHitXY();						//設定擊中座標
		CMovingBitmap nightmareCannon;			//圖片:夢魘炮
		CAnimation nightmareCannonHit;			//圖片:夢魘炮擊中
		void LoadNightmareCannonHitBitmap();	//載入動畫:夢魘炮擊中
		void HitAnimationLock();				//擊中動畫鎖定
		int velocity_cannon_x,velocity_cannon_y;//夢魘炮速度
		int distance;							//當前移動距離
		int lastMovingState;					//上次的移動方向
		bool usingState;						//是否被使用中
		bool catchAction;						//0:抓取動作，1:不抓取動作
		int isHitSomething;						//是否擊中到東西
		bool isCatchHitXY;						//是否擷取擊中座標
		bool showLock;							//顯示鎖定
		bool boomsound;							//是否播放爆炸音效
	};
}

