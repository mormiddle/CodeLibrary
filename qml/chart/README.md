# qml中的Chart

## 一、QmlCustomPlot

在qml中使用CustomPlot，使用自定义类slqmlcustomplot实现包括Barchart，ColorMap，KLine，PlotBar和PlotView效果

支持MSCV2017

### 1. slqmlcustomplot类

- 继承自QQuickPaintedItem(QQuickItem的子类，可以直接使用QPainter API进行绘制)
- 需要注意是的是QQuickPaintedItem绘制操作发生在CPU上，在大量绘图的情况下，可能会影响程序的性能
- 比较重要的几个函数包括getPlot，onCustomReplot和updateCustomPlotSize

#### 1.1 getPlot

- 通过函数来获取指针
- 方便内存管理，数据封装和接口清晰

#### 1.2 onCustomReplot

- 内部只有一个update函数，用于更新CustomPlot的绘图区域
- update有一个可选参数 rect，用于指定需要更新的部分矩形区域。如果未提供 rect 参数，则默认更新整个部件

#### 1.3 updateCustomPlotSize

- 更新CustomPlot的大小，将QCustomPlot 控件的宽度和高度设置为组件的宽度和高度
- 在组件的尺寸发生变化时，该函数会被调用，以确保 QCustomPlot 控件始终与组件一样大小

### 2. CustomPlotItem子类

一个基本的slqmlcustomplot类，绘制一个表格，内部维护一个timerEvent（定时器事件处理函数）

- initCustomPlot用于初始化图表，可以设定样式和内容
- 这个基本类中，包括拖拽和缩放，使用`getPlot()->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);`来实现
- `QCustomPlot::afterReplot`是一个信号，在 QCustomPlot 绘图区域完成重新绘制之后发出信号
- 使用`connect(getPlot(), &QCustomPlot::afterReplot, this, &CustomPlotItem::onCustomReplot);`在绘图重绘后，使用onCustomReplot来更新绘图
- `onCustomReplot()` 函数中的 `update()` 函数用于更新 QCustomPlot 的显示区域，使其尽可能适应当前控件大小，因此需要在控件大小发生变化时调用。而 `getPlot()->replot()` 函数则用于重新绘制 QCustomPlot 对象，将新的数据显示到绘图区域上。因此，在调用 `update()` 函数后，需要再次调用 `getPlot()->replot()` 函数才能将新的数据显示出来。

### 3 . CustomPlotBarItem子类

一个基于slqmlcustomplot的条形图和折线图，条形图为堆积条形图，折线图有阴影显示和突出点

- Qt中声明一个可供QML调用的属性，名为barColor，它的类型为QColor。通过READ和WRITE关键字，该属性可以读取和写入。当该属性的值发生变化时，会触发一个barColorChanged信号，从而通知其他地方该属性的变化。
- initCustomPlot用于初始化图表，可以设定样式和内容
- barColor用于读取颜色，setBarColor用于设置颜色，barColorChanged是一个信号用于监控颜色变换
- 使用`QCPGraph *graph1 = getPlot()->addGraph();`，添加曲线对象
- 使用`QCPBars *bars1 = new QCPBars(getPlot()->xAxis, getPlot()->yAxis);`，添加柱状图对象
- 使用`QLinearGradient plotGradient;`，添加线性渐变色对象

### 4. CustomKLine子类

一个基于slqmlcustomplot的阴阳线、蜡烛图和OHLC图

- 构造函数中，使用`setFlag(QQuickItem::ItemHasContents, true);`，来设置该 QQuickItem 具有内容，即需要进行绘制
- 构造函数中，使用`setAcceptedMouseButtons(Qt::AllButtons);`，来设置该 QQuickItem 接受所有的鼠标按键事件，包括左键、中键和右键
- 使用`QCPFinancial *candlesticks = new QCPFinancial(plot->xAxis, plot->yAxis);`，来构建一个蜡烛图对象，
  - QCPFinancialData：表示一个包含股票价格的数据结构，其中包括时间戳、开盘价、最高价、最低价、收盘价。
- 使用`candlesticks->data()->set(QCPFinancial::timeSeriesToOhlc(time, value1, binSize, startTime));`，设置蜡烛图数据的方法，其中参数为时间序列、值序列、时间间隔和起始时间
- 使用`QCPFinancial *ohlc = new QCPFinancial(plot->xAxis, plot->yAxis);`，来构建一个ohlc对象
- 使用`QCPAxisRect *volumeAxisRect = new QCPAxisRect(plot);`，来创建矩阵图
- 使用`plot->plotLayout()->setRowSpacing(0);`，设置QCustomPlot中的图形布局的行间距为0

### 5. CustomColorMap子类

- 构造函数同CustomKLine子类
- 使用`QCPColorMap *colorMap = new QCPColorMap(plot->xAxis, plot->yAxis);`，来创建颜色图
  - 传入QCPColorMap为QCustomPlot的x轴和y轴
- 使用`QCPColorScale *colorScale = new QCPColorScale(plot);`，来添加一个颜色图例
- 使用`plot->plotLayout()->addElement(0, 1, colorScale);`，来将`colorScale`元素添加到绘图布局中的第一行、第二列中
  - 通过`addElement()`函数可以将元素添加到布局中的特定单元格中。在这里，第一个参数为行，第二个参数为列，第三个参数为需要添加到该单元格的元素。
- 使用`colorMap->setGradient(QCPColorGradient::gpPolar);`，使用 QCPColorGradient 枚举值为 `gpPolar` 的预定义颜色映射设置 `colorMap` 对象的渐变色谱（gradient）

### 6. CustomBarChart子类

一个基于slqmlcustomplot的简单条形图

- 使用`QCPBars *regen = new QCPBars(plot->xAxis, plot->yAxis);`，来创造一个空的条形矩阵
- 使用`regen->setAntialiased(false);`，来关闭抗锯齿功能，提供更清晰、像素对齐的条形边框
- 使用`regen->setStackingGap(1);`，来设置堆积条之间的间距为1
- 使用`regen->moveAbove(nuclear);`，来设置堆积图彼此叠加

### 7. main.qml

整合集中几种customplot在一个界面中

- 使用`SwipeView`，来实现一种滑动页面视图
- 使用`TabBar`，来在屏幕底部显示一组标签页，每个标签页代表一个不同的页面





