load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "Polygons",
    srcs = ["Polygons.cpp", "Parallelogram.cpp", "Kite.cpp", "Rectangle.cpp", "Rhombus.cpp", "Square.cpp", "Trapezoid.cpp"],
    hdrs = ["Polygons.hpp", "Parallelogram.hpp", "Kite.hpp", "Rectangle.hpp", "Rhombus.hpp", "Square.hpp", "Trapezoid.hpp"],
)

cc_binary(
    name = "polygons",
    srcs = ["main.cpp"],
    deps = [
        ":Polygons",
    ],
)