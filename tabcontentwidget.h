#ifndef TABCONTENTWIDGET_H
#define TABCONTENTWIDGET_H

#include <QWidget>
#include <QFileDialog>
#include"trinode.h"
#include "thread.h"
#include "utils.h"
#include "filetrienode.h"
#include <QListWidget>
#include<QtConcurrent/QtConcurrent>
#include <QFileSystemWatcher>
#include<QFutureWatcher>
#include<QFuture>

namespace Ui {
class TabContentWidget;
}

namespace Ui { class MainWindow; }


class TabContentWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TabContentWidget(QWidget *parent = nullptr);
    ~TabContentWidget();
    Thread* Adham;
    void keyPressEvent(QKeyEvent* event);
    void research();


private slots:
    void on_AddDirectoryButton_clicked();

    void on_SearchButton_clicked();
    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_TargetWordLineEdit_textChanged(const QString &arg1);

public slots:
    void showProgess(int);
    void DirChange(QString);

signals:
    void Event(QKeyEvent*);
private:
    Ui::TabContentWidget *ui;
    TrieNode ourMightyTrie;
    FileTrieNode* Files= nullptr;
    QFileSystemWatcher watcher;
    QFutureWatcher<void> futurewatcher;
};

void UpdateTries(TrieNode* ourMightyTrieNode,FileTrieNode* Files,QString Path,TabContentWidget* parent);

void FeedFileTrie(QFileInfoList& l,FileTrieNode*& Files);


#endif // TABCONTENTWIDGET_H
