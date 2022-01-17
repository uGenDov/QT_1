#include <QApplication>
#include "login.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Login window;
    window.show();
    QApplication::setStyle(QStyleFactory::create("Windows"));
    return QApplication::exec();
}
