#ifndef TRIENODE_H
#define TRIENODE_H
#include<QString>
#include<map>
#include<vector>
using namespace std;
class TrieNode
{
private:
    bool isCompleteWord = false;
    map<QChar,TrieNode*> ChildNodes;
    vector<QString>* FileNames =nullptr; // contains the file names that is containing the word that completed in that node

public:
    TrieNode();
    ~TrieNode();
    void AddWord(const QString& word ,const QString& FileName, int index =0);
    map<QChar,TrieNode*>* getChildNods(){return &ChildNodes;}
    bool IsCompleteWord(){return isCompleteWord;}
    vector<QString>* getContainingFileNames(){return  FileNames;}
};

#endif // TRIENODE_H
