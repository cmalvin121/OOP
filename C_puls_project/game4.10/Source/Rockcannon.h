namespace game_framework
{
class RockCannon
{
    public:
        RockCannon();
        void LoadBitmap();					//���J����ʵe
        void OnMove();						//���ʹϧ�
        void OnShow();						//��ܹϧ�
        void SetNowCharge(int);					//�]�w�{�b�R��
        void SetLastMovingState(int);			//�]�w�W�����ʪ��A
        void SetX(int);
        void SetY(int);
        void SetCatchAction(bool);
        bool GetUsingState();
        void SetUsingState(bool flag);
    private:
        int x1, y1;							//�}���e�y��
        int screenX, screenY;				//�e�����y��
        CAnimation normalCannon;			//�ʵe:�@�묥�J��
        CAnimation chargeCannon;			//�ʵe:�R�ଥ�J��
        CAnimation superChargeCannon;		//�ʵe:�W�ťR�ଥ�J��
        CAnimation normalCannonLeft;			//�ʵe:�@�묥�J��(��)
        CAnimation chargeCannonLeft;			//�ʵe:�R�ଥ�J��(��)
        CAnimation superChargeCannonLeft;		//�ʵe:�W�ťR�ଥ�J��(��)
        void LoadNormalCannonBitmap();		//���J�@�묥�J��
        void LoadChargeCannonBitmap();		//���J�R�ଥ�J��
        void LoadSuperChargeCannonBitmap();	//���J�W�ťR�ଥ�J��
        void LoadNormalCannonLeftBitmap();		//���J�@�묥�J��(��)
        void LoadChargeCannonLeftBitmap();		//���J�R�ଥ�J��(��)
        void LoadSuperChargeCannonLeftBitmap();	//���J�W�ťR�ଥ�J��(��)
        void SetScreen();					//�]�w�����ù��y��
        int velocity_cannon;				//���J���t��
        int nowCharge;						//�{�b�R��
        int lastMovingState;				//�W�������ʤ�V
        bool catchAction;					//0:����ʧ@�A1:������ʧ@
        bool showLock;						//�����w
        bool usingState;					//�O�_�Q�ϥΤ�
        int distance;
};
}
