cmake_minimum_required(VERSION 3.28...3.30)

project(Console)

#sets 
# set(HEADERS_PATH "include/")

file(GLOB SRC_FILES "*.cpp")
# file(GLOB HEADERS "${HEADERS_PATH}*.h")


# executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} CalcCoreLib)


# target_include_directories(${PROJECT_NAME} PUBLIC ${HEADERS_PATH})
