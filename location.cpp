#include "location.h"
#include "ui_location.h"
#include <QCoreApplication>
#include <QPushButton>
#include <QFile>
#include <QGridLayout>
#include <QObject>
#include <QStringList>
#include <QTextStream>

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
    QPushButton *close = new QPushButton("&Close", this);
    connect(close, SIGNAL(clicked()), this, SLOT(closeWin()));

    this->doc = &file;

    QPushButton *displayHours = new QPushButton("&Location Hours", this);
    connect(displayHours, SIGNAL(clicked()), this, SLOT(readFile()));

     QGridLayout *layout = new QGridLayout();
     this->setLayout(layout);
     layout->addWidget (close, 1, 1);
     layout->addWidget (displayHours, 1, 0);
     layout->addWidget (newText, 0, 0, 1, 2);
}

void location::readFile(){
    doc->open((QIODevice::ReadOnly | QIODevice::Text));
    QTextStream in(doc);
    QString line = in.readAll();
    doc->close();

    newText->setPlainText(line);
}

/*void location::readFile(){
    if (!doc->open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QString line;
    QStringList line_data;
    QTextStream in(doc);
    while (!in.atEnd()) {
        QString line = in.readLine();
        process_line(line);
    }
}

void location::process_line(QString line){
    static int row = 0;
    QStringList ss = line.split('\t');
    if(newTable->rowCount() < row + 1)
        newTable->setRowCount(row + 1);
    if(newTable->columnCount() < ss.size())
        newTable->setColumnCount( ss.size() );

    for(int column = 0; column < ss.size(); column++){
        QTableWidgetItem *newItem = new QTableWidgetItem(ss.at(column));
        newTable->setItem(row, column, newItem);
    }
    row++;
}*/

void location::closeWin(){
   this->close();
}

location::~location(){
    delete ui;
}
