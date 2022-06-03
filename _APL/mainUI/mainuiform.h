#ifndef MAINUIFORM_H
#define MAINUIFORM_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class mainUIForm; }
QT_END_NAMESPACE

class mainUIForm : public QMainWindow
{
    Q_OBJECT

public:
    mainUIForm(QWidget *parent = nullptr);
    ~mainUIForm();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::mainUIForm *ui;
};
#endif // MAINUIFORM_H
