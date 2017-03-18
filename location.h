#ifndef LOCATION_H
#define LOCATION_H

#include <QWidget>

namespace Ui {
    class location;
}

class location : public QWidget{
    Q_OBJECT

public:
    explicit location(QWidget *parent = 0);
    ~location();

private:
    Ui::location *ui;
};

#endif // LOCATION_H
