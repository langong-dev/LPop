#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QIcon>
#include <QTimer>
#include <QPainter>
#include <QMouseEvent>
#include <ctime>
#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include <QMessagebox>
#include <QSysInfo>

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
    void updateScore();
    void updateLife();
    void updateEnergy();
    void EnergyPlay();

    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

    Map m_map;
    QTimer m_Timer;
    Plane m_plane;
    EnemyPlane m_enemys[ENEMY_NUM];
    int m_recorder;
    Bomb m_bombs[BOMB_NUM];
    bool nplane;

    long long m_score;
    long long m_life;
    long long m_energy;
    QLabel *name;
    QLabel *score;
    QLabel *life;
    QLabel *energy;
    QLabel *all;
//    QPushButton *quitb;
//    QPushButton *eneb;

//    Bullet temp_bullet;
//    EnemyBullet temp_bullet;
};
#endif // MAINSCENE_H
