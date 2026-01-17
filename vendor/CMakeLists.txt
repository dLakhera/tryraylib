add_subdirectory(raylib)

add_library(vendor INTERFACE)

target_link_libraries(vendor INTERFACE raylib)
