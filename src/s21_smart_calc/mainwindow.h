#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>

extern "C" int scan_rpn(char *inp, char *result);

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
//    QString X_value;
    Ui::MainWindow *ui;
private:
//    Input_X *input_window;
    void append(QString text);
    void show_graphic();
    void clicked_backspace();
    void clear();
    void equal();
};
#endif // MAINWINDOW_H
