#ifndef RECIPEPAGE_H
#define RECIPEPAGE_H

#include <QWidget>

namespace Ui {
class RecipePage;
}

class RecipePage : public QWidget
{
    Q_OBJECT

public:
    explicit RecipePage(QWidget *parent = nullptr);
    ~RecipePage();

private:
    Ui::RecipePage *ui;
};

#endif // RECIPEPAGE_H
