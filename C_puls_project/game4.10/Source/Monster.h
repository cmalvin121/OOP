namespace game_framework
{
	class Monster
	{
	public:
		Monster();
		void Initialize();						//初始化參數
		void LoadBitMap();						//載入圖片
		void setXY(int nx, int ny);				//設定XY
		void setScreenXY(int nx, int ny);		//設定螢幕XY
		void FixCannonScreenXY(int, int);		//修正砲彈螢幕XY
		int getX();								//取得蝙蝠X座標
		int getY();								//取得蝙蝠Y座標
		int getScreenX();						//取得蝙蝠X螢幕座標
		int getScreenY();						//取得蝙蝠Y螢幕座標
		void setAlive(bool state);				//設定存活狀態
		bool getAlive();						//取得存活狀態
		int getLife();							//取得生命值
		void deductLife(int damage);			//扣除生命值
		void OnShow();							//顯示動畫
		void OnShowBoom();						//顯示爆炸動畫
		void DeterminAttack(int, int);			//決定攻擊模式
		bool MonsterCollision(int, int);		//與洛克人碰撞判斷
		int  MonsterCannonCollision(int, int);	//砲擊與洛克人碰撞判斷
	private:
		int x, y;								//座標
		int s_x, s_y;							//螢幕座標
		int life;								//生命
		bool isAlive;							//存活狀態
		CMovingBitmap monsRight;				//圖片:往右站立
		CMovingBitmap monsLeft;					//圖片:往左站立
		CMovingBitmap monsRightAttack;			//圖片:往右攻擊
		CMovingBitmap monsLeftAttack;			//圖片:往左攻擊
		CAnimation monsBoom;					//動畫:爆炸
		void LoadBoomBitmap();					//載入動畫:爆炸
		TrashCannon cannon;						//垃圾砲
		bool AttackDirection;					//攻擊方向,0:往左射,1:往右射
		int AttackDelay;						//攻擊延遲
		int nowAttackDistance;					//當前攻擊距離
	};
}