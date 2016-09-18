#include "state.h"

State::State(double _x, double _y, double _theta):
    x(_x), y(_y), theta(_theta)
{

}

void State::setX(double _x)
{
    x = _x;
}

void State::setY(double _y)
{
    y = _y;
}

void State::setTheta(double _theta)
{
    theta = _theta;
}
