#include "login.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Login window;
    window.setWindowOpacity(.9);
    window.show();
    QApplication::setFont(QFont("Arial", 9, -1, false));
    QApplication::setStyle(QStyleFactory::create("Windows"));
    return QApplication::exec();
}