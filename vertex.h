#ifndef VERTEX_H
#define VERTEX_H

#include <QObject>
#include <QString>
#include <QDebug>

#include "state.h"

#include <list>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class Vertex: public QObject
{
    Q_OBJECT
public:
    Vertex(int type, State _state = State(0,0,0),Vertex* _parent = nullptr);    //type 0 = Qt-Coor; type 1 = Real-Coor;
    ~Vertex();

    void setState(const State& _state);
    void setRealState(const State& _state);     //Due to the differences between real world coordinates and Qt/openCV coordinates
    State stateTransform(const State& _state);

    void setParent(Vertex* _parent);
    void addChild(Vertex* _child);
    void removeChild(Vertex* _child);

    cv::Point getPoint();

    State state;
    State realState;
    Vertex* parent;
    std::list<Vertex *> children;

public slots:
    void draw();
signals:
    void drawDot(Vertex* itself);
    void drawEdge(Vertex* itself, Vertex* parent);
    void removeDot(Vertex* itself);
    void removeEdge(Vertex* itself, Vertex* parent);

};

#endif // VERTEX_H
