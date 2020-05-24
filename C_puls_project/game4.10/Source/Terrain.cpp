#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Monster.h"
#include "Terrain.h"
namespace game_framework
{
Terrain::Terrain()
{}
void Terrain::LoadBitMap()
{
    background.LoadBitmap("Bitmaps\\map.bmp");					// 載入背景的圖形
    background2.LoadBitmap("Bitmaps\\map2.bmp");
    background3.LoadBitmap("Bitmaps\\map3.bmp");
    background4.LoadBitmap("Bitmaps\\map4.bmp");
    block.LoadBitmap("Bitmaps\\wall.bmp");
    deadBlock.LoadBitmap("Bitmaps\\deadBlock.bmp");

    for (int i = 0; i < 8; i++)
        X6_1[i].LoadBitMap();
}
void Terrain::OnShow()
{
    background.ShowBitmap();			// 貼上背景圖
    background2.ShowBitmap();
    background3.ShowBitmap();
    background4.ShowBitmap();

    /*
    for (int i = 0; i < 31; i++)//地形規劃方塊顯示
    {
        for (int j = 0; j < 315; j++)
        {
            if (map[i][j] == 1)
            {
                block.SetTopLeft(wallX + j * 80, wallY + i * 80 - 1492);
                block.ShowBitmap();
            }
            else if (map[i][j] == 2)
            {
                deadBlock.SetTopLeft(wallX + j * 80, wallY + i * 80 - 1492);
                deadBlock.ShowBitmap();
            }
        }
    }*/

    for (int i = 0; i < 8; i++)
        if (X6_1[i].getAlive())
            X6_1[i].OnShow();
}
void Terrain::Initialize()
{
    picX = picY = 0;
    wallX = wallY = 0;
    lastX = lastY = 0;
    /////////////monster////////////
    X6_1[0].Initialize();
    X6_1[0].setXY(1920, 1295);
    X6_1[0].setScreenXY(1920, 1295);
    X6_1[1].Initialize();
    X6_1[1].setXY(4560, 1760);
    X6_1[1].setScreenXY(4560, 1760);
    X6_1[2].Initialize();
    X6_1[2].setXY(7520, 1760);
    X6_1[2].setScreenXY(7520, 1760);
    X6_1[3].Initialize();
    X6_1[3].setXY(10560, 880);
    X6_1[3].setScreenXY(10560, 880);
    X6_1[4].Initialize();
    X6_1[4].setXY(14640, 1760);
    X6_1[4].setScreenXY(14640, 1760);
    X6_1[5].Initialize();
    X6_1[5].setXY(18240, 1840);
    X6_1[5].setScreenXY(18240, 1840);
    X6_1[6].Initialize();
    X6_1[6].setXY(23120, 80);
    X6_1[6].setScreenXY(23120, 80);
    X6_1[7].Initialize();
    X6_1[7].setXY(23360, 1840);
    X6_1[7].setScreenXY(23360, 1840);
    ////////////////////////////////

    for (int i = 0; i < 31; i++)
    {
        for (int j = 0; j < 315; j++)
            map[i][j] = 0;
    }

    map[5][5] = 1;
    map[26][0] = 1;
    map[26][1] = 1;
    map[26][2] = 1;
    map[26][3] = 1;
    map[26][4] = 1;
    map[27][4] = 1;
    map[30][2] = 2;
    map[30][3] = 2;
    map[30][4] = 2;
    map[30][5] = 2;
    map[30][6] = 2;
    map[30][7] = 2;
    map[30][8] = 2;
    map[30][9] = 2;
    map[30][10] = 2;
    map[30][11] = 2;
    map[30][12] = 2;
    map[30][13] = 2;
    map[30][14] = 2;
    map[30][15] = 2;
    map[30][16] = 2;
    map[30][17] = 2;
    map[30][18] = 2;
    map[30][19] = 2;
    map[30][20] = 2;
    map[30][21] = 2;
    map[30][22] = 2;
    map[30][23] = 2;
    map[30][24] = 2;
    map[30][25] = 2;
    map[30][26] = 2;
    map[30][27] = 2;
    map[30][28] = 2;
    map[30][29] = 2;
    map[30][30] = 2;
    map[30][31] = 2;
    map[30][32] = 2;
    map[30][33] = 2;
    map[30][34] = 2;
    map[30][35] = 2;
    map[30][36] = 2;
    map[30][37] = 2;
    map[30][38] = 2;
    map[30][39] = 2;
    map[30][40] = 2;
    map[30][41] = 2;
    map[30][42] = 2;
    map[30][43] = 2;
    map[30][44] = 2;
    map[30][45] = 2;
    map[30][46] = 2;
    map[30][47] = 2;
    map[30][48] = 2;
    map[30][49] = 2;
    map[30][50] = 2;
    map[30][51] = 2;
    map[30][52] = 2;
    map[30][53] = 2;
    map[30][54] = 2;
    map[30][55] = 2;
    map[30][56] = 2;
    map[30][57] = 2;
    map[30][58] = 2;
    map[30][59] = 2;
    map[30][60] = 2;
    map[30][61] = 2;
    map[30][62] = 2;
    map[30][63] = 2;
    map[30][64] = 2;
    map[30][65] = 2;
    map[30][66] = 2;
    map[30][67] = 2;
    map[30][68] = 2;
    map[30][69] = 2;
    map[30][70] = 2;
    map[30][71] = 2;
    map[30][72] = 2;
    map[30][73] = 2;
    map[30][74] = 2;
    map[30][75] = 2;
    map[30][76] = 2;
    map[30][77] = 2;
    map[30][78] = 2;
    map[30][79] = 2;
    map[30][80] = 2;
    //---------------------
    map[24][9] = 1;
    map[24][10] = 1;
    map[24][11] = 1;
    map[24][12] = 1;
    map[25][9] = 1;
    map[25][10] = 1;
    map[25][11] = 1;
    map[25][12] = 1;
    map[22][16] = 1;
    map[22][17] = 1;
    map[22][18] = 1;
    map[22][19] = 1;
    map[23][16] = 1;
    map[23][17] = 1;
    map[23][18] = 1;
    map[23][19] = 1;
    map[19][23] = 1;
    map[19][24] = 1;
    map[19][25] = 1;
    map[19][26] = 1;
    map[20][23] = 1;
    map[20][24] = 1;
    map[20][25] = 1;
    map[20][26] = 1;
    map[22][31] = 1;
    map[22][32] = 1;
    map[22][33] = 1;
    map[23][31] = 1;
    map[23][32] = 1;
    map[23][33] = 1;
    map[19][36] = 1;
    map[19][37] = 1;
    map[19][38] = 1;
    map[19][39] = 1;
    map[20][36] = 1;
    map[20][37] = 1;
    map[20][38] = 1;
    map[20][39] = 1;
    map[22][41] = 1;
    map[22][42] = 1;
    map[22][43] = 1;
    map[22][44] = 1;
    map[23][41] = 1;
    map[23][42] = 1;
    map[23][43] = 1;
    map[23][44] = 1;
    map[20][49] = 1;
    map[20][50] = 1;
    map[20][51] = 1;
    map[21][49] = 1;
    map[21][50] = 1;
    map[21][51] = 1;
    map[22][57] = 1;
    map[22][58] = 1;
    map[22][59] = 1;
    map[23][57] = 1;
    map[23][58] = 1;
    map[23][59] = 1;
    map[20][67] = 1;
    map[20][68] = 1;
    map[20][69] = 1;
    map[21][67] = 1;
    map[21][68] = 1;
    map[21][69] = 1;
    //---------------------------
    map[26][77] = 1;
    map[27][77] = 1;
    map[26][78] = 1;
    map[26][79] = 1;
    map[26][80] = 1;
    map[26][81] = 1;
    map[26][82] = 1;
    map[26][83] = 1;
    map[26][84] = 1;
    map[26][85] = 1;
    map[26][86] = 1;
    map[26][87] = 1;
    map[26][88] = 1;
    map[26][89] = 1;
    map[26][90] = 1;
    map[26][91] = 1;
    map[26][92] = 1;
    map[26][93] = 1;
    map[22][94] = 1;
    map[23][94] = 1;
    map[24][94] = 1;
    map[25][94] = 1;
    map[26][94] = 1;
    map[22][95] = 1;
    map[22][96] = 1;
    map[22][97] = 1;
    map[22][98] = 1;
    map[6][88] = 1;
    map[7][88] = 1;
    map[8][88] = 1;
    map[9][88] = 1;
    map[10][88] = 1;
    map[11][88] = 1;
    map[12][88] = 1;
    map[13][88] = 1;
    map[14][88] = 1;
    map[15][88] = 1;
    map[0][96] = 1;
    map[0][95] = 1;
    map[0][94] = 1;
    map[0][93] = 1;
    map[0][92] = 1;
    map[0][91] = 1;
    map[0][90] = 1;
    map[0][89] = 1;
    map[0][88] = 1;
    map[0][87] = 1;
    map[0][86] = 1;
    map[0][85] = 1;
    map[0][84] = 1;
    map[0][83] = 1;
    map[0][82] = 1;
    map[1][82] = 1;
    map[2][82] = 1;
    map[3][82] = 1;
    map[4][82] = 1;
    map[5][82] = 1;
    map[6][82] = 1;
    map[6][83] = 1;
    map[6][84] = 1;
    map[6][85] = 1;
    map[6][86] = 1;
    map[6][87] = 1;
    map[6][88] = 1;
    map[6][89] = 1;
    map[7][89] = 1;
    map[6][90] = 1;
    map[7][90] = 1;
    map[6][91] = 1;
    map[7][91] = 1;
    map[6][92] = 1;
    map[7][92] = 1;
    map[22][98] = 1;
    map[21][98] = 1;
    map[20][98] = 1;
    map[19][98] = 1;
    map[18][98] = 1;
    map[17][98] = 1;
    map[16][98] = 1;
    map[15][98] = 1;
    map[14][98] = 1;
    map[14][98] = 1;
    map[14][99] = 1;
    map[14][100] = 1;
    map[14][101] = 1;
    map[14][102] = 1;
    map[14][103] = 1;
    map[14][104] = 1;
    map[14][105] = 1;
    map[13][105] = 1;
    map[12][105] = 1;
    map[11][105] = 1;
    map[10][105] = 1;
    map[9][105] = 1;
    map[8][105] = 1;
    map[8][105] = 1;
    map[8][106] = 1;
    map[8][107] = 1;
    map[8][108] = 1;
    map[8][109] = 1;
    map[8][110] = 1;
    map[8][111] = 1;
    map[8][112] = 1;
    map[8][113] = 1;
    map[8][114] = 1;
    map[8][115] = 1;
    map[8][116] = 1;
    map[8][117] = 1;
    map[8][118] = 1;
    map[8][119] = 1;
    map[8][120] = 1;
    map[8][121] = 1;
    map[8][122] = 1;
    map[8][123] = 1;
    map[8][124] = 1;
    map[8][125] = 1;
    map[8][126] = 1;
    map[8][127] = 1;
    map[8][128] = 1;
    map[8][129] = 1;
    map[8][129] = 1;
    map[9][129] = 1;
    map[10][129] = 1;
    map[11][129] = 1;
    map[11][129] = 1;
    map[11][130] = 1;
    map[11][131] = 1;
    map[11][132] = 1;
    map[11][133] = 1;
    map[11][134] = 1;
    map[11][135] = 1;
    map[11][136] = 1;
    map[11][137] = 1;
    map[11][138] = 1;
    map[11][139] = 1;
    map[11][140] = 1;
    map[11][141] = 1;
    map[11][142] = 1;
    map[11][143] = 1;
    map[11][144] = 1;
    map[11][145] = 1;
    map[11][146] = 1;
    map[11][147] = 1;
    map[11][148] = 1;
    map[11][148] = 1;
    map[12][148] = 1;
    map[13][148] = 1;
    map[14][148] = 1;
    map[14][148] = 1;
    map[14][149] = 1;
    map[14][150] = 1;
    map[14][151] = 1;
    map[14][152] = 1;
    map[14][153] = 1;
    map[14][153] = 1;
    map[15][153] = 1;
    map[16][153] = 1;
    map[17][153] = 1;
    map[18][153] = 1;
    map[19][153] = 1;
    map[20][153] = 1;
    map[20][153] = 1;
    map[20][154] = 1;
    map[20][155] = 1;
    map[20][156] = 1;
    map[20][157] = 1;
    map[20][157] = 1;
    map[21][157] = 1;
    map[22][157] = 1;
    map[23][157] = 1;
    map[23][157] = 1;
    map[23][158] = 1;
    map[23][159] = 1;
    map[23][160] = 1;
    map[23][161] = 1;
    map[23][162] = 1;
    map[23][163] = 1;
    map[23][164] = 1;
    map[23][165] = 1;
    map[23][166] = 1;
    map[23][167] = 1;
    map[13][166] = 1;
    map[13][167] = 1;
    map[12][166] = 1;
    map[12][167] = 1;
    map[11][166] = 1;
    map[11][167] = 1;
    map[11][168] = 1;
    map[11][169] = 1;
    map[11][170] = 1;
    map[11][171] = 1;
    map[11][172] = 1;
    map[11][173] = 1;
    map[10][173] = 2;
    map[9][173] = 2;
    map[8][173] = 2;
    map[7][173] = 2;
    map[6][173] = 2;
    map[5][173] = 2;
    map[4][173] = 2;
    map[3][173] = 2;
    map[2][173] = 2;
    map[1][173] = 2;
    map[0][173] = 2;
    map[24][168] = 2;
    map[24][169] = 2;
    map[24][170] = 2;
    map[24][171] = 2;
    map[24][172] = 2;
    map[24][173] = 2;
    map[23][174] = 1;
    map[23][175] = 1;
    map[23][176] = 1;
    map[23][177] = 1;
    map[24][178] = 2;
    map[24][179] = 2;
    map[24][180] = 2;
    map[24][181] = 2;
    map[24][182] = 2;
    map[23][183] = 1;
    map[23][184] = 1;
    map[23][185] = 1;
    map[23][186] = 1;
    map[22][183] = 1;
    map[22][184] = 1;
    map[22][185] = 1;
    map[22][186] = 1;
    map[24][187] = 2;
    map[24][188] = 2;
    map[24][189] = 2;
    map[24][190] = 2;
    map[24][191] = 2;
    map[24][192] = 2;
    map[24][193] = 2;
    map[24][194] = 2;
    map[23][195] = 1;
    map[23][196] = 1;
    map[23][197] = 1;
    map[23][198] = 1;
    map[24][199] = 2;
    map[24][200] = 2;
    map[24][201] = 2;
    map[24][202] = 2;
    map[24][203] = 2;
    map[24][204] = 2;
    map[23][205] = 1;
    map[23][206] = 1;
    map[23][207] = 1;
    map[23][208] = 1;
    map[23][209] = 1;
    map[24][210] = 2;
    map[24][211] = 2;
    map[24][212] = 2;
    map[24][213] = 2;
    map[24][214] = 2;
    map[23][215] = 1;
    map[23][216] = 1;
    map[23][217] = 1;
    map[23][218] = 1;
    map[23][219] = 1;
    map[22][215] = 1;
    map[22][216] = 1;
    map[22][217] = 1;
    map[22][218] = 1;
    map[22][219] = 1;
    map[24][220] = 2;
    map[24][221] = 2;
    map[24][222] = 2;
    map[24][223] = 2;
    map[24][224] = 2;
    map[24][225] = 2;
    map[24][226] = 2;
    map[24][227] = 2;
    map[23][228] = 1;
    map[23][229] = 1;
    map[23][230] = 1;
    map[23][231] = 1;
    map[24][232] = 2;
    map[24][233] = 2;
    map[24][234] = 2;
    map[24][235] = 2;
    map[24][236] = 2;
    map[24][237] = 2;
    map[24][238] = 2;
    map[24][239] = 2;
    map[23][240] = 1;
    map[23][241] = 1;
    map[23][242] = 1;
    map[23][243] = 1;
    map[23][244] = 1;
    map[24][245] = 2;
    map[24][246] = 2;
    map[24][247] = 2;
    map[24][248] = 2;
    map[24][249] = 2;
    map[24][250] = 2;
    map[24][251] = 2;
    map[24][252] = 2;
    map[23][253] = 1;
    map[23][254] = 1;
    map[23][255] = 1;
    map[23][256] = 1;
    map[23][257] = 1;
    map[23][258] = 1;
    map[23][259] = 1;
    map[23][260] = 1;
    map[23][261] = 1;
    map[23][262] = 1;
    map[23][263] = 1;
    map[23][264] = 1;
    map[23][265] = 1;
    map[24][266] = 2;
    map[24][267] = 2;
    map[24][268] = 2;
    map[24][269] = 2;
    map[24][270] = 2;
    map[24][271] = 2;
    map[24][272] = 2;
    map[24][273] = 2;
    map[24][274] = 2;
    map[23][274] = 2;
    map[22][274] = 2;
    map[21][274] = 2;
    map[18][270] = 1;
    map[18][271] = 1;
    map[18][272] = 1;
    map[18][273] = 1;
    map[18][274] = 1;
    map[18][275] = 1;
    map[18][276] = 1;
    map[18][277] = 1;
    map[18][278] = 1;
    map[19][270] = 1;
    map[19][271] = 1;
    map[19][272] = 1;
    map[19][273] = 1;
    map[19][274] = 1;
    map[20][270] = 1;
    map[20][271] = 1;
    map[20][272] = 1;
    map[20][273] = 1;
    map[20][274] = 1;
    map[18][279] = 1;
    map[17][279] = 1;
    map[16][279] = 1;
    map[15][279] = 1;
    map[14][279] = 1;
    map[13][279] = 1;
    map[12][279] = 1;
    map[12][280] = 1;
    map[12][281] = 1;
    map[12][282] = 1;
    map[12][283] = 1;
    map[11][283] = 1;
    map[10][283] = 1;
    map[10][283] = 1;
    map[10][284] = 1;
    map[10][285] = 1;
    map[10][286] = 1;
    map[10][287] = 1;
    map[10][288] = 1;
    map[10][289] = 1;
    map[10][290] = 1;
    map[10][291] = 1;
    map[10][292] = 1;
    map[10][293] = 1;
    map[10][293] = 1;
    map[11][293] = 1;
    map[12][293] = 1;
    map[12][292] = 1;
    map[12][291] = 1;
    map[12][290] = 1;
    map[12][289] = 1;
    map[12][288] = 1;
    map[12][287] = 1;
    map[13][287] = 1;
    map[14][287] = 1;
    map[15][287] = 1;
    map[16][287] = 1;
    map[17][287] = 1;
    map[18][287] = 1;
    map[19][287] = 1;
    map[20][287] = 1;
    map[24][290] = 2;
    map[24][289] = 2;
    map[24][288] = 2;
    map[24][287] = 2;
    map[24][286] = 2;
    map[24][285] = 2;
    map[24][284] = 2;
    map[21][283] = 2;
    map[22][283] = 2;
    map[23][283] = 2;
    map[24][283] = 2;
    map[23][309] = 1;
    map[23][308] = 1;
    map[23][307] = 1;
    map[23][306] = 1;
    map[23][305] = 1;
    map[23][304] = 1;
    map[23][303] = 1;
    map[23][302] = 1;
    map[23][301] = 1;
    map[23][300] = 1;
    map[23][299] = 1;
    map[23][298] = 1;
    map[23][297] = 1;
    map[23][296] = 1;
    map[23][295] = 1;
    map[23][294] = 1;
    map[23][293] = 1;
    map[23][292] = 1;
    map[23][291] = 1;
    map[24][310] = 2;
    map[24][311] = 2;
    map[24][312] = 2;
    map[23][313] = 1;
    map[22][313] = 1;
    map[21][313] = 1;
    map[20][313] = 1;
    map[19][313] = 1;
    map[18][313] = 1;
    map[17][313] = 1;
    map[16][313] = 1;
    map[15][313] = 1;
    map[14][313] = 1;
    map[13][313] = 1;
    map[12][313] = 1;
    map[12][312] = 1;
    map[12][311] = 1;
    map[12][310] = 1;
    map[12][309] = 1;
    map[12][308] = 1;
    map[12][307] = 1;
    map[12][306] = 1;
    map[12][305] = 1;
    map[12][304] = 1;
    map[12][303] = 1;
    map[12][302] = 1;
    map[12][301] = 1;
    map[12][300] = 1;
    map[12][299] = 1;
    map[11][299] = 1;
    map[10][299] = 1;
    map[9][299] = 1;
    map[8][299] = 1;
    map[7][299] = 1;
    map[6][299] = 1;
    map[5][299] = 1;
    map[4][299] = 1;
    map[3][299] = 1;
    map[3][298] = 1;
    map[3][297] = 1;
    map[3][296] = 1;
    map[3][295] = 1;
    map[3][294] = 1;
    map[3][293] = 1;
    map[3][292] = 1;
    map[3][291] = 1;
    map[3][290] = 1;
    map[3][289] = 1;
    map[3][288] = 1;
    map[3][287] = 1;
    map[3][286] = 1;
    map[3][285] = 1;
    map[3][284] = 1;
    map[3][283] = 1;
    map[2][283] = 1;
    map[1][283] = 1;
    map[0][283] = 1;
    map[0][282] = 1;
    map[0][281] = 1;
    map[0][280] = 1;
    map[0][279] = 1;
    map[0][278] = 1;
    map[0][277] = 1;
    map[0][276] = 1;
    map[0][275] = 1;
    background.SetTopLeft(0, 0 - 1492);				// 設定背景的起始座標
    background2.SetTopLeft(background.Width(), 0 - 1492);
    background3.SetTopLeft(background.Width() + background2.Width(), 0 - 1492);
    background4.SetTopLeft(background.Width() + background2.Width() + background3.Width(), 0 - 1492);
}
void Terrain::GetLastRockmanXY(int x, int y)
{
    lastX = x;
    lastY = y;
}
void Terrain::GetNowRockmanXY(int x, int y)
{
    nowX = x;
    nowY = y;
}
int Terrain::GetLastX()
{
    return lastX;
}
int Terrain::GetLastY()
{
    return lastY;
}
void Terrain::MoveScreen()
{
    int mon_posX, mon_posY;

    for (int i = 0; i < 8; i++)
    {
        mon_posX = X6_1[i].getScreenX();
        mon_posY = X6_1[i].getScreenY();

        if (nowX > 900)
            mon_posX -= (nowX - lastX);

        if (nowY < 2700)
            mon_posY -= (nowY - lastY);

        X6_1[i].setScreenXY(mon_posX, mon_posY);
        X6_1[i].DeterminAttack(nowX, nowY);
    }

    if (nowX > 900)
    {
        wallX -= (nowX - lastX);
        picX -= (nowX - lastX);
    }

    if (nowY < 2700)
    {
        wallY -= (nowY - lastY);
        picY -= (nowY - lastY);
    }

    background.SetTopLeft(picX, picY - 1492);
    background2.SetTopLeft(picX + background.Width(), picY - 1492);
    background3.SetTopLeft(picX + background.Width() + background2.Width(), picY - 1492);
    background4.SetTopLeft(picX + background.Width() + background2.Width() + background3.Width(), picY - 1492);
}
int Terrain::crashleft()
{
    int map_x, map_y;
    map_x = nowX / 80;

    for (int i = 0; i < 200; i++)
    {
        map_y = (nowY + i) / 80;

        if (map[map_y][map_x] == 1)
        {
            //TRACE("%d %d %d %d左\n", map_x, map_y, nowY, i);
            return map_x * 80 + 80;
        }

        if (map[map_y][map_x] == 2)
            return -1;
    }

    return 0;
}
int Terrain::crashright()
{
    int map_x, map_y;
    map_x = (nowX + 160) / 80;

    for (int i = 0; i < 200; i++)
    {
        map_y = (nowY + i) / 80;

        if (map[map_y][map_x] == 1)
        {
            //TRACE("%d %d %d %d右\n", map_x, map_y, nowY, i);
            return map_x * 80;
        }

        if (map[map_y][map_x] == 2)
            return -1;
    }

    return 0;
}
int Terrain::crashtop()
{
    int map_x, map_y;
    map_y = nowY / 80;

    for (int i = 20; i <= 140; i++)
    {
        map_x = (nowX + i) / 80;

        if (map[map_y][map_x] == 1)
        {
            //TRACE("%d %d上\n", map_x, map_y);
            return map_y * 80 + 80;
        }

        if (map[map_y][map_x] == 2)
            return -1;
    }

    return 0;
}
int Terrain::crashdown()
{
    int map_x, map_y;
    map_y = (nowY + 200) / 80;

    for (int i = 20; i <= 140; i++)
    {
        map_x = (nowX + i) / 80;

        if (map[map_y][map_x] == 1)
        {
            TRACE("%d %d下\n", map_x, map_y);
            return map_y * 80;
        }

        if (map[map_y][map_x] == 2)
            return -1;
    }

    return 0;
}
bool Terrain::MonsterCollision()
{
    for (int i = 0; i < 8; i++)
        if (X6_1[i].MonsterCollision(nowX, nowY))
            return true;

    return false;
}
void Terrain::setMonsterLife(int damage)
{
    X6_1.deductLife(damage);
}
int Terrain::getMonsterX()
{
    return X6_1.getX();
}
int Terrain::getMonsterY()
{
    return X6_1.getY();
}
bool Terrain::getMonsterAliveState()
{
    return X6_1.getAlive();
}
}