#ifndef MAP_H
#define MAP_H

#include <QPixmap>

#include "config.h"

class Map
{
public:
    Map();

    void mapPosition();

    // Map Image
    QPixmap m_map1;
    QPixmap m_map2;

    // y
    int m_map1_posY;
    int m_map2_posY;

    // speed
    int m_scroll_speed;
};

#endif // MAP_H
