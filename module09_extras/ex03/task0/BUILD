load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "UniquePtr",
    srcs = [],
    hdrs = ["UniquePtr.hpp", "moveSwap.hpp", "BasePtr.hpp"],
)

cc_binary(
    name = "upcases",
    srcs = ["main.cpp"],
    deps = [
        ":UniquePtr",
    ],
)