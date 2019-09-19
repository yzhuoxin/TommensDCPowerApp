#include "mainwindow.h"
#include "ui_mainwindow.h"


QString MainWindow::tomAppPath="";
QString MainWindow::logfilepath="";
QString MainWindow::databasePath="";
WriteCOMlogs *MainWindow::WriteApplog=nullptr;
QString MainWindow::xmlfilePath="";
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    tomAppPath=qApp->applicationDirPath();
    logfilepath=tomAppPath+("\\log\\");
    databasePath=tomAppPath+"\\Database\\";
    xmlfilePath=tomAppPath+"\\setting\\";
   //start create Menu and systemtrayico
       m_systemTray = new QSystemTrayIcon(this);
        mainMenu = new QMenu(this);

        showMainFormAction = new QAction(mainMenu);
        showMainFormAction->setText(tr("显示主窗口"));
        mainMenu->addAction(showMainFormAction);
        connect(showMainFormAction, &QAction::triggered, this, &MainWindow::show_mainFrom);
         menuAddSeparator(mainMenu);

        basicSetAction = new QAction(mainMenu);
        basicSetAction->setText(tr("基本设置"));
        mainMenu->addAction(basicSetAction);
        connect(basicSetAction, &QAction::triggered, this, &MainWindow::show_base_set_fm);
        portSetAction= new  QAction(mainMenu);
        portSetAction->setText(tr("采集端口设置"));
        mainMenu->addAction(portSetAction);
        connect(portSetAction, &QAction::triggered, this, &MainWindow::show_port_set_fm);

         menuAddSeparator(mainMenu);

        safetyValueSetAction = new QAction(mainMenu);
        safetyValueSetAction->setText(tr("安全值设置"));
        mainMenu->addAction(safetyValueSetAction);
       connect(safetyValueSetAction, &QAction::triggered, this, &MainWindow::show_safetyValue_set_fm);

        deviceAddressModAction=new QAction(mainMenu);
        deviceAddressModAction->setText(tr("设备地址码修改"));
        mainMenu->addAction(deviceAddressModAction);
        connect(deviceAddressModAction, &QAction::triggered, this, &MainWindow::show_deviceAddressMod_fm);
        menuAddSeparator(mainMenu);

        analysisSampDataAction=new QAction(mainMenu);
        analysisSampDataAction->setText(tr("采集数据分析"));
        mainMenu->addAction(analysisSampDataAction);
         connect(analysisSampDataAction, &QAction::triggered, this, &MainWindow::show_analysisSampData_fm);

        manageSampDataAction=new QAction(mainMenu);
        manageSampDataAction->setText(tr("采集数据管理"));
        mainMenu->addAction(manageSampDataAction);
         connect(manageSampDataAction, &QAction::triggered, this, &MainWindow::show_manageSampData_fm);

        exportSampDataAction =new QAction(mainMenu);
        exportSampDataAction->setText(tr("导出采样数据"));
        mainMenu->addAction(exportSampDataAction);
        connect(exportSampDataAction, &QAction::triggered, this, &MainWindow::show_exportSampData_fm);

          menuAddSeparator(mainMenu);

        autoControlSetAction=new QAction(mainMenu);
        autoControlSetAction->setText(tr("自动化输出控制设置"));
        mainMenu->addAction(autoControlSetAction);
         connect(autoControlSetAction, &QAction::triggered, this, &MainWindow::show_autoControlSet_fm);

        shortcutButtonsetAction=new QAction(mainMenu);
        shortcutButtonsetAction->setText(tr("快捷键设置"));
        mainMenu->addAction(shortcutButtonsetAction);
        connect(shortcutButtonsetAction, &QAction::triggered, this, &MainWindow::show_shortcutButtonset_fm);
          menuAddSeparator(mainMenu);

        exitAction=new QAction(mainMenu);
        exitAction->setText(tr("退出"));
        mainMenu->addAction(exitAction);
       connect(exitAction, &QAction::triggered, this, &MainWindow::exit_mainform);

        m_systemTray->setContextMenu(mainMenu);
        m_systemTray->setIcon(QIcon(tomAppPath+"\\images\\bitbug_favicon.ico"));
        m_systemTray->setToolTip(tr("直流电源软件"));
        m_systemTray->show();

    ui->setupUi(this);

    //start process the log
    WriteApplog=new WriteCOMlogs();
    WriteApplog->startLog();

     ui->AutoControl_QTableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
     ui->AutoControl_QTableWidget->horizontalHeader()->resizeSection(0,220); //设置表头第一列的宽度为220
     ui->AutoControl_QTableWidget->horizontalHeader()->resizeSection(6,150); //设置表头第6列的宽度为150
     ui->AutoControl_QTableWidget->horizontalHeader()->setFixedHeight(25); //设置表头的高度
     //setico

    //      ui->Auto_QpushButton->setIcon(QIcon("contact_48.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::menuAddSeparator(QMenu * PerMenu)
{
    QAction *action = new QAction(PerMenu);
        action->setSeparator(true);
        PerMenu->addAction(action);

}

void MainWindow::show_mainFrom()
{

}
void MainWindow::show_base_set_fm()
{
      basicSetDialog *  basicSetForm=new basicSetDialog(this);
      basicSetForm->setAttribute(Qt::WA_DeleteOnClose);
      basicSetForm->show();
}
void MainWindow::show_port_set_fm()
{}
void MainWindow::show_safetyValue_set_fm()
{}

void MainWindow::show_deviceAddressMod_fm()
{}
void MainWindow:: show_analysisSampData_fm(){}
void MainWindow::show_manageSampData_fm(){}
void  MainWindow::show_exportSampData_fm(){}
void  MainWindow::show_autoControlSet_fm(){}
void  MainWindow::show_shortcutButtonset_fm(){}
void  MainWindow::exit_mainform()
{
 qApp->exit();
}





void MainWindow::on_Auto_QpushButton_clicked()
{
   // ui->lcdNumber_2->display("000000");
    //QString::arg ( int a, int fieldWidth = 0, int base = 10, const QChar & fillChar = QLatin1Char( ' ' ) ) const
    double ageti=101.1255454;
    QString agestr= QString("%1").arg(ageti, 4, 'g', 4,QLatin1Char('0'));
   // QString agestr=QString("%1").arg(ageti,3,10, QLatin1Char('0'));

   // ui->V_QLCDNumber->setSegmentStyle(QLCDNumber::Flat);
    ui->V_QLCDNumber->setSmallDecimalPoint(true);
    ui->V_QLCDNumber->display(agestr);
    addDeviceToListWidget(tr("厂家大u部队良好默认设备1"));

}
void MainWindow::setDeviceICO(QListWidgetItem *indexDeviceItem,ListICOStatus dIcoStatus)
{
   if (indexDeviceItem!=NULL)
   {
    QString icoName="\\images\\deviceOFF.png";
    switch(dIcoStatus)
   {
    case ICODPowerOn:
        icoName="\\images\\deviceON.png";
        break;
    case ICODPowerOFF:
        icoName="\\images\\deviceOFF.png";
        break;
    case  ICODWaring:
        icoName="\\images\\deviceWarning.png";
        break;
    case ICODError:
         icoName="\\images\\deviceError.png";
        break;
     case ICODCheck:
        icoName="\\images\\deviceCheck.png";
        break;
    }
    indexDeviceItem->setIcon(QIcon(tomAppPath+icoName));
}
}


void MainWindow::addDeviceToListWidget(QString AddDeviceName)
{
    QSize ICON_SIZE = QSize(84,32);
    QSize CELL_SIZE = QSize(84,84);
    ui->Device_QListWidget->setIconSize(ICON_SIZE);


         ui->Device_QListWidget->setResizeMode(QListView::Adjust);
        ui->Device_QListWidget->setViewMode(QListView::IconMode);
        ui->Device_QListWidget->setMovement(QListView::Static);

        ui->Device_QListWidget->setSpacing(20);
        ui->Device_QListWidget->setWordWrap(true);
         QListWidgetItem *DeviceItem=new QListWidgetItem;
         DeviceItem->setSizeHint(CELL_SIZE);
         DeviceItem->setIcon(QIcon(tomAppPath+"\\images\\deviceOFF.png"));
         DeviceItem->setText(AddDeviceName);
         DeviceItem->setTextAlignment(Qt::AlignVCenter);

         DeviceItem->setToolTip(DeviceItem->text());
         ui->Device_QListWidget->addItem(DeviceItem);
}

void MainWindow::on_stop_QpushButton_clicked()
{

  qDebug("This is a debug message.");



   // setDeviceICO(ui->Device_QListWidget->currentItem(),ICODError);
}
