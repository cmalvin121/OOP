namespace game_framework
{
	class Nightmare
	{
	public:
		Nightmare();
		void Initialize();					//��l�ưѼ�
		void LoadBitMap();					//���J�Ϥ�
		void setXY(int nx, int ny);			//�]�wXY
		void setScreenXY(int nx, int ny);	//�]�w�ù�XY
		void setAlive(bool state);			//�]�w�s�����A
		int getX();							//���o���LX�y��
		int getY();							//���o���LY�y��
		int getScreenX();					//���o���LX�ù��y��
		int getScreenY();					//���o���LY�ù��y��
		bool getAlive();					//���o�s�����A
		int getLife();
		void OnShow();						//��ܰʵe
		void OnShowBoom();					//����z���ʵe
		void DeterminAttack(int, int);		//�M�w�����Ҧ�
		bool MonsterCollision(int, int);	//�P���J�H�I���P�_
		int  MonsterCannonCollision(int, int);//���u�P���J�H�I���P�_
		void deductLife(int damage);		//�����ͩR��
		void FixCannonScreenXY(int, int);	//�ץ��ù��y��
	private:
		bool isAlive;						//�s�����A
		int x, y;							//�y��
		int s_x, s_y;						//�ù��y�а����q
		int life;							//�ͩR
		bool AttackDirection;				//0:�����g,1:���k�g
		int AttackDelay;					//���u��������
		int moveDelay;						//���ʧ�������
		int determinActionDelay;			//�M�w�����Ҧ�����
		int AttackMode;						//�����Ҧ� 0:�R�� 1:���� 2:�}��
		bool firesound;
		CAnimation monsRight;
		CAnimation monsLeft;
		CAnimation monsMovingRight;
		CAnimation monsMovingLeft;
		CAnimation monsRightAttack;
		CAnimation monsLeftAttack;
		void moveAttack(int,int);
		void fire(int, int);
		void stay();
		void LoadRightBitMap();
		void LoadLeftBitMap();
		void LoadMovingRightBitMap();
		void LoadMovingLeftBitMap();
		void LoadattackRightBitMap();
		void LoadattackLeftBitMap();
		CAnimation monsBoom;
		NightmareCannon cannon;
		void LoadBoomBitmap();
	};
}