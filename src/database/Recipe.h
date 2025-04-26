#ifndef RECIPE_H
#define RECIPE_H

#include <QString>
#include <QList>

struct Recipe {
    int id;
    QString name;
    QString imagePath;
    QString instructions;
    // Add other fields as needed

    // Default constructor
    Recipe() : id(-1) {}

    // Convenience constructor
    Recipe(int id, QString name, QString imagePath)
        : id(id), name(name), imagePath(imagePath) {}
};

#endif // RECIPE_H
