namespace game_framework
{
	class NightmareCannon
	{
	public:
		NightmareCannon();
		void LoadBitmap();					//���J����ʵe
		void OnMove();						//���ʹϧ�
		void OnShow();						//��ܹϧ�
		void OnShowHit();
		void SetLastMovingState(int);		//�]�w�W�����ʪ��A
		void SetX(int);
		void SetY(int);
		void AddScreenX_fix(int);
		void AddScreenY_fix(int);
		void SetScreenXY(int, int);			//�]�w�����ù��y��
		void SetVelocity(int, int);
		void SetCatchAction(bool);
		bool GetUsingState();
		void SetUsingState(bool flag);
		int collision(int x, int y);
	private:
		int x1, y1;								//�}���e�y��
		int screenX, screenY;					//�e�����y��
		int hitX, hitY;							//�l�u�����y��
		bool boomsound;
		CMovingBitmap nightmareCannon;			//�Ϥ�:���L��
		CAnimation nightmareCannonHit;			//�Ϥ�:���L������
		void LoadNightmareCannonHitBitmap();	//���J�ʵe:���L������
		void HitAnimationLock();				//�����ʵe��w
		void SetHitXY();						//�]�w�����y��
		int velocity_cannon_x,velocity_cannon_y;//���L���t��
		int lastMovingState;					//�W�������ʤ�V
		int isHitSomething;						//�O�_������F��
		bool catchAction;						//0:����ʧ@�A1:������ʧ@
		bool showLock;							//�����w
		bool usingState;						//�O�_�Q�ϥΤ�
		bool isCatchHitXY;						//�O�_�^�������y��
		int distance;
	};
}

