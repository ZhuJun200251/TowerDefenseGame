#include "startfrom.h"
#include "ui_startfrom.h"
#include "mainwindow.h"

StartFrom::StartFrom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartFrom)
{
    ui->setupUi(this);

    setWindowTitle("开始界面");

    connect(ui->pushButton, &QPushButton::clicked, [=]()
    {
        MainWindow *mainwindow = new MainWindow();

        mainwindow->show();
    });
}

StartFrom::~StartFrom()
{
    delete ui;
}
