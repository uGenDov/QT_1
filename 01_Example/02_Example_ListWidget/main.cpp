#include <QApplication>
#include <QStyleFactory>
#include "listwidgetadditem.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    ListWidgetAddItem window;
    window.show();
    QApplication::setStyle(QStyleFactory::create("Windows"));
    return QApplication::exec();
}