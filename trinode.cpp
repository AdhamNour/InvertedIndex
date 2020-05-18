#include "trinode.h"
TrieNode::TrieNode()
{

}

TrieNode::~TrieNode()
{
	for (auto i = ChildNodes.begin(); i != ChildNodes.end(); i++)
		delete i->second;
	if (FileNames != nullptr)
		delete FileNames;
}

void TrieNode::AddWord(const string &word, const string &FileName, unsigned int index)
{
	if (index >= word.size()){
		this->isCompleteWord = true;
		if (this->FileNames == nullptr){
			this->FileNames = new set<string>;
		}
		this->FileNames->insert(FileName);
		return;
	}
	auto i = ChildNodes[word[index]];
	if (i != nullptr)
		i->AddWord(word, FileName, index + 1);
	else{
		i = new TrieNode;
		i->AddWord(word, FileName, index + 1);
		ChildNodes[word[index]] = i;//bug may exist here
	}

}
set<string>* TrieNode::getContainingFileNames(const string&TargetWord, unsigned int index)
{

	if ((this->isCompleteWord) && (index == TargetWord.size()))
		return this->FileNames;
	else if (index != TargetWord.size())
	{
		auto i = ChildNodes[TargetWord[index]];
		if (i != nullptr){
			return i->getContainingFileNames(TargetWord, index + 1);
		}
		else {
			return nullptr;
		}

	}
	else if (index == TargetWord.size()&& !(this->isCompleteWord))
	{
		return nullptr;
	} 
	else{
		return nullptr;
	}

}
