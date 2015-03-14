#include "At.h"

const QString
At::at("AT");

const QString
At::end("\x0D\x0A");

const QString
At::dial("AT+CDV");

const QString
At::toneDial("AT$VTS=");

const QString
At::echoOff("ATE0");

const QString
At::echoOn("ATE1");

const QString
At::signalStrength("AT^HDRCSQ");

const QString
At::signalStrengthResponse("^HDRCSQ:");

const QString
At::dataRate("AT+EVCSQ1");

const QString
At::dataRateResponse("+EVCSQ1:");

const QString
At::setEvdoOnlyMode("AT^PREFMODE=4");

const QString
At::softwareVersion("AT+CGMR");

const QString
At::softwareVersionResponse("+CGMR:");

const QString
At::prl("AT+PRL");

const QString
At::prlResponse("+PRL:");

const QString
At::meid("AT^MEID");

const QString
At::meidResponse("^MEID:");

const QString
At::esn("AT+VGMUID?");

const QString
At::esnResponse("+VGMUID:");

const QString
At::pinStatus("AT+CPIN?");

const QString
At::cmeError("+CME ERROR:");
