#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT

public:
    Controller();

public slots:
    void onHexChanged    (std::string &v);
    void onDecimalChanged(std::string &v);
    void onBinarChanged  (std::string &v);

};

#endif // CONTROLLER_H
