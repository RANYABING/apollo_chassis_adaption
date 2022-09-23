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

#include "modules/canbus/vehicle/mjev/protocol/steeringcommand102_102.h"

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace mjev {

using ::apollo::drivers::canbus::Byte;

const int32_t Steeringcommand102102::ID = 0x102;

// public
Steeringcommand102102::Steeringcommand102102() { Reset(); }

uint32_t Steeringcommand102102::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Steeringcommand102102::UpdateData(uint8_t* data) {
  set_p_handwheelsteerangtgt(data, handwheelsteerangtgt_);
  set_p_handwheelsteerangspd(data, handwheelsteerangspd_);
  set_p_steerenctrl(data, steerenctrl_);
}

void Steeringcommand102102::Reset() {
  // TODO(All) :  you should check this manually
  handwheelsteerangtgt_ = 0;
  handwheelsteerangspd_ = 0;
  steerenctrl_ = Steeringcommand102_102::STEERENCTRL_STEERENCTRLDISABLE;
}

Steeringcommand102102* Steeringcommand102102::set_handwheelsteerangtgt(
    int handwheelsteerangtgt) {
  handwheelsteerangtgt_ = handwheelsteerangtgt;
  return this;
 }

// config detail: {'bit': 16, 'is_signed_var': True, 'len': 16, 'name': 'HandWheelSteerAngTgt', 'offset': 0.0, 'order': 'intel', 'physical_range': '[-500|500]', 'physical_unit': 'deg', 'precision': 1.0, 'type': 'int'}
void Steeringcommand102102::set_p_handwheelsteerangtgt(uint8_t* data,
    int handwheelsteerangtgt) {
  handwheelsteerangtgt = ProtocolData::BoundedValue(-500, 500, handwheelsteerangtgt);
  int x = handwheelsteerangtgt;
  uint8_t t = 0;

  t = x & 0xFF;
  Byte to_set0(data + 2);
  to_set0.set_value(t, 0, 8);
  x >>= 8;

  t = x & 0xFF;
  Byte to_set1(data + 3);
  to_set1.set_value(t, 0, 8);
}


Steeringcommand102102* Steeringcommand102102::set_handwheelsteerangspd(
    int handwheelsteerangspd) {
  handwheelsteerangspd_ = handwheelsteerangspd;
  return this;
 }

// config detail: {'bit': 8, 'is_signed_var': False, 'len': 8, 'name': 'HandWheelSteerAngSpd', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': 'deg/s', 'precision': 1.0, 'type': 'int'}
void Steeringcommand102102::set_p_handwheelsteerangspd(uint8_t* data,
    int handwheelsteerangspd) {
  handwheelsteerangspd = ProtocolData::BoundedValue(0, 255, handwheelsteerangspd);
  int x = handwheelsteerangspd;

  Byte to_set(data + 1);
  to_set.set_value(x, 0, 8);
}


Steeringcommand102102* Steeringcommand102102::set_steerenctrl(
    Steeringcommand102_102::SteerenctrlType steerenctrl) {
  steerenctrl_ = steerenctrl;
  return this;
 }

// config detail: {'bit': 0, 'enum': {0: 'STEERENCTRL_STEERENCTRLDISABLE', 1: 'STEERENCTRL_STEERENCTRLENABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'SteerEnCtrl', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Steeringcommand102102::set_p_steerenctrl(uint8_t* data,
    Steeringcommand102_102::SteerenctrlType steerenctrl) {
  int x = steerenctrl;

  Byte to_set(data + 0);
  to_set.set_value(x, 0, 1);
}

}  // namespace mjev
}  // namespace canbus
}  // namespace apollo
