#cmake_minimum_required(VERSION 3.10)
#
## Название вашего проекта
#project(MyProject)
#
#set(SRC_PATH ${CMAKE_SOURCE_DIR}/src)
#
## Установка переменных для путей к библиотеке GLFW
#set(GLFW_ROOT_PATH ${CMAKE_SOURCE_DIR}/../libs/glfw_c)
#set(GLFW_INCLUDE_PATH ${GLFW_ROOT_PATH}/include)
#set(GLFW_LIBRARY_PATH ${GLFW_ROOT_PATH}/lib)
#
## Установка компилятора на C++17 (или другой стандарт, если необходимо)
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED True)
#
## Установка директорий для поиска заголовочных файлов
#include_directories(${GLFW_INCLUDE_PATH})
#
## Установка директорий для поиска библиотек
#link_directories(${GLFW_LIBRARY_PATH})
## Пути к библиотеке glad
#set(GLAD_ROOT_PATH ${CMAKE_SOURCE_DIR}/../libs/glad)
#set(GLAD_INCLUDE_PATH ${GLAD_ROOT_PATH}/include)
#set(GLAD_SOURCE_PATH ${GLAD_ROOT_PATH}/src)
#
## Установка директорий для поиска заголовочных файлов
#include_directories(${GLAD_INCLUDE_PATH})
#
## Добавление исходного файла glad.c
#set(GLAD_SOURCES ${GLAD_SOURCE_PATH}/glad.c)
#
## Добавление исполняемого файла
#add_executable(MyProject ${SRC_PATH}/main.cpp ${GLAD_SOURCES})  # Замените main.cpp на ваш исходный файл
#
## Линковка с библиотекой GLFW
#target_link_libraries(MyProject glfw)  # Убедитесь, что имя библиотеки корректное (обычно glfw или glfw3)
#
## Опционально: если вы используете другие библиотеки, например, OpenGL
#find_package(OpenGL REQUIRED)
#if (OPENGL_FOUND)
#    include_directories(${OPENGL_INCLUDE_DIR})
#    target_link_libraries(MyProject ${OPENGL_LIBRARIES})
#endif()
cmake_minimum_required(VERSION 3.15)
project(my_project)

set(CMAKE_CXX_STANDARD 17)

# Подключение Conan toolchain
include(${CMAKE_BINARY_DIR}/generators/conan_toolchain.cmake)

# Найти пакеты
find_package(glad REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
find_package(imgui REQUIRED)
find_package(assimp REQUIRED)
# Вручную добавить пути включения (если необходимо)
include_directories(${glad_INCLUDE_DIRS})
include_directories(${glfw3_INCLUDE_DIRS})
include_directories(${glm_INCLUDE_DIRS})
include_directories(${imgui_INCLUDE_DIRS})
include_directories(${assimp_INCLUDE_DIRS})

list(APPEND SRC_INCLUDE_FILES 
    src/headers/camera.h 
    src/headers/light.h
    src/headers/mainWindow.h
    src/headers/mesh.h
    src/headers/model.h
    src/headers/shader.h
    src/headers/stb_image.h)

list(APPEND SRC_IMGUI_FILES 
    src/imgui/imgui_impl_glfw.cpp 
    src/imgui/imgui_impl_opengl3.cpp
    src/imgui/imgui_impl_opengl3_loader.h
    src/imgui/imgui_impl_glfw.h
    src/imgui/imgui_impl_opengl3.h)

list(APPEND SRC_FILES 
    src/main.cpp 
    src/camera.cpp 
    src/light.cpp
    src/mainWindow.cpp
    src/shader.cpp
    src/mesh.cpp
    src/model.cpp)

# Создаем исполняемый файл
add_executable(${PROJECT_NAME} ${SRC_INCLUDE_FILES} ${SRC_IMGUI_FILES} ${SRC_FILES})

# Связываем библиотеки с исполняемым файлом
target_link_libraries(${PROJECT_NAME} glad::glad glfw imgui::imgui glm::glm assimp::assimp)
