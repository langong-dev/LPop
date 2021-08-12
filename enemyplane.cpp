#include "enemyplane.h"

EnemyPlane::EnemyPlane()
{
    m_enemy.load(ENEMY_PATH);
    m_X = 2 * WINDOW_W;
    m_Y = 0;
    m_Free = true;
    m_Speed = ENEMY_SPEED;

    m_Rect.setWidth(m_enemy.width());
    m_Rect.setHeight(m_enemy.height());
    m_Rect.moveTo(m_X,m_Y);

    m_recorder = 0;
}

void EnemyPlane::updatePosition()
{
    if(m_Free)
    {
        return;
    }

    m_Y += m_Speed;
    m_Rect.moveTo(m_X,m_Y);

    if(m_Y >= WINDOW_H + m_Rect.height())
    {
        m_Free = true;
    }
}

void EnemyPlane::shoot()
{
    m_recorder++;
    if(m_recorder < ENEMY_BULLET_INTERVAL)
    {
        return;
    }
    m_recorder = 0;

    for(int i = 0 ; i < ENEMY_BULLET_NUM;i++)
    {
        if(m_bullets[i].m_Free)
        {
            m_bullets[i].m_Free = false;
            m_bullets[i].m_X = m_X + m_Rect.width()*0.5 - 10;
            m_bullets[i].m_Y = m_Y + 25 ;
            break;
        }
    }
}
