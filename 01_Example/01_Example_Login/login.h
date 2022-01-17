#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QStyleFactory>

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
