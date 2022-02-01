load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "UniquePtr",
    srcs = [],
    hdrs = ["../task0/UniquePtr.hpp", "../task0/moveSwap.hpp", "../task0/BasePtr.hpp"],
)

cc_library(
    name = "SharedPtr",
    srcs = [],
    hdrs = ["SharedPtr.hpp"],
)

cc_binary(
    name = "spcases",
    srcs = ["main.cpp"],
    deps = [
        ":UniquePtr",
        ":SharedPtr",
    ],
)