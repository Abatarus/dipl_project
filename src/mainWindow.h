#ifndef WINDOW_H
#define WINDOW_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>


class MainWindow {
  public:
  MainWindow(int wight, int height, std::string title);
  int CheckErrorAndRun();
  private:
  int _height;
  int _wight;
  std::string _title;
  GLFWwindow *_window;
};
#endif