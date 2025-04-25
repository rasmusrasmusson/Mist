#include "dishespage.h"
#include "DishWidget.h"
#include "database/AppDatabase.h"  // Your renamed database class
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>

DishesPage::DishesPage(QWidget *parent)
    : QWidget(parent)
{
    // Main layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(10, 10, 10, 10);
    mainLayout->setSpacing(15);

    // Title label
    QLabel *titleLabel = new QLabel("Available Dishes", this);
    titleLabel->setStyleSheet("font-size: 24px; font-weight: bold;");
    titleLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(titleLabel);

    // Dishes grid layout
    QGridLayout *dishesGrid = new QGridLayout();
    dishesGrid->setSpacing(20);

    // Load dishes from database
    try {
        auto dishes = AppDatabase::instance().getAllDishes();

        int row = 0, col = 0;
        const int maxColumns = 3;  // 3 dishes per row

        for (const auto &dish : dishes) {
            DishWidget *dishWidget = new DishWidget(dish, this);
            dishesGrid->addWidget(dishWidget, row, col++);

            if (col >= maxColumns) {
                col = 0;
                row++;
            }
        }
    } catch (const std::exception &e) {
        qCritical() << "Failed to load dishes:" << e.what();
    }

    mainLayout->addLayout(dishesGrid);
    setLayout(mainLayout);
}

// Slot example for when a dish is selected
void DishesPage::onDishSelected(int dishId)
{
    qDebug() << "Selected dish ID:" << dishId;
    emit dishSelected(dishId);  // Forward the signal
}
