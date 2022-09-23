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

#include "modules/canbus/vehicle/mjev/protocol/gearcommand103_103.h"

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace mjev {

using ::apollo::drivers::canbus::Byte;

const int32_t Gearcommand103103::ID = 0x103;

// public
Gearcommand103103::Gearcommand103103() { Reset(); }

uint32_t Gearcommand103103::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Gearcommand103103::UpdateData(uint8_t* data) {
  set_p_geartarget(data, geartarget_);
  set_p_gearenctrl(data, gearenctrl_);
}

void Gearcommand103103::Reset() {
  // TODO(All) :  you should check this manually
  geartarget_ = Gearcommand103_103::GEARTARGET_GEAR_TARGET_PARK;
  gearenctrl_ = Gearcommand103_103::GEARENCTRL_GEAR_EN_CTRL_DISABLE;
}

Gearcommand103103* Gearcommand103103::set_geartarget(
    Gearcommand103_103::GeartargetType geartarget) {
  geartarget_ = geartarget;
  return this;
 }

// config detail: {'bit': 1, 'enum': {0: 'GEARTARGET_GEAR_TARGET_PARK', 1: 'GEARTARGET_GEAR_TARGET_DRIVE', 2: 'GEARTARGET_GEAR_TARGET_REVERSE'}, 'is_signed_var': False, 'len': 3, 'name': 'GearTarget', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Gearcommand103103::set_p_geartarget(uint8_t* data,
    Gearcommand103_103::GeartargetType geartarget) {
  int x = geartarget;

  Byte to_set(data + 0);
  to_set.set_value(x, 1, 3);
}


Gearcommand103103* Gearcommand103103::set_gearenctrl(
    Gearcommand103_103::GearenctrlType gearenctrl) {
  gearenctrl_ = gearenctrl;
  return this;
 }

// config detail: {'bit': 0, 'enum': {0: 'GEARENCTRL_GEAR_EN_CTRL_DISABLE', 1: 'GEARENCTRL_GEAR_EN_CTRL_ENABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'GearEnCtrl', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Gearcommand103103::set_p_gearenctrl(uint8_t* data,
    Gearcommand103_103::GearenctrlType gearenctrl) {
  int x = gearenctrl;

  Byte to_set(data + 0);
  to_set.set_value(x, 0, 1);
}

}  // namespace mjev
}  // namespace canbus
}  // namespace apollo
