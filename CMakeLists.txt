cmake_minimum_required(VERSION 3.16)
project(Mist VERSION 1.0.0 LANGUAGES CXX)

# Set default build type if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Explicitly set build types
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configurations" FORCE)

# Find Qt packages
find_package(Qt6 REQUIRED COMPONENTS Quick Sql Network)

# Source files
file(GLOB SOURCES
    "main.cpp"
    "src/database/recipedatabase.cpp"
)

# Executable
qt_add_executable(Mist ${SOURCES})

# QML configuration
qt_add_qml_module(Mist
    URI Mist
    VERSION 1.0
    QML_FILES
        "app/qml/Main.qml"
        "app/qml/screens/DishesPage.qml"
        "app/qml/screens/RecipePage.qml"
    RESOURCES
        "assets/images/bread.jpg"
        "assets/images/pizza.jpg"
)

# Link libraries
target_link_libraries(Mist PRIVATE
    Qt6::Quick
    Qt6::Sql
    Qt6::Network
)

# Include directories
target_include_directories(Mist PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src/database"
)
