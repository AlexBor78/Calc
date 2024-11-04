cmake_minimum_required(VERSION 3.28...3.30)

project(Calc)

#sets 
set(CORE_DIR_PATH "src/CalcCore")
set(CONSOLE_CLIENT_DIR_TATH "src/Console")

add_subdirectory(${CORE_DIR_PATH})
add_subdirectory(${CONSOLE_CLIENT_DIR_TATH})
