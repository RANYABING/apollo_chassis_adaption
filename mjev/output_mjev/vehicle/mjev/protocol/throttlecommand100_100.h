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

class Throttlecommand100100 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  Throttlecommand100100();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'bit': 32, 'is_signed_var': False, 'len': 16, 'name': 'TrottlePedalTarget', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|100]', 'physical_unit': '%', 'precision': 0.1, 'type': 'double'}
  Throttlecommand100100* set_trottlepedaltarget(double trottlepedaltarget);

  // config detail: {'bit': 8, 'is_signed_var': False, 'len': 10, 'name': 'Throttle_Acc', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|10.23]', 'physical_unit': 'm/s^2', 'precision': 0.01, 'type': 'double'}
  Throttlecommand100100* set_throttle_acc(double throttle_acc);

  // config detail: {'bit': 0, 'enum': {0: 'THROTTLEENCTRL_DRIVE_EN_CTRL_DISABLE', 1: 'THROTTLEENCTRL_DRIVE_EN_CTRL_ENABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'ThrottleEnCtrl', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Throttlecommand100100* set_throttleenctrl(Throttlecommand100_100::ThrottleenctrlType throttleenctrl);

 private:

  // config detail: {'bit': 32, 'is_signed_var': False, 'len': 16, 'name': 'TrottlePedalTarget', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|100]', 'physical_unit': '%', 'precision': 0.1, 'type': 'double'}
  void set_p_trottlepedaltarget(uint8_t* data, double trottlepedaltarget);

  // config detail: {'bit': 8, 'is_signed_var': False, 'len': 10, 'name': 'Throttle_Acc', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|10.23]', 'physical_unit': 'm/s^2', 'precision': 0.01, 'type': 'double'}
  void set_p_throttle_acc(uint8_t* data, double throttle_acc);

  // config detail: {'bit': 0, 'enum': {0: 'THROTTLEENCTRL_DRIVE_EN_CTRL_DISABLE', 1: 'THROTTLEENCTRL_DRIVE_EN_CTRL_ENABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'ThrottleEnCtrl', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_throttleenctrl(uint8_t* data, Throttlecommand100_100::ThrottleenctrlType throttleenctrl);

 private:
  double trottlepedaltarget_;
  double throttle_acc_;
  Throttlecommand100_100::ThrottleenctrlType throttleenctrl_;
};

}  // namespace mjev
}  // namespace canbus
}  // namespace apollo


