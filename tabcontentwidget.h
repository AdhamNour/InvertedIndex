#ifndef TABCONTENTWIDGET_H
#define TABCONTENTWIDGET_H

#include <QWidget>
#include <QFileDialog>
#include"trinode.h"
#include "thread.h"
namespace Ui {
class TabContentWidget;
}

class TabContentWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TabContentWidget(QWidget *parent = nullptr);
    ~TabContentWidget();
    Thread* Adham;
    void keyPressEvent(QKeyEvent* event);


private slots:
    void on_AddDirectoryButton_clicked();

    void on_SearchButton_clicked();
public slots:
    void showProgess(int);

signals:
    void Event(QKeyEvent*);
private:

    Ui::TabContentWidget *ui;
    TrieNode ourMightyTrie;
};

#endif // TABCONTENTWIDGET_H
