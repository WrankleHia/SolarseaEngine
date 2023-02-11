#ifndef SE_MAINWINDOW_H
#define SE_MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SE_MainWindow; }
QT_END_NAMESPACE

class SE_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    SE_MainWindow(QWidget *parent = nullptr);
    ~SE_MainWindow();

private:
    Ui::SE_MainWindow *ui;
};
#endif // SE_MAINWINDOW_H
