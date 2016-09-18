#include "vertex.h"


Vertex::Vertex(int type, State _state, Vertex *_parent): parent(_parent)
{
    if(type == 0){
        this->setState(_state);
    }else if(type == 1){
        this->setRealState(_state);
    }

    this->setParent(_parent);

}

Vertex::~Vertex()
{
    qDebug() << QString("(%1,%2)").arg(this->state.x).arg(this->state.y) << "Vertex is going to be deleted!";

    if(parent != nullptr){
        emit removeEdge(this,parent);
        parent = nullptr;
    }

    qDebug() << QString("I have %1 child").arg(children.size());
    if(children.size() != 0){
        for(std::list<Vertex *>::iterator iter = children.begin();iter != children.end(); iter++){
            delete *iter;
        }

        children.clear();
    }
    emit this->removeDot(this);

    qDebug() << "Vertex is deleted!";
}

void Vertex::setState(const State &_state)
{
    state = _state;
    realState = this->stateTransform(_state);   //Due to the difference between realWorld Coordinates and Qt/openCV Coordinates

    return;
}

void Vertex::setRealState(const State &_state)
{
    realState = _state;
    state = this->stateTransform(_state);       //Due to the difference between realWorld Coordinates and Qt/openCV Coordinates

    return;
}

State Vertex::stateTransform(const State &_state)
{
    State transState;
    transState.setX(_state.x);
    transState.setY(600 - _state.y);
    transState.setTheta(-_state.theta);

    return transState;
}

void Vertex::setParent(Vertex *_parent)
{
    if(parent != nullptr){
        parent->removeChild(this);
        emit removeEdge(this,parent);
    }

    if(_parent != nullptr){
        _parent->addChild(this);
        parent = _parent;
        emit drawEdge(this,parent);
        return;
    }
}

void Vertex::addChild(Vertex *_child)
{
    children.push_back(_child);
    return;
}

void Vertex::removeChild(Vertex *_child)
{
    std::list<Vertex *>::iterator iter = children.begin();
    for(;iter != children.end(); iter++){
        if(*iter == _child){
            children.erase(iter);
            break;
        }
    }

    return;
}

cv::Point Vertex::getPoint()
{
    return cv::Point(this->state.x,this->state.y);
}

void Vertex::draw()
{
    emit drawDot(this);
    emit drawEdge(this,parent);
}

