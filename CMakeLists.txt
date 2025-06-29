cmake_minimum_required(VERSION 3.10)
project(FileRAII)

set(CMAKE_CXX_STANDARD 17)

# Создание статической библиотеки
add_library(file STATIC src/File.cpp)

# Подключение заголовков
target_include_directories(file PUBLIC include)

# Создание исполняемого файла
add_executable(demo demo/main.cpp)

# Линковка библиотеки к исполняемому файлу
target_link_libraries(demo PRIVATE file)

# Создание выходной папки для библиотеки и demo
set_target_properties(file PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)
set_target_properties(demo PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
