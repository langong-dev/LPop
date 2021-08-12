#ifndef PLANE_H
#define PLANE_H

#include <QPixmap>
#include <QRect>

#include "config.h"
#include "bullet.h"

class Plane
{
public:
    Plane();

    void shoot();
    void setPosition(int x, int y);

    QPixmap m_Plane;
    int m_X;
    int m_Y;
    QRect m_Rect;
    Bullet m_bullets[BULLET_NUM];
    int m_recorder;
};

#endif // PLANE_H
