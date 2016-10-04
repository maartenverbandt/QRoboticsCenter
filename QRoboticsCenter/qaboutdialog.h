#ifndef QABOUTDIALOG_H
#define QABOUTDIALOG_H

#include <QDialog>

namespace Ui {
class QAboutDialog;
}

class QAboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QAboutDialog(QWidget *parent = 0);
    ~QAboutDialog();

private:
    Ui::QAboutDialog *ui;
};

#endif // QABOUTDIALOG_H
