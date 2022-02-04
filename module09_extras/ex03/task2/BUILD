load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "UniquePtr",
    srcs = [],
    hdrs = ["UniquePtr.hpp", "moveSwap.hpp", "BasePtr.hpp"],
)

cc_library(
    name = "SharedPtr",
    srcs = [],
    hdrs = ["SharedPtr.hpp", "ShareCount.hpp"],
)

cc_library(
    name = "WeakPtr",
    srcs = [],
    hdrs = ["WeakPtr.hpp", "SmartPointer.hpp"],
)

cc_binary(
    name = "wpcases",
    srcs = ["main.cpp"],
    deps = [
        ":UniquePtr",
        ":SharedPtr",
        ":WeakPtr",
    ],
)