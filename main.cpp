#include <QApplication>
#include <QWidget>
#include "grid.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainGrid window;

    window.resize(350, 350);
    window.setWindowTitle("Piatnashki");
    window.show();


    return app.exec();
}
