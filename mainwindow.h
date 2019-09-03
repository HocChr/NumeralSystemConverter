#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void binarChanged  (std::string& value);
    void decimalChanged(std::string& value);
    void hexChanged    (std::string& value);

private slots:
    void onEditBinar();
    void onEditDecimal();
    void onEditHex();

public slots:
    void onDataChanged(std::string& decimal,std::string& binar,std::string& hex);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
