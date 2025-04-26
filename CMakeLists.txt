cmake_minimum_required(VERSION 3.21)

project(Mist LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Quick QuickControls2 Sql)

qt_standard_project_setup()

qt_add_executable(Mist
    main.cpp
    databasemanager.cpp
    databasemanager.h
)

qt_add_qml_module(Mist
    URI Mist
    VERSION 1.0
    QML_FILES
        qml/main.qml
        qml/DishesPage.qml
        qml/RecipePage.qml
)

target_link_libraries(Mist PRIVATE
    Qt6::Quick
    Qt6::QuickControls2
    Qt6::Sql
)

set_target_properties(Mist PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.mist
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_sources(Mist PRIVATE
    src/AppDatabase.cpp
    src/AppDatabase.h
)

target_include_directories(Mist PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
