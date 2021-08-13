#ifndef BOSS_H
#define BOSS_H

#include "enemyplane.h"
#include "bossbullet.h"
#include "sboss.h"

class Boss : public EnemyPlane
{
public:
    Boss(int type);

    void initBoss();
    void updatePosition();
    void shoot();

    BossBullet *m_bullets[ENEMY_BULLET_NUM][10];
    int id;
    SBG CONSTBOSS;
    int m_toward_x, m_toward_y;
    int m_recorder[10];
    int m_life;
};

#endif // BOSS_H
