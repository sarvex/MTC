#ifndef HOMEWIDGET_H
#define HOMEWIDGET_H

#include "AnimateButton.h"
#include "ImageButton.h"
#include "TimeLabel.h"

#include <QLabel>
#include <QPixmap>
#include <QWidget>


class HomeWidget
        : public QWidget
{
    Q_OBJECT

public:
    explicit HomeWidget(QWidget *parent = 0);

signals:
    bool activateAction ();
    bool closeAction ();
    bool minimizeAction ();

public slots:
    bool onModemPlugged (bool status);
    bool onModemConnected (bool status);
    bool onSpeedUpdate (double uploaded, double downloaded);
    bool onUsageUpdate (double uploaded, double downloaded);

    bool onSettingsButtonClicked ();
    bool onSignalStrengthUpdate (int value);
    bool onDateRateUpdate (int value);

    bool onConnectButtonClicked ();
    bool onConnectingButtonClicked ();
    bool onDisconnectButtonClicked ();
    bool onDisconnectingButtonClicked ();

    bool onRetranslate();

protected:

private:
    ImageButton * minimizeButton;
    ImageButton * closeButton;


    QLabel * download;
    QLabel * upload;
    QLabel * uploadSpeed;
    QLabel * downloadSpeed;
    QLabel * downloadTraffic;
    QLabel * uploadTraffic;
    QLabel * speed;
    QLabel * traffic;
    QLabel * dataRate;
    QLabel * signalStrength;

    QLabel * homeDataBackground;
    QLabel * titleText;

    ImageButton * settingsButton;

    ImageButton * connectButton;
    ImageButton * disconnectButton;

    AnimateButton * connectingButton;
    AnimateButton * disconnectingButton;

    TimeLabel * sessionTime;

    QList <QPixmap> signalStrengthImage;
    QList <QPixmap> dataRates;

    bool connected;
    bool plugged;

    double uploaded;
    double downloaded;
};

#endif // HOMEWIDGET_H
