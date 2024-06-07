from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps
from conan.tools.files import copy

class MyProjectConan(ConanFile):
    name = "my_project"
    version = "1.0"
    
    # Зависимости проекта
    requires = (
        "glad/0.1.36",
        "glfw/3.4",
        "glm/1.0.1",
        "imgui/1.89.4",
        "assimp/5.4.1"
    )
  
    
    # Настройки сборки
    settings = "os", "compiler", "build_type", "arch"
    
    def layout(self):
        cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()
        deps = CMakeDeps(self)
        deps.generate()
        
    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
