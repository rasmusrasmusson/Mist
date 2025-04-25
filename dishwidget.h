#ifndef DISHWIDGET_H
#define DISHWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>

class Recipe; // Forward declaration

class DishWidget : public QWidget {
    Q_OBJECT
public:
    explicit DishWidget(const Recipe& recipe, QWidget* parent = nullptr);

private:
    QLabel* imageLabel;
    QLabel* nameLabel;
};

#endif // DISHWIDGET_H
