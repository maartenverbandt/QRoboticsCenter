#ifndef QPRINTSTITCHER_H
#define QPRINTSTITCHER_H

#include <QObject>

class QPrintStitcher : public QObject
{
    Q_OBJECT
public:
    explicit QPrintStitcher(QObject *parent = 0);

    bool stitch(QString part, int size);
    QString getLine();

private:
    QString _line;

signals:
    void complete(QString line);

public slots:
};

#endif // QPRINTSTITCHER_H
