namespace game_framework
{
class Boss
{
    public:
        Boss();
        void Initialize();								//初始化參數
        void LoadBitMap();								//載入圖片
		void setXY(int nx, int ny);						//設定XY
		void setScreen_XY(int nx, int ny);				//設定螢幕XY
		void FixCannonScreenXY(int, int);				//修正砲彈螢幕XY
		int getX();										//取得夢魘傑洛X座標
		int getY();										//取得夢魘傑洛Y座標
		int getScreenX();								//取得夢魘傑洛X螢幕座標
		int getScreenY();								//取得夢魘傑洛Y螢幕座標
		bool getAlive();								//取得存活狀態
		int getLife();									//取得生命值
		void deductLife(int damage);					//扣除生命值
        void OnShow();									//顯示動畫
        void OnMove(int RockX, int RockY);				//角色移動
        void DeterminAttack(int RockX, int RockY);		//決定攻擊模式
		bool GetStartAttack();							//取得角色是否開始攻擊
        bool MonsterCollision(int, int);				//與洛克人碰撞判斷
        int MonsterCannonCollision(int, int);			//砲擊與洛克人碰撞判斷
    private:
		int x, y;										//座標
		int screen_x, screen_y;							//螢幕座標偏移量
		int life;										//生命
		bool isAlive;									//存活狀態
		CMovingBitmap boss;								//圖片:向右站立
		CMovingBitmap bossLeft;							//圖片:往左站立
		CAnimation bossSprint;							//動畫:向右衝刺
		CAnimation bossSprintLeft;						//動畫:往左衝刺
		CAnimation bossFire;							//動畫:向右射擊
		CAnimation bossFireLeft;						//動畫:往左射擊
		CAnimation bossChop;							//動畫:向右斬擊
		CAnimation bossChopLeft;						//動畫:往左斬擊
		CAnimation bossDestoryLight;					//動畫:滅閃光(槌地板)
		CAnimation bossKill;							//動畫:幻夢零(右)(超大劍氣)
		CAnimation bossKillLeft;						//動畫:幻夢零(左)(超大劍氣)
		CAnimation hugeknife;							//動畫:幻夢零充能
		CAnimation knife;								//動畫:光束劍(右)
		CAnimation knifeLeft;							//動畫:光束劍(左)
		CMovingBitmap lifeItem;							//圖片:生命條
		CMovingBitmap lifeValue;						//圖片:生命值
		void LoadBossSprintBitMap();					//載入動畫:向右衝刺
		void LoadBossSprintLeftBitMap();				//載入動畫:往左衝刺
		void LoadBossFireBitMap();						//載入動畫:向右射擊
		void LoadBossFireLeftBitMap();					//載入動畫:往左射擊
		void LoadBossChopBitMap();						//載入動畫:向右斬擊
		void LoadBossChopLeftBitMap();					//載入動畫:往左斬擊
		void LoadBossDestoryLightBitMap();				//載入動畫:滅閃光(槌地板)
		void LoadBossKillBitMap();						//載入動畫:幻夢零(右)(超大劍氣)
		void LoadBossKillLeftBitMap();					//載入動畫:幻夢零(左)(超大劍氣)
		void LoadHugeknifeBitMap();						//載入動畫:幻夢零充能
		void LoadKnifeBitMap();							//載入動畫:光束劍(右)
		void LoadKnifeLeftBitMap();						//載入動畫:光束劍(左)
		void LoadLifeObjectBitmap();					//載入圖片:生命物件
		void ResetAnimation();							//重置動畫
        BossCannon cannon[6];							//夢魘傑洛砲彈
		bool startAttack;								//是否開始攻擊
		bool isfire;									//是否已射擊
		int attackDelay;								//攻擊延遲
		int AttackDirection;							//攻擊方向,0:往左射,1:往右射
		int KillDirection;								//幻夢零(超大劍氣)攻擊方向
		int AttackCommand[15];							//攻擊指令
		int commandProcess;								//指令進程
		int reverse;									//攻擊方向反轉
        int skill;										//當前攻擊的技能
		void Stay();									//攻擊模式:待機
		void Sprint();									//攻擊模式:衝刺
		void Fire();									//攻擊模式:砲擊
		void FireFlySword(int RockX, int RockY);		//攻擊模式:追蹤飛刀
		void DestroyLight();							//攻擊模式:滅閃光(槌地板)
		void Kill();									//攻擊模式:幻夢零(超大劍氣)
		bool isInjured;									//是否已經受傷
		int injureDelay;								//受傷無敵時間
		int injureShine;								//無敵時間閃爍
		bool isPlaySound;								//是否撥放音效
		int destroyLightCount;							//滅閃光(槌地板)音效計數器
};
}