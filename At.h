#ifndef AT_H
#define AT_H

#include <QString>

class At {
public:
    static const QString at;
    static const QString end;
    static const QString dial;
    static const QString toneDial;

    static const QString echoOff;
    static const QString echoOn;

    static const QString signalStrength;
    static const QString signalStrengthResponse;

    static const QString dataRate;
    static const QString dataRateResponse;

    static const QString setEvdoOnlyMode;

    static const QString softwareVersion;
    static const QString softwareVersionResponse;

    static const QString prl;
    static const QString prlResponse;

    static const QString meid;
    static const QString meidResponse;

    static const QString esn;
    static const QString esnResponse;

    static const QString pinStatus;
    static const QString cmeError;
};

#endif // AT_H
