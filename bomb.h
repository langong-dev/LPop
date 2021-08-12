#ifndef BOMB_H
#define BOMB_H

#include <QPixmap>
#include <QVector>

#include "config.h"

class Bomb
{
public:
    Bomb();

    void updateInfo();

    QVector<QPixmap> m_pixArr;
    int m_X;
    int m_Y;
    bool m_Free;
    int m_Recoder;
    int m_index;
};

#endif // BOMB_H
