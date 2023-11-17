cmake_minimum_required(VERSION 3.10)

project(task)

include_directories (database exporter parser placement)

aux_source_directory (database SRC_LIST1)
aux_source_directory (exporter SRC_LIST2)
aux_source_directory (parser SRC_LIST3)
aux_source_directory (placement SRC_LIST4)

add_executable(task main.cpp ${SRC_LIST1} ${SRC_LIST2} ${SRC_LIST3} ${SRC_LIST4})
