#include "MainWindow.h"
#include "SerialPort.h"
#include "SerialEnumerator.h"

#include <QApplication>
#include <QDateTime>
#include <QDebug>
#include <QList>
#include <QProcess>
#include <QSettings>

MainWindow::MainWindow(
		QWidget *parent)
	: QMainWindow(parent) {

	qDebug () << "Check the registry";
	if (false == this->checkRegistry ()) {
		qDebug () << "Application not installed, run setup";

		this->runSetup ();

	} else {

		qDebug () << "Check the modem port";
		if (false == this->checkModem ()) {

			qDebug () << "Modem not found";
			this->ejectModem ();

		} 

		this->runApplication ();
	}
}

MainWindow::~MainWindow() {

}

bool MainWindow::checkRegistry () {

	QSettings setting("HKEY_LOCAL_MACHINE\\Software\\Wow6432Node\\MTC", QSettings::NativeFormat);
	this->installDirectory = setting.value ("InstallationDirectory").toString ();
	this->amd = true;

	if (true == this->installDirectory.isEmpty ()) {

		QSettings setting("HKEY_LOCAL_MACHINE\\Software\\MTC", QSettings::NativeFormat);
		this->installDirectory = setting.value ("InstallationDirectory").toString ();
		this->amd = false;
	}

	this->installDirectory.replace ("\\", "/");
	return (false == this->installDirectory.isEmpty ());
}


bool MainWindow::checkModem () {
	QList<PortInformation> ports = SerialEnumerator::getPorts();

	foreach (PortInformation port, ports) {
		if (0x15EB == port.vendorID) {
			if (0x0001 == port.productID) {
				if (port.friendName.contains("VIA Telecom AT Port") || port.friendName.contains("Olive Telecom AT Port")) {
					return true;
				}
			}
		}
	}

	return false;
}

bool MainWindow::runSetup () {
	qDebug () << "Entering MainWindow::runSetup";

	QString exeFileName ("setup.exe");

	int result = (int)::ShellExecuteA(0, "open", exeFileName.toUtf8().constData(), 0, 0, SW_SHOWNORMAL);

	if (SE_ERR_ACCESSDENIED == result) {
		// Requesting elevation
		result = (int)::ShellExecuteA(0, "runas", exeFileName.toUtf8().constData(), 0, 0, SW_SHOWNORMAL);
	}

	if (result <= 32) {
		// error handling
	}

	QProcess::startDetached (exeFileName);

	qDebug () << "Exiting MainWindow::runSetup";

	return true;
}

bool MainWindow::ejectModem () {
	qDebug () << "Entering MainWindow::ejectModem";
	QString drivers = this->installDirectory + "/drivers";
	
	if (true == this->amd) {
		drivers.append("/x64");
	} else {
		drivers.append("/x86");
	}

	drivers.append("/dpinst.exe");
	
	QProcess::startDetached (drivers, QStringList (), this->installDirectory);
	
	QString eject = this->installDirectory + "/drivers/modem.exe";

	QProcess::startDetached (eject, QStringList (), this->installDirectory);

	qDebug () << "Executed Eject" << eject;
	qDebug () << "Entering MainWindow::ejectModem";
	return true;
}

bool MainWindow::runApplication () {

	QProcess::startDetached (this->installDirectory + "/MTC.exe", QStringList (), this->installDirectory);

	return true;
}
