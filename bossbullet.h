#ifndef BOSSBULLET_H
#define BOSSBULLET_H

#include "enemybullet.h"
#include "sboss.h"

class BossBullet : public EnemyBullet
{
public:
    BossBullet(int bosstype, int bullettype);

    int bossid, bulletid;
    SBG CONSTBOSS;
};

#endif // BOSSBULLET_H
