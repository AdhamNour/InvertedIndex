#ifndef TRIENODE_H
#define TRIENODE_H
#include <bits/stdc++.h>
#include <QString>
#include<QFileInfo>
#include<QFileInfoList>

using namespace std;
class TrieNode
{
private:
	bool isCompleteWord = false;
    map<QChar, TrieNode*> ChildNodes;
    QFileInfoList* Files = nullptr; // contains the file names that is containing the word that completed in that node

public:
	TrieNode();
	~TrieNode();
    void AddWord(const QString& word, const QFileInfo& File,  int index = 0);
    map<QChar, TrieNode*>* getChildNods(){ return &ChildNodes; }
	bool IsCompleteWord(){ return isCompleteWord; }
    QFileInfoList* getContainingFiles(const QString &TargetWord,  int index = 0);
    void saveTrie( QString word = "");
};
#endif // TRIENODE_H
