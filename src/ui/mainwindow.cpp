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
#include "help.h"
#include "../includes/math.cpp"

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
    ui->menuBar->setStyleSheet("QMenuBar {background-color: #284b63; color: white;} QMenuBar::item:selected{background-color: #3c6e71; color: white;}");
    ui->Options->setStyleSheet("QMenu::item {background-color: #284b63; color: white;"
                               "} QMenu::item:selected{background-color: #3c6e71; color: white;}");
    setWindowIcon(QIcon(":/resources/img/icon.ico"));

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


/**
 * @brief definice chování zmáčknutí tlačítka [0-9]
 * @return void
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
QString MainWindow::sym_Check() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    while(!currentText.isEmpty() && (!std::isdigit(currentText.back().toLatin1()) && !currentText.endsWith('.') && !currentText.endsWith(')') && !currentText.endsWith('!'))) {
        if(currentText.length()-1 == 0) break;
        currentText.remove(currentText.length() - 1, 1);
    }

    ui->Display->setText(currentText);
    return currentText;
}


/**
 * @brief Kontorla počtu závorek
 */
std::pair<int, int> MainWindow::bracket_Check() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    int left = 0;
    int right = 0;

    for(int x = 0; x < currentText.length(); x++) {
        if(currentText[x] == '(') left++;
        if(currentText[x] == ')') right++;
    }

    return std::make_pair(left, right);
}


/**
 * @brief Konvertuje string na double
 */
double MainWindow::convert_Number(QString currentText, int a, int b) {
    if(b == 0) while(a-b > 0 && (std::isdigit(currentText[a-b-1].toLatin1()) || currentText[a-b-1] == '.')) b++;

    QString string = "";
    for(int c = 0; c < b; c++) string.append(currentText[a-b+c]);

    int f = 10;
    int int_value = 0;
    double float_value = 0;
    bool double_flag = false;
    for(int c = 0; c < b; c++) {
        if(string[c] == '.') {
            double_flag = true;
            continue;
        } else if(string[c] == '-') continue;

        int tmp = string[c].digitValue();
        if(double_flag == false) int_value = int_value*10+tmp;
        else {
            float_value = (float)tmp/f+float_value;
            f *= 10;
        }
    }

    if(currentText[a-b] == '-') return -int_value+float_value;
    else return int_value+float_value;
}


/**
 * @brief Spracuje obdrženou funkci
 */
QString MainWindow::process_Function(QString function) {
    while(function.contains('^')) {
        int a = function.indexOf('^');

        int b = 0;
        while(a-b > 0 && (std::isdigit(function[a-b-1].toLatin1()) || function[a-b-1] == '.')) b++;
        double number1 = convert_Number(function, a, b);

        int c = 0;
        while(a+c+1 < function.length() && (std::isdigit(function[a+c+1].toLatin1()) || function[a+c+1] == '.' || (function[a+c+1] == '-' && c == 0))) c++;
        double number2 = convert_Number(function, a+c+1, c-1);

        if(number1 < 0) b++;
        function.replace(a-b, b+c+1, QString::number(power(number1, number2)));
    }

    while(function.contains("√")) {
        int a = function.indexOf("√");

        int b = 0;
        while(a-b > 0 && (std::isdigit(function[a-b-1].toLatin1()) || function[a-b-1] == '.')) b++;
        double number1 = convert_Number(function, a, b);

        int c = 0;
        while(a+c+1 < function.length() && (std::isdigit(function[a+c+1].toLatin1()) || function[a+c+1] == '.' || function[a+c+1] == '.')) c++;
        double number2 = convert_Number(function, a+c+1, c);

        function.replace(a-b, b+c+1, QString::number(root(number2, number1)));
    }

    for(int a = 0; a < function.length(); a++) {
        if(function[a] == '*' || function[a] == '/') {
            int b = 0;
            while(a-b > 0 && (std::isdigit(function[a-b-1].toLatin1()) || function[a-b-1] == '.' || function[a-b-1] == '-')) b++;
            double number1 = convert_Number(function, a, b);

            int c = 0;
            double number2 = 0;
            if(function[a+1] == '/') {
                while(a+c+2 < function.length() && (std::isdigit(function[a+c+2].toLatin1()) || function[a+c+1] == '.' || (function[a+c+2] == '-' && c == 0))) c++;
                number2 = convert_Number(function, a+c+2, c);
            } else {
                while(a+c+1 < function.length() && (std::isdigit(function[a+c+1].toLatin1()) || function[a+c+1] == '.' || (function[a+c+1] == '-' && c == 0))) c++;
                number2 = convert_Number(function, a+c+1, c);
            }

            switch (function[a].toLatin1()) {
            case '*':
                function.replace(a-b, b+c+1, QString::number(mul(number1, number2)));
                break;
            case '/':
                if(number2 == 0) return "Delení 0";
                else if(function[a+1].toLatin1() == '/') {
                    std::pair<double, double> result = idiv(number1, number2);

                    QString reminder = ui->Rest_of_number->text();

                    double number = 0;
                    if(!reminder.isEmpty()) number = convert_Number(reminder, reminder.length());
                    number += result.second;

                    ui->Rest_of_number->setText(QString::number(number));

                    function.replace(a-b, b+c+2, QString::number(result.first));
                } else function.replace(a-b, b+c+1, QString::number(div(number1, number2)));
                break;
            default:
                break;
            }

            a = a-b;
        }
    }

    for(int a = 0; a < function.length(); a++) {
        if(a != 0 && (function[a] == '+' || function[a] == '-')) {
            int b = 0;
            while(a-b > 0 && (std::isdigit(function[a-b-1].toLatin1()) || function[a-b-1] == '.' || function[a-b-1] == '-')) b++;
            double number1 = convert_Number(function, a, b);

            int c = 0;
            while(a+c+1 < function.length() && (std::isdigit(function[a+c+1].toLatin1()) || function[a+c+1] == '.' || (function[a+c+1] == '-' && c == 0))) c++;
            double number2 = convert_Number(function, a+c+1);

            switch (function[a].toLatin1()) {
            case '+':
                function.replace(a-b, b+c+1, QString::number(sum(number1, number2)));
                break;
            case '-':
                function.replace(a-b, b+c+1, QString::number(sub(number1, number2)));
                break;
            default:
                break;
            }

            a = a-b;
        }
    }

    return function;
}


/**
 * @brief definice chování zmáčknutí tlačítka "="
 */
void MainWindow::on_Equals_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && (isdigit(currentText.back().toLatin1()) || currentText.endsWith(')') || currentText.endsWith('!'))) {
        int sequence_Start = 0;
        int sequence_End = 0;

        // Kontrola počtu závorek
        std::pair<int, int> brackets = bracket_Check();
        if(brackets.first != brackets.second) {
            qDebug() << "Chybne zavorky";
            return;
        }

        // Zpracování všech faktoriálú
        while(currentText.contains('!')) {
            int a = currentText.indexOf('!');
            int b = 0;

            while(a-b > 0 && (std::isdigit(currentText[a-b-1].toLatin1()) || currentText[a-b-1] == '.')) {
                if(currentText[a-b-1] == '.') {
                    qDebug() << "Float Factorial!";
                    return;
                } else b++;
            }

            double result = convert_Number(currentText, a, b);
            result = fact(result);
            currentText.replace(a-b, b+1, QString::number(result));
            ui->Display->setText(currentText);
        }

        // Postupné zpracování vnitřních funkcí
        while(currentText.contains('(')) {
            sequence_End = currentText.indexOf(')');
            sequence_Start = sequence_End-1;
            while(currentText[sequence_Start-1] != '(') sequence_Start--;

            QString result = process_Function(currentText.mid(sequence_Start, sequence_End-sequence_Start));
            currentText.replace(sequence_Start-1, sequence_End-sequence_Start+2, result);

            if(result == "Delení 0") {
                ui->Display->setText(result);
                return;
            }
        }

        ui->Display->setText(process_Function(currentText));
    }
}


/**
 * @brief definice chování zmáčknutí tlačítka "-" (mínus)
 */
void MainWindow::on_Minus_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    if (!currentText.endsWith('-') && !currentText.endsWith('.')) {
        if(!currentText.isEmpty() && currentText.endsWith('+')) currentText.remove(currentText.length() - 1, 1);

        // vypsaní - za text v Displayi
        ui->Display->setText(currentText + "-");
        qDebug() << "-";
    }
}


/**
 * @brief definice chování zmáčknutí tlačítka "+"
 */
void MainWindow::on_Plus_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && !currentText.endsWith('.') && (isdigit(currentText.back().toLatin1()) || currentText.length()-1 > 0)) {
        currentText = sym_Check();

        // vypsaní + za text v Displayi
        ui->Display->setText(ui->Display->text() + "+");
        qDebug() << "+";
    }
}


/**
 * @brief definice chování zmáčknutí tlačítka "/"
 */
void MainWindow::on_Div_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && !currentText.endsWith('.') && (isdigit(currentText.back().toLatin1()) || currentText.length()-1 > 0)) {
        currentText = sym_Check();

        // vypsaní / za text v Displayi
        ui->Display->setText(ui->Display->text() + "/");
        qDebug() << "/";
    }
}


/**
 * @brief definice chování zmáčknutí tlačítka "*"
 */
void MainWindow::on_Mul_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && !currentText.endsWith('.') && (isdigit(currentText.back().toLatin1()) || currentText.length()-1 > 0)) {
        currentText = sym_Check();

        // vypsaní * za text v Displayi
        ui->Display->setText(ui->Display->text() + "*");
        qDebug() << "*";
    }
}


/**
 * @brief definice chování zmáčknutí tlačítka "//" (celočíselného dělení)
 */
void MainWindow::on_Idiv_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && !currentText.endsWith('.') && (isdigit(currentText.back().toLatin1()) || currentText.length()-1 > 0)) {
        currentText = sym_Check();

        // vypsaní //(idiv) za text v Displayi
        ui->Display->setText(ui->Display->text() + "//");
        qDebug() << "//";
    }
}


/**
 * @brief definice chování zmáčknutí tlačítka "!" (faktoriálu)
 */
void MainWindow::on_Fact_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && (std::isdigit(currentText.back().toLatin1()) || currentText.endsWith(')'))) {
        // vypsaní ! za text v Displayi
        ui->Display->setText(ui->Display->text() + "!");
        qDebug() << "!";
    }
}


/**
 * @brief definice chování zmáčknutí tlačítka odmocniny
 */
void MainWindow::on_Root_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    if(!currentText.isEmpty() && isdigit(currentText.back().toLatin1())) {
        // vypsaní √ za text v Displayi
        ui->Display->setText(ui->Display->text() + "√");
        qDebug() << "√";
    }
}


/**
 * @brief definice chování zmáčknutí tlačítka mocniny
 */
void MainWindow::on_Power_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && !currentText.endsWith('.') && !currentText.endsWith('-')) {
        currentText = sym_Check();

        // vypsaní ^ za text v Displayi
        ui->Display->setText(ui->Display->text() + "^");
        qDebug() << "^";
    }
}


/**
 * @brief definice chování zmáčknutí "." (desetinné tečky)
 */
void MainWindow::on_Dot_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    // Vytvoříme pomocnou proměnnou pro poslední číslo nebo operátor v rovnici
    QString lastNumber;

    // Najdeme poslední číslo nebo operátor v rovnici
    int pos = currentText.length() - 1;
    while (pos >= 0 && !std::isdigit(currentText[pos].toLatin1()) && currentText[pos] != '.') {
        lastNumber = currentText[pos] + lastNumber;
        pos--;
    }
    while (pos >= 0 && (std::isdigit(currentText[pos].toLatin1()) || currentText[pos] == '.')) {
        lastNumber = currentText[pos] + lastNumber;
        pos--;
    }

    // Ověří se, jestli není Display prázdný a není to výsledek
    if (!currentText.isEmpty() && std::isdigit(currentText.back().toLatin1())) {
        // Pokud byla tečka již vložena v posledním čísle nebo operátoru, nevkládáme ji znovu
        if (dot_use && lastNumber.contains('.')) return;
        dot_use = true;
        ui->Display->setText(ui->Display->text() + ".");
        qDebug() << ".";
    }
}


/**
 * @brief definice chování zmáčknutí tlačítka "("
 */
void MainWindow::on_Left_bracket_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    if(currentText.isEmpty() || (!std::isdigit(currentText.back().toLatin1()) && !currentText.endsWith('.') && !currentText.endsWith(')'))) {
        // vypsaní ( za text v Displayi
        ui->Display->setText(ui->Display->text() + "(");
        qDebug() << "(";
    }
}

/**
 * @brief definice chování zmáčknutí tlačítka ")"
 */
void MainWindow::on_Right_bracket_clicked() {
    // Do proměnné currentText se nastaví všechen text, který je ve widgetu Display
    QString currentText = ui->Display->text();

    std::pair<int, int> brackets = bracket_Check();

    if(brackets.first > brackets.second && !currentText.endsWith('(')) {
        currentText = sym_Check();

        // vypsaní ) za text v Displayi
        ui->Display->setText(ui->Display->text() + ")");
        qDebug() << ")";
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
}


/**
 * @brief definice chování zmáčknutí tlačítka backspace (vymazání posledního zadaného symbolu)
 */
void MainWindow::on_Backspace_clicked() {
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
 * @brief vytvoření nového okna pomocí třídy Help a zobrazení metody show()
 * @see Help
 */
void MainWindow::on_Help_triggered()
{
    Help *helpWindow = new Help(this);
    helpWindow->show();
}
