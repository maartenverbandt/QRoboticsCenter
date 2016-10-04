#include "qaboutdialog.h"
#include "ui_qaboutdialog.h"

QAboutDialog::QAboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QAboutDialog)
{
    ui->setupUi(this);
}

QAboutDialog::~QAboutDialog()
{
    delete ui;
}
