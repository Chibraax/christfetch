from conan import ConanFile

class ChristFetch(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    def requirements(self):
        self.requires("nlohmann_json/3.11.3")
        self.requires("argparse/3.2")
        self.requires("fmt/11.1.3")

    def build_requirements(self):
        self.tool_requires("cmake/3.22.6")