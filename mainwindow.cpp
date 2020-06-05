#include "mainwindow.h"
#include <QDebug>
#include "globalstruct.h"
#include <math.h>
#include "greenturret.h"
#include "fireturret.h"
#include "lightturret.h"
#include "bigturret.h"
#include <QPushButton>

#define PI 3.1416

#define MouClickRegion(X, Width, Y, Height)     \
(ev->x() >= (X) && ev->x() <= (X) + (Width) &&  \
ev->y() >= (Y) && ev->y() <= (Y) + (Height))

#define DistBetPoints(X1, Y1, X2, Y2)           \
abs(sqrt((((X1) - (X2)) * ((X1) - (X2))) + (((Y1) - (Y2)) * ((Y1) - (Y2)))))

#define X40(num) ((num) - 1) * 40 + 10

#define InsterMonster(PathNum, StaCoorNum, MonsterId)     \
MonsterVec.push_back(new Monster(pointarr[PathNum], PathLength[PathNum], X40(staco[StaCoorNum].x), X40(staco[StaCoorNum].y), MonsterId));

inline bool MainWindow::DeductionMoney(int money)
{
    if(this->money - money < 0) return true;
    this->money -= money;
    moneylable->setText(QString("金钱：%1").arg(this->money));
    return false;
}

MainWindow::MainWindow()
{
    setFixedSize(1040, 640);

    setWindowTitle("游戏界面");

    QLabel *victorylable = new QLabel(this);
    victorylable->move(176, 180);
    victorylable->setFont(QFont("楷体", 110));
    victorylable->setText(QString("游戏胜利"));
    victorylable->hide();

    QTimer* timer2 = new QTimer(this);
    timer2->start(2000);

    connect(timer2,&QTimer::timeout,[=]()
    {
            CoorStr* Waypointarr1[] = {new CoorStr(X40(8), X40(6)), new CoorStr(X40(2), X40(6)),
                                       new CoorStr(X40(2), X40(13)), new CoorStr(X40(19), X40(13)), new CoorStr(X40(19), X40(9)), new CoorStr(homecoor->x, homecoor->y)};
            CoorStr* Waypointarr2[] = {new CoorStr(X40(20), X40(5)), new CoorStr(X40(14), X40(5)),
                                       new CoorStr(X40(14), X40(9)), new CoorStr(X40(8), X40(9)), new CoorStr(X40(8), X40(6)), new CoorStr(X40(2), X40(6)),
                                             new CoorStr(X40(2), X40(13)), new CoorStr(X40(19), X40(13)),
                                       new CoorStr(X40(19), X40(9)), new CoorStr(homecoor->x, homecoor->y)};
            CoorStr staco[] = {CoorStr(8, 0), CoorStr(20, 0), CoorStr(8, -1), CoorStr(20, -1)};

            int PathLength[] = {sizeof(Waypointarr1)/sizeof(CoorStr*), sizeof(Waypointarr1)/sizeof(CoorStr*)};

            IrodMonsProgDefa(Waypointarr1, Waypointarr2, staco, PathLength, victorylable);
    });

    moneylable->move(20, 40);
    setStyleSheet("color:white");
    moneylable->setFont(QFont("微软雅黑", 24));
    moneylable->setText(QString("金钱：%1").arg(money));

    QLabel *lifelable = new QLabel(this);
    lifelable->setGeometry(20, 100, 220, 40);
    lifelable->setFont(QFont("微软雅黑", 24));
    lifelable->setText(QString("生命：%1").arg(life));

    QTimer* timer = new QTimer(this);
    timer->start(120);

    connect(timer,&QTimer::timeout,[=]()
    {
        for (auto defei : DefeTowerVec)
        {
            if (!defei->GetAimsMonster())
            {
                for(int i = MonsterVec.size() - 1; i >= 0; i--)
                    if (DistBetPoints(defei->GetUpLeftX() + 40, defei->GetUpLeftY() + 40,
                        MonsterVec.at(i)->GetX() + (MonsterVec.at(i)->GetWidth() >> 1),
                        MonsterVec.at(i)->GetY() + (MonsterVec.at(i)->GetHeight() >> 1)) <= defei->GetRange())
                    {
                        defei->SetAimsMonster(MonsterVec.at(i));
                        break;
                    }
            }
            else
                if (DistBetPoints(defei->GetUpLeftX() + 40, defei->GetUpLeftY() + 40,
                    defei->GetAimsMonster()->GetX() + (defei->GetAimsMonster()->GetWidth() >> 1),
                    defei->GetAimsMonster()->GetY() + (defei->GetAimsMonster()->GetHeight() >> 1)) <= defei->GetRange())
                {
                    defei->SetRotatAngle(
                        atan2
                        (
                            defei->GetAimsMonster()->GetY() - defei->GetUpLeftY() + 40,
                            defei->GetAimsMonster()->GetX() - defei->GetUpLeftX()
                        ) * 180 / PI );

                     defei->InterBullet();
                }

            if (defei->GetAimsMonster())
                if (DistBetPoints(defei->GetUpLeftX() + 40, defei->GetUpLeftY() + 40,
                    defei->GetAimsMonster()->GetX() + (defei->GetAimsMonster()->GetWidth() >> 1),
                    defei->GetAimsMonster()->GetY() + (defei->GetAimsMonster()->GetHeight() >> 1)) > defei->GetRange())
                        defei->SetAimsMonster(NULL);
        }

        for (auto defei : DefeTowerVec)
            defei->BulletMove();

        for (auto Moni = MonsterVec.begin(); Moni != MonsterVec.end(); Moni++)
            if((*Moni)->Move())
            {
                delete *Moni;
                MonsterVec.erase(Moni);
                life--;
                lifelable->setText(QString("生命：%1").arg(life));

                if (life <= 0) this->close();

                break;
            }

        for (auto defei : DefeTowerVec)
        {
            auto &tbullvec = defei->GetBulletVec();
            for (auto bullit = tbullvec.begin(); bullit != tbullvec.end(); bullit++)
                for (auto monit = MonsterVec.begin(); monit != MonsterVec.end(); monit++)
                    if ((*bullit)->GetX() + (defei->GetBulletWidth() >> 1) >= (*monit)->GetX() && (*bullit)->GetX() <= (*monit)->GetX() + (*monit)->GetWidth() &&
                       (*bullit)->GetY() + (defei->GetBulletHeight() >> 1) >= (*monit)->GetY() && (*bullit)->GetY() <= (*monit)->GetY() + (*monit)->GetHeight())
                    {
                        tbullvec.erase(bullit);

                        (*monit)->SetHealth((*monit)->GetHealth() - defei->GetAttack());

                        if ((*monit)->GetHealth() <= 0)
                        {
                            for (auto defei2 : DefeTowerVec)
                                if (defei2->GetAimsMonster() == *monit)
                                    defei2->SetAimsMonster(NULL);

                            MonsterVec.erase(monit);
                            money += RewardMoney;
                            moneylable->setText(QString("金钱：%1").arg(money));
                        }
                        goto L1;
                    }
            L1:;
        }

        update();
    });
}

void MainWindow::IrodMonsProgDefa(CoorStr** Waypointarr1, CoorStr** Waypointarr2, CoorStr* staco, int* PathLength, QLabel* victorylable)
{
    CoorStr** pointarr[] = {Waypointarr1, Waypointarr2};

    if(counter >= 1 && counter <= 14)
    {
        InsterMonster(0, 0, 1);
    }
    else if(counter > 14 && counter <= 34)
    {
        InsterMonster(0, 0, 1);
        InsterMonster(1, 1, 2);
    }
    else if (counter > 34 && counter <= 35)
    {
        InsterMonster(0, 0, 3);
        InsterMonster(1, 1, 3);
    }
    else if (counter > 35 && counter <= 52)
    {
        InsterMonster(0, 2, 4);
        InsterMonster(0, 0, 4);
        InsterMonster(1, 1, 1);
    }
    if(counter > 52 && counter <= 56)
    {
        InsterMonster(0, 0, 3);
        InsterMonster(1, 1, 3);
    }
    if (counter > 52 && counter <= 71)
    {
        InsterMonster(0, 2, 2);
        InsterMonster(0, 0, 5);
        InsterMonster(1, 3, 1);
        InsterMonster(1, 1, 4);
    }

    if (counter > 71 && MonsterVec.empty())
        victorylable->show();

    counter++;
    update();
}

void MainWindow::DrawMapArr(QPainter& painter)
{
    int Map_1[16][26] =
    {
        0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 1, 1, 3, 6, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 1, 1, 6, 6, 0, 0, 0, 0, 0, 0, 3, 6, 1, 1, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 3, 6, 1, 1, 3, 6, 0, 0, 0, 0, 0, 0, 6, 6, 1, 1, 3, 6, 0, 0, 0,
        0, 0, 0, 0, 0, 6, 6, 1, 1, 6, 6, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 6, 6, 0, 0, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 3, 6, 0, 1, 1, 0, 0, 0, 0, 3, 6, 0, 0, 0, 0, 0,
        0, 1, 1, 0, 3, 6, 0, 1, 1, 0, 6, 6, 0, 1, 1, 0, 3, 6, 0, 6, 6, 0, 0, 0, 0, 0,
        0, 1, 1, 0, 6, 6, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 6, 6, 1, 1, 1, 1, 1, 1, 5, 5,
        0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 5, 5,
        0, 1, 1, 0, 3, 6, 0, 0, 3, 6, 0, 0, 3, 6, 0, 0, 3, 6, 1, 1, 3, 6, 0, 0, 0, 0,
        0, 1, 1, 0, 6, 6, 0, 0, 6, 6, 0, 0, 6, 6, 0, 0, 6, 6, 1, 1, 6, 6, 0, 0, 0, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
        0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };

    int Map[16][26];

    memcpy(Map, Map_1, sizeof(Map));

    for (int j = 0; j < 16; j++)
        for (int i = 0; i < 26; i++)
        {
            switch (Map[j][i])
            {
            case 0:
                painter.drawPixmap(i * 40, j * 40, 40, 40,
                    QPixmap(":/image/草地块.png"));
                break;
            case 1:
                painter.drawPixmap(i * 40, j * 40, 40, 40,
                    QPixmap(":/image/地面.png"));
                break;
            case 3:
                painter.drawPixmap(i * 40, j * 40, 80, 80,
                    QPixmap(":/image/石砖块.png"));
                TowerPitVec.push_back(new DefenseTowerPit(i * 40, j * 40));
                break;
            case 5:
                painter.drawPixmap(i * 40, j * 40, 80, 80,
                    QPixmap(":/image/房子.png"));
                break;
            }
        }
}

void MainWindow::DrawSelectionBox(QPainter& painter)
{
    if (!SelBox->GetDisplay())
        return;

    painter.drawPixmap(SelBox->GetX(), SelBox->GetY(), SelBox->GetWidth(), SelBox->GetHeight(),
        QPixmap(SelBox->GetImgPath()));

    SubbutStr *ASubBut = SelBox->GetSelSubBut();
    for (int i = 0; i < 4; i++)
        painter.drawPixmap(ASubBut[i].SubX, ASubBut[i].SubY, ASubBut[i].SubWidth, ASubBut[i].SubHeight,
            QPixmap(ASubBut[i].SubImgPath));

    painter.setPen(QPen(Qt::yellow, 6, Qt::SolidLine));
    painter.drawRect(QRect(SelBox->GetX() + 95, SelBox->GetY() + 95, 80, 80));
}

void MainWindow::DrawDefenseTower(QPainter& painter)
{
    for (auto defei : DefeTowerVec)
    {
        painter.drawPixmap(defei->GetUpLeftX(), defei->GetUpLeftY(), 80, 80, QPixmap(defei->GetBaseImgPath()));

        if(DisplayAllRange)
            painter.drawEllipse(QPoint(defei->GetUpLeftX() + 40, defei->GetUpLeftY() + 40), defei->GetRange(), defei->GetRange());

        for (auto bulli : defei->GetBulletVec())
            painter.drawPixmap(bulli->coor.x, bulli->coor.y, defei->GetBulletWidth(), defei->GetBulletHeight(),QPixmap(defei->GetBulletPath()));

        painter.translate(defei->GetUpLeftX() + 40, defei->GetUpLeftY() + 40);
        painter.rotate(defei->GetRotatAngle());
        painter.translate(-(defei->GetUpLeftX() + 40), -(defei->GetUpLeftY() + 40));
        painter.drawPixmap(defei->GetX(), defei->GetY(), defei->GetWidth(), defei->GetHeight(), QPixmap(defei->GetDefImgPath()));

        painter.resetTransform();
    }
}

void MainWindow::DrawMonster(QPainter& painter)
{
    for (auto moni : MonsterVec)
        painter.drawPixmap(moni->GetX(), moni->GetY(), moni->GetWidth(), moni->GetHeight(), QPixmap(moni->GetImgPath()));
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    DrawMapArr(painter);

    DrawDefenseTower(painter);

    DrawMonster(painter);

    DrawSelectionBox(painter);
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if (ev->button() != Qt::LeftButton)
        return;

    SubbutStr *ASubBut = SelBox->GetSelSubBut();
    for (int i = 0; i < 4; i++)
        if (MouClickRegion(ASubBut[i].SubX, ASubBut[i].SubWidth, ASubBut[i].SubY, ASubBut[i].SubHeight) && SelBox->GetDisplay())
        {
            SelBox->SetDisplay(false);
            switch (i)
            {
            case 0:
                if (DeductionMoney(100)) return;
                DefeTowerVec.push_back(new GreenTurret(SelBox->GetX() + 110, SelBox->GetY() + 112, SelBox->GetX() + 95, SelBox->GetY() + 95, 72, 46));
                break;
            case 1:
                if (DeductionMoney(160)) return;
                DefeTowerVec.push_back(new FireTurret(SelBox->GetX() + 110, SelBox->GetY() + 112, SelBox->GetX() + 95, SelBox->GetY() + 95, 72, 46));
                break;
            case 2:
                if (DeductionMoney(240)) return;
                DefeTowerVec.push_back(new LightTurret(SelBox->GetX() + 110, SelBox->GetY() + 112, SelBox->GetX() + 95, SelBox->GetY() + 95, 76, 50));
                break;
            case 3:
                if (DeductionMoney(400)) return;
                DefeTowerVec.push_back(new BigTurret(SelBox->GetX() + 110, SelBox->GetY() + 104, SelBox->GetX() + 95, SelBox->GetY() + 95, 80, 70));
                break;
            default:
                break;
            }

            update();
            return;
        }

    for (auto APit : TowerPitVec)
        if (MouClickRegion(APit->GetX(), APit->GetWidth(), APit->GetY(), APit->GetHeight()))
        {
            for (auto defei : DefeTowerVec)
                if(defei->GetUpLeftX() == APit->GetX() && defei->GetUpLeftY() == APit->GetY())
                {
                    DisplayRangeX = defei->GetUpLeftX(), DisplayRangeY = defei->GetUpLeftY();
                    return;
                }

            SelBox->CheckTower(APit->GetX(), APit->GetY());
            update();

            return;
        }

    SelBox->SetDisplay(false);

    update();
}

//析构释放内存
MainWindow::~MainWindow()
{
    for (auto it = TowerPitVec.begin(); it != TowerPitVec.end(); it++)
    {
        delete *it;
        *it = NULL;
    }

    delete SelBox;
    SelBox = NULL;

    for (auto it = DefeTowerVec.begin(); it != DefeTowerVec.end(); it++)
    {
        delete *it;
        *it = NULL;
    }

    for (auto it = MonsterVec.begin(); it != MonsterVec.end(); it++)
    {
        delete *it;
        *it = NULL;
    }

    delete homecoor;
}
