cmake_minimum_required(VERSION 3.16)

# Project setup
project(Mist VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt packages
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Sql)

# Enable automatic moc, uic, and rcc
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Source files - UPDATE THESE PATHS TO MATCH YOUR ACTUAL FILES
set(SOURCES
    main.cpp
    DishWidget.cpp
    dishespage.cpp
    recipepage.cpp
    src/database/AppDatabase.cpp  # Renamed from recipedatabase.cpp
)

# UI files
set(FORMS
    dishespage.ui
    recipepage.ui
)

# Resources
qt_add_resources(RESOURCES
    resources.qrc
)

# Include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/database
)

# Create executable
qt_add_executable(Mist
    ${SOURCES}
    ${FORMS}
    ${RESOURCES}
)

# Link Qt libraries
target_link_libraries(Mist PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Sql
)

# Install target (optional)
install(TARGETS Mist DESTINATION bin)
