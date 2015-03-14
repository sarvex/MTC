#ifndef DEFINES_H
#define DEFINES_H

#define SIGNAL_STRENGTH_TIMEOUT 3000
#define THREAD_SLEEP_TIMEOUT 200
#define PORT_TIMEOUT 500

#define MODEM_HARDWARE "V-ME200"
#define MODEM_DEVICE "MTC Connect"
#define MODEM_DIALER_VERSION "Olive 0001"


#define MODEM "USB\\VID_15EB&PID_0001&MI_00"
#define MODEM_REVISION "USB\\VID_15EB&PID_0001&REV_0000&MI_00"

#define OLIVE_MODEM_NAME "VIA Telecom USB Modem"
#define OLIVE_DEVICE_TYPE "RASDT_Modem"

#define VENDOR_ID 0x15EB
#define PRODUCT_ID 0x0001

#define AT_PORT_NAME_1 "VIA Telecom AT Port"
#define AT_PORT_NAME_2 "Olive Telecom AT Port"
#define DIAGNOSTIC_PORT_NAME "VIA Telecom Voice Port"

#define SLASH '/'
#define LOG_FILE_NAME "mtc"
#define LOCALE_PREFIX ":/MTC_"

#define SPLASH_SCREEN_TIMEOUT 3000

#define APPLICATION_NAME "MTC Dialer"
#define DIALER_VERSION "Olive 001"
#define APPLICATION_ICON ":/logo.png"
#define SPLASH_SCREEN ":/splash.png"

#define THEMES_FOLDER_NAME "themes"
#define THEME_XML_FILE_NAME "layout.xml"
#define THEME_IMAGES_DIRECTORY_NAME "images"

#define DOT '.'
#define SLASH '/'
#define COMMA ','
#define QUOTE '\''

#define PESN_RESPONSE_LOCATION 4
#define DRC_RESPONSE_LOCATION 9

#define DIALUP_NUMBER "#777"
#define DIALUP_CONNECTION_NAME "Olive Connection"
#define DEFAULT_USERNAME "mobile"
#define DEFAULT_PASSWORD "internet"
#define DEFAULT_LANGUAGE "ru_RU"

#define DORMANT0 "^DSDORMANT:0"
#define DORMANT1 "^DSDORMANT:1"
#define ERROR_STRING "ERROR"

#define OK_STRING "OK"
#define CANCEL_STRING "Cancel"

#define TIME_FORMAT "hh:mm:ss"

#define LOCK_LENGTH 4

#define SPEED_TEST_PAGE "http://www.speedtest.net/"
#define HOME_PAGE "http://www.mts.com.ua/ukr/main.php"

#define DATABASE_TYPE "QSQLITE"
#define DATABASE_CONNECTION "database"
#define DATABASE_NAME "olive"
#define DATABASE_HOST "OliveHost"
#define DATABASE_USER "OliveUser"
#define DATABASE_PASSWORD "OlivePassword"

#define CREATE_TABLE_PREFERENCE "create table if not exists preferences(setting INTEGER PRIMARY KEY,value varchar(20))"
#define SELECT_PREFERENCES "SELECT * FROM preferences"
#define READ_PREFERENCE "SELECT value FROM preferences WHERE setting = :setting"
#define WRITE_PREFERENCE "UPDATE preferences SET value = :value WHERE setting = :setting"
#define INSERT_PREFERENCE "INSERT INTO preferences(setting, value) VALUES (:setting, :value)"
#define SETTING ":setting"
#define VALUE ":value"

#define USERNAME_SETTING "11"
#define PASSWORD_SETTING "12"
#define NUMBER_SETTING "13"
#define LANGUAGE_SETTING "21"

#define SPEED_ZERO "0"
#define SPEED_ONE "38400"
#define SPEED_TWO "76800"
#define SPEED_THREE "153600"
#define SPEED_FOUR "307200"
#define SPEED_FIVE "614400"
#define SPEED_SIX "921600"
#define SPEED_SEVEN "1228800"
#define SPEED_EIGHT "1536000"
#define SPEED_NINE "1843200"
#define SPEED_TEN "2457600"
#define SPEED_ELEVEN "3072000"

#define VERSION_URL "www.olive.net/vme200/mtc/version"
#define SETUP_URL "www.olive.net/vme200/mtc/setup"

#define VERSION 0001
#define NETWORK_ERROR "Network Error"
#define VERSION_ERROR "Unable to contact Upgrader Server"
#define SETUP_ERROR "Unable to download the latest Setup"
#define NEW_VERSION "New Version"
#define NETWORK_SUCCESS "Network Success"
#define VERSION_SUCCESS "A new version is available, Click Upgrade to download"
#define VERSION_LATEST "You are using the latest version"
#define SETUP_SUCCESS "Latest version downloaded, Do you want to run the setup"

#endif // DEFINES_H
