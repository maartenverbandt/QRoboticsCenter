#ifndef QROBOTBUTTON_H
#define QROBOTBUTTON_H

#include <QObject>
#include <qrobot.h>
#include <qpushbutton.h>
#include <qstylepainter.h>
#include <QStyleOptionButton>

class QRobotButton : public QPushButton
{
    Q_OBJECT

public:
    QRobotButton(QRobot *robot, QWidget *parent = 0);
    QRobotButton(QString text, QIcon icon, int id, QWidget *parent = 0);

protected:
    virtual void paintEvent(QPaintEvent *);

private:
    const static size_t _icon_size = 60;
    int _id;

};

#endif // QROBOTBUTTON_H
