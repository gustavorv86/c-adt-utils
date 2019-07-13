
project(adt-stack C)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dist/${CMAKE_BUILD_TYPE}/lib)

add_library(${PROJECT_NAME} SHARED
	stack.c
)

