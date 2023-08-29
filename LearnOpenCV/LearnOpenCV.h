#pragma once

#include <QtWidgets/QWidget>
#include "ui_LearnOpenCV.h"

class LearnOpenCV : public QWidget
{
    Q_OBJECT

public:
    LearnOpenCV(QWidget *parent = nullptr);
    ~LearnOpenCV();

private:
    Ui::LearnOpenCVClass ui;
};
