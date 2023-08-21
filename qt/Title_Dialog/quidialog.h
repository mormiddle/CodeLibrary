#ifndef QUIDIALOG_H
#define QUIDIALOG_H

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QLayout>
#include <QToolButton>
#include <QtWidgets>

class QuiDialog : public QDialog
{
    Q_OBJECT


public:
    enum Widget {
        Lab_Ico = 0,                //左上角图标
        BtnMenu = 1,                //下拉菜单按钮
        BtnMenu_Min = 2,            //最小化按钮
        BtnMenu_Max = 3,            //最大化按钮
        BtnMenu_Normal = 4,         //还原按钮
        BtnMenu_Close = 5           //关闭按钮
    };



public:
    //桌面宽度高度
    static int deskWidth();
    static int deskHeight();

    //设置全局样式
    static void setStyle();

    //设置窗体居中显示
    static void setFormInCenter(QWidget *frm);

public:
    explicit QuiDialog(QWidget *parent = 0);
    ~QuiDialog();

protected:
    bool eventFilter(QObject *obj, QEvent *evt);

private:
    QVBoxLayout *verticalLayout1;
    QWidget *widgetMain;
    QVBoxLayout *verticalLayout2;
    QWidget *widgetTitle;
    QHBoxLayout *horizontalLayout4;
    QLabel *labIco;
    QLabel *labTitle;
    QWidget *widgetMenu;
    QHBoxLayout *horizontalLayout;
//    QToolButton *btnMenu;
    QPushButton *btnMenu_Min;
    QPushButton *btnMenu_Max;
    QPushButton *btnMenu_Close;
    QWidget *widget;
    QVBoxLayout *verticalLayout3;

private:
    bool max;                       //是否处于最大化状态
    QRect location;                 //鼠标移动窗体后的坐标位置

    QString title;                  //标题
    Qt::Alignment alignment;        //标题文本对齐
    bool minHide;                   //最小化隐藏
    QWidget *mainWidget;            //主窗体对象

public:
    QLabel *getLabIco()             const;
    QLabel *getLabTitle()           const;
    QToolButton *getBtnMenu()       const;
    QPushButton *getBtnMenuMin()    const;
    QPushButton *getBtnMenuMax()    const;
    QPushButton *getBtnMenuMClose() const;

//    Style getStyle()                const;
    QString getTitle()              const;
    Qt::Alignment getAlignment()    const;

    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;

private slots:
    void initControl();             //初始化控件
    void initForm();                //初始化窗体

private slots:
    void on_btnMenu_Min_clicked();
    void on_btnMenu_Max_clicked();
    void on_btnMenu_Close_clicked();

public Q_SLOTS:
    //设置部件图标
    void setIcon(QuiDialog::Widget widget, QChar str, quint32 size = 9);
    void setIconMain(QChar str, quint32 size = 9);
    //设置部件图片
    void setPixmap(QuiDialog::Widget widget, const QString &file, const QSize &size = QSize(16, 16));
    //设置部件是否可见
    void setVisible(QuiDialog::Widget widget, bool visible = true);
    //设置只有关闭按钮
    void setOnlyCloseBtn();

    //设置标题栏高度
    void setTitleHeight(int height);
    //设置按钮统一宽度
    void setBtnWidth(int width);

    //设置标题及文本样式
    void setTitle(const QString &title);
    void setAlignment(Qt::Alignment alignment);

    //设置最小化隐藏
    void setMinHide(bool minHide);

    //设置主窗体
    void setMainWidget(QWidget *mainWidget);

Q_SIGNALS:
    void closing();
};

//图形字体处理类
class IconHelper : public QObject
{
    Q_OBJECT

public:
    explicit IconHelper(QObject *parent = 0);
    static IconHelper *Instance()
    {
        static QMutex mutex;

        if (!self) {
            QMutexLocker locker(&mutex);

            if (!self) {
                self = new IconHelper;
            }
        }

        return self;
    }

    void setIcon(QLabel *lab, QChar c, quint32 size = 9);
    void setIcon(QAbstractButton *btn, QChar c, quint32 size = 9);
    QPixmap getPixmap(const QString &color, QChar c, quint32 size = 9,
                      quint32 pixWidth = 10, quint32 pixHeight = 10);

    //根据按钮获取该按钮对应的图标
    QPixmap getPixmap(QToolButton *btn, bool normal);


protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    static IconHelper *self;    //对象自身
    QFont iconFont;             //图形字体
    QList<QToolButton *> btns;  //按钮队列
    QList<QPixmap> pixNormal;   //正常图片队列
    QList<QPixmap> pixDark;     //加深图片队列
};

//全局变量控制
class QUIConfig
{
public:
    //全局图标
    static QChar IconMain;          //标题栏左上角图标
    static QChar IconMenu;          //下拉菜单图标
    static QChar IconMin;           //最小化图标
    static QChar IconMax;           //最大化图标
    static QChar IconNormal;        //还原图标
    static QChar IconClose;         //关闭图标

    static QString FontName;        //全局字体名称
    static int FontSize;            //全局字体大小
    static QString ConfigFile;      //配置文件文件路径及名称

    //样式表颜色值
    static QString TextColor;       //文字颜色
    static QString PanelColor;      //面板颜色
    static QString BorderColor;     //边框颜色
    static QString NormalColorStart;//正常状态开始颜色
    static QString NormalColorEnd;  //正常状态结束颜色
    static QString DarkColorStart;  //加深状态开始颜色
    static QString DarkColorEnd;    //加深状态结束颜色
    static QString HighColor;       //高亮颜色

    static void ReadConfig();       //读取配置文件,在main函数最开始加载程序载入
    static void WriteConfig();      //写入配置文件,在更改配置文件程序关闭时调用
    static void NewConfig();        //以初始值新建配置文件
    static bool CheckConfig();      //校验配置文件
};

#endif // QUIDIALOG_H
