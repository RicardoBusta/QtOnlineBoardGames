#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QWidget>

namespace Ui {
class ChatWidget;
}

class ChatWidget : public QWidget
{
  Q_OBJECT

public:
  explicit ChatWidget(QWidget *parent = 0);
  ~ChatWidget();

signals:
  void textSent(QString);

protected slots:
  // User pressed enter to send the text to the server
  void sendText();

  void textReceived(QString txt);

private:
  Ui::ChatWidget *ui;
};

#endif // CHATWIDGET_H
