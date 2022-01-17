#include "dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent) {
    this->gridLayout     = new QGridLayout(this);

    this->labelName      = new QLabel(QString("Name:"), this);
    this->labelNumber    = new QLabel(QString("Number:"), this);

    this->lineEditName   = new QLineEdit(this);
    this->lineEditNumber = new QLineEdit(this);

    this->buttonBox      = new QDialogButtonBox(this);

    this->gridLayout->addWidget(this->labelName, 0, 0);
    this->gridLayout->addWidget(this->lineEditName, 0, 1);
    this->gridLayout->addWidget(this->labelNumber, 1, 0);
    this->gridLayout->addWidget(this->lineEditNumber, 1, 1);
    this->gridLayout->addWidget(this->buttonBox, 2, 1);

    this->buttonBox->setStandardButtons(QDialogButtonBox::Cancel | QDialogButtonBox::Ok);

    QObject::connect(this->buttonBox, &QDialogButtonBox::accepted, this, &Dialog::accept);
    QObject::connect(this->buttonBox, &QDialogButtonBox::rejected, this, &Dialog::reject);

    Dialog::setFont(QFont("Arial", 9, -1, false));
    Dialog::setWindowIcon(QIcon("D:/images/QT_List/add.png"));
    Dialog::setWindowTitle(QString("Add New Item"));
    Dialog::setFixedHeight(QDialog::sizeHint().height());
    Dialog::setFixedWidth(400);
}

QString Dialog::name() const { return this->lineEditName->text().replace("-", "").trimmed(); }

QString Dialog::number() const { return this->lineEditNumber->text().replace("-", "").trimmed(); }

void Dialog::setName(const QString &name) const { this->lineEditName->setText(name); }

void Dialog::setNumber(const QString &number) const { this->lineEditNumber->setText(number); }

Dialog::~Dialog() = default;
