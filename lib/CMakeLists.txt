# Cloud communication library
add_library(lib_cloud
    cloud/CloudManager.cpp
)
target_link_libraries(lib_cloud PRIVATE Qt6::Network)

# Oven control library
add_library(lib_oven
    oven/OvenController.cpp
)
target_link_libraries(lib_oven PRIVATE Qt6::Bluetooth)
