#include "LSI_classes.h"
#include "dialog.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget wdg;

    //set style of the window
    wdg.setWindowIcon(QIcon(":/app_icon"));
    wdg.setFixedSize(240,280);
    wdg.setStyleSheet("QPushButton {background-color: rgb(96,118,107); border-width:1px;"
                      "border-style: outset; border-color: white; border-radius: 7px}"
                      "QPushButton:pressed {background-color: rgb(169,229,201); border-width:1px;"
                      "border-style: outset; border-color: white; border-radius: 7px}");
    QPalette pal;
    pal.setColor(wdg.backgroundRole(),QColor(38,60,88));
    wdg.setPalette(pal);

    //main Layout
    QVBoxLayout *mainLayout = new QVBoxLayout;

    //creating object calculator
    LSI_calc_class *calc = new LSI_calc_class;

    //creating menu
    QMenuBar menuBar;
    QMenu *File = new QMenu("&File");
    QMenu *Edit = new QMenu("&Edit");
    File->addAction("&Exit",&app,SLOT(quit()),Qt::CTRL+Qt::Key_Q);
    Edit->addAction("&Copy",calc,SLOT(copy()),Qt::CTRL+Qt::Key_C);
    Edit->addAction("&Paste",calc,SLOT(paste()),Qt::CTRL+Qt::Key_V);
    menuBar.addMenu(File);
    menuBar.addMenu(Edit);
    menuBar.addAction("About",new about,SLOT(show()));
    mainLayout->setMenuBar(&menuBar);


    //add calc layout to main layout
    mainLayout->addLayout(calc->lay1);

    //set main layout to widget
    wdg.setLayout(mainLayout);

    wdg.show();

    return app.exec();
}
