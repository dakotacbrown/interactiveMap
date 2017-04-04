#include "location.h"
#include "ui_location.h"
#include "parser.h"
#include <QCoreApplication>
#include <QPushButton>
#include <QFile>
#include <QGridLayout>
#include <QObject>
#include <QTextStream>
#include <QStringList>
#include <QByteArray>

location::location(QWidget *parent):QWidget(parent),
    ui(new Ui::location){
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::Window);
    this->setWindowModality(Qt::WindowModal);
    QPushButton *close = new QPushButton("&Close", this);
    connect(close, SIGNAL(clicked()), this, SLOT(close()));
}

location::location(QFile &file, QWidget *parent):QWidget(parent),
    ui(new Ui::location){
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::Window);
    this->setWindowModality(Qt::WindowModal);

    doc = &file;
    newText->setReadOnly(true);

    closeButton = new QPushButton("&Close", this);
    displayHours = new QPushButton("&Location Hours", this);

    connect(closeButton, SIGNAL(clicked()), this, SLOT(closeWin()));
    connect(displayHours, SIGNAL(clicked()), this, SLOT(loadHours()));

     QGridLayout *layout = new QGridLayout();
     this->setLayout(layout);
     layout->addWidget (displayHours, 1, 0);
     layout->addWidget (closeButton, 1, 1);
     layout->addWidget (newText, 0, 0, 1, 2);
}

location::location(QFile &file, QFile &file2, QWidget *parent):QWidget(parent),
    ui(new Ui::location){
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::Window);
    this->setWindowModality(Qt::WindowModal);

    doc = &file;
    doc2 = &file2;

    newText->setReadOnly(true);

    closeButton = new QPushButton("&Close", this);
    displayHours = new QPushButton("&Location Hours", this);
    displayMenus = new QPushButton("&Location Menus", this);

    connect(closeButton, SIGNAL(clicked()), this, SLOT(closeWin()));
    connect(displayHours, SIGNAL(clicked()), this, SLOT(loadHours()));
    connect(displayMenus, SIGNAL(clicked()), this, SLOT(loadMenus()));

    QGridLayout *layout = new QGridLayout();
    this->setLayout(layout);
    layout->addWidget (displayHours, 1, 0);
    layout->addWidget(displayMenus, 1, 1);
    layout->addWidget (closeButton, 1, 2);
    layout->addWidget (newText, 0, 0, 1, 3);

}

void location::loadHours(){
    newText->setReadOnly(false);
    newText->clear();
    doc->open((QIODevice::ReadOnly | QIODevice::Text));
    QTextStream in(doc);
    QString line = in.readAll();
    doc->close();

    newText->setHtml(line);
    newText->setReadOnly(true);
}

void location::loadMenus(){
    newText->setReadOnly(false);
    newText->clear();

    parser p = new parser(doc);


    newText->setReadOnly(true);
}

void location::process_line(){
    QByteArray line = doc2->readLine();
    newText->append(line.split('\n').first());
}

void location::closeWin(){
    newText->setReadOnly(false);
    newText->clear();
    newText->setReadOnly(true);
    this->close();
}

location::~location(){
    delete ui;
}
