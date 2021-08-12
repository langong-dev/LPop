#include "mainscene.h"

MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    initScene();
    playGame();
}

MainScene::~MainScene()
{
}

void MainScene::initScene()
{
    // Window Init
    setFixedSize(WINDOW_W, WINDOW_H);
    setWindowTitle(WINDOW_TITLE);
    setWindowIcon(QIcon(WINDOW_ICON_PATH));

    // Game Init
    m_Timer.setInterval(GAME_RATE);

    m_recorder = 0;
    srand((unsigned int)time(NULL));
}

void MainScene::playGame()
{
    // Start Timer
    m_Timer.start();
    // Slot Timer
    connect(&m_Timer,&QTimer::timeout,[=](){
        enemyToScene();
        updatePosition();
        update();
        collisionDetection();
    });
}

void MainScene::updatePosition()
{
    m_map.mapPosition();

//    temp_bullet.m_Free = false;
//    temp_bullet.updatePosition();

    m_plane.shoot();
    // Bullet
    for(int i = 0 ;i < BULLET_NUM;i++)
    {
        if(!m_plane.m_bullets[i].m_Free)
        {
            m_plane.m_bullets[i].updatePosition();
        }
    }

    for(int i = 0 ; i< ENEMY_NUM;i++)
    {
       if(m_enemys[i].m_Free == false)
       {
            m_enemys[i].updatePosition();
       }
       m_enemys[i].shoot();
       for(int j = 0 ;j < ENEMY_BULLET_NUM;j++)
       {
           if(!m_enemys[i].m_bullets[j].m_Free)
           {
               m_enemys[i].m_bullets[j].updatePosition();
           }
       }
    }

    for(int i = 0 ; i < BOMB_NUM;i++)
    {
        if(m_bombs[i].m_Free == false)
        {
           m_bombs[i].updateInfo();
        }
    }
}

void MainScene::enemyToScene()
{
    m_recorder++;
    if(m_recorder < ENEMY_INTERVAL)
    {
        return;
    }

    m_recorder = 0;

    for(int i = 0 ; i< ENEMY_NUM;i++)
    {
        if(m_enemys[i].m_Free)
        {
            //敌机空闲状态改为false
            m_enemys[i].m_Free = false;
            //设置坐标
            m_enemys[i].m_X = rand() % (WINDOW_W - m_enemys[i].m_Rect.width());
            m_enemys[i].m_Y = -m_enemys[i].m_Rect.height();
            break;
        }
    }
}

void MainScene::collisionDetection()
{
    for(int i = 0 ;i < ENEMY_NUM;i++)
    {
        if(m_enemys[i].m_Free)
        {
            continue;
        }
        for(int j = 0 ; j < BULLET_NUM;j++)
        {
            if(m_plane.m_bullets[j].m_Free)
            {
                continue;
            }
            if(m_enemys[i].m_Rect.intersects(m_plane.m_bullets[j].m_Rect))
            {
                m_enemys[i].m_Free = true;
                m_plane.m_bullets[j].m_Free = true;

                for(int k = 0 ; k < BOMB_NUM;k++)
                {
                    if(m_bombs[k].m_Free)
                    {
                        //爆炸状态设置为非空闲
                        m_bombs[k].m_Free = false;
                        //更新坐标

                        m_bombs[k].m_X = m_enemys[i].m_X;
                        m_bombs[k].m_Y = m_enemys[i].m_Y;
                        break;
                    }
                }
            }
        }
    }
}

void MainScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    // Draw
    painter.drawPixmap(0,m_map.m_map1_posY , m_map.m_map1);
    painter.drawPixmap(0,m_map.m_map2_posY , m_map.m_map2);
    painter.drawPixmap(m_plane.m_X,m_plane.m_Y,m_plane.m_Plane);

//    painter.drawPixmap(temp_bullet.m_X,temp_bullet.m_Y,temp_bullet.m_Bullet);
//    qDebug() << temp_bullet.m_X << " " << temp_bullet.m_Y;

    for(int i = 0 ;i < BULLET_NUM;i++)
    {
        if(!m_plane.m_bullets[i].m_Free)
        {
            painter.drawPixmap(m_plane.m_bullets[i].m_X,m_plane.m_bullets[i].m_Y,m_plane.m_bullets[i].m_Bullet);
        }
    }

    for(int i = 0 ; i< ENEMY_NUM;i++)
    {
        if(m_enemys[i].m_Free == false)
        {
            painter.drawPixmap(m_enemys[i].m_X,m_enemys[i].m_Y,m_enemys[i].m_enemy);
        }
        for(int j = 0 ;j < ENEMY_BULLET_NUM;j++)
        {
            if(!m_enemys[i].m_bullets[j].m_Free)
            {
                painter.drawPixmap(m_enemys[i].m_bullets[j].m_X,m_enemys[i].m_bullets[j].m_Y,m_enemys[i].m_bullets[j].m_Bullet);
            }
        }
    }

    for(int i = 0 ; i < BOMB_NUM;i++)
    {
        if(m_bombs[i].m_Free == false)
        {
           painter.drawPixmap(m_bombs[i].m_X,m_bombs[i].m_Y,m_bombs[i].m_pixArr[m_bombs[i].m_index]);
        }
    }
}

void MainScene::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x() - m_plane.m_Rect.width()*0.5; //鼠标位置 - 飞机矩形的一半
    int y = event->y() - m_plane.m_Rect.height()*0.5;

    //边界检测
    if(x <= 0 )
    {
        x = 0;
    }
    if(x >= WINDOW_W - m_plane.m_Rect.width())
    {
        x = WINDOW_W - m_plane.m_Rect.width();
    }
    if(y <= 0)
    {
        y = 0;
    }
    if(y >= WINDOW_H - m_plane.m_Rect.height())
    {
        y = WINDOW_H - m_plane.m_Rect.height();
    }
    m_plane.setPosition(x,y);
}

void MainScene::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        m_plane.m_X=(m_plane.m_X-PLANE_KEYBOARD_MOVE<0)?m_plane.m_X:m_plane.m_X-PLANE_KEYBOARD_MOVE;

    }
    if(event->key() == Qt::Key_Right)
    {
        m_plane.m_X=(m_plane.m_X+PLANE_KEYBOARD_MOVE+m_plane.m_Plane.width()>WINDOW_W)?m_plane.m_X:m_plane.m_X+PLANE_KEYBOARD_MOVE;

    }
    if(event->key() == Qt::Key_Up)
    {
        m_plane.m_Y=(m_plane.m_Y-PLANE_KEYBOARD_MOVE<0)?m_plane.m_Y:m_plane.m_Y-PLANE_KEYBOARD_MOVE;

    }
    if(event->key() == Qt::Key_Down)
    {
        m_plane.m_Y=(m_plane.m_Y+PLANE_KEYBOARD_MOVE+m_plane.m_Plane.height()>WINDOW_H)?m_plane.m_Y:m_plane.m_Y+PLANE_KEYBOARD_MOVE;

    }
    update();
}
