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
    void loadHours();
    void loadMenus();

public:
    explicit location(QWidget *parent = 0);
    explicit location(QFile &file, QWidget *parent = 0);
    explicit location(QString place, QFile &file, QFile &file2, QWidget *parent = 0);
    void process_line();
    ~location();

private:
    Ui::location *ui;
    QTextEdit *newText = new QTextEdit();
    QFile *doc = new QFile();
    QFile *doc2 = new QFile();
    QString local;
    QPushButton *closeButton;
    QPushButton *displayHours;
    QPushButton *displayMenus;
};

#endif // LOCATION_H
