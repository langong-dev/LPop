#include "boss.h"

#include "config.h"

Boss::Boss(int type)
{
//    boss_config();
    id = type;
    for (int i = 0; i < ENEMY_BULLET_NUM; i ++)
    {
        for (int j = 0; j < CONSTBOSS.BOSSL[id].BOSS_BULLET_COUNT; j ++)
        {
            m_bullets[i][j] = new BossBullet(id, j);
        }
    }
    initBoss();
}

void Boss::initBoss()
{
    m_enemy.load(CONSTBOSS.BOSSL[id].BOSS_PATH);
    m_X = (WINDOW_W - m_enemy.width()) * 0.5;
    m_Y = (WINDOW_H - m_enemy.height()) * 0.3;
    m_Free = true;
    m_Speed = 0;
    m_toward_x = m_toward_y = 0;
    m_life = CONSTBOSS.BOSSL[id].BOSS_LIFE;

    m_Rect.setWidth(m_enemy.width());
    m_Rect.setHeight(m_enemy.height());
    m_Rect.moveTo(m_X,m_Y);

    for (int bid = 0; bid < CONSTBOSS.BOSSL[id].BOSS_BULLET_COUNT; bid ++)
        m_recorder[bid] = 0;
}

void Boss::updatePosition()
{
    if(m_Free)
    {
        return;
    }
//    qDebug() << "__________________________________________";
    if (CONSTBOSS.BOSSL[id].BOSS_MOVE_MODE == 1)
    {
//        qDebug() << "MOVE BOSS ++++++++++++++++++++++++++++++++";
        if (m_toward_x == 0 && m_toward_y == 0)
        {
            m_toward_x = 0;
            m_toward_y = direy[2] * 2;
        }
        else if (m_toward_y == direy[2] * 2 && m_Y >= WINDOW_H - m_Rect.height())
        {
            m_toward_y = direy[1] * 2;
        }
        else if (m_toward_y == direy[1] * 2 && m_Y <= 1)
        {
            m_toward_y = direy[2] * 2;
        }
    }

    m_X += m_toward_x, m_Y += m_toward_y;

//    m_Y += m_Speed;
    m_Rect.moveTo(m_X,m_Y);

//    if(m_Y >= WINDOW_H + m_Rect.height())
//    {
//        m_Free = true;
//    }
}

void Boss::shoot()
{
    for (int bid = 0; bid < CONSTBOSS.BOSSL[id].BOSS_BULLET_COUNT; bid ++)
    {
        m_recorder[bid] ++;
        if(m_recorder[bid] < CONSTBOSS.BOSSL[id].BOSS_BULLET_INTERVAL[bid])
        {
            continue;
        }
        m_recorder[bid] = 0;

//        for (int j = 0; j < CONSTBOSS.BOSSL[id].BOSS_BULLET_COUNT; j ++)
        {
            for(int i = 0 ; i < ENEMY_BULLET_NUM;i++)
            {
                if(m_bullets[i][bid]->m_Free)
                {
//                    qDebug () << "CREATE " <<i << j;
                    m_bullets[i][bid]->m_Free = false;
                    m_bullets[i][bid]->m_X = m_X + m_Rect.width()*0.5 - 10;
                    m_bullets[i][bid]->m_Y = m_Y + 25 ;
                    break;
                }
                else
                {
//                    qDebug () << "IGNORE " <<i << j;
                }
            }
        }
    }
}
