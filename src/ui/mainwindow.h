#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Number0_clicked();
    void on_Number1_clicked();
    void on_Number9_clicked();
    void on_Number2_clicked();
    void on_Number3_clicked();
    void on_Number4_clicked();
    void on_Number5_clicked();
    void on_Number6_clicked();
    void on_Number7_clicked();
    void on_Number8_clicked();
    void on_Dot_clicked();
    void on_Equals_clicked();
    void on_Div_clicked();
    void on_Mul_clicked();
    void on_Minus_clicked();
    void on_Plus_clicked();
    void on_Root_clicked();
    void on_Power_clicked();
    void on_Right_bracket_clicked();
    void on_Left_bracket_clicked();
    void on_Idiv_clicked();
    void on_Fact_clicked();
    void on_Clear_clicked();
    void on_Backspace_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
