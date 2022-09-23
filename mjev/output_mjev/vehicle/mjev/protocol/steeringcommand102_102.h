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

class Steeringcommand102102 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  Steeringcommand102102();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'bit': 16, 'is_signed_var': True, 'len': 16, 'name': 'HandWheelSteerAngTgt', 'offset': 0.0, 'order': 'intel', 'physical_range': '[-500|500]', 'physical_unit': 'deg', 'precision': 1.0, 'type': 'int'}
  Steeringcommand102102* set_handwheelsteerangtgt(int handwheelsteerangtgt);

  // config detail: {'bit': 8, 'is_signed_var': False, 'len': 8, 'name': 'HandWheelSteerAngSpd', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': 'deg/s', 'precision': 1.0, 'type': 'int'}
  Steeringcommand102102* set_handwheelsteerangspd(int handwheelsteerangspd);

  // config detail: {'bit': 0, 'enum': {0: 'STEERENCTRL_STEERENCTRLDISABLE', 1: 'STEERENCTRL_STEERENCTRLENABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'SteerEnCtrl', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Steeringcommand102102* set_steerenctrl(Steeringcommand102_102::SteerenctrlType steerenctrl);

 private:

  // config detail: {'bit': 16, 'is_signed_var': True, 'len': 16, 'name': 'HandWheelSteerAngTgt', 'offset': 0.0, 'order': 'intel', 'physical_range': '[-500|500]', 'physical_unit': 'deg', 'precision': 1.0, 'type': 'int'}
  void set_p_handwheelsteerangtgt(uint8_t* data, int handwheelsteerangtgt);

  // config detail: {'bit': 8, 'is_signed_var': False, 'len': 8, 'name': 'HandWheelSteerAngSpd', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': 'deg/s', 'precision': 1.0, 'type': 'int'}
  void set_p_handwheelsteerangspd(uint8_t* data, int handwheelsteerangspd);

  // config detail: {'bit': 0, 'enum': {0: 'STEERENCTRL_STEERENCTRLDISABLE', 1: 'STEERENCTRL_STEERENCTRLENABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'SteerEnCtrl', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_steerenctrl(uint8_t* data, Steeringcommand102_102::SteerenctrlType steerenctrl);

 private:
  int handwheelsteerangtgt_;
  int handwheelsteerangspd_;
  Steeringcommand102_102::SteerenctrlType steerenctrl_;
};

}  // namespace mjev
}  // namespace canbus
}  // namespace apollo


