#include "simviewer.h"

SimViewer::SimViewer(QWidget *parent): QGraphicsView(parent)
{
    this->setFixedSize(800,600);
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    this->setScene(scene);

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    rrtSolver = new RRT();
    connect(rrtSolver,SIGNAL(updateMap()),this,SLOT(updateMap()));
    loadDefaultMap();

}

void SimViewer::mousePressEvent(QMouseEvent *event)
{
    // To set Start/Goal point

    p = event->pos();
//    qDebug() << p;

    if(event->button() == Qt::LeftButton)
    {
        if(!rrtSolver->isStartSetOrNot()){
            startArrow = new Arrow(Qt::red);
            startState.setX(p.x());
            startState.setY(p.y());
            scene->addItem(startArrow);
        }
    }
    else if(event->button() == Qt::RightButton)
    {
        if(!rrtSolver->isGoalSetOrNot()){
            goalArrow = new Arrow(Qt::green);
            goalState.setX(p.x());
            goalState.setY(p.y());
            scene->addItem(goalArrow);
        }
    }

    return;
}

void SimViewer::mouseMoveEvent(QMouseEvent *event)
{

    q = event->pos();

    if(event->buttons() & Qt::LeftButton){
        if(!rrtSolver->isStartSetOrNot())
            startArrow->drawArrow(p,q);
    }
    else if(event->buttons() & Qt::RightButton){
        if(!rrtSolver->isGoalSetOrNot())
            goalArrow->drawArrow(p,q);
    }

    return;
}

void SimViewer::mouseReleaseEvent(QMouseEvent *event)
{
    // To get the orientation of Start/Goal point

//    qDebug() << "Mouse Released!";
    if(event->button() == Qt::LeftButton){
        if(!rrtSolver->isStartSetOrNot()){
            startState.setTheta(startArrow->getCurrentAngleRad());
            startArrow->removeItself();

            rrtSolver->setStart(startState);
        }

    }else if(event->button() == Qt::RightButton){
        if(!rrtSolver->isGoalSetOrNot()){
            goalState.setTheta(goalArrow->getCurrentAngleRad());
            goalArrow->removeItself();

            rrtSolver->setGoal(goalState);
        }

    }

    return;
}

void SimViewer::loadDefaultMap()
{
    qDebug() << "Load DEFAULT MAP!";
    QString fileName = "/home/river85511/Desktop/testMap.png";
    cv::Mat image = cv::imread(fileName.toLatin1().data());
    cv::cvtColor(image,rgbMap,CV_BGR2RGB);

    rrtSolver->setMap(&rgbMap);

    updateMap();
}


void SimViewer::loadMap()
{
    qDebug() << "LOAD MAP!";
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"),".",tr("Image File(*.png *.jpg *.jpeg *.bmp)"));
    cv::Mat image = cv::imread(fileName.toLatin1().data());
    cv::cvtColor(image,rgbMap,CV_BGR2RGB);

    updateMap();
}

void SimViewer::updateMap()
{
    QImage img = QImage((const uchar*)(rgbMap.data),
                        rgbMap.cols,rgbMap.rows,
                        rgbMap.cols*rgbMap.channels(),
                        QImage::Format_RGB888);

    scene->addPixmap(QPixmap::fromImage(img));
}

void SimViewer::startRRT()
{
    rrtSolver->growTree();
}
