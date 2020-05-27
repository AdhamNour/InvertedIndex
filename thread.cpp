#include "thread.h"
#include <QtCore>

Thread::Thread()
{

}
void Thread::run(){
    QDir dir(Address);
    QFileInfoList qsl = dir.entryInfoList();

    for (int i = 0;i<qsl.size();i++) {
        QFile file(qsl.at(i).absoluteFilePath());
        if(!file.open(QFile::ReadOnly|QFile::Text)){
            cout<<"err"<<endl;
            continue;
        }
        emit percent(i);
        QTextStream in(&file);
        QString word;
        while(!in.atEnd()){
            in>>word;
            if(word.size()==0)
                continue;
            ourMightyTrie->AddWord(word,qsl.at(i));

        }


    }
    cout<<"end"<<endl;
}

