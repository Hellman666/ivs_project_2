#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QtMath>

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

void MainWindow::on_Number0_clicked()
{
    // Ověří, jestli není v Diplayi výsledek, pokud je, tak vymaže Display
    QString currentText = ui->Display->text();
    if (currentText == "Výsledek") {
        ui->Display->clear();
    }
    // vypsaní 0 do Displaye
    ui->Display->setText(ui->Display->text() + "0");
    qDebug() <<"0";
}


void MainWindow::on_Number1_clicked()
{
    // Ověří, jestli není v Diplayi výsledek, pokud je, tak vymaže Display
    QString currentText = ui->Display->text();
    if (currentText == "Výsledek") {
        ui->Display->clear();
    }
    // vypsaní 1 do Displaye
    ui->Display->setText(ui->Display->text() + "1");
    qDebug() <<"1";
}



void MainWindow::on_Number2_clicked()
{
    // Ověří, jestli není v Diplayi výsledek, pokud je, tak vymaže Display
    QString currentText = ui->Display->text();
    if (currentText == "Výsledek") {
        ui->Display->clear();
    }
    // vypsaní 2 do Displaye
    ui->Display->setText(ui->Display->text() + "2");
    qDebug() <<"2";
}


void MainWindow::on_Number3_clicked()
{
    // Ověří, jestli není v Diplayi výsledek, pokud je, tak vymaže Display
    QString currentText = ui->Display->text();
    if (currentText == "Výsledek") {
        ui->Display->clear();
    }
    // vypsaní 3 do Displaye
    ui->Display->setText(ui->Display->text() + "3");
    qDebug() <<"3";
}


void MainWindow::on_Number4_clicked()
{
    // Ověří, jestli není v Diplayi výsledek, pokud je, tak vymaže Display
    QString currentText = ui->Display->text();
    if (currentText == "Výsledek") {
        ui->Display->clear();
    }
    // vypsaní 4 do Displaye
    ui->Display->setText(ui->Display->text() + "4");
    qDebug() <<"4";
}


void MainWindow::on_Number5_clicked()
{
    // Ověří, jestli není v Diplayi výsledek, pokud je, tak vymaže Display
    QString currentText = ui->Display->text();
    if (currentText == "Výsledek") {
        ui->Display->clear();
    }
    // vypsaní 5 do Displaye
    ui->Display->setText(ui->Display->text() + "5");
    qDebug() <<"5";
}


void MainWindow::on_Number6_clicked()
{
    // Ověří, jestli není v Diplayi výsledek, pokud je, tak vymaže Display
    QString currentText = ui->Display->text();
    if (currentText == "Výsledek") {
        ui->Display->clear();
    }
    // vypsaní 6 do Displaye
    ui->Display->setText(ui->Display->text() + "6");
    qDebug() <<"6";
}


void MainWindow::on_Number7_clicked()
{
    // Ověří, jestli není v Diplayi výsledek, pokud je, tak vymaže Display
    QString currentText = ui->Display->text();
    if (currentText == "Výsledek") {
        ui->Display->clear();
    }
    // vypsaní 7 do Displaye
    ui->Display->setText(ui->Display->text() + "7");
    qDebug() <<"7";
}


void MainWindow::on_Number8_clicked()
{
    // Ověří, jestli není v Diplayi výsledek, pokud je, tak vymaže Display
    QString currentText = ui->Display->text();
    if (currentText == "Výsledek") {
        ui->Display->clear();
    }
    // vypsaní 8 do Displaye
    ui->Display->setText(ui->Display->text() + "8");
    qDebug() <<"8";
}


void MainWindow::on_Number9_clicked()
{
    // Ověří, jestli není v Diplayi výsledek, pokud je, tak vymaže Display
    QString currentText = ui->Display->text();
    if (currentText == "Výsledek") {
        ui->Display->clear();
    }
    // vypsaní 9 do Displaye
    ui->Display->setText(ui->Display->text() + "9");
    qDebug() <<"9";
}

void MainWindow::on_Dot_clicked()
{
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // TODO: ošetřit, aby se nebral v potaz mezivýsledek
    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && currentText!="Výsledek") {
        // vypsaní . za text v Displayi
        ui->Display->setText(ui->Display->text() + ".");
        qDebug() <<".";
    }
}


void MainWindow::on_Equals_clicked()
{
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // TODO: ošetřit, aby se nebral v potaz mezivýsledek
    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && currentText!="Výsledek") {
        // Výsledek výpočtu se vypíše do widgetu Display
        ui->Display->setText("Výsledek");
        qDebug() <<"=";
    }

}


void MainWindow::on_Div_clicked()
{
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // TODO: ošetřit, aby se nebral v potaz mezivýsledek
    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && currentText!="Výsledek") {
        // vypsaní / za text v Displayi
        ui->Display->setText(ui->Display->text() + "/");
        qDebug() <<"/";
    }
}


void MainWindow::on_Mul_clicked()
{
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // TODO: ošetřit, aby se nebral v potaz mezivýsledek
    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && currentText!="Výsledek") {
        // vypsaní * za text v Displayi
        ui->Display->setText(ui->Display->text() + "*");
        qDebug() <<"*";
    }
}


void MainWindow::on_Minus_clicked()
{
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // TODO: ošetřit, aby se nebral v potaz mezivýsledek
    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && currentText!="Výsledek") {
        // vypsaní - za text v Displayi
        ui->Display->setText(ui->Display->text() + "-");
        qDebug() <<"-";
    }
}


void MainWindow::on_Plus_clicked()
{
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // TODO: ošetřit, aby se nebral v potaz mezivýsledek
    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && currentText!="Výsledek") {
        // vypsaní + za text v Displayi
        ui->Display->setText(ui->Display->text() + "+");
        qDebug() <<"+";
    }
}


void MainWindow::on_Root_clicked()
{
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // TODO: ošetřit, aby se nebral v potaz mezivýsledek
    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && currentText!="Výsledek") {
        // vypsaní √ za text v Displayi
        ui->Display->setText(ui->Display->text() + "√");
        qDebug() <<"√";
    }
}


void MainWindow::on_Power_clicked()
{
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // TODO: ošetřit, aby se nebral v potaz mezivýsledek
    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && currentText!="Výsledek") {
        // vypsaní ^ za text v Displayi
        ui->Display->setText(ui->Display->text() + "^");
        qDebug() <<"^";
    }
}


void MainWindow::on_Right_bracket_clicked()
{
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // TODO: ošetřit, aby se nebral v potaz mezivýsledek
    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && currentText!="Výsledek") {
        // vypsaní ) za text v Displayi
        ui->Display->setText(ui->Display->text() + ")");
        qDebug() <<")";
    }
}


void MainWindow::on_Left_bracket_clicked()
{
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // TODO: ošetřit, aby se nebral v potaz mezivýsledek
    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && currentText!="Výsledek") {
        // vypsaní ( za text v Displayi
        ui->Display->setText(ui->Display->text() + "(");
        qDebug() <<"(";
    }
}


void MainWindow::on_Idiv_clicked()
{
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // TODO: ošetřit, aby se nebral v potaz mezivýsledek
    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && currentText!="Výsledek") {
        // vypsaní //(idiv) za text v Displayi
        ui->Display->setText(ui->Display->text() + "//");
        qDebug() <<"//";
    }
}


void MainWindow::on_Fact_clicked()
{
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // TODO: ošetřit, aby se nebral v potaz mezivýsledek
    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && currentText!="Výsledek") {
        // vypsaní ! za text v Displayi
        ui->Display->setText(ui->Display->text() + "!");
        qDebug() <<"!";
    }
}


void MainWindow::on_Clear_clicked()
{
    // Smazání všeho textu v Display
    // TODO: aby se smazala i mezipaměť
    ui->Display->clear();
    qDebug() <<"C";
}


void MainWindow::on_Backspace_clicked()
{
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && currentText!="Výsledek") {
        // Pokud není, tak odstraní poslední prvek z Displaye a
        currentText = currentText.left(currentText.length() - 1);
        ui->Display->setText(currentText);
    }
    qDebug() <<"<-";
}

