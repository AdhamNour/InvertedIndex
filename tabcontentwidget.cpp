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
    for (int i = 0;i<qsl.size();i++) {
        QFile file(qsl.at(i).absoluteFilePath());
        if(!file.open(QFile::ReadOnly|QFile::Text)){
            cout<<"err"<<endl;
            continue;
        }
        QTextStream in(&file);
        QString word;
        while(!in.atEnd()){
            in>>word;
            if(word.size()==0)
                continue;
            ourMightyTrie.AddWord(word,qsl.at(i).absoluteFilePath());

        }


    }
    cout<<"end"<<endl;
}
