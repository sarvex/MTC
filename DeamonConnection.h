#ifndef DEAMONCONNECTION_H
#define DEAMONCONNECTION_H

#include <QObject>
#include <QTimer>

#include <windows.h>
#include <ras.h>
#include <raserror.h>


class DeamonConnection : public QObject {
    Q_OBJECT
public:
    static DeamonConnection* getInstance ();

    bool connectDataCall();
    bool disconnectDataCall();

    bool removeConnectionEntry();

    bool createConnectionEntry();
    bool deleteConnectionEntry();

    long int getTransmissionSpeed();
    long int getRecievingSpeed();

    bool connected(bool status);
    bool error(int errorNumber, QString errorMessage);

signals:
    bool speedUpdate (double upload, double download);
    bool usageUpdate (double upload, double download);

    bool modemConnected (bool status);

    bool rasError(int errorNumber, QString errorMessage);

public slots:
    bool onTimer();
    bool onModemConnected(bool status);

protected:

private:
    QString getModemName ();

    explicit DeamonConnection(QObject *parent = 0);
    static DeamonConnection* singleton;

    QTimer * timer;

    double bytesTransmitted;
    double bytesRecieved;
    double duration;

    friend void  CALLBACK RasDialFunc(UINT unMsg, RASCONNSTATE rasconnstate, DWORD dwError);
};

void CALLBACK RasDialFunc(UINT unMsg, RASCONNSTATE rasconnstate, DWORD dwError);

#endif // DEAMONCONNECTION_H
