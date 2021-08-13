#ifndef SBOSS_H
#define SBOSS_H

#include <QString>

class SBOSS
{
public:
    QString BOSS_PATH;
    int BOSS_BULLET_COUNT;
    int BOSS_BULLET_TYPE[10]; // 0: Normal, 1: Rocket, 2: Fast
    QString BOSS_BULLET_PATH[10];
    int BOSS_BULLET_X[10];
    int BOSS_BULLET_Y[10];
//    int BOSS_BULLET_START_X[10];
//    int BOSS_BULLET_START_Y[10];
    int BOSS_MOVE_MODE;
    int BOSS_LIFE;
    int BOSS_BULLET_KILL[10];
    int BOSS_BULLET_INTERVAL[10];
    QString BOSS_NAME;
};
#define BOSS_CNT 1
#define BOSS_BULLET_ID0 ":/resources/bullet_c.png"
#define BOSS_BULLET_ID1 ":/resources/bullet_6.png"

class SBG
{
public:
    SBOSS BOSSL[10];
    SBG()
    {
        BOSSL[0].BOSS_PATH = ":/resources/boss1.png";
        BOSSL[0].BOSS_BULLET_COUNT = 5;
        BOSSL[0].BOSS_BULLET_TYPE[0] = BOSSL[0].BOSS_BULLET_TYPE[1] = BOSSL[0].BOSS_BULLET_TYPE[2] = BOSSL[0].BOSS_BULLET_TYPE[3] = BOSSL[0].BOSS_BULLET_TYPE[4] = 0;
        BOSSL[0].BOSS_BULLET_X[0] = 0, BOSSL[0].BOSS_BULLET_X[1] = -2, BOSSL[0].BOSS_BULLET_X[2] = 2, BOSSL[0].BOSS_BULLET_X[3] = -3, BOSSL[0].BOSS_BULLET_X[4] = 3;
        BOSSL[0].BOSS_BULLET_Y[0] = 3, BOSSL[0].BOSS_BULLET_Y[1] = 4, BOSSL[0].BOSS_BULLET_Y[2] = 4, BOSSL[0].BOSS_BULLET_Y[3] = 0, BOSSL[0].BOSS_BULLET_Y[4] = 0;
        BOSSL[0].BOSS_MOVE_MODE = 1;
        BOSSL[0].BOSS_BULLET_INTERVAL[0] = 40;
        BOSSL[0].BOSS_BULLET_INTERVAL[1] = 40;
        BOSSL[0].BOSS_BULLET_INTERVAL[2] = 40;
        BOSSL[0].BOSS_BULLET_INTERVAL[3] = 40;
        BOSSL[0].BOSS_BULLET_INTERVAL[4] = 40;
        BOSSL[0].BOSS_LIFE = 1000;
        BOSSL[0].BOSS_NAME = "Boss Big Bird";


        for (int i = 0; i < BOSS_CNT; i ++)
        {
            for (int j = 0; j < BOSSL[i].BOSS_BULLET_COUNT; j ++)
            {
                if (BOSSL[i].BOSS_BULLET_TYPE[j] == 0)
                {
                    BOSSL[i].BOSS_BULLET_PATH[j] = BOSS_BULLET_ID0;
                    BOSSL[i].BOSS_BULLET_KILL[j] = 5;
                }
                if (BOSSL[i].BOSS_BULLET_TYPE[j] == 1)
                {
                    BOSSL[i].BOSS_BULLET_PATH[j] = BOSS_BULLET_ID1;
                    BOSSL[i].BOSS_BULLET_KILL[j] = 10;
                }
            }
        }
    }
};

#endif // SBOSS_H
