#include "enemybullet.h"

EnemyBullet::EnemyBullet()
{
//    if (type == 0)
//    {
        m_Bullet.load(ENEMY_BULLET_PATH);

        // Speed
        m_mx = dx[0];
        m_my = dy[0];
//    }
    // Pos
    m_X = WINDOW_W*0.5 - m_Bullet.width()*0.5;
    m_Y = 0;

    // Status
    m_Free = true;

    // Rect
    m_Rect.setWidth(m_Bullet.width());
    m_Rect.setHeight(m_Bullet.height());
    m_Rect.moveTo(m_X,m_Y);
}

void EnemyBullet::updatePosition()
{
    if(m_Free)
    {
        return;
    }

    // Move down
    m_X  += m_mx;
    m_Y  += m_my;
    m_Rect.moveTo(m_X,m_Y);

    if(m_X <= -m_Rect.width() || m_X >= WINDOW_W + m_Rect.width() || m_Y <= -m_Rect.height() ||  m_Y >= WINDOW_H+m_Rect.height())
    {
        m_Free = true;
    }
//    qDebug() << "OUT:" <<WINDOW_H+m_Rect.height();
}
