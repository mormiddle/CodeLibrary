#include "mainwindow.h"

#include "quidialog.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QuiDialog qui;
    MainWindow *widget = new MainWindow;

    qui.setMainWidget(widget);

    //设计标题按钮大小
    qui.setBtnWidth(30);

    //设置标题
     qui.setTitle("sxc");

    //设置标题文本居中
//    qui.setAlignment(Qt::AlignCenter);

    //设置窗体可拖动大小
    qui.setSizeGripEnabled(true);

    //设置标题栏高度
    qui.setTitleHeight(55);

    qui.show();

    return a.exec();
}
