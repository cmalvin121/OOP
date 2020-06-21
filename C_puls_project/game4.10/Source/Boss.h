namespace game_framework
{
class Boss
{
    public:
        Boss();
        void Initialize();								//��l�ưѼ�
        void LoadBitMap();								//���J�Ϥ�
		void setXY(int nx, int ny);						//�]�wXY
		void setScreen_XY(int nx, int ny);				//�]�w�ù�XY
		void FixCannonScreenXY(int, int);				//�ץ����u�ù�XY
		int getX();										//���o���L�Ǭ�X�y��
		int getY();										//���o���L�Ǭ�Y�y��
		int getScreenX();								//���o���L�Ǭ�X�ù��y��
		int getScreenY();								//���o���L�Ǭ�Y�ù��y��
		bool getAlive();								//���o�s�����A
		int getLife();									//���o�ͩR��
		void deductLife(int damage);					//�����ͩR��
        void OnShow();									//��ܰʵe
        void OnMove(int RockX, int RockY);				//���Ⲿ��
        void DeterminAttack(int RockX, int RockY);		//�M�w�����Ҧ�
		bool GetStartAttack();							//���o����O�_�}�l����
        bool MonsterCollision(int, int);				//�P���J�H�I���P�_
        int MonsterCannonCollision(int, int);			//�����P���J�H�I���P�_
    private:
		int x, y;										//�y��
		int screen_x, screen_y;							//�ù��y�а����q
		int life;										//�ͩR
		bool isAlive;									//�s�����A
		CMovingBitmap boss;								//�Ϥ�:�V�k����
		CMovingBitmap bossLeft;							//�Ϥ�:��������
		CAnimation bossSprint;							//�ʵe:�V�k�Ĩ�
		CAnimation bossSprintLeft;						//�ʵe:�����Ĩ�
		CAnimation bossFire;							//�ʵe:�V�k�g��
		CAnimation bossFireLeft;						//�ʵe:�����g��
		CAnimation bossChop;							//�ʵe:�V�k����
		CAnimation bossChopLeft;						//�ʵe:��������
		CAnimation bossDestoryLight;					//�ʵe:���{��(�l�a�O)
		CAnimation bossKill;							//�ʵe:�۹ڹs(�k)(�W�j�C��)
		CAnimation bossKillLeft;						//�ʵe:�۹ڹs(��)(�W�j�C��)
		CAnimation hugeknife;							//�ʵe:�۹ڹs�R��
		CAnimation knife;								//�ʵe:�����C(�k)
		CAnimation knifeLeft;							//�ʵe:�����C(��)
		CMovingBitmap lifeItem;							//�Ϥ�:�ͩR��
		CMovingBitmap lifeValue;						//�Ϥ�:�ͩR��
		void LoadBossSprintBitMap();					//���J�ʵe:�V�k�Ĩ�
		void LoadBossSprintLeftBitMap();				//���J�ʵe:�����Ĩ�
		void LoadBossFireBitMap();						//���J�ʵe:�V�k�g��
		void LoadBossFireLeftBitMap();					//���J�ʵe:�����g��
		void LoadBossChopBitMap();						//���J�ʵe:�V�k����
		void LoadBossChopLeftBitMap();					//���J�ʵe:��������
		void LoadBossDestoryLightBitMap();				//���J�ʵe:���{��(�l�a�O)
		void LoadBossKillBitMap();						//���J�ʵe:�۹ڹs(�k)(�W�j�C��)
		void LoadBossKillLeftBitMap();					//���J�ʵe:�۹ڹs(��)(�W�j�C��)
		void LoadHugeknifeBitMap();						//���J�ʵe:�۹ڹs�R��
		void LoadKnifeBitMap();							//���J�ʵe:�����C(�k)
		void LoadKnifeLeftBitMap();						//���J�ʵe:�����C(��)
		void LoadLifeObjectBitmap();					//���J�Ϥ�:�ͩR����
		void ResetAnimation();							//���m�ʵe
        BossCannon cannon[6];							//���L�Ǭ����u
		bool startAttack;								//�O�_�}�l����
		bool isfire;									//�O�_�w�g��
		int attackDelay;								//��������
		int AttackDirection;							//������V,0:�����g,1:���k�g
		int KillDirection;								//�۹ڹs(�W�j�C��)������V
		int AttackCommand[15];							//�������O
		int commandProcess;								//���O�i�{
		int reverse;									//������V����
        int skill;										//��e�������ޯ�
		void Stay();									//�����Ҧ�:�ݾ�
		void Sprint();									//�����Ҧ�:�Ĩ�
		void Fire();									//�����Ҧ�:����
		void FireFlySword(int RockX, int RockY);		//�����Ҧ�:�l�ܭ��M
		void DestroyLight();							//�����Ҧ�:���{��(�l�a�O)
		void Kill();									//�����Ҧ�:�۹ڹs(�W�j�C��)
		bool isInjured;									//�O�_�w�g����
		int injureDelay;								//���˵L�Įɶ�
		int injureShine;								//�L�Įɶ��{�{
		bool isPlaySound;								//�O�_���񭵮�
		int destroyLightCount;							//���{��(�l�a�O)���ĭp�ƾ�
};
}