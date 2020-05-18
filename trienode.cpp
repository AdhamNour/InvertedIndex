#include "trienode.h"

TrieNode::TrieNode()
{

}

TrieNode::~TrieNode()
{
    for(auto i = ChildNodes.begin();i!= ChildNodes.end() ; i++)
        delete i->second;
    if(FileNames !=  nullptr)
        delete FileNames;
}

void TrieNode::AddWord(const QString &word, const QString &FileName, int index)
{
    if(index >= word.size()){
        this->isCompleteWord = true;
        return;
    }
    auto i = ChildNodes[word[index]];
    if(i!= nullptr)
        i->AddWord(word,FileName,index+1);
    else{
        i = new TrieNode;
        i->AddWord(word,FileName,index+1);
        ChildNodes[word[index]]=i;//bug may exist here
    }

}
