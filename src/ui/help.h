/**
 * @file mainwindow.cpp
 *
 * @brief deklarace rozhraní hlavního okna aplikace
 *
 * @author Dominik Borek (xborek12)
 * @date 13.04.2023
 */
#ifndef HELP_H
#define HELP_H

#include <QDialog>

namespace Ui {
class Help;
}

class Help : public QDialog
{
    Q_OBJECT

public:
    explicit Help(QWidget *parent = nullptr);
    ~Help();

private:
    Ui::Help *ui;
};

#endif // HELP_H
