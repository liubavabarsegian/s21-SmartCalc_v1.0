#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, &QPushButton::clicked, this, [this]{ append(ui->pushButton_0->text()); });
    connect(ui->pushButton_1, &QPushButton::clicked, this, [this]{ append(ui->pushButton_1->text()); });
    connect(ui->pushButton_2, &QPushButton::clicked, this, [this]{ append(ui->pushButton_2->text()); });
    connect(ui->pushButton_3, &QPushButton::clicked, this, [this]{ append(ui->pushButton_3->text()); });
    connect(ui->pushButton_4, &QPushButton::clicked, this, [this]{ append(ui->pushButton_4->text()); });
    connect(ui->pushButton_5, &QPushButton::clicked, this, [this]{ append(ui->pushButton_5->text()); });
    connect(ui->pushButton_6, &QPushButton::clicked, this, [this]{ append(ui->pushButton_6->text()); });
    connect(ui->pushButton_7, &QPushButton::clicked, this, [this]{ append(ui->pushButton_7->text()); });
    connect(ui->pushButton_8, &QPushButton::clicked, this, [this]{ append(ui->pushButton_8->text()); });
    connect(ui->pushButton_9, &QPushButton::clicked, this, [this]{ append(ui->pushButton_9->text()); });
    connect(ui->pushButton_left_brace, &QPushButton::clicked, this, [this]{ append(ui->pushButton_left_brace->text()); });
    connect(ui->pushButton_right_brace, &QPushButton::clicked, this, [this]{ append(ui->pushButton_right_brace->text()); });
    connect(ui->pushButton_pow, &QPushButton::clicked, this, [this]{ append(ui->pushButton_pow->text()); });
    connect(ui->pushButton_division, &QPushButton::clicked, this, [this]{ append("/"); });
    connect(ui->pushButton_multiplication, &QPushButton::clicked, this, [this]{ append(ui->pushButton_multiplication->text()); });
    connect(ui->pushButton_plus, &QPushButton::clicked, this, [this]{append(ui->pushButton_plus->text()); });
    connect(ui->pushButton_minus, &QPushButton::clicked, this, [this]{append(ui->pushButton_minus->text()); });
    connect(ui->pushButton_dot, &QPushButton::clicked, this, [this]{append(ui->pushButton_dot->text()); });
    connect(ui->pushButton_mod, &QPushButton::clicked, this, [this]{append("%"); });



    connect(ui->pushButton_backspace, &QPushButton::clicked, this, &MainWindow::clicked_backspace);
    connect(ui->pushButton_AC, &QPushButton::clicked, this, &MainWindow::clear);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::append(QString text)
{
    ui->lineEdit->setText(ui->lineEdit->text()+ text);
}

void MainWindow::clicked_backspace()
{
     ui->lineEdit->setText(ui->lineEdit->text().remove(-1, 1));
}

void MainWindow::clear()
{
    ui->lineEdit->setText("");
}
