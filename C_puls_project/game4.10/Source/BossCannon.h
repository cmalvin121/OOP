namespace game_framework
{
class BossCannon
{
    public:
        BossCannon();
        void LoadBitMap();						//載入砲彈動畫
		void SetX(int x);						//設定X
		void SetY(int y);						//設定Y
		void SetScreenXY(int x, int y);			//設定砲彈螢幕座標XY
		void AddScreenX_fix(int fix);			//修正砲彈螢幕座標X
		void AddScreenY_fix(int fix);			//修正砲彈螢幕座標Y
		void OnMove();							//移動圖形
		void OnShow();							//顯示圖形
        void setCannon(int t);					//設定砲彈型態
		void SetVelocity(int RockX, int RockY);	//設定砲彈速度(追蹤砲彈)
        void SetLastMovingState(int flag);		//設定上次移動狀態
        void SetUsingState(bool flag);			//設定砲彈使用狀態
        bool GetUsingState();					//取得砲彈使用狀態
        void SetCatchAction(bool flag);			//設定砲彈抓取使用者座標
        int collision(int x, int y);			//砲彈與洛克人碰撞
    private:
        int x1, y1;								//角色當前座標
        int screenX, screenY;					//畫面座標
        int hitX, hitY;							//子彈擊中座標
		CAnimation cannon;						//動畫:螺旋砲(右)
		CAnimation cannonLeft;					//動畫:螺旋砲(左)
		CAnimation flySword;					//動畫:追蹤飛刀(右)
		CAnimation flySwordLeft;				//動畫:追蹤飛刀(左)
		CAnimation destroyLight;				//動畫:滅閃光砲彈(槌地板砲彈)
		CMovingBitmap hugeSword;				//圖片:幻夢零劍氣(右)
		CMovingBitmap hugeSwordLeft;			//圖片:幻夢零劍氣(左)
		void LoadCannonBitMap();				//動畫:螺旋砲(右)
		void LoadCannonLeftBitMap();			//動畫:螺旋砲(左)
		void LoadFlySwordBitMap();				//動畫:追蹤飛刀(右)
		void LoadFlySwordLeftBitMap();			//動畫:追蹤飛刀(左)
		void LoadDestroyLightBitMap();			//動畫:滅閃光砲彈(槌地板砲彈)
		int type;								//1 = 幻夢零劍氣  2 = 螺旋砲  3 = 滅閃光砲彈(槌地板砲彈) 4 = 追蹤飛刀
        int velocity_cannon_x;					//夢魘傑洛炮速度
		int velocity_cannon_y;					//夢魘傑洛炮速度
		int distance;							//當前移動距離
        int lastMovingState;					//上次的移動方向
		bool usingState;						//是否被使用中
		bool catchAction;						//0:抓取動作，1:不抓取動作
        int isHitSomething;						//是否擊中到東西
		bool isCatchHitXY;						//是否擷取擊中座標
        bool showLock;							//顯示鎖定
};
}