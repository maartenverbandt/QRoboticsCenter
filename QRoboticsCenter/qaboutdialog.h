#ifndef QABOUTDIALOG_H
#define QABOUTDIALOG_H

#include <QDialog>
#include <QPixmap>
#include <QApplication>
#include <QAction>

namespace Ui {
class QAboutDialog;
}

class QAboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QAboutDialog(QWidget *parent = 0);
    ~QAboutDialog();

    void setApplicationTitle(QString application_title);
    void setVersion(QString version_number);
    void setCopyright(QString copyright);
    void setLink(QString link);
    void setIcon(QString image_path);
    void setIcon(QIcon icon);

private:
    Ui::QAboutDialog *ui;
};

class QShowAboutDialogAction : public QAction
{
    Q_OBJECT
public:
    explicit QShowAboutDialogAction(QObject *parent = 0);

    void showDialog();

};

#endif // QABOUTDIALOG_H
