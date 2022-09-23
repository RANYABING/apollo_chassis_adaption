/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#pragma once

#include "modules/drivers/canbus/can_comm/protocol_data.h"
#include "modules/canbus/proto/chassis_detail.pb.h"

namespace apollo {
namespace canbus {
namespace mjev {

class Wheelspeedreport506506 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Wheelspeedreport506506();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 48, 'description': 'WheelSpeedRR', 'is_signed_var': False, 'len': 16, 'name': 'WheelSpeedRR', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|65.535]', 'physical_unit': 'm/s', 'precision': 0.001, 'type': 'double'}
  double wheelspeedrr(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 32, 'description': 'WheelSpeedRL', 'is_signed_var': False, 'len': 16, 'name': 'WheelSpeedRL', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|65.535]', 'physical_unit': 'm/s', 'precision': 0.001, 'type': 'double'}
  double wheelspeedrl(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 16, 'description': 'WheelSpeedFR', 'is_signed_var': False, 'len': 16, 'name': 'WheelSpeedFR', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|65.535]', 'physical_unit': 'm/s', 'precision': 0.001, 'type': 'double'}
  double wheelspeedfr(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 0, 'description': 'WheelSpeedFL', 'is_signed_var': False, 'len': 16, 'name': 'WheelSpeedFL', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|65.535]', 'physical_unit': 'm/s', 'precision': 0.001, 'type': 'double'}
  double wheelspeedfl(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace mjev
}  // namespace canbus
}  // namespace apollo


