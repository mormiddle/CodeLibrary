/***************************************************************
* 文件名称: 程序信息
* 文件功能: 获取程序的各种信息
* 文件说明：获取内容包括名称，版本，路径，数据路径，日志路径等等
***************************************************************/
#include "SlApp.h"
#include "SlLog.h"
#include "SlTime.h"

#include <QCoreApplication>
#include <QDir>

static double m_msAppInit = 0;

static QString m_appCodecName;
static QTextCodec* m_appCodec = NULL;

static QString m_appName;
static QString m_appVersion;
static QString m_appExeFile;

static QString m_appPath;
static QString m_appDataPath;
static QString m_appLogPath;

static QString m_appIniFile;

QString SlApp::getAppCodecName() { return m_appCodecName; }
QTextCodec* SlApp::getAppCodec() { return  m_appCodec; }

QString SlApp::getAppName() { return  m_appName; }
QString SlApp::getAppVersion() { return  m_appVersion; }
QString SlApp::getAppExeFile() { return  m_appExeFile; }

QString SlApp::getAppPath() { return  m_appPath; }
QString SlApp::getAppDataPath() { return m_appDataPath; }
QString SlApp::getAppLogPath() { return  m_appLogPath; }

QString SlApp::getAppIniFile() { return m_appIniFile; }



