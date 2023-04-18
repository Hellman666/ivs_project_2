/**
 * @file mainwindow.cpp
 * 
 * @brief implementace hlavního okna aplikace
 * 
 * @author Dominik Borek (xborek12) 
 * @date 13.04.2023
 */

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QKeyEvent>
#include <iostream>
#include <string>
#include <cctype>
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

bool plus_use = false;   // příznak +
bool minus_use = false;  // příznak -
bool mul_use = false;    // příznak *
bool div_use = false;    // příznak /
bool idiv_use = false;   // příznak //
bool fact_use = false;   // příznak !
bool root_use = false;   // příznak root
bool power_use = false;  // příznak power
bool dot_use = false;    // příznak .

double value_a;
double value_b;
QString equation;

/**
 * @brief konstruktor pro hlavní okno qt aplikace
 * @param parent rodičovský prvek QWidget
 * @see QMainWindow
 */
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
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

/**
 * @brief destruktor hlavního okna qt aplikace
 */
MainWindow::~MainWindow() {
    delete ui;
}

/**
 * @brief definice chování zmáčknutí tlačítka [0-9]
 */
void MainWindow::on_NumberButton_clicked() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString buttonText = button->text();

    // Vypsaní textu tlačítka do Displaye
    ui->Display->setText(ui->Display->text() + buttonText);

    // Vypsání textu tlačítka do konzole
    qDebug() << buttonText;
}

/**
 * @brief Ověření, jestli Display končí číslem
 */
void MainWindow::SymCheck() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    while(!std::isdigit(currentText.back().toLatin1()) && !currentText.endsWith('.')) {
        currentText.remove(currentText.length() - 1, 1);
    }

    ui->Display->setText(currentText);
}

/**
 * @brief definice chování zmáčknutí "." (desetinné tečky)
 */
void MainWindow::on_Dot_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // Ověří se, jestli Display končí číslem
    if(!std::isdigit(currentText.back().toLatin1())) return;

    if(dot_use == true){
        return;
    }

    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty()) {
        // vypsaní . za text v Displayi
        dot_use = true;
        ui->Display->setText(ui->Display->text() + ".");
        qDebug() << ".";
    }
}

/**
 * @brief definice chování zmáčknutí tlačítka "="
 */
void MainWindow::on_Equals_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty()) {
        equation = currentText;
        qDebug() << equation;

        if (plus_use == true) {
            qDebug() << "plus = true";
            value_a = equation.split("+")[0].toDouble();
            value_b = equation.split("+")[1].toDouble();
            try {
                double result = sum(value_a, value_b);
                ui->Display->setText(QString::number(result));
                qDebug() << result;
            } catch (std::runtime_error& e) {
                qDebug() << e.what();
                ui->Display->setText("Error: " + QString(e.what()));
            }
        } else if (minus_use == true) {
            qDebug() << "minus = true";
            if(equation.startsWith('-')) {
                equation = equation.remove(0,1);
                value_a = -1*equation.split("-")[0].toDouble();
            } else {
                value_a = equation.split("-")[0].toDouble();
            }
            value_b = equation.split("-")[1].toDouble();
            try {
                double result = sub(value_a, value_b);
                ui->Display->setText(QString::number(result));
                qDebug() << result;
            } catch (std::runtime_error& e) {
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
            } catch (std::runtime_error& e) {
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
            } catch (std::runtime_error& e) {
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
            } catch (std::runtime_error& e) {
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
            } catch (std::runtime_error& e) {
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
            } catch (std::runtime_error& e) {
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
            } catch (std::runtime_error& e) {
                qDebug() << e.what();
                ui->Display->setText("Error: " + QString(e.what()));
            }
        }

        else {
            qDebug() << "Chyba při implementaci matematických funkcí";
        }
    }
}

/**
 * @brief definice chování zmáčknutí tlačítka "/"
 */
void MainWindow::on_Div_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    SymCheck();

    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty()) {
        // vypsaní / za text v Displayi
        ui->Display->setText(ui->Display->text() + "/");
        qDebug() << "/";
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

/**
 * @brief definice chování zmáčknutí tlačítka "*"
 */
void MainWindow::on_Mul_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    SymCheck();

    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty()) {
        // vypsaní * za text v Displayi
        ui->Display->setText(ui->Display->text() + "*");
        qDebug() << "*";
    }
    plus_use = false;
    minus_use = false;
    mul_use = true;
    idiv_use = false;
    fact_use = false;
    root_use = false;
    power_use = false;
    div_use = false;
}

/**
 * @brief definice chování zmáčknutí tlačítka "-" (mínus)
 */
void MainWindow::on_Minus_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();


    if (!currentText.endsWith('-') && !currentText.endsWith('.')) {
        // vypsaní - za text v Displayi
        ui->Display->setText(ui->Display->text() + "-");
        qDebug() << "-";

        minus_use = true;
        plus_use = false;
        mul_use = false;
        idiv_use = false;
        fact_use = false;
        root_use = false;
        power_use = false;
        div_use = false;
    }
}

/**
 * @brief definice chování zmáčknutí tlačítka "+"
 */
void MainWindow::on_Plus_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    SymCheck();

    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty()) {
        // vypsaní + za text v Displayi
        ui->Display->setText(ui->Display->text() + "+");
        qDebug() << "+";

        plus_use = true;
        minus_use = false;
        mul_use = false;
        idiv_use = false;
        fact_use = false;
        root_use = false;
        power_use = false;
        div_use = false;
    }
}

/**
 * @brief definice chování zmáčknutí tlačítka odmocniny
 */
void MainWindow::on_Root_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    SymCheck();

    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty()) {
        // vypsaní √ za text v Displayi
        ui->Display->setText(ui->Display->text() + "√");
        qDebug() << "√";

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

/**
 * @brief definice chování zmáčknutí tlačítka mocniny
 */
void MainWindow::on_Power_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    SymCheck();

    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty()) {
        // vypsaní ^ za text v Displayi
        ui->Display->setText(ui->Display->text() + "^");
        qDebug() << "^";

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

/**
 * @brief definice chování zmáčknutí tlačítka ")"
 */
void MainWindow::on_Right_bracket_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // vypsaní ) za text v Displayi
    ui->Display->setText(ui->Display->text() + ")");
    qDebug() << ")";

}

/**
 * @brief definice chování zmáčknutí tlačítka "("
 */
void MainWindow::on_Left_bracket_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // vypsaní ( za text v Displayi
    ui->Display->setText(ui->Display->text() + "(");
    qDebug() << "(";
}

/**
 * @brief definice chování zmáčknutí tlačítka "//" (celočíselného dělení)
 */
void MainWindow::on_Idiv_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    SymCheck();

    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty()) {
        // vypsaní //(idiv) za text v Displayi
        ui->Display->setText(ui->Display->text() + "//");
        qDebug() << "//";

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

/**
 * @brief definice chování zmáčknutí tlačítka "!" (faktoriálu)
 */
void MainWindow::on_Fact_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    SymCheck();

    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty()) {
        // vypsaní ! za text v Displayi
        ui->Display->setText(ui->Display->text() + "!");
        qDebug() << "!";

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

/**
 * @brief definice chování zmáčknutí tlačítka "C" (vymazání zadávacího pole)
 */
void MainWindow::on_Clear_clicked() {
    // Smazání všeho textu v Display
    ui->Display->clear();
    ui->Rest_of_number->clear();
    qDebug() << "C";

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

/**
 * @brief definice chování zmáčknutí tlačítka backspace (vymazání posledního zadaného symbolu)
 */
void MainWindow::on_Backspace_clicked() {
    /*!

    */
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty()) {
        // Pokud není, tak odstraní poslední prvek z Displaye a
        currentText = currentText.left(currentText.length() - 1);
        ui->Display->setText(currentText);
    }
    qDebug() << "<-";
}

/**
 * @brief definice chování zmáčknutí tlačítek
 */
void MainWindow::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_0) {
        QString currentText = ui->Display->text();
        ui->Display->setText(currentText + "0");
    } else if (event->key() == Qt::Key_1) {
        QString currentText = ui->Display->text();
        ui->Display->setText(currentText + "1");
    } else if (event->key() == Qt::Key_2) {
        QString currentText = ui->Display->text();
        ui->Display->setText(currentText + "2");
    } else if (event->key() == Qt::Key_3) {
        QString currentText = ui->Display->text();
        ui->Display->setText(currentText + "3");
    } else if (event->key() == Qt::Key_4) {
        QString currentText = ui->Display->text();
        ui->Display->setText(currentText + "4");
    } else if (event->key() == Qt::Key_5) {
        QString currentText = ui->Display->text();
        ui->Display->setText(currentText + "5");
    } else if (event->key() == Qt::Key_6) {
        QString currentText = ui->Display->text();
        ui->Display->setText(currentText + "6");
    } else if (event->key() == Qt::Key_7) {
        QString currentText = ui->Display->text();
        ui->Display->setText(currentText + "7");
    } else if (event->key() == Qt::Key_8) {
        QString currentText = ui->Display->text();
        ui->Display->setText(currentText + "8");
    } else if (event->key() == Qt::Key_9) {
        QString currentText = ui->Display->text();
        ui->Display->setText(currentText + "9");
    } else if (event->key() == Qt::Key_Plus) {
        plus_use = true;
        on_Plus_clicked();
    } else if (event->key() == Qt::Key_Minus) {
        minus_use = true;
        on_Minus_clicked();
    } else if (event->key() == Qt::Key_Asterisk) {
        mul_use = true;
        on_Mul_clicked();
    } else if (event->key() == Qt::Key_Slash) {
        if (div_use == true) {
            idiv_use = true;
            div_use = false;
            on_Backspace_clicked();
            on_Idiv_clicked();
        } else {
            div_use = true;
            on_Div_clicked();
        }
    } else if (event->key() == Qt::Key_Exclam) {
        fact_use = true;
        on_Fact_clicked();
    } else if (event->key() == Qt::Key_AsciiCircum || event->key() == Qt::Key_3 && event->modifiers() == Qt::AltModifier) {
        power_use = true;
        on_Power_clicked();
    } else if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
        on_Equals_clicked();
    } else if (event->key() == Qt::Key_Period || event->key() == Qt::Key_Comma) {
        on_Dot_clicked();
    } else {
        event->ignore();
    }
}
