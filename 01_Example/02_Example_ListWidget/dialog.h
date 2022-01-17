#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QIcon>

class Dialog : public QDialog {
private:
    Q_OBJECT
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
    QLabel           *labelName;
    QLabel           *labelNumber;
    QLineEdit        *lineEditName;
    QLineEdit        *lineEditNumber;
    QDialogButtonBox *buttonBox;
};
