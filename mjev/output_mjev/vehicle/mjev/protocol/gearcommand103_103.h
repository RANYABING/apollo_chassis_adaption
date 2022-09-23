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

class Gearcommand103103 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  Gearcommand103103();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'bit': 1, 'enum': {0: 'GEARTARGET_GEAR_TARGET_PARK', 1: 'GEARTARGET_GEAR_TARGET_DRIVE', 2: 'GEARTARGET_GEAR_TARGET_REVERSE'}, 'is_signed_var': False, 'len': 3, 'name': 'GearTarget', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Gearcommand103103* set_geartarget(Gearcommand103_103::GeartargetType geartarget);

  // config detail: {'bit': 0, 'enum': {0: 'GEARENCTRL_GEAR_EN_CTRL_DISABLE', 1: 'GEARENCTRL_GEAR_EN_CTRL_ENABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'GearEnCtrl', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Gearcommand103103* set_gearenctrl(Gearcommand103_103::GearenctrlType gearenctrl);

 private:

  // config detail: {'bit': 1, 'enum': {0: 'GEARTARGET_GEAR_TARGET_PARK', 1: 'GEARTARGET_GEAR_TARGET_DRIVE', 2: 'GEARTARGET_GEAR_TARGET_REVERSE'}, 'is_signed_var': False, 'len': 3, 'name': 'GearTarget', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_geartarget(uint8_t* data, Gearcommand103_103::GeartargetType geartarget);

  // config detail: {'bit': 0, 'enum': {0: 'GEARENCTRL_GEAR_EN_CTRL_DISABLE', 1: 'GEARENCTRL_GEAR_EN_CTRL_ENABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'GearEnCtrl', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_gearenctrl(uint8_t* data, Gearcommand103_103::GearenctrlType gearenctrl);

 private:
  Gearcommand103_103::GeartargetType geartarget_;
  Gearcommand103_103::GearenctrlType gearenctrl_;
};

}  // namespace mjev
}  // namespace canbus
}  // namespace apollo


