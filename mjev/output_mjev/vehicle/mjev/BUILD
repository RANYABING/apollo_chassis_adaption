load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "mjev_vehicle_factory",
    srcs = [
        "mjev_vehicle_factory.cc",
    ],
    hdrs = [
        "mjev_vehicle_factory.h",
    ],
    deps = [
        ":mjev_controller",
        ":mjev_message_manager",
        "//modules/canbus/vehicle:abstract_vehicle_factory",
    ],
)

cc_library(
    name = "mjev_message_manager",
    srcs = [
        "mjev_message_manager.cc",
    ],
    hdrs = [
        "mjev_message_manager.h",
    ],
    deps = [
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/canbus/proto:chassis_detail_cc_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/canbus/vehicle/mjev/protocol:canbus_mjev_protocol",
    ],
)

cc_library(
    name = "mjev_controller",
    srcs = [
        "mjev_controller.cc",
    ],
    hdrs = [
        "mjev_controller.h",
    ],
    deps = [
        ":mjev_message_manager",
        "//modules/drivers/canbus/can_comm:can_sender",
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/canbus/proto:chassis_detail_cc_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/canbus/vehicle:vehicle_controller_base",
        "//modules/canbus/vehicle/mjev/protocol:canbus_mjev_protocol",
    ],
)

cpplint()
