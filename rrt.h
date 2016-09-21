#ifndef RRT_H
#define RRT_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "vertex.h"
#include "state.h"

#include <QObject>
#include <QDebug>


#define PI 3.14159265359

class RRT: public QObject
{
    Q_OBJECT
public:
    RRT();
    RRT(const State& startState, const State& goalState, cv::Mat* _map);

    void setStart(const State& startState);
    void setGoal(const State& goalState);
    void setMap(cv::Mat* _map);

    bool isStartSetOrNot();
    bool isGoalSetOrNot();

    void growTree();

    State genSampleState();
    double gauss_distribution(double mean, double std);

    void updateTreeVector(Vertex* vertex);

public slots:
    void drawDot(Vertex* vertex);
    void drawEdge(Vertex* vertex1, Vertex* vertex2);
    void removeDot(Vertex* vertex);
    void removeEdge(Vertex* vertex1, Vertex* vertex2);

signals:
    void updateMap();

private:
    Vertex *start;
    bool startIsSetOrNot;
    Vertex *goal;
    bool goalIsSetOrNot;

    Vertex* root;
    std::vector<Vertex *> treeVector;

    cv::Mat* map;
    cv::Mat grayMap;

    cv::Scalar red;
    cv::Scalar green;
    cv::Scalar black;
    cv::Scalar white;
    double bigDotRadius;
    double smallDotRadius;
};

#endif // RRT_H
