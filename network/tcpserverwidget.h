#ifndef TCPSERVERWIDGET_H
#define TCPSERVERWIDGET_H

#include <QWidget>
#include <QtNetwork>

namespace Ui {
class TcpServerWidget;
}

class TcpServerWidget : public QWidget
{
  Q_OBJECT

public:
  explicit TcpServerWidget(QWidget *parent = 0);
  ~TcpServerWidget();

  void startServer(quint16 port);

public slots:
  // Detected a new connection from a new client
  void newConnection();
  // Detected that a client has been disconnected
  void clearDisconnection();
  // Will read a message that has arrived from a client and repass it to all other clients
  void readMessage();

private:
  Ui::TcpServerWidget *ui;

  QTcpServer *tcpServer;

  QList<QTcpSocket*> connections;

  void processInput(const QString &input);
  void broadcastString(QString output);
};

#endif // TCPSERVERWIDGET_H
