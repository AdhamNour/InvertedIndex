#include "tabcontentwidget.h"
#include "ui_tabcontentwidget.h"

TabContentWidget::TabContentWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabContentWidget)
{
    ui->setupUi(this);
}

TabContentWidget::~TabContentWidget()
{
    delete ui;
}
