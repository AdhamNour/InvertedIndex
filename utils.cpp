//implemented by Ziad Tarek
#include "utils.h"

QString  Utils::HighLight(const QString &wordToBeReplaced,const QString& OriginalText)
{
    QString HighlightedWord = "<span style=\"background-color: #FFFF00\">"+wordToBeReplaced+"</span>";
    QTextEdit textEdit;
    textEdit.setPlainText(OriginalText);
    QString ret = textEdit.toHtml();
    ret.replace(wordToBeReplaced,HighlightedWord);
    return ret;
}

