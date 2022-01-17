#include "listwidgetadditem.h"
#include "dialog.h"

ListWidgetAddItem::ListWidgetAddItem(QWidget *parent) : QWidget(parent) {
    this->gridLayout     = new QGridLayout(this);
    this->vLayout        = new QVBoxLayout();

    this->listWidget     = new QListWidget(this);

    this->buttonAddNew   = new QPushButton(QString("Add New Item"), this);
    this->buttonEdit     = new QPushButton(QString("Edit Item"), this);
    this->buttonDelete   = new QPushButton(QString("Delete Item"), this);
    this->buttonClearAll = new QPushButton(QString("Clear All"), this);

    this->vLayout->addWidget(this->buttonAddNew);
    this->vLayout->addWidget(this->buttonEdit);
    this->vLayout->addWidget(this->buttonDelete);
    this->vLayout->addItem(new QSpacerItem(20, 80, QSizePolicy::Minimum, QSizePolicy::Expanding));
    this->vLayout->addWidget(this->buttonClearAll);

    this->gridLayout->addWidget(this->listWidget);

    this->gridLayout->addLayout(this->vLayout, 0, 1);

    QObject::connect(this->buttonAddNew, &QPushButton::clicked, this, [&]() {
        Dialog dialog(this);
        if (dialog.exec()) this->listWidget->addItem(dialog.name() + " - " + dialog.number());
    });

    QObject::connect(this->buttonEdit, &QPushButton::clicked, this->listWidget, [&]() {
        if (!this->listWidget->currentItem()) return;

        QStringList parts = this->listWidget->currentItem()->text().split("-");

        Dialog dialog(this);
        dialog.setName(parts[0].trimmed());
        dialog.setNumber(parts[1].trimmed());

        if (dialog.exec()) this->listWidget->currentItem()->setText(dialog.name() + " - " + dialog.number());
    });

    QObject::connect(this->buttonDelete, &QPushButton::clicked, this->listWidget, [&]() {
        delete this->listWidget->currentItem();
    });

    QObject::connect(this->buttonClearAll, &QPushButton::clicked, this->listWidget, [&]() {
        this->listWidget->clear();
    });

    ListWidgetAddItem::setFont(QFont("Arial", 9, -1, false));
    ListWidgetAddItem::setWindowTitle(QString("ListWidget"));
    ListWidgetAddItem::setWindowIcon(QIcon("../01_Example/02_Example_ListWidget/list.png"));
}

ListWidgetAddItem::~ListWidgetAddItem() = default;
