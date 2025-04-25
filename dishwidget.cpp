#include "DishWidget.h"
#include "Recipe.h"  // Your recipe data class

DishWidget::DishWidget(const Recipe& recipe, QWidget* parent)
    : QWidget(parent)
{
    // Setup image
    imageLabel = new QLabel(this);
    QPixmap img(recipe.imagePath);
    imageLabel->setPixmap(img.scaled(200, 200, Qt::KeepAspectRatio));

    // Setup name
    nameLabel = new QLabel(recipe.name, this);
    nameLabel->setAlignment(Qt::AlignCenter);

    // Layout
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(imageLabel);
    layout->addWidget(nameLabel);

    // Styling
    setStyleSheet("background: white; border-radius: 8px; border: 1px solid #ddd;");
    setFixedSize(220, 250);  // Fixed size for grid alignment
}
