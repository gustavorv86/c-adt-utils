
cmake_minimum_required(VERSION 3.0)

project(c-adt-utils)

set(CMAKE_C_STANDARD 11)

add_compile_options(-Wall -Wextra)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug)
endif()

if(NOT DEFINED CMAKE_BUILD_TESTS)
	set(CMAKE_BUILD_TESTS TRUE)
endif()

add_subdirectory(src/stack)
add_subdirectory(src/queue)
add_subdirectory(src/linked_list)
add_subdirectory(src/doubly_linked_list)
add_subdirectory(src/linked_map)
add_subdirectory(src/hash_map)

if(CMAKE_BUILD_TESTS)
	add_subdirectory(src/stack/test)
	add_subdirectory(src/queue/test)
	add_subdirectory(src/linked_list/test)
	add_subdirectory(src/doubly_linked_list/test)
	add_subdirectory(src/linked_map/test)
	add_subdirectory(src/hash_map/test)
endif()

