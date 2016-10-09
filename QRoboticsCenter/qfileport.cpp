#include "qfileport.h"
#include "ui_qfileport.h"

QFilePort::QFilePort(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QFilePort)
{
    ui->setupUi(this);
}

QFilePort::~QFilePort()
{
    delete ui;
}

QAction *QFilePort::getPopupAction()
{
    return _popup;
}

QString QFilePort::readHeader()
{
    QStringList columns;
    QString header;
    QString line;

    do {
        header += line;
        _data_begin = _stream->pos();
        line = _stream->readLine();
        columns = line.split('\t',QString::SkipEmptyParts);
        line += '\n';
    } while(columns.length() < 2);
    reset();

    ui->header_label->setText(header);
    return header;
}

QStringList QFilePort::readLine()
{
    // read line
    QStringList columns = _stream->readLine().split('\t',QString::SkipEmptyParts);
    ui->progressBar->setValue(_stream->pos());

    // check end of file
    if(_stream->atEnd()){
        reset();
    }

    return columns;
}

void QFilePort::reset()
{
    _stream->seek(_data_begin); //go to start of csv
}

void QFilePort::saveSettings()
{
    QSettings settings("RobSoft", "QGPIOWidget");
    settings.beginGroup("QFilePort");
    // save filename
    settings.setValue("filename",_file->fileName());
    settings.endGroup();
}

void QFilePort::loadSettings()
{
    QSettings settings("RobSoft", "QGPIOWidget");
    settings.beginGroup("QFilePort");
    // save filename
    setFile(settings.value("filename").toString());
    settings.endGroup();
}

bool QFilePort::setFile(QString absolute_path)
{
    if(_file->isOpen()){
        _file->close();
    }

    _file->setFileName(absolute_path);
    if(_file->exists()){
        ui->name_lineEdit->setText(absolute_path);
        ui->progressBar->setMaximum(_file->size());
        _file->open(QFile::ReadOnly);
        _stream->seek(0);
        readHeader();
        return true;
    }

    return false;
}

void QFilePort::openFile()
{
    QFileInfo info(*_file);
    QString path = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    info.path(),
                                                    tr("CSV files (*.csv *.txt)"));
    if(~path.isEmpty()){
        setFile(path);
    }
}
