#ifndef PARSER_H
#define PARSER_H

#include <QFile>
#include <QString>

class parser {

public:
    explicit parser();
    explicit parser(QFile &file);

private:
    QFile *doc = new QFile();
    QString loadFile();
};

#endif // PARSER_H
