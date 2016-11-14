#ifndef QROBOTBUTTON_H
#define QROBOTBUTTON_H

#include <QObject>
#include <qabstractrobot.h>
#include <qpushbutton.h>
#include <qstylepainter.h>
#include <QStyleOptionButton>

class QRobotButton : public QPushButton
{
    Q_OBJECT

public:
    QRobotButton(QAbstractRobot *robot, QWidget *parent = 0);

protected:
    virtual void paintEvent(QPaintEvent *);

private:
    const static size_t _icon_size = 60;
    int _id;

};

#endif // QROBOTBUTTON_H
