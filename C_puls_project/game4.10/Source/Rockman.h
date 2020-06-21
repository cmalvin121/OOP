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
		int GetJumpDegree();			//���o���D����
		void JumpDropping();			//���D�Ḩ�U
		bool GetJumping();				//�^�Ǹ��D���A
		void Dropping();				//�O�_���b����
		bool GetDropping();				//�^�Ǹ��U���A
		void isAlreadyOnGround();		//�O�_���b�a��
        void SetSprinting(bool);		//�]�w�O�_���b�Ĩ�
        void SetKeySprintState(bool);	//�]�w�Ĩ����O�_����
		int GetSprintDegree();			//���o�Ĩ����
		void setkickWall();				//�P�_�O�_���b����
		void KickWall();				//����
        void SetAttacking(bool);		//�]�w�O�_���b����
        void SetKeyAttackingState(bool);//�]�w��������O�_����
		int GetDetermineCharge();		//���o�P�_�E��
        int GetCharge();				//���o�E��{��
		int GetChargeAttack();			//���o�į����
		bool GetIsAttacking();			//���o�O�_���b����
        int GetX();						//���oX;
        int GetY();						//���oY;
        void SetX(int);					//�]�wX
        void SetY(int);					//�]�wY
        void SetCrashState(int);		//�]�w�I�����A
        void SetCrashStateWall(int);    //�]�w�I��������A
		int getInjuredDelay();			//�^�Ǩ��˪��A
        void SetInjuredState(bool, int);//�]�w���˪��A
        void SetLife(int);				//�]�w�ͩR��(�@��)
		int Getlife();					//���o�ͩR��
        void setCannon(int x, int y, int lastMovingState);			//�]�m�l�u
        RockCannon* getCannon();		//return rockcannon[20]
		void SetFixCannonScreen(int,int);	//�ץ����J���ù��y��XY
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
        CMovingBitmap lifeItem;		// �Ϥ�:�ͩR��
        CMovingBitmap lifeValue;	// �Ϥ�:�ͩR��1
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
        CAnimation animation_InjureLeft;		//�ʵe:��������
        CAnimation animation_InjureRight;		//�ʵe:���k����
        void LoadLifeObjectBitmap();			//���J�Ϥ�:�ͩR�ȡB�ͩR��
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
        void LoadInjureLeftBitmap();			//���J�ʵe:��������
        void LoadInjureRightBitmap();			//���J�ʵe:���k����
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
		int dropDegree, landLevel;						//������m�B��������I
		int velocity_drop, initial_velocity_drop;		//��e�����t�סB��l�����t��
		int kickWallDegree;								//����{��
		bool isKickWall;								//�O�_���b����
		bool isKickWallSlide;							//�O�_���b����Ƹ�
        int charge, chargeAttack;						//�E��{�סB�E�����(�T�q��)
        int determineCharge;							//�P�_�O�_���b�E��
        int attackActionDelay;							//�����ʧ@����
        RockCannon rockcannon[20];						//����:���J��
        int crashState;									//�I�����A
        int crashState_wall;							//�O�_�I�����
        int life;										//���J�H�ͩR��
        int injureDelay;								//���˵L�Įɶ�
        int injureShine;								//���˵L�İ{�{�ܼ�
};
}