
project(atd-linked-list-test C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dist/${CMAKE_BUILD_TYPE}/bin)

add_executable(${PROJECT_NAME} 
	main.c
)

include_directories(
	${CMAKE_SOURCE_DIR}/src/linked_list
)

link_directories(
	${CMAKE_BINARY_DIR}/dist/${CMAKE_BUILD_TYPE}/lib	
)

target_link_libraries(${PROJECT_NAME}
    adt-linked-list
)

