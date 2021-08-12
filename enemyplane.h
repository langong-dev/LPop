#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H

#include <QPixmap>

#include "config.h"
#include "enemybullet.h"

class EnemyPlane
{
public:
    EnemyPlane();

    void updatePosition();
    void shoot();

    QPixmap m_enemy;
    int m_X;
    int m_Y;
    QRect m_Rect;
    bool m_Free;
    int m_Speed;
    EnemyBullet m_bullets[ENEMY_BULLET_NUM];
    int m_recorder;
};

#endif // ENEMYPLANE_H
