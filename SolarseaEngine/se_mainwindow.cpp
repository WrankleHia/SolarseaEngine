#include "se_mainwindow.h"
#include "ui_se_mainwindow.h"

SE_MainWindow::SE_MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SE_MainWindow)
{
    ui->setupUi(this);
}

SE_MainWindow::~SE_MainWindow()
{
    delete ui;
}

