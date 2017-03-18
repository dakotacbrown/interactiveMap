#include "location.h"
#include "ui_location.h"
#include <QCoreApplication>


location::location(QWidget *parent):QWidget(parent),
    ui(new Ui::location){
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::Window);
    this->setWindowModality(Qt::WindowModal);
    connect(ui->close, SIGNAL(clicked()), this, SLOT(close()));
}

location::~location(){
    delete ui;
}
