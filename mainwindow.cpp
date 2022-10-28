#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QIntValidator"
#include "QDoubleValidator"
#include "math.h"
#include "QtMath"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_str1->setValidator( new QDoubleValidator(this) );
    ui->lineEdit_str2->setValidator( new QDoubleValidator(this) );
    ui->lineEdit_angle->setValidator( new QDoubleValidator(this) );
}

MainWindow::~MainWindow()
{
    delete ui;
}

double MainWindow::square(double str1, double str2, double angle, bool &flag){
    if (str1 <= 0 || str2 <= 0 || angle <= 0)
    {
        return 0;
    }
    return str1 * str2 * sin(qDegreesToRadians(angle));
}

double MainWindow::perimetr(double str1, double str2, double angle, bool &flag){
    double str3;
    str3 = sqrt(pow(str1, 2) + pow(str2, 2) - 2* str1 * str2 * cos(qDegreesToRadians(angle)));
    return str1 + str2 + str3;
}


void MainWindow::on_pushButton_clicked()
{
    bool flag = true;
    double s1 = ui->lineEdit_str1->text().replace(",",".").toDouble();
    double s2 = ui->lineEdit_str2->text().replace(",",".").toDouble();
    double an = ui->lineEdit_angle->text().replace(",",".").toDouble();
    double sq = square(s1, s2, an, flag);
    double per = perimetr(s1, s2, an, flag);
    if (sq == NULL || per == NULL)
    {
        QMessageBox::information(this, "error", "Вы ввели неправельные значения");
    }
    else {
        ui->square->setText(QString::number(sq));
        ui->perim->setText(QString::number(per));
    }
}

