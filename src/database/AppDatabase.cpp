#include "AppDatabase.h"
#include <QStandardPaths>
#include <QDir>
#include <QDebug>
#include <QSqlError>
#include <QCoreApplication>

RecipeDatabase::RecipeDatabase(QObject *parent) : QObject(parent)
{
    // Initialize database connection
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbPath = getDatabasePath();
    m_db.setDatabaseName(dbPath);

    qDebug() << "Connecting to database at:" << dbPath;

    if (!m_db.open()) {
        qCritical() << "Database open error:" << m_db.lastError().text();
        return;
    }

    // Verify driver features
    qDebug() << "SQLite version:" << m_db.driver()->property("version").toString();
    qDebug() << "SQLite features:" << m_db.driver()->hasFeature(QSqlDriver::Transactions);

    initializeDatabase();
}

RecipeDatabase::~RecipeDatabase()
{
    if (m_db.isOpen()) {
        qDebug() << "Closing database connection";
        m_db.close();
    }
}

QString RecipeDatabase::getDatabasePath()
{
    QString path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir dir(path);

    if (!dir.exists()) {
        qDebug() << "Creating app data directory:" << path;
        if (!dir.mkpath(path)) {
            qWarning() << "Failed to create app data directory!";
            // Fallback to executable directory
            path = QCoreApplication::applicationDirPath();
        }
    }

    QString dbPath = path + "/mist_recipes.db";
    qDebug() << "Database path:" << dbPath;
    return dbPath;
}

void RecipeDatabase::initializeDatabase()
{
    if (!m_db.isOpen()) {
        qCritical() << "Database not open for initialization!";
        return;
    }

    QSqlQuery query;
    QStringList tables = m_db.tables();
    qDebug() << "Existing tables:" << tables;

    if (!query.exec(
            "CREATE TABLE IF NOT EXISTS Dishes ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "name TEXT NOT NULL, "
            "imagePath TEXT, "
            "steps TEXT, "
            "created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP)"))
    {
        qCritical() << "Create table error:" << query.lastError().text();
        return;
    }

    // Check if table is empty
    if (query.exec("SELECT COUNT(*) FROM Dishes") && query.next()) {
        int count = query.value(0).toInt();
        qDebug() << "Found" << count << "existing recipes";

        if (count == 0) {
            qDebug() << "Inserting sample recipes";
            addRecipe("Pizza", "qrc:/assets/images/pizza.jpg",
                      "1. Preheat oven to 220°C\n"
                      "2. Roll out dough\n"
                      "3. Add toppings\n"
                      "4. Bake for 12-15 minutes");

            addRecipe("Bread", "qrc:/assets/images/bread.jpg",
                      "1. Mix ingredients\n"
                      "2. Knead dough\n"
                      "3. Let rise\n"
                      "4. Bake at 200°C for 30 minutes");
        }
    } else {
        qWarning() << "Failed to count recipes:" << query.lastError().text();
    }
}

QVariantList RecipeDatabase::getDishes()
{
    QVariantList dishes;

    if (!m_db.isOpen()) {
        qWarning() << "Database not open!";
        return dishes;
    }

    QSqlQuery query("SELECT id, name, imagePath FROM Dishes ORDER BY name");
    while (query.next()) {
        QVariantMap dish;
        dish["id"] = query.value(0);
        dish["name"] = query.value(1);
        dish["imagePath"] = query.value(2);
        dishes.append(dish);
    }

    qDebug() << "Loaded" << dishes.count() << "dishes";
    return dishes;
}

QVariantMap RecipeDatabase::getRecipe(int id)
{
    QVariantMap recipe;

    if (!m_db.isOpen()) {
        qWarning() << "Database not open!";
        return recipe;
    }

    QSqlQuery query;
    query.prepare("SELECT name, imagePath, steps FROM Dishes WHERE id = ?");
    query.addBindValue(id);

    if (query.exec() && query.next()) {
        recipe["name"] = query.value(0);
        recipe["imagePath"] = query.value(1);
        recipe["steps"] = query.value(2).toString().split('\n');
        qDebug() << "Loaded recipe:" << recipe["name"];
    } else {
        qWarning() << "Recipe load error:" << query.lastError().text();
    }

    emit recipeLoaded(recipe);
    return recipe;
}

bool RecipeDatabase::addRecipe(const QString &name, const QString &imagePath, const QString &steps)
{
    if (!m_db.isOpen()) {
        qWarning() << "Database not open!";
        return false;
    }

    QSqlQuery query;
    query.prepare(
        "INSERT INTO Dishes (name, imagePath, steps) "
        "VALUES (:name, :imagePath, :steps)");
    query.bindValue(":name", name);
    query.bindValue(":imagePath", imagePath);
    query.bindValue(":steps", steps);

    if (!query.exec()) {
        qCritical() << "Add recipe failed:" << query.lastError().text()
        << "\nQuery:" << query.lastQuery();
        return false;
    }

    qDebug() << "Added recipe:" << name;
    return true;
}

Q_INVOKABLE bool RecipeDatabase::clearDatabase()
{
    if (!m_db.isOpen()) return false;

    m_db.transaction();
    QSqlQuery query("DELETE FROM Dishes");
    if (!query.exec()) {
        m_db.rollback();
        return false;
    }
    return m_db.commit();
}

Q_INVOKABLE bool RecipeDatabase::backupDatabase(const QString &path)
{
    if (!m_db.isOpen()) return false;

    QString backupPath = QDir::toNativeSeparators(path + "/mist_recipes_backup.db");
    QFile::remove(backupPath);
    return QFile::copy(m_db.databaseName(), backupPath);
}
