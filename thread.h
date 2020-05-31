#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QObject>
#include<QDir>
#include<QFileInfoList>
#include<QTextStream>
#include<iostream>
#include<trinode.h>

using namespace std;

namespace Ui {
class TabContentWidget;
}

class Thread : public QThread
{
    Q_OBJECT
public:
    QString Address;
    TrieNode* ourMightyTrie;
    Thread();
    explicit Thread(QObject *parent=0,QString Address="",TrieNode* ourMightyTrie=0){
        this->Address=Address;
        this->ourMightyTrie=ourMightyTrie;
    }
    void run();
signals:
    void percent(int);
public slots:
};

#endif // THREAD_H
