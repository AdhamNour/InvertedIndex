#include "tabcontentwidget.h"
#include "ui_tabcontentwidget.h"
#include<iostream>
#include <QTextStream>
#include <QFile>
#include"trinode.h"
#include<QMessageBox>
#include<QKeyEvent>
using namespace std;
TabContentWidget::TabContentWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabContentWidget)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);
    Adham = new Thread(this);
    connect(Adham, SIGNAL(percent(int)),this,SLOT(showProgess(int)));

}

TabContentWidget::~TabContentWidget()
{
    delete ui;
}

void TabContentWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Enter || event->key() == Qt::Key_Return){
        cout<<ui->TargetWordLineEdit->text().toStdString()<<endl;
        on_SearchButton_clicked();
    }
    else{
        emit Event(event);
    }


}

void TabContentWidget::on_AddDirectoryButton_clicked()
{
    cout<<"start"<<endl;
    QString Address = QFileDialog::getExistingDirectory(this,"select directory",QDir::currentPath());
    ui->AddressLineEdit->setText(Address);
    ui->AddressLineEdit->setEnabled(false);
    QDir dir(Address);
    QFileInfoList qsl = dir.entryInfoList();
    ui->LoadingAddressLabel->setText("Loading from :"+Address);
    ui->progressBar->setRange(0,qsl.size()-2);

    Adham->Address=Address;
    Adham->ourMightyTrie=&ourMightyTrie;
    Adham->start();
}



void TabContentWidget::showProgess(int i){
    ui->progressBar->setValue(i);
}
void TabContentWidget::on_SearchButton_clicked()
{
    ui->listWidget->clear();
    QFileInfoList* fl = ourMightyTrie.getContainingFiles(ui->TargetWordLineEdit->text());
    if(fl == nullptr){
        cout<<"error in searching"<<endl;
        QMessageBox::warning(this,"TakeCare","The desigred word doesn't exist");
        return;
    }
    for (int i = 0 ;  i < fl->size() ; i++) {
        ui->listWidget->addItem(fl->at(i).absoluteFilePath());
    }
}

void TabContentWidget::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QFile file(item->text());
    if(!file.open(QFile::ReadOnly)){
        cout<<"opening file error"<<endl;
    }
    QTextStream in(&file);
    QString s = in.readAll();
    ui->textBrowser->setHtml(Utils::HighLight(ui->TargetWordLineEdit->text(),s));
}

void TabContentWidget::on_TargetWordLineEdit_textChanged(const QString &arg1)
{
    ui->listWidget->clear();

}
