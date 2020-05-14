namespace game_framework
{
	class Monster
	{
	public:
		Monster();
		void LoadBitMap();
		void setXY(int nx, int ny);
		void setScreenXY(int nx, int ny);
		void setAlive(bool state);
		int getScreenX();
		int getScreenY();
		void OnShow();
		void DeterminAttack(int, int);
	private:
		bool isAlive;
		int x, y;
		int s_x, s_y;
		int life;
		bool AttackDirection;				//0:�����g,1:���k�g
		int nowAttackDistance;
		int AttackDelay;
		CMovingBitmap monsRight;
		CMovingBitmap monsLeft;
		CMovingBitmap monsRightAttack;
		CMovingBitmap monsLeftAttack;
	};
}