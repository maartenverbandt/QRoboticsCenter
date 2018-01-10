#include "qroboticscentermainwindow.h"

QRoboticsCenterMainwindow::QRoboticsCenterMainwindow(QWidget *parent) : QMainWindow(parent)
{
    setup();

    QObject::connect(_scan, &QAction::triggered, this, &QRoboticsCenterMainwindow::scan);
    QObject::connect(_scanner, &QSerialScanner::connectionFound, _overview, &QRobotOverview::addConnection);

    scan();
}

QRoboticsCenterMainwindow::~QRoboticsCenterMainwindow()
{
    saveSettings();
}

void QRoboticsCenterMainwindow::closeEvent(QCloseEvent*)
{
    foreach (QWidget *widget, QApplication::topLevelWidgets()){
        widget->close();
    }
}

void QRoboticsCenterMainwindow::setup()
{
    // main widget
    setCentralWidget(_overview);

    // Scanning menu
    QMenu *scan = menuBar()->addMenu("Scan");
    _scan->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
    scan->addAction(_scan);
    scan->addSeparator();
    _scan_usb->setCheckable(true);
    _scan_bluetooth->setCheckable(true);
    scan->addAction(_scan_usb);
    scan->addAction(_scan_bluetooth);

    // Help menu
    QMenu *help = menuBar()->addMenu("Help");
    help->addAction(_about);
    loadSettings();
}

void QRoboticsCenterMainwindow::scan()
{
    if(_scan_usb->isChecked()) _scanner->scanUSB();
    if(_scan_bluetooth->isChecked()) _scanner->scanBT();
}

void QRoboticsCenterMainwindow::saveSettings()
{
    QSettings settings("RobSoft", "QRoboticsCenter");

    // set window group
    settings.beginGroup("QRobotMainwindow");

    // save window settings
    settings.setValue("pos", pos());

    //save scan settings
    settings.setValue("scan_usb", _scan_usb->isChecked());
    settings.setValue("scan_bluetooth", _scan_bluetooth->isChecked());

    settings.endGroup();

    // Save robot settings
    /*QListIterator<QAbstractRobot*> robot(_robots);
    while (robot.hasNext())
        robot.next()->saveState();*/
}

void QRoboticsCenterMainwindow::loadSettings()
{
    QSettings settings;

    // set window group
    settings.beginGroup("QRobotCoordinator");

    // restore window settings
    move(settings.value("pos", QPoint(200, 200)).toPoint());

    //save scan settings
    _scan_usb->setChecked(settings.value("scan_usb",true).toBool());
    _scan_bluetooth->setChecked(settings.value("scan_bluetooth",false).toBool());

    settings.endGroup();
}
