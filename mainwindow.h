#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <Qtimer>
#include "defensetowerpit.h"
#include "selectionbox.h"
#include "defetowerparent.h"
#include "monster.h"
#include <QLabel>

class MainWindow : public QWidget
{
private:
    QVector<DefenseTowerPit*> TowerPitVec;
    SelectionBox* SelBox = new SelectionBox(":/image/选择框.png");

    QVector<DefeTowerParent*> DefeTowerVec;

    QVector<Monster*> MonsterVec;

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void DrawMapArr(QPainter&);
    void DrawSelectionBox(QPainter&);
    void DrawDefenseTower(QPainter&);
    void DrawMonster(QPainter&);

    int DisplayRangeX, DisplayRangeY;
    bool DisplayRange = false;

    int money = 1000;
    QLabel *moneylable = new QLabel(this);

    inline bool DeductionMoney(int);

    int life = 10;

    int counter = 0;

    const int RewardMoney = 28;

    CoorStr *homecoor = new CoorStr(0, 0);

    void IrodMonsProgDefa(CoorStr**, CoorStr**, CoorStr*, int*, QLabel*);

    bool DisplayAllRange = false;

public:
    MainWindow();
    ~MainWindow();
};

#endif  //MAINWINDOW_H
