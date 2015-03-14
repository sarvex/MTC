#ifndef DEAMONNETWORK_H
#define DEAMONNETWORK_H

#include <QObject>

class DeamonNetwork : public QObject {
    Q_OBJECT
public:
    static DeamonNetwork* getInstance ();



signals:

public slots:

protected:

private:
    explicit DeamonNetwork(QObject *parent = 0);
    static DeamonNetwork* singleton;
};

#endif // DEAMONNETWORK_H
