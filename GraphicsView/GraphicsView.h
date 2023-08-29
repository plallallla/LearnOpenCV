#pragma once

#include <QtWidgets/QGraphicsView>
#include "ui_GraphicsView.h"

class GraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    GraphicsView(QWidget *parent = nullptr);
    ~GraphicsView();

private:
    Ui::GraphicsViewClass ui;
};
