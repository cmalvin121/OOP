namespace game_framework
{
class Rockman
{
    public:
        Rockman();
        void Initialize();				//初始化參數
        void LoadBitmap();				//載入角色動畫
        void LoadAttackBitmap();		//載入角色攻擊動畫
        void OnMove();					//移動圖形
        void OnShow();					//顯示圖形
        void SetMovingLeft(bool);		//設定是否往左
        void SetMovingRight(bool);		//設定是否往右
        void SetJumping(bool);			//設定是否正在跳躍
        void SetSprinting(bool);		//設定是否正在衝刺
        void SetKeySprintState(bool);	//設定衝刺按鍵是否按住
        void SetAttacking(bool);		//設定是否正在攻擊
        void SetKeyAttackingState(bool);//設定攻擊按鍵是否按住
        int GetJumpDegree();			//取得跳躍高度
        int GetSprintDegree();			//取得衝刺長度
        int GetCharge();				//取得聚氣程度
        int GetX();						//return x;
        int GetY();						// return y;
        void SetX(int);					//設定X
        void SetY(int);					//設定Y
        void JumpDropping();			//跳躍後落下
        void Dropping();				//是否正在降落
        bool GetDropping();				//回傳落下狀態
        void isAlreadyOnGround();		//是否正在地面
        void SetCrashState(int);		//設定碰撞狀態
        void SetCrashStateWall(int);    //設定碰撞牆壁狀態
        bool getInjuredState();			//回傳受傷狀態
        void setkickWall();				//判斷是否正在踢牆
        void KickWall();				//踢牆
        void setCannon(int x, int y, int lastMovingState);				//設置子彈
        RockCannon* getCannon();		//return rockcannon[20]
    private:
        bool isMovingLeft;			// 是否正在往左移動
        bool isMovingRight;			// 是否正在往右移動
        bool isJumping;				// 是否正在跳躍
        bool isDropping;			// 是否正在下降
        bool lastMovingState;       // 上個移動狀態
        bool isSprinting;           // 是否正在衝刺
        bool keepkeydownSprinting;  // 一直按住衝刺
        bool isAttacking;			// 是否正在攻擊
        bool keepkeydownAttacking;  // 一直按住攻擊
        bool isInjured;			    // 是否受傷
        bool showDropping();		// 判斷是否要顯示落下動作
        CAnimation animationRight;				//動畫:向右站立
        CAnimation animationLeft;				//動畫:往左站立
        CAnimation animationMovingRight;		//動畫:往右移動
        CAnimation animationMovingLeft;			//動畫:往左移動
        CAnimation animation_jumpRight;			//動畫:往右跳躍
        CAnimation animation_jumpLeft;			//動畫:往左跳躍
        CAnimation animation_sprintRight;		//動畫:往右衝刺
        CAnimation animation_sprintLeft;		//動畫:往左衝刺
        CAnimation animation_kickWallLeft;		//動畫:往左踢牆
        CAnimation animation_kickWallRight;		//動畫:往右踢牆
        CAnimation animation_kickWallSlideLeft;	//動畫:往左踢牆滑落
        CAnimation animation_kickWallSlideRight;//動畫:往右踢牆滑落
        void LoadRightBitmap();					//載入動畫:向右站立
        void LoadLeftBitmap();					//載入動畫:向左站立
        void LoadMovingLeftBitmap();			//載入動畫:向左移動
        void LoadMovingRightBitmap();			//載入動畫:向右移動
        void LoadJumpingLeftBitmap();			//載入動畫:向左跳躍
        void LoadJumpingRightBitmap();			//載入動畫:向右跳躍
        void LoadSprintingLeftBitmap();			//載入動畫:向左衝刺
        void LoadSprintingRightBitmap();		//載入動畫:向右衝刺
        void LoadKickWallLeftBitmap();			//載入動畫:向左踢牆
        void LoadKickWallRightBitmap();			//載入動畫:向右踢牆
        void LoadKickWallSlideLeftBitmap();		//載入動畫:向左踢牆滑落
        void LoadKickWallSlideRightBitmap();	//載入動畫:向右踢牆滑落
        //------以下為攻擊動畫-----------------------------------------------------------
        CAnimation animationRightAttack;				//動畫:向右站立攻擊
        CAnimation animationLeftAttack;					//動畫:往左站立攻擊
        CAnimation animationMovingRightAttack;			//動畫:往右移動攻擊
        CAnimation animationMovingLeftAttack;			//動畫:往左移動攻擊
        CAnimation animation_jumpRightAttack;			//動畫:往右跳躍攻擊
        CAnimation animation_jumpLeftAttack;			//動畫:往左跳躍攻擊
        CAnimation animation_sprintLeftAttack;			//動畫:往右衝刺攻擊
        CAnimation animation_sprintRightAttack;			//動畫:往左衝刺攻擊
        CAnimation animation_kickWallLeftAttack;		//動畫:往左踢牆攻擊
        CAnimation animation_kickWallRightAttack;		//動畫:往右踢牆攻擊
        CAnimation animation_kickWallSlideLeftAttack;	//動畫:往左踢牆滑落攻擊
        CAnimation animation_kickWallSlideRightAttack;  //動畫:往右踢牆滑落攻擊
        void LoadRightAttackBitmap();					//載入動畫:向右站立攻擊
        void LoadLeftAttackBitmap();					//載入動畫:向左站立攻擊
        void LoadMovingLeftAttackBitmap();				//載入動畫:向左移動攻擊
        void LoadMovingRightAttackBitmap();				//載入動畫:向右移動攻擊
        void LoadJumpingLeftAttackBitmap();				//載入動畫:向左跳躍攻擊
        void LoadJumpingRightAttackBitmap();			//載入動畫:向右跳躍攻擊
        void LoadSprintingLeftAttackBitmap();			//載入動畫:向左衝刺攻擊
        void LoadSprintingRightAttackBitmap();			//載入動畫:向右衝刺攻擊
        void LoadKickWallLeftAttackBitmap();			//載入動畫:向左踢牆攻擊
        void LoadKickWallRightAttackBitmap();			//載入動畫:向右踢牆攻擊
        void LoadKickWallSlideLeftAttackBitmap();		//載入動畫:向左踢牆滑落攻擊
        void LoadKickWallSlideRightAttackBitmap();		//載入動畫:向右踢牆滑落攻擊
        //-------------------------------------------------------------------------------
        int x, y;										//腳色當前座標
        int jumpDegree, sprintDegree;					//跳躍高度、衝刺長度
        int velocity_jump, initial_velocity_jump;		//當前跳躍速度、初始跳躍速度
        int velocity_sprint, initial_velocity_sprint;	//當前衝刺速度、初始衝刺速度
        int charge, chargeAttack;						//聚氣程度、聚氣攻擊(三段式)
        int determineCharge;							//判斷是否正在聚氣
        int attackActionDelay;							//攻擊動作延遲
        RockCannon rockcannon[20];							//物件:洛克炮
        int dropDegree, landLevel;						//降落位置、降落基準點
        int velocity_drop, initial_velocity_drop;		//當前降落速度、初始降落速度
        int crashState;									//碰撞狀態
        int crashState_wall;							//是否碰撞牆壁
        int kickWallDegree;								//踢牆程度
        bool isKickWall;								//是否正在踢牆
        bool isKickWallSlide;							//是否正在踢牆滑落

};
}