#include "DeamonConnection.h"
#include "DeamonDatabase.h"
#include "DeamonPort.h"
#include "HomeWidget.h"

#include <QApplication>
#include <QMessageBox>

HomeWidget::HomeWidget
(QWidget *parent) :
    QWidget(parent),
    connected(false),
    plugged (false)
{
    this->homeDataBackground = new QLabel (this);
    this->homeDataBackground->setPixmap (QPixmap(":/homeDataBg.png"));
    this->homeDataBackground->setGeometry (0, 0, 480, 213);

    this->sessionTime = new TimeLabel (this);
    this->sessionTime->setGeometry (385, 52, 70, 20);

    this->download = new QLabel (tr("Download"), this);
    this->download->setGeometry (275, 163, 80, 18);

    this->upload = new QLabel (tr("Upload"), this);
    this->upload->setGeometry (275, 147, 80, 18);

    this->downloadSpeed = new QLabel (tr("0.0 Kbps"), this);
    this->downloadSpeed->setGeometry (340, 163, 65, 18);

    this->uploadSpeed = new QLabel (tr("0.0 Kbps"), this);
    this->uploadSpeed->setGeometry (340, 147, 65, 18);

    this->downloadTraffic = new QLabel (tr("0.0 MB"), this);
    this->downloadTraffic->setGeometry (405, 163, 60, 18);

    this->uploadTraffic = new QLabel (tr("0.0 MB"), this);
    this->uploadTraffic->setGeometry (405, 147, 60, 18);

    this->speed = new QLabel (tr("Speed"), this);
    this->speed->setGeometry (350, 125, 60, 18);

    this->traffic = new QLabel (tr("Traffic"), this);
    this->traffic->setGeometry (405, 125, 60, 18);

    this->titleText = new QLabel (tr("MTC Connect"), this);
    this->titleText->setStyleSheet ("QLabel { color: white; font: bold 15px; }");
    this->titleText->setGeometry (38, 5, 160, 22);

    this->settingsButton = new ImageButton(tr("Settings"), ":/mediumButtonDefault.png", ":/mediumButtonHover.png", ":/mediumButtonPress.png", false, this);
    this->settingsButton->setGeometry (15, 165, 120, 31);
    this->settingsButton->setEnabled (false);

    this->connectButton = new ImageButton(tr("Connect"), ":/bigButtonDefault.png", ":/bigButtonHover.png", ":/bigButtonPress.png", false, this);
    this->connectButton->setSize (22);
    this->connectButton->setBold (false);
    this->connectButton->setGeometry (15, 70, 214, 42);
    this->connectButton->setEnabled (false);

    this->disconnectButton = new ImageButton(tr("Disconnect"), ":/bigButtonDefault.png", ":/bigButtonHover.png", ":/bigButtonPress.png", false, this );
    this->disconnectButton->setSize (22);
    this->disconnectButton->setBold (false);
    this->disconnectButton->setGeometry (15, 70, 214, 42);
    this->disconnectButton->setVisible (false);

    this->connectingButton = new AnimateButton(tr("Connecting"), ":/bigButtonDefault.png", ":/bigButtonHover.png", ":/bigButtonPress.png", ":/bigButtonDefault.png", ":/bigButtonHover.png", ":/bigButtonPress.png", this);
    this->connectingButton->setSize (22);
    this->connectingButton->setBold (false);
    this->connectingButton->setGeometry (15, 70, 214, 42);
    this->connectingButton->setVisible (false);

    this->disconnectingButton = new AnimateButton(tr("Disconnecting"), ":/bigButtonDefault.png", ":/bigButtonHover.png", ":/bigButtonPress.png", ":/bigButtonDefault.png", ":/bigButtonHover.png", ":/bigButtonPress.png", this);
    this->disconnectingButton->setSize (22);
    this->disconnectingButton->setBold (false);
    this->disconnectingButton->setGeometry (15, 70, 214, 42);
    this->disconnectingButton->setVisible (false);

    this->signalStrengthImage.append (QPixmap(":/signalStrength0.png"));
    this->signalStrengthImage.append (QPixmap(":/signalStrength1.png"));
    this->signalStrengthImage.append (QPixmap(":/signalStrength2.png"));
    this->signalStrengthImage.append (QPixmap(":/signalStrength3.png"));
    this->signalStrengthImage.append (QPixmap(":/signalStrength4.png"));
    this->signalStrengthImage.append (QPixmap(":/signalStrength5.png"));

    this->signalStrength = new QLabel (this);
    this->signalStrength->setGeometry (280, 108, 172, 16);
    this->signalStrength->setPixmap (this->signalStrengthImage.at(0));

    this->dataRates.append (QPixmap(":/speedMeter1.png"));
    this->dataRates.append (QPixmap(":/speedMeter2.png"));
    this->dataRates.append (QPixmap(":/speedMeter3.png"));
    this->dataRates.append (QPixmap(":/speedMeter4.png"));
    this->dataRates.append (QPixmap(":/speedMeter5.png"));
    this->dataRates.append (QPixmap(":/speedMeter6.png"));
    this->dataRates.append (QPixmap(":/speedMeter7.png"));
    this->dataRates.append (QPixmap(":/speedMeter8.png"));
    this->dataRates.append (QPixmap(":/speedMeter9.png"));
    this->dataRates.append (QPixmap(":/speedMeter10.png"));
    this->dataRates.append (QPixmap(":/speedMeter11.png"));
    this->dataRates.append (QPixmap(":/speedMeter12.png"));

    this->dataRate = new QLabel (this);
    this->dataRate->setPixmap (this->dataRates.at(0));
    this->dataRate->setGeometry (280, 80, 172, 15);

    this->minimizeButton = new ImageButton("",
                                           ":/minimizeDefault.png",
                                           ":/minimizeHover.png",
                                           false, this);
    this->minimizeButton->setGeometry (418, 5, 22, 22);

    this->closeButton = new ImageButton("",
                                        ":/closeDefault.png",
                                        ":/closeHover.png",
                                        false, this);
    this->closeButton->setGeometry (446, 5, 21, 22);

    this->closeButton->setToolTip (tr("Close"));
    this->minimizeButton->setToolTip (tr("Minimize"));

    this->connectButton->setToolTip (tr ("Connect"));
    this->connectingButton->setToolTip (tr ("Connecting"));
    this->disconnectButton->setToolTip (tr ("Disconnect"));
    this->disconnectingButton->setToolTip (tr ("Disconnecting"));
    this->settingsButton->setToolTip (tr ("Settings"));

    QObject::connect (this->settingsButton,
                      SIGNAL(clicked()),
                      this,
                      SLOT(onSettingsButtonClicked()));

    QObject::connect (this->connectButton,
                      SIGNAL(clicked()),
                      this,
                      SLOT(onConnectButtonClicked()));

    QObject::connect (this->disconnectButton,
                      SIGNAL(clicked()),
                      this,
                      SLOT(onDisconnectButtonClicked()));

    QObject::connect (this->minimizeButton,
                      SIGNAL(clicked()),
                      this,
                      SIGNAL(minimizeAction ()));

    QObject::connect (this->closeButton,
                      SIGNAL(clicked()),
                      this, SIGNAL
                      (closeAction ()));

    QObject::connect (DeamonConnection::getInstance (),
                      SIGNAL(modemConnected (bool)),
                      this,
                      SLOT(onModemConnected(bool)));

    QObject::connect (DeamonPort::getInstance (),
                      SIGNAL(modemPlugged (bool)),
                      this,
                      SLOT(onModemPlugged (bool)));

    QObject::connect (DeamonConnection::getInstance (),
                      SIGNAL(speedUpdate(double, double)),
                      this,
                      SLOT(onSpeedUpdate(double, double)));

    QObject::connect (DeamonConnection::getInstance (),
                      SIGNAL (usageUpdate (double, double)),
                      this,
                      SLOT(onUsageUpdate(double,double)));

    QObject::connect (DeamonPort::getInstance (),
                      SIGNAL(signalStrengthUpdate(int)),
                      this,
                      SLOT(onSignalStrengthUpdate(int)));

    QObject::connect (DeamonPort::getInstance (),
                      SIGNAL(dataRateUpdate(int)),
                      this,
                      SLOT(onDateRateUpdate(int)));
}

bool
HomeWidget::onModemPlugged
(bool status)
{
    this->plugged = status;

    this->connectButton->setEnabled (status);
    this->settingsButton->setEnabled (status);

    if (false == status) {
        this->onSignalStrengthUpdate (0);
    }

    return true;
}

bool
HomeWidget::onConnectButtonClicked
()
{
    DeamonConnection::getInstance ()->connectDataCall ();

    this->connectButton->hide ();
    this->connectingButton->show ();

    this->connected = false;

    return (true);
}

bool
HomeWidget::onConnectingButtonClicked
()
{
    DeamonConnection::getInstance ()->disconnectDataCall ();

    this->connectingButton->hide ();
    this->connectButton->show ();

    this->connected = false;

    return true;
}

bool HomeWidget::onDisconnectButtonClicked(){
    DeamonConnection::getInstance ()->disconnectDataCall ();

    this->disconnectButton->hide ();

    return true;
}

bool HomeWidget::onDisconnectingButtonClicked(){

    return true;
}

bool HomeWidget::onModemConnected (bool status){
    this->connected = status;

    if (true == status)
    {
        this->connectingButton->hide ();
        this->disconnectButton->show ();
    }

    else
    {
        this->connectingButton->hide ();
        this->disconnectingButton->hide ();
        this->disconnectButton->hide ();
        this->connectButton->show ();
    }

    return true;
}

bool HomeWidget::onSignalStrengthUpdate(int value){
    this->signalStrength->setPixmap (this->signalStrengthImage.at (value));

    return true;
}


bool HomeWidget::onDateRateUpdate(int value){
    this->dataRate->setPixmap (this->dataRates.at (value));

    return true;
}

bool HomeWidget::onRetranslate (){

    this->connectButton->setText (tr ("Connect"));
    this->connectingButton->setText (tr ("Connecting"));
    this->disconnectButton->setText (tr ("Disconnect"));
    this->disconnectingButton->setText (tr ("Disconnecting"));

    this->settingsButton->setText (tr ("Settings"));

    this->downloadSpeed->setText (tr ("0.0 Mbps"));
    this->uploadSpeed->setText (tr ("0.0 Mbps"));
    this->downloadTraffic->setText (tr ("0.0 MB"));
    this->uploadTraffic->setText (tr ("0.0 MB"));

    this->download->setText (tr ("Download"));
    this->upload->setText (tr ("Upload"));
    this->speed->setText (tr ("Speed"));
    this->traffic->setText (tr ("Traffic"));
    this->titleText->setText (tr ("MTC Connect"));

    this->closeButton->setToolTip (tr("Close"));
    this->minimizeButton->setToolTip (tr("Minimize"));

    this->connectButton->setToolTip (tr ("Connect"));
    this->connectingButton->setToolTip (tr ("Connecting"));
    this->disconnectButton->setToolTip (tr ("Disconnect"));
    this->disconnectingButton->setToolTip (tr ("Disconnecting"));
    this->settingsButton->setToolTip (tr ("Settings"));

    return true;
}

bool HomeWidget::onSettingsButtonClicked (){

    emit activateAction ();

    return true;

}

bool HomeWidget::onSpeedUpdate (double uploaded, double downloaded)
{
    this->downloadSpeed->setText (QString::number ((downloaded*8), 'f', 2) + tr(" Kbps"));
    this->uploadSpeed->setText (QString::number ((uploaded*8), 'f', 2) + tr(" Kbps"));

    return (true);
}

bool HomeWidget::onUsageUpdate (
        double uploaded,
        double downloaded)
{
    this->uploaded += (uploaded / (1024));
    this->downloaded += (downloaded / (1024));

    this->downloadTraffic->setText (QString::number (this->downloaded, 'f', 2) + tr(" MB"));
    this->uploadTraffic->setText (QString::number (this->uploaded, 'f', 2) + tr(" MB"));

    return (true);
}
