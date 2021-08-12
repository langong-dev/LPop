#ifndef BULLET_H
#define BULLET_H

#include <QPixmap>
#include "config.h"

class Bullet
{
public:
    Bullet();

    void updatePosition();

    QPixmap m_Bullet;
    int m_X;
    int m_Y;
    int m_Speed;
    bool m_Free;
    QRect m_Rect;
};

#endif // BULLET_H
