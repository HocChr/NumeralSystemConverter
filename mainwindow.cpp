#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QIntValidator>
#include <QFile>
#include <math.h>

//--- Helper Classes --------------------------------------

class BinarValidator : public QIntValidator
{
public:
    BinarValidator(int bottom, int top, QObject * parent) :
        QIntValidator(bottom, top, parent)
    {
    }

    QValidator::State validate(QString &s, int &i) const override;
};

QValidator::State BinarValidator::validate(QString &s, int &) const
{
    if (s.isEmpty() || s == "-")
    {
        return QValidator::Intermediate;
    }

    for(QString::const_iterator itr(s.begin()); itr != s.end(); ++itr)
    {
        if( QString::compare(*itr, "0", Qt::CaseInsensitive) != 0 &&
                QString::compare(*itr, "1", Qt::CaseInsensitive) != 0 )
            return  QValidator::Invalid;;
    }
    return QValidator::Acceptable;
}

//---------------------------------------------------------

class MyIntValidator : public QIntValidator
{
public:
    MyIntValidator(int bottom, int top, QObject * parent) :
        QIntValidator(bottom, top, parent)
    {
    }

    QValidator::State validate(QString &s, int &i) const override;
};

QValidator::State MyIntValidator::validate(QString &s, int &) const
{
    if (s.isEmpty()) {
        return QValidator::Intermediate;
    }

    bool ok;
    int d = s.toInt(&ok);

    if (ok && d >= bottom() && d <= top()) {
        return QValidator::Acceptable;
    } else {
        return QValidator::Invalid;
    }
}

//--- Main-Window -----------------------------------------

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Zahlenkonverter");

    ui->editBinar  ->setValidator(new BinarValidator(0, 100, this));
    ui->editDecimal->setValidator(new MyIntValidator(0, static_cast<int>(pow(2, 24)), this));
    //ui->editHex    ->setInputMask("HH-HH-HH-HH");

    connect(ui->editBinar  , SIGNAL(textChanged(const QString &)), this, SLOT(onEditBinar()));
    connect(ui->editDecimal, SIGNAL(textChanged(const QString &)), this, SLOT(onEditDecimal()));
    connect(ui->editHex    , SIGNAL(textChanged(const QString &)), this, SLOT(onEditHex()));

    setMaximumSize(300, 90);

    QFile File("darkorange_stylesheet.qss");
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());
    qApp->setStyleSheet(StyleSheet);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onDataChanged(std::string &decimal, std::string &binar, std::string &hex)
{
    ui->editDecimal->blockSignals(true);
    ui->editHex    ->blockSignals(true);
    ui->editBinar  ->blockSignals(true);
    
    ui->editDecimal->setText(decimal.c_str());
    ui->editHex    ->setText(hex.c_str());
    ui->editBinar  ->setText(binar.c_str());
    
    ui->editDecimal->blockSignals(false);
    ui->editHex    ->blockSignals(false);
    ui->editBinar  ->blockSignals(false);
}

void MainWindow::onEditBinar()
{
    std::string value = ui->editBinar->text().toStdString();
    emit binarChanged(value);
}

void MainWindow::onEditDecimal()
{
    std::string value = ui->editDecimal->text().toStdString();
    emit decimalChanged(value);
}

void MainWindow::onEditHex()
{
    std::string value = ui->editHex->text().toStdString();
    emit hexChanged(value);
}

