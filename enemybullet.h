#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include <QPixmap>
#include <QDebug>
#include "config.h"

class EnemyBullet
{
public:
    EnemyBullet();

    void updatePosition();

    QPixmap m_Bullet;
    int m_X;
    int m_Y;
    int m_mx;
    int m_my;
    bool m_Free;
    QRect m_Rect;
};

#endif // ENEMYBULLET_H
