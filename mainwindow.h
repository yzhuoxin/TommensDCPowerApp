#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "writecomlogs.h"
#include <QListWidget>
#include <QSystemTrayIcon>
#include <QMenu>
#include "basicsetdialog.h"
enum ListICOStatus { ICODPowerOn, ICODPowerOFF, ICODWaring,ICODError,ICODCheck };

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static QString  tomAppPath;
    static WriteCOMlogs * WriteApplog;
    static  QString logfilepath;
    static QString databasePath;
    static QString xmlfilePath;

    void  addDeviceToListWidget(QString AddDeviceName);
    void  setDeviceICO( QListWidgetItem *indexDeviceItem,ListICOStatus dIcoStatus);
private slots:



    void on_Auto_QpushButton_clicked();

    void on_stop_QpushButton_clicked();


protected:
    void menuAddSeparator(QMenu * PerMenu);
    void show_mainFrom();
    void show_base_set_fm();
    void show_port_set_fm();
    void show_safetyValue_set_fm();
    void show_deviceAddressMod_fm();
    void show_analysisSampData_fm();
    void show_manageSampData_fm();
    void show_exportSampData_fm();
    void show_autoControlSet_fm();
    void show_shortcutButtonset_fm();
    void exit_mainform();
private:
    Ui::MainWindow *ui;
    //////////////////////////////////////////////////////////////////////////
    // systemtrayico and menu
    QSystemTrayIcon   *m_systemTray;//systemTrayico
    QMenu * mainMenu;

    //menu items
    QAction * showMainFormAction;
    QAction * basicSetAction;
    QAction * portSetAction;
    QAction * safetyValueSetAction;
    QAction * deviceAddressModAction;
    QAction * analysisSampDataAction;
    QAction * manageSampDataAction;
    QAction * exportSampDataAction;
    QAction * autoControlSetAction;
    QAction * shortcutButtonsetAction;
    QAction * exitAction;

};

#endif // MAINWINDOW_H
