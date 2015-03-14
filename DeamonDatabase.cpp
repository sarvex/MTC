#include "DeamonDatabase.h"

#include "Define.h"

#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>

DeamonDatabase* DeamonDatabase::singleton = NULL;

DeamonDatabase* DeamonDatabase::getInstance () {
	if (NULL == singleton) {
		singleton = new DeamonDatabase();
	}
	return (singleton);
}

DeamonDatabase::DeamonDatabase ( QObject * parent) : QObject(parent) {
	sqlDatabase = QSqlDatabase::addDatabase(DATABASE_TYPE, DATABASE_CONNECTION);

	sqlDatabase.setHostName(DATABASE_HOST);

	sqlDatabase.setDatabaseName(DATABASE_NAME);
	sqlDatabase.setUserName(DATABASE_USER);
	sqlDatabase.setPassword(DATABASE_PASSWORD);


	if (false == sqlDatabase.open()) {
		qDebug() <<" Unable to open sqlDatabase " << sqlDatabase.lastError();
	}

	QSqlQuery sqlQuery (sqlDatabase);

	if (false == (sqlQuery.exec(CREATE_TABLE_PREFERENCE))) {
		qDebug () << "Preference table not created" << sqlQuery.lastError();
	}
}

bool DeamonDatabase::closeDatabase() {

	this->sqlDatabase.commit();
	this->sqlDatabase.close();

	this->sqlDatabase = QSqlDatabase ();
	this->sqlDatabase.removeDatabase (DATABASE_CONNECTION);

	return (true);
}

bool DeamonDatabase::checkSettings(){
	bool result = false;

	QSqlQuery sqlQuery (this->sqlDatabase);

	sqlQuery.exec (SELECT_PREFERENCES);
	result = sqlQuery.first();
	return result;
}

QString DeamonDatabase::readSetting ( const QString& setting) {
	QSqlQuery sqlQuery(this->sqlDatabase);

	sqlQuery.prepare (READ_PREFERENCE);
	sqlQuery.bindValue (SETTING, setting.toInt());

	if (false == sqlQuery.exec() ) {
		return "";
	} else {
		sqlQuery.first();
		return (sqlQuery.value(0).toString());
	}
}

bool DeamonDatabase::writeSetting (const QString& setting, const QString& value) {
	bool result = false;

	QSqlQuery sqlQuery(this->sqlDatabase);

	sqlQuery.prepare(READ_PREFERENCE);
	sqlQuery.bindValue(SETTING, setting.toInt());
	sqlQuery.exec();

	bool existing = sqlQuery.first();
	sqlQuery.clear();

	if ( false == existing ) {
		sqlQuery.prepare(INSERT_PREFERENCE);
	} else {
		sqlQuery.prepare(WRITE_PREFERENCE);
	}

	sqlQuery.bindValue (SETTING, setting.toInt());
	sqlQuery.bindValue (VALUE, value);

	result = sqlQuery.exec ();
	return (result);
}
