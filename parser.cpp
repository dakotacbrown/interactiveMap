#include "parser.h"
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QStringList>

parser :: parser(){

}

void parser::loadFile(){
    doc->open((QIODevice::ReadOnly | QIODevice::Text));
    while (!doc->atEnd()) {
        process_line();
    }
    doc->close();
}

void parser::process_line(){
    QByteArray line = doc->readLine();
    newText->append(line.split('\n').first());
}
