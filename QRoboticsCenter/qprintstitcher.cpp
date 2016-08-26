#include "qprintstitcher.h"

QPrintStitcher::QPrintStitcher(QObject *parent) : QObject(parent)
{

}

bool QPrintStitcher::stitch(QString part, int size)
{
    QString string = _line + part.left(size).remove("\n"); //append new string without line feeds
    QStringList substrings = string.split("\r",QString::SkipEmptyParts); //split the string at CRs
    _line = substrings.last();
    if(string.at(string.length()-1) == '\r'){
        _line += "\r";
        return true;
    }

    return false;
}

QString QPrintStitcher::getLine()
{
    return _line;
}

