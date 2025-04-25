cmake_minimum_required(VERSION 3.16)

# Project setup
project(Mist VERSION 1.0 LANGUAGES CXX)

# Enable modern CMake features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt6 packages (with all required modules)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# Enable automatic moc, uic, and rcc
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Add resources
qt_add_resources(RESOURCES resources.qrc)

# Source files
set(SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
)

# Create executable
qt_add_executable(Mist ${SOURCES})

# Link Qt libraries
target_link_libraries(Mist PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

# Install target (optional)
install(TARGETS Mist DESTINATION bin)
