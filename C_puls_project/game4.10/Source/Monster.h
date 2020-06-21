namespace game_framework
{
	class Monster
	{
	public:
		Monster();
		void Initialize();						//��l�ưѼ�
		void LoadBitMap();						//���J�Ϥ�
		void setXY(int nx, int ny);				//�]�wXY
		void setScreenXY(int nx, int ny);		//�]�w�ù�XY
		void FixCannonScreenXY(int, int);		//�ץ����u�ù�XY
		int getX();								//���o����X�y��
		int getY();								//���o����Y�y��
		int getScreenX();						//���o����X�ù��y��
		int getScreenY();						//���o����Y�ù��y��
		void setAlive(bool state);				//�]�w�s�����A
		bool getAlive();						//���o�s�����A
		int getLife();							//���o�ͩR��
		void deductLife(int damage);			//�����ͩR��
		void OnShow();							//��ܰʵe
		void OnShowBoom();						//����z���ʵe
		void DeterminAttack(int, int);			//�M�w�����Ҧ�
		bool MonsterCollision(int, int);		//�P���J�H�I���P�_
		int  MonsterCannonCollision(int, int);	//�����P���J�H�I���P�_
	private:
		int x, y;								//�y��
		int s_x, s_y;							//�ù��y��
		int life;								//�ͩR
		bool isAlive;							//�s�����A
		CMovingBitmap monsRight;				//�Ϥ�:���k����
		CMovingBitmap monsLeft;					//�Ϥ�:��������
		CMovingBitmap monsRightAttack;			//�Ϥ�:���k����
		CMovingBitmap monsLeftAttack;			//�Ϥ�:��������
		CAnimation monsBoom;					//�ʵe:�z��
		void LoadBoomBitmap();					//���J�ʵe:�z��
		TrashCannon cannon;						//�U����
		bool AttackDirection;					//������V,0:�����g,1:���k�g
		int AttackDelay;						//��������
		int nowAttackDistance;					//��e�����Z��
	};
}