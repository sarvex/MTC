#ifndef DEAMONDATABASE_H
#define DEAMONDATABASE_H

#include <QObject>
#include <QSqlDatabase>

class DeamonDatabase : public QObject {
    Q_OBJECT
public:
    static DeamonDatabase* getInstance ();

    bool initilize();
    bool closeDatabase();

    bool checkSettings();
    QString readSetting (const QString& setting);
    bool writeSetting (const QString& setting, const QString& value);

signals:

public slots:

protected:

private:
    explicit DeamonDatabase(QObject *parent = 0);
    static DeamonDatabase* singleton;

    QSqlDatabase sqlDatabase;
};

#endif // DEAMONDATABASE_H
