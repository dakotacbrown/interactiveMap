#ifndef PARSER_H
#define PARSER_H

#include <QFile>
#include <QString>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QStringList>

class parser {

public:
    explicit parser();
    explicit parser(QFile *file, QString place);
    QString loadFile();
    void process_line();

private:
    QFile *doc = new QFile();
    QString processed;
    QRegularExpression location;
    QRegularExpression cal;
    QRegularExpressionMatch match;
    QRegularExpressionMatch match2;
    QStringList startDate;
    QStringList endDate;
    QStringList dayOfWeek;
    QStringList unit;
    QStringList mealPeriodID;
    QStringList mealPeriod;
    QStringList beginTime;
    QStringList endTime;
    QStringList course;
    QStringList itemName;
    QStringList vegan;
    QStringList vegetarian;
    QStringList gluten;
    QStringList portion;
    QStringList kcal;
    QStringList fat;
    QStringList na;
    QStringList pro;
    QStringList carbs;
};

#endif // PARSER_H
