load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "Matrix",
    srcs = ["Matrix.cpp"],
    hdrs = ["Matrix.hpp"],
)

cc_binary(
    name = "matrixOperators",
    srcs = ["main.cpp"],
    deps = [
        ":Matrix",
    ],
)