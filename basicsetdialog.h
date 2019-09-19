#ifndef BASICSETDIALOG_H
#define BASICSETDIALOG_H

#include <QDialog>

namespace Ui {
class basicSetDialog;
}

class basicSetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit basicSetDialog(QWidget *parent = nullptr);
    ~basicSetDialog();

private:
    Ui::basicSetDialog *ui;
};

#endif // BASICSETDIALOG_H
