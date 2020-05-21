#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QKeyEvent>
#include<QString>
#include<set>
#include"tabcontentwidget.h"

using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent* event);

private slots:
    void on_actionAdd_Tab_triggered();

    void on_tabWidget_tabCloseRequested(int index);

private:
    Ui::MainWindow *ui;
    set<TabContentWidget*> openedTab;


    void openNewTab();
    void closeTab(const int& index);
public slots:
    void onKeyEvent2(QKeyEvent*);

};
#endif // MAINWINDOW_H
