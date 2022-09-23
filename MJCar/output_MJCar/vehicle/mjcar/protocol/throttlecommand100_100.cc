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

#include "modules/canbus/vehicle/MJCar/protocol/throttlecommand100_100.h"

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace MJCar {

using ::apollo::drivers::canbus::Byte;

const int32_t Throttlecommand100100::ID = 0x100;

// public
Throttlecommand100100::Throttlecommand100100() { Reset(); }

uint32_t Throttlecommand100100::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Throttlecommand100100::UpdateData(uint8_t* data) {
  set_p_trottlepedaltarget(data, trottlepedaltarget_);
  set_p_throttle_acc(data, throttle_acc_);
  set_p_throttleenctrl(data, throttleenctrl_);
}

void Throttlecommand100100::Reset() {
  // TODO(All) :  you should check this manually
  trottlepedaltarget_ = 0.0;
  throttle_acc_ = 0.0;
  throttleenctrl_ = Throttlecommand100_100::THROTTLEENCTRL_DRIVE_EN_CTRL_DISABLE;
}

Throttlecommand100100* Throttlecommand100100::set_trottlepedaltarget(
    double trottlepedaltarget) {
  trottlepedaltarget_ = trottlepedaltarget;
  return this;
 }

// config detail: {'bit': 32, 'is_signed_var': False, 'len': 16, 'name': 'TrottlePedalTarget', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|100]', 'physical_unit': '%', 'precision': 0.1, 'type': 'double'}
void Throttlecommand100100::set_p_trottlepedaltarget(uint8_t* data,
    double trottlepedaltarget) {
  trottlepedaltarget = ProtocolData::BoundedValue(0.0, 100.0, trottlepedaltarget);
  int x = trottlepedaltarget / 0.100000;
  uint8_t t = 0;

  t = x & 0xFF;
  Byte to_set0(data + 4);
  to_set0.set_value(t, 0, 8);
  x >>= 8;

  t = x & 0xFF;
  Byte to_set1(data + 5);
  to_set1.set_value(t, 0, 8);
}


Throttlecommand100100* Throttlecommand100100::set_throttle_acc(
    double throttle_acc) {
  throttle_acc_ = throttle_acc;
  return this;
 }

// config detail: {'bit': 8, 'is_signed_var': False, 'len': 10, 'name': 'Throttle_Acc', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|10.23]', 'physical_unit': 'm/s^2', 'precision': 0.01, 'type': 'double'}
void Throttlecommand100100::set_p_throttle_acc(uint8_t* data,
    double throttle_acc) {
  throttle_acc = ProtocolData::BoundedValue(0.0, 10.23, throttle_acc);
  int x = throttle_acc / 0.010000;
  uint8_t t = 0;

  t = x & 0xFF;
  Byte to_set0(data + 1);
  to_set0.set_value(t, 0, 8);
  x >>= 8;

  t = x & 0x3;
  Byte to_set1(data + 2);
  to_set1.set_value(t, 0, 2);
}


Throttlecommand100100* Throttlecommand100100::set_throttleenctrl(
    Throttlecommand100_100::ThrottleenctrlType throttleenctrl) {
  throttleenctrl_ = throttleenctrl;
  return this;
 }

// config detail: {'bit': 0, 'enum': {0: 'THROTTLEENCTRL_DRIVE_EN_CTRL_DISABLE', 1: 'THROTTLEENCTRL_DRIVE_EN_CTRL_ENABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'ThrottleEnCtrl', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Throttlecommand100100::set_p_throttleenctrl(uint8_t* data,
    Throttlecommand100_100::ThrottleenctrlType throttleenctrl) {
  int x = throttleenctrl;

  Byte to_set(data + 0);
  to_set.set_value(x, 0, 1);
}

}  // namespace MJCar
}  // namespace canbus
}  // namespace apollo
