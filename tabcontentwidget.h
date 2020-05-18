#ifndef TABCONTENTWIDGET_H
#define TABCONTENTWIDGET_H

#include <QWidget>
#include <QFileDialog>
#include "trinode.h"

namespace Ui {
class TabContentWidget;
}

class TabContentWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TabContentWidget(QWidget *parent = nullptr);
    ~TabContentWidget();

private slots:
    void on_AddDirectoryButton_clicked();

private:
    Ui::TabContentWidget *ui;
    TrieNode ourMightyTrie;
};

#endif // TABCONTENTWIDGET_H
