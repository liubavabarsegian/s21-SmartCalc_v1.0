#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scan_rpn.h"
#include "qcustomplot.h"

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
    connect(ui->show_graphic, &QPushButton::clicked, this, [this]{show_graphic();});

    ui->customPlot->xAxis->setRange(-5, 5);
    ui->customPlot->yAxis->setRange(-10, 10);
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
            qDebug("input: %s", input.toStdString().c_str());
            char result[255];
            scan_rpn((char *)input.toStdString().c_str(), result);
            qDebug("res: %s", result);
            ui->textEdit->setText(QString(result));
        }
//        else
            //error message
    }
    else {
        qDebug("input: %s", input.toStdString().c_str());
        char result[255];
        scan_rpn((char *)input.toStdString().c_str(), result);
        qDebug("res: %s", result);
        ui->textEdit->setText(QString(result));
    }
}

void MainWindow::show_graphic()
{
    ui->customPlot->clearGraphs();
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->legend->setFont(QFont("Helvetica",9));
    ui->customPlot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
    ui->customPlot->addGraph();

    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(3);
    pen.setColor(QColor(67, 65, 156));
    ui->customPlot->graph(0)->setName("Function");
    ui->customPlot->graph(0)->setPen(pen);
//    ui->customPlot->graph(0)->setBrush(QBrush(QColor(255,50,30,20)));

//    ui->customPlot->graph(0)->setChannelFillGraph(ui->customPlot->graph(1));

    double x1 = std::atof("-10");//ui->x1->text().toLocal8Bit().data());
    double x2 = std::atof("10");//ui->x2->text().toLocal8Bit().data());
    QString formula = ui->textEdit->toPlainText();
    QByteArray b_formula = formula.toLocal8Bit();
    QString temp;
    QVector<double> X, Y;
    // int result_flag = 0;

    double step = (x2 - x1) / 1000;
    for (; x1 <= x2; x1 += step + 0.001) {
        QString s_x1 = QString::number(x1);

        X.push_back(x1);
        temp = formula;
        formula.replace("x", QString::number(x1));
        formula.replace(".", ",");
        qDebug("%s", formula.toStdString().c_str());
        char result[255];
        scan_rpn((char *)formula.toStdString().c_str(), result);
        Y.push_back(atof(result));
        formula = temp;

    }
    ui->customPlot->graph(0)->addData(X,Y);
    ui->customPlot->replot();


    ui->customPlot->xAxis->setRange(-5, 5);
    ui->customPlot->yAxis->setRange(-10, 10);
    X.clear();
    Y.clear();
//    ui->customPlot->graph(1)->setData(x0, yConfLower);
//    ui->customPlot->graph(2)->setData(x0, y0);
//    ui->customPlot->graph(3)->setData(x1, y1);
//    errorBars->setData(y1err);
//    ui->customPlot->graph(2)->rescaleAxes();
//    ui->customPlot->graph(3)->rescaleAxes(true);
//    // setup look of bottom tick labels:
//    ui->customPlot->xAxis->setTickLabelRotation(30);
//    ui->customPlot->xAxis->ticker()->setTickCount(9);
//    ui->customPlot->xAxis->setNumberFormat("ebc");
//    ui->customPlot->xAxis->setNumberPrecision(1);
//    ui->customPlot->xAxis->moveRange(-10);
//    // make top right axes clones of bottom left axes. Looks prettier:
//    ui->customPlot->axisRect()->setupFullAxesBox();
    ui->customPlot->replot();

}

void MainWindow::clear()
{
    ui->textEdit->setText("");
    ui->inputX->setText("");
}
