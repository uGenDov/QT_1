#include <QWidget>
#include <QGridLayout>
#include <QListWidget>
#include <QPushButton>

class ListWidgetAddItem : public QWidget {
public:
    explicit ListWidgetAddItem(QWidget *parent = nullptr);

    ~ListWidgetAddItem() override;

private:
    QGridLayout *gridLayout;
    QVBoxLayout *vLayout;
    QListWidget *listWidget;
    QPushButton *buttonAddNew;
    QPushButton *buttonEdit;
    QPushButton *buttonDelete;
    QPushButton *buttonClearAll;
};
