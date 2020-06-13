namespace game_framework
{
	class Bat
	{
	public:
		Bat();
		void Initialize();					//��l�ưѼ�
		void LoadBitMap();					//���J�Ϥ�
		void setXY(int nx, int ny);			//�]�wXY
		void setScreenXY(int nx, int ny);	//�]�w�ù�XY
		void setAlive(bool state);			//�]�w�s�����A
		int getX();							//���o����X�y��
		int getY();							//���o����Y�y��
		int getScreenX();					//���o����X�ù��y��
		int getScreenY();					//���o����Y�ù��y��
		bool getAlive();					//���o�s�����A
		void OnShow();						//��ܰʵe
		void OnShowBoom();					//����z���ʵe
		void DeterminAttack(int, int);		//�M�w�����Ҧ�
		bool MonsterCollision(int, int);	//�P���J�H�I���P�_
		void deductLife(int damage);		//�����ͩR��
	private:
		bool isAlive;						//�s�����A
		int x, y;							//�y��
		int s_x, s_y;						//�ù��y�а����q
		int life;							//�ͩR
		bool AttackDirection;				//0:�����g,1:���k�g
		int AttackMode;						//�����Ҧ� 0:�R�� 1:����
		CAnimation monsMovingRight;
		CAnimation monsMovingLeft;
		void moveAttack(int, int);
		void LoadMovingRightBitMap();
		void LoadMovingLeftBitMap();
		CAnimation monsBoom;
		void LoadBoomBitmap();
	};
}