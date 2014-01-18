#include "tcpserverwidget.h"
#include "ui_tcpserverwidget.h"

#include "common.h"

#include <QMessageBox>
#include <QTime>


TcpServerWidget::TcpServerWidget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::TcpServerWidget),
  tcpServer(NULL)
{
  qsrand(QTime::currentTime().msec());
  ui->setupUi(this);
}

TcpServerWidget::~TcpServerWidget()
{
  delete ui;
}

void TcpServerWidget::startServer(quint16 port)
{
  qDebug() << "server started" << port;
  tcpServer = new QTcpServer(this);
  if (!tcpServer->listen(/*QHostAddress::Any*/QHostAddress("127.0.0.1"),port)) {
  //if (!tcpServer->listen(QHostAddress(address),port)) {
    QMessageBox::critical(this, tr("TCP Server"),
                          tr("Unable to start the server: %1.")
                          .arg(tcpServer->errorString()));
  }
  connect(tcpServer,SIGNAL(newConnection()),this,SLOT(newConnection()));
  ui->ip_label->setText( tcpServer->serverAddress().toString() );
  ui->port_label->setText( QString::number(tcpServer->serverPort()) );
}

void TcpServerWidget::newConnection()
{
  qDebug() << "new connection detected";
  QTcpSocket *newSocket = tcpServer->nextPendingConnection();
  connect(newSocket,SIGNAL(disconnected()),this,SLOT(clearDisconnection()));
  connect(newSocket,SIGNAL(readyRead()),this,SLOT(readMessage()));
  connections.push_back(newSocket);
}

void TcpServerWidget::clearDisconnection()
{
  QTcpSocket *socket = (QTcpSocket*)sender();

  delete socket;
  connections.removeOne(socket);
}

void TcpServerWidget::readMessage()
{
  qDebug() << "message read";
  QTcpSocket *socket = (QTcpSocket*)sender();
  QByteArray data = socket->readAll();
  QString incoming_string(data);

  qDebug() << "process input";

  processInput(incoming_string);

  qDebug() << "done";
}

void TcpServerWidget::processInput(const QString &input)
{
  QString output = input;

  int input_code = input.left(3).toInt();

  switch(input_code){
    case MESSAGE_TEXT:
    break;
    default:
    break;
  }

  if( input.startsWith("DICEROLL")){
    output = "MESSAGE user_name Dice roll: "+QString::number((qrand()%6)+1)+" (1-6)";
  }

  broadcastString(output);
}

void TcpServerWidget::broadcastString(QString output)
{
  qDebug() << "broadcast";
  QByteArray data;
  data.append(output);
  for(int i=0;i<connections.size();i++){
    connections.at(i)->write(data);
    connections.at(i)->flush();
  }
}
