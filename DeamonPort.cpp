#include "DeamonPort.h"

#include "SerialEnumerator.h"

#include "At.h"
#include "Define.h"

#include <QDebug>
#include <QTime>

DeamonPort*
DeamonPort::singleton = NULL;

DeamonPort* DeamonPort::getInstance () {
    if (NULL == singleton) {
        singleton = new DeamonPort();
    }
    return (singleton);
}

DeamonPort::DeamonPort(QObject *parent) : QThread(parent), port (NULL), running (true), plugged (false) {
    this->mutex = new QMutex();

    this->writeToAtPort (At::echoOff);
    this->writeToAtPort (At::signalStrength);
    this->writeToAtPort (At::setEvdoOnlyMode);
    this->writeToAtPort (At::pinStatus);

    this->systemInformationTimer = new QTimer(this);
    connect(systemInformationTimer, SIGNAL(timeout()), SLOT(onSystemUpdateTimer()));
    this->systemInformationTimer->start(SIGNAL_STRENGTH_TIMEOUT);
}

bool DeamonPort::onSystemUpdateTimer () {
    this->writeToAtPort(At::signalStrength);
    this->writeToAtPort(At::dataRate);
    return true;
}

void
DeamonPort::run (){
    this->running = true;

    while (true == this->running) {

        if ( true == this->checkPort ()) {

            if ( false == this->openPort ()) {

                continue;
            }

                this->writeToAtPort ();

                this->msleep (THREAD_SLEEP_TIMEOUT);

                this->readFromAtPort ();

            }
            // sleep
            this->msleep (THREAD_SLEEP_TIMEOUT);

    }
}

bool DeamonPort::checkPort () {
    bool result = false;

    QList<PortInformation> ports = SerialEnumerator::getPorts();
    for (int index = 0; index < ports.size(); index++) {
        if (VENDOR_ID == ports.at(index).vendorID) {
            if (PRODUCT_ID == ports.at(index).productID) {

                if (ports.at(index).friendName.contains(AT_PORT_NAME_1) || ports.at(index).friendName.contains(AT_PORT_NAME_2)) {
                    this->portName = ports.at (index).portName;
                    this->portName.remove ("\\\\.\\");

                    result = true;
                    break;
                }
            }
        }
    }

    if (false == result) {
        this->portName = "";
    }

    if (this->plugged != result) {

        this->plugged = result;
        emit modemPlugged (result);
    }

    return result;
}

bool DeamonPort::openPort() {
    bool result = false;

    if (true == this->portName.isEmpty ()) {
        if ( NULL != this->port) {
            delete this->port;
            this->port = NULL;
        }
        result = false;
    } else {
        if ( NULL == this->port) {
            this->port = new SerialPort(portName, SerialPort::Polling);

            if ( true == this->port->open (QIODevice::ReadWrite|QIODevice::Unbuffered) ) {
                qDebug () << "Successfully opened Serial Port";
                this->port->setBaudRate (BAUD115200);
                this->port->setDataBits (DATA_8);
                this->port->setParity (PAR_NONE);
                this->port->setStopBits (STOP_1);
                this->port->setFlowControl (FLOW_HARDWARE);
                this->port->setTimeout (PORT_TIMEOUT);

                result = true;
            } else {
                result = false;
            }
        } else {
            result = true;
        }
    }

    return result;
}

bool DeamonPort::writeToAtPort(QString value){

    this->mutex->lock ();

    this->queue.enqueue (value);

    this->mutex->unlock ();

    return false;
}

bool DeamonPort::writeToAtPort () {
    bool result = false;

    this->mutex->lock();

    if ( false == this->queue.isEmpty ()) {
        QString data = this->queue.dequeue ().append (At::end);

        int written = this->port->write (data.toAscii (), data.length ());
        qDebug() << QTime::currentTime().toString("hh:mm:ss.zzz") << "[" << written << "]"<< "Write to AT port :"<< data;

        this->port->flush ();
        result = true;
    }

    this->mutex->unlock();
    return result;
}

bool DeamonPort::readFromAtPort () {
    int size = this->port->bytesAvailable();

    if (0 == size) return false;

    QByteArray data;
    data.resize (size);

    int read = this->port->read(data.data (), size);
    data.resize (read);

    data.replace ("\0", 1, " ", 1);


    qDebug() << "Read From AT port :"
             << QTime::currentTime().toString("hh:mm:ss.zzz")
             << "[" << read << "]" << data;

    return this->parseResponse (data);

}

bool DeamonPort::parseResponse (QByteArray& data) {
    bool result = false;

    QString value(data);

    value.remove(DORMANT0).remove(DORMANT1);

    QStringList response = value.split("OK", QString::SkipEmptyParts);

    foreach (QString responseItem, response ) {
        qDebug() << "Parsing Item : " << responseItem;

        if (responseItem.contains(At::signalStrengthResponse)){

            responseItem.remove(At::signalStrength).remove(At::signalStrengthResponse).remove(OK_STRING).simplified();
            int rawSignalStrength = responseItem.simplified().toInt ();
            int signalStrength = 0;
            switch (rawSignalStrength) {
            case 0: signalStrength = 0; break;
            case 20: signalStrength = 1; break;
            case 40: signalStrength = 2; break;
            case 60: signalStrength = 3; break;
            case 80: signalStrength = 4; break;
            case 99: signalStrength = 5; break;
            }

            qDebug() << "Signal Strength:" << signalStrength;

            emit signalStrengthUpdate(signalStrength);

        } else if (responseItem.contains (At::dataRateResponse)) {

            responseItem.remove (At::dataRate).remove (At::dataRateResponse).remove (OK_STRING);
            QString speed = responseItem.simplified ().split (COMMA).at (DRC_RESPONSE_LOCATION);
            speed.remove(QUOTE);

            int level = 0;

            if (speed.contains (SPEED_ELEVEN)) {
                level = 11;
            } else if (speed.contains (SPEED_TEN)) {
                level = 10;
            } else if (speed.contains (SPEED_NINE)) {
                level = 9;
            } else if (speed.contains (SPEED_EIGHT)) {
                level = 8;
            } else if (speed.contains (SPEED_SEVEN)) {
                level = 7;
            } else if (speed.contains (SPEED_SIX)) {
                level = 6;
            } else if (speed.contains (SPEED_FIVE)) {
                level = 5;
            } else if (speed.contains (SPEED_FOUR)) {
                level = 4;
            } else if (speed.contains (SPEED_THREE)) {
                level = 3;
            } else if (speed.contains (SPEED_TWO)) {
                level = 2;
            } else if (speed.contains (SPEED_ONE)) {
                level = 1;
            } else if (speed.contains (SPEED_ZERO)) {
                level = 0;
            }

            qDebug() << "Data Rate:" << speed << level;

            emit dataRateUpdate (level);
        } else if (responseItem.contains (At::softwareVersionResponse)) {

            responseItem.remove (At::softwareVersion).remove (At::softwareVersionResponse).remove (OK_STRING);
            qDebug () << "Softare Version:" << responseItem.simplified ();
            emit this->softwareVersionUpdate (responseItem.simplified ());

        } else if (responseItem.contains (At::prlResponse)) {

            responseItem.remove (At::prl).remove (At::prlResponse).remove (OK_STRING);

            qDebug () << "PRL:" << responseItem.simplified ();
            emit this->prlUpdate (responseItem.simplified ());

        } else if (responseItem.contains (At::meidResponse)) {

            responseItem.remove (At::meid).remove (At::meidResponse).remove (OK_STRING);

            qDebug () << "MEID:" << responseItem.simplified ();
            emit this->meidUpdate (responseItem.simplified ());

        } else if (responseItem.contains (At::esnResponse)) {

            responseItem.remove (At::esn).remove (At::esnResponse).remove (OK_STRING);

            QString pEsn = responseItem.simplified ().split (COMMA).at (PESN_RESPONSE_LOCATION);
            qDebug () << "pESN:" << pEsn;
            emit this->esnUpdate (pEsn);

        } else if (responseItem.contains (At::cmeError)) {

            responseItem.remove (At::cmeError);

            QString cError = responseItem.simplified ();
            qDebug () << "cError:" << cError;
            emit this->cmeErrorUpdate (cError);
        }
    }

return result;
}

bool DeamonPort::stop (){
    this->running = false;

    return true;
}
