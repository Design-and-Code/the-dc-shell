cmake_minimum_required(VERSION 3.0)

project(the-dc-shell)

include_directories(${PROJECT_SOURCE_DIR}/headers)

add_executable(${PROJECT_NAME} main.c shell_utils.c utils.c)
