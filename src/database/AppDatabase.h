#pragma once

#include <QObject>
#include <QSqlDatabase>
#include <QtQmlIntegration>  // Add for QML integration

class AppDatabase : public QObject
{
    Q_OBJECT
    QML_ELEMENT         // Enable QML registration
    QML_SINGLETON       // Make it a singleton

public:
    explicit AppDatabase(QObject *parent = nullptr);

    Q_INVOKABLE bool initializeDatabase();  // Make invokable from QML
    Q_INVOKABLE QVariantList getDishes();
    Q_INVOKABLE QVariantMap getRecipe(int dishId);
    Q_INVOKABLE bool addDish(const QString &name, const QString &description);  // Example new method

    static AppDatabase* instance();  // Singleton accessor

private:
    QSqlDatabase m_db;
    QString m_databasePath;

    bool createTables();  // Split table creation into separate method
    bool seedInitialData();  // Separate initial data population
};
