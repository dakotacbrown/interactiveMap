#include "location.h"
#include "ui_location.h"
#include <QCoreApplication>
#include <QPushButton>


location::location(QWidget *parent):QWidget(parent),
    ui(new Ui::location){
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::Window);
    this->setWindowModality(Qt::WindowModal);
    QPushButton *close = new QPushButton("&Close", this);
    connect(close, SIGNAL(clicked()), this, SLOT(close()));
}

void location::close(){
   this->close();
}

location::~location(){
    delete ui;
}
