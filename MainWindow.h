#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>

#include "AnimateButton.h"
#include "ImageButton.h"

#include "HomeWidget.h"
#include "SettingWidget.h"

#include <QBuffer>
#include <QByteArray>
#include <QHttp>
#include <QLabel>
#include <QPixmap>
#include <QStackedWidget>
#include <QSystemTrayIcon>
#include <QTranslator>
#include <QUrl>

class MainWindow
        : public QMainWindow {
    Q_OBJECT

public:
    MainWindow (QWidget *parent = 0);
    ~MainWindow ();

    void setVisible (bool visible);

public slots:
    bool onVersionRequestFinished (int index, bool failed);
    bool onSetupRequestFinished (int index, bool failed);
    bool onUpgradeTriggered();

    bool openWebPage (const QString& url);
    bool onReceiveMessage (const QString& message);

    bool onModemConnected (bool status);
    bool onRasError(int errorNumber, QString errorMessage);

    bool onLanguageChange (const QString& language);
    bool onRetranslate ();
    bool onSystemTrayActivated (QSystemTrayIcon::ActivationReason reason);

    bool onActivate();
    bool onDismiss ();

    bool onMinimizeButtonClicked();
    bool onCloseButtonClicked();

    bool onCmeErrorUpdate(QString value);

signals:
    bool retranslate();

protected:
    void paintEvent(QPaintEvent* event);
    virtual void closeEvent (QCloseEvent* event);

    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

private:
    bool checkVersion ();
    bool createDisplay ();

    bool createSystemTray();

    bool close ();

    QStackedWidget * display;

    HomeWidget * home;
    SettingsWidget * setting;

    ImageButton * logoButton;

    QAction * minimizeAction;
    QAction * restoreAction;
    QAction * safelyRemoveAction;
    QAction * upgradeAction;
    QAction * quitAction;

    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;

    QImage * background;

    QPoint offset;

    QTranslator * translator;

    QHttp * versionRequest;
    QHttp * setupRequest;

    QBuffer * versionBuffer;
    QBuffer * setupBuffer;

    QByteArray * versionData;
    QByteArray * setupData;

    int versionRequestIndex;
    int setupRequestIndex;

    bool moving;
    bool connected;

};

#endif // MAINWINDOW_H
