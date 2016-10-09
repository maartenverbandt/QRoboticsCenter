#include "qexternalportdialog.h"

QExternalPortDialog::QExternalPortDialog(QObject *parent) : QDialog(parent)
{
    layoutSetup();
}

QExternalPortDialog::addWidget(QWidget* w, QString name)
{
    QPushButton* button = new QPushButton(name,this);
    button->setMinimumSize(60,60);
    button->setMaximumSize(60,60);
    button->setCheckable(true);
    _button_layout->addWidget(button);

    _buttons->addButton(button,_stack->count());
    _stack->addWidget(w);
}

void QExternalPortDialog::layoutSetup()
{
    _layout = new QHBoxLayout(this);
    _button_layout = new QVBoxLayout(this);
    _buttons = new QButtonGroup(this);
    _stack = new QStackedWidget(this);

    setLayout(_layout);
    _layout->addLayout(_button_layout);
    _layout->addWidget(_stack,1);

    QObject::connect(_buttons,SIGNAL(buttonToggled(int,bool)),_stack,SLOT(setCurrentIndex(int)));
}

