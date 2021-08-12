#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QIcon>
#include <QTimer>
#include <QPainter>
#include <QMouseEvent>
#include <ctime>
#include <QDebug>

#include "config.h"
#include "map.h"
#include "plane.h"
#include "enemyplane.h"
#include "bomb.h"

class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();

    void initScene();
    void playGame();
    void updatePosition();
    void enemyToScene();
    void collisionDetection();

    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

    Map m_map;
    QTimer m_Timer;
    Plane m_plane;
    EnemyPlane m_enemys[ENEMY_NUM];
    int m_recorder;
    Bomb m_bombs[BOMB_NUM];

//    Bullet temp_bullet;
//    EnemyBullet temp_bullet;
};
#endif // MAINSCENE_H
