#include "login.h"

Login::Login(QWidget *parent) : QWidget(parent) {
    this->gridLayout       = new QGridLayout(this);

    this->lineEditName     = new QLineEdit(this);
    this->lineEditPassword = new QLineEdit(this);

    this->line             = new QFrame(this);

    this->buttonOK         = new QPushButton(QIcon("../01_Example/01_Login/Button_done.png"), "OK", this);
    this->buttonCancel     = new QPushButton(QIcon("../01_Example/01_Login/Button_close.png"), "Cancel", this);

    this->lineEditName->setPlaceholderText("Evgenii");
    this->lineEditPassword->setPlaceholderText("15548404000");

    this->lineEditName->setToolTip("Input your name");
    this->lineEditPassword->setToolTip("Input your password");
    this->lineEditName->setToolTipDuration(2000);
    this->lineEditPassword->setToolTipDuration(2000);

    this->lineEditPassword->setEchoMode(QLineEdit::PasswordEchoOnEdit);

    QRegExp regExp("[A-Za-z]{0,10}");
    this->lineEditName->setValidator(new QRegExpValidator(regExp, this));

    this->line->setFrameShape(QFrame::HLine);
    this->line->setFrameShadow(QFrame::Sunken);

    this->gridLayout->addWidget(new QLabel("Name:"), 0, 0);
    this->gridLayout->addWidget(new QLabel("Password:"), 1, 0);
    this->gridLayout->addWidget(this->lineEditName, 0, 1, 1, 2);
    this->gridLayout->addWidget(this->lineEditPassword, 1, 1, 1, 2);
    this->gridLayout->addWidget(this->line, 2, 0, 1, 3);
    this->gridLayout->addWidget(this->buttonOK, 3, 1);
    this->gridLayout->addWidget(this->buttonCancel, 3, 2);

    QObject::connect(this->buttonOK, &QPushButton::clicked, this, [&]() {
        if (this->lineEditName->text().isEmpty() || this->lineEditPassword->text().isEmpty()) {
            QMessageBox::warning(this, "Empty fields", "You didn't fill in name and password field!");
        } else if (this->lineEditName->text() == "Evgenii" && this->lineEditPassword->text() == "15548404000") {
            QMessageBox::information(this, "Correct", "Congratulations", QMessageBox::Ok | QMessageBox::Cancel);
        } else {
            QMessageBox::critical(this, "Wrong", "Your name or password is wrong. Try again", QMessageBox::Retry);
        }
    });

    QObject::connect(this->buttonCancel, &QPushButton::clicked, this, [&]() { Login::close(); });

    Login::setTabOrder(this->lineEditName, this->lineEditPassword);
    Login::setTabOrder(this->lineEditPassword, this->buttonOK);
    Login::setTabOrder(this->buttonOK, this->buttonCancel);

    Login::setFont(QFont("Arial", 9, -1, false));
    Login::setWindowTitle(QString("Login"));
    Login::setWindowIcon(QIcon("../01_Example/01_Login/login.png"));
    Login::setFixedSize(QWidget::sizeHint().width(), QWidget::sizeHint().height());
}

Login::~Login() = default;