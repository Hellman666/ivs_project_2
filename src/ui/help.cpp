/**
 * @file mainwindow.cpp
 *
 * @brief implementace hlavního okna aplikace
 *
 * @author Dominik Borek (xborek12)
 * @date 13.04.2023
 */

#include "help.h"
#include "ui_help.h"
#include <QPixmap>

/**
 * @brief konstruktor pro okno Help aplikace qt
 * @param parent rodičovský prvek QWidget
 * @see QDialog
 */

Help::Help(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Help)
{
    ui->setupUi(this);
    QPixmap pixmap(":/resources/img/kalkulacka.png"); // načtěte obrázek ze souboru pomocí prefixu :/
    ui->label->setPixmap(pixmap);
    qDebug() << pixmap;
}

/**
 * @brief destruktor hlavního okna qt aplikace
 */
Help::~Help()
{
    delete ui;
}
