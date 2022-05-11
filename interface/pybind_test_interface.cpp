#include <pybind11/pybind11.h>

#include <arithmetic.h>
#include <image.h>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

PYBIND11_MODULE(pybind_test, m) {
    m.doc() = "Pybind test module";

    // Basic arithmetic functions.
    m.def("add", &add, "Add two numbers.");
    m.def("subtract", &subtract, "Subtract two numbers");

    // Basic image loading functions.
    m.def("load_and_save", &load_and_save, "Load and save target image.");

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}