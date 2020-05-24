namespace game_framework
{
class RockCannon
{
    public:
        RockCannon();
        void LoadBitmap();					//���J����ʵe
        void OnMove();						//���ʹϧ�
        void OnShow();						//��ܹϧ�
		void OnShowHit();
        void SetNowCharge(int);					//�]�w�{�b�R��
        void SetLastMovingState(int);			//�]�w�W�����ʪ��A
        void SetX(int);
        void SetY(int);
        void SetCatchAction(bool);
        bool GetUsingState();
        void SetUsingState(bool flag);
        void SetFixScreen(int,int);
        int collision(int x, int y,bool MonsterisAlive);
    private:
        int x1, y1;								//�}���e�y��
        int screenX, screenY;					//�e�����y��
		int hitX, hitY;							//�l�u�����y��
        CAnimation normalCannon;				//�ʵe:�@�묥�J��
        CAnimation chargeCannon;				//�ʵe:�R�ଥ�J��
        CAnimation superChargeCannon;			//�ʵe:�W�ťR�ଥ�J��
        CAnimation normalCannonLeft;			//�ʵe:�@�묥�J��(��)
        CAnimation chargeCannonLeft;			//�ʵe:�R�ଥ�J��(��)
        CAnimation superChargeCannonLeft;		//�ʵe:�W�ťR�ଥ�J��(��)
		CAnimation normalCannonHit;				//�ʵe:�@��B�R�ଥ�J������
		CAnimation normalCannonHitLeft;			//�ʵe:�@��B�R�ଥ�J������(��)
		CAnimation superChargeCannonHit;		//�ʵe:�W�ťR�ଥ�J������
		CAnimation superChargeCannonHitLeft;	//�ʵe:�W�ťR�ଥ�J������(��)
        void LoadNormalCannonBitmap();			//���J�ʵe:�@�묥�J��
        void LoadChargeCannonBitmap();			//���J�ʵe:�R�ଥ�J��
        void LoadSuperChargeCannonBitmap();		//���J�ʵe:�W�ťR�ଥ�J��
        void LoadNormalCannonLeftBitmap();		//���J�ʵe:�@�묥�J��(��)
        void LoadChargeCannonLeftBitmap();		//���J�ʵe:�R�ଥ�J��(��)
        void LoadSuperChargeCannonLeftBitmap();	//���J�ʵe:�W�ťR�ଥ�J��(��)
		void LoadNormalCannonHitBitmap();		//���J�ʵe:�@��B�R�ଥ�J������
		void LoadNormalCannonHitLeftBitmap();	//���J�ʵe:�@��B�R�ଥ�J������(��)
		void LoadSuperChargeCannonHitBitmap();	//���J�ʵe:�W�ťR�ଥ�J������
		void LoadSuperChargeCannonHitLeftBitmap();//���J�ʵe:�W�ťR�ଥ�J������(��)
		void HitAnimationLock();				//�����ʵe��w
        void SetScreen();						//�]�w�����ù��y��
		void SetHitXY();						//�]�w�����y��
        int velocity_cannon;					//���J���t��
        int nowCharge;							//�{�b�R��
        int lastMovingState;					//�W�������ʤ�V
		int isHitSomething;						//�O�_������F��
        bool catchAction;						//0:����ʧ@�A1:������ʧ@
        bool showLock;							//�����w
        bool usingState;						//�O�_�Q�ϥΤ�
		bool isCatchHitXY;						//�O�_�^�������y��
        int distance;
};
}
