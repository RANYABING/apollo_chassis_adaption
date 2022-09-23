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

#include "modules/canbus/vehicle/mjev/protocol/steeringreport502_502.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace mjev {

using ::apollo::drivers::canbus::Byte;

Steeringreport502502::Steeringreport502502() {}
const int32_t Steeringreport502502::ID = 0x502;

void Steeringreport502502::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_mjev()->mutable_steeringreport502_502()->set_handwheelsteerangspdact(handwheelsteerangspdact(bytes, length));
  chassis->mutable_mjev()->mutable_steeringreport502_502()->set_handwheelsteerangact(handwheelsteerangact(bytes, length));
  chassis->mutable_mjev()->mutable_steeringreport502_502()->set_steercomfault(steercomfault(bytes, length));
  chassis->mutable_mjev()->mutable_steeringreport502_502()->set_steerhardfault(steerhardfault(bytes, length));
  chassis->mutable_mjev()->mutable_steeringreport502_502()->set_steerenstate(steerenstate(bytes, length));
}

// config detail: {'bit': 40, 'description': 'greater than 0 accel less than 0 deaccel', 'is_signed_var': False, 'len': 8, 'name': 'handwheelsteerangspdact', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': 'deg/s', 'precision': 1.0, 'type': 'int'}
int Steeringreport502502::handwheelsteerangspdact(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 24, 'description': 'greater than 0 left less than 0 left', 'is_signed_var': True, 'len': 16, 'name': 'handwheelsteerangact', 'offset': 0.0, 'order': 'intel', 'physical_range': '[-512|511]', 'physical_unit': 'deg', 'precision': 1.0, 'type': 'int'}
int Steeringreport502502::handwheelsteerangact(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 3);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  x <<= 16;
  x >>= 16;

  int ret = x;
  return ret;
}

// config detail: {'bit': 16, 'enum': {0: 'STEERCOMFAULT_STEERCOMNOFAULT', 1: 'STEERCOMFAULT_STEERCOMFAULT'}, 'is_signed_var': False, 'len': 8, 'name': 'steercomfault', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Steeringreport502_502::SteercomfaultType Steeringreport502502::steercomfault(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  Steeringreport502_502::SteercomfaultType ret =  static_cast<Steeringreport502_502::SteercomfaultType>(x);
  return ret;
}

// config detail: {'bit': 8, 'enum': {0: 'STEERHARDFAULT_STEERSYSTEMHWNOFAULT', 1: 'STEERHARDFAULT_STEERSYSTEMHWFAULT'}, 'is_signed_var': False, 'len': 8, 'name': 'steerhardfault', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Steeringreport502_502::SteerhardfaultType Steeringreport502502::steerhardfault(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 8);

  Steeringreport502_502::SteerhardfaultType ret =  static_cast<Steeringreport502_502::SteerhardfaultType>(x);
  return ret;
}

// config detail: {'bit': 0, 'enum': {0: 'STEERENSTATE_STEERENSTATEMANUAL', 1: 'STEERENSTATE_STEERENSTATEAUTO', 2: 'STEERENSTATE_STEERENSTATETAKEOVER', 3: 'STEERENSTATE_STEERENSTATESTANDBY'}, 'is_signed_var': True, 'len': 2, 'name': 'steerenstate', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Steeringreport502_502::SteerenstateType Steeringreport502502::steerenstate(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 2);

  x <<= 30;
  x >>= 30;

  Steeringreport502_502::SteerenstateType ret =  static_cast<Steeringreport502_502::SteerenstateType>(x);
  return ret;
}
}  // namespace mjev
}  // namespace canbus
}  // namespace apollo
