#ifndef CONFIG_H
#define CONFIG_H

//#define WINDOW_W 256
//#define WINDOW_H 384
#define WINDOW_W 512
#define WINDOW_H 650
#define WINDOW_TITLE "LPop Game"
#define WINDOW_ICON_PATH ":/resources/LanGongIconMode.ico"

#define GAME_RATE  10

#define MAP_PATH ":/resources/img_bg_level_1.jpg"
#define MAP_SPEED 0

#define PLANE_PATH ":/resources/hero2.png"
#define PLANE_KEYBOARD_MOVE 5

#define ENEMY_PATH  ":/resources/img-plane_5.png"
#define ENEMY_BULLET_PATH ":/resources/bullet_4.png"
#define ENEMY_SPEED 3
#define ENEMY_NUM   20
#define ENEMY_INTERVAL  30
#define ENEMY_BULLET_MODE 0
#define ENEMY_BULLET_NUM 30
#define ENEMY_BULLET_INTERVAL 40
const int dx[10] = {0};
const int dy[10] = {5};

#define BULLET_PATH ":/resources/bullet_11.png"
#define BULLET_SPEED 5
#define BULLET_NUM 30
#define BULLET_INTERVAL 20

#define BOMB_PATH  ":/resources/bomb-%1.png"
#define BOMB_NUM  20
#define BOMB_MAX  7
#define BOMB_INTERVAL 20

#endif // CONFIG_H
