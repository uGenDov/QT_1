#include <QWidget>
#include <QApplication>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QStyleFactory>
#include <QRegExpValidator>

class Login : public QWidget {
public:
    explicit Login(QWidget *parent = nullptr);

    ~Login() override;

private:
    QGridLayout *gridLayout;
    QLineEdit   *lineEditName;
    QLineEdit   *lineEditPassword;
    QFrame      *line;
    QPushButton *buttonOK;
    QPushButton *buttonCancel;
};