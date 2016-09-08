#pragma once

#include <QtWidgets>
#include <QString>

class about: public QDialog
{
    Q_OBJECT
    QLabel *lbl;
public:
    about(QWidget* wgt = 0);
};
