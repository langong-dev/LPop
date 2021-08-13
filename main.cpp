#include "mainscene.h"
#include "config.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    int returncode = WINDOW_EXIT;
    while (returncode == WINDOW_EXIT)
    {
        QApplication a(argc, argv);
        MainScene w;
        w.show();
        returncode = a.exec();
    }
    return 0;
}
