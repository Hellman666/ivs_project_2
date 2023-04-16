#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QtMath>

double calcValue;
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

//    // Sender returns a pointer to the button pressed
//    QPushButton *button = (QPushButton *)sender();

//    // Get number on button
//    QString butonValidation = button->text();

//    // Get the value in the display
//    QString displayValidation = ui->Display->text();

//    if((displayValidation.toDouble() == 0) || (displayValidation.toDouble() == 0.0)){

//        // calcVal = butonValidation.toDouble();
//        ui->Display->setText(butonValidation);

//    } else {
//        // Put the new number to the right of whats there
//        QString newValidation = displayValidation + butonValidation;

//        // Double version of number
//        double dblNewValidation = newValidation.toDouble();

//        // calcValue = newValidation.toDouble();

//        // Set value in display and allow up to 16
//        // digits before using exponents
//        ui->Display->setText(QString::number(dblNewValidation, 'g', 16));

//    }
}

void MainWindow::MathFunctionPressed(){
//    divide = false;
//    plus = false;
//    minus = false;
//    mul = false;
//    root = false;
//    idiv = false;
//    fact = false;
//    dot = false;

//    QString displayValue = ui->Display->text();
//    calcValue = displayValue.toDouble();

//    QPushButton *button = (QPushButton *)sender();

//    QString buttonValue = button->text();

//    if(QString::compare(buttonValue, "/", Qt::CaseInsensitive) == 0){
//        divide = true;
//        qDebug() << "divide true";
//    } else if(QString::compare(buttonValue, "+", Qt::CaseInsensitive) == 0){
//        plus = true;
//    } else if(QString::compare(buttonValue, "-", Qt::CaseInsensitive) == 0){
//        minus = true;
//    } else if(QString::compare(buttonValue, "*", Qt::CaseInsensitive) == 0){
//        mul = true;
//    } else if(QString::compare(buttonValue, "√", Qt::CaseInsensitive) == 0){
//        root = true;
//    } else if(QString::compare(buttonValue, "//", Qt::CaseInsensitive) == 0){
//        idiv = true;
//    } else if(QString::compare(buttonValue, "!", Qt::CaseInsensitive) == 0){
//        fact = true;
//    } else if(QString::compare(buttonValue, ".", Qt::CaseInsensitive) == 0){
//        dot = true;
//    } else {
//        qDebug() << "Neznámý znak";
//    }

//    ui->Display->setText("");

}


//double nthRoot(double x, int n) {
//    if (x < 0 && n % 2 == 0) {
//        // nelze vypočítat sudou odmocninu z negativního čísla
//        return qQNaN();
//    }

//    return qPow(x, 1.0 / n);
//}

void MainWindow::EqualButtonPressed(){

//    // Holds new calculation
//    double solution = 0.0;

//    // Get value in display
//    QString displayVal = ui->Display->text();
//    double dblDisplayVal = displayVal.toDouble();

//    // Make sure a math button was pressed
//    if(divide || plus || minus || mul || root || idiv || fact || dot ){
//        if(divide){
//            solution = calcValue / dblDisplayVal;
//        } else if(plus){
//            solution = calcValue + dblDisplayVal;
//        } else if(minus){
//            solution = calcValue - dblDisplayVal;
//        } else if(mul){
//            solution = calcValue * dblDisplayVal;
//        } else if(root){
//            solution = nthRoot(calcValue, dblDisplayVal);
//        } else if(idiv){
//            // TODO: udělat idiv
//            solution = calcValue / dblDisplayVal;
//        } else if(fact){
//            // TODO: udělat fact
//            solution = calcValue / dblDisplayVal;
//        } else{
//            qDebug() << "Chyba při Equal button pressed";
//        }
//    }

//    // Put solution in display
//    ui->Display->setText(QString::number(solution));

}

void MainWindow::on_Number0_clicked()
{
    ui->Display->setText(ui->Display->text() + "0");
    qDebug() <<"0";
}


void MainWindow::on_Number1_clicked()
{
    ui->Display->setText(ui->Display->text() + "1");
    qDebug() <<"1";
}



void MainWindow::on_Number2_clicked()
{
    ui->Display->setText(ui->Display->text() + "2");
    qDebug() <<"2";
}


void MainWindow::on_Number3_clicked()
{
    ui->Display->setText(ui->Display->text() + "3");

    qDebug() <<"3";
}


void MainWindow::on_Number4_clicked()
{
    ui->Display->setText(ui->Display->text() + "4");

    qDebug() <<"4";
}


void MainWindow::on_Number5_clicked()
{
    ui->Display->setText(ui->Display->text() + "5");

    qDebug() <<"5";
}


void MainWindow::on_Number6_clicked()
{

    ui->Display->setText(ui->Display->text() + "6");
    qDebug() <<"6";
}


void MainWindow::on_Number7_clicked()
{
    ui->Display->setText(ui->Display->text() + "7");
    qDebug() <<"7";
}


void MainWindow::on_Number8_clicked()
{
    ui->Display->setText(ui->Display->text() + "8");
    qDebug() <<"8";
}


void MainWindow::on_Number9_clicked()
{
    ui->Display->setText(ui->Display->text() + "9");
    qDebug() <<"9";
}

void MainWindow::on_Dot_clicked()
{
    ui->Display->setText(ui->Display->text() + ".");
    qDebug() <<".";
}


void MainWindow::on_Equals_clicked()
{
    ui->Display->setText("Výsledek");
    qDebug() <<"=";
}


void MainWindow::on_Div_clicked()
{
    ui->Display->setText(ui->Display->text() + "/");
    qDebug() <<"/";
}


void MainWindow::on_Mul_clicked()
{
    ui->Display->setText(ui->Display->text() + "*");
    qDebug() <<"*";
}


void MainWindow::on_Minus_clicked()
{
    ui->Display->setText(ui->Display->text() + "-");
    qDebug() <<"-";
}


void MainWindow::on_Plus_clicked()
{
    ui->Display->setText(ui->Display->text() + "+");
    qDebug() <<"+";
}


void MainWindow::on_Root_clicked()
{
    ui->Display->setText(ui->Display->text() + "√");
    qDebug() <<"√";
}


void MainWindow::on_Power_clicked()
{
    ui->Display->setText(ui->Display->text() + "^");
    qDebug() <<"^";
}


void MainWindow::on_Right_bracket_clicked()
{
    ui->Display->setText(ui->Display->text() + ")");
    qDebug() <<")";
}


void MainWindow::on_Left_bracket_clicked()
{
    ui->Display->setText(ui->Display->text() + "(");
    qDebug() <<"(";
}


void MainWindow::on_Idiv_clicked()
{
    ui->Display->setText(ui->Display->text() + "//");
    qDebug() <<"//";
}


void MainWindow::on_Fact_clicked()
{
    ui->Display->setText(ui->Display->text() + "!");
    qDebug() <<"!";
}


void MainWindow::on_Clear_clicked()
{
    ui->Display->clear();
    qDebug() <<"C";
}


void MainWindow::on_Backspace_clicked()
{
    QString currentText = ui->Display->text();
    if (!currentText.isEmpty()) {
        currentText = currentText.left(currentText.length() - 1);
        ui->Display->setText(currentText);
    }
    qDebug() <<"<-";
}

