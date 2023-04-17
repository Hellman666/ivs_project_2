#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include "../includes/math.cpp"

//        /**
//            * @file mainwindow.cpp
//            * @brief = stručný popis funkce/souboru
//            * @author = autor
//            * @date = datum
//            * @param = parametr
//            * @param
//            * @param
//            * ...
//            * @return co to vrací
//            * @see - pokud je tam odkaz na nějakou funkci, tak můžu dát odkaz na tu funkci
//        */


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
            try {
                double result = sum(value_a, value_b);
                ui->Display->setText(QString::number(result));
                qDebug() << result;
            }
            catch (std::runtime_error& e) {
                qDebug() << e.what();
                ui->Display->setText("Error: " + QString(e.what()));
            }
        } else if (minus_use == true) {
            qDebug() << "minus = true";
            value_a = equation.split("-")[0].toDouble();
            value_b = equation.split("-")[1].toDouble();
            try {
                double result = sub(value_a, value_b);
                ui->Display->setText(QString::number(result));
                qDebug() << result;
            }
            catch (std::runtime_error& e) {
                qDebug() << e.what();
                ui->Display->setText("Error: " + QString(e.what()));
            }
        } else if (root_use == true) {
            qDebug() << "root = true";
            value_a = equation.split("√")[0].toDouble();
            value_b = equation.split("√")[1].toDouble();
            try {
                double result = root(value_a, value_b);
                ui->Display->setText(QString::number(result));
                qDebug() << result;
            }
            catch (std::runtime_error& e) {
                qDebug() << e.what();
                ui->Display->setText("Error: " + QString(e.what()));
            }
        } else if (power_use == true) {
            qDebug() << "power = true";
            value_a = equation.split("^")[0].toDouble();
            value_b = equation.split("^")[1].toDouble();
            try {
                double result = power(value_a, value_b);
                ui->Display->setText(QString::number(result));
                qDebug() << result;
            }
            catch (std::runtime_error& e) {
                qDebug() << e.what();
                ui->Display->setText("Error: " + QString(e.what()));
            }
        } else if (mul_use == true) {
            qDebug() << "mul = true";
            value_a = equation.split("*")[0].toDouble();
            value_b = equation.split("*")[1].toDouble();
            try {
                double result = mul(value_a, value_b);
                ui->Display->setText(QString::number(result));
                qDebug() << result;
            }
            catch (std::runtime_error& e) {
                qDebug() << e.what();
                ui->Display->setText("Error: " + QString(e.what()));
            }
        } else if (div_use == true) {
            qDebug() << "div = true";
            value_a = equation.split("/")[0].toDouble();
            value_b = equation.split("/")[1].toDouble();
            try {
                double result = div(value_a, value_b);
                ui->Display->setText(QString::number(result));
                qDebug() << result;
            }
            catch (std::runtime_error& e) {
                qDebug() << e.what();
                ui->Display->setText("Error: " + QString(e.what()));
            }
        } else if (idiv_use == true) {
            qDebug() << "idiv = true";
            value_a = equation.split("//")[0].toDouble();
            value_b = equation.split("//")[1].toDouble();
            try {
                std::pair<int, int> result = idiv(value_a, value_b);
                ui->Display->setText(QString::number(result.first));
                ui->Rest_of_number->setText(QString::number(result.second));
                qDebug() << result;
            }
            catch (std::runtime_error& e) {
                qDebug() << e.what();
                ui->Display->setText("Error: " + QString(e.what()));
            }
        } else if (fact_use == true) {
            qDebug() << "fact = true";
            value_a = equation.split("!")[0].toDouble();
            try {
                double result = fact(value_a);
                ui->Display->setText(QString::number(result));
                qDebug() << result;
            }
            catch (std::runtime_error& e) {
                qDebug() << e.what();
                ui->Display->setText("Error: " + QString(e.what()));
            }
        }

        else {
            qDebug() << "Chyba při implementaci matematických funkcí";
        }
    }

}


void MainWindow::on_Div_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && currentText!="Výsledek") {
        // vypsaní / za text v Displayi
        ui->Display->setText(ui->Display->text() + "/");
        qDebug() <<"/";
        plus_use = false;
        minus_use = false;
        mul_use = false;
        idiv_use = false;
        fact_use = false;
        root_use = false;
        power_use = false;
        div_use = true;
    }
}


void MainWindow::on_Mul_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && currentText!="Výsledek") {
        // vypsaní * za text v Displayi
        ui->Display->setText(ui->Display->text() + "*");
        qDebug() <<"*";
        plus_use = false;
        minus_use = false;
        idiv_use = false;
        fact_use = false;
        root_use = false;
        power_use = false;
        div_use = false;
        mul_use = true;
    }
}


void MainWindow::on_Minus_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && currentText!="Výsledek") {
        // vypsaní - za text v Displayi
        ui->Display->setText(ui->Display->text() + "-");
        qDebug() <<"-";

        minus_use = true;
        plus_use = false;
        mul_use = false;
        idiv_use = false;
        fact_use = false;
        root_use = false;
        power_use = false;
        div_use = false;    }
}


void MainWindow::on_Plus_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // value_a = currentText.toDouble();
    // qDebug() << value_a;

    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && currentText!="Výsledek") {

        // vypsaní + za text v Displayi
        ui->Display->setText(ui->Display->text() + "+");
        qDebug() <<"+";

        plus_use = true;
        minus_use = false;
        mul_use = false;
        idiv_use = false;
        fact_use = false;
        root_use = false;
        power_use = false;
        div_use = false;    }
}


void MainWindow::on_Root_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && currentText!="Výsledek") {

        // vypsaní √ za text v Displayi
        ui->Display->setText(ui->Display->text() + "√");
        qDebug() <<"√";

        root_use = true;
        plus_use = false;
        minus_use = false;
        mul_use = false;
        idiv_use = false;
        fact_use = false;
        power_use = false;
        div_use = false;
    }
}


void MainWindow::on_Power_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && currentText!="Výsledek") {
        // vypsaní ^ za text v Displayi
        ui->Display->setText(ui->Display->text() + "^");
        qDebug() <<"^";

        power_use = true;
        plus_use = false;
        minus_use = false;
        mul_use = false;
        idiv_use = false;
        fact_use = false;
        root_use = false;
        div_use = false;
    }
}


void MainWindow::on_Right_bracket_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

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

    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && currentText!="Výsledek") {
        // vypsaní //(idiv) za text v Displayi
        ui->Display->setText(ui->Display->text() + "//");
        qDebug() <<"//";

        idiv_use = true;
        plus_use = false;
        minus_use = false;
        mul_use = false;
        fact_use = false;
        root_use = false;
        power_use = false;
        div_use = false;
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
        plus_use = false;
        minus_use = false;
        mul_use = false;
        idiv_use = false;
        root_use = false;
        power_use = false;
        div_use = false;
    }
}


void MainWindow::on_Clear_clicked() {
    // Smazání všeho textu v Display
    ui->Display->clear();
    ui->Rest_of_number->clear();
    qDebug() <<"C";

    plus_use = false;
    minus_use = false;
    mul_use = false;
    idiv_use = false;
    fact_use = false;
    root_use = false;
    power_use = false;
    div_use = false;
    qDebug() << "all false";
    value_a = 0.0;
    value_b = 0.0;
    qDebug() << value_a;
    qDebug() << value_b;
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
