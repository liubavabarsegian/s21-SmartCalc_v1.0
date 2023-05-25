#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scan_rpn.h"

//#include "input_x.h"
extern "C" char* scan_rpn(const char *input);

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

    connect(ui->pushButton_sin, &QPushButton::clicked, this, [this]{append("sin("); });
    connect(ui->pushButton_cos, &QPushButton::clicked, this, [this]{append("cos("); });
    connect(ui->pushButton_tan, &QPushButton::clicked, this, [this]{append("tan("); });
    connect(ui->pushButton_sqrt, &QPushButton::clicked, this, [this]{append("sqrt("); });
    connect(ui->pushButton_asin, &QPushButton::clicked, this, [this]{append("asin("); });
    connect(ui->pushButton_acos, &QPushButton::clicked, this, [this]{append("acos("); });
    connect(ui->pushButton_atan, &QPushButton::clicked, this, [this]{append("atan("); });
    connect(ui->pushButton_ln, &QPushButton::clicked, this, [this]{append("ln("); });
    connect(ui->pushButton_log, &QPushButton::clicked, this, [this]{append("log("); });

    connect(ui->pushButton_backspace, &QPushButton::clicked, this, &MainWindow::clicked_backspace);
    connect(ui->pushButton_AC, &QPushButton::clicked, this, &MainWindow::clear);
    connect(ui->pushButton_x, &QPushButton::clicked, this, [this]{append("x");});
    connect(ui->pushButton_equal, &QPushButton::clicked, this, [this]{equal();});

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::append(QString text)
{
    ui->textEdit->setText(ui->textEdit->toPlainText()+ text);
}

void MainWindow::clicked_backspace()
{
     ui->textEdit->setText(ui->textEdit->toPlainText().remove(-1, 1));
}

void MainWindow::equal()
{
    QString input = ui->textEdit->toPlainText();
    if (input.contains("x"))
    {
        if (ui->inputX->text() != "")
        {
            input.replace("x", ui->inputX->text());
            qDebug("%s", input.toStdString().c_str());
            ui->textEdit->setText(QString(scan_rpn(input.toStdString().c_str())));
        }
//        else
            //error message
    }
    else {
        ui->textEdit->setText(QString(scan_rpn(input.toStdString().c_str())));
    }
}

void MainWindow::clear()
{
    ui->textEdit->setText("");
    ui->inputX->setText("");
}
