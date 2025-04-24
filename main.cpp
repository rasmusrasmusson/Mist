#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "src/database/recipeDatabase.h"  // Ensure this path matches your structure

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Register RecipeDatabase for QML
    qmlRegisterType<RecipeDatabase>("Mist", 1, 0, "RecipeDatabase");

    QQmlApplicationEngine engine;

    // Handle QML load errors
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                     &app, []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);

    // Load QML (use one of these, not both)
    engine.loadFromModule("Mist", "Main");  // If using Qt 6.5+ modules
    // OR for file path:
    // engine.load(QUrl(QStringLiteral("qrc:app/qml/Main.qml")));

    return app.exec();
}
