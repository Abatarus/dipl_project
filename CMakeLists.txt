cmake_minimum_required(VERSION 3.10)

# Название вашего проекта
project(MyProject)

# Установка переменных для путей к библиотеке GLFW
set(GLFW_ROOT_PATH ${CMAKE_SOURCE_DIR}/../libs/glfw_c)
set(GLFW_INCLUDE_PATH ${GLFW_ROOT_PATH}/include)
set(GLFW_LIBRARY_PATH ${GLFW_ROOT_PATH}/lib)

# Установка компилятора на C++19 (или другой стандарт, если необходимо)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Установка директорий для поиска заголовочных файлов
include_directories(${GLFW_INCLUDE_PATH})

# Установка директорий для поиска библиотек
link_directories(${GLFW_LIBRARY_PATH})
# Пути к библиотеке glad
set(GLAD_ROOT_PATH ${CMAKE_SOURCE_DIR}/../libs/glad)
set(GLAD_INCLUDE_PATH ${GLAD_ROOT_PATH}/include)
set(GLAD_SOURCE_PATH ${GLAD_ROOT_PATH}/src)

# Установка директорий для поиска заголовочных файлов
include_directories(${GLAD_INCLUDE_PATH})

# Добавление исходного файла glad.c
set(GLAD_SOURCES ${GLAD_SOURCE_PATH}/glad.c)

# Добавление исполняемого файла
add_executable(MyProject main.cpp ${GLAD_SOURCES})  # Замените main.cpp на ваш исходный файл

# Линковка с библиотекой GLFW
target_link_libraries(MyProject glfw)  # Убедитесь, что имя библиотеки корректное (обычно glfw или glfw3)

# Опционально: если вы используете другие библиотеки, например, OpenGL
find_package(OpenGL REQUIRED)
if (OPENGL_FOUND)
    include_directories(${OPENGL_INCLUDE_DIR})
    target_link_libraries(MyProject ${OPENGL_LIBRARIES})
endif()