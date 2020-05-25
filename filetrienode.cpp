#include "filetrienode.h"

FileTrieNode::FileTrieNode()
{

}

FileTrieNode::~FileTrieNode()
{
    for (auto i = ChildNodes.begin(); i != ChildNodes.end(); i++)
        delete i->second;

}

void FileTrieNode::addFileName(const QString &FileName, int index)
{
    if (index >= FileName.size()){
        this->isCompleteFileName = true;
        return;
    }
    auto i = ChildNodes[FileName[index]];
    if (i != nullptr)
        i->addFileName(FileName, index + 1);
    else{
        i = new FileTrieNode;
        i->addFileName(FileName, index + 1);
        ChildNodes[FileName[index]] = i;//bug may exist here
    }
}

bool FileTrieNode::contains(const QString &FileName, int index)
{
    if(index >= FileName.size())
        return this->isCompleteFileName;
    auto i = ChildNodes[FileName[index]];
    if(i == nullptr)
        return false;
    return  i->contains(FileName,index+1);
}
