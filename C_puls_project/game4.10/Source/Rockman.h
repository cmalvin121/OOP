namespace game_framework
{
class Rockman
{
    public:
        Rockman();
        void Initialize();				//��l�ưѼ�
        void LoadBitmap();				//���J����ʵe
        void LoadAttackBitmap();		//���J��������ʵe
        void OnMove();					//���ʹϧ�
        void OnShow();					//��ܹϧ�
        void SetMovingLeft(bool);		//�]�w�O�_����
        void SetMovingRight(bool);		//�]�w�O�_���k
        void SetJumping(bool);			//�]�w�O�_���b���D
        void SetSprinting(bool);		//�]�w�O�_���b�Ĩ�
        void SetKeySprintState(bool);	//�]�w�Ĩ����O�_����
        void SetAttacking(bool);		//�]�w�O�_���b����
        void SetKeyAttackingState(bool);//�]�w��������O�_����
        int GetJumpDegree();			//���o���D����
        int GetSprintDegree();			//���o�Ĩ����
        int GetCharge();				//���o�E��{��
        int GetX();						//return x;
        int GetY();						// return y;
        void SetX(int);					//�]�wX
        void SetY(int);					//�]�wY
        void JumpDropping();			//���D�Ḩ�U
        void Dropping();				//�O�_���b����
        bool GetDropping();				//�^�Ǹ��U���A
        void isAlreadyOnGround();		//�O�_���b�a��
        void SetCrashState(int);		//�]�w�I�����A
        void SetCrashStateWall(int);    //�]�w�I��������A
        bool getInjuredState();			//�^�Ǩ��˪��A
        void setkickWall();				//�P�_�O�_���b����
        void KickWall();				//����
        void setCannon(int x, int y, int lastMovingState);				//�]�m�l�u
        RockCannon* getCannon();		//return rockcannon[20]
    private:
        bool isMovingLeft;			// �O�_���b��������
        bool isMovingRight;			// �O�_���b���k����
        bool isJumping;				// �O�_���b���D
        bool isDropping;			// �O�_���b�U��
        bool lastMovingState;       // �W�Ӳ��ʪ��A
        bool isSprinting;           // �O�_���b�Ĩ�
        bool keepkeydownSprinting;  // �@������Ĩ�
        bool isAttacking;			// �O�_���b����
        bool keepkeydownAttacking;  // �@���������
        bool isInjured;			    // �O�_����
        bool showDropping();		// �P�_�O�_�n��ܸ��U�ʧ@
        CAnimation animationRight;				//�ʵe:�V�k����
        CAnimation animationLeft;				//�ʵe:��������
        CAnimation animationMovingRight;		//�ʵe:���k����
        CAnimation animationMovingLeft;			//�ʵe:��������
        CAnimation animation_jumpRight;			//�ʵe:���k���D
        CAnimation animation_jumpLeft;			//�ʵe:�������D
        CAnimation animation_sprintRight;		//�ʵe:���k�Ĩ�
        CAnimation animation_sprintLeft;		//�ʵe:�����Ĩ�
        CAnimation animation_kickWallLeft;		//�ʵe:��������
        CAnimation animation_kickWallRight;		//�ʵe:���k����
        CAnimation animation_kickWallSlideLeft;	//�ʵe:��������Ƹ�
        CAnimation animation_kickWallSlideRight;//�ʵe:���k����Ƹ�
        void LoadRightBitmap();					//���J�ʵe:�V�k����
        void LoadLeftBitmap();					//���J�ʵe:�V������
        void LoadMovingLeftBitmap();			//���J�ʵe:�V������
        void LoadMovingRightBitmap();			//���J�ʵe:�V�k����
        void LoadJumpingLeftBitmap();			//���J�ʵe:�V�����D
        void LoadJumpingRightBitmap();			//���J�ʵe:�V�k���D
        void LoadSprintingLeftBitmap();			//���J�ʵe:�V���Ĩ�
        void LoadSprintingRightBitmap();		//���J�ʵe:�V�k�Ĩ�
        void LoadKickWallLeftBitmap();			//���J�ʵe:�V������
        void LoadKickWallRightBitmap();			//���J�ʵe:�V�k����
        void LoadKickWallSlideLeftBitmap();		//���J�ʵe:�V������Ƹ�
        void LoadKickWallSlideRightBitmap();	//���J�ʵe:�V�k����Ƹ�
        //------�H�U�������ʵe-----------------------------------------------------------
        CAnimation animationRightAttack;				//�ʵe:�V�k���ߧ���
        CAnimation animationLeftAttack;					//�ʵe:�������ߧ���
        CAnimation animationMovingRightAttack;			//�ʵe:���k���ʧ���
        CAnimation animationMovingLeftAttack;			//�ʵe:�������ʧ���
        CAnimation animation_jumpRightAttack;			//�ʵe:���k���D����
        CAnimation animation_jumpLeftAttack;			//�ʵe:�������D����
        CAnimation animation_sprintLeftAttack;			//�ʵe:���k�Ĩ����
        CAnimation animation_sprintRightAttack;			//�ʵe:�����Ĩ����
        CAnimation animation_kickWallLeftAttack;		//�ʵe:�����������
        CAnimation animation_kickWallRightAttack;		//�ʵe:���k�������
        CAnimation animation_kickWallSlideLeftAttack;	//�ʵe:��������Ƹ�����
        CAnimation animation_kickWallSlideRightAttack;  //�ʵe:���k����Ƹ�����
        void LoadRightAttackBitmap();					//���J�ʵe:�V�k���ߧ���
        void LoadLeftAttackBitmap();					//���J�ʵe:�V�����ߧ���
        void LoadMovingLeftAttackBitmap();				//���J�ʵe:�V�����ʧ���
        void LoadMovingRightAttackBitmap();				//���J�ʵe:�V�k���ʧ���
        void LoadJumpingLeftAttackBitmap();				//���J�ʵe:�V�����D����
        void LoadJumpingRightAttackBitmap();			//���J�ʵe:�V�k���D����
        void LoadSprintingLeftAttackBitmap();			//���J�ʵe:�V���Ĩ����
        void LoadSprintingRightAttackBitmap();			//���J�ʵe:�V�k�Ĩ����
        void LoadKickWallLeftAttackBitmap();			//���J�ʵe:�V���������
        void LoadKickWallRightAttackBitmap();			//���J�ʵe:�V�k�������
        void LoadKickWallSlideLeftAttackBitmap();		//���J�ʵe:�V������Ƹ�����
        void LoadKickWallSlideRightAttackBitmap();		//���J�ʵe:�V�k����Ƹ�����
        //-------------------------------------------------------------------------------
        int x, y;										//�}���e�y��
        int jumpDegree, sprintDegree;					//���D���סB�Ĩ����
        int velocity_jump, initial_velocity_jump;		//��e���D�t�סB��l���D�t��
        int velocity_sprint, initial_velocity_sprint;	//��e�Ĩ�t�סB��l�Ĩ�t��
        int charge, chargeAttack;						//�E��{�סB�E�����(�T�q��)
        int determineCharge;							//�P�_�O�_���b�E��
        int attackActionDelay;							//�����ʧ@����
        RockCannon rockcannon[20];							//����:���J��
        int dropDegree, landLevel;						//������m�B��������I
        int velocity_drop, initial_velocity_drop;		//��e�����t�סB��l�����t��
        int crashState;									//�I�����A
        int crashState_wall;							//�O�_�I�����
        int kickWallDegree;								//����{��
        bool isKickWall;								//�O�_���b����
        bool isKickWallSlide;							//�O�_���b����Ƹ�

};
}