#include "DeamonSetting.h"

#include "Define.h"
#include "DeamonDatabase.h"

#include <QDebug>
#include <QSettings>


DeamonSetting::DeamonSetting(QObject * parent) : QObject(parent), number (DIALUP_NUMBER), name (DIALUP_CONNECTION_NAME){

    this->background = new QImage(":/background.png");

    this->username = DeamonDatabase::getInstance ()->readSetting (USERNAME_SETTING);
    this->password = DeamonDatabase::getInstance ()->readSetting (PASSWORD_SETTING);
    this->number = DeamonDatabase::getInstance ()->readSetting (NUMBER_SETTING);
    this->language = DeamonDatabase::getInstance ()->readSetting (LANGUAGE_SETTING);

    if (this->username.isEmpty ()) this->username = DEFAULT_USERNAME;
    if (this->password.isEmpty ()) this->password = DEFAULT_PASSWORD;
    if (this->number.isEmpty ()) this->number = DIALUP_NUMBER;

    qDebug () << "Language saved" << this->language;


    if (this->language.isEmpty ())
    {
        qDebug () << "Language not saved";

        QSettings setting ("HKEY_LOCAL_MACHINE\\Software\\MTC", QSettings::NativeFormat);
        QString language = setting.value ("Preference", "Invalid").toString ();

        if (language.contains ("1033")) {
            this->language = "en_US";
        } else if (language.contains ("1049")) {
            this->language = "ru_RU";
        } else if (language.contains ("1058")) {
            this->language = "uk_UA";
        }
    }

    this->dialerVersion = DIALER_VERSION;
}

DeamonSetting* DeamonSetting::singleton = NULL;

DeamonSetting* DeamonSetting::getInstance () {
    if (NULL == singleton) {
        singleton = new DeamonSetting();
    }
    return (singleton);
}

QString DeamonSetting::getUsername () const {
    return this->username;
}

bool DeamonSetting::setUsername (const QString& username){
    this->username = username;
    DeamonDatabase::getInstance ()->writeSetting (USERNAME_SETTING, username);
    return true;
}

QString DeamonSetting::getPassword () const {
    return this->password;
}

bool DeamonSetting::setPassword (const QString& password){
    this->password = password;
    DeamonDatabase::getInstance ()->writeSetting (PASSWORD_SETTING, password);

    return true;
}

QString DeamonSetting::getNumber() const {
    return this->number;
}

bool DeamonSetting::setNumber (const QString& number){
    this->number = number;
    DeamonDatabase::getInstance ()->writeSetting (NUMBER_SETTING, number);

    return true;
}

QString DeamonSetting::getName() const {
    return this->name;
}

bool DeamonSetting::setName (const QString& name){
    this->name = name;

    return true;
}

QString  DeamonSetting::getLock() const {
    return this->lock;
}

bool  DeamonSetting::setLock(const QString& lock) {
    this->lock = lock;

    return true;
}

QString  DeamonSetting::getDialerVersion() const {
    return this->dialerVersion;
}

bool  DeamonSetting::setDialerVersion (const QString& dialerVersion) {
    this->dialerVersion = dialerVersion;

    return true;
}

QString  DeamonSetting::getLanguage() const {
    return this->language;
}

bool  DeamonSetting::setLanguage (const QString& language) {
    this->language = language;
    this->language = DeamonDatabase::getInstance ()->writeSetting (LANGUAGE_SETTING, language);

    return true;
}
