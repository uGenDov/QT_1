#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QIcon>
#include <QMessageBox>
#include <QRegExpValidator>

class Dialog : public QDialog {
public:
    explicit Dialog(QWidget *parent = nullptr);

    ~Dialog() override;

public:
    QString name() const;
    QString number() const;

    void setName(const QString &name) const;
    void setNumber(const QString &number) const;

private:
    QGridLayout      *gridLayout;
    QLineEdit        *lineEditName;
    QLineEdit        *lineEditNumber;
    QDialogButtonBox *buttonBox;
};
