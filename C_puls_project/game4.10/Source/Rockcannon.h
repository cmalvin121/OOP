namespace game_framework
{
class RockCannon
{
    public:
        RockCannon();
        void LoadBitmap();														//載入角色動畫
		void SetX(int);															//設定X
		void SetY(int);															//設定Y
		void SetFixScreen(int, int);											//設定砲擊螢幕座標修正
        void OnMove();															//移動圖形
        void OnShow();															//顯示圖形
		void OnShowHit();														//顯示砲彈擊中動畫
		void SetNowCharge(int);													//設定現在充能
		void SetLastMovingState(int);											//設定上次移動狀態
		void SetUsingState(bool flag);											//設定砲彈使用狀態
		bool GetUsingState();													//取得砲彈使用狀態
        void SetCatchAction(bool);												//設定砲彈抓取使用者座標
        int collision(int x, int y,bool MonsterisAlive, int monsterNum);		//砲彈與怪物碰撞
    private:
        int x1, y1;								//腳色當前座標
        int screenX, screenY;					//畫面的座標
		int hitX, hitY;							//子彈擊中座標
		void SetScreen();						//設定砲擊螢幕座標
		void SetHitXY();						//設定擊中座標
        CAnimation normalCannon;				//動畫:一般洛克炮
        CAnimation chargeCannon;				//動畫:充能洛克炮
        CAnimation superChargeCannon;			//動畫:超級充能洛克炮
        CAnimation normalCannonLeft;			//動畫:一般洛克炮(左)
        CAnimation chargeCannonLeft;			//動畫:充能洛克炮(左)
        CAnimation superChargeCannonLeft;		//動畫:超級充能洛克炮(左)
		CAnimation normalCannonHit;				//動畫:一般、充能洛克炮擊中
		CAnimation normalCannonHitLeft;			//動畫:一般、充能洛克炮擊中(左)
		CAnimation superChargeCannonHit;		//動畫:超級充能洛克炮擊中
		CAnimation superChargeCannonHitLeft;	//動畫:超級充能洛克炮擊中(左)
        void LoadNormalCannonBitmap();			//載入動畫:一般洛克炮
        void LoadChargeCannonBitmap();			//載入動畫:充能洛克炮
        void LoadSuperChargeCannonBitmap();		//載入動畫:超級充能洛克炮
        void LoadNormalCannonLeftBitmap();		//載入動畫:一般洛克炮(左)
        void LoadChargeCannonLeftBitmap();		//載入動畫:充能洛克炮(左)
        void LoadSuperChargeCannonLeftBitmap();	//載入動畫:超級充能洛克炮(左)
		void LoadNormalCannonHitBitmap();		//載入動畫:一般、充能洛克炮擊中
		void LoadNormalCannonHitLeftBitmap();	//載入動畫:一般、充能洛克炮擊中(左)
		void LoadSuperChargeCannonHitBitmap();	//載入動畫:超級充能洛克炮擊中
		void LoadSuperChargeCannonHitLeftBitmap();//載入動畫:超級充能洛克炮擊中(左)
		void HitAnimationLock();				//擊中動畫鎖定
		int nowCharge;							//現在充能
        int velocity_cannon;					//洛克炮速度
		int distance;							//當前移動距離
        int lastMovingState;					//上次的移動方向
		bool usingState;						//是否被使用中
		bool catchAction;						//0:抓取動作，1:不抓取動作
		int isHitSomething;						//是否擊中到東西
		bool isCatchHitXY;						//是否擷取擊中座標
        bool showLock;							//顯示鎖定
};
}
