#include "parsetext.h"

#define MIN(a, b) (a < b) ? a : b

ParseText::ParseText()
{
    text = "";
    preText = "";
    pos = 0;
}

bool ParseText::change(QString istr)
{
    qint32 length = MIN(MIN(text.length(), istr.length()), pos);
    preText = "";
    for (qint32 i = 0; i < length; i++)
    {
        if (text[i] != istr[i])
        {
            pos = i;
            break;
        }
    }
    const QChar *arStr = istr.constData();
    qint32 ppos = 0, lastp = -1;
    bool chg = false;
    for (qint32 fnd = istr.indexOf("#RUB#", pos);
         fnd != -1 && lastp != pos;
         fnd = istr.indexOf("#RUB#", pos)
         )
    {
        preText.insert(preText.length(), &arStr[ppos], fnd);
        lastp = pos;
        pos = fnd;
        preText += "₽";
        pos = pos + 1;
        chg = true;
        preText.insert(preText.length(), &arStr[pos + 4], istr.length() - pos - 4);
    }
    for (qint32 fnd = istr.indexOf("#PML#", pos);
         fnd != -1 && lastp != pos;
         fnd = istr.indexOf("#PML#", pos)
         )
    {
        preText.insert(preText.length(), &arStr[ppos], fnd);
        lastp = pos;
        pos = fnd;
        preText += "‰";
        pos = pos + 1;
        chg = true;
        preText.insert(preText.length(), &arStr[pos + 4], istr.length() - pos - 4);
    }
    for (qint32 fnd = istr.indexOf("#CPR#", pos);
         fnd != -1 && lastp != pos;
         fnd = istr.indexOf("#CPR#", pos)
         )
    {
        preText.insert(preText.length(), &arStr[ppos], fnd);
        lastp = pos;
        pos = fnd;
        preText += "©";
        pos = pos + 1;
        chg = true;
        preText.insert(preText.length(), &arStr[pos + 4], istr.length() - pos - 4);
    }
    for (qint32 fnd = istr.indexOf("#EUR#", pos);
         fnd != -1 && lastp != pos;
         fnd = istr.indexOf("#EUR#", pos)
         )
    {
        preText.insert(preText.length(), &arStr[ppos], fnd);
        lastp = pos;
        pos = fnd;
        preText += "€";
        pos = pos + 1;
        chg = true;
        preText.insert(preText.length(), &arStr[pos + 4], istr.length() - pos - 4);
    }

    return chg;
}

QString ParseText::getText()
{
    text = preText;
    return  text;
}



