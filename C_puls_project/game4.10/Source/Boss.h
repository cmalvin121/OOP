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
        void setXY(int nx, int ny);
        void setScreen_XY(int nx, int ny);
        void deductLife(int damage);
        void OnMove();
    private:
        CMovingBitmap boss;
        CAnimation lacerate;
        CAnimation cannon;
        int x, y;
        int screen_x, screen_y;
        int life;

};
}