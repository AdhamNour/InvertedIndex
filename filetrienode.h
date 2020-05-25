#ifndef FILETRIENODE_H
#define FILETRIENODE_H

#include <QString>
#include<map>

using namespace std;

class FileTrieNode
{
private:
    static QString  DirectoryAddress;
    bool isCompleteFileName = false;
    map<QChar, FileTrieNode*> ChildNodes;
public:
    FileTrieNode();
    ~FileTrieNode();
    void addFileName(const QString& FileName , int index = 0);
    bool contains (const QString& FileName ,  int index = 0);
};

#endif // FILETRIENODE_H
