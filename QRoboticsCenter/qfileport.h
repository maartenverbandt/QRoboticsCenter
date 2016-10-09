#ifndef QFILEPORT_H
#define QFILEPORT_H

#include <QWidget>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QSettings>
#include <QDebug>

namespace Ui {
class QFilePort;
}

class QFilePort : public QWidget
{
    Q_OBJECT

public:
    explicit QFilePort(QWidget *parent = 0);
    ~QFilePort();

    QAction *getPopupAction();
    void reset();

protected:
    virtual void sendData() = 0;
    QStringList readLine();
    void abort(QString text = "Aborted for unknown reason");

private:
    Ui::QFilePort *ui;

    QFile* _file;
    QTextStream* _stream;
    quint64 _data_begin;
    int _timer_id;
    bool _repeat;

    QAction *_popup;

    QString readHeader();

    void saveSettings();
    void loadSettings();

    void timerEvent(QTimerEvent *e);

public slots:
    bool setFile(QString absolute_path);
    bool openFile();
    void handleStartButton(bool checked);
    void start();
    void stop();

};

#endif // QFILEPORT_H
