#ifndef QABOUTDIALOG_H
#define QABOUTDIALOG_H

#include <QDialog>
#include <QPixmap>

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

private:
    Ui::QAboutDialog *ui;
};

#endif // QABOUTDIALOG_H
