#ifndef TRIENODE_H
#define TRIENODE_H
#include <bits/stdc++.h>
#include <QString>

using namespace std;
class TrieNode
{
private:
	bool isCompleteWord = false;
    map<QChar, TrieNode*> ChildNodes;
    set<QString>* FileNames = nullptr; // contains the file names that is containing the word that completed in that node

public:
	TrieNode();
	~TrieNode();
    void AddWord(const QString& word, const QString& FileName,  int index = 0);
    map<QChar, TrieNode*>* getChildNods(){ return &ChildNodes; }
	bool IsCompleteWord(){ return isCompleteWord; }
    set<QString>* getContainingFileNames(const QString &TargetWord,  int index = 0);
    void saveTrie( QString word = "");
};
#endif // TRIENODE_H
