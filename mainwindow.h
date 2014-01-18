#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class TcpServerWidget;
class TcpClientWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
  void hostServer();
  void joinServer();

private:
    Ui::MainWindow *ui;

    TcpServerWidget *serverWidget;
    TcpClientWidget *clientWidget;
};

#endif // MAINWINDOW_H
