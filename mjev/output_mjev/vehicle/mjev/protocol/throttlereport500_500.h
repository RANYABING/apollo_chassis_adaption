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

class Throttlereport500500 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Throttlereport500500();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 24, 'is_signed_var': False, 'len': 16, 'name': 'ThrottlePedalAct', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|100]', 'physical_unit': '%', 'precision': 0.1, 'type': 'double'}
  double throttlepedalact(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 16, 'enum': {0: 'DRIVECOMFAULT_THROTTLE_COM_NO_FAULT', 1: 'DRIVECOMFAULT_THROTTLE_COM_FAULT'}, 'is_signed_var': False, 'len': 8, 'name': 'DriveComFault', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Throttlereport500_500::DrivecomfaultType drivecomfault(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 8, 'enum': {0: 'DRIVEHWFAULT_DRIVE_SYSTEM_HW_NO_FAULT', 1: 'DRIVEHWFAULT_DRIVE_SYSTEM_HW_FAULT'}, 'is_signed_var': False, 'len': 8, 'name': 'DriveHWFault', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Throttlereport500_500::DrivehwfaultType drivehwfault(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 0, 'enum': {0: 'THROTTLEENSTATE_THROTTLE_EN_STATE_MANUAL', 1: 'THROTTLEENSTATE_THROTTLE_EN_STATE_AUTO', 2: 'THROTTLEENSTATE_THROTTLE_EN_STATE_TAKEOVER', 3: 'THROTTLEENSTATE_THROTTLE_EN_STATE_STANDBY'}, 'is_signed_var': False, 'len': 2, 'name': 'ThrottleEnState', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Throttlereport500_500::ThrottleenstateType throttleenstate(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace mjev
}  // namespace canbus
}  // namespace apollo


