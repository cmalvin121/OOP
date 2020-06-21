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
		void FixCannonScreenXY(int, int);	//�ץ��ù��y��
		int getX();							//���o���LX�y��
		int getY();							//���o���LY�y��
		int getScreenX();					//���o���LX�ù��y��
		int getScreenY();					//���o���LY�ù��y��
		void setAlive(bool state);			//�]�w�s�����A
		bool getAlive();					//���o�s�����A
		int getLife();						//���o�ͩR��
		void deductLife(int damage);		//�����ͩR��
		void OnShow();						//��ܰʵe
		void OnShowBoom();					//����z���ʵe
		void DeterminAttack(int, int);		//�M�w�����Ҧ�
		bool MonsterCollision(int, int);	//�P���J�H�I���P�_
		int  MonsterCannonCollision(int, int);//���u�P���J�H�I���P�_
	private:
		int x, y;							//�y��
		int s_x, s_y;						//�ù��y�а����q
		int life;							//�ͩR
		bool isAlive;						//�s�����A
		CAnimation monsRight;				//�ʵe:�V�k����
		CAnimation monsLeft;				//�ʵe:��������
		CAnimation monsMovingRight;			//�ʵe:�V�k����
		CAnimation monsMovingLeft;			//�ʵe:��������
		CAnimation monsRightAttack;			//�ʵe:�V�k�g��
		CAnimation monsLeftAttack;			//�ʵe:�����g��
		CAnimation monsBoom;				//�ʵe:�z��
		void LoadRightBitMap();				//���J�ʵe:�V�k����
		void LoadLeftBitMap();				//���J�ʵe:��������
		void LoadMovingRightBitMap();		//���J�ʵe:�V�k����
		void LoadMovingLeftBitMap();		//���J�ʵe:��������
		void LoadattackRightBitMap();		//���J�ʵe:�V�k�g��
		void LoadattackLeftBitMap();		//���J�ʵe:�����g��
		void LoadBoomBitmap();				//���J�ʵe:�z��
		NightmareCannon cannon;				//���L��
		int AttackDelay;					//���u��������
		int moveDelay;						//���ʧ�������
		int determinActionDelay;			//�M�w�����Ҧ�����
		bool AttackDirection;				//������V,0:�����g,1:���k�g
		int AttackMode;						//�����Ҧ� 0:�R�� 1:���� 2:�}��
		void moveAttack(int, int);			//�����Ҧ�:�ļ�����
		void fire(int, int);				//�����Ҧ�:����
		void stay();						//�����Ҧ�:�ݾ�
		bool firesound;						//�O�_����g������
	};
}