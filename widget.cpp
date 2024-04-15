#include "widget.h"
#include "ui_widget.h"
#include "QMessageBox"
#include "QString"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->coffee->setEnabled(false);
    ui->tea->setEnabled(false);
    ui->milk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

int money = 0;

void Widget::enableButtons()
{
    ui->coffee->setEnabled(money >= 100);
    ui->tea->setEnabled(money >= 150);
    ui->milk->setEnabled(money >= 200);
}

void Widget::addMoney(int amount)
{
    money += amount;
    ui->lcdNumber->display(money);
    enableButtons();
}

void Widget::buyDrink(int price)
{
    money -= price;
    ui->lcdNumber->display(money);
    enableButtons();
}

void Widget::on_ten_clicked()
{
    addMoney(10);
}

void Widget::on_fifty_clicked()
{
    addMoney(50);
}

void Widget::on_hundred_clicked()
{
    addMoney(100);
}

void Widget::on_fivehundred_clicked()
{
    addMoney(500);
}

void Widget::on_coffee_clicked()
{
    buyDrink(100);
}

void Widget::on_tea_clicked()
{
    buyDrink(150);
}

void Widget::on_milk_clicked()
{
    buyDrink(200);
}

void Widget::on_reset_clicked()
{
    QMessageBox msgbox;

    int fiftyhd = money / 500;
    money = money % 500;

    int hd = money / 100;
    money = money % 100;

    int fifty = money / 50;
    money = money % 50;

    int ten = money / 10;
    money = money % 10;

    ui->lcdNumber->display(money);

    QString msg = "10: "+ QString::number(ten) + ", 50: "+ QString::number(fifty) + ", 100: "+ QString::number(hd) + ", 500: "+ QString::number(fiftyhd);

    msgbox.setText(msg);
    msgbox.setIcon(QMessageBox::Information);
    msgbox.exec();

    enableButtons();
}
