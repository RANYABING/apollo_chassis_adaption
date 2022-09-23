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

#include "modules/canbus/vehicle/mjev/protocol/throttlereport500_500.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace mjev {

using ::apollo::drivers::canbus::Byte;

Throttlereport500500::Throttlereport500500() {}
const int32_t Throttlereport500500::ID = 0x500;

void Throttlereport500500::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_mjev()->mutable_throttlereport500_500()->set_throttlepedalact(throttlepedalact(bytes, length));
  chassis->mutable_mjev()->mutable_throttlereport500_500()->set_drivecomfault(drivecomfault(bytes, length));
  chassis->mutable_mjev()->mutable_throttlereport500_500()->set_drivehwfault(drivehwfault(bytes, length));
  chassis->mutable_mjev()->mutable_throttlereport500_500()->set_throttleenstate(throttleenstate(bytes, length));
}

// config detail: {'bit': 24, 'is_signed_var': False, 'len': 16, 'name': 'throttlepedalact', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|100]', 'physical_unit': '%', 'precision': 0.1, 'type': 'double'}
double Throttlereport500500::throttlepedalact(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 3);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.100000;
  return ret;
}

// config detail: {'bit': 16, 'enum': {0: 'DRIVECOMFAULT_THROTTLE_COM_NO_FAULT', 1: 'DRIVECOMFAULT_THROTTLE_COM_FAULT'}, 'is_signed_var': False, 'len': 8, 'name': 'drivecomfault', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Throttlereport500_500::DrivecomfaultType Throttlereport500500::drivecomfault(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  Throttlereport500_500::DrivecomfaultType ret =  static_cast<Throttlereport500_500::DrivecomfaultType>(x);
  return ret;
}

// config detail: {'bit': 8, 'enum': {0: 'DRIVEHWFAULT_DRIVE_SYSTEM_HW_NO_FAULT', 1: 'DRIVEHWFAULT_DRIVE_SYSTEM_HW_FAULT'}, 'is_signed_var': False, 'len': 8, 'name': 'drivehwfault', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Throttlereport500_500::DrivehwfaultType Throttlereport500500::drivehwfault(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 8);

  Throttlereport500_500::DrivehwfaultType ret =  static_cast<Throttlereport500_500::DrivehwfaultType>(x);
  return ret;
}

// config detail: {'bit': 0, 'enum': {0: 'THROTTLEENSTATE_THROTTLE_EN_STATE_MANUAL', 1: 'THROTTLEENSTATE_THROTTLE_EN_STATE_AUTO', 2: 'THROTTLEENSTATE_THROTTLE_EN_STATE_TAKEOVER', 3: 'THROTTLEENSTATE_THROTTLE_EN_STATE_STANDBY'}, 'is_signed_var': False, 'len': 2, 'name': 'throttleenstate', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Throttlereport500_500::ThrottleenstateType Throttlereport500500::throttleenstate(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 2);

  Throttlereport500_500::ThrottleenstateType ret =  static_cast<Throttlereport500_500::ThrottleenstateType>(x);
  return ret;
}
}  // namespace mjev
}  // namespace canbus
}  // namespace apollo
