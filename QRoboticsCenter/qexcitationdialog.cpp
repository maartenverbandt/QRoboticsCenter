#include "qexcitationdialog.h"
#include "ui_qexcitationdialog.h"

QExcitationDialog::QExcitationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QExcitationDialog),
    _popup(new QAction("Excitation",this))
{
    ui->setupUi(this);

    QObject::connect(ui->excitation_selection_comboBox,SIGNAL(currentIndexChanged(int)),ui->stackedWidget,SLOT(setCurrentIndex(int)));
    ui->excitation_selection_comboBox->setCurrentIndex(1);
    ui->stackedWidget->setCurrentIndex(1);

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

void QExcitationDialog::connect(QBalancingConnectionManager *c)
{
    QObject::connect(this,&QExcitationDialog::requestEvent,c,&QBalancingConnectionManager::eventMsgSend);
    QObject::connect(this,&QExcitationDialog::requestSweptsine,c,&QBalancingConnectionManager::signalSweptsineMsgSend);
    QObject::connect(this,&QExcitationDialog::requestMultisine,c,&QBalancingConnectionManager::signalMultisineMsgSend);
    QObject::connect(this,&QExcitationDialog::requestSteppedsine,c,&QBalancingConnectionManager::signalSteppedsineMsgSend);
}

QAction *QExcitationDialog::getPopupAction()
{
    return _popup;
}

unsigned int QExcitationDialog::getChannels()
{
    unsigned int channels = 0;
    for(int k=0;k<8;k++){
        channels |= ((quint8)(_channels[k]->currentIndex()) << (k<<1));
    }
    return channels;
}

void QExcitationDialog::on_set_pushButton_clicked()
{
    switch(ui->excitation_selection_comboBox->currentIndex()){
        case 0:
            mavlink_signal_sweptsine_t sweptsine;
            sweptsine.channels = getChannels();
            sweptsine.fmin = ui->doubleSpinBox_fl->value();
            sweptsine.fmax = ui->doubleSpinBox_fh->value();
            sweptsine.period = ui->doubleSpinBox_T->value();
            sweptsine.amplitude = ui->doubleSpinBox_A->value();
            emit requestSweptsine(sweptsine);
            break;
        case 1:
            mavlink_signal_multisine_t multisine;
            multisine.channels = getChannels();
            multisine.id = ui->multisine_spinBox->value();
            multisine.amplitude = ui->musin_gain_doubleSpinBox->value();
            emit requestMultisine(multisine);
            break;
        case 2:
            mavlink_signal_steppedsine_t steppedsine;
            steppedsine.channels = getChannels();
            steppedsine.fmin = ui->doubleSpinBox_fl_2->value();
            steppedsine.fmax = ui->doubleSpinBox_fh_2->value();
            steppedsine.period = ui->doubleSpinBox_T_2->value();
            steppedsine.amplitude = ui->doubleSpinBox_A_2->value();
            emit requestSteppedsine(steppedsine);
            break;
    }
}

void QExcitationDialog::on_disable_pushButton_clicked()
{
    mavlink_event_t event;
    event.type = 310; //stop excitation
    emit requestEvent(event);
}
