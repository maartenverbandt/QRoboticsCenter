#include "qabstractexternalport.h"

QAbstractExternalPort::QAbstractExternalPort(QObject *parent) : QDialog(parent)
{
    layoutSetup();
}

void QAbstractExternalPort::layoutSetup()
{
    _layout = new QHBoxLayout(this);
    _button_layout = new QVBoxLayout(this);
}

