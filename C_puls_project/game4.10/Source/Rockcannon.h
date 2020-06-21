namespace game_framework
{
class RockCannon
{
    public:
        RockCannon();
        void LoadBitmap();														//���J����ʵe
		void SetX(int);															//�]�wX
		void SetY(int);															//�]�wY
		void SetFixScreen(int, int);											//�]�w�����ù��y�Эץ�
        void OnMove();															//���ʹϧ�
        void OnShow();															//��ܹϧ�
		void OnShowHit();														//��ܯ��u�����ʵe
		void SetNowCharge(int);													//�]�w�{�b�R��
		void SetLastMovingState(int);											//�]�w�W�����ʪ��A
		void SetUsingState(bool flag);											//�]�w���u�ϥΪ��A
		bool GetUsingState();													//���o���u�ϥΪ��A
        void SetCatchAction(bool);												//�]�w���u����ϥΪ̮y��
        int collision(int x, int y,bool MonsterisAlive, int monsterNum);		//���u�P�Ǫ��I��
    private:
        int x1, y1;								//�}���e�y��
        int screenX, screenY;					//�e�����y��
		int hitX, hitY;							//�l�u�����y��
		void SetScreen();						//�]�w�����ù��y��
		void SetHitXY();						//�]�w�����y��
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
		int nowCharge;							//�{�b�R��
        int velocity_cannon;					//���J���t��
		int distance;							//��e���ʶZ��
        int lastMovingState;					//�W�������ʤ�V
		bool usingState;						//�O�_�Q�ϥΤ�
		bool catchAction;						//0:����ʧ@�A1:������ʧ@
		int isHitSomething;						//�O�_������F��
		bool isCatchHitXY;						//�O�_�^�������y��
        bool showLock;							//�����w
};
}
