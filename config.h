#ifndef CONFIG_H
#define CONFIG_H

#include <QString>

//#define WINDOW_W 256
//#define WINDOW_H 384
#define WINDOW_W 512
#define WINDOW_H 650
#define WINDOW_TITLE "LPop Game"
#define WINDOW_ICON_PATH ":/resources/LanGongIconMode.ico"
#define WINDOW_EXTRA 350
#define WINDOW_EXIT 1337

#define GAME_RATE  10

#define MAP_PATH ":/resources/img_bg_level_1.jpg"
#define MAP_SPEED 0

#define PLANE_PATH ":/resources/hero2.png"
#define PLANE_KEYBOARD_MOVE 5

#define ENEMY_PATH  ":/resources/img-plane_5.png"
#define ENEMY_BULLET_PATH ":/resources/bullet_4.png"
#define ENEMY_SPEED 4
#define ENEMY_NUM   15
#define ENEMY_INTERVAL  40
#define ENEMY_BULLET_MODE 0
#define ENEMY_BULLET_NUM 20
#define ENEMY_BULLET_INTERVAL 60
const int dx[10] = {0};
const int dy[10] = {6};

#define BULLET_PATH ":/resources/bullet_11.png"
#define BULLET_SPEED 8
#define BULLET_NUM 20
#define BULLET_INTERVAL 20
#define BULLET_KILL 2

#define BOMB_PATH  ":/resources/bomb-%1.png"
#define BOMB_NUM  20
#define BOMB_MAX  7
#define BOMB_INTERVAL 20

#ifndef STRUCT_BOSS_H
#define STRUCT_BOSS_H
//struct BOSS
//{
//    QString BOSS_PATH;
//    int BOSS_BULLET_COUNT;
//    int BOSS_BULLET_TYPE[10]; // 0: Normal, 1: Rocket, 2: Fast
//    QString BOSS_BULLET_PATH[10];
//    int BOSS_BULLET_X[10];
//    int BOSS_BULLET_Y[10];
//    int BOSS_BULLET_START_X[10];
//    int BOSS_BULLET_START_Y[10];
//}BOSSL[10];
//#define BOSS_CNT 1
//#define BOSS_BULLET_ID0 ":/resources/bullet_c.png"
//#define BOSS_BULLET_ID1 ":/resources/bullet_6.png"

//void boss_config()
//{

//    BOSSL[0].BOSS_PATH = ":/resources/boss1.png";
//    BOSSL[0].BOSS_BULLET_COUNT = 3;
//    BOSSL[0].BOSS_BULLET_TYPE[0] = BOSSL[0].BOSS_BULLET_TYPE[1] = BOSSL[0].BOSS_BULLET_TYPE[2] = 0;
//    BOSSL[0].BOSS_BULLET_X[0] = 4, BOSSL[0].BOSS_BULLET_X[1] = 3, BOSSL[0].BOSS_BULLET_X[2] = 3;
//    BOSSL[0].BOSS_BULLET_Y[0] = 0, BOSSL[0].BOSS_BULLET_Y[1] = -1, BOSSL[0].BOSS_BULLET_Y[2] = -1;

//    for (int i = 0; i < BOSS_CNT; i ++)
//    {
//        for (int j = 0; j < BOSSL[i].BOSS_BULLET_COUNT; j ++)
//        {
//            if (BOSSL[i].BOSS_BULLET_TYPE[j] == 0)
//            {
//                BOSSL[i].BOSS_BULLET_PATH[j] = BOSS_BULLET_ID0;
//            }
//            if (BOSSL[i].BOSS_BULLET_TYPE[j] == 1)
//            {
//                BOSSL[i].BOSS_BULLET_PATH[j] = BOSS_BULLET_ID1;
//            }
//        }
//    }
//}
#endif

#define SCORE_BOMB_DEFAULT 10
#define SCORE_PRE_TEXT "Score  : "
#define LIFE_START 2000
#define LIFE_PRE_TEXT "Life   : "
#define LIFE_BULLET_DEFAULT 5
#define LIFE_BOMB_DEFAULT 10
#define ENERGY_LINE 666
#define ENERGY_PRE_TEXT "Energy : "
#define ENERGY_BOMB_DEFAULT 15
#define ENERGY_LOSE 5

const int direx[5] = {0, 0, 0, -1, 1};
const int direy[5] = {0, -1, 1, 0, 0};

#endif // CONFIG_H
