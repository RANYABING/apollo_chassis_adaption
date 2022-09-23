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

#include "modules/canbus/vehicle/mjev/protocol/brakecommand101_101.h"

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace mjev {

using ::apollo::drivers::canbus::Byte;

const int32_t Brakecommand101101::ID = 0x101;

// public
Brakecommand101101::Brakecommand101101() { Reset(); }

uint32_t Brakecommand101101::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Brakecommand101101::UpdateData(uint8_t* data) {
  set_p_brakepedaltarget(data, brakepedaltarget_);
  set_p_brakeenctrl(data, brakeenctrl_);
  set_p_brake_dec(data, brake_dec_);
  set_p_aebenctrl(data, aebenctrl_);
}

void Brakecommand101101::Reset() {
  // TODO(All) :  you should check this manually
  brakepedaltarget_ = 0.0;
  brakeenctrl_ = Brakecommand101_101::BRAKEENCTRL_BRAKE_EN_CTRL_DISABLE;
  brake_dec_ = 0.0;
  aebenctrl_ = Brakecommand101_101::AEBENCTRL_AEB_EN_CTRL_DISABLE;
}

Brakecommand101101* Brakecommand101101::set_brakepedaltarget(
    double brakepedaltarget) {
  brakepedaltarget_ = brakepedaltarget;
  return this;
 }

// config detail: {'bit': 24, 'is_signed_var': False, 'len': 16, 'name': 'BrakePedalTarget', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|100]', 'physical_unit': '%', 'precision': 0.1, 'type': 'double'}
void Brakecommand101101::set_p_brakepedaltarget(uint8_t* data,
    double brakepedaltarget) {
  brakepedaltarget = ProtocolData::BoundedValue(0.0, 100.0, brakepedaltarget);
  int x = brakepedaltarget / 0.100000;
  uint8_t t = 0;

  t = x & 0xFF;
  Byte to_set0(data + 3);
  to_set0.set_value(t, 0, 8);
  x >>= 8;

  t = x & 0xFF;
  Byte to_set1(data + 4);
  to_set1.set_value(t, 0, 8);
}


Brakecommand101101* Brakecommand101101::set_brakeenctrl(
    Brakecommand101_101::BrakeenctrlType brakeenctrl) {
  brakeenctrl_ = brakeenctrl;
  return this;
 }

// config detail: {'bit': 1, 'enum': {0: 'BRAKEENCTRL_BRAKE_EN_CTRL_DISABLE', 1: 'BRAKEENCTRL_BRAKE_EN_CTRL_ENABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'BrakeEnCtrl', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Brakecommand101101::set_p_brakeenctrl(uint8_t* data,
    Brakecommand101_101::BrakeenctrlType brakeenctrl) {
  int x = brakeenctrl;

  Byte to_set(data + 0);
  to_set.set_value(x, 1, 1);
}


Brakecommand101101* Brakecommand101101::set_brake_dec(
    double brake_dec) {
  brake_dec_ = brake_dec;
  return this;
 }

// config detail: {'bit': 8, 'is_signed_var': False, 'len': 10, 'name': 'Brake_Dec', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|10.23]', 'physical_unit': 'm/s^2', 'precision': 0.01, 'type': 'double'}
void Brakecommand101101::set_p_brake_dec(uint8_t* data,
    double brake_dec) {
  brake_dec = ProtocolData::BoundedValue(0.0, 10.23, brake_dec);
  int x = brake_dec / 0.010000;
  uint8_t t = 0;

  t = x & 0xFF;
  Byte to_set0(data + 1);
  to_set0.set_value(t, 0, 8);
  x >>= 8;

  t = x & 0x3;
  Byte to_set1(data + 2);
  to_set1.set_value(t, 0, 2);
}


Brakecommand101101* Brakecommand101101::set_aebenctrl(
    Brakecommand101_101::AebenctrlType aebenctrl) {
  aebenctrl_ = aebenctrl;
  return this;
 }

// config detail: {'bit': 0, 'enum': {0: 'AEBENCTRL_AEB_EN_CTRL_DISABLE', 1: 'AEBENCTRL_AEB_EN_CTRL_ENABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'AEBEnCtrl', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Brakecommand101101::set_p_aebenctrl(uint8_t* data,
    Brakecommand101_101::AebenctrlType aebenctrl) {
  int x = aebenctrl;

  Byte to_set(data + 0);
  to_set.set_value(x, 0, 1);
}

}  // namespace mjev
}  // namespace canbus
}  // namespace apollo
