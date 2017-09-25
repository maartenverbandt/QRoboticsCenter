#include "qstackedwindow.h"

QStackedWindow::QStackedWindow(QWidget *parent) :
    QMainWindow(parent),
    _stack(new QStackedWidget(this)),
    _stackup_action(new QAction("next",this)),
    _stackdown_action(new QAction("prev",this))
{
    // Set stack widget
    setCentralWidget(_stack);

    // Stack up action
    _stackup_action = new QAction("next",this);
    _stackup_action->setShortcut(Qt::CTRL + Qt::Key_Right);
    QObject::connect(_stackup_action,SIGNAL(triggered(bool)),this,SLOT(stackUp()));
    addAction(_stackup_action);

    // Stack down action
    _stackdown_action = new QAction("prev",this);
    _stackdown_action->setShortcut(Qt::CTRL + Qt::Key_Left);
    QObject::connect(_stackdown_action,SIGNAL(triggered(bool)),this,SLOT(stackDown()));
    addAction(_stackdown_action);
}

int QStackedWindow::addView(QWidget *w)
{
    //make action and menu
    int index = _stack->addWidget(w);
    setView(index);
    return index;
}

void QStackedWindow::setView(int index)
{
    //set index of the view
    if((index>=0) && (index<_stack->count()))
        _stack->setCurrentIndex(index);
}

QAction *QStackedWindow::getNextViewAction()
{
    return _stackup_action;
}

QAction *QStackedWindow::getPrevViewAction()
{
    return _stackdown_action;
}

void QStackedWindow::stackUp()
{
    int new_index = _stack->currentIndex()+1;
    if(new_index>_stack->count())
        new_index = 0;
    _stack->setCurrentIndex(new_index);
}

void QStackedWindow::stackDown()
{
    int new_index = _stack->currentIndex()-1;
    if(new_index < 0)
        new_index = _stack->count();
    _stack->setCurrentIndex(new_index);
}

void QStackedWindow::setStackEnabled(bool enable)
{
    _stack->setEnabled(enable);
}
