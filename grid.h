#ifndef GRID_H
#define GRID_H

#include <QWidget>
#include <QApplication>
#include <QPushButton>

class MainGrid : public QWidget {

    Q_OBJECT

    public:
        MainGrid(QWidget *parent = 0);

    private slots:
        void switchButt(int,int);

    private:
        static const int n = 3;
        static const int num = n*n;

        QPushButton but[n][n];

        int arr[n][n];

};

#endif // GRID_H
