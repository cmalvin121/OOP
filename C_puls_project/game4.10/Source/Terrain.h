namespace game_framework
{
class Terrain     //�a��(�c�l�B���)
{
    public:
        Terrain();
        void LoadBitMap();					//���J�Ϥ�
        void Initialize();					//��l�ưѼ�
		void GetLastRockmanXY(int x, int y);//�a�ϧ�����J�H���ʫe���y��
		void GetNowRockmanXY(int x, int y);	//�a�ϧ�����J�H���ʫᤧ�y��
        void MoveScreen();					//�e������
        int GetLastX();						//���o���J�H���ʫe���y��X
        int GetLastY();						//���o���J�H���ʫe���y��Y
        int crashleft();					//����I���P�_
        int crashright();					//�k��I���P�_
        int crashtop();						//�W��I���P�_
        int crashdown();					//�U��I���P�_
        bool MonsterCollision();			//���J�H�P�Ҧ��Ǫ����I��
        int MosterCannonCollision();		//���J�H�P�Ҧ��Ǫ����u���I��
		bool GetIsBossCannon();				//���o�O�_��BOSS�����u
        //////////////////////// Monster
        Monster getMonster(int index);		//���o�U����
        Nightmare getNightmare(int index);	//���o���L
        Bat getBat(int index);				//���o����
		Boss getBoss();						//���o���L�Ǭ�
        void setMonsterLife(int index, int damage, int monsterNum);	//�]�w���w�Ǫ����ͩR
        int getMonsterLife(int index, int monsterNum);				//���o���w�Ǫ����ͩR
		bool IsBossStage();											//�O�_��BOSS�԰�
		bool IsBossDead();											//�O�_BOSS�w���`
        void setLifeToZero();										//�Ҧ��p�Ǧ�q�j���k0(�@��)
		void OnShow();												//��ܹϤ�
        ////////////////////////////////
    protected:
        CMovingBitmap	background;	// �I����
        CMovingBitmap	background2;// �I����2
        CMovingBitmap	background3;// �I����3
        CMovingBitmap	background4;// �I����4
        CMovingBitmap	block;		// ��ê��
        CMovingBitmap	deadBlock;	// �y��B�L���}
        Boss boss;					// ���L�Ǭ�
        Monster X6_1[8];			// �U����
        Nightmare X6_2[6];			// ���L
        Bat X4_1[6];				// ����
        int picX, picY;				// �e�����ʰ����q
        int wallX, wallY;			// ��ê���e�����ʰ����q
        int lastX, lastY;			// ���J�H���ʤ��e�y��
        int nowX, nowY;				// ���J�H���ʤ���y��
        int map[31][315];			// �a�ϻ�ê���}�C
		bool isBossCannon;			// �O�_��BOSS���u
};
}