#include "utils.h"

QString  Utils::HighLight(const QString &TargetWord,const QString& OriginalText)
{
    QString HighlightedTargetWord = "<span style=\"background-color: #FFFF00\">"+TargetWord+"</span>";
    QTextEdit textEdit;
    textEdit.setPlainText(OriginalText);
    QString ret = textEdit.toHtml();
    ret.replace(TargetWord,HighlightedTargetWord);
    return ret;
}

