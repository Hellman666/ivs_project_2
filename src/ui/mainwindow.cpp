#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

double calcValidation;
bool divide = false;
bool plus = false;
bool minus = false;
bool mul = false;
bool root = false;
bool idiv = false;
bool fact = false;
bool dot = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #3c6e71;");
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    ui->Rest_of_number->setStyleSheet("QLineEdit {color: white; background-color: #284b63; padding: 10px; color: white; border-width: 2px; border-radius: 15px; border-color: #b8cbd8; }");
    ui->Display->setStyleSheet("QLineEdit {color: white; background-color: #284b63; padding: 10px; color: white; border-style: outset; border-width: 2px; border-radius: 15px; border-color: #b8cbd8; }");

    // Will hold references to all the number buttons
    QPushButton *num[10];

    // Cycle through locating the buttons
    for(int i = 0; i < 10; ++i){
        QString buttonName = "Number" + QString::number(i);

        // Get the buttons by name and add to array
        num[i] = MainWindow::findChild<QPushButton *>(buttonName);

        // When the button is released call num_pressed()
        connect(num[i], SIGNAL(released()), this, SLOT(NumPressed()));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::NumPressed(){

    // Sender returns a pointer to the button pressed
    QPushButton *button = (QPushButton *)sender();

    // Get number on button
    QString butonValidation = button->text();

    // Get the value in the display
    QString displayValidation = ui->Display->text();

    if((displayValidation.toDouble() == 0) || (displayValidation.toDouble() == 0.0)){

        // calcVal = butonValidation.toDouble();
        ui->Display->setText(butonValidation);

    } else {
        // Put the new number to the right of whats there
        QString newValidation = displayValidation + butonValidation;

        // Double version of number
        double dblNewValidation = newValidation.toDouble();

        //calcValidation = newValidation.toDouble();

        // Set value in display and allow up to 16
        // digits before using exponents
        ui->Display->setText(QString::number(dblNewValidation, 'g', 16));

    }
}

void MainWindow::MathFunctionPressed()
{
    // Store current value in Display
    QString displayValidation = ui->Display->text();
    calcValidation = displayValidation.toDouble();

    // Sender returns a pointer to the button pressed
    QPushButton *button = (QPushButton *)sender();

    QString butVal = button->text();

        if(QString::compare(butVal, "/", Qt::CaseInsensitive) == 0){
            divide = true;
        } else if(QString::compare(butVal, "*", Qt::CaseInsensitive) == 0){
            mul = true;
        } else if(QString::compare(butVal, ".", Qt::CaseInsensitive) == 0){
            dot = true;
        } else if(QString::compare(butVal, "+", Qt::CaseInsensitive) == 0){
            plus = true;
        } else {
            minus = true;
        }

        // Clear display
        ui->Display->setText("");
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

