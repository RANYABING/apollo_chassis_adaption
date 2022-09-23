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

#include "modules/canbus/vehicle/mjev/protocol/brakereport501_501.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace mjev {

using ::apollo::drivers::canbus::Byte;

Brakereport501501::Brakereport501501() {}
const int32_t Brakereport501501::ID = 0x501;

void Brakereport501501::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_mjev()->mutable_brakereport501_501()->set_brakepedalact(brakepedalact(bytes, length));
  chassis->mutable_mjev()->mutable_brakereport501_501()->set_brakehwfault(brakehwfault(bytes, length));
  chassis->mutable_mjev()->mutable_brakereport501_501()->set_brakecomfault(brakecomfault(bytes, length));
  chassis->mutable_mjev()->mutable_brakereport501_501()->set_brakeenstate(brakeenstate(bytes, length));
}

// config detail: {'bit': 24, 'is_signed_var': False, 'len': 16, 'name': 'brakepedalact', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|100]', 'physical_unit': '%', 'precision': 0.1, 'type': 'double'}
double Brakereport501501::brakepedalact(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 3);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.100000;
  return ret;
}

// config detail: {'bit': 16, 'enum': {0: 'BRAKEHWFAULT_BRAKE_SYSTEM_HW_NO_FAULT', 1: 'BRAKEHWFAULT_BRAKE_SYSTEM_HW_FAULT'}, 'is_signed_var': False, 'len': 8, 'name': 'brakehwfault', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Brakereport501_501::BrakehwfaultType Brakereport501501::brakehwfault(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  Brakereport501_501::BrakehwfaultType ret =  static_cast<Brakereport501_501::BrakehwfaultType>(x);
  return ret;
}

// config detail: {'bit': 8, 'enum': {0: 'BRAKECOMFAULT_BRAKE_COM_NO_FAULT', 1: 'BRAKECOMFAULT_BRAKE_COM_FAULT'}, 'is_signed_var': False, 'len': 8, 'name': 'brakecomfault', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Brakereport501_501::BrakecomfaultType Brakereport501501::brakecomfault(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 8);

  Brakereport501_501::BrakecomfaultType ret =  static_cast<Brakereport501_501::BrakecomfaultType>(x);
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 2, 'name': 'brakeenstate', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Brakereport501501::brakeenstate(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 2);

  int ret = x;
  return ret;
}
}  // namespace mjev
}  // namespace canbus
}  // namespace apollo
