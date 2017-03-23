#ifndef LOCATION_H
#define LOCATION_H

#include <QWidget>
#include <QFile>
#include <QTextBrowser>

namespace Ui {
    class location;
}

class location : public QWidget{
    Q_OBJECT

public:
    explicit location(QWidget *parent = 0);
    explicit location(const QFile &file, QWidget *parent = 0);
    ~location();

public slots:
    void closeWin();
    void readFile(QFile &file, QTextBrowser &textBox);

private:
    Ui::location *ui;
};

#endif // LOCATION_H
