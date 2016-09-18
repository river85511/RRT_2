#include "arrow.h"

Arrow::Arrow(QColor _color, QGraphicsItem *parent): QGraphicsLineItem(parent),
    color(_color),lineWidth(5.0), linePen(QPen(color,lineWidth))
{
//    qDebug() << "Arrow Created!";
    this->setPen(linePen);
    this->hide();

    QPolygonF triangle;
    triangle.append(QPoint(-5, 10));
    triangle.append(QPoint(15, 0));
    triangle.append(QPoint(-5,-10));

    tri = new QGraphicsPolygonItem(triangle,this);
    tri->setPen(QColor(0,0,0,0));
    tri->setBrush(color);
    tri->hide();

}

Arrow::~Arrow()
{
//    qDebug() << "Arrow Removed!";
}

void Arrow::removeItself()
{
    this->scene()->removeItem(this);
    delete this;
    return;
}

void Arrow::drawArrow(QPointF _p1, QPointF _p2)
{
    setCurrentAngle(_p1,_p2);

    this->show();
    this->setLine(_p1.x(),_p1.y(),_p2.x(),_p2.y());

    tri->show();
    tri->setPos(_p2);
    tri->setRotation(getCurrentAngleDeg());
}

void Arrow::setCurrentAngle(QPointF _p1, QPointF _p2)
{
    currentAngle = atan2(_p2.y() - _p1.y(),_p2.x() - _p1.x());
}

double Arrow::getCurrentAngleRad()
{
    return currentAngle;
}

double Arrow::getCurrentAngleDeg()
{
    return currentAngle /PI * 180.0;
}

QPointF Arrow::rotationMatrix(QPointF _p1, QPointF _p2, double theta)
{
     double x_vect = _p2.x() - _p1.x();
     double y_vect = _p2.y() - _p1.y();

     x_vect = cos(theta)*x_vect - sin(theta)*y_vect;
     y_vect = sin(theta)*x_vect + cos(theta)*y_vect;

     return QPointF(x_vect, y_vect);
}

QPointF Arrow::rotationMatrix(double _x1, double _y1, double _x2, double _y2, double theta)
{
    double x_vect = _x2 - _x1;
    double y_vect = _y2 - _y1;

    x_vect = cos(theta)*x_vect - sin(theta)*y_vect;
    y_vect = sin(theta)*x_vect + cos(theta)*y_vect;

    return QPointF(x_vect, y_vect);
}

QPointF Arrow::rotationMatrix(double x_vect, double y_vect, double theta)
{
    x_vect = cos(theta)*x_vect - sin(theta)*y_vect;
    y_vect = sin(theta)*x_vect + cos(theta)*y_vect;

    return QPointF(x_vect, y_vect);
}

