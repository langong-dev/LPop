#include "map.h"

Map::Map()
{
    // Load Image
    m_map1.load(MAP_PATH);
    m_map2.load(MAP_PATH);

    // Set y
    m_map1_posY = -WINDOW_H;
    m_map2_posY = 0;

    // Set speed
    m_scroll_speed = MAP_SPEED;
}

void Map::mapPosition()
{
    // First
    m_map1_posY += MAP_SPEED;
    if(m_map1_posY >= 0)
    {
        m_map1_posY =-WINDOW_H;
    }

    // Second
    m_map2_posY += MAP_SPEED;
    if(m_map2_posY >= WINDOW_H )
    {
        m_map2_posY =0;
    }
}
