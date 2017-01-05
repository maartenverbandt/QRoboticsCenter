#ifndef QROBOTCONFIG_H
#define QROBOTCONFIG_H

#include <QObject>
#include <qtreewidgetparameter.h>

class QRobotConfig : public QObject
{
    Q_OBJECT
public:
    explicit QRobotConfig(QObject *parent = 0);

protected:
    QTreeWidgetItem *addGroup(QString group);
    void addParameter(QTreeWidgetItem *item, QString group = QString());
    template <typename T> QTreeWidgetItem* addParameter(QString name, T *value, QString group = QString());

private:
    QList<QTreeWidgetItem*> _top;
    QList<QTreeWidgetParameterInterface*> _parameters;

signals:

public slots:
};

template <typename T> QTreeWidgetItem* QRobotConfig::addParameter(QString name, T *value, QString group)
{
    QTreeWidgetParameter<T>* item = new QTreeWidgetParameter<T>(name,value);
    _parameters.append(item);
    addParameter(item,group);
    item->setup();

    return item;
}

#endif // QROBOTCONFIG_H
