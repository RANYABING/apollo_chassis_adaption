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

class Gearreport503503 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Gearreport503503();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 0, 'enum': {0: 'GEARSTATEFAULT_GEAR_NO_FAULT', 1: 'GEARSTATEFAULT_GEAR_FAULT'}, 'is_signed_var': False, 'len': 1, 'name': 'GearStateFault', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Gearreport503_503::GearstatefaultType gearstatefault(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 1, 'enum': {0: 'GEAR_STATEACT_GEAR_ACTUAL_NEUTRAL', 1: 'GEAR_STATEACT_GEAR_ACTUAL_DRIVE', 2: 'GEAR_STATEACT_GEAR_ACTUAL_REVERSE'}, 'is_signed_var': False, 'len': 3, 'name': 'Gear_StateAct', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Gearreport503_503::Gear_stateactType gear_stateact(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace mjev
}  // namespace canbus
}  // namespace apollo


