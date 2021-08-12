#include "plane.h"

Plane::Plane()
{
    // Load Image
    m_Plane.load(PLANE_PATH);

    // Init Pos
    m_X = WINDOW_W * 0.5 - m_Plane.width()*0.5;
    m_Y = WINDOW_H - m_Plane.height();

    // Rect
    m_Rect.setWidth(m_Plane.width());
    m_Rect.setHeight(m_Plane.height());
    m_Rect.moveTo(m_X,m_Y);

    m_recorder = 0;
}

void Plane::setPosition(int x, int y)
{
    m_X = x;
    m_Y = y;
    m_Rect.moveTo(m_X,m_Y);
}

void Plane::shoot()
{
    m_recorder++;
    if(m_recorder < BULLET_INTERVAL)
    {
        return;
    }
    m_recorder = 0;

    for(int i = 0 ; i < BULLET_NUM;i++)
    {
        if(m_bullets[i].m_Free)
        {
            m_bullets[i].m_Free = false;
            m_bullets[i].m_X = m_X + m_Rect.width()*0.5 - 10;
            m_bullets[i].m_Y = m_Y - 25 ;
            break;
        }
    }
}
