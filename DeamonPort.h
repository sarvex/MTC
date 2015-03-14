#ifndef DEAMONPORT_H
#define DEAMONPORT_H

#include <QThread>

#include "SerialPort.h"

#include <QMutex>
#include <QQueue>
#include <QTimer>

class DeamonPort : public QThread {
    Q_OBJECT
public:
    static DeamonPort* getInstance ();

    bool writeToAtPort(QString value);

    bool writeAtInformation();
    bool writeAtDiagnostic();

    bool stop();

signals:
    bool modemPlugged(bool status);

    bool signalStrengthUpdate(int value);
    bool dataRateUpdate(int value);

    bool softwareVersionUpdate (QString value);
    bool prlUpdate (QString value);
    bool meidUpdate (QString value);
    bool esnUpdate (QString value);
    bool cmeErrorUpdate (QString value);

public slots:
    bool onSystemUpdateTimer();

protected:
    void run();

private:
    explicit DeamonPort(QObject *parent = 0);
    static DeamonPort* singleton;

    bool checkPort ();
    bool openPort ();

    bool writeToAtPort();
    bool readFromAtPort();
    bool parseResponse(QByteArray& value);


    SerialPort * port;

    QMutex * mutex;

    QQueue<QString> queue;

    QString portName;

    QTimer * systemInformationTimer;

    volatile bool running;

    bool plugged;

    static const QString end;


};

#endif // DEAMONPORT_H
