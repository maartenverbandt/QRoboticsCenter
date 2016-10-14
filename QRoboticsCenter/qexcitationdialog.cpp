#include "qexcitationdialog.h"
#include "ui_qexcitationdialog.h"

QExcitationDialog::QExcitationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QExcitationDialog),
    _popup(new QAction("Excitation",this))
{
    ui->setupUi(this);

    QObject::connect(ui->excitation_selection_comboBox,SIGNAL(currentIndexChanged(int)),ui->stackedWidget,SLOT(setCurrentIndex(int)));
    ui->excitation_selection_comboBox->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(0);

    for(int k=0;k<8;k++){
        _channels[k] = new QComboBox(this);
        _channels[k]->addItem("0%",0);
        _channels[k]->addItem("25%",1);
        _channels[k]->addItem("50%",2);
        _channels[k]->addItem("100%",3);
        _channels[k] ->setCurrentIndex(0);
        ui->channels_formLayout->addRow("ch" + QString::number(k+1), _channels[k]);
    }

    QObject::connect(_popup,SIGNAL(triggered(bool)),this,SLOT(show()));
}

QExcitationDialog::~QExcitationDialog()
{
    delete ui;
}

QAction *QExcitationDialog::getPopupAction()
{
    return _popup;
}

unsigned int QExcitationDialog::getChannels()
{
    unsigned int channels = 0;
    for(int k=0;k<8;k++){
        channels |= ((u_int8_t)(_channels[k]->currentIndex()) << (k<<1));
    }
    return channels;
}

void QExcitationDialog::on_set_pushButton_clicked()
{
    switch(ui->excitation_selection_comboBox->currentIndex()){
        case EXCITATION_SWEPTSINE:
            emit requestSweptsine(getChannels(), ui->doubleSpinBox_fl->value(), ui->doubleSpinBox_fh->value(), ui->doubleSpinBox_T->value(), ui->doubleSpinBox_A->value());
            break;
        case EXCITATION_MULTISINE:
            emit requestMultisine(getChannels(), ui->multisine_spinBox->value(), ui->musin_gain_doubleSpinBox->value());
            break;
        case EXCITATION_STEPPEDSINE:
            emit requestSteppedsine(getChannels(), ui->doubleSpinBox_fl_2->value(), ui->doubleSpinBox_fh_2->value(), ui->doubleSpinBox_T_2->value(), ui->doubleSpinBox_A_2->value());
            break;
    }
}

void QExcitationDialog::on_disable_pushButton_clicked()
{
    emit requestStopExcitation();
}
