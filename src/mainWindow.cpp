#include "mainWindow.h"
#include <iostream>
MainWindow::MainWindow(int wight, int height, std::string title) {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  _wight = wight;
  _height = height;
  _title = title;
}

int MainWindow::CheckErrorAndRun() {
  _window = glfwCreateWindow(_wight, _height, _title.c_str(), NULL, NULL);
  if (_window == NULL)
  {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(_window);
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }
  while (!glfwWindowShouldClose(_window))
  {
    glfwSwapBuffers(_window);
    glfwPollEvents();
  }
  glfwTerminate();
  return 0;
}