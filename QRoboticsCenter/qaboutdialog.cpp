#include "qaboutdialog.h"
#include "ui_qaboutdialog.h"

QAboutDialog::QAboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QAboutDialog)
{
    // Setup dialog
    ui->setupUi(this);
    setWindowTitle("About");
    setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    setModal(true); //make it a blocking widget
    setAttribute(Qt::WA_DeleteOnClose);

    // Get info from application
    setApplicationTitle(QApplication::applicationName());
    setVersion(QApplication::applicationVersion());
    setIcon(QApplication::windowIcon());
}

QAboutDialog::~QAboutDialog()
{
    delete ui;
}

void QAboutDialog::setApplicationTitle(QString application_title)
{
    ui->title_label->setText(application_title);
}

void QAboutDialog::setVersion(QString version_number)
{
    ui->version_label->setText("Version: " + version_number);
}

void QAboutDialog::setCopyright(QString copyright)
{
    ui->copyright_label->setText(copyright);
}

void QAboutDialog::setLink(QString link)
{
    ui->link_label->setText(link);
}

void QAboutDialog::setIcon(QString image_path)
{
    QPixmap pixmap(image_path);
    ui->icon_label->setPixmap(pixmap.scaled(ui->icon_label->rect().size(),Qt::KeepAspectRatio));
}

void QAboutDialog::setIcon(QIcon icon)
{
    QPixmap pixmap = icon.pixmap(ui->icon_label->rect().width(),ui->icon_label->rect().height());
    ui->icon_label->setPixmap(pixmap.scaled(ui->icon_label->rect().size(),Qt::KeepAspectRatio));
}



QShowAboutDialogAction::QShowAboutDialogAction(QObject *parent) :
    QAction("about",parent)
{
    QObject::connect(this, &QShowAboutDialogAction::triggered, this, &QShowAboutDialogAction::showDialog);
}

void QShowAboutDialogAction::showDialog()
{
    QDialog *d = new QAboutDialog(0);
    d->show();
}
