#ifndef ARROW_H
#define ARROW_H

#define PI 3.14159265359

#include <cmath>

#include <QColor>
#include <QBrush>
#include <QPen>
#include <QPointF>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsLineItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPolygonF>
#include <QGraphicsPolygonItem>
#include <QPoint>

#include <QDebug>

class Arrow: public QObject, public QGraphicsLineItem
{
    Q_OBJECT
public:
    Arrow(QColor _color = QColor(0,0,0), QGraphicsItem* parent = NULL);
    ~Arrow();
    void removeItself();

    void drawArrow(QPointF _p1, QPointF _p2);

    void setCurrentAngle(QPointF _p1, QPointF _p2);
    double getCurrentAngleRad();
    double getCurrentAngleDeg();

    QPointF rotationMatrix(QPointF _p1, QPointF _p2, double theta);
    QPointF rotationMatrix(double _x1, double _y1, double _x2, double _y2, double theta);
    QPointF rotationMatrix(double x_vect, double y_vect, double theta);
private:
    QColor color;
    double lineWidth;
    QPen linePen;

    double currentAngle;

    QGraphicsPolygonItem *tri;

};

#endif // ARROW_H
