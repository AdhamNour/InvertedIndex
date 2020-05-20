#include "tabcontentwidget.h"
#include "ui_tabcontentwidget.h"
#include<iostream>
#include <QTextStream>
#include <QFile>
#include"trinode.h"
using namespace std;
TabContentWidget::TabContentWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabContentWidget)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);

}

TabContentWidget::~TabContentWidget()
{
    delete ui;
}

void TabContentWidget::on_AddDirectoryButton_clicked()
{
    cout<<"start"<<endl;
    QString Address = QFileDialog::getExistingDirectory(this,"select directory",QDir::currentPath());
    QDir dir(Address);
    QFileInfoList qsl = dir.entryInfoList();
    ui->LoadingAddressLabel->setText(ui->LoadingAddressLabel->text()+Address);    ui->progressBar->setRange(0,qsl.size()-2);
    for (int i = 0;i<qsl.size();i++) {
        QFile file(qsl.at(i).absoluteFilePath());
        if(!file.open(QFile::ReadOnly|QFile::Text)){
            cout<<"err"<<endl;
            continue;
        }
        ui->progressBar->setValue(i);
        QTextStream in(&file);
        QString word;
        while(!in.atEnd()){
            in>>word;
            if(word.size()==0)
                continue;
            ourMightyTrie.AddWord(word,qsl.at(i));

        }


    }
    cout<<"end"<<endl;
    //ourMightyTrie.saveTrie();
}

void TabContentWidget::on_SearchButton_clicked()
{
    QString s = ui->TargetWordLineEdit->text();
    QFileInfoList* fl = ourMightyTrie.getContainingFiles(s);
    if(fl == nullptr){
        cout<<"error in searching"<<endl;
        return;
    }
    for (int i = 0 ;  i < fl->size() ; i++) {
        ui->listWidget->addItem(fl->at(i).completeBaseName());
    }
}
