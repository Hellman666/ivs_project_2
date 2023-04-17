#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include "../includes/math.h"
#include "../includes/math.cpp"

/**
    * @file mainwindow.cpp
    *
*/


bool plus_use = false;
bool minus_use = false;
bool mul_use = false;
bool div_use = false;
bool idiv_use = false;
bool fact_use = false;
bool root_use = false;
bool power_use = false;

double value_a;
double value_b;
QString equation;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {

    ui->setupUi(this);
    this->setStyleSheet("background-color: #3c6e71;");
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    ui->Rest_of_number->setStyleSheet("QLineEdit {color: white; background-color: #284b63; padding: 10px; color: white; border-width: 2px; border-radius: 15px; border-color: #b8cbd8; }");
    ui->Display->setStyleSheet("QLineEdit {color: white; background-color: #284b63; padding: 10px; color: white; border-style: outset; border-width: 2px; border-radius: 15px; border-color: #b8cbd8; }");

    connect(ui->Number0, &QPushButton::clicked, this, &MainWindow::on_NumberButton_clicked);
    connect(ui->Number1, &QPushButton::clicked, this, &MainWindow::on_NumberButton_clicked);
    connect(ui->Number2, &QPushButton::clicked, this, &MainWindow::on_NumberButton_clicked);
    connect(ui->Number3, &QPushButton::clicked, this, &MainWindow::on_NumberButton_clicked);
    connect(ui->Number4, &QPushButton::clicked, this, &MainWindow::on_NumberButton_clicked);
    connect(ui->Number5, &QPushButton::clicked, this, &MainWindow::on_NumberButton_clicked);
    connect(ui->Number6, &QPushButton::clicked, this, &MainWindow::on_NumberButton_clicked);
    connect(ui->Number7, &QPushButton::clicked, this, &MainWindow::on_NumberButton_clicked);
    connect(ui->Number8, &QPushButton::clicked, this, &MainWindow::on_NumberButton_clicked);
    connect(ui->Number9, &QPushButton::clicked, this, &MainWindow::on_NumberButton_clicked);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_NumberButton_clicked() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    QString buttonText = button->text();

    // Ověří, jestli není v Diplayi výsledek, pokud je, tak vymaže Display
    QString currentText = ui->Display->text();
    if (currentText == "Výsledek") {
            ui->Display->clear();
    }

    // Vypsaní textu tlačítka do Displaye
    ui->Display->setText(ui->Display->text() + buttonText);

    // Vypsání textu tlačítka do konzole
    qDebug() << buttonText;
}

void MainWindow::on_Dot_clicked() {
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


void MainWindow::on_Equals_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && currentText!="Výsledek") {
        equation = currentText;
        qDebug() << equation;

        if(plus_use == true) {
            qDebug() << "plus = true";
            value_a = equation.split("+")[0].toDouble();
            value_b = equation.split("+")[1].toDouble();
            double result = sum(value_a, value_b);
            ui->Display->setText(QString::number(result));
            qDebug() << result;
        } else if (minus_use == true) {
            qDebug() << "minus = true";
            value_a = equation.split("-")[0].toDouble();
            value_b = equation.split("-")[1].toDouble();
            double result = sub(value_a, value_b);
            ui->Display->setText(QString::number(result));
            qDebug() << result;
        } else if (root_use == true) {
            qDebug() << "root = true";
            value_a = equation.split("√")[0].toDouble();
            value_b = equation.split("√")[1].toDouble();
            double result = root(value_a, value_b);
            ui->Display->setText(QString::number(result));
            qDebug() << result;
        } else if (power_use == true) {
            qDebug() << "power = true";
            value_a = equation.split("^")[0].toDouble();
            value_b = equation.split("^")[1].toDouble();
            double result = power(value_a, value_b);
            ui->Display->setText(QString::number(result));
            qDebug() << result;
        } else if (mul_use == true) {
            qDebug() << "mul = true";
            value_a = equation.split("*")[0].toDouble();
            value_b = equation.split("*")[1].toDouble();
            double result = mul(value_a, value_b);
            ui->Display->setText(QString::number(result));
            qDebug() << result;
        } else if (div_use == true) {
            qDebug() << "div = true";
            value_a = equation.split("/")[0].toDouble();
            value_b = equation.split("/")[1].toDouble();
            double result = div(value_a, value_b);
            ui->Display->setText(QString::number(result));
            qDebug() << result;
        } else if (idiv_use == true) {
            qDebug() << "idiv = true";
            value_a = equation.split("//")[0].toDouble();
            value_b = equation.split("//")[1].toDouble();
            std::pair<int, int> result = idiv(value_a, value_b);
            ui->Display->setText(QString::number(result.first));
            ui->Rest_of_number->setText(QString::number(result.second));
            qDebug() << result;
        } else if (fact_use == true) {
            qDebug() << "fact = true";
            value_a = equation.split("!")[0].toDouble();
            double result = fact(value_a);
            ui->Display->setText(QString::number(result));
            qDebug() << result;
        }

        else {
            qDebug() << "tyto podmínky nefungují";
        }

        // Výsledek výpočtu se vypíše do widgetu Display
        // ui->Display->setText("Výsledek");
        qDebug() << "=";
    }

}


void MainWindow::on_Div_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // TODO: ošetřit, aby se nebral v potaz mezivýsledek
    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && currentText!="Výsledek") {
        // vypsaní / za text v Displayi
        ui->Display->setText(ui->Display->text() + "/");
        qDebug() <<"/";

        div_use = true;
    }
}


void MainWindow::on_Mul_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // TODO: ošetřit, aby se nebral v potaz mezivýsledek
    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && currentText!="Výsledek") {
        // vypsaní * za text v Displayi
        ui->Display->setText(ui->Display->text() + "*");
        qDebug() <<"*";

        mul_use = true;
    }
}


void MainWindow::on_Minus_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // TODO: ošetřit, aby se nebral v potaz mezivýsledek
    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && currentText!="Výsledek") {
        // vypsaní - za text v Displayi
        ui->Display->setText(ui->Display->text() + "-");
        qDebug() <<"-";

        minus_use = true;
        plus_use = false;
    }
}


void MainWindow::on_Plus_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // value_a = currentText.toDouble();
    // qDebug() << value_a;

    // TODO: ošetřit, aby se nebral v potaz mezivýsledek
    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && currentText!="Výsledek") {

        // vypsaní + za text v Displayi
        ui->Display->setText(ui->Display->text() + "+");
        qDebug() <<"+";

        plus_use = true;
        minus_use = false;
    }
}


void MainWindow::on_Root_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // TODO: ošetřit, aby se nebral v potaz mezivýsledek
    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && currentText!="Výsledek") {

        // vypsaní √ za text v Displayi
        ui->Display->setText(ui->Display->text() + "√");
        qDebug() <<"√";

        root_use = true;
    }
}


void MainWindow::on_Power_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // TODO: ošetřit, aby se nebral v potaz mezivýsledek
    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && currentText!="Výsledek") {
        // vypsaní ^ za text v Displayi
        ui->Display->setText(ui->Display->text() + "^");
        qDebug() <<"^";

        power_use = true;
    }
}


void MainWindow::on_Right_bracket_clicked() {
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


void MainWindow::on_Left_bracket_clicked() {

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


void MainWindow::on_Idiv_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // TODO: ošetřit, aby se nebral v potaz mezivýsledek
    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && currentText!="Výsledek") {
        // vypsaní //(idiv) za text v Displayi
        ui->Display->setText(ui->Display->text() + "//");
        qDebug() <<"//";

        idiv_use = true;
    }
}


void MainWindow::on_Fact_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && currentText!="Výsledek") {
        // vypsaní ! za text v Displayi
        ui->Display->setText(ui->Display->text() + "!");
        qDebug() <<"!";

        fact_use = true;
    }
}


void MainWindow::on_Clear_clicked() {
    // Smazání všeho textu v Display
    // TODO: aby se smazala i mezipaměť
    ui->Display->clear();
    ui->Rest_of_number->clear();
    qDebug() <<"C";
}


void MainWindow::on_Backspace_clicked() {
    /*!

    */
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
