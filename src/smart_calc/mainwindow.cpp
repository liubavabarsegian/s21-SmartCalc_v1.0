#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scan_rpn.h"
#include "qcustomplot.h"

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
    connect(ui->show_graphic, &QPushButton::clicked, this, [this]{show_graphic();});

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

void MainWindow::show_graphic()
{
    QVector<double> x1(20), y1(20);
    QVector<double> x2(100), y2(100);
    QVector<double> x3(20), y3(20);
    QVector<double> x4(20), y4(20);
    for (int i=0; i<x1.size(); ++i)
    {
      x1[i] = i/(double)(x1.size()-1)*10;
      y1[i] = qCos(x1[i]*0.8+qSin(x1[i]*0.16+1.0))*qSin(x1[i]*0.54)+1.4;
    }
    for (int i=0; i<x2.size(); ++i)
    {
      x2[i] = i/(double)(x2.size()-1)*10;
      y2[i] = qCos(x2[i]*0.85+qSin(x2[i]*0.165+1.1))*qSin(x2[i]*0.50)+1.7;
    }
    for (int i=0; i<x3.size(); ++i)
    {
      x3[i] = i/(double)(x3.size()-1)*10;
      y3[i] = 0.05+3*(0.5+qCos(x3[i]*x3[i]*0.2+2)*0.5)/(double)(x3[i]+0.7)+qrand()/(double)RAND_MAX*0.01;
    }
    for (int i=0; i<x4.size(); ++i)
    {
      x4[i] = x3[i];
      y4[i] = (0.5-y3[i])+((x4[i]-2)*(x4[i]-2)*0.02);
    }

    // create and configure plottables:
    QCPGraph *graph1 = ui->customPlot->addGraph();
    graph1->setData(x1, y1);
    graph1->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 9));
    graph1->setPen(QPen(QColor(120, 120, 120), 2));

    QCPGraph *graph2 = ui->customPlot->addGraph();
    graph2->setData(x2, y2);
    graph2->setPen(Qt::NoPen);
    graph2->setBrush(QColor(200, 200, 200, 20));
    graph2->setChannelFillGraph(graph1);

//    QCPBars *bars1 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
//    bars1->setWidth(9/(double)x3.size());
//    bars1->setData(x3, y3);
//    bars1->setPen(Qt::NoPen);
//    bars1->setBrush(QColor(10, 140, 70, 160));

//    QCPBars *bars2 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
//    bars2->setWidth(9/(double)x4.size());
//    bars2->setData(x4, y4);
//    bars2->setPen(Qt::NoPen);
//    bars2->setBrush(QColor(10, 100, 50, 70));
//    bars2->moveAbove(bars1);

    // move bars above graphs and grid below bars:
//    ui->customPlot->addLayer("abovemain", ui->customPlot->layer("main"), QCustomPlot::limAbove);
//    ui->customPlot->addLayer("belowmain", ui->customPlot->layer("main"), QCustomPlot::limBelow);
//    graph1->setLayer("abovemain");
//    ui->customPlot->xAxis->grid()->setLayer("belowmain");
//    ui->customPlot->yAxis->grid()->setLayer("belowmain");

//    ui->customPlot->xAxis->setBasePen(QPen(Qt::white, 1));
//    ui->customPlot->yAxis->setBasePen(QPen(Qt::white, 1));
//    ui->customPlot->xAxis->setTickPen(QPen(Qt::white, 1));
//    ui->customPlot->yAxis->setTickPen(QPen(Qt::white, 1));
//    ui->customPlot->xAxis->setSubTickPen(QPen(Qt::white, 1));
//    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white, 1));
//    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
//    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
//    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
//    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
//    ui->customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
//    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
//    ui->customPlot->xAxis->grid()->setSubGridVisible(true);
//    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
//    ui->customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
//    ui->customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
//    ui->customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
//    ui->customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
//    QLinearGradient plotGradient;
//    plotGradient.setStart(0, 0);
//    plotGradient.setFinalStop(0, 350);
//    plotGradient.setColorAt(0, QColor(80, 80, 80));
//    plotGradient.setColorAt(1, QColor(50, 50, 50));
//    ui->customPlot->setBackground(plotGradient);
//    QLinearGradient axisRectGradient;
//    axisRectGradient.setStart(0, 0);
//    axisRectGradient.setFinalStop(0, 350);
//    axisRectGradient.setColorAt(0, QColor(80, 80, 80));
//    axisRectGradient.setColorAt(1, QColor(30, 30, 30));
//    ui->customPlot->axisRect()->setBackground(axisRectGradient);

//    ui->customPlot->rescaleAxes();
//    ui->customPlot->yAxis->setRange(0, 2);
}

void MainWindow::clear()
{
    ui->textEdit->setText("");
    ui->inputX->setText("");
}
