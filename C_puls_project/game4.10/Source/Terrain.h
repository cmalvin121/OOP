namespace game_framework
{
class Terrain     //地形(箱子、方塊)
{
    public:
        Terrain();
        void LoadBitMap();					//載入圖片
        void Initialize();					//初始化參數
		void GetLastRockmanXY(int x, int y);//地圖抓取洛克人移動前之座標
		void GetNowRockmanXY(int x, int y);	//地圖抓取洛克人移動後之座標
        void MoveScreen();					//畫面移動
        int GetLastX();						//取得洛克人移動前之座標X
        int GetLastY();						//取得洛克人移動前之座標Y
        int crashleft();					//左邊碰撞判斷
        int crashright();					//右邊碰撞判斷
        int crashtop();						//上邊碰撞判斷
        int crashdown();					//下邊碰撞判斷
        bool MonsterCollision();			//洛克人與所有怪物之碰撞
        int MosterCannonCollision();		//洛克人與所有怪物砲彈之碰撞
		bool GetIsBossCannon();				//取得是否為BOSS的砲彈
        //////////////////////// Monster
        Monster getMonster(int index);		//取得垃圾怪
        Nightmare getNightmare(int index);	//取得夢魘
        Bat getBat(int index);				//取得蝙蝠
		Boss getBoss();						//取得夢魘傑洛
        void setMonsterLife(int index, int damage, int monsterNum);	//設定指定怪物之生命
        int getMonsterLife(int index, int monsterNum);				//取得指定怪物之生命
		bool IsBossStage();											//是否為BOSS戰鬥
		bool IsBossDead();											//是否BOSS已死亡
        void setLifeToZero();										//所有小怪血量強制歸0(作弊)
		void OnShow();												//顯示圖片
        ////////////////////////////////
    protected:
        CMovingBitmap	background;	// 背景圖
        CMovingBitmap	background2;// 背景圖2
        CMovingBitmap	background3;// 背景圖3
        CMovingBitmap	background4;// 背景圖4
        CMovingBitmap	block;		// 障礙物
        CMovingBitmap	deadBlock;	// 尖刺、無底洞
        Boss boss;					// 夢魘傑洛
        Monster X6_1[8];			// 垃圾怪
        Nightmare X6_2[6];			// 夢魘
        Bat X4_1[6];				// 蝙蝠
        int picX, picY;				// 畫面移動偏移量
        int wallX, wallY;			// 障礙物畫面移動偏移量
        int lastX, lastY;			// 洛克人移動之前座標
        int nowX, nowY;				// 洛克人移動之後座標
        int map[31][315];			// 地圖障礙物陣列
		bool isBossCannon;			// 是否為BOSS砲彈
};
}