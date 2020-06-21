namespace game_framework
{
	class Nightmare
	{
	public:
		Nightmare();
		void Initialize();					//初始化參數
		void LoadBitMap();					//載入圖片
		void setXY(int nx, int ny);			//設定XY
		void setScreenXY(int nx, int ny);	//設定螢幕XY
		void FixCannonScreenXY(int, int);	//修正螢幕座標
		int getX();							//取得夢魘X座標
		int getY();							//取得夢魘Y座標
		int getScreenX();					//取得夢魘X螢幕座標
		int getScreenY();					//取得夢魘Y螢幕座標
		void setAlive(bool state);			//設定存活狀態
		bool getAlive();					//取得存活狀態
		int getLife();						//取得生命值
		void deductLife(int damage);		//扣除生命值
		void OnShow();						//顯示動畫
		void OnShowBoom();					//顯示爆炸動畫
		void DeterminAttack(int, int);		//決定攻擊模式
		bool MonsterCollision(int, int);	//與洛克人碰撞判斷
		int  MonsterCannonCollision(int, int);//砲彈與洛克人碰撞判斷
	private:
		int x, y;							//座標
		int s_x, s_y;						//螢幕座標偏移量
		int life;							//生命
		bool isAlive;						//存活狀態
		CAnimation monsRight;				//動畫:向右站立
		CAnimation monsLeft;				//動畫:往左站立
		CAnimation monsMovingRight;			//動畫:向右移動
		CAnimation monsMovingLeft;			//動畫:往左移動
		CAnimation monsRightAttack;			//動畫:向右射擊
		CAnimation monsLeftAttack;			//動畫:往左射擊
		CAnimation monsBoom;				//動畫:爆炸
		void LoadRightBitMap();				//載入動畫:向右站立
		void LoadLeftBitMap();				//載入動畫:往左站立
		void LoadMovingRightBitMap();		//載入動畫:向右移動
		void LoadMovingLeftBitMap();		//載入動畫:往左移動
		void LoadattackRightBitMap();		//載入動畫:向右射擊
		void LoadattackLeftBitMap();		//載入動畫:往左射擊
		void LoadBoomBitmap();				//載入動畫:爆炸
		NightmareCannon cannon;				//夢魘砲
		int AttackDelay;					//砲彈攻擊延遲
		int moveDelay;						//移動攻擊延遲
		int determinActionDelay;			//決定攻擊模式延遲
		bool AttackDirection;				//攻擊方向,0:往左射,1:往右射
		int AttackMode;						//攻擊模式 0:靜止 1:移動 2:開火
		void moveAttack(int, int);			//攻擊模式:衝撞攻擊
		void fire(int, int);				//攻擊模式:砲擊
		void stay();						//攻擊模式:待機
		bool firesound;						//是否播放射擊音效
	};
}