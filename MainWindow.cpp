#include "MainWindow.h"

#include "DeamonPort.h"
#include "DeamonConnection.h"
#include "DeamonDatabase.h"
#include "DeamonSetting.h"
#include "Define.h"
#include "SettingWidget.h"

#include <QApplication>
#include <QDebug>
#include <QDesktopServices>
#include <QDir>
#include <QMenu>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPainter>
#include <QProcess>

MainWindow::MainWindow
(QWidget *parent)
    : QMainWindow(parent),
      connected(false)
{
    this->setMouseTracking(false);
    this->createSystemTray();

    this->background = new QImage(":/background.png");

    this->translator = new QTranslator(this);
    this->translator->load (LOCALE_PREFIX + DeamonSetting::getInstance ()->getLanguage ());
    qApp->installTranslator (this->translator);

    this->logoButton = new ImageButton("",
                                       ":/logoDefault.png",
                                       ":/logoHover.png",
                                       ":/logoPress.png",
                                       false, this);
    this->logoButton->setGeometry (10, 5, 22, 22);

    this->display = new QStackedWidget (this);
    this->display->setGeometry (0, 0, 480, 213);

    this->home = new HomeWidget(this->display);
    this->setting = new SettingsWidget(this->display);

    this->display->addWidget (this->home);
    this->display->addWidget (this->setting);

    QObject::connect (DeamonConnection::getInstance (), SIGNAL(modemConnected (bool)), SLOT(onModemConnected(bool)));
    QObject::connect (DeamonConnection::getInstance (), SIGNAL(rasError(int, QString)), SLOT(onRasError(int, QString)));
    QObject::connect (this, SIGNAL(retranslate()), SLOT(onRetranslate()));
    QObject::connect (this->setting, SIGNAL(dismissAction ()), this, SLOT (onDismiss ()));
    QObject::connect (this->setting, SIGNAL(languageChange(QString)), this, SLOT(onLanguageChange(QString)));
    QObject::connect (this->home, SIGNAL(activateAction ()), this, SLOT (onActivate ()));

    QObject::connect (this->home, SIGNAL(minimizeAction()), this, SLOT (onMinimizeButtonClicked ()));
    QObject::connect (this->home, SIGNAL(closeAction ()), this, SLOT (onCloseButtonClicked ()));
    QObject::connect (this->setting, SIGNAL(minimizeAction ()), this, SLOT ( onMinimizeButtonClicked()));
    QObject::connect (this->setting, SIGNAL(closeAction ()), this, SLOT (onCloseButtonClicked ()));

    QObject::connect (this, SIGNAL(retranslate()), this->setting, SLOT(onRetranslate()));
    QObject::connect (this, SIGNAL(retranslate()), this->home, SLOT(onRetranslate()));

    QObject::connect (DeamonPort::getInstance (), SIGNAL(cmeErrorUpdate(QString)), SLOT(onCmeErrorUpdate(QString)));

    this->onRetranslate ();

    DeamonPort::getInstance ()->start ();
}

bool
MainWindow::createSystemTray () {

    this->minimizeAction = new QAction(tr("Minimize"), this);
    this->restoreAction = new QAction(tr("Restore"), this);
    this->upgradeAction = new QAction(tr("Upgrade"), this);
    this->quitAction = new QAction(tr("Quit"), this);

    this->trayIconMenu = new QMenu(this);
    this->trayIconMenu->addAction(this->minimizeAction);
    this->trayIconMenu->addAction(this->restoreAction);
    this->trayIconMenu->addSeparator();
    this->trayIconMenu->addAction (this->upgradeAction);
    this->trayIconMenu->addSeparator ();
    this->trayIconMenu->addAction(this->quitAction);

    this->trayIcon = new QSystemTrayIcon(this);
    this->trayIcon->setContextMenu(this->trayIconMenu);
    this->trayIcon->setToolTip(APPLICATION_NAME);
    this->trayIcon->setIcon(QIcon(APPLICATION_ICON));
    this->trayIcon->show();

    QObject::connect (this->minimizeAction,
                      SIGNAL(triggered()),
                      this,
                      SLOT(hide()));

    QObject::connect (this->restoreAction,
                      SIGNAL(triggered()),
                      this,
                      SLOT(showNormal()));

    QObject::connect (this->upgradeAction,
                      SIGNAL(triggered()),
                      this,
                      SLOT(onUpgradeTriggered()));

    QObject::connect (this->quitAction,
                      SIGNAL(triggered()),
                      qApp,
                      SLOT(quit()));

    QObject::connect (this->trayIcon,
                      SIGNAL(activated (QSystemTrayIcon::ActivationReason)),
                      this,
                      SLOT(onSystemTrayActivated(QSystemTrayIcon::ActivationReason)));

    return (true);
}

void MainWindow::setVisible
(bool visible)
{
    this->minimizeAction->setEnabled(visible);
    this->restoreAction->setEnabled(isMaximized() || !visible);

    QMainWindow::setVisible(visible);
}

MainWindow::~MainWindow()
{

}

void
MainWindow::paintEvent
(QPaintEvent* event)
{
    Q_UNUSED (event)

    QPainter painter(this);
    painter.drawImage(QPoint(0,0), *this->background);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    if (this->moving) {
        this->move(event->globalPos() - this->offset);
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        this->moving = true;
        this->offset = event->pos();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        this->moving = false;
    }
}



bool MainWindow::onActivate () {

    this->display->setCurrentIndex (1);

    return (true);
}


bool MainWindow::onDismiss()
{
    this->display->setCurrentIndex (0);

    return true;
}

bool MainWindow::onRasError (int errorNumber, QString errorMessage) {
    switch (errorNumber) {
    case 633: // fall through
    case 678: // fall through
    case 680: // fall through
    case 691: // fall through
    case 692: // fall through
    case 719: // fall through
    case 720: // fall through
    case 738: // fall through
    case 797:{
        QMessageBox::critical (NULL, QString::number (errorNumber), errorMessage, QMessageBox::Ok, QMessageBox::Ok);
    } break;
    }

    return true;
}



bool MainWindow::openWebPage(const QString& url) {
    QDesktopServices::openUrl(QUrl(url));
    return (true);
}

bool MainWindow::onRetranslate (){
    this->minimizeAction->setText (tr("Minimize"));
    this->restoreAction->setText (tr("Restore"));
    this->upgradeAction->setText (tr("Upgrade"));
    this->quitAction->setText (tr("Quit"));

    return true;
}

bool MainWindow::onSystemTrayActivated(QSystemTrayIcon::ActivationReason reason){

    switch (reason) {
    case QSystemTrayIcon::Trigger: { // do nothing
    }break;
    case QSystemTrayIcon::DoubleClick: {
        this->showNormal();
    }break;
    case QSystemTrayIcon::MiddleClick: {// fall through
    }break;
    case QSystemTrayIcon::Unknown: {
    }break;
    case QSystemTrayIcon::Context: {
    }break;
    default:{   // do nothing

    };
    }

    return true;
}

bool MainWindow::onLanguageChange (const QString& language) {
    this->translator->load (LOCALE_PREFIX + language);
    emit this->retranslate();

    return true;
}

bool MainWindow::checkVersion () {

    this->versionRequest = new QHttp (this);
    QObject::connect (this->versionRequest,
                      SIGNAL(requestFinished(int, bool)),
                      this,
                      SLOT(onVersionRequestFinished(int, bool)));

    this->versionData = new QByteArray(128, 0);
    this->versionBuffer = new QBuffer (this->versionData, 0);
    this->versionBuffer->open (QIODevice::ReadWrite|QIODevice::Truncate);

    this->versionRequest->setHost (QUrl(VERSION_URL).host ());
    this->versionRequestIndex = this->versionRequest->get (
                QUrl(VERSION_URL).toEncoded (),
                this->versionBuffer);

    return true;
}

bool
MainWindow::onUpgradeTriggered () {
    this->setupRequest = new QHttp (this);
    QObject::connect (this->setupRequest,
                      SIGNAL(requestFinished(int, bool)),
                      this,
                      SLOT(onSetupRequestFinished(int, bool)));

    this->setupData = new QByteArray(128000, 0);
    this->setupBuffer = new QBuffer (this->setupData, 0);
    this->setupBuffer->open (QIODevice::ReadWrite|QIODevice::Truncate);

    this->setupRequest->setHost (QUrl(SETUP_URL).host ());
    this->setupRequestIndex = this->setupRequest->get (
                QUrl (SETUP_URL).toEncoded (),
                this->setupBuffer);

    return true;
}

bool
MainWindow::onVersionRequestFinished (
        int index, bool failed) {

    if (index != this->versionRequestIndex) {

        return false;
    }

    bool result = false;

    if ( true == failed ) {
        QMessageBox::critical (NULL,
                               NETWORK_ERROR,
                               VERSION_ERROR,
                               QMessageBox::Ok,
                               QMessageBox::Ok);

        result = false;

    } else {
        QString version(*this->versionData);
        QString current(VERSION);

        if (version.toInt () > current.toInt ()) {
            this->trayIcon->showMessage (NEW_VERSION,
                                         VERSION_SUCCESS);
            this->upgradeAction->setEnabled (true);

        } else {
            QMessageBox::information (NULL,
                                      NETWORK_SUCCESS,
                                      VERSION_LATEST,
                                      QMessageBox::Ok,
                                      QMessageBox::Ok);
            result = true;
        }
    }

    this->versionBuffer->close ();

    if (NULL != this->versionBuffer) {
        delete this->versionBuffer;
        this->versionBuffer = NULL;
    }

    if (NULL != this->versionData) {
        delete this->versionData;
        this->versionData = NULL;
    }

    return result;
}

bool
MainWindow::onSetupRequestFinished (
        int index, bool failed) {

    bool result = false;

    if (index != this->setupRequestIndex) {

        return false;
    }

    if ( true == failed ) {
        QMessageBox::critical (NULL,
                               NETWORK_ERROR,
                               SETUP_ERROR,
                               QMessageBox::Ok,
                               QMessageBox::Ok);

        result = false;

    } else {

        QFile setupFile (QDir::tempPath () + "/setup.exe");
        setupFile.open (QIODevice::WriteOnly | QIODevice::Truncate);
        setupFile.write (*this->setupData);
        setupFile.close ();

        if (QMessageBox::Ok == QMessageBox::question (NULL,
                                                      NETWORK_SUCCESS,
                                                      SETUP_SUCCESS,
                                                      QMessageBox::Ok |
                                                      QMessageBox::Cancel,
                                                      QMessageBox::Ok)) {
            QProcess::startDetached (QDir::tempPath ()+"/setup.exe",
                                     QStringList (), QDir::tempPath ());

            result = true;
        }

    }

    this->setupBuffer->close ();

    if (true == result) {
        //this->closeButton->click ();
    }

    return result;
}


bool MainWindow::onMinimizeButtonClicked() {
    this->hide();

    return (true);
}

bool MainWindow::onCloseButtonClicked() {

    this->close ();

    return true;
}

bool MainWindow::close() {

    if (true == this->connected) {

        if ( QMessageBox::Ok ==
             QMessageBox::information (NULL,
                                       "MTC",
                                       tr("Do you want to disconnect connection?"),
                                       QMessageBox::Ok|QMessageBox::Cancel,
                                       QMessageBox::Cancel)) {

            DeamonConnection::getInstance ()->disconnectDataCall ();

        } else {

            return false;
        }
    }

    DeamonDatabase::getInstance ()->closeDatabase ();

    DeamonPort::getInstance ()->stop ();
    DeamonPort::getInstance ()->wait ();

    qApp->quit ();
    return (true);
}


bool
MainWindow::onReceiveMessage
(const QString& message)
{
    Q_UNUSED (message);
    this->showNormal();
    return (true);
}

bool
MainWindow::onModemConnected
(bool status)
{
    this->connected = status;
    return true;
}

void
MainWindow::closeEvent (
        QCloseEvent * event)
{

    if (true == this->close ())
    {

        event->accept ();

    }
    else
    {

        event->ignore ();
    }
}

bool
MainWindow::onCmeErrorUpdate
(QString value)
{

    if(13 == value.toInt () || 10 == value.toInt ()) {

        if( QMessageBox::Ok ==
        QMessageBox::warning (NULL,
                                  tr("MTC Connect"),
                                  tr("RUIM not inserted"),
                                  QMessageBox::Ok, QMessageBox::Ok))
        {
            //qApp->quit ();

        }

    }

    return true;
}
