#ifndef GAMEAREAWIDGET_H
#define GAMEAREAWIDGET_H

#include <QWidget>

namespace Ui {
class GameAreaWidget;
}

class GameAreaWidget : public QWidget
{
  Q_OBJECT

public:
  explicit GameAreaWidget(QWidget *parent = 0);
  ~GameAreaWidget();

private:
  Ui::GameAreaWidget *ui;
};

#endif // GAMEAREAWIDGET_H
