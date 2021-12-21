cc_library(
    name = "lib",
    hdrs = [
        "Problem2073.cc",
        "Problem2074.cc",
        "Problem2103.cc",
        "Problem2104_linear.cc",
        "Problem2104_quadratic.cc",
        "Problem84.cc",
        "Problem85.cc",
    ],
)

cc_test(
    name = "test",
    srcs = [
        "Problem2073Test.cc",
        "Problem2074Test.cc",
        "Problem2103Test.cc",
        "Problem2104Test_linear.cc",
        "Problem2104Test_quadratic.cc",
        "Problem85Test.cc",
    ],
    deps = [
        ":lib",
        "//googletest:gtest_main",
    ],
)
