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

    root = start;
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

        for(int i =0; i<5; i++){

        State state = genSampleState();
        qDebug() << state.x << state.y << state.theta;
        Vertex* vertex = new Vertex(1,state,root);
            connect(vertex,SIGNAL(drawDot(Vertex*)),this,SLOT(drawDot(Vertex*)));
            connect(vertex,SIGNAL(drawEdge(Vertex*,Vertex*)),this,SLOT(drawEdge(Vertex*,Vertex*)));
            connect(vertex,SIGNAL(removeDot(Vertex*)),this,SLOT(removeDot(Vertex*)));
            connect(vertex,SIGNAL(removeEdge(Vertex*,Vertex*)),this,SLOT(removeEdge(Vertex*,Vertex*)));
            vertex->draw();
        }



    }
}

State RRT::genSampleState()
{
    State realState;

    double x_init     = root->realState.x;
    double y_init     = root->realState.y;
    double theta_init = root->realState.theta;

    double r0          = 100.0;
    double sigma_r     = 5.0;
    double sigma_theta = 0.1*PI;

    double r     = abs(gauss_distribution(0,sigma_r)) + r0;
    double theta = gauss_distribution(0,sigma_theta)  + theta_init;

    qDebug() << theta;

    double sx = x_init + r*cos(theta);
    double sy = y_init + r*sin(theta);

    realState.setX(sx);
    realState.setY(sy);
    realState.setTheta(theta);

    return realState;
}

double RRT::gauss_distribution(double mean, double std)
{
    double u = rand() / (double)RAND_MAX;//RAND_MAX=32767
    double v = rand() / (double)RAND_MAX;

    return sqrt(-2 * log(u)) * cos(2 * M_PI * v) * std + mean; //M_PI=3.14159
}

void RRT::updateTreeVector(Vertex *vertex)
{
    if(vertex->children.size() != 0){
        std::list<Vertex *>::const_iterator iter = vertex->children.begin();
        for(;iter != vertex->children.end(); iter++){
            updateTreeVector(*iter);
        }
    }

    treeVector.push_back(vertex);

    return;
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

