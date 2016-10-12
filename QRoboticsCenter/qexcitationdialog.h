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

private slots:
    void on_set_pushButton_clicked();
    void on_disable_pushButton_clicked();

signals:
    void setExcitation(int type, int channels, double var1, double var2, double var3, double var4);

};

#endif // QEXCITATIONDIALOG_H
