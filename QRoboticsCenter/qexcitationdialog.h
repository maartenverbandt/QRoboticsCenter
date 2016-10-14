#ifndef QEXCITATIONDIALOG_H
#define QEXCITATIONDIALOG_H

#include <QDialog>
#include <QComboBox>
#include <QAction>

typedef enum excitation_type_t {
    EXCITATION_SWEPTSINE,
    EXCITATION_MULTISINE,
    EXCITATION_STEPPEDSINE,
    EXCITATION_STOPPED = 255
} excitation_type_t;

namespace Ui {
class QExcitationDialog;
}

class QExcitationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QExcitationDialog(QWidget *parent = 0);
    ~QExcitationDialog();

    QAction* getPopupAction();

private:
    Ui::QExcitationDialog *ui;
    QComboBox* _channels[8];
    QAction* _popup;

    unsigned int getChannels();

private slots:
    void on_set_pushButton_clicked();
    void on_disable_pushButton_clicked();

signals:
    void requestSweptsine(unsigned int channels, double fmin, double fmax, double period, double amplitude);
    void requestMultisine(unsigned int channels, int id, double amplitude);
    void requestSteppedsine(unsigned int channels, double fmin, double fmax, int period, double amplitude);
    void requestStopExcitation();
};

#endif // QEXCITATIONDIALOG_H
