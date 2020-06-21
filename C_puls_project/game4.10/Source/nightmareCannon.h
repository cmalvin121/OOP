namespace game_framework
{
	class NightmareCannon
	{
	public:
		NightmareCannon();
		void LoadBitmap();					//���J����ʵe
		void SetX(int);						//�]�wX
		void SetY(int);						//�]�wY
		void SetScreenXY(int, int);			//�]�w�����ù��y��
		void AddScreenX_fix(int);			//�ץ����u�ù��y��X
		void AddScreenY_fix(int);			//�ץ����u�ù��y��Y
		void OnMove();						//���ʹϧ�
		void OnShow();						//��ܹϧ�
		void OnShowHit();					//��ܯ��u�����ʵe
		void SetVelocity(int, int);			//�]�w���u�t��(�l�ܯ��u)
		void SetLastMovingState(int);		//�]�w�W�����ʪ��A
		void SetUsingState(bool flag);		//�]�w���u�ϥΪ��A
		bool GetUsingState();				//���o���u�ϥΪ��A
		void SetCatchAction(bool);			//�]�w���u����ϥΪ̮y��
		int collision(int x, int y);		//���u�P���J�H�I��
	private:
		int x1, y1;								//�}���e�y��
		int screenX, screenY;					//�e�����y��
		int hitX, hitY;							//�l�u�����y��
		void SetHitXY();						//�]�w�����y��
		CMovingBitmap nightmareCannon;			//�Ϥ�:���L��
		CAnimation nightmareCannonHit;			//�Ϥ�:���L������
		void LoadNightmareCannonHitBitmap();	//���J�ʵe:���L������
		void HitAnimationLock();				//�����ʵe��w
		int velocity_cannon_x,velocity_cannon_y;//���L���t��
		int distance;							//��e���ʶZ��
		int lastMovingState;					//�W�������ʤ�V
		bool usingState;						//�O�_�Q�ϥΤ�
		bool catchAction;						//0:����ʧ@�A1:������ʧ@
		int isHitSomething;						//�O�_������F��
		bool isCatchHitXY;						//�O�_�^�������y��
		bool showLock;							//�����w
		bool boomsound;							//�O�_�����z������
	};
}

