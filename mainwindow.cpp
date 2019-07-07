#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->editBinar  , SIGNAL(textChanged(const QString &)), this, SLOT(onEditBinar()));
    connect(ui->editDecimal, SIGNAL(textChanged(const QString &)), this, SLOT(onEditDecimal()));
    connect(ui->editHex    , SIGNAL(textChanged(const QString &)), this, SLOT(onEditHex()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onEditBinar()
{
    qDebug() << "onEditBinar";
}

void MainWindow::onEditDecimal()
{
    qDebug() << "onEditDecimal";
}

void MainWindow::onEditHex()
{
    qDebug() << "onEditHex";
}
