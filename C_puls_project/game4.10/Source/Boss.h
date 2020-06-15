namespace game_framework
{
class Boss
{
    public:
        Boss();
        void Initialize();
        void LoadBitMap();
        void OnShow();
        int getX();
        int getY();
        int getScreenX();
        int getScreenY();
        bool getAlive();
        void setXY(int nx, int ny);
        void setScreen_XY(int nx, int ny);
        void deductLife(int damage);
        void OnMove();
        void DeterminAttack(int RockX, int RockY);
    private:
        CMovingBitmap boss;
        BossCannon cannon;
        int x, y;
        int screen_x, screen_y;
        int life;
        int delayTime;
        int AttackDirection;
};
}