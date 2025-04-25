cmake_minimum_required(VERSION 3.16)

# Project setup
project(Mist VERSION 1.0 LANGUAGES CXX)

# Enable modern CMake features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt6 packages - ADD SQL FOR DATABASE
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Sql)

# Enable automatic moc, uic, and rcc
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Source files
set(SOURCES
    main.cpp
    dishespage.cpp
    recipepage.cpp
    DishWidget.cpp
    database/DatabaseManager.cpp
)

# UI files (forms)
set(FORMS
    dishespage.ui
    recipepage.ui
)

# Add resources (only need to declare once)
qt_add_resources(RESOURCES resources.qrc)

# Image resources (add this below your existing qt_add_resources)
qt_add_resources(RESOURCES
    resources.qrc
    # Add more .qrc files here if needed later
    # images.qrc  # Example for additional resource files
)

# Create executable - INCLUDES FORMS
qt_add_executable(Mist
    ${SOURCES}
    ${FORMS}
)

# Link Qt libraries - ADD SQL
target_link_libraries(Mist PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Sql
)

# Install target (optional)
install(TARGETS Mist DESTINATION bin)
