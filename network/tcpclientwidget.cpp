#include "tcpclientwidget.h"
#include "ui_tcpclientwidget.h"

#include "common.h"

TcpClientWidget::TcpClientWidget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::TcpClientWidget),
  tcpSocket(NULL)
{
  ui->setupUi(this);
}

TcpClientWidget::~TcpClientWidget()
{
  delete ui;
}

void TcpClientWidget::connectSocket(QString hostAddress, quint16 port)
{
  qDebug() << "client connected" << hostAddress << port;
  tcpSocket = new QTcpSocket(this);

  this->address = hostAddress;
  this->port = QString::number(port);

  connect(tcpSocket,SIGNAL(connected()),this,SLOT(connected()));
  connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readMessage()));
  tcpSocket->connectToHost(/*QHostAddress(hostAddress)*/"127.0.0.1",port);
}

void TcpClientWidget::setUserName(QString userName)
{
  this->userName = userName;
}

void TcpClientWidget::sendStringToHost(QString txt)
{
  QByteArray data;
  data.append(txt);
  tcpSocket->write(data);
  tcpSocket->flush();
}

void TcpClientWidget::connected()
{ 
  ui->ip_label->setText(address);
  ui->port_label->setText(port);
}

void TcpClientWidget::readMessage()
{
  QByteArray data = tcpSocket->readAll();
  QString incoming_string(data);

  if(incoming_string.startsWith("MESSAGE")){
    emit textMessage(incoming_string);
  }
}

void TcpClientWidget::sendTextMessage(QString txt)
{
  QString out;
  if(txt.startsWith("/roll")){
    out = "DICEROLL user_name 1 6"+txt;
  }else{
    out = "MESSAGE user_name "+txt;
  }

  if(out != ""){
    sendStringToHost(out);
  }
}
