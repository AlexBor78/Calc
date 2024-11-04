cmake_minimum_required(VERSION 3.28...3.30)

project(CalcCoreLib)

#sets 
set(HEADERS_PATH "include/")

file(GLOB SRC_FILES "*.cpp")
# file(GLOB HEADERS "${HEADERS_PATH}*.h")


# library
add_library(${PROJECT_NAME} STATIC ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${HEADERS_PATH})
