#include "DishWidget.h"
#include "data/Recipe.h"  // Adjusted path to match your project structure
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>

DishWidget::DishWidget(const Recipe& recipe, QWidget* parent)
    : QWidget(parent),
    imageLabel(new QLabel(this)),
    nameLabel(new QLabel(recipe.name, this))
{
    // Setup image - add null check
    if (!recipe.imagePath.isEmpty()) {
        QPixmap img(recipe.imagePath);
        if (!img.isNull()) {
            imageLabel->setPixmap(img.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        } else {
            imageLabel->setText("Image not found");
            qWarning() << "Failed to load image:" << recipe.imagePath;
        }
    }

    // Setup name label
    nameLabel->setAlignment(Qt::AlignCenter);
    nameLabel->setStyleSheet("font-weight: bold;");

    // Layout
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setContentsMargins(5, 5, 5, 5);
    layout->addWidget(imageLabel);
    layout->addWidget(nameLabel);

    // Styling
    setStyleSheet(R"(
        DishWidget {
            background: white;
            border-radius: 8px;
            border: 1px solid #ddd;
        }
        QLabel { padding: 3px; }
    )");
}
