
#include "LSI_classes.h"


// LSI_calc_class  construcor
double LSI_calc_class::getMem() const
{
    return mem;
}

void LSI_calc_class::setMem(double value)
{
    mem = value;
}

LSI_calc_class::LSI_calc_class(QObject *parent)
    : QObject(parent)
{
    //additional variables
    isClickedOper = true;   //it's used to determine if a button of operation was clicked
    isFirstOperEnt = false;
    isSecOperEnt = false;
    op1=0;                //first operand and it's used to display result of calculation
    op2=0;                //second operand
    str1="0";              //it's used to convert operands into double format
    oper=0;
    x=0;
    mem=0;


    //main entry field - myLineEdit widget
    QFont LSI_font("Times", 12, QFont::Bold);
    le = new myLineEdit(this);
    le->setFont(LSI_font);
    le->setStyleSheet("background-color: white; border-width:2px; border-style: outset;"
                      "border-color: black; border-radius: 5px");
    le->setMaxLength(22);
    le->setMinimumHeight(50);
    le->setAlignment(Qt::AlignRight);
    le->insert(QString::number(op1));
    le->deselect();


    //text edit to display flag "use of memmory" in calculator
    txt = new QLabel;
    txt->setStyleSheet("background-color: white");
    txt->setFont(QFont(LSI_font));
    txt->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    txt->setLineWidth(2);
    txt->setMaximumWidth(40);
    txt->setMaximumHeight(25);
    txt->setMinimumHeight(25);
    txt->setDisabled(true);
    txt->setAlignment(Qt::AlignCenter);


    QFont LSI_btn_font("Times", 11, QFont::Bold);
    //button widgets
    btnMC = new QPushButton("MC");
    btnMC->setStyleSheet("color: red");
    btnMC->setMaximumHeight(25);
    btnMC->setMaximumWidth(40);
    btnMC->setFont(LSI_btn_font);

    btnMR = new QPushButton("MR");
    btnMR->setStyleSheet("color: red");
    btnMR->setMaximumHeight(25);
    btnMR->setMaximumWidth(40);
    btnMR->setFont(LSI_btn_font);

    btnMS = new QPushButton("MS");
    btnMS->setStyleSheet("color: red");
    btnMS->setMaximumHeight(25);
    btnMS->setMaximumWidth(40);
    btnMS->setFont(LSI_btn_font);

    btnMPlus = new QPushButton("M+");
    btnMPlus->setStyleSheet("color: red");
    btnMPlus->setMaximumHeight(25);
    btnMPlus->setMaximumWidth(40);
    btnMPlus->setFont(LSI_btn_font);

    btnBackSp = new QPushButton;
    btnBackSp->setIcon(QIcon(":/btn_icon"));
    btnBackSp->setMaximumHeight(25);
    btnBackSp->setMaximumWidth(40);
    btnBackSp->setFont(LSI_btn_font);

    btnCE = new QPushButton("CE");
    btnCE->setMaximumHeight(25);
    btnCE->setMaximumWidth(40);
    btnCE->setFont(LSI_btn_font);

    btnC = new QPushButton("C");
    btnC->setMaximumHeight(25);
    btnC->setMaximumWidth(40);
    btnC->setFont(LSI_btn_font);

    btnPlMin = new QPushButton("+/-");
    btnPlMin->setMaximumHeight(25);
    btnPlMin->setMaximumWidth(40);
    btnPlMin->setFont(LSI_btn_font);

    btnSQRT = new QPushButton("sqrt");
    btnSQRT->setMaximumHeight(25);
    btnSQRT->setMaximumWidth(40);
    btnSQRT->setFont(LSI_btn_font);

    btn1 = new QPushButton("1");
    btn1->setMaximumHeight(25);
    btn1->setMaximumWidth(40);
    btn1->setFont(LSI_btn_font);

    btn2 = new QPushButton("2");
    btn2->setMaximumHeight(25);
    btn2->setMaximumWidth(40);
    btn2->setFont(LSI_btn_font);

    btn3 = new QPushButton("3");
    btn3->setMaximumHeight(25);
    btn3->setMaximumWidth(40);
    btn3->setFont(LSI_btn_font);

    btn4 = new QPushButton("4");
    btn4->setMaximumHeight(25);
    btn4->setMaximumWidth(40);
    btn4->setFont(LSI_btn_font);

    btn5 = new QPushButton("5");
    btn5->setMaximumHeight(25);
    btn5->setMaximumWidth(40);
    btn5->setFont(LSI_btn_font);

    btn6 = new QPushButton("6");
    btn6->setMaximumHeight(25);
    btn6->setMaximumWidth(40);
    btn6->setFont(LSI_btn_font);

    btn7 = new QPushButton("7");
    btn7->setMaximumHeight(25);
    btn7->setMaximumWidth(40);
    btn7->setFont(LSI_btn_font);

    btn8 = new QPushButton("8");
    btn8->setMaximumHeight(25);
    btn8->setMaximumWidth(40);
    btn8->setFont(LSI_btn_font);

    btn9 = new QPushButton("9");
    btn9->setMaximumHeight(25);
    btn9->setMaximumWidth(40);
    btn9->setFont(LSI_btn_font);

    btn0 = new QPushButton("0");
    btn0->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    btn0->setMaximumHeight(25);
    btn0->setFont(LSI_btn_font);

    btnDivis = new QPushButton("/");
    btnDivis->setMaximumHeight(25);
    btnDivis->setMaximumWidth(40);
    btnDivis->setFont(LSI_btn_font);

    btnPerc = new QPushButton("%");
    btnPerc->setMaximumHeight(25);
    btnPerc->setMaximumWidth(40);
    btnPerc->setFont(LSI_btn_font);

    btnMult = new QPushButton("*");
    btnMult->setMaximumHeight(25);
    btnMult->setMaximumWidth(40);
    btnMult->setFont(LSI_btn_font);

    btn1DivX = new QPushButton("1/x");
    btn1DivX->setMaximumHeight(25);
    btn1DivX->setMaximumWidth(40);
    btn1DivX->setFont(LSI_btn_font);

    btnMinus = new QPushButton("-");
    btnMinus->setMaximumHeight(25);
    btnMinus->setMaximumWidth(40);
    btnMinus->setFont(LSI_btn_font);

    btnPlus = new QPushButton("+");
    btnPlus->setMaximumHeight(25);
    btnPlus->setMaximumWidth(40);
    btnPlus->setFont(LSI_btn_font);

    btnRes = new QPushButton("=");
    btnRes->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Expanding);
    btnRes->setMaximumWidth(40);
    btnRes->setFont(LSI_btn_font);

    btnDot = new QPushButton(".");
    btnDot->setMaximumHeight(25);
    btnDot->setMaximumWidth(40);
    btnDot->setFont(LSI_btn_font);



    //main layout
    lay1 = new QGridLayout;
    lay1->setMargin(1);
    lay1->addWidget(le,0,0,1,5);
    lay1->addWidget(txt,1,0);
    lay1->addWidget(btnMC,1,1);
    lay1->addWidget(btnMR,1,2);
    lay1->addWidget(btnMS,1,3);
    lay1->addWidget(btnMPlus,1,4);
    lay1->addWidget(btnBackSp,2,0);
    lay1->addWidget(btnCE,2,1);
    lay1->addWidget(btnC,2,2);
    lay1->addWidget(btnPlMin,2,3);
    lay1->addWidget(btnSQRT,2,4);
    lay1->addWidget(btn7,3,0);
    lay1->addWidget(btn8,3,1);
    lay1->addWidget(btn9,3,2);
    lay1->addWidget(btnDivis,3,3);
    lay1->addWidget(btnPerc,3,4);
    lay1->addWidget(btn4,4,0);
    lay1->addWidget(btn5,4,1);
    lay1->addWidget(btn6,4,2);
    lay1->addWidget(btnMult,4,3);
    lay1->addWidget(btn1DivX,4,4);
    lay1->addWidget(btn1,5,0);
    lay1->addWidget(btn2,5,1);
    lay1->addWidget(btn3,5,2);
    lay1->addWidget(btnMinus,5,3);
    lay1->addWidget(btnRes,5,4,2,1);
    lay1->addWidget(btn0,6,0,1,2);
    lay1->addWidget(btnDot,6,2);
    lay1->addWidget(btnPlus,6,3);



    //connections

    QObject::connect(le,SIGNAL(textEdited(QString)),SLOT(textEdit()));
    QObject::connect(btnPlus,SIGNAL(clicked(bool)),SLOT(operat()));
    QObject::connect(btnMinus,SIGNAL(clicked(bool)),SLOT(operat()));
    QObject::connect(btnMult,SIGNAL(clicked(bool)),SLOT(operat()));
    QObject::connect(btnDivis,SIGNAL(clicked(bool)),SLOT(operat()));
    QObject::connect(btnRes,SIGNAL(clicked(bool)),SLOT(result()));
    QObject::connect(btnC,SIGNAL(clicked(bool)),SLOT(clear_all()));
    QObject::connect(btnCE,SIGNAL(clicked(bool)),SLOT(clear_edit()));
    QObject::connect(le,SIGNAL(selectionChanged()),SLOT(deselect()));

    QObject::connect(btn1,SIGNAL(clicked(bool)),SLOT(ins()));
    QObject::connect(btn2,SIGNAL(clicked(bool)),SLOT(ins()));
    QObject::connect(btn3,SIGNAL(clicked(bool)),SLOT(ins()));
    QObject::connect(btn4,SIGNAL(clicked(bool)),SLOT(ins()));
    QObject::connect(btn5,SIGNAL(clicked(bool)),SLOT(ins()));
    QObject::connect(btn6,SIGNAL(clicked(bool)),SLOT(ins()));
    QObject::connect(btn7,SIGNAL(clicked(bool)),SLOT(ins()));
    QObject::connect(btn8,SIGNAL(clicked(bool)),SLOT(ins()));
    QObject::connect(btn9,SIGNAL(clicked(bool)),SLOT(ins()));
    QObject::connect(btn0,SIGNAL(clicked(bool)),SLOT(ins()));
    QObject::connect(btnDot,SIGNAL(clicked(bool)),SLOT(ins()));
    QObject::connect(btnBackSp,SIGNAL(clicked(bool)),SLOT(ins()));
    QObject::connect(btnPlMin,SIGNAL(clicked(bool)),SLOT(ins()));
    QObject::connect(btnSQRT,SIGNAL(clicked(bool)),SLOT(operat()));
    QObject::connect(btn1DivX,SIGNAL(clicked(bool)),SLOT(operat()));
    QObject::connect(btnPerc,SIGNAL(clicked(bool)),SLOT(operat()));
    QObject::connect(btnMC,SIGNAL(clicked(bool)),SLOT(memory()));
    QObject::connect(btnMR,SIGNAL(clicked(bool)),SLOT(memory()));
    QObject::connect(btnMS,SIGNAL(clicked(bool)),SLOT(memory()));
    QObject::connect(btnMPlus,SIGNAL(clicked(bool)),SLOT(memory()));


}



void LSI_calc_class::ins()
{
    if (sender()==btn1) {
        QKeyEvent * ev = new QKeyEvent(QEvent::KeyRelease,
                                       Qt::Key_1,Qt::NoModifier,"1");
        le->keyPressEvent(ev);
    }
    if (sender()==btn2) {
        QKeyEvent * ev = new QKeyEvent(QEvent::KeyRelease,
                                       Qt::Key_2,Qt::NoModifier,"2");
        le->keyPressEvent(ev);
    }
    if (sender()==btn3) {
        QKeyEvent * ev = new QKeyEvent(QEvent::KeyRelease,
                                       Qt::Key_3,Qt::NoModifier,"3");
        le->keyPressEvent(ev);
    }
    if (sender()==btn4) {
        QKeyEvent * ev = new QKeyEvent(QEvent::KeyRelease,
                                       Qt::Key_4,Qt::NoModifier,"4");
        le->keyPressEvent(ev);
    }

    if (sender()==btn5) {
        QKeyEvent * ev = new QKeyEvent(QEvent::KeyRelease,
                                       Qt::Key_5,Qt::NoModifier,"5");
        le->keyPressEvent(ev);
    }

    if (sender()==btn6) {
        QKeyEvent * ev = new QKeyEvent(QEvent::KeyRelease,
                                       Qt::Key_6,Qt::NoModifier,"6");
        le->keyPressEvent(ev);
    }

    if (sender()==btn7) {
        QKeyEvent * ev = new QKeyEvent(QEvent::KeyRelease,
                                       Qt::Key_7,Qt::NoModifier,"7");
        le->keyPressEvent(ev);
    }
    if (sender()==btn8) {
        QKeyEvent * ev = new QKeyEvent(QEvent::KeyRelease,
                                       Qt::Key_8,Qt::NoModifier,"8");
        le->keyPressEvent(ev);
    }

    if (sender()==btn9) {
        QKeyEvent * ev = new QKeyEvent(QEvent::KeyRelease,
                                       Qt::Key_9,Qt::NoModifier,"9");
        le->keyPressEvent(ev);
    }

    if (sender()==btn0) {
        QKeyEvent * ev = new QKeyEvent(QEvent::KeyRelease,
                                       Qt::Key_0,Qt::NoModifier,"0");
        le->keyPressEvent(ev);
    }

    if (sender()==btnDot) {
        QKeyEvent * ev = new QKeyEvent(QEvent::KeyRelease,
                                       Qt::Key_Period,Qt::NoModifier,".");
        le->keyPressEvent(ev);
    }

    if (sender()==btnBackSp) {
        le->backspace();
    }
    if (sender()==btnPlMin) {
        le->setText(QString::number(le->text().toDouble()*(-1)));
    }
    le->setFocus();
}

void LSI_calc_class::memory()
{
    if(sender()==btnMC) {
        mem=0;
        txt->clear();
    }
    if(sender()==btnMR) {
        le->setText(QString::number(mem));
    }
    if(sender()==btnMS) {
        mem=le->text().toDouble();
        txt->setText("M");
    }
    if(sender()==btnMPlus) {
        mem+=le->text().toDouble();
        txt->setText("M");
    }
}


//menu Edit function "Copy"
void LSI_calc_class::copy()
{
    QLineEdit clipboard;
    clipboard.setText(le->text());
    clipboard.selectAll();
    clipboard.copy();
}

//menu Edit function "Paste"
void LSI_calc_class::paste()
{
    QRegExp rx("^\\-?\\d*\\.?\\d*$");
    QLineEdit clipboard;
    clipboard.paste();
    if (rx.indexIn(clipboard.text())!=-1)
        le->setText(clipboard.text());
}


//slots LSI_calc_class implementation

void LSI_calc_class::textEdit()
{
    if (isClickedOper) {
        le->setText(str1);
    }
    if (isFirstOperEnt) isSecOperEnt=true;
    isClickedOper=false;
}


void LSI_calc_class::operat()
{
    if (sender()==btnSQRT) {
        le->setText(QString::number(sqrt(le->text().toDouble())));
    }
    if(sender()==btn1DivX) {
        le->setText(QString::number(1/(le->text().toDouble())));
    }
    if(sender()==btnPerc) {
        op2=op1/100*(le->text().toDouble());
        le->setText(QString::number(op2));
        result();
    }

    if (sender()==btnPlus || sender()==btnMinus ||
            sender()==btnMult || btnDivis) {
        if(isSecOperEnt==false) {
            if(sender()==btnPlus) oper=1;
            if(sender()==btnMinus) oper=2;
            if(sender()==btnMult) oper=3;
            if(sender()==btnDivis) oper=4;
        }
        if (isSecOperEnt==true) {
            result();
            if(sender()==btnPlus) oper=1;
            if(sender()==btnMinus) oper=2;
            if(sender()==btnMult) oper=3;
            if(sender()==btnDivis) oper=4;
            str1=le->text();
            op1=str1.toDouble();
            isFirstOperEnt = true;
        } else {
            str1=le->text();
            op1=str1.toDouble();
            isFirstOperEnt = true;
        }
    }
    le->setFocus();
    isClickedOper=true;
}


void LSI_calc_class::result()
{
    switch (oper) {
    case 1:
        str1=le->text();
        op2=str1.toDouble();
        isSecOperEnt=true;
        op1+=op2;
        x=1;
        break;
    case 2:
        str1=le->text();
        op2=str1.toDouble();
        isSecOperEnt=true;
        op1-=op2;
        x=2;
        break;
    case 3:
        str1=le->text();
        op2=str1.toDouble();
        isSecOperEnt=true;
        op1*=op2;
        x=3;
        break;
    case 4:
        str1=le->text();
        op2=str1.toDouble();
        isSecOperEnt=true;
        op1/=op2;
        x=4;
        break;
    default:
        if (x==1) op1+=op2;
        if (x==2) op1-=op2;
        if (x==3) op1*=op2;
        if (x==4) op1/=op2;
        if (x==0) {
            str1=le->text();
            op1=str1.toDouble();
        }
        break;
    }
    le->setText(QString::number(op1));
    oper=0;
    str1="0";
    isClickedOper=true;
    isFirstOperEnt=false;
    isSecOperEnt=false;
    le->setFocus();
}


void LSI_calc_class::deselect()
{
    le->deselect();
}


void LSI_calc_class::clear_all()
{
    op1=0;
    op2=0;
    oper=0;
    x=0;
    str1="";
    le->setText(QString::number(op1));
    le->setFocus();
    isFirstOperEnt=false;
    isSecOperEnt=false;
    isClickedOper=true;

}


void LSI_calc_class::clear_edit()
{
    le->setText("0");
    le->setFocus();
    isClickedOper=true;
}








myLineEdit::myLineEdit(LSI_calc_class *ptr, QLineEdit *parent):QLineEdit(parent)
{
    QRegExp rx("^\\-?\\d*\\.?\\d*$");
    QValidator *validator = new QRegExpValidator(rx);
    this->setValidator(validator);
    setReadOnly(true);
    tmp=ptr;
}


void myLineEdit::keyPressEvent(QKeyEvent *event)
{
    setReadOnly(false);
    tmp->str1 = event->text();
    switch (event->key()) {
        case Qt::Key_Plus:
            emit tmp->btnPlus->clicked();
            break;
        case Qt::Key_Minus:
            emit tmp->btnMinus->clicked();
            break;
        case Qt::Key_Asterisk:
            emit tmp->btnMult->clicked();
            break;
        case Qt::Key_Slash:
            emit tmp->btnDivis->clicked();
            break;
        case Qt::Key_Enter:
            emit tmp->btnRes->clicked();
            tmp->oper=0;
            break;
        default:
        //qDebug() << event->key();
            QLineEdit::keyPressEvent(event);
    }
    setReadOnly(true);
}

