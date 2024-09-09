#ifndef CENTEREDSCROLLAREA_H
#define CENTEREDSCROLLAREA_H

#include <QAbstractScrollArea>
#include <QScrollBar>
#include <QWidget>
#include <QVBoxLayout>

class CenteredScrollArea : public QAbstractScrollArea {
    Q_OBJECT

public:
    explicit CenteredScrollArea(QWidget *parent = nullptr);

    // 设置内容部件
    void setWidget(QWidget *widget) ;

    // 重写 resizeEvent 来调整布局和更新滚动条
    void resizeEvent(QResizeEvent *event) override ;
    void setWidgetResizable(bool tar);

    // 重写滚动条的范围设置
    void updateScrollBars() ;

    // 更新内容的位置，如果没有超出范围，则居中
    void updateContentPosition() ;

protected:
    // 处理滚动条的变化事件
    void scrollContentsBy(int dx, int dy) override ;

private:
    QWidget *contentWidget;  // 显示内容的部件
    bool widgetResizable;
    void resizeWidget();
};


#endif // CENTEREDSCROLLAREA_H
