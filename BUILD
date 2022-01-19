cc_library(
    name = "lib",
    hdrs = [
        "Problem1383.cc",
        "Problem2073.cc",
        "Problem2074.cc",
        "Problem2103.cc",
        "Problem2104_linear.cc",
        "Problem2104_quadratic.cc",
        "Problem2105.cc",
        "Problem2106.cc",
        "Problem2136.cc",
        "Problem84.cc",
        "Problem85.cc",
    ],
)

cc_test(
    name = "test",
    srcs = [
        "Problem1383Test.cc",
        "Problem2073Test.cc",
        "Problem2074Test.cc",
        "Problem2103Test.cc",
        "Problem2104Test_linear.cc",
        "Problem2104Test_quadratic.cc",
        "Problem2105Test.cc",
        "Problem2106Test.cc",
        "Problem2136Test.cc",
        "Problem85Test.cc",
    ],
    deps = [
        ":lib",
        "//googletest:gtest_main",
    ],
)
