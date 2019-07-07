#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT

public:
    Controller();

public slots:
    void onHexChanged();

};

#endif // CONTROLLER_H
