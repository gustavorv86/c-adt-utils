
project(adt-hash-map C)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dist/${CMAKE_BUILD_TYPE}/lib)

add_library(${PROJECT_NAME} SHARED
	../linked_map/linked_map.c
	hash_map.c
)

target_include_directories(${PROJECT_NAME} PUBLIC
	../linked_map
)
