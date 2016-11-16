#include "qrobotconfig.h"

QRobotConfig::QRobotConfig(QObject *parent) :
    QObject(parent)
{

}

QTreeWidgetItem *QRobotConfig::addGroup(QString group)
{
    QStringList list;
    list.append(group);
    list.append("");
    QTreeWidgetItem *item = new QTreeWidgetItem(list,100);
    _top.append(item);

    return item;
}

void QRobotConfig::addParameter(QTreeWidgetItem *item, QString group)
{
    if(group.isNull()){
        _top.append(item);
    } else {
        //browse through: FIX!!
        //QList<QTreeWidgetItem*> parents = ui->treeWidget->findItems(group,Qt::MatchExactly);
        /*if(!parents.isEmpty()){
            parents[0]->addChild(item);
        } else {
            _top.append(item);
        }*/
    }
}
