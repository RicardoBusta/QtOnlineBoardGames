#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>

class MainWindow;

class Application : public QApplication
{
    Q_OBJECT
public:
    explicit Application(int argc, char **argv);

private:
    MainWindow* mainWindow;

signals:

public slots:

};

#endif // APPLICATION_H
