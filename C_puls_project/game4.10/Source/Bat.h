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
		int getX();							//���o����X�y��
		int getY();							//���o����Y�y��
		int getScreenX();					//���o����X�ù��y��
		int getScreenY();					//���o����Y�ù��y��
		void setAlive(bool state);			//�]�w�s�����A
		bool getAlive();					//���o�s�����A
		int getLife();						//���o�ͩR��
		void deductLife(int damage);		//�����ͩR��
		void OnShow();						//��ܰʵe
		void OnShowBoom();					//����z���ʵe
		void DeterminAttack(int, int);		//�M�w�����Ҧ�
		bool MonsterCollision(int, int);	//�P���J�H�I���P�_
	private:
		int x, y;							//�y��
		int s_x, s_y;						//�ù��y�а����q
		int life;							//�ͩR
		bool isAlive;						//�s�����A
		CAnimation monsMovingRight;			//�ʵe:���k����
		CAnimation monsMovingLeft;			//�ʵe:��������
		CAnimation monsBoom;				//�ʵe:�z��
		void LoadMovingRightBitMap();		//���J�ʵe:���k����
		void LoadMovingLeftBitMap();		//���J�ʵe:��������
		void LoadBoomBitmap();				//���J�Ҧ��ʵe
		bool AttackDirection;				//������V,0:�����g,1:���k�g
		int AttackMode;						//�����Ҧ� 0:�R�� 1:����
		void moveAttack(int, int);			//�ļ�����
	};
}