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
    connect(&watcher,SIGNAL(directoryChanged(QString)),this,SLOT(DirChange(QString)));

    ui->progressBar->setValue(0);
    Adham = new Thread(this);
    connect(Adham, SIGNAL(percent(int)),this,SLOT(showProgess(int)));

}

TabContentWidget::~TabContentWidget()
{
    ourMightyTrie.saveTrie();
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

void TabContentWidget::research()
{
    on_SearchButton_clicked();

}

void TabContentWidget::on_AddDirectoryButton_clicked()
{
    cout<<"start"<<endl;

    if(! ui->AddressLineEdit->isEnabled() )
        watcher.removePath(ui->AddressLineEdit->text());

    QString Address = QFileDialog::getExistingDirectory(this,"select directory",QDir::currentPath());

    watcher.addPath(Address);

    ui->AddressLineEdit->setText(Address);
    ui->AddressLineEdit->setEnabled(false);
    QDir dir(Address);
    QFileInfoList qsl = dir.entryInfoList(QDir::Files|QDir::NoDot|QDir::NoDotDot);
    ui->LoadingAddressLabel->setText("Loading from :"+Address);
    ui->progressBar->setRange(0,qsl.size());

    if(Files != nullptr)
        delete Files;

    Files = new FileTrieNode;
    QtConcurrent::run(FeedFileTrie,qsl,Files);

    Adham->Address=Address;
    Adham->ourMightyTrie=&ourMightyTrie;
    Adham->start();
}



void TabContentWidget::showProgess(int i){
    ui->progressBar->setValue(i);
}

void TabContentWidget::DirChange(QString x)
{
    QtConcurrent::run(UpdateTries,&ourMightyTrie,Files,x,this);
    if(ui->TargetWordLineEdit->text() != "");
        on_SearchButton_clicked();

}

void FeedFileTrie(QFileInfoList &l,FileTrieNode*& Files)
{
    for(auto i : l)
        Files->addFileName(i.baseName()+i.completeSuffix());
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

void UpdateTries(TrieNode *ourMightyTrieNode, FileTrieNode *Files, QString Path , TabContentWidget* parent)
{

    QFileInfoList qsl =QDir(Path).entryInfoList(QDir::Files|QDir::NoDot|QDir::NoDotDot);
    for(auto i : qsl){
        if(!Files->contains(i.baseName()+i.completeSuffix())){
            Files->addFileName(i.baseName()+i.completeSuffix());

            QFile file(i.absoluteFilePath());
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
                QMutex mutex;
                mutex.lock();
                ourMightyTrieNode->AddWord(word,i);
                mutex.unlock();

            }
        }

    }
//    parent->research();

}
