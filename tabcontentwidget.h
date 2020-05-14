#ifndef TABCONTENTWIDGET_H
#define TABCONTENTWIDGET_H

#include <QWidget>

namespace Ui {
class TabContentWidget;
}

class TabContentWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TabContentWidget(QWidget *parent = nullptr);
    ~TabContentWidget();

private:
    Ui::TabContentWidget *ui;
};

#endif // TABCONTENTWIDGET_H
