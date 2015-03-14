#ifndef DEAMONSETTING_H
#define DEAMONSETTING_H

#include <QObject>
#include <QString>
#include <QImage>




class DeamonSetting : public QObject {
    Q_OBJECT
public:
    static DeamonSetting* getInstance ();

    QString getUsername () const;
    bool setUsername (const QString& username);

    QString getPassword () const;
    bool setPassword (const QString& password);

    QString getNumber() const;
    bool setNumber (const QString& number);

    QString getName() const;
    bool setName (const QString& name);

    QString getLock() const;
    bool setLock (const QString& lock);

    QString getLanguage() const;
    bool setLanguage (const QString& language);

    QString getDialerVersion () const;
    bool setDialerVersion (const QString& dialerVersion);

signals:

public slots:

protected:

private:
    explicit DeamonSetting(QObject *parent = 0);
    static DeamonSetting* singleton;

    QString language;

    QString username;
    QString password;

    QString uploadTraffic;
    QString downloadTraffic;

    QString number;
    QString name;

    QString lock;

    QString dialerVersion;

    QString Language;

    QImage * background;

};

#endif // DEAMONSETTING_H
