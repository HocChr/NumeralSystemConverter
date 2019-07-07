#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->lineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(onEditBinar()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onEditBinar()
{
    qDebug() << "Hallöle";
}
