#include "location.h"
#include "ui_location.h"


location::location(QWidget *parent):QWidget(parent),
    ui(new Ui::location){
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::Window);
    this->setWindowModality(Qt::WindowModal);
}

location::~location(){
    delete ui;
}
