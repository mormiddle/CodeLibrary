# TaoLogger


## 使用

源代码拷过去，在main函数的QCoreApplication/QApplication构造之后，调用一下init函数就行了。

例如：
```C++
#include "TaoLogger.h"
//省略其它头文件
...
...
int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   initLog();
   ...
   return app.exec();
}
```

initLog函数的定义如下:
```
void initLog(const QString &logPath = QStringLiteral("Log"), int logMaxCount = 1024, bool async = true);
```
其中logPath为log存储路径，默认为Log文件夹。

logMaxCount最大文件数，默认为1024。

async为异步存储，默认为true。

该log针对的是c++的，在以上操作结束后，想要调用日志输出，使用一下格式

- 调试信息用qDebug
- 常规信息用qInfo
- 警告用qWarning
- 比较严重的问题用qCritical

比如：

```c++
LOG_DEBUG << u8"山有木兮木有枝，心悦君兮君不知。";
```

## 开发环境

* Qt 5.9.x Windows

