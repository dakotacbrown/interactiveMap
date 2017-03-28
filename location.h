#ifndef LOCATION_H
#define LOCATION_H

#include <QWidget>
#include <QFile>
#include <QTextEdit>
namespace Ui {
    class location;
}

class location : public QWidget{
    Q_OBJECT

public slots:
    void closeWin();
    void readFile();

public:
    explicit location(QWidget *parent = 0);
    explicit location(QFile &file, QWidget *parent = 0);
    ~location();

protected:
    QTextEdit *newText = new QTextEdit();
    //QTableWidget *newTable = new QTableWidget();
    QFile *doc = new QFile();
    //void process_line(QString);

private:
    Ui::location *ui;
};

#endif // LOCATION_H
