#ifndef TCPCLIENTWIDGET_H
#define TCPCLIENTWIDGET_H

#include <QWidget>
#include <QtNetwork>

namespace Ui {
class TcpClientWidget;
}

class TcpClientWidget : public QWidget
{
  Q_OBJECT

public:
  explicit TcpClientWidget(QWidget *parent = 0);
  ~TcpClientWidget();

  void connectSocket(QString hostAddress, quint16 port);

  void setUserName(QString userName);
  void sendStringToHost(QString txt);
signals:
  void textMessage(QString);

public slots:
  // The client sucessfully connected to the host
  void connected();
  // The host sent a message to the client. It must be processed.
  void readMessage();

  // Sends the text message to the host.
  void sendTextMessage(QString txt);

private:
  Ui::TcpClientWidget *ui;

  QTcpSocket *tcpSocket;

  QString userName;

  QString address;
  QString port;
};

#endif // TCPCLIENTWIDGET_H
