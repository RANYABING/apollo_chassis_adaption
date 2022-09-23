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
namespace mjcar {

class Steeringreport502502 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Steeringreport502502();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 40, 'description': 'greater than 0 accel less than 0 deaccel', 'is_signed_var': False, 'len': 8, 'name': 'HandWheelSteerAngSpdAct', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': 'deg/s', 'precision': 1.0, 'type': 'int'}
  int handwheelsteerangspdact(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 24, 'description': 'greater than 0 left less than 0 left', 'is_signed_var': True, 'len': 16, 'name': 'HandWheelSteerAngAct', 'offset': 0.0, 'order': 'intel', 'physical_range': '[-512|511]', 'physical_unit': 'deg', 'precision': 1.0, 'type': 'int'}
  int handwheelsteerangact(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 16, 'enum': {0: 'STEERCOMFAULT_STEERCOMNOFAULT', 1: 'STEERCOMFAULT_STEERCOMFAULT'}, 'is_signed_var': False, 'len': 8, 'name': 'SteerComFault', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Steeringreport502_502::SteercomfaultType steercomfault(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 8, 'enum': {0: 'STEERHARDFAULT_STEERSYSTEMHWNOFAULT', 1: 'STEERHARDFAULT_STEERSYSTEMHWFAULT'}, 'is_signed_var': False, 'len': 8, 'name': 'SteerHardFault', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Steeringreport502_502::SteerhardfaultType steerhardfault(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 0, 'enum': {0: 'STEERENSTATE_STEERENSTATEMANUAL', 1: 'STEERENSTATE_STEERENSTATEAUTO', 2: 'STEERENSTATE_STEERENSTATETAKEOVER', 3: 'STEERENSTATE_STEERENSTATESTANDBY'}, 'is_signed_var': True, 'len': 2, 'name': 'SteerEnState', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Steeringreport502_502::SteerenstateType steerenstate(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace mjcar
}  // namespace canbus
}  // namespace apollo


