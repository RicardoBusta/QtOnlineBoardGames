#include "gameareawidget.h"
#include "ui_gameareawidget.h"

#include "gameobjectgraphicitem.h"

GameAreaWidget::GameAreaWidget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::GameAreaWidget)
{
  ui->setupUi(this);

  ui->listWidget->addItem(new QListWidgetItem(QIcon("://images/board.png"),"board"));
  ui->listWidget->addItem(new QListWidgetItem(QIcon("://images/black.png"),"black"));
  ui->listWidget->addItem(new QListWidgetItem(QIcon("://images/white.png"),"white"));

  ui->graphicsWidget->setScene(new QGraphicsScene());
  GameObject *gameObject = new GameObject;
  gameObject->id = 0;
  gameObject->position = QPoint(0,0);
  gameObject->imageURL = "://images/board.png";
  ui->graphicsWidget->scene()->addItem(new GameObjectGraphicItem());

  ui->splitter->setStretchFactor(0, 1);
  ui->splitter->setStretchFactor(1, 100);
}

GameAreaWidget::~GameAreaWidget()
{
  delete ui;
}
