#pragma once

#include <QtWidgets>
#include <QString>

class myLineEdit;

//class calculator
class LSI_calc_class: public QObject {

    Q_OBJECT

private:

    //additional variables
    bool isClickedOper;   //it's used to determine if a button of operation was clicked
    double op1;           //first operand and it's used to display result of calculation
    double op2;           //second operand
    QString str1;         //it's used to convert operands into double format
    int oper;             //1(+), 2(-), 3(*), 4(/)
    int x;                //used to determine which operator was used before
    bool isFirstOperEnt;
    bool isSecOperEnt;
    double mem;

    //main entry field - myLineEdit widget
    myLineEdit *le;

    //text edit to display flag "use of memmory" in calculator
    QLabel *txt;

    //button widgets
    QPushButton *btnMC;
    QPushButton *btnMR;
    QPushButton *btnMS;
    QPushButton *btnMPlus;
    QPushButton *btnBackSp;
    QPushButton *btnCE;
    QPushButton *btnC;
    QPushButton *btnPlMin;
    QPushButton *btnSQRT;
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QPushButton *btn4;
    QPushButton *btn5;
    QPushButton *btn6;
    QPushButton *btn7;
    QPushButton *btn8;
    QPushButton *btn9;
    QPushButton *btn0;
    QPushButton *btnDivis;
    QPushButton *btnPerc;
    QPushButton *btnMult;
    QPushButton *btn1DivX;
    QPushButton *btnMinus;
    QPushButton *btnPlus;
    QPushButton *btnRes;
    QPushButton *btnDot;

public:

    //main layout
    QGridLayout *lay1;

    //constructor
    explicit LSI_calc_class(QObject *parent=0);

    friend class myLineEdit;

    double getMem() const;
    void setMem(double value);

public slots:
    void operat();
    void result();
    void textEdit();
    void deselect();
    void clear_edit();
    void clear_all();
    void ins();
    void memory();
    void copy();
    void paste();
};




//class main entry field - myLineEdit widget
class myLineEdit: public QLineEdit {
    LSI_calc_class *tmp;

public:
    explicit myLineEdit(LSI_calc_class *ptr, QLineEdit *parent=0);

public:
     void keyPressEvent(QKeyEvent *event);

};





