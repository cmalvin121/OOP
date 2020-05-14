namespace game_framework
{
	class Terrain     //地形(箱子、方塊)
	{
	public:
		Terrain();
		void LoadBitMap();
		void OnShow();
		void Initialize();
		void MoveScreen();
		void GetLastRockmanXY(int x, int y);
		void GetNowRockmanXY(int x, int y);
		int GetLastX();
		int GetLastY();
		int crashleft();
		int crashright();
		int crashtop();
		int crashdown();
	protected:
		CMovingBitmap	background;	// 背景圖
		CMovingBitmap	background2;// 背景圖2
		CMovingBitmap	background3;// 背景圖3
		CMovingBitmap	background4;// 背景圖4
		CMovingBitmap	block;		// 障礙物
		CMovingBitmap	deadBlock;	// 尖刺、無底洞
		Monster X6_1;
		int picX, picY;
		int wallX, wallY;
		int lastX, lastY;
		int nowX, nowY;
		int map[31][315];
	};
}