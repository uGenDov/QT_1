#include "dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent) {
    this->gridLayout     = new QGridLayout(this);
    this->lineEditName   = new QLineEdit(this);
    this->lineEditNumber = new QLineEdit(this);
    this->buttonBox      = new QDialogButtonBox(this);

    //------------------------------------------------------------------------------------------------------------------

    this->lineEditName->setClearButtonEnabled(true);
    this->lineEditNumber->setClearButtonEnabled(true);

    this->lineEditName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]{0,10}"), this));
    this->lineEditNumber->setValidator(new QRegExpValidator(QRegExp("[0-9]{0,4}"), this));

    this->gridLayout->addWidget(new QLabel("Name:"), 0, 0);
    this->gridLayout->addWidget(new QLabel("Number:"), 1, 0);
    this->gridLayout->addWidget(this->lineEditName, 0, 1);
    this->gridLayout->addWidget(this->lineEditNumber, 1, 1);
    this->gridLayout->addWidget(this->buttonBox, 2, 1);

    this->buttonBox->setStandardButtons(QDialogButtonBox::Cancel | QDialogButtonBox::Ok);

    //------------------------------------------------------------------------------------------------------------------

    QObject::connect(this->buttonBox, &QDialogButtonBox::accepted, this, [&]() {
        if (this->lineEditName->text().isEmpty() && this->lineEditNumber->text().isEmpty()) {
            QMessageBox::warning(this, "Empty fields", "You didn't enter an item name and item number");
            return;
        } else this->accept();
    });

    QObject::connect(this->buttonBox, &QDialogButtonBox::rejected, this, &Dialog::reject);

    Dialog::setFont(QFont("Arial", 9, -1, false));
    Dialog::setWindowIcon(QIcon("../01_Example/02_Example_ListWidget/add.png"));
    Dialog::setWindowTitle("Add New Item");
    Dialog::setFixedHeight(QDialog::sizeHint().height());
    Dialog::setFixedWidth(400);
}

QString Dialog::name() const { return this->lineEditName->text().replace("-", "").trimmed(); }

QString Dialog::number() const { return this->lineEditNumber->text().replace("-", "").trimmed(); }

void Dialog::setName(const QString &name) const { this->lineEditName->setText(name); }

void Dialog::setNumber(const QString &number) const { this->lineEditNumber->setText(number); }

Dialog::~Dialog() = default;
