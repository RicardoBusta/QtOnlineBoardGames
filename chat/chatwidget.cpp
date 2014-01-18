#include "chatwidget.h"
#include "ui_chatwidget.h"

ChatWidget::ChatWidget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::ChatWidget)
{
  ui->setupUi(this);

  connect(ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(sendText()));
  connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(sendText()));

  ui->splitter->setStretchFactor(0, 1);
  ui->splitter->setStretchFactor(1, 100);
}

ChatWidget::~ChatWidget()
{
  delete ui;
}

void ChatWidget::sendText()
{
  emit textSent(ui->lineEdit->text());

  ui->lineEdit->clear();
}

void ChatWidget::textReceived(QString txt)
{
  ui->textEdit->append(txt);
}
