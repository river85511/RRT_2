#include "rrt.h"


RRT::RRT():
    red(cv::Scalar(255,0,0)), green(cv::Scalar(0,255,0)),black(cv::Scalar(0,0,0)),white(cv::Scalar(255,255,255)),
    bigDotRadius(4.0),smallDotRadius(2.0)
{
    qDebug() << "RRT SOLVER IS CREATED!";
    startIsSetOrNot = false;
    goalIsSetOrNot = false;
}

RRT::RRT(const State &startState, const State &goalState, cv::Mat *_map)
{
    this->setStart(startState);
    startIsSetOrNot = true;
    this->setGoal(goalState);
    goalIsSetOrNot = true;

    this->setMap(_map);
}

void RRT::setStart(const State &startState)
{
    start = new Vertex(0,startState);
    connect(start,SIGNAL(drawDot(Vertex*)),this,SLOT(drawDot(Vertex*)));
    connect(start,SIGNAL(drawEdge(Vertex*,Vertex*)),this,SLOT(drawEdge(Vertex*,Vertex*)));
    connect(start,SIGNAL(removeDot(Vertex*)),this,SLOT(removeDot(Vertex*)));
    connect(start,SIGNAL(removeEdge(Vertex*,Vertex*)),this,SLOT(removeEdge(Vertex*,Vertex*)));
    start->draw();
    startIsSetOrNot = true;
    return;
}

void RRT::setGoal(const State &goalState)
{
    goal = new Vertex(0,goalState);
    connect(goal,SIGNAL(drawDot(Vertex*)),this,SLOT(drawDot(Vertex*)));
    connect(goal,SIGNAL(drawEdge(Vertex*,Vertex*)),this,SLOT(drawEdge(Vertex*,Vertex*)));
    connect(goal,SIGNAL(removeDot(Vertex*)),this,SLOT(removeDot(Vertex*)));
    connect(goal,SIGNAL(removeEdge(Vertex*,Vertex*)),this,SLOT(removeEdge(Vertex*,Vertex*)));
    goal->draw();
    goalIsSetOrNot = true;
    return;
}

void RRT::setMap(cv::Mat*_map)
{
    map = _map;
    cv::cvtColor(*_map,grayMap,CV_BGR2GRAY);
    return;
}

bool RRT::isStartSetOrNot()
{
    return startIsSetOrNot;
}

bool RRT::isGoalSetOrNot()
{
    return goalIsSetOrNot;
}

void RRT::growTree()
{
    if(!isStartSetOrNot()){
        qDebug() << "Please Set START!";
    }else{
        qDebug() << "GROW TREE!";
//        Vertex* vertex = new Vertex(0,State(100,50,0),start);
//        connect(vertex,SIGNAL(drawDot(Vertex*)),this,SLOT(drawDot(Vertex*)));
//        connect(vertex,SIGNAL(drawEdge(Vertex*,Vertex*)),this,SLOT(drawEdge(Vertex*,Vertex*)));
//        connect(vertex,SIGNAL(removeDot(Vertex*)),this,SLOT(removeDot(Vertex*)));
//        connect(vertex,SIGNAL(removeEdge(Vertex*,Vertex*)),this,SLOT(removeEdge(Vertex*,Vertex*)));
//        vertex->draw();

//        vertex->setParent(goal);
//        vertex->draw();

//        delete start;
//        start = NULL;
    }
}

void RRT::drawDot(Vertex *vertex)
{
    cv::circle(*map,vertex->getPoint(),smallDotRadius,black,smallDotRadius,8);
    emit updateMap();
    return;
}

void RRT::drawEdge(Vertex *vertex1, Vertex *vertex2)
{
    if(vertex2 != nullptr){
        cv::line(*map,vertex1->getPoint(),vertex2->getPoint(),black);
        emit updateMap();
    }
    return;
}

void RRT::removeDot(Vertex *vertex)
{
    cv::circle(*map,vertex->getPoint(),smallDotRadius,white,smallDotRadius,8);
    emit updateMap();
    return;
}

void RRT::removeEdge(Vertex *vertex1, Vertex *vertex2)
{
    if(vertex2 != nullptr){
        cv::line(*map,vertex1->getPoint(),vertex2->getPoint(),white);
        emit updateMap();
    }
    return;
}

