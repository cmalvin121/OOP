namespace game_framework
{
	class Bat
	{
	public:
		Bat();
		void Initialize();					//初始化參數
		void LoadBitMap();					//載入圖片
		void setXY(int nx, int ny);			//設定XY
		void setScreenXY(int nx, int ny);	//設定螢幕XY
		int getX();							//取得蝙蝠X座標
		int getY();							//取得蝙蝠Y座標
		int getScreenX();					//取得蝙蝠X螢幕座標
		int getScreenY();					//取得蝙蝠Y螢幕座標
		void setAlive(bool state);			//設定存活狀態
		bool getAlive();					//取得存活狀態
		int getLife();						//取得生命值
		void deductLife(int damage);		//扣除生命值
		void OnShow();						//顯示動畫
		void OnShowBoom();					//顯示爆炸動畫
		void DeterminAttack(int, int);		//決定攻擊模式
		bool MonsterCollision(int, int);	//與洛克人碰撞判斷
	private:
		int x, y;							//座標
		int s_x, s_y;						//螢幕座標偏移量
		int life;							//生命
		bool isAlive;						//存活狀態
		CAnimation monsMovingRight;			//動畫:往右移動
		CAnimation monsMovingLeft;			//動畫:往左移動
		CAnimation monsBoom;				//動畫:爆炸
		void LoadMovingRightBitMap();		//載入動畫:往右移動
		void LoadMovingLeftBitMap();		//載入動畫:往左移動
		void LoadBoomBitmap();				//載入所有動畫
		bool AttackDirection;				//攻擊方向,0:往左射,1:往右射
		int AttackMode;						//攻擊模式 0:靜止 1:移動
		void moveAttack(int, int);			//衝撞攻擊
	};
}