namespace game_framework
{
/*enum skill {
    skill_one,				//�C��
    skill_two,				//���u���u
    skill_three,			//���a�O
    skill_four				//����
};*/
class BossCannon
{
    public:
        BossCannon();
        void LoadBitmap();					//���J����ʵe
        void setCannon(int t);
        void OnMove();						//���ʹϧ�
        void OnShow();						//��ܹϧ�
        void OnShowHit();
        void SetLastMovingState(int flag);		//�]�w�W�����ʪ��A
        void SetX(int x);
        void SetY(int y);
        void AddScreenX_fix(int fix);
        void AddScreenY_fix(int fix);
        void SetScreenXY(int x, int y);			//�]�w�����ù��y��
        void SetCatchAction(bool flag);
        bool GetUsingState();
        void SetUsingState(bool flag);
        int collision(int x, int y);
    private:
        int x1, y1;								//�}���e�y��
        int screenX, screenY;					//�e�����y��
        int hitX, hitY;							//�l�u�����y��
        CMovingBitmap bossCannon;				//�Ϥ�:
        CAnimation bossCannonHit;				//�Ϥ�:
        void LoadTrashCannonHitBitmap();		//���J�ʵe:�U��������
        void HitAnimationLock();				//�����ʵe��w
        void SetHitXY();						//�]�w�����y��
        int velocity_cannon;					//���J���t��
        int lastMovingState;					//�W�������ʤ�V
        int isHitSomething;						//�O�_������F��
        bool catchAction;						//0:����ʧ@�A1:������ʧ@
        bool showLock;							//�����w
        bool usingState;						//�O�_�Q�ϥΤ�
        bool isCatchHitXY;						//�O�_�^�������y��
        int distance;
        int type;								//1 = �C��  2 = ���u���u  3 = ���a�O
};
}