#ifndef QEXCITATIONDIALOG_H
#define QEXCITATIONDIALOG_H

#include <QDialog>
#include <QComboBox>
#include <QAction>
#include <qbalancingconnectionmanager.h>
#include <mavlink.h>

namespace Ui {
class QExcitationDialog;
}

class QExcitationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QExcitationDialog(QWidget *parent = 0);
    ~QExcitationDialog();

    void connect(QBalancingConnectionManager *c);
    QAction* getPopupAction();

private:
    Ui::QExcitationDialog *ui;
    QComboBox* _channels[8];
    QAction* _popup;

    unsigned int getChannels();

signals:
    void requestSweptsine(mavlink_signal_sweptsine_t sweptsine);
    void requestMultisine(mavlink_signal_multisine_t multisine);
    void requestSteppedsine(mavlink_signal_steppedsine_t steppedsine);
    void requestEvent(mavlink_event_t event);

private slots:
    void on_set_pushButton_clicked();
    void on_disable_pushButton_clicked();

};

#endif // QEXCITATIONDIALOG_H
