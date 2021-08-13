#include "bossbullet.h"

BossBullet::BossBullet(int bosstype, int bullettype)
{
    bossid = bosstype;
    bulletid = bullettype;
    m_Bullet.load(CONSTBOSS.BOSSL[bossid].BOSS_BULLET_PATH[bulletid]);
    m_mx = CONSTBOSS.BOSSL[bossid].BOSS_BULLET_X[bulletid];
    m_my = CONSTBOSS.BOSSL[bossid].BOSS_BULLET_Y[bulletid];
    init();
}
