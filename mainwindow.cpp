#include "mainwindow.h"
#include "ui_mainwindow.h"

#include"tabcontentwidget.h"

#include<QDesktopServices>
#include<iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    openNewTab();

    //QTabBar* u = ui->tabWidget->tabBar();


//    QPushButton* p = new QPushButton("+");

//    u->setTabButton(ui->tabWidget->count()-1,QTabBar::LeftSide,p);
//    ui->tabWidget->addTab(new QWidget,"tst");

//    QString link = "https://www.facebook.com/AdhamNourElwaffaa/";
//    QDesktopServices::openUrl(QUrl(link));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->modifiers()==Qt::ControlModifier){
        switch (event->key()) {
            case Qt::Key_N:
                openNewTab();
            break;
            case Qt::Key_W:
                closeTab(ui->tabWidget->currentIndex());
            break;
        default:
            cout<<"control pressed with no additional key"<<endl;

        }
    }
    if(event->modifiers()==Qt::AltModifier){
        switch (event->key()) {
        case Qt::Key_A:
            ui->tabWidget->setCurrentIndex((ui->tabWidget->count()+ui->tabWidget->currentIndex()-1)%ui->tabWidget->count());
            break;
        case Qt::Key_D:
            ui->tabWidget->setCurrentIndex((ui->tabWidget->currentIndex()+1)%ui->tabWidget->count());
            break;
        default:
            cout<<"alt  pressed with no additional key"<<endl;

        }
    }

}

void MainWindow::openNewTab()
{
    ui->tabWidget->addTab(new TabContentWidget(),QString("Project %0").arg(ui->tabWidget->count()+1));
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
}

void MainWindow::closeTab(const int &index)
{
    ui->tabWidget->removeTab(index);
}




void MainWindow::on_actionAdd_Tab_triggered()
{
    openNewTab();
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    closeTab(index);
}
