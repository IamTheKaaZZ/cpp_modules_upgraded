load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "copy_swap",
    srcs = ["copy_vs_move.cpp"],
    hdrs = ["copy_swap.hpp", "move_swap.hpp"],
)

cc_binary(
    name = "moveSwap",
    srcs = ["copy_vs_move.cpp"],
    deps = [
        ":copy_swap",
    ],
)