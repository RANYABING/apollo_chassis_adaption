load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "mjcar_vehicle_factory",
    srcs = [
        "mjcar_vehicle_factory.cc",
    ],
    hdrs = [
        "mjcar_vehicle_factory.h",
    ],
    deps = [
        ":mjcar_controller",
        ":mjcar_message_manager",
        "//modules/canbus/vehicle:abstract_vehicle_factory",
    ],
)

cc_library(
    name = "mjcar_message_manager",
    srcs = [
        "mjcar_message_manager.cc",
    ],
    hdrs = [
        "mjcar_message_manager.h",
    ],
    deps = [
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/canbus/proto:chassis_detail_cc_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/canbus/vehicle/mjcar/protocol:canbus_mjcar_protocol",
    ],
)

cc_library(
    name = "mjcar_controller",
    srcs = [
        "mjcar_controller.cc",
    ],
    hdrs = [
        "mjcar_controller.h",
    ],
    deps = [
        ":mjcar_message_manager",
        "//modules/drivers/canbus/can_comm:can_sender",
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/canbus/proto:chassis_detail_cc_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/canbus/vehicle:vehicle_controller_base",
        "//modules/canbus/vehicle/mjcar/protocol:canbus_mjcar_protocol",
    ],
)

cpplint()
