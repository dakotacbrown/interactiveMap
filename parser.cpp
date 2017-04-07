#include "parser.h"
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QDate>
#include <QStringList>
#include <QTime>

parser :: parser(){
    //this constructor doesn't need to be used.
    //that's why it's empty.

}

parser :: parser(QFile *file, QString place){

    doc = file;
    location.setPattern(place);
    QDate date;
    int x = date.currentDate().dayOfWeek();
    QString day = QDate::longDayName(x);
    cal.setPattern(day);

}

QString parser::loadFile(){
    doc->open((QIODevice::ReadOnly | QIODevice::Text));
    while (!doc->atEnd()) {
        process_line();
    }
    doc->close();

    QString time = QTime::currentTime().toString("h:mm AP");

    if()

    for(int i = 1; i < startDate.size(); i++){
        processed.append(time + " " + beginTime.at(i) + " " + endTime.at(i) + "\n");
    }

    return processed;
}

void parser::process_line(){
    QByteArray line = doc->readLine();
    match = location.match(line);
    match2 = cal.match(line);

    if(match.hasMatch() && match2.hasMatch()){
        QRegularExpression rx("[,]");
        QString string;
        string.append(line);

        QStringList list = string.split(rx);

        startDate.append(list.at(0));
        endDate.append(list.at(1));
        dayOfWeek.append(list.at(2));
        unit.append(list.at(3));
        mealPeriodID.append(list.at(4));
        mealPeriod.append(list.at(5));
        beginTime.append(list.at(6));
        endTime.append(list.at(7));
        course.append(list.at(8));
        itemName.append(list.at(9));
        vegan.append(list.at(10));
        vegetarian.append(list.at(11));
        gluten.append(list.at(12));
        portion.append(list.at(13));
        kcal.append(list.at(14));
        fat.append(list.at(15));
        na.append(list.at(16));
        pro.append(list.at(17));
        carbs.append(list.at(18));
    }
}
