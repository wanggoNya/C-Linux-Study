ADD_EXECUTABLE( b.out b.c )
find_package(json-c CONFIG)
target_link_libraries(${PROJECT_NAME} PRIVATE json-c::json-c)
