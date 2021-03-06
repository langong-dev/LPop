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
//    showFullScreen();
    setFixedSize(WINDOW_W + WINDOW_EXTRA, WINDOW_H);
    setWindowTitle(WINDOW_TITLE);
    setWindowIcon(QIcon(WINDOW_ICON_PATH));
    setFocus();

    // Game Init
    m_Timer.setInterval(GAME_RATE);

    m_recorder = 0;
    srand((unsigned int)time(NULL));
    m_score = 0;
    m_life = LIFE_START;
    m_energy = 0;
    nplane = true;
    bosspos = -1;


    name = new QLabel(this);
    score = new QLabel(this);
    life = new QLabel(this);
    energy = new QLabel(this);
    QFont font = name->font();
    font.setPointSize(36);
    font.setBold(true);
    name->move(WINDOW_W + 30, 50);
    name->resize(WINDOW_EXTRA - 60, 50);
    name->setText("LPop");
    name->setFont(font);
    font.setPointSize(24);
    score->move(WINDOW_W + 30, 125);
    score->resize(WINDOW_EXTRA - 60, 50);
    score->setText(SCORE_PRE_TEXT + QString::number(m_score));
    score->setFont(font);
    life->move(WINDOW_W + 30, 200);
    life->resize(WINDOW_EXTRA - 60, 50);
    life->setText(LIFE_PRE_TEXT + QString::number(m_life));
    life->setFont(font);
    energy->move(WINDOW_W + 30, 275);
    energy->resize(WINDOW_EXTRA - 60, 50);
    energy->setText(ENERGY_PRE_TEXT + QString::number(m_energy) + "/" + QString::number(ENERGY_LINE));
    energy->setFont(font);

    bossbar = new QLabel(this);
    bossbar->setFont(font);

//    quitb = new QLabel(this);
//    quitb->move(WINDOW_W + 30, WINDOW_H - 100);
//    quitb->resize(WINDOW_EXTRA - 60, 50);
//    quitb->setText("Quit (CTRL-Q)");
//    quitb->setFont(font);
    font.setPointSize(14);
//    font.setBold(false);
    all = new QLabel(this);
    all->move(WINDOW_W + 30, 350);
    all->resize(WINDOW_EXTRA - 60, WINDOW_H - 350 - 70);
    all->setText("   LPop: A simple game written in Qt.\n   Use mouse or keyboard to move the blue plane to crash the red planes. Keep far from the bullets.\n - Press 'Space' key to use the skill.\n - 'Q' to quit, 'R' to restart.");
    all->setFont(font);
    all->setWordWrap(true);
    status = new QLabel(this);
    status->move(WINDOW_W + 30, WINDOW_H - 50);
    status->resize(WINDOW_EXTRA - 60, 30);
    status->setText("   The LPop game is made by 5+1.");
    status->setFont(font);



//    eneb = new QPushButton(this);
//    eneb->move(WINDOW_W + 30, WINDOW_H - 175);
//    eneb->resize(WINDOW_EXTRA - 60, 50);
//    eneb->setText("Skill (Space)");
//    eneb->setFont(font);
//    connect (eneb, &QPushButton::clicked, [=](){
//        EnergyPlay();
//    });

//    quitb = new QPushButton(this);
//    quitb->move(WINDOW_W + 30, WINDOW_H - 100);
//    quitb->resize(WINDOW_EXTRA - 60, 50);
//    quitb->setText("Quit");
//    quitb->setFont(font);
//    connect(quitb, &QPushButton::clicked, [=](){
//        close();
//    });


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

    if (nplane)
    {
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
    else
    {
        if (m_boss->m_Free) return;
        m_boss->updatePosition();
        m_boss->shoot();
        for (int j = 0 ;j < CONSTBOSS.BOSSL[bosspos].BOSS_BULLET_COUNT;j++)
        {
            for (int i = 0; i < ENEMY_BULLET_NUM; i ++)
            {
                if (!m_boss->m_bullets[i][j]->m_Free)
                {
                    qDebug() << "UPDATE" <<i <<j;
                    m_boss->m_bullets[i][j]->updatePosition();
                }
            }
        }
    }
}

void MainScene::enemyToScene()
{
    if (!nplane) return;
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
            m_enemys[i].m_Free = false;
            m_enemys[i].m_X = rand() % (WINDOW_W - m_enemys[i].m_Rect.width());
            m_enemys[i].m_Y = -m_enemys[i].m_Rect.height();
            break;
        }
    }
}

void MainScene::bossToScene()
{
    QMessageBox::information(this, tr("Boss is coming!"),
       tr("The boss is coming, good luck!"),
       QMessageBox::Ok,
       QMessageBox::Ok);


    bosspos ++;
    nplane = false;
    m_boss = new Boss(bosspos);
    m_boss->m_Free = false;
    bossbar->move(30, 30);
    bossbar->resize(WINDOW_W-60, 50);
    bossbar->setText(CONSTBOSS.BOSSL[bosspos].BOSS_NAME+" : "+QString::number(m_boss->m_life));
    bossbar->setStyleSheet("QLabel { color : white; }");

    QEventLoop eventloop;
    QTimer::singleShot(1000, &eventloop, SLOT(quit()));
    eventloop.exec();
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

                m_score += SCORE_BOMB_DEFAULT;
                m_energy += ENERGY_BOMB_DEFAULT;
                updateScore();
                updateEnergy();

                for(int k = 0 ; k < BOMB_NUM;k++)
                {
                    if(m_bombs[k].m_Free)
                    {
                        //??????????????????????????????
                        m_bombs[k].m_Free = false;
                        //????????????

                        m_bombs[k].m_X = m_enemys[i].m_X;
                        m_bombs[k].m_Y = m_enemys[i].m_Y;


                        break;
                    }
                }
            }
        }
    }
    for(int i = 0 ;i < ENEMY_NUM;i++)
    {
        for(int j = 0 ; j < ENEMY_BULLET_NUM;j++)
        {
            if (m_enemys[i].m_bullets[j].m_Free)
            {
                continue;
            }
            QRect temp_rect = m_enemys[i].m_bullets[j].m_Rect;
            temp_rect.setWidth(10);
            temp_rect.setHeight(10);
            if(m_plane.m_Rect.intersects(temp_rect))
            {
                m_enemys[i].m_bullets[j].m_Free = true;
                m_life -= LIFE_BULLET_DEFAULT;
                m_energy -= ENERGY_LOSE;
                updateLife();
                updateEnergy();
            }
        }
    }

    if (!nplane)
    {
        for (int i = 0; i < CONSTBOSS.BOSSL[bosspos].BOSS_BULLET_COUNT; i ++)
        {
            for (int j = 0; j < ENEMY_BULLET_NUM; j ++)
            {
                if (m_boss->m_bullets[j][i]->m_Free) continue;
                QRect temp_rect = m_boss->m_bullets[j][i]->m_Rect;
                temp_rect.setWidth(10);
                temp_rect.setHeight(10);
                if(m_plane.m_Rect.intersects(temp_rect))
                {
                    m_boss->m_bullets[j][i]->m_Free = true;
                    m_life -= CONSTBOSS.BOSSL[bosspos].BOSS_BULLET_KILL[i];
                    m_energy -= ENERGY_LOSE;
                    updateLife();
                    updateEnergy();
                }
            }
        }
        if (!m_boss->m_Free)
        {
            for(int j = 0 ; j < BULLET_NUM;j++)
            {
                if(m_plane.m_bullets[j].m_Free)
                {
                    continue;
                }
                if(m_boss->m_Rect.intersects(m_plane.m_bullets[j].m_Rect))
                {
                    m_plane.m_bullets[j].m_Free = true;

                    m_score += 2 * SCORE_BOMB_DEFAULT;
                    m_energy += ENERGY_BOMB_DEFAULT;
                    updateScore();
                    updateEnergy();

                    m_boss->m_life -= BULLET_KILL;
                    updateBoss();
                    if (m_boss->m_life <= 0)
                    {

                        deleteBoss();
                        return;
                    }
                }
            }
        }
    }

}

void MainScene::deleteBoss()
{
    m_boss->m_Free = true;
    bossbar->hide();
    for (int j = 0; j < CONSTBOSS.BOSSL[bosspos].BOSS_BULLET_COUNT; j ++)
    {
        for (int i = 0; i < ENEMY_BULLET_NUM; i ++)
        {
            qDebug() << i << j;
            m_boss->m_bullets[i][j]->m_Free = true;
        }
    }
    QMessageBox::information(this, tr("Well Done"),
       tr("Well done, You won the boss. Let's continue!"),
       QMessageBox::Ok,
       QMessageBox::Ok);
    m_score += 100, m_life = (m_life + 100) % LIFE_START;
    updateScore();
    updateLife();

    QEventLoop eventloop;
    QTimer::singleShot(1000, &eventloop, SLOT(quit()));
    eventloop.exec();

    nplane = true;
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

    if (nplane)
    {
        for(int i = 0 ; i< ENEMY_NUM;i++)
        {
            if(m_enemys[i].m_Free == false)
            {
                painter.drawPixmap(m_enemys[i].m_X,m_enemys[i].m_Y,m_enemys[i].m_enemy);
            }
            for(int j = 0 ;j < ENEMY_BULLET_NUM;j++)
            {
                if(!m_enemys[i].m_bullets[j].m_Free && nplane)
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
    else
    {
        qDebug() << "Draw Boss.";
        if (!m_boss->m_Free)
        {
            painter.drawPixmap(m_boss->m_X,m_boss->m_Y,m_boss->m_enemy);
            for (int j = 0; j < CONSTBOSS.BOSSL[bosspos].BOSS_BULLET_COUNT; j ++)
            {
                for (int i = 0; i < ENEMY_BULLET_NUM; i ++)
                {
                    if (!m_boss->m_bullets[i][j]->m_Free)
                    painter.drawPixmap(m_boss->m_bullets[i][j]->m_X,m_boss->m_bullets[i][j]->m_Y,m_boss->m_bullets[i][j]->m_Bullet);
                }
            }
        }
    }
}

void MainScene::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x() - m_plane.m_Rect.width()*0.5; //???????????? - ?????????????????????
    int y = event->y() - m_plane.m_Rect.height()*0.5;

    //????????????
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
    if (event->key() == Qt::Key_Space)
    {
        EnergyPlay();
    }
    if (event->key() == Qt::Key_Q)
    {
        qApp->exit(0);
    }
    if (event->key() == Qt::Key_R)
    {
        qApp->exit(WINDOW_EXIT);
    }
//    if (event->key() == Qt::Key_H)
//    {
//        QMessageBox msgBox;
//        msgBox.setWindowTitle("Help - LPop Game");
//        msgBox.setText("Use mouse or keyboard to move the blue plane to crash the red plane.\nIf your energy is more than the line, you can use the skill (Press space to use) to crash all the planes.\nYou must keep far from the bullets.");
//        msgBox.setStandardButtons(QMessageBox::Ok);
//        msgBox.setDefaultButton(QMessageBox::Ok);
//        msgBox.exec();
//    }
    update();
}

void MainScene::updateScore()
{
    score->setText(SCORE_PRE_TEXT + QString::number(m_score));
    if (m_score >= 1500 && bosspos < 0)
    {
        bossToScene();
    }
}

void MainScene::updateLife()
{
    life->setText(LIFE_PRE_TEXT + QString::number(m_life));
    if (m_life <= 0)
    {
//        hide();
        QString str = "Game over, you have got " + QString::number(m_score) + ". Click Cancel to exit.";
        int ret = QMessageBox::	critical(this, tr("Game over"),
                   str,
                   QMessageBox::Retry | QMessageBox::Cancel,
                   QMessageBox::Retry);
        switch (ret) {
            case QMessageBox::Retry:
                qApp->exit(WINDOW_EXIT);
                break;
            case QMessageBox::Cancel:
                qApp->exit(0);
                break;
            default:
              // should never be reached
              break;
        }
    }
}

void MainScene::updateEnergy()
{
    if (m_energy < 0) m_energy = 0;
    energy->setText(ENERGY_PRE_TEXT + QString::number(m_energy) + "/" + QString::number(ENERGY_LINE));
}

void MainScene::EnergyPlay()
{
    if (m_energy >= ENERGY_LINE)
    {
        m_energy -= ENERGY_LINE;
        updateEnergy();
        if (nplane)
            for (int i = 0; i < ENEMY_NUM; i ++)
            {
                m_enemys[i].m_Free = true;
                for (int j = 0; j < ENEMY_BULLET_NUM; j ++)
                {
                    m_enemys[i].m_bullets[j].m_Free = true;
                }
            }
        else
        {
            m_boss->m_life -= 50;
            updateBoss();
        }
    }
}

void MainScene::updateBoss()
{
    bossbar->setText(CONSTBOSS.BOSSL[bosspos].BOSS_NAME+" : "+QString::number(m_boss->m_life));
}
