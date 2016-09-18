#ifndef SIMVIEWER_H
#define SIMVIEWER_H

#include <QWidget>
#include <QObject>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QPointF>
#include <QGraphicsScene>
#include <QColor>
#include <QFileDialog>
#include <QImage>
#include <QString>
#include <QGraphicsPixmapItem>

#include <QDebug>

#include "arrow.h"
#include "rrt.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class SimViewer: public QGraphicsView
{
    Q_OBJECT
public:
    SimViewer(QWidget* parent = NULL);

    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

    void loadDefaultMap();

public slots:
    void loadMap();
    void updateMap();

    void startRRT();

private:
    QPointF p;
    QPointF q;

    QGraphicsScene *scene;

    Arrow *startArrow;
    State startState;
    bool startIsSet;
    Arrow *goalArrow;
    State goalState;
    bool goalIsSet;

    cv::Mat rgbMap;
    cv::Mat grayMap;

    RRT* rrtSolver;
};

#endif // SIMVIEWER_H
