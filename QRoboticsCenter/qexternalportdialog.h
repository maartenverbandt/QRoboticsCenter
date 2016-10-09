#ifndef QEXTERNALPORTDIALOG_H
#define QEXTERNALPORTDIALOG_H

#include <QDialog>
#include <QLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <QStackedWidget>

class QExternalPortDialog : public QDialog
{
    Q_OBJECT
public:
    explicit QExternalPortDialog(QObject *parent = 0);

protected:
    addWidget(QWidget* w, QString name);

private:
    QHBoxLayout* _layout;
    QVBoxLayout* _button_layout;
    QButtonGroup* _buttons;
    QStackedWidget* _stack;

    void layoutSetup();

signals:

public slots:
};

#endif // QEXTERNALPORTDIALOG_H
