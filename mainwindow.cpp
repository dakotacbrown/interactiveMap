#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "location.h"
#include <QPixmap>
#include <QPalette>
#include <QRect>
#include <QMouseEvent>

    location *offen;
    location *oaks;
    location *btsu;
    location *founders;
    location *olscamp;
    location *carillon;
    location *library;
    location *kreischer;

    QRect offenRect = QRect(21, 55, 54, 85);
    QRect oaksRect = QRect(40, 325, 125, 75);
    QRect btsuRect = QRect(190, 430, 115, 205);
    QRect foundersRect = QRect(25, 820, 158, 105);
    QRect olscampRect = QRect(520, 430, 135, 120);
    QRect carillonRect = QRect(575, 785, 95, 60);
    QRect libraryRect = QRect(835, 610, 90, 95);
    QRect kreischerRect = QRect(1225, 475, 230, 150);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){

    ui->setupUi(this);
    offen = new location(this);
    oaks = new location(this);
    btsu = new location(this);
    founders = new location(this);
    olscamp = new location(this);
    carillon = new location(this);
    library = new location(this);
    kreischer = new location(this);

    /**This block of code initializes the screen to be a fixed size. That way it cannont be moved.
    /  It loads the blank map image stored in resources and makes it the window background.
    **/
    this->setFixedSize(1470,1213);
    QPixmap bkgnd(":/myresources/blank.jpg");  //Load pic
    bkgnd = bkgnd.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation); //set scale of pic to match the window
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);//set the pic to the background
    this->setPalette(palette); //show the background pic
}

/**This function makes the screen size fixed so it cannont be moved.
/  It loads the blank map image stored in resources and makes it the window background.
**/
void MainWindow::resizeEvent(QResizeEvent *evt){
    QPixmap bkgnd(":/myresources/blank.jpg");//Load pic
    bkgnd = bkgnd.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);//set scale of pic to match the window
    QPalette p = palette(); //copy current, not create new
    p.setBrush(QPalette::Background, bkgnd);//set the pic to the background
    setPalette(p);//show the background pic

    QMainWindow::resizeEvent(evt); //call base implementation
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    if(event->buttons() == Qt::LeftButton && offenRect.contains(event->pos())){
        QPixmap bkgnd(":/myresources/offenhauer.jpg");//Load pic
        bkgnd = bkgnd.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);//set scale of pic to match the window
        QPalette p = palette(); //copy current, not create new
        p.setBrush(QPalette::Background, bkgnd);//set the pic to the background
        setPalette(p);
        offen->show();
    }

    else if(event->buttons() == Qt::LeftButton && oaksRect.contains(event->pos())){
        QPixmap bkgnd(":/myresources/oaks.jpg");//Load pic
        bkgnd = bkgnd.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);//set scale of pic to match the window
        QPalette p = palette(); //copy current, not create new
        p.setBrush(QPalette::Background, bkgnd);//set the pic to the background
        setPalette(p);
        oaks->show();
    }

    else if(event->buttons() == Qt::LeftButton && btsuRect.contains(event->pos())){
        QPixmap bkgnd(":/myresources/btsu.jpg");//Load pic
        bkgnd = bkgnd.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);//set scale of pic to match the window
        QPalette p = palette(); //copy current, not create new
        p.setBrush(QPalette::Background, bkgnd);//set the pic to the background
        setPalette(p);
        btsu->show();
    }

    else if(event->buttons() == Qt::LeftButton && foundersRect.contains(event->pos())){
        QPixmap bkgnd(":/myresources/founders.jpg");//Load pic
        bkgnd = bkgnd.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);//set scale of pic to match the window
        QPalette p = palette(); //copy current, not create new
        p.setBrush(QPalette::Background, bkgnd);//set the pic to the background
        setPalette(p);
        founders->show();
    }

    else if(event->buttons() == Qt::LeftButton && olscampRect.contains(event->pos())){
        QPixmap bkgnd(":/myresources/olscamp.jpg");//Load pic
        bkgnd = bkgnd.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);//set scale of pic to match the window
        QPalette p = palette(); //copy current, not create new
        p.setBrush(QPalette::Background, bkgnd);//set the pic to the background
        setPalette(p);
        olscamp->show();
    }

    else if(event->buttons() == Qt::LeftButton && carillonRect.contains(event->pos())){
        QPixmap bkgnd(":/myresources/carillon.jpg");//Load pic
        bkgnd = bkgnd.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);//set scale of pic to match the window
        QPalette p = palette(); //copy current, not create new
        p.setBrush(QPalette::Background, bkgnd);//set the pic to the background
        setPalette(p);
        carillon->show();
    }

    else if(event->buttons() == Qt::LeftButton && libraryRect.contains(event->pos())){
        QPixmap bkgnd(":/myresources/library.jpg");//Load pic
        bkgnd = bkgnd.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);//set scale of pic to match the window
        QPalette p = palette(); //copy current, not create new
        p.setBrush(QPalette::Background, bkgnd);//set the pic to the background
        setPalette(p);
        library->show();
    }

    else if(event->buttons() == Qt::LeftButton && kreischerRect.contains(event->pos())){
        QPixmap bkgnd(":/myresources/kreischer.jpg");//Load pic
        bkgnd = bkgnd.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);//set scale of pic to match the window
        QPalette p = palette(); //copy current, not create new
        p.setBrush(QPalette::Background, bkgnd);//set the pic to the background
        setPalette(p);
        kreischer->show();
    }
    QMainWindow::mouseMoveEvent(event);
}

MainWindow::~MainWindow(){
    delete ui;
}
