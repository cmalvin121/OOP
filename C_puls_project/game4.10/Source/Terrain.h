namespace game_framework
{
	class Terrain     //�a��(�c�l�B���)
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
		CMovingBitmap	background;	// �I����
		CMovingBitmap	background2;// �I����2
		CMovingBitmap	background3;// �I����3
		CMovingBitmap	background4;// �I����4
		CMovingBitmap	block;		// ��ê��
		CMovingBitmap	deadBlock;	// �y��B�L���}
		Monster X6_1;
		int picX, picY;
		int wallX, wallY;
		int lastX, lastY;
		int nowX, nowY;
		int map[31][315];
	};
}