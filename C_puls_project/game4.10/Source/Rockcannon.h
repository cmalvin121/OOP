namespace game_framework
{
class RockCannon
{
    public:
        RockCannon();
        void LoadBitmap();					//載入角色動畫
        void OnMove();						//移動圖形
        void OnShow();						//顯示圖形
		void OnShowHit();
        void SetNowCharge(int);					//設定現在充能
        void SetLastMovingState(int);			//設定上次移動狀態
        void SetX(int);
        void SetY(int);
        void SetCatchAction(bool);
        bool GetUsingState();
        void SetUsingState(bool flag);
        void SetFixScreen(int,int);
        int collision(int x, int y,bool MonsterisAlive, int monsterNum);
    private:
        int x1, y1;								//腳色當前座標
        int screenX, screenY;					//畫面的座標
		int hitX, hitY;							//子彈擊中座標
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
        void SetScreen();						//設定砲擊螢幕座標
		void SetHitXY();						//設定擊中座標
        int velocity_cannon;					//洛克炮速度
        int nowCharge;							//現在充能
        int lastMovingState;					//上次的移動方向
		int isHitSomething;						//是否擊中到東西
        bool catchAction;						//0:抓取動作，1:不抓取動作
        bool showLock;							//顯示鎖定
        bool usingState;						//是否被使用中
		bool isCatchHitXY;						//是否擷取擊中座標
        int distance;
};
}
