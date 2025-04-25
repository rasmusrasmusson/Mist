#ifndef RECIPEDATABASE_H
#define RECIPEDATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariantMap>
#include <QVariantList>

class RecipeDatabase : public QObject
{
    Q_OBJECT
public:
    explicit RecipeDatabase(QObject *parent = nullptr);
    ~RecipeDatabase();

    // Methods exposed to QML
    Q_INVOKABLE QVariantList getDishes();
    Q_INVOKABLE QVariantMap getRecipe(int id);
    Q_INVOKABLE bool addRecipe(const QString &name, const QString &imagePath, const QString &steps);

signals:  // Moved inside the class declaration
    void recipeLoaded(const QVariantMap &recipe);

private:
    QSqlDatabase m_db;
    void initializeDatabase();
    QString getDatabasePath();
};

#endif // RECIPEDATABASE_H
