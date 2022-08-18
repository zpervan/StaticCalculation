workspace(name = "StaticCalculation")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "bazel_skylib",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/bazel-skylib/releases/download/1.2.1/bazel-skylib-1.2.1.tar.gz",
        "https://github.com/bazelbuild/bazel-skylib/releases/download/1.2.1/bazel-skylib-1.2.1.tar.gz",
    ],
    sha256 = "f7be3474d42aae265405a592bb7da8e171919d74c16f082a5457840f06054728",
)

load("@bazel_skylib//:workspace.bzl", "bazel_skylib_workspace")

bazel_skylib_workspace()

local_repository(
    name = "gllib",
    path = "ThirdParty/GL/",
)

local_repository(
    name = "googletestlib",
    path = "ThirdParty/googletest/",
)

local_repository(
    name = "imguilib",
    path = "ThirdParty/imgui/",
)

local_repository(
    name = "sfmllib",
    path = "ThirdParty/SFML/",
)

local_repository(
    name = "spdloglib",
    path = "ThirdParty/spdlog/",
)
