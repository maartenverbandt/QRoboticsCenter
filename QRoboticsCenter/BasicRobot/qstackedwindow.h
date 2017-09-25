#ifndef QSTACKEDWINDOW_H
#define QSTACKEDWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QMenu>
#include <QDebug>

class QStackedWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit QStackedWindow(QWidget *parent = 0);

    int addView(QWidget* w);
    void setView(int index);
    QAction *getNextViewAction();
    QAction *getPrevViewAction();

private:
    QStackedWidget* _stack;
    QAction* _stackup_action;
    QAction* _stackdown_action;

private slots:
    void stackUp();
    void stackDown();

public slots:
    void setStackEnabled(bool enable = true);

};

#endif // QSTACKEDWINDOW_H
