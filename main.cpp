#include <QtGui/QApplication>

#include "Define.h"
#include "MainWindow.h"
#include "SingleApplication.h"

#include <QDir>
#include <QFile>
#include <QMessageBox>
#include <QProcess>
#include <QSplashScreen>
#include <QSystemTrayIcon>
#include <QTextStream>
#include <QTimer>

void myMessageHandler(QtMsgType messageType, const char *message) {
    QString logMessage;

    switch (messageType) {
    case QtDebugMsg: {
            logMessage = QString("Debug: %1").arg(message);
            fprintf(stderr, "Debug: %s\n", message);
        }break;

    case QtWarningMsg: {
            logMessage = QString("Warning: %1").arg(message);
            fprintf(stderr, "Warning: %s\n", message);
        }break;

    case QtCriticalMsg: {
            logMessage = QString("Critical: %1").arg(message);
            fprintf(stderr, "Critical: %s\n", message);
        }break;

    case QtFatalMsg: {
            logMessage = QString("Fatal: %1").arg(message);
            fprintf(stderr, "Fatal: %s\n", message);
            abort();
        }break;
    }

    QFile outFile(QDir::tempPath () + SLASH + LOG_FILE_NAME);
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream textStream(&outFile);
    textStream << logMessage << endl;
}

int main(int argc, char *argv[])
{
    SingleApplication application(argc, argv, "89F11B94-0B73-11E1-93E6-85BA4724019B-961DE3DE-0B73-11E1-AA22-89BA4724019B");

    qInstallMsgHandler(myMessageHandler);

    if (application.isRunning()) {
        application.sendMessage("Message from other instace");
        return (0);
    }

    if (!QSystemTrayIcon::isSystemTrayAvailable()) {
        QMessageBox::critical(0, QObject::tr("System"), QObject::tr("No System Tray on this system."));
        return (1);
    }

    QProcess::startDetached (QApplication::applicationDirPath () + "/drivers/modem.exe", QStringList (), QApplication::applicationDirPath ());

    MainWindow mainWindow;
    mainWindow.setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);
    mainWindow.setWindowIcon(QIcon(APPLICATION_ICON));
    mainWindow.setWindowTitle (APPLICATION_NAME);
    mainWindow.setFixedSize (480, 213);
    mainWindow.setAttribute(Qt::WA_TranslucentBackground);
    QObject::connect (&application, SIGNAL(messageAvailable(QString)), &mainWindow, SLOT(onReceiveMessage(QString)));

    SingleApplication::setQuitOnLastWindowClosed(false);
    QSplashScreen splash (QPixmap (SPLASH_SCREEN));
    splash.show();
    application.processEvents();

    QTimer::singleShot (SPLASH_SCREEN_TIMEOUT,
                       &splash,
                       SLOT(close()));

    QTimer::singleShot (SPLASH_SCREEN_TIMEOUT,
                        &mainWindow,
                        SLOT(show()));


    return application.exec();
}
