#ifndef QEXTERNALPORTDIALOG_H
#define QEXTERNALPORTDIALOG_H

#include <QDialog>
#include <QLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <QStackedWidget>
#include <QAction>

class QExternalPortDialog : public QDialog
{
    Q_OBJECT
public:
    explicit QExternalPortDialog(QString name, QWidget *parent = 0);
    ~QExternalPortDialog();

    void addPort(QWidget* w, QString name);
    QAction* getPopupAction();

private:
    QAction* _popup;

    QHBoxLayout* _layout;
    QVBoxLayout* _button_layout;
    QButtonGroup* _buttons;
    QStackedWidget* _stack;

    void layoutSetup();

signals:

public slots:
};

#endif // QEXTERNALPORTDIALOG_H
