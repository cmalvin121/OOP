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
		void setAlive(bool state);			//設定存活狀態
		int getX();							//取得蝙蝠X座標
		int getY();							//取得蝙蝠Y座標
		int getScreenX();					//取得蝙蝠X螢幕座標
		int getScreenY();					//取得蝙蝠Y螢幕座標
		bool getAlive();					//取得存活狀態
		void OnShow();						//顯示動畫
		void OnShowBoom();					//顯示爆炸動畫
		void DeterminAttack(int, int);		//決定攻擊模式
		bool MonsterCollision(int, int);	//與洛克人碰撞判斷
		void deductLife(int damage);		//扣除生命值
	private:
		bool isAlive;						//存活狀態
		int x, y;							//座標
		int s_x, s_y;						//螢幕座標偏移量
		int life;							//生命
		bool AttackDirection;				//0:往左射,1:往右射
		int AttackMode;						//攻擊模式 0:靜止 1:移動
		CAnimation monsMovingRight;
		CAnimation monsMovingLeft;
		void moveAttack(int, int);
		void LoadMovingRightBitMap();
		void LoadMovingLeftBitMap();
		CAnimation monsBoom;
		void LoadBoomBitmap();
	};
}