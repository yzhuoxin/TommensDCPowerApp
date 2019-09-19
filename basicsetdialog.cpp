#include "basicsetdialog.h"
#include "ui_basicsetdialog.h"

basicSetDialog::basicSetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::basicSetDialog)
{
    ui->setupUi(this);
}

basicSetDialog::~basicSetDialog()
{
    delete ui;
}
