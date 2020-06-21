namespace game_framework
{
class BossCannon
{
    public:
        BossCannon();
        void LoadBitMap();						//���J���u�ʵe
		void SetX(int x);						//�]�wX
		void SetY(int y);						//�]�wY
		void SetScreenXY(int x, int y);			//�]�w���u�ù��y��XY
		void AddScreenX_fix(int fix);			//�ץ����u�ù��y��X
		void AddScreenY_fix(int fix);			//�ץ����u�ù��y��Y
		void OnMove();							//���ʹϧ�
		void OnShow();							//��ܹϧ�
        void setCannon(int t);					//�]�w���u���A
		void SetVelocity(int RockX, int RockY);	//�]�w���u�t��(�l�ܯ��u)
        void SetLastMovingState(int flag);		//�]�w�W�����ʪ��A
        void SetUsingState(bool flag);			//�]�w���u�ϥΪ��A
        bool GetUsingState();					//���o���u�ϥΪ��A
        void SetCatchAction(bool flag);			//�]�w���u����ϥΪ̮y��
        int collision(int x, int y);			//���u�P���J�H�I��
    private:
        int x1, y1;								//�����e�y��
        int screenX, screenY;					//�e���y��
        int hitX, hitY;							//�l�u�����y��
		CAnimation cannon;						//�ʵe:���ۯ�(�k)
		CAnimation cannonLeft;					//�ʵe:���ۯ�(��)
		CAnimation flySword;					//�ʵe:�l�ܭ��M(�k)
		CAnimation flySwordLeft;				//�ʵe:�l�ܭ��M(��)
		CAnimation destroyLight;				//�ʵe:���{�����u(�l�a�O���u)
		CMovingBitmap hugeSword;				//�Ϥ�:�۹ڹs�C��(�k)
		CMovingBitmap hugeSwordLeft;			//�Ϥ�:�۹ڹs�C��(��)
		void LoadCannonBitMap();				//�ʵe:���ۯ�(�k)
		void LoadCannonLeftBitMap();			//�ʵe:���ۯ�(��)
		void LoadFlySwordBitMap();				//�ʵe:�l�ܭ��M(�k)
		void LoadFlySwordLeftBitMap();			//�ʵe:�l�ܭ��M(��)
		void LoadDestroyLightBitMap();			//�ʵe:���{�����u(�l�a�O���u)
		int type;								//1 = �۹ڹs�C��  2 = ���ۯ�  3 = ���{�����u(�l�a�O���u) 4 = �l�ܭ��M
        int velocity_cannon_x;					//���L�Ǭ����t��
		int velocity_cannon_y;					//���L�Ǭ����t��
		int distance;							//��e���ʶZ��
        int lastMovingState;					//�W�������ʤ�V
		bool usingState;						//�O�_�Q�ϥΤ�
		bool catchAction;						//0:����ʧ@�A1:������ʧ@
        int isHitSomething;						//�O�_������F��
		bool isCatchHitXY;						//�O�_�^�������y��
        bool showLock;							//�����w
};
}