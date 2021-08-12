#include "bullet.h"

Bullet::Bullet()
{
    m_Bullet.load(BULLET_PATH);

    // Pos
    m_X = WINDOW_W*0.5 - m_Bullet.width()*0.5;
    m_Y = WINDOW_H;

    // Status
    m_Free = true;

    // Speed
    m_Speed = BULLET_SPEED;

    // Rect
    m_Rect.setWidth(m_Bullet.width());
    m_Rect.setHeight(m_Bullet.height());
    m_Rect.moveTo(m_X,m_Y);
}

void Bullet::updatePosition()
{
    //如果子弹是空闲状态，不需要坐标计算
    //玩家飞机可以控制子弹的空闲状态为false
    if(m_Free)
    {
        return;
    }

    // Move up
    m_Y  -= m_Speed;
    m_Rect.moveTo(m_X,m_Y);

    if(m_Y <= -m_Rect.height())
    {
        m_Free = true;
    }
}
