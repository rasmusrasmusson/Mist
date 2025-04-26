#include "AppDatabase.h"
#include <QStandardPaths>
#include <QDir>
#include <QSqlQuery>
#include <QSqlError>

AppDatabase* AppDatabase::instance()
{
    static AppDatabase instance;
    return &instance;
}

AppDatabase::AppDatabase(QObject *parent) : QObject(parent)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_databasePath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)
                     + "/mist_oven.db";
}

bool AppDatabase::initializeDatabase()
{
    QDir().mkpath(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));

    m_db.setDatabaseName(m_databasePath);
    if (!m_db.open()) {
        qWarning() << "Database error:" << m_db.lastError().text();
        return false;
    }

    return createTables() && seedInitialData();
}

bool AppDatabase::createTables()
{
    QSqlQuery query;

    QStringList tables = {
        "CREATE TABLE IF NOT EXISTS dishes ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "name TEXT NOT NULL,"
        "image_path TEXT,"
        "description TEXT)",

        "CREATE TABLE IF NOT EXISTS recipes ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "dish_id INTEGER,"
        "step_number INTEGER,"
        "instruction TEXT,"
        "temperature INTEGER,"
        "duration INTEGER,"
        "FOREIGN KEY(dish_id) REFERENCES dishes(id))"
    };

    for (const QString &table : tables) {
        if (!query.exec(table)) {
            qWarning() << "Table creation failed:" << query.lastError().text();
            return false;
        }
    }
    return true;
}

bool AppDatabase::seedInitialData()
{
    QSqlQuery query;
    query.exec("SELECT COUNT(*) FROM dishes");

    if (query.next() && query.value(0).toInt() == 0) {
        QStringList seedData = {
            "INSERT INTO dishes (name, description) VALUES "
            "('Chicken Roast', 'Juicy roasted chicken with herbs')",

            "INSERT INTO recipes (dish_id, step_number, instruction, temperature, duration) VALUES "
            "(1, 1, 'Preheat oven', 180, 10),"
            "(1, 2, 'Roast chicken', 180, 60)"
        };

        for (const QString &seed : seedData) {
            if (!query.exec(seed)) {
                qWarning() << "Seeding failed:" << query.lastError().text();
                return false;
            }
        }
    }
    return true;
}

QVariantList AppDatabase::getDishes()
{
    QVariantList dishes;
    QSqlQuery query("SELECT id, name, image_path, description FROM dishes");

    while (query.next()) {
        dishes.append(QVariantMap{
            {"id", query.value(0)},
            {"name", query.value(1)},
            {"image", query.value(2)},
            {"description", query.value(3)}
        });
    }
    return dishes;
}

QVariantMap AppDatabase::getRecipe(int dishId)
{
    QVariantMap recipe;
    QSqlQuery query;

    query.prepare("SELECT name, description FROM dishes WHERE id = ?");
    query.addBindValue(dishId);
    if (query.exec() && query.next()) {
        recipe["name"] = query.value(0);
        recipe["description"] = query.value(1);
    }

    query.prepare("SELECT step_number, instruction, temperature, duration "
                  "FROM recipes WHERE dish_id = ? ORDER BY step_number");
    query.addBindValue(dishId);

    QVariantList steps;
    if (query.exec()) {
        while (query.next()) {
            steps.append(QVariantMap{
                {"number", query.value(0)},
                {"instruction", query.value(1)},
                {"temperature", query.value(2)},
                {"duration", query.value(3)}
            });
        }
    }
    recipe["steps"] = steps;

    return recipe;
}

bool AppDatabase::addDish(const QString &name, const QString &description)
{
    QSqlQuery query;
    query.prepare("INSERT INTO dishes (name, description) VALUES (?, ?)");
    query.addBindValue(name);
    query.addBindValue(description);
    return query.exec();
}
