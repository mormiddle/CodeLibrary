#include "SlLog.h"
#include "SlApp.h"
#include "SlTime.h"
#include "SlStr.h"
#include "SlIni.h"

#include <QMutex>
#include <QDir>
#include <QTextStream>
#include <QThread>

static QtMessageHandler m_prevMessageHandler = NULL;

/***************************************************************
* 函数名称:
* 函数功能: 将给定文件名、行号和函数名转换为一条格式化的代码信息字符串
* 参　  数: 无
* 返 回 值: 无
***************************************************************/
QString getCodeInfo( const QString& file, int line, const QString& funcIn )
{
    QString func = funcIn;
    if( int n = func.lastIndexOf( "(") )
    {
        func = func.left( n );
        if( int n = func.lastIndexOf( " " ) )
        {
            func = func.mid( n + 1 );
        }
    }

    if( file.indexOf( ":/" ) > 0 )
    {
        return QString( "%1 (%2:%3)" ).arg( func ).arg( line );
    }

    return QString( "%1 (file:/%2:%3)" ).arg( func ).arg( line );
}

void outputMessage( QtMsgType msgType, const QMessageLogContext& context, const QString& msgIn )
{
    static QMutex mutex;
    mutex.lock();

    QDateTime dt = QDateTime::currentDateTime();
    QString message;
    {
        QString type;
        switch ( msgType )
        {
        case QtInfoMsg:     type = "[info ]"; break;  // info
        case QtDebugMsg:	type = "[debug]"; break;  // debug
        case QtWarningMsg:	type = "[warn ]"; break;  // warning
        case QtCriticalMsg:	type = "[error]"; break;  // critical
        case QtFatalMsg:	type = "[fatal]"; break;  // fatal
        }

        static bool m_bLogCodeInfo = false;
        {
            static int sec = -1;
            int n = dt.time().second();
            if( sec != n)
            {
                sec = n;

                SlIni ini;
                m_bLogCodeInfo = ( ini.getInt( "Log", "bLogCodeInfo" ) == 1 );
            }
        }
        bool bLogCodeInfo = m_bLogCodeInfo;

        QString codeInfo;
        if( bLogCodeInfo && context.line > 0 )
        {
            codeInfo = getCodeInfo( context.file, context.line, context.function );
        }

        bool bDefaultCategory = ( context.category == NULL || QString( context.category ) == "default" );

        QString msg;
        if( msgIn.left( 8 ) == "[trace]" )
        {
            type = "[trace]";
            msg = msgIn.mid(8).trimmed();

            bLogCodeInfo = true;
        }
        else if ( int n = ( codeInfo.isEmpty() ? 0 : 1 + msgIn.indexOf( codeInfo ) ) )
        {
            // call console.trace() in qml          [debug] onClicked (qrc:/qml/top/topmain.qml:26)
            // call console.exception() in qml      [error] msg\r\nonClicked (qrc:/qml/top/topmain.qml:34)
            if ( type == "[debug]" )
            {
                type = "[trace]";
            }
            if ( bDefaultCategory )
            {
                type.append( " qml:" );
            }

            if ( --n )
            {
                if ( n > 0 && msgIn.mid( n - 1, 1 ) == "\n" )
                {
                    n--;
                }
                if ( n )
                {
                    msg = msgIn.left( n );
                }
            }

            bLogCodeInfo = true;
        }
        else
        {
            msg = msgIn;
        }

        message = QString( "%1 (0x%2) %3" ).arg( dt.toString( "hh:mm:ss.zzz" ) )
            .arg( ( __int64 ) QThread::currentThreadId(), 4, 16, QChar( '0' ) ).arg( type );

        if ( !bDefaultCategory )
        {
            message.append( QString( " %1:" ).arg( context.category ) );
        }

        if ( bLogCodeInfo && !codeInfo.isEmpty() )
        {
            message.append( ( codeInfo.left( 1 ) == " " ? " -" : " " ) + codeInfo );
        }

        if ( !msg.isEmpty() )
        {
            message.append( " " + msg );
        }
    }

    // output to file
    {
        static QDate date;
        static QString logFile;
        if ( date != dt.date() )
        {
            date = dt.date();

            logFile = QString( "%1/%2_%3" ).arg( SlApp::getAppLogPath() )
                .arg( SlApp::getAppName() ).arg( date.toString( "yyyyMMdd.log" ) );
        }

        QFile* pFile = new QFile( logFile );
        pFile->open( QIODevice::WriteOnly | QIODevice::Append );
        QTextStream text_stream( pFile );
        text_stream << message << "\r\n";
        pFile->flush();
        pFile->close();
    }

    // output to ide
    m_prevMessageHandler( msgType, QMessageLogContext(), message );

    mutex.unlock();

}
