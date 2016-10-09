#ifndef QFILEPORT_H
#define QFILEPORT_H

#include <QWidget>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>

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

private:
    Ui::QFilePort *ui;

    QFile* _file;
    QTextStream* _stream;
    quint64 _data_begin;
    int _timer_id;
    bool _repeat;

    QAction *_popup;

    QString readHeader();
    QStringList readLine();

    void saveSettings();
    void loadSettings();

public slots:
    bool setFile(QString absolute_path);
    bool openFile();

};

#endif // QFILEPORT_H
