#ifndef TRIENODE_H
#define TRIENODE_H
#include <bits/stdc++.h>

using namespace std;
class TrieNode
{
private:
	bool isCompleteWord = false;
	map<char, TrieNode*> ChildNodes;
	set<string>* FileNames = nullptr; // contains the file names that is containing the word that completed in that node

public:
	TrieNode();
	~TrieNode();
	void AddWord(const string& word, const string& FileName, unsigned int index = 0);
	map<char, TrieNode*>* getChildNods(){ return &ChildNodes; }
	bool IsCompleteWord(){ return isCompleteWord; }
	set<string>* getContainingFileNames(const string&TargetWord, unsigned int index = 0);
};
#endif // TRIENODE_H