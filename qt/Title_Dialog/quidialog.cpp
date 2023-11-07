#include "quidialog.h"

//初始化控件(布局)
void QuiDialog::initControl()
{
    this->setObjectName(QString::fromUtf8("QuiDialog"));;
    this->resize(900, 750);

    verticalLayout1 = new QVBoxLayout(this);
    verticalLayout1->setSpacing(0);
    verticalLayout1->setObjectName(QString::fromUtf8("verticalLayout1"));
    verticalLayout1->setContentsMargins(1, 1, 1, 1);//设置控件上下左右的间隔
    widgetMain = new QWidget(this);
    widgetMain->setObjectName(QString::fromUtf8("widgetMain"));
    widgetMain->setStyleSheet(QString::fromUtf8(""));

    verticalLayout2 = new QVBoxLayout(widgetMain);
    verticalLayout2->setSpacing(0);
    verticalLayout2->setObjectName(QString::fromUtf8("verticalLayout2"));
    verticalLayout2->setContentsMargins(0, 0, 0, 0);
    widgetTitle = new QWidget(widgetMain);
    widgetTitle->setObjectName(QString::fromUtf8("widgetTitle"));
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(widgetTitle->sizePolicy().hasHeightForWidth());
    widgetTitle->setSizePolicy(sizePolicy);
    widgetTitle->setMinimumSize(QSize(0, 30));

    //标题图标
    horizontalLayout4 = new QHBoxLayout(widgetTitle);
    horizontalLayout4->setSpacing(0);
    horizontalLayout4->setObjectName(QString::fromUtf8("horizontalLayout4"));
    horizontalLayout4->setContentsMargins(10, 0, 0, 0); //修改标题控件的间隔
    labIco = new QLabel(widgetTitle);
    labIco->setObjectName(QString::fromUtf8("labIco"));
    QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(labIco->sizePolicy().hasHeightForWidth());
    labIco->setSizePolicy(sizePolicy1);
    labIco->setMinimumSize(QSize(30, 0));
    labIco->setAlignment(Qt::AlignCenter);
    horizontalLayout4->addWidget(labIco);

    //标题栏
    labTitle = new QLabel(widgetTitle);
    labTitle->setObjectName(QString::fromUtf8("labTitle"));
    QFont font;
    font.setPixelSize(20);
    labTitle->setFont(font);
    QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(labTitle->sizePolicy().hasHeightForWidth());
    labTitle->setSizePolicy(sizePolicy2);
    labTitle->setAlignment(Qt::AlignLeading | Qt::AlignLeft | Qt::AlignVCenter);
    horizontalLayout4->addWidget(labTitle);

    //标题菜单(不启用)
    widgetMenu = new QWidget(widgetTitle);
    widgetMenu->setObjectName(QString::fromUtf8("widgetMenu"));
    sizePolicy1.setHeightForWidth(widgetMenu->sizePolicy().hasHeightForWidth());
    widgetMenu->setSizePolicy(sizePolicy1);
    horizontalLayout = new QHBoxLayout(widgetMenu);
    horizontalLayout->setSpacing(0);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    horizontalLayout->setContentsMargins(0, 0, 0, 0);
//    btnMenu = new QToolButton(widgetMenu);
//    btnMenu->setObjectName(QString::fromUtf8("btnMenu"));
    QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
    sizePolicy3.setHorizontalStretch(0);
    sizePolicy3.setVerticalStretch(0);
//    sizePolicy3.setHeightForWidth(btnMenu->sizePolicy().hasHeightForWidth());
//    btnMenu->setSizePolicy(sizePolicy3);
//    btnMenu->setMinimumSize(QSize(30, 0));
//    btnMenu->setMaximumSize(QSize(30, 16777215));
//    btnMenu->setFocusPolicy(Qt::NoFocus);
//    btnMenu->setPopupMode(QToolButton::InstantPopup);

//    horizontalLayout->addWidget(btnMenu);

    btnMenu_Min = new QPushButton(widgetMenu);
    btnMenu_Min->setObjectName(QString::fromUtf8("btnMenu_Min"));
    QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Expanding);
    sizePolicy4.setHorizontalStretch(0);
    sizePolicy4.setVerticalStretch(0);
    sizePolicy4.setHeightForWidth(btnMenu_Min->sizePolicy().hasHeightForWidth());
    btnMenu_Min->setSizePolicy(sizePolicy4);
    btnMenu_Min->setMinimumSize(QSize(30, 0));
    btnMenu_Min->setMaximumSize(QSize(30, 16777215));
    btnMenu_Min->setCursor(QCursor(Qt::ArrowCursor));
    btnMenu_Min->setFocusPolicy(Qt::NoFocus);
    horizontalLayout->addWidget(btnMenu_Min);

    btnMenu_Max = new QPushButton(widgetMenu);
    btnMenu_Max->setObjectName(QString::fromUtf8("btnMenu_Max"));
    sizePolicy3.setHeightForWidth(btnMenu_Max->sizePolicy().hasHeightForWidth());
    btnMenu_Max->setSizePolicy(sizePolicy3);
    btnMenu_Max->setMinimumSize(QSize(30, 0));
    btnMenu_Max->setMaximumSize(QSize(30, 16777215));
    btnMenu_Max->setCursor(QCursor(Qt::ArrowCursor));
    btnMenu_Max->setFocusPolicy(Qt::NoFocus);
    horizontalLayout->addWidget(btnMenu_Max);

    btnMenu_Close = new QPushButton(widgetMenu);
    btnMenu_Close->setObjectName(QString::fromUtf8("btnMenu_Close"));
    sizePolicy3.setHeightForWidth(btnMenu_Close->sizePolicy().hasHeightForWidth());
    btnMenu_Close->setSizePolicy(sizePolicy3);
    btnMenu_Close->setMinimumSize(QSize(30, 0));
    btnMenu_Close->setMaximumSize(QSize(30, 16777215));
    btnMenu_Close->setCursor(QCursor(Qt::ArrowCursor));
    btnMenu_Close->setFocusPolicy(Qt::NoFocus);
    horizontalLayout->addWidget(btnMenu_Close);

    horizontalLayout4->addWidget(widgetMenu);
    verticalLayout2->addWidget(widgetTitle);

    widget = new QWidget(widgetMain);
    widget->setObjectName(QString::fromUtf8("widget"));
    verticalLayout3 = new QVBoxLayout(widget);
    verticalLayout3->setSpacing(0);
    verticalLayout3->setObjectName(QString::fromUtf8("verticalLayout3"));
    verticalLayout3->setContentsMargins(0, 0, 0, 0);

    verticalLayout2->addWidget(widget);
    verticalLayout1->addWidget(widgetMain);

    connect(this->btnMenu_Min, SIGNAL(clicked(bool)), this, SLOT(on_btnMenu_Min_clicked()));
    connect(this->btnMenu_Max, SIGNAL(clicked(bool)), this, SLOT(on_btnMenu_Max_clicked()));
    connect(this->btnMenu_Close, SIGNAL(clicked(bool)), this, SLOT(on_btnMenu_Close_clicked()));
}

void QuiDialog::initForm()
{
    setIcon(QuiDialog::Lab_Ico, QUIConfig::IconMain, 11);
//    setIcon(QuiDialog::BtnMenu, QUIConfig::IconMenu);
    setIcon(QuiDialog::BtnMenu_Min, QUIConfig::IconMin, 15);
    setIcon(QuiDialog::BtnMenu_Normal, QUIConfig::IconNormal, 15);
    setIcon(QuiDialog::BtnMenu_Close, QUIConfig::IconClose, 15);

    this->max = false;
    this->location = this->geometry();
    this->setProperty("from", true);
    this->widgetTitle->setProperty("form", "title");
    this->setWindowFlags((Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint));

    //设置标题及对齐方式
    title = "全聚焦相控阵控制软件";
    alignment = Qt::AlignLeft | Qt::AlignVCenter;
    minHide = false;
    mainWidget = 0;

    setVisible(QuiDialog::BtnMenu, false);

    //绑定事件过滤器监听鼠标移动
    this->installEventFilter(this);
    this->widgetTitle->installEventFilter(this);

    //设置黑色皮肤
    QString qssFile = ":/res/black.css";
    qssFile = ":/res/black.css";
    setStyle();
}


int QuiDialog::deskWidth()
{
    return qApp->desktop()->availableGeometry().width();
}

int QuiDialog::deskHeight()
{
    return qApp->desktop()->availableGeometry().height();
}

void QuiDialog::setStyle()
{
    //添加css配置文件，设置主题颜色
    QString qssFile = ":/res/black.css";

    QFile file(qssFile);

    if (file.open(QFile::ReadOnly)) {
        QString qss = QLatin1String(file.readAll());
        QString paletteColor = qss.mid(20, 7);
        qApp->setPalette(QPalette(QColor(paletteColor)));
        qApp->setStyleSheet(qss);
        file.close();
    }
}


void QuiDialog::setFormInCenter(QWidget *frm)
{
    //设置窗口居中
    int frmX = frm->width();
    int frmY = frm->height();
    QDesktopWidget w;
    int deskWidth = w.availableGeometry().width();
    int deskHeight = w.availableGeometry().height();
    QPoint movePoint(deskWidth / 2 - frmX / 2, deskHeight / 2 - frmY / 2);
    frm->move(movePoint);
}


QuiDialog::QuiDialog(QWidget *parent)
{
    this->initControl();
    this->initForm();
}

QuiDialog::~QuiDialog()
{
    delete widgetMain;
}

bool QuiDialog::eventFilter(QObject *obj, QEvent *evt)
{
    //设置鼠标事件，双击最大化，长按移动窗口
    static QPoint mousePoint;
    static bool mousePressed = false;

    QMouseEvent *event = static_cast<QMouseEvent *>(evt);
    if (event->type() == QEvent::MouseButtonPress) {
        if (event->button() == Qt::LeftButton) {
            mousePressed = true;
            mousePoint = event->globalPos() - this->pos();
            return true;
        }
    } else if (event->type() == QEvent::MouseButtonRelease) {
        mousePressed = false;
        return true;
    } else if (event->type() == QEvent::MouseMove) {
        if (!max && mousePressed && (event->buttons() && Qt::LeftButton)) {
            this->move(event->globalPos() - mousePoint);
            return true;
        }
    } else if (event->type() == QEvent::MouseButtonDblClick) {
        //以下写法可以将双击识别限定在标题栏
        //if (this->btnMenu_Max->isVisible() && obj == this->widgetTitle) {
        if (this->btnMenu_Max->isVisible()) {
            this->on_btnMenu_Max_clicked();
            return true;
        }
    }

    return QWidget::eventFilter(obj, evt);
}

QLabel *QuiDialog::getLabIco() const
{
    return this->labIco;
}

QLabel *QuiDialog::getLabTitle() const
{
    return this->labTitle;
}

//QToolButton *QuiDialog::getBtnMenu() const
//{
//    return this->btnMenu;
//}

QPushButton *QuiDialog::getBtnMenuMin() const
{
    return this->btnMenu_Min;
}

QPushButton *QuiDialog::getBtnMenuMax() const
{
    return this->btnMenu_Max;
}

QPushButton *QuiDialog::getBtnMenuMClose() const
{
    return this->btnMenu_Close;
}

QString QuiDialog::getTitle() const
{
    return this->title;
}

Qt::Alignment QuiDialog::getAlignment() const
{
    return this->alignment;
}

QSize QuiDialog::sizeHint() const
{
    return QSize(600, 450);
}

QSize QuiDialog::minimumSizeHint() const
{
    return QSize(200, 150);
}


void QuiDialog::on_btnMenu_Min_clicked()
{
    if (minHide) {
        hide();
    } else {
        showMinimized();
    }
}

void QuiDialog::on_btnMenu_Max_clicked()
{
    if (max) {
        this->setGeometry(location);
        setIcon(QuiDialog::BtnMenu_Normal, QUIConfig::IconNormal);
    } else {
        location = this->geometry();
        this->setGeometry(qApp->desktop()->availableGeometry());
        setIcon(QuiDialog::BtnMenu_Max, QUIConfig::IconMax);
    }

    max = !max;
}

void QuiDialog::on_btnMenu_Close_clicked()
{
    emit closing();
    exit(0);
}

void QuiDialog::setIcon(QuiDialog::Widget widget, QChar str, quint32 size)
{
    if (widget == QuiDialog::Lab_Ico) {
//        setIconMain(str, size);
        QString file = ":/res/Jy.png";
        setPixmap(QuiDialog::Lab_Ico, file, QSize(35, 35));
    }
//    else if (widget == QuiDialog::BtnMenu) {
//        QUIConfig::IconMenu = str;
//        IconHelper::Instance()->setIcon(this->btnMenu, str, size);
//    }
    else if (widget == QuiDialog::BtnMenu_Min) {
        QUIConfig::IconMin = str;
        IconHelper::Instance()->setIcon(this->btnMenu_Min, str, size);
    } else if (widget == QuiDialog::BtnMenu_Max) {
        QUIConfig::IconMax = str;
        IconHelper::Instance()->setIcon(this->btnMenu_Max, str, size);
    } else if (widget == QuiDialog::BtnMenu_Normal) {
        QUIConfig::IconNormal = str;
        IconHelper::Instance()->setIcon(this->btnMenu_Max, str, size);
    } else if (widget == QuiDialog::BtnMenu_Close) {
        QUIConfig::IconClose = str;
        IconHelper::Instance()->setIcon(this->btnMenu_Close, str, size);
    }
}

void QuiDialog::setIconMain(QChar str, quint32 size)
{
    QUIConfig::IconMain = str;
    IconHelper::Instance()->setIcon(this->labIco, str, size);
}

void QuiDialog::setPixmap(QuiDialog::Widget widget, const QString &file, const QSize &size)
{
    QPixmap pix = QPixmap(file);
    //按照宽高比自动缩放
    pix = pix.scaled(size, Qt::KeepAspectRatio);

    if (widget == QuiDialog::Lab_Ico) {
        this->labIco->setPixmap(pix);
    }
//    else if (widget == QuiDialog::BtnMenu) {
//        this->btnMenu->setIcon(QIcon(file));
//    }
    else if (widget == QuiDialog::BtnMenu_Min) {
        this->btnMenu_Min->setIcon(QIcon(file));
    } else if (widget == QuiDialog::BtnMenu_Max) {
        this->btnMenu_Max->setIcon(QIcon(file));
    } else if (widget == QuiDialog::BtnMenu_Close) {
        this->btnMenu_Close->setIcon(QIcon(file));
    }
}

void QuiDialog::setVisible(QuiDialog::Widget widget, bool visible)
{
    if (widget == QuiDialog::Lab_Ico) {
        this->labIco->setVisible(visible);
    }
//    else if (widget == QuiDialog::BtnMenu) {
//        this->btnMenu->setVisible(visible);
//    }
    else if (widget == QuiDialog::BtnMenu_Min) {
        this->btnMenu_Min->setVisible(visible);
    } else if (widget == QuiDialog::BtnMenu_Max) {
        this->btnMenu_Max->setVisible(visible);
    } else if (widget == QuiDialog::BtnMenu_Close) {
        this->btnMenu_Close->setVisible(visible);
    }
}

void QuiDialog::setOnlyCloseBtn()
{
//    this->btnMenu->setVisible(false);
    this->btnMenu_Min->setVisible(false);
    this->btnMenu_Max->setVisible(false);
}

void QuiDialog::setTitleHeight(int height)
{
    this->widgetTitle->setFixedHeight(height);
}

void QuiDialog::setBtnWidth(int width)
{
    this->labIco->setFixedWidth(width);
//    this->btnMenu->setFixedWidth(width);
    this->btnMenu_Min->setFixedWidth(width);
    this->btnMenu_Max->setFixedWidth(width);
    this->btnMenu_Close->setFixedWidth(width);
}

void QuiDialog::setTitle(const QString &title)
{
    if (this->title != title) {
        this->title = title;
        this->labTitle->setText(title);
        this->setWindowTitle(this->labTitle->text());
    }
}

void QuiDialog::setAlignment(Qt::Alignment alignment)
{
    if (this->alignment != alignment) {
        this->alignment = alignment;
        this->labTitle->setAlignment(alignment);
    }
}

void QuiDialog::setMinHide(bool minHide)
{
    if (this->minHide != minHide) {
        this->minHide = minHide;
    }
}

void QuiDialog::setMainWidget(QWidget *mainWidget)
{
    //一个QUI窗体对象只能设置一个主窗体
    if (this->mainWidget == 0) {
        //将子窗体添加到布局
        this->widget->layout()->addWidget(mainWidget);
        //自动设置大小
        resize(mainWidget->width(), mainWidget->height() + this->widgetTitle->height());
        qDebug() << " mainWidget->height()" <<  mainWidget->height();
        this->mainWidget = mainWidget;
    }
}




IconHelper *IconHelper::self = 0;
IconHelper::IconHelper(QObject *parent) : QObject(qApp)
{
    int fontId = QFontDatabase::addApplicationFont(":/res/fontawesome-webfont.ttf");
    QStringList fontName = QFontDatabase::applicationFontFamilies(fontId);

    if (fontName.count() > 0) {
        iconFont = QFont(fontName.at(0));
    } else {
        qDebug() << "load fontawesome-webfont.ttf error";
    }
}

void IconHelper::setIcon(QLabel *lab, QChar c, quint32 size)
{
    iconFont.setPointSize(size);
    lab->setFont(iconFont);
    lab->setText(c);
}

void IconHelper::setIcon(QAbstractButton *btn, QChar c, quint32 size)
{
    iconFont.setPointSize(size);
    btn->setFont(iconFont);
    btn->setText(c);
}

QPixmap IconHelper::getPixmap(const QString &color, QChar c, quint32 size,
                              quint32 pixWidth, quint32 pixHeight)
{
    QPixmap pix(pixWidth, pixHeight);
    pix.fill(Qt::transparent);

    QPainter painter;
    painter.begin(&pix);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.setPen(QColor(color));
    painter.setBrush(QColor(color));

    iconFont.setPointSize(size);
    painter.setFont(iconFont);
    painter.drawText(pix.rect(), Qt::AlignCenter, c);
    painter.end();

    return pix;
}

QPixmap IconHelper::getPixmap(QToolButton *btn, bool normal)
{
    QPixmap pix;
    int index = btns.indexOf(btn);

    if (index >= 0) {
        if (normal) {
            pix = pixNormal.at(index);
        } else {
            pix = pixDark.at(index);
        }
    }

    return pix;
}


bool IconHelper::eventFilter(QObject *watched, QEvent *event)
{
    if (watched->inherits("QToolButton")) {
        QToolButton *btn = (QToolButton *)watched;
        int index = btns.indexOf(btn);
        if (index >= 0) {
            if (event->type() == QEvent::Enter) {
                btn->setIcon(QIcon(pixDark.at(index)));
            } else if (event->type() == QEvent::Leave) {
                if (btn->isChecked()) {
                    btn->setIcon(QIcon(pixDark.at(index)));
                } else {
                    btn->setIcon(QIcon(pixNormal.at(index)));
                }
            }
        }
    }

    return QObject::eventFilter(watched, event);
}

QChar QUIConfig::IconMain = QChar();
//QChar QUIConfig::IconMain = QChar(0xf072);
//QChar QUIConfig::IconMenu = QChar(0xf0d7);
QChar QUIConfig::IconMin = QChar(0xf068);
QChar QUIConfig::IconMax = QChar(0xf2d2);
QChar QUIConfig::IconNormal = QChar(0xf2d0);
QChar QUIConfig::IconClose = QChar(0xf00d);

#ifdef __arm__
QString QUIConfig::FontName = "Droid Sans Fallback";
int QUIConfig::FontSize = 13;
#else
QString QUIConfig::FontName = "Microsoft Yahei";
int QUIConfig::FontSize = 9;
#endif

QString QUIConfig::ConfigFile = "config.ini";
QString QUIConfig::TextColor = "#F0F0F0";
QString QUIConfig::PanelColor = "#F0F0F0";
QString QUIConfig::BorderColor = "#F0F0F0";
QString QUIConfig::NormalColorStart = "#F0F0F0";
QString QUIConfig::NormalColorEnd = "#F0F0F0";
QString QUIConfig::DarkColorStart = "#F0F0F0";
QString QUIConfig::DarkColorEnd = "#F0F0F0";
QString QUIConfig::HighColor = "#F0F0F0";

void QUIConfig::ReadConfig()
{
    if (!CheckConfig()) {
        return;
    }

    QSettings set(QUIConfig::ConfigFile, QSettings::IniFormat);

    set.beginGroup("BaseConfig");
    set.endGroup();
}

void QUIConfig::WriteConfig()
{
    QSettings set(QUIConfig::ConfigFile, QSettings::IniFormat);

    set.beginGroup("BaseConfig");
    set.endGroup();
}

void QUIConfig::NewConfig()
{
#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
#endif
    WriteConfig();
}

bool QUIConfig::CheckConfig()
{
    //如果配置文件大小为0,则以初始值继续运行,并生成配置文件
    QFile file(QUIConfig::ConfigFile);

    if (file.size() == 0) {
        NewConfig();
        return false;
    }

    //如果配置文件不完整,则以初始值继续运行,并生成配置文件
    if (file.open(QFile::ReadOnly)) {
        bool ok = true;

        while (!file.atEnd()) {
            QString line = file.readLine();
            line = line.replace("\r", "");
            line = line.replace("\n", "");
            QStringList list = line.split("=");

            if (list.count() == 2) {
                if (list.at(1) == "") {
                    ok = false;
                    break;
                }
            }
        }

        if (!ok) {
            NewConfig();
            return false;
        }
    } else {
        NewConfig();
        return false;
    }

    return true;
}

