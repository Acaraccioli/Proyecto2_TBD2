cmake_minimum_required (VERSION 2.8)
project(main)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(${PROJECT_NAME}  main.cpp Tabla.cpp Gestor.cpp Bloque.cpp  BD.cpp archivo.cpp)