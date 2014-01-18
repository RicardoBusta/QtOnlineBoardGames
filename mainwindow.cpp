#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "network/tcpserverwidget.h"
#include "network/tcpclientwidget.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  connect(ui->host_pushButton,SIGNAL(clicked()),this,SLOT(hostServer()));
  connect(ui->join_pushButton,SIGNAL(clicked()),this,SLOT(joinServer()));

  ui->splitter->setStretchFactor(0, 100);
  ui->splitter->setStretchFactor(1, 1);

  ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::hostServer()
{
  TcpServerWidget *serverWidget = new TcpServerWidget();
  serverWidget->setVisible(true);
  ui->connection_widget->layout()->addWidget(serverWidget);
  ui->stackedWidget->setCurrentIndex(1);

  //serverWidget->startServer(ui->host_ip_lineEdit->text(),ui->port_lineEdit->text().toUInt());
  serverWidget->startServer(ui->port_lineEdit->text().toUInt());

  joinServer();
}
#include <QTcpSocket>

void MainWindow::joinServer()
{
  clientWidget = new TcpClientWidget(ui->connection_widget);
  clientWidget->setVisible(true);
  clientWidget->setUserName(ui->nickName_lineEdit->text());

  ui->connection_widget->layout()->addWidget(clientWidget);
  ui->stackedWidget->setCurrentIndex(1); 

  connect(ui->chatWidget,SIGNAL(textSent(QString)),clientWidget,SLOT(sendTextMessage(QString)));
  connect(clientWidget,SIGNAL(textMessage(QString)),ui->chatWidget,SLOT(textReceived(QString)));

  //clientWidget->connectSocket(ui->host_ip_lineEdit->text(),ui->port_lineEdit->text().toUInt());
  clientWidget->connectSocket(ui->host_ip_lineEdit->text(),ui->port_lineEdit->text().toUInt());
}
