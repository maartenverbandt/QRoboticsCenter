#ifndef QROBOTICSCENTERMAINWINDOW_H
#define QROBOTICSCENTERMAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QApplication>

#include <qrobotoverview.h>
#include <qserialscanner.h>
#include <qaboutdialog.h>

class QRoboticsCenterMainwindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit QRoboticsCenterMainwindow(QWidget *parent = 0);
    ~QRoboticsCenterMainwindow();

protected:
    void closeEvent(QCloseEvent *);

private:
    QSerialScanner *_scanner = new QSerialScanner(this);
    QRobotOverview *_overview = new QRobotOverview(this);

    QAction* _scan = new QAction("scan", this);
    QAction* _scan_usb = new QAction("usb", this);
    QAction* _scan_bluetooth = new QAction("bluetooth", this);
    QShowAboutDialogAction* _about = new QShowAboutDialogAction(0);

    void setup();
    void saveSettings();
    void loadSettings();

signals:

public slots:
    void scan();

};

#endif // QROBOTICSCENTERMAINWINDOW_H
