#ifndef STATE_H
#define STATE_H

class State
{
public:
    State(double _x = 0, double _y = 0, double _theta = 0);

    void setX(double _x);
    void setY(double _y);
    void setTheta(double _theta);

    double x;
    double y;
    double theta;
};

#endif // STATE_H
