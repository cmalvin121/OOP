namespace game_framework
{
	class Monster
	{
	public:
		Monster();
		void Initialize();
		void LoadBitMap();
		void setXY(int nx, int ny);
		void setScreenXY(int nx, int ny);
		void setAlive(bool state);
		int getX();
		int getY();
		int getScreenX();
		int getScreenY();
		bool getAlive();
		int getLife();
		void OnShow();
		void OnShowBoom();
		void DeterminAttack(int, int);
		bool MonsterCollision(int, int);
		int  MonsterCannonCollision(int, int);
		void deductLife(int damage);
		void FixCannonScreenXY(int, int);
	private:
		bool isAlive;
		int x, y;
		int s_x, s_y;
		int life;
		bool AttackDirection;				//0:©¹¥ª®g,1:©¹¥k®g
		int nowAttackDistance;
		int AttackDelay;
		CMovingBitmap monsRight;
		CMovingBitmap monsLeft;
		CMovingBitmap monsRightAttack;
		CMovingBitmap monsLeftAttack;
		CAnimation monsBoom;
		TrashCannon cannon;
		void LoadBoomBitmap();
	};
}