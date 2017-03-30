#ifndef LOCATION_H
#define LOCATION_H

#include <QWidget>
#include <QFile>
#include <QTextEdit>
#include <QPushButton>

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
    explicit location(QFile &file, QFile &file2, QWidget *parent = 0);
    ~location();

protected:
    QTextEdit *newText = new QTextEdit();
    //QTableWidget *newTable = new QTableWidget();
    QFile *doc = new QFile();
    QFile *doc2 = new QFile();
    QPushButton *closeButton;
    QPushButton *displayHours;
    QPushButton *displayMenus;
    //void process_line(QString);

private:
    Ui::location *ui;
};

#endif // LOCATION_H
