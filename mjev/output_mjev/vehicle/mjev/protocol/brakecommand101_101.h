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

class Brakecommand101101 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  Brakecommand101101();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'bit': 24, 'is_signed_var': False, 'len': 16, 'name': 'BrakePedalTarget', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|100]', 'physical_unit': '%', 'precision': 0.1, 'type': 'double'}
  Brakecommand101101* set_brakepedaltarget(double brakepedaltarget);

  // config detail: {'bit': 1, 'enum': {0: 'BRAKEENCTRL_BRAKE_EN_CTRL_DISABLE', 1: 'BRAKEENCTRL_BRAKE_EN_CTRL_ENABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'BrakeEnCtrl', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Brakecommand101101* set_brakeenctrl(Brakecommand101_101::BrakeenctrlType brakeenctrl);

  // config detail: {'bit': 8, 'is_signed_var': False, 'len': 10, 'name': 'Brake_Dec', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|10.23]', 'physical_unit': 'm/s^2', 'precision': 0.01, 'type': 'double'}
  Brakecommand101101* set_brake_dec(double brake_dec);

  // config detail: {'bit': 0, 'enum': {0: 'AEBENCTRL_AEB_EN_CTRL_DISABLE', 1: 'AEBENCTRL_AEB_EN_CTRL_ENABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'AEBEnCtrl', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Brakecommand101101* set_aebenctrl(Brakecommand101_101::AebenctrlType aebenctrl);

 private:

  // config detail: {'bit': 24, 'is_signed_var': False, 'len': 16, 'name': 'BrakePedalTarget', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|100]', 'physical_unit': '%', 'precision': 0.1, 'type': 'double'}
  void set_p_brakepedaltarget(uint8_t* data, double brakepedaltarget);

  // config detail: {'bit': 1, 'enum': {0: 'BRAKEENCTRL_BRAKE_EN_CTRL_DISABLE', 1: 'BRAKEENCTRL_BRAKE_EN_CTRL_ENABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'BrakeEnCtrl', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_brakeenctrl(uint8_t* data, Brakecommand101_101::BrakeenctrlType brakeenctrl);

  // config detail: {'bit': 8, 'is_signed_var': False, 'len': 10, 'name': 'Brake_Dec', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|10.23]', 'physical_unit': 'm/s^2', 'precision': 0.01, 'type': 'double'}
  void set_p_brake_dec(uint8_t* data, double brake_dec);

  // config detail: {'bit': 0, 'enum': {0: 'AEBENCTRL_AEB_EN_CTRL_DISABLE', 1: 'AEBENCTRL_AEB_EN_CTRL_ENABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'AEBEnCtrl', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_aebenctrl(uint8_t* data, Brakecommand101_101::AebenctrlType aebenctrl);

 private:
  double brakepedaltarget_;
  Brakecommand101_101::BrakeenctrlType brakeenctrl_;
  double brake_dec_;
  Brakecommand101_101::AebenctrlType aebenctrl_;
};

}  // namespace mjev
}  // namespace canbus
}  // namespace apollo


