#include "location.h"
#include "ui_location.h"
#include <QCoreApplication>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <QTextBrowser>
#include <QGridLayout>
#include <QObject>


location::location(QWidget *parent):QWidget(parent),
    ui(new Ui::location){
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::Window);
    this->setWindowModality(Qt::WindowModal);
    QPushButton *close = new QPushButton("&Close", this);
    connect(close, SIGNAL(clicked()), this, SLOT(close()));
}

location::location(const QFile &file, QWidget *parent):QWidget(parent),
    ui(new Ui::location){
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::Window);
    this->setWindowModality(Qt::WindowModal);
    QPushButton *close = new QPushButton("&Close", this);
    connect(close, SIGNAL(clicked()), this, SLOT(closeWin()));

    QTextBrowser *textBox = new QTextBrowser();

    QPushButton *displayHours = new QPushButton("&Location Hours", this);
    connect(displayHours, SIGNAL(clicked()), this, SLOT(readFile(file, textBox)));

     QGridLayout *layout = new QGridLayout ();
     this->setLayout (layout);
     layout->addWidget (close, 0, 0);
     layout->addWidget (displayHours, 0, 1);
     layout->addWidget (textBox, 2, 0);
}

void location::readFile(QFile &file, QTextBrowser &textBox){
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        textBox.setText(line);
    }
}

void location::closeWin(){
   this->close();
}

location::~location(){
    delete ui;
}
