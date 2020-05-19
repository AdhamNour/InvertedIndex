#include "trinode.h"
#include <QFile>
#include<QTextStream>
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

void TrieNode::AddWord(const QString &word, const QString &FileName,  int index)
{
	if (index >= word.size()){
		this->isCompleteWord = true;
		if (this->FileNames == nullptr){
            this->FileNames = new set<QString>;
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
set<QString>* TrieNode::getContainingFileNames(const QString&TargetWord,  int index)
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
 void TrieNode::saveTrie(QString word) {

     if(this->isCompleteWord){
        QFile save_file("E:\\Data Structure\\build-InvertedIndexProject-Desktop_Qt_5_14_2_MinGW_64_bit-Debug\\debug\\our_mighty_trie.sav");
        if(!save_file.open(QFile::Append|QFile::Text)){
            cout<<"err"<<endl;
        } else if(!save_file.open(QFile::WriteOnly|QFile::Text)){
            cout<<"err2"<<endl;
        }
        QTextStream in(&save_file);
        QString files;
         for(auto file:*this->FileNames){
             files += file+",";
         }
         in<<word<<" "<<files;

}
     for(auto child : this->ChildNodes){
        child.second->saveTrie(word + child.first);
     }
}
