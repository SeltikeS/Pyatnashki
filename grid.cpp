#include "grid.h"
#include <QGridLayout>
#include <QDebug>
#include <QString>


// MAIN function
MainGrid::MainGrid(QWidget *parent)
    : QWidget(parent) {

    // Set array of number
    int but_num = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ;
            arr[i][j] = ++but_num;
        }

    }
    // Last button is empty (last number = 0)
    arr[n-1][n-1] = 0;

    // Add grid for buttons
    QGridLayout *grid = new QGridLayout(this);

    // Set buttons array
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Set buttons configuration
            but[i][j].setParent(this);
            but[i][j].setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
            but[i][j].setText(QString("%1").arg(arr[i][j]));
            but[i][j].setStyleSheet("QPushButton {border-width: 2px; border-style: solid; border-color: grey}"
                                    "QPushButton::pressed {border-width: 4px;background: #E3E1E0;border-color: grey}"
                                    "QPushButton {font: bold 150px; }");
            if((arr[i][j])==0) but[i][j].setText(" ");

            // Add buttons to grid
            grid->addWidget(&but[i][j], i, j);

            // Connect buttons to SWITCH function
            connect(&but[i][j], &QPushButton::clicked, this, [=]{switchButt(i,j);});
        }
    }

    // Add grid layout
    setLayout(grid);

}

// SWITCH function
void MainGrid::switchButt(int clickedX,int clickedY) {

    // Set EMPTY button (x,y)
    int zeroButtX = 0;
    int zeroButtY = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(arr[i][j]==0) {
                zeroButtX = i;
                zeroButtY = j;
                break;
            }

        }
    }

    // Only neibor buttons can be clicked
    if(( (abs(zeroButtX - clickedX) <= 1) && (abs(zeroButtY - clickedY) == 0) )  xor  ( (abs(zeroButtY - clickedY) <= 1) && (abs(zeroButtX - clickedX) == 0) )){
        arr[zeroButtX][zeroButtY] = arr[clickedX][clickedY];
        arr[clickedX][clickedY] = 0;
    }

    // Refresh button numbers
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            but[i][j].setText(QString("%1").arg(arr[i][j]));
            if((arr[i][j])==0) but[i][j].setText(" ");
        }
    }
}
