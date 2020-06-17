namespace game_framework
{
/*enum skill {
    skill_one,				//劍氣
    skill_two,				//直線炮彈
    skill_three,			//捶地板
    skill_four				//砍擊
};*/
class BossCannon
{
    public:
        BossCannon();
        void LoadBitMap();					//載入角色動畫
        void setCannon(int t);
        void OnMove();						//移動圖形
        void OnShow();						//顯示圖形
        void SetLastMovingState(int flag);		//設定上次移動狀態
        void SetX(int x);
        void SetY(int y);
        void AddScreenX_fix(int fix);
        void AddScreenY_fix(int fix);
        void SetScreenXY(int x, int y);			//設定砲擊螢幕座標
        void SetUsingState(bool flag);
        bool GetUsingState();
        void SetCatchAction(bool flag);
        int collision(int x, int y);
    private:
        int x1, y1;								//腳色當前座標
        int screenX, screenY;					//畫面的座標
        int hitX, hitY;							//子彈擊中座標
        CMovingBitmap bossCannonleft;				//圖片:
        int velocity_cannon;					//洛克炮速度
        int lastMovingState;					//上次的移動方向
        int isHitSomething;						//是否擊中到東西
        bool catchAction;						//0:抓取動作，1:不抓取動作
        bool showLock;							//顯示鎖定
        bool usingState;						//是否被使用中
        bool isCatchHitXY;						//是否擷取擊中座標
        int distance;
        int type;								//1 = 劍氣  2 = 直線炮彈  3 = 捶地板
};
}