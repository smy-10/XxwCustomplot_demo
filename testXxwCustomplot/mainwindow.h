#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "XxwCustomPlot.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void resizeEvent(QResizeEvent *event);
private:
    Ui::MainWindow *ui;
    XxwCustomPlot* plot;
};

#endif // MAINWINDOW_H
