add_executable(trylib)

file(GLOB SRC_FILES    
    "*.cpp"
)

target_sources(trylib PRIVATE ${SRC_FILES})
target_link_libraries(trylib PRIVATE vendor)
