#include "qexternalportdialog.h"

QExternalPortDialog::QExternalPortDialog(QString name, QWidget *parent) : QDialog(parent), _popup(new QAction(name,this))
{
    layoutSetup();
    QObject::connect(_popup,SIGNAL(triggered()),this,SLOT(show()));
}

QExternalPortDialog::~QExternalPortDialog()
{
    delete _stack;
}

void QExternalPortDialog::setCurrentPort(int index)
{
    if(index<_stack->count()){
        _buttons->button(index)->setChecked(true);
        //_stack->setCurrentIndex(index);
    }
}

void QExternalPortDialog::addPort(QWidget* w, QString name)
{
    QPushButton* button = new QPushButton(name,this);
    button->setMinimumSize(60,60);
    button->setMaximumSize(60,60);
    button->setCheckable(true);
    _button_layout->addWidget(button);
    _button_layout->setAlignment(button,Qt::AlignTop);

    _buttons->addButton(button,_stack->count());
    _stack->addWidget(w);
    setCurrentPort(_stack->count()-1);
}

QAction *QExternalPortDialog::getPopupAction()
{
    return _popup;
}

void QExternalPortDialog::layoutSetup()
{
    _layout = new QHBoxLayout();
    _button_layout = new QVBoxLayout();
    _buttons = new QButtonGroup(this);
    _stack = new QStackedWidget(this);

    setLayout(_layout);
    _layout->addLayout(_button_layout);
    _layout->addWidget(_stack,1);

    QObject::connect(_buttons,SIGNAL(buttonToggled(int,bool)),_stack,SLOT(setCurrentIndex(int)));
}

