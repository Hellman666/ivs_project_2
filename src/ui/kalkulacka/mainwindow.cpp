#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #3c6e71;");
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    ui->Rest_of_number->setStyleSheet("QLineEdit {color: white; background-color: #284b63; padding: 10px; color: white; border-width: 2px; border-radius: 15px; border-color: #b8cbd8; }");
    ui->Display->setStyleSheet("QLineEdit {color: white; background-color: #284b63; padding: 10px; color: white; border-style: outset; border-width: 2px; border-radius: 15px; border-color: #b8cbd8; }");
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_Number0_clicked()
{
    qDebug() <<"0";
}


void MainWindow::on_Number1_clicked()
{
    qDebug() <<"1";
}



void MainWindow::on_Number2_clicked()
{
    qDebug() <<"2";
}


void MainWindow::on_Number3_clicked()
{
    qDebug() <<"3";
}


void MainWindow::on_Number4_clicked()
{
    qDebug() <<"4";
}


void MainWindow::on_Number5_clicked()
{
    qDebug() <<"5";
}


void MainWindow::on_Number6_clicked()
{
    qDebug() <<"6";
}


void MainWindow::on_Number7_clicked()
{
    qDebug() <<"7";
}


void MainWindow::on_Number8_clicked()
{
    qDebug() <<"8";
}


void MainWindow::on_Number9_clicked()
{
    qDebug() <<"9";
}


void MainWindow::on_Dot_clicked()
{
    qDebug() <<".";
}


void MainWindow::on_Equals_clicked()
{
    qDebug() <<"=";
}


void MainWindow::on_Div_clicked()
{
    qDebug() <<"/";
}


void MainWindow::on_Mul_clicked()
{
    qDebug() <<"x";
}


void MainWindow::on_Minus_clicked()
{
    qDebug() <<"-";
}


void MainWindow::on_Plus_clicked()
{
    qDebug() <<"+";
}


void MainWindow::on_Root_clicked()
{
    qDebug() <<"√";
}


void MainWindow::on_Power_clicked()
{
    qDebug() <<"^";
}


void MainWindow::on_Right_bracket_clicked()
{
    qDebug() <<")";
}


void MainWindow::on_Left_bracket_clicked()
{
    qDebug() <<"(";
}


void MainWindow::on_Idiv_clicked()
{
    qDebug() <<"//";
}


void MainWindow::on_Fact_clicked()
{
    qDebug() <<"!";
}


void MainWindow::on_Clear_clicked()
{
    qDebug() <<"C";
}


void MainWindow::on_Backspace_clicked()
{
    qDebug() <<"<-";
}

